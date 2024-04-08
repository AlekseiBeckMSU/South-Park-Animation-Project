/**
 * @file PolyDrawable.cpp
 * @author Alex Beck
 */

#include "pch.h"
#include "PolyDrawable.h"

PolyDrawable::PolyDrawable(const std::wstring &name) : Drawable(name)
{
}

/**
 * Draw the current graphics
 * @param graphics
 */
void PolyDrawable::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
    if(!mPoints.empty()) {

        mPath = graphics->CreatePath();
        mPath.MoveToPoint(RotatePoint(mPoints[0], mPlacedR) + mPlacedPosition);
        for (auto i = 1; i<mPoints.size(); i++)
        {
            mPath.AddLineToPoint(RotatePoint(mPoints[i], mPlacedR) + mPlacedPosition);
        }
        mPath.CloseSubpath();

        wxBrush brush(mColor);
        graphics->SetBrush(brush);
        graphics->FillPath(mPath);
    }
}

/**
 * HitTests for PolyDrawable objects
 * @param pos
 * @return
 */
bool PolyDrawable::HitTest(wxPoint pos)
{
    return mPath.Contains(pos.x, pos.y);
}

/**
 * Adds a point to the collection of points
 * @param point
 */
void PolyDrawable::AddPoint(wxPoint point)
{
    mPoints.push_back(point);
}