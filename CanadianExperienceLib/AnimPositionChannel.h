/**
 * @file AnimPositionChannel.h
 * @author Alex Beck
 *
 *
 */

#ifndef CANADIANEXPERIENCE_CANADIANEXPERIENCELIB_ANIMPOSITIONCHANNEL_H
#define CANADIANEXPERIENCE_CANADIANEXPERIENCELIB_ANIMPOSITIONCHANNEL_H

#include "AnimChannel.h"

/**
 * Animation channel for position/point.
 */

class AnimPositionChannel : public AnimChannel
{
private:

    /// Current wxPoint point
    wxPoint mCurrentPoint;

protected:

    /// Class that represents a keyframe point
    class KeyframePoint : public Keyframe
    {
    private:

        /// Current angle
        wxPoint mCurrentPoint;

        /// The channel this keyframe is associated with
        AnimPositionChannel *mChannel;

    public:
        /// Default constructor (disabled)
        KeyframePoint() = delete;

        /// Copy constructor (disabled)
        KeyframePoint(const KeyframePoint &) = delete;

        /// Assignment operator
        void operator=(const KeyframePoint &) = delete;

        /**
         * Constructor
         * @param channel The channel we are for
         * @param point The point for the keyframe
         */
        KeyframePoint(AnimPositionChannel *channel, wxPoint point) :
            Keyframe(channel), mChannel(channel), mCurrentPoint(point) {}

        /**
         * getter for angle
         * @return mAngle
         */
        wxPoint GetCurrentPoint() {return mCurrentPoint;}

        /**
         * sets As1
         */
        void UseAs1() override { mChannel->mKeyframe1 = this; };

        /**
         * sets As1
         */
        void UseAs2() override { mChannel->mKeyframe2 = this; };
        /**
          * sets As1
          */
        void UseOnly() override { mChannel->mCurrentPoint = mCurrentPoint; };

    };

    /**
     * sets tween
     * @param t
     */
    void Tween(double t) override;

private:
    /// The first angle keyframe
    KeyframePoint *mKeyframe1 = nullptr;

    /// The second angle keyframe
    KeyframePoint *mKeyframe2 = nullptr;

public:

    /// Copy constructor (disabled)
    AnimPositionChannel(const AnimPositionChannel &) = delete;

    /// Assignment operator
    void operator=(const AnimPositionChannel &) = delete;

    /// Default constructor
    AnimPositionChannel(){}

    /// Destructor
    ~AnimPositionChannel() override {};

    /**
     * Getter for mCurrentPointer
     * @return
     */
    wxPoint GetPoint() const {return mCurrentPoint;}

    /**
     * Setter for current keyframe using a wxPoint variable
     * @param point
     */
    void SetKeyframe(wxPoint point);

};

#endif //CANADIANEXPERIENCE_CANADIANEXPERIENCELIB_ANIMPOSITIONCHANNEL_H
