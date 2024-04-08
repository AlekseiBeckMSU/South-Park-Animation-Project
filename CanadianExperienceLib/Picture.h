/**
 * @file Picture.h
 * @author Alex Beck
 *
 * Picture class that contains the current observers and current actors
 */


#ifndef CANADIANEXPERIENCE_CANADIANEXPERIENCELIB_PICTURE_H
#define CANADIANEXPERIENCE_CANADIANEXPERIENCELIB_PICTURE_H

#include "Timeline.h"

class Actor;
class PictureObserver;
/**
 * The picture we are drawing.
 *
 * There will be one picture object that contains all of
 * our actors, which then contains the drawables.
 */
class Picture
{
private:
    /// The picture size
    wxSize mSize = wxSize(1500, 800);

    /// Vector of all observers
    std::vector<PictureObserver *> mObservers;

    /// Vector of all the actors
    std::vector<std::shared_ptr<Actor>> mActors;

    /// The animation timeline
    Timeline mTimeline;
public:
    Picture() {}
    /// Copy Constructor (Disabled)
    Picture(const Picture &) = delete;
    /// Assignment Operator (Disabled)
    void operator=(const Picture &) = delete;

    /**
     * Get the picture size
     * @return Picture size in pixels
     */
    wxSize GetSize() {return mSize;}

    /**
     * Set the picture size
     * @param size Picture size in pixels
     */
    void SetSize(wxSize size) {mSize = size;}

    void AddObserver(PictureObserver *observer);

    void RemoveObserver(PictureObserver *observer);

    void UpdateObservers();

    void Draw(std::shared_ptr<wxGraphicsContext> graphics);

    void AddActor(std::shared_ptr<Actor> actor);

    /// Actor iterator
    class ActorIterator
    {
    public:
        /** Constructor
         * @param picture The picture we are iterating over
         * @param pos Position in the collection
         */
        ActorIterator(Picture* picture, int pos) : mPicture(picture), mPos(pos) {}

        /**
         * Compare two iterators
         * @param other The other iterator we are comparing to
         * @return  true if this position is not equal to the other position
        */
        bool operator!=(const ActorIterator& other) const
        {
            return mPos != other.mPos;
        }

        /**
         * Get value at current position
         * @return Value at mPos in the collection
         */
        std::shared_ptr<Actor> operator *() const { return mPicture->mActors[mPos]; }

        /**
         * Increment the iterator
         * @return Reference to this iterator */
        const ActorIterator& operator++()
        {
            mPos++;
            return *this;
        }

    private:
        Picture* mPicture;   ///< Picture we are iterating over
        int mPos;       ///< Position in the collection
    };
    /**
     * Get an iterator for the beginning of the collection
     * @return Iter object at position 0
     */
    ActorIterator begin() { return ActorIterator(this, 0); }

    /**
     * Get an iterator for the end of the collection
     * @return Iter object at position past the end
     */
    ActorIterator end() { return ActorIterator(this, mActors.size()); }

    /**
     * Get a pointer to the Timeline object
     * @return Pointer to the Timeline object
     */
    Timeline *GetTimeline() {return &mTimeline;}

    void SetAnimationTime(double time);

};

#endif //CANADIANEXPERIENCE_CANADIANEXPERIENCELIB_PICTURE_H
