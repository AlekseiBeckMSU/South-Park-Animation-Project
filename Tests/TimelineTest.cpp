/**
 * @file TimelineTest.cpp
 * @author Alex Beck
 */

#include <pch.h>
#include "gtest/gtest.h"
#include <AnimChannelAngle.h>
#include <Timeline.h>

TEST(TimelineTest, numFrames)
{
    Timeline timeline;

    ASSERT_EQ(300, timeline.GetNumFrames());

    timeline.SetNumFrames(305);

    ASSERT_EQ(305, timeline.GetNumFrames());

    timeline.SetNumFrames(500);

    ASSERT_EQ(500, timeline.GetNumFrames());
}

TEST(TimelineTest, frameRate)
{
    Timeline timeline;

    ASSERT_EQ(30, timeline.GetFrameRate());

    timeline.SetFrameRate(100);

    ASSERT_EQ(100, timeline.GetFrameRate());

    timeline.SetFrameRate(200);

    ASSERT_EQ(200, timeline.GetFrameRate());
}

TEST(TimelineTest, currentTime)
{
    Timeline timeline;

    ASSERT_NEAR(0.0, timeline.GetCurrentTime(), 0.00001);

    timeline.SetCurrentTime(7.1);

    ASSERT_NEAR(7.1, timeline.GetCurrentTime(), 0.00001);

    timeline.SetCurrentTime(10.5);

    ASSERT_NEAR(10.5, timeline.GetCurrentTime(), 0.00001);
}

TEST(TimelineTest, GetDuration)
{
    Timeline timeline;

    // Default value
    ASSERT_NEAR(10, timeline.GetDuration(), 0.0001);

    // Changed duration
    timeline.SetFrameRate(375);
    ASSERT_NEAR(300.0 / 375.0, timeline.GetDuration(), 0.0001);

    timeline.SetNumFrames(789);
    ASSERT_NEAR(789.0 / 375.0, timeline.GetDuration(), 0.0001);
}

TEST(TimelineTest, GetCurrentFrame)
{
    Timeline timeline;

    // Default value
    ASSERT_EQ(0, timeline.GetCurrentFrame());

    // Changed time
    timeline.SetCurrentTime(9.27);
    ASSERT_EQ(278, timeline.GetCurrentFrame());
}

TEST(TimelineTest, Add)
{
    Timeline timeline;
    AnimChannelAngle channel;

    timeline.AddChannel(&channel);
    ASSERT_EQ(&timeline, channel.GetTimeline());
}