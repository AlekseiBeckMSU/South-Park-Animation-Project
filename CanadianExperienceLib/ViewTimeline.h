/**
 * @file ViewTimeline.h
 * @author Alex Beck
 *
 * View class for the timeline area of the screen.
 */

#ifndef CANADIANEXPERIENCE_VIEWTIMELINE_H
#define CANADIANEXPERIENCE_VIEWTIMELINE_H

#include "PictureObserver.h"

/**
 * View class for the timeline area of the screen.
 */
class ViewTimeline final : public wxScrolledCanvas, public PictureObserver {
private:
    void OnLeftDown(wxMouseEvent &event);
    void OnLeftUp(wxMouseEvent& event);
    void OnMouseMove(wxMouseEvent& event);
    void OnPaint(wxPaintEvent& event);

    /// Bitmap image for the pointer
    std::unique_ptr<wxImage> mPointerImage;

    /// Graphics bitmap to display
    wxGraphicsBitmap mPointerBitmap;

    /// Flag to indicate we are moving the pointer
    bool      mMovingPointer = false;

public:

    static const int Height = 90;      ///< Height to make this window

    ViewTimeline(wxFrame* parent, std::wstring imagesDir);

    void UpdateObserver() override;

    void OnEditTimelineProperties(wxCommandEvent& event);

    /**
     * Set key frame handler, sets keyframe
     * @param event
     */
    void OnSetKeyframe(wxCommandEvent& event);

    /**
     * Delete key frame handler, deletes keyframe
     * @param event
     */
    void OnDeleteKeyframe(wxCommandEvent& event);
};


#endif //CANADIANEXPERIENCE_VIEWTIMELINE_H
