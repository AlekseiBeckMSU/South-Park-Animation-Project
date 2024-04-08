/**
 * @file HeadTop.h
 * @author Alex Beck
 *
 * HeadTop class that draws eyes and eyebrows
 */

#ifndef CANADIANEXPERIENCE_CANADIANEXPERIENCELIB_HEADTOP_H
#define CANADIANEXPERIENCE_CANADIANEXPERIENCELIB_HEADTOP_H

#include "ImageDrawable.h"
#include "AnimPositionChannel.h"

/**
 * HeadTop class that draws the head for each character
 */

class HeadTop : public ImageDrawable
{
private:
    /// Current AnimPositionChannel channel value
    AnimPositionChannel mChannel;

    /// mHaroldHead string used to check which head to draw
    const std::string mHaroldHead = "HaroldHead";

    /// mAlexHead string used to check which head to draw
    const std::string mAlexHead = "AlexHead";

    /// mCurrentHead string used to check which head is the current one in order to draw
    std::string mCurrentHead = "HaroldHead";

public:
    /**
     * Setter for the current Timeline object timeline
     * @param timeline
     */
    void SetTimeline(Timeline *timeline) override;

    /**
     * Setter for the current keyframe
     */
    void SetKeyframe() override;

    /**
     * Getter for the current keyframe
     */
    void GetKeyframe() override;

    /// Default constructor (disabled)
    HeadTop() = delete;
    
    /// Copy constructor (disabled)
    HeadTop(const HeadTop &) = delete;
    
    /// Assignment operator
    void operator=(const HeadTop &) = delete;

    /**
     * Getter for movable
     * @return
     */
    bool IsMovable() override;

    /**
     * Constructor
     * @param characterName
     * @param imageFile
     */
    HeadTop(const std::wstring &characterName, const std::wstring &imageFile);

    /**
     * Draws a character
     * @param graphics
     */
    void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;

    wxPoint TransformPoint(wxPoint p);

    void DrawCharacterHarold(std::shared_ptr<wxGraphicsContext> graphics);

    void DrawOneEyeBrow(std::shared_ptr<wxGraphicsContext> graphics, wxPoint firstEyeBrowPoint, wxPoint secondEyeBrowPoint);

    void DrawOneEye(std::shared_ptr<wxGraphicsContext> graphics, wxPoint eyePoint);

    void DrawCharacterAlex(std::shared_ptr<wxGraphicsContext> graphics);

    /**
     * Sets the current head to whichever still needs to be drawn
     * @param head
     */
    void SetCurrentHead(std::string head) {mCurrentHead = head;}
    
    
};

#endif //CANADIANEXPERIENCE_CANADIANEXPERIENCELIB_HEADTOP_H
