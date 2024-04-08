/**
 * @file ImageDrawable.h
 * @author Alex Beck
 *
 * ImageDrawable class contains the bitmap and current center of drawables
 */

#ifndef CANADIANEXPERIENCE_CANADIANEXPERIENCELIB_IMAGEDRAWABLE_H
#define CANADIANEXPERIENCE_CANADIANEXPERIENCELIB_IMAGEDRAWABLE_H

#include "Drawable.h"

/**
 * Image drawable class, contains the bitmap and current center of drawables
 */
class ImageDrawable : public Drawable
{
private:

    /// Center point
    wxPoint mCenter = wxPoint(0, 0);

    /// The graphics bitmap we will use
    wxGraphicsBitmap mBitmap;

public:

    /// Default constructor (disabled)
    ImageDrawable() = delete;

    /// Copy constructor (disabled)
    ImageDrawable(const ImageDrawable &) = delete;

    /// Assignment operator
    void operator=(const ImageDrawable &) = delete;


    ImageDrawable(const std::wstring &name, const std::wstring &filename);

    void Draw(std::shared_ptr<wxGraphicsContext> graphics);

    bool HitTest(wxPoint pos);

    /**
     * Center point getter
     * @return mCenter value that is the center point
     */
    wxPoint GetCenter() {return mCenter;}

    /**
     * Center point setter
     * @param center center point value
     */
    void SetCenter(wxPoint center) {mCenter = center;}

protected:

    /// The image we are drawing
    std::unique_ptr<wxImage> mImage;

};

#endif //CANADIANEXPERIENCE_CANADIANEXPERIENCELIB_IMAGEDRAWABLE_H
