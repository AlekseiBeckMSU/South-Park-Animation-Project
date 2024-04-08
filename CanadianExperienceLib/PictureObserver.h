/**
 * @file PictureObserver.h
 * @author Alex Beck
 *
 * Picture Observer class
 */

#ifndef CANADIANEXPERIENCE_CANADIANEXPERIENCELIB_PICTUREOBSERVER_H
#define CANADIANEXPERIENCE_CANADIANEXPERIENCELIB_PICTUREOBSERVER_H



class Picture;
/**
 * Observer base class for a picture.
 *
 * This class implements the base class functionality for
 * an observer in the observer pattern.
 */
class PictureObserver
{
protected:
    /// Constructor
    PictureObserver() {}
private:
    /// Picture we are observing
    std::shared_ptr<Picture> mPicture;

public:

    virtual ~PictureObserver();
    /// Copy Constructor (Disabled)
    PictureObserver(const PictureObserver &) = delete;
    /// Assignment Operator (Disabled)
    void operator=(const PictureObserver &) = delete;

    /**
     * Updates the observer
     */
    virtual void UpdateObserver() = 0;

    /**
     *
     * @return
     */
    std::shared_ptr<Picture> GetPicture() {return mPicture;}

    void SetPicture(std::shared_ptr<Picture> picture);
};

#endif //CANADIANEXPERIENCE_CANADIANEXPERIENCELIB_PICTUREOBSERVER_H
