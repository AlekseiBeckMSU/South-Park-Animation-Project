/**
 * @file PolyDrawable.h
 * @author Alex Beck
 *
 * PolyDrawable class to contain all points and path
 */

#ifndef CANADIANEXPERIENCE_CANADIANEXPERIENCELIB_POLYDRAWABLE_H
#define CANADIANEXPERIENCE_CANADIANEXPERIENCELIB_POLYDRAWABLE_H

#include "Drawable.h"

/**
 * A drawable based on polygon images.
 *
 * This class has a list of points and draws a polygon
 * drawable based on those points.
 */

class PolyDrawable : public Drawable
{
private:

    /// The polygon color
    wxColour mColor = *wxBLACK;

    /// The array of point objects
    std::vector<wxPoint> mPoints;

    /// The transformed graphics path used
    /// to draw this polygon
    wxGraphicsPath mPath;

public:

    /**
     * Set the color
    * @param color The new color to be set
     */
    void SetColor(wxColour color) {mColor = color;}

    /**
     * Get the current color
     * @return The current color
     */
    wxColour GetColor() const {return mColor;}

    /**
     * Constructor
     * @param name PolyDrawable name
     */
    PolyDrawable(const std::wstring &name);
    
    /// Default constructor (disabled)
    PolyDrawable() = delete;
    
    /// Copy constructor (disabled)
    PolyDrawable(const PolyDrawable &) = delete;
    
    /// Assignment operator
    void operator=(const PolyDrawable &) = delete;

    void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;

    bool HitTest(wxPoint pos) override;

    void AddPoint(wxPoint point);
};

#endif //CANADIANEXPERIENCE_CANADIANEXPERIENCELIB_POLYDRAWABLE_H
