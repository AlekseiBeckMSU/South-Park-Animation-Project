/**
 * @file AnimChannelAngle.h
 * @author Alex Beck
 *
 *
 */

#ifndef CANADIANEXPERIENCE_CANADIANEXPERIENCELIB_ANIMCHANNELANGLE_H
#define CANADIANEXPERIENCE_CANADIANEXPERIENCELIB_ANIMCHANNELANGLE_H

#include "AnimChannel.h"

/**
 * Animation channel for angles.
 */

class AnimChannelAngle : public AnimChannel
{
private:

    /// Current angle
    double mAngle = 0;



protected:

    /// Class that represents a keyframe
    class KeyframeAngle : public Keyframe
    {
    private:

        /// Current angle
        double mAngle;

        /// The channel this keyframe is associated with
        AnimChannelAngle *mChannel;

    public:
        /// Default constructor (disabled)
        KeyframeAngle() = delete;

        /// Copy constructor (disabled)
        KeyframeAngle(const KeyframeAngle &) = delete;

        /// Assignment operator
        void operator=(const KeyframeAngle &) = delete;

        /**
         * Constructor
         * @param channel The channel we are for
         * @param angle The angle for the keyframe
         */
        KeyframeAngle(AnimChannelAngle *channel, double angle) :
            Keyframe(channel), mChannel(channel), mAngle(angle) {}

        /**
         * getter for angle
         * @return mAngle
         */
        double GetAngle() {return mAngle;}

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
        void UseOnly() override { mChannel->mAngle = mAngle; };

    };

    void Tween(double t) override;

private:
    /// The first angle keyframe
    KeyframeAngle *mKeyframe1 = nullptr;

    /// The second angle keyframe
    KeyframeAngle *mKeyframe2 = nullptr;

public:

    /// Copy constructor (disabled)
    AnimChannelAngle(const AnimChannelAngle &) = delete;

    /// Assignment operator
    void operator=(const AnimChannelAngle &) = delete;

    /// Default constructor
    AnimChannelAngle(){}

    /// Destructor
    ~AnimChannelAngle() override {};

    /**
     * Getter for mAngle
     * @return
     */
    double GetAngle() const {return mAngle;}

    void SetKeyframe(double angle);


};

#endif //CANADIANEXPERIENCE_CANADIANEXPERIENCELIB_ANIMCHANNELANGLE_H
