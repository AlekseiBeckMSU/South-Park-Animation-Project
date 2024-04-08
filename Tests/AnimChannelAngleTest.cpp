/**
 * @file AnimChannelAngleTest.cpp
 * @author Alex Beck
 */

#include <pch.h>
#include "gtest/gtest.h"
#include <AnimChannelAngle.h>

TEST(AnimChannelAngleTest, Name)
{
    /// create anim channel angle object
    AnimChannelAngle animChannelAngle;

    /// assert the default value is empty by also testing the getter
    ASSERT_EQ(L"", animChannelAngle.GetName());

    /// set the name to Alex
    animChannelAngle.SetName(L"Alex");

    /// test that the setter and getter work by checking if the name was changed to Alex
    ASSERT_EQ(L"Alex", animChannelAngle.GetName());
}



