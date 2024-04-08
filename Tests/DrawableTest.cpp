/**
 * @file DrawableTest.cpp
 * @author Alex Beck
 */

#include <pch.h>
#include "gtest/gtest.h"
#include <Drawable.h>

class DrawableMock : public Drawable
{
public:
    DrawableMock(const std::wstring &name) : Drawable(name) {}
    virtual void Draw(std::shared_ptr<wxGraphicsContext> graphics) override {}
    virtual bool HitTest(wxPoint pos) override {return true;}
};

TEST(DrawableTest, Constructor)
{
    // Create DrawableMock object and set the mName wstring to Alex
    DrawableMock drawablemock(L"Alex");

    // Assert that the constructor setter set the name to Alex and the getter gets the wstring Alex
    ASSERT_EQ(L"Alex", drawablemock.GetName());
}

TEST(DrawableTest, Position)
{
    // Create DrawableMock object and set the mName wstring to Alex
    DrawableMock drawablemock(L"Alex");

    // Assert that the default position value is (0,0) while also testing GetPosition
    ASSERT_EQ(wxPoint(0,0), drawablemock.GetPosition());

    // Set the position to a test value (20, 20)
    drawablemock.SetPosition(wxPoint(20, 20));

    // Test if the setter set the position correctly to (20, 20) and tests the getter to return (20, 20)
    ASSERT_EQ(wxPoint(20, 20), drawablemock.GetPosition());

}

TEST(DrawableTest, Rotation)
{
    // Create DrawableMock object and set the mName wstring to Alex
    DrawableMock drawablemock(L"Alex");

    // Assert that the default value is 0 while also testing the getter to return 0
    ASSERT_EQ(0, drawablemock.GetRotation());

    // Set the rotation to a value 20
    drawablemock.SetRotation(20);

    // Test the setter and getter of rotation to return 20
    ASSERT_EQ(20, drawablemock.GetRotation());

    // Set the rotation to a value 1.23 to test floating point numbers
    drawablemock.SetRotation(1.23);

    // Test the setter and getter of rotation to return the floating point number and test accuracy
    ASSERT_NEAR(1.23, drawablemock.GetRotation(), 0.00001);
}

TEST(DrawableTest, Association)
{
    DrawableMock body(L"Body");
    auto arm = std::make_shared<DrawableMock>(L"Arm");
    auto leg = std::make_shared<DrawableMock>(L"Leg");

    ASSERT_EQ(nullptr, arm->GetParent());
    ASSERT_EQ(nullptr, leg->GetParent());

    body.AddChild(arm);
    body.AddChild(leg);

    ASSERT_EQ(&body, arm->GetParent());
    ASSERT_EQ(&body, leg->GetParent());
}