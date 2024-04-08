/**
 * @file TimelineDlg.h
 * @author Alex Beck
 *
 *
 */

#ifndef CANADIANEXPERIENCE_CANADIANEXPERIENCELIB_TIMELINEDLG_H
#define CANADIANEXPERIENCE_CANADIANEXPERIENCELIB_TIMELINEDLG_H

class Timeline;

/**
 * Timeline dialog box
 */

class TimelineDlg final : public wxDialog
{
private:

    /// Timeline object pointer
    Timeline * mTimeline = nullptr;

    /// Number of frames in the animation
    int mNumberOfFrames;

    /// Number of frame rate
    int mFrameRate;
public:

    TimelineDlg(wxWindow* parent, Timeline* timeline);

    void OnOK(wxCommandEvent& event);

};

#endif //CANADIANEXPERIENCE_CANADIANEXPERIENCELIB_TIMELINEDLG_H
