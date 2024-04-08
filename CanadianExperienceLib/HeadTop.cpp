/**
 * @file HeadTop.cpp
 * @author Alex Beck
 */

#include "pch.h"
#include "HeadTop.h"
#include "Timeline.h"

using namespace std;

bool HeadTop::IsMovable()
{
    return true;
}


HeadTop::HeadTop(const std::wstring &characterName, const std::wstring &imageFile) :
ImageDrawable(characterName, imageFile)
{
    mImage = make_unique<wxImage>(imageFile, wxBITMAP_TYPE_ANY);
}

/** Transform a point from a location on the bitmap to
*  a location on the screen.
* @param  p Point to transform
* @returns Transformed point
*/
wxPoint HeadTop::TransformPoint(wxPoint p)
{
    // Make p relative to the image center
    p = p - GetCenter();

    // Rotate as needed and offset
    return RotatePoint(p, mPlacedR) + mPlacedPosition;
}

void HeadTop::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
    ImageDrawable::Draw(graphics);

    if (mCurrentHead == mHaroldHead)
    {
        DrawCharacterHarold(graphics);
    }
    else if (mCurrentHead == mAlexHead)
    {
        DrawCharacterAlex(graphics);
    }
}

/**
 * Draw one eyebrow for the current character
 * @param graphics
 * @param firstEyeBrowPoint
 * @param secondEyeBrowPoint
 */
void HeadTop::DrawOneEyeBrow(std::shared_ptr<wxGraphicsContext> graphics, wxPoint firstEyeBrowPoint, wxPoint secondEyeBrowPoint)
{
    wxPen eyebrowPen(*wxBLACK, 2);
    graphics->SetPen(eyebrowPen);
    graphics->StrokeLine(firstEyeBrowPoint.x, firstEyeBrowPoint.y, secondEyeBrowPoint.x, secondEyeBrowPoint.y);
}

/**
 * Draws one eye for the current character
 * @param graphics
 * @param eyePoint
 */
void HeadTop::DrawOneEye(std::shared_ptr<wxGraphicsContext> graphics, wxPoint eyePoint)
{
    // set color of brush
    wxBrush brush(wxColour(0,0,0));

    float wid = 15.0f;
    float hit = 20.0f;

    // set brush to graphics to it can use it to fill in the elipses
    graphics->SetBrush(brush);

    graphics->PushState();
    graphics->Translate(eyePoint.x, eyePoint.y);
    graphics->Rotate(-mPlacedR);
    graphics->DrawEllipse(-wid/2, -hit/2, wid, hit);
    graphics->PopState();
}

/**
 * Draws both eyes and both eyebrows for Harold character
 * @param graphics
 */
void HeadTop::DrawCharacterHarold(std::shared_ptr<wxGraphicsContext> graphics)
{
    // draw left eye
    DrawOneEye(graphics,TransformPoint(wxPoint(75, 72)));

    // draw left eyebrow
    DrawOneEyeBrow(graphics,TransformPoint(wxPoint(25, 57)),TransformPoint(wxPoint(42, 57)));

    // draw right eye
    DrawOneEye(graphics,TransformPoint(wxPoint(35, 72)));

    // draw right eyebrow
    DrawOneEyeBrow(graphics,TransformPoint(wxPoint(68, 57)), TransformPoint(wxPoint(85, 57)));
}

/**
 * Draws both eyes and both eyebrows for Alex character
 * @param graphics
 */
void HeadTop::DrawCharacterAlex(std::shared_ptr<wxGraphicsContext> graphics)
{
    // draw left eye
    DrawOneEye(graphics,TransformPoint(wxPoint(95, 72)));

    // draw left eyebrow
    DrawOneEyeBrow(graphics,TransformPoint(wxPoint(45, 57)),TransformPoint(wxPoint(62, 57)));

    // draw right eye
    DrawOneEye(graphics,TransformPoint(wxPoint(55, 72)));

    // draw right eyebrow
    DrawOneEyeBrow(graphics,TransformPoint(wxPoint(88, 57)), TransformPoint(wxPoint(105, 57)));
}
void HeadTop::SetTimeline(Timeline *timeline)
{
    Drawable::SetTimeline(timeline);
    timeline->AddChannel(&mChannel);
}
void HeadTop::SetKeyframe()
{
    Drawable::SetKeyframe();
    mChannel.SetKeyframe(GetPosition());
}
void HeadTop::GetKeyframe()
{
    Drawable::GetKeyframe();
    if(mChannel.IsValid())
    {
        SetPosition(mChannel.GetPoint());
    }
}

