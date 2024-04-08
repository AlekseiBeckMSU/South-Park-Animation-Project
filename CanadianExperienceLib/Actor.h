/**
 * @file Actor.h
 * @author Alex Beck
 *
 * Actor class to create actors
 */

#ifndef CANADIANEXPERIENCE_CANADIANEXPERIENCELIB_ACTOR_H
#define CANADIANEXPERIENCE_CANADIANEXPERIENCELIB_ACTOR_H

#include "AnimPositionChannel.h"

class Picture;
class Drawable;

/**
 * Class for actors in our drawings.
 *
 * An actor is some graphical object that consists of
 * one or more parts. Actors can be animated.
 */
class Actor {
private:
    /// The current channel of the position object
    AnimPositionChannel mCurrentChannel;

    /// The actor name
    std::wstring mName;

    /// Is this actor enabled (drawable)?
    bool mEnabled = true;

    /// The actor position
    wxPoint mPosition;

    /// Is this actor mouse clickable?
    bool mClickable = true;

    /// The root drawable
    std::shared_ptr<Drawable> mRoot;

    /// The drawables in drawing order
    std::vector<std::shared_ptr<Drawable>> mDrawablesInOrder;

    /// The pointer to the picture the current actor is from
    Picture *mPicture = nullptr;

public:

    /**
     * Gets the current position's current channel
     * @return mCurrentChannel
     */
    AnimPositionChannel *GetPositionChannel()  {return &mCurrentChannel;};

    /// Destructor
    virtual ~Actor() {}

    Actor(const std::wstring &name);

    /// Default constructor (disabled)
    Actor() = delete;

    /// Copy constructor (disabled)
    Actor(const Actor &) = delete;

    /// Assignment operator
    void operator=(const Actor &) = delete;

    void SetRoot(std::shared_ptr<Drawable> root);
    void Draw(std::shared_ptr<wxGraphicsContext> graphics);
    std::shared_ptr<Drawable> HitTest(wxPoint pos);
    void AddDrawable(std::shared_ptr<Drawable> drawable);

    /**
     * Get the actor name
     * @return Actor name
     */
    std::wstring GetName() const { return mName; }

    /**
     * The actor position
     * @return The actor position as a point
     */
    wxPoint GetPosition() const { return mPosition; }

    /**
     * The actor position
     * @param pos The new actor position
     */
    void SetPosition(wxPoint pos) { mPosition = pos; }

    /**
     * Actor is enabled
     * @return enabled status
     */
    bool IsEnabled() const { return mEnabled; }

    /**
     * Set Actor Enabled
     * @param enabled New enabled status
     */
    void SetEnabled(bool enabled) { mEnabled = enabled; }

    /**
     * Actor is clickable
     * @return true if actor is clickable
     */
    bool IsClickable() const { return mClickable; }

    /**
     * Actor clickable
     * @param clickable New clickable status
     */
    void SetClickable(bool clickable) { mClickable = clickable; }

    /**
     * Set picture to parameter
     * @param picture
     */
    void SetPicture(Picture *picture);

    /**
     * Get the current picture
     * @return mPicture
     */
    Picture* GetPicture() const { return mPicture; }

    void SetKeyframe();
    void GetKeyframe();

    /**
     * Sets the current timeline object to mTimeline
     * @param timeline
     */
    void SetTimeline(Timeline *timeline);
};
#endif //CANADIANEXPERIENCE_CANADIANEXPERIENCELIB_ACTOR_H
