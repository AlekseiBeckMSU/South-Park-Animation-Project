/**
 * @file AnimPositionChannel.cpp
 * @author Alex Beck
 */

#include "pch.h"
#include "AnimPositionChannel.h"

void AnimPositionChannel::Tween(double t)
{
    auto point1 = mKeyframe1->GetCurrentPoint();
    auto point2 = mKeyframe2->GetCurrentPoint();
    double xx = point1.x * (1 - t) + point2.x * t;
    double yy = point1.y * (1 - t) + point2.y * t;
    mCurrentPoint = wxPoint((xx), (yy));
}

void AnimPositionChannel::SetKeyframe(wxPoint point)
{
    // Create a keyframe of the appropriate type
    // Telling it this channel and the angle
    auto keyframe = std::make_shared<KeyframePoint>(this, point);

    // Insert it into the collection
    InsertKeyframe(keyframe);
}