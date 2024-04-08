/**
 * @file AnimChannel.h
 * @author Alex Beck
 *
 *
 */

#ifndef CANADIANEXPERIENCE_CANADIANEXPERIENCELIB_ANIMCHANNEL_H
#define CANADIANEXPERIENCE_CANADIANEXPERIENCELIB_ANIMCHANNEL_H

class Timeline;

/**
 * Base class for animation channels
 *
 * This class provides basic functionality and a polymorphic
 * representation for animation channels.
 */

class AnimChannel
{
private:
    /// Animation Name
    std::wstring mName;

    /// Keyframe 1
    int mKeyframe1 = -1;

    /// Keyframe 2
    int mKeyframe2 = -1;

    /// Time line object
    Timeline *mTimeline = nullptr;

protected:
    /// Default constructor
    AnimChannel() { }

    /// Class that represents a keyframe
    class Keyframe
    {
    private:

        /// Current frame
        int mFrame;

        /// The channel this keyframe is associated with
        AnimChannel *mChannel;
    protected:
        /**
         * Constructor
         * @param channel Channel we are associated with
         */
        Keyframe(AnimChannel *channel) : mChannel(channel) {}
    public:

        /// Default constructor (disabled)
        Keyframe() = delete;
        
        /// Copy constructor (disabled)
        Keyframe(const Keyframe &) = delete;
        
        /// Assignment operator
        void operator=(const Keyframe &) = delete;
        
        
        /**
         * Getter for mFrame
         * @return mFrame
         */
        int GetFrame() {return mFrame;}

        /**
         * Setter for mFrame
         * @param frame
         */
        void SetFrame(int frame) {mFrame = frame;}

        /**
         * Use animation function set to 0
         */
        virtual void UseAs1() = 0;

        /**
         * Use animation function 2 set to 0
         */
        virtual void UseAs2() = 0;

        /**
         * Use animation function 3 set to 0
         */
        virtual void UseOnly() = 0;

    };

    void InsertKeyframe(std::shared_ptr<Keyframe> keyframe);

    /**
     * Tween function set to 0
     * @param t
     */
    virtual void Tween(double t) = 0;

private:

    /// The collection of keyframes for this channel
    std::vector<std::shared_ptr<Keyframe>> mKeyframes;

public:

    /// Copy constructor (disabled)
    AnimChannel(const AnimChannel &) = delete;

    /// Assignment operator
    void operator=(const AnimChannel &) = delete;

    /// Destructor
    virtual ~AnimChannel(){};

    /**
     * gets name
     * @return mName
     */
    std::wstring GetName() const {return mName;}

    /**
     * sets name
     * @param name
     */
    void SetName(std::wstring name) {mName = name;}

    /**
     * returns a bool of if it is valid or not
     * @return
     */
    bool IsValid();

    void SetFrame(int currFrame);

    /**
     * gets the timeline
     * @return mTimeline
     */
    Timeline* GetTimeline() const {return mTimeline;}

    /**
     * sets the time line
     * @param timeline
     */
    void SetTimeline(Timeline* timeline) {mTimeline = timeline;}

};

#endif //CANADIANEXPERIENCE_CANADIANEXPERIENCELIB_ANIMCHANNEL_H
