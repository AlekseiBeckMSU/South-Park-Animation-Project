/**
 * @file Drawable.h
 * @author Alex Beck
 *
 * Drawable class for positioning and location of drawables
 */

#ifndef CANADIANEXPERIENCE_CANADIANEXPERIENCELIB_DRAWABLE_H
#define CANADIANEXPERIENCE_CANADIANEXPERIENCELIB_DRAWABLE_H

#include "AnimChannel.h"
#include "AnimChannelAngle.h"
#include "AnimPositionChannel.h"

class Actor;

/**
 * Abstract base class for drawable elements of our picture.
 *
 * A drawable is one part of an actor. Drawable parts can be moved
 * independently.
 */

class Drawable {
private:

    /// The animation channel for animating the angle of this drawable
    AnimChannelAngle mChannel;

    /// The drawable name
    std::wstring mName;

    /// The position of this drawable relative to its parent
    wxPoint mPosition = wxPoint(0, 0);

    /// The rotation of this drawable relative to its parent
    double mRotation = 0;

    /// The actor using this drawable
    Actor *mActor = nullptr;

    /// Vector of all children
    std::vector<std::shared_ptr<Drawable>> mChildren;

    /// current parent drawable object
    Drawable *mParent = nullptr;

protected:
    Drawable(const std::wstring &name);

    wxPoint RotatePoint(wxPoint point, double angle);

    /// The actual postion in the drawing
    wxPoint mPlacedPosition = wxPoint(0, 0);

    /// The actual rotation in the drawing
    double mPlacedR = 0;

public:

    /// Destructor
    virtual ~Drawable() {}

    /// Default constructor (disabled)
    Drawable() = delete;

    /// Copy constructor (disabled)
    Drawable(const Drawable &) = delete;

    /// Assignment operator
    void operator=(const Drawable &) = delete;

    void SetActor(Actor* actor);

    void Place(wxPoint offset, double rotate);

    void AddChild(std::shared_ptr<Drawable> child);

    void Move(wxPoint delta);

    /**
     * Draw this drawable
     * @param graphics Graphics object to draw on
     */
    virtual void Draw(std::shared_ptr<wxGraphicsContext> graphics) = 0;

    /**
     * Test to see if we have been clicked on by the mouse
     * @param pos Position to test
     * @return true if clicked on
     */
    virtual bool HitTest(wxPoint pos) = 0;

    /**
     * Is this a movable drawable?
     * @return true if movable
     */
    virtual bool IsMovable() { return false; }

    /**
     * Set the drawable position
     * @param pos The new drawable position
     */
    void SetPosition(wxPoint pos) { mPosition = pos; }

    /**
     * Get the drawable position
     * @return The drawable position
     */
    wxPoint GetPosition() const { return mPosition; }

    /**
     * Set the rotation angle in radians
    * @param r The new rotation angle in radians
     */
    void SetRotation(double r) { mRotation = r; }

    /**
     * Get the rotation angle in radians
     * @return The rotation angle in radians
     */
    double GetRotation() const { return mRotation; }

    /**
     * Get the drawable name
     * @return The drawable name
     */
    std::wstring GetName() const { return mName; }

    /**
     * Get parent, Returns current parent
     * @return mParent
     */
    Drawable* GetParent() const { return mParent; }

    /**
     * Sets the current parent to parameter drawable parent
     * @param parent
     */
    void SetParent(Drawable* parent) { mParent = parent; }

    virtual void SetTimeline(Timeline *timeline);

    /**
     * The angle animation channel
     * @return Pointer to animation channel
     */
    AnimChannelAngle *GetAngleChannel() { return &mChannel; }

    virtual void SetKeyframe();
    virtual void GetKeyframe();
};

#endif //CANADIANEXPERIENCE_CANADIANEXPERIENCELIB_DRAWABLE_H
