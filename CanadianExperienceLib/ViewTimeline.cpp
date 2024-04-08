/**
 * @file ViewTimeline.cpp
 * @author Alex Beck
 */

#include "pch.h"
#include <wx/dcbuffer.h>
#include <wx/xrc/xmlres.h>
#include <sstream>
#include "ViewTimeline.h"
#include "TimelineDlg.h"
#include "Picture.h"
#include "Actor.h"
#include "AnimChannel.h"
#include "AnimChannelAngle.h"
using namespace std;

/// Timeline threshold so pointer does not go past 10
const double timelineThreshold = 10;

/// Y location for the top of a tick mark
const int TickTop = 15;

/// The spacing between ticks in the timeline
const int TickSpacing = 4;

/// The length of a short tick mark
const int TickShort = 10;

/// The length of a long tick mark
const int TickLong = 20;

/// Size of the tick mark labels
const int TickFontSize = 15;

/// Space to the left of the scale
const int BorderLeft = 10;

/// Space to the right of the scale
const int BorderRight = 10;

/// Filename for the pointer image
const std::wstring PointerImageFile = L"/pointer.png";

/**
 * Constructor
 * @param parent The main wxFrame object
 * @param imagesDir the image directory wstring
 */
ViewTimeline::ViewTimeline(wxFrame* parent, wstring imagesDir) :
    wxScrolledCanvas(parent,
            wxID_ANY,
            wxDefaultPosition,
            wxSize(100, Height),
            wxBORDER_SIMPLE)
{
    SetBackgroundStyle(wxBG_STYLE_PAINT);

    mPointerImage = make_unique<wxImage>(imagesDir + PointerImageFile, wxBITMAP_TYPE_ANY);

    Bind(wxEVT_PAINT, &ViewTimeline::OnPaint, this);
    Bind(wxEVT_LEFT_DOWN, &ViewTimeline::OnLeftDown, this);
    Bind(wxEVT_LEFT_UP, &ViewTimeline::OnLeftUp, this);
    Bind(wxEVT_MOTION, &ViewTimeline::OnMouseMove, this);
    parent->Bind(wxEVT_COMMAND_MENU_SELECTED,
                 &ViewTimeline::OnEditTimelineProperties, this,
                 XRCID("EditTimelineProperties"));
    parent->Bind(wxEVT_COMMAND_MENU_SELECTED, &ViewTimeline::OnSetKeyframe, this, XRCID("SetKeyframe"));
    parent->Bind(wxEVT_COMMAND_MENU_SELECTED, &ViewTimeline::OnDeleteKeyframe, this, XRCID("DeleteKeyframe"));

}


/**
 * Paint event, draws the window.
 * @param event Paint event object
 */
void ViewTimeline::OnPaint(wxPaintEvent& event)
{

    auto picture = GetPicture();
    auto size = picture->GetSize();
    auto timeline = picture->GetTimeline();
    auto numFrames = timeline->GetNumFrames();
    auto width = numFrames * TickSpacing + BorderRight + BorderLeft;
    auto height = size.GetHeight();
    auto currentFrame = timeline->GetCurrentFrame();
    SetVirtualSize(width,height);
    SetScrollRate(1,0);

    wxAutoBufferedPaintDC dc(this);
    wxBrush background(*wxWHITE);
    DoPrepareDC(dc);
    dc.SetBackground(background);
    dc.Clear();
    // Create a graphics context
    auto graphics = std::shared_ptr<wxGraphicsContext>(wxGraphicsContext::Create( dc ));
    wxPen pen(wxColour(0, 128, 0), 1);
    graphics->SetPen(pen);
    wxFont font(wxSize(0, 16),
                wxFONTFAMILY_SWISS,
                wxFONTSTYLE_NORMAL,
                wxFONTWEIGHT_NORMAL);
    graphics->SetFont(font, *wxBLACK);

    for(int tickNum = 0; tickNum < timeline->GetNumFrames() + 1; tickNum++)
    {
        // Convert the tick number to seconds in a string
        std::wstringstream str;
        str << tickNum / timeline->GetFrameRate();
        std::wstring wstr = str.str();

        double w, h;
        graphics->GetTextExtent(wstr, &w, &h);

        bool onSecond = (tickNum % timeline->GetFrameRate()) == 0;
        auto x1 = BorderLeft + TickSpacing * tickNum;
        auto x2 = x1;
        auto y1 = TickTop;
        auto y2 = TickTop + TickLong;

        if (onSecond)
        {
            graphics->StrokeLine(x1, y1 , x2, y2);
            graphics->DrawText(wstr,w/2 + TickSpacing*tickNum,h + TickLong);
        }
        else
        {
            y2 = TickTop + TickShort;
            graphics->StrokeLine(x1, y1 , x2, y2);
        }
    }

    if(mPointerBitmap.IsNull())
    {
        mPointerBitmap = graphics->CreateBitmapFromImage(*mPointerImage);
    }

    auto imageWidth = mPointerImage->GetWidth();
    auto imageHeight = mPointerImage->GetHeight();
    graphics->DrawBitmap(mPointerBitmap,
                         TickSpacing * currentFrame + 0.5 + TickSpacing, TickTop,
                         imageWidth,
                         imageHeight);



}

/**
 * Handle the left mouse button down event
 * @param event
 */
void ViewTimeline::OnLeftDown(wxMouseEvent &event)
{
    auto click = CalcUnscrolledPosition(event.GetPosition());

    int x = click.x;

    // Get the timeline
    Timeline *timeline = GetPicture()->GetTimeline();
    int pointerX = (int)(timeline->GetCurrentTime() *
        timeline->GetFrameRate() * TickSpacing + BorderLeft);

    mMovingPointer = x >= pointerX - mPointerImage->GetWidth() / 2 &&
        x <= pointerX + mPointerImage->GetWidth() / 2;
}

/**
* Handle the left mouse button up event
* @param event
*/
void ViewTimeline::OnLeftUp(wxMouseEvent &event)
{
    OnMouseMove(event);
}

/**
* Handle the mouse move event
* @param event
*/
void ViewTimeline::OnMouseMove(wxMouseEvent &event)
{
    auto click = CalcUnscrolledPosition(event.GetPosition());
    auto picture = GetPicture();
    auto timeline = picture->GetTimeline();
    auto frameRate = timeline->GetFrameRate();
    auto numFrames = timeline->GetNumFrames();
    auto xClick = double(click.x);
    double currentMoment = (xClick - BorderLeft) / (frameRate * TickSpacing);
    if (event.LeftIsDown())
    {
        if (currentMoment > timelineThreshold) {
            currentMoment = timelineThreshold;
        }
        else if (currentMoment > numFrames) {
            currentMoment = numFrames;
        }
        if (currentMoment > 0)
        {
            picture->SetAnimationTime(currentMoment);
        }
    }
}

/**
 * Force an update of this window when the picture changes.
 */
void ViewTimeline::UpdateObserver()
{
    Refresh();
}

/**
 * Handle an Edit>Timeline Properties... menu option
 * @param event The menu event
 */
void ViewTimeline::OnEditTimelineProperties(wxCommandEvent& event)
{
    auto currentPicture = GetPicture();
    TimelineDlg dlg(this->GetParent(), currentPicture->GetTimeline());
    if(dlg.ShowModal() == wxID_OK)
    {
        // The dialog box has changed the Timeline settings
        // Updates the window
        UpdateObserver();
    }
}

void ViewTimeline::OnSetKeyframe(wxCommandEvent& event)
{
    auto picture = GetPicture();
    for (auto actor : *picture)
    {
        actor->SetKeyframe();
    }
}

void ViewTimeline::OnDeleteKeyframe(wxCommandEvent& event)
{

}
