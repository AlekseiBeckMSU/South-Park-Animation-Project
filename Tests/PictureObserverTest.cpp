/**
 * @file PictureObserverTest.cpp
 * @author Alex Beck
 */

#include <pch.h>
#include "gtest/gtest.h"
#include <PictureObserver.h>
#include <Picture.h>

class PictureObserverMock : public PictureObserver
{
public:
    bool mUpdated = false;
    PictureObserverMock() : PictureObserver() {}
    virtual void UpdateObserver() override { mUpdated = true; }

};
TEST(PictureObserverTest, Construct) {
    PictureObserverMock observer;
}
TEST(PictureObserverTest, OneObserver) {
    // Allocate a Picture object
    auto picture = std::make_shared<Picture>();

    // Create a mock observer object
    PictureObserverMock observer;

    // And set it for the observer:
    observer.SetPicture(picture);

    picture->UpdateObservers();

    ASSERT_TRUE(observer.mUpdated);
}

TEST(PictureObserverTest, GetPicture){
    // Create a mock observer object
    PictureObserverMock getPictureObserver;

    // Allocate a Picture object
    auto getPicturePicture = std::make_shared<Picture>();

    // Set the observer to a Picture object
    getPictureObserver.SetPicture(getPicturePicture);

    // Assert that the picture returned from GetPicture() is the same as the Picture object
    ASSERT_EQ(getPictureObserver.GetPicture(), getPicturePicture);
}

TEST(PictureObserverTest, UpDateTwoObservers){
    // Create a mock observer object
    PictureObserverMock upDateObserver1;

    // Create a mock observer object
    PictureObserverMock upDateObserver2;

    // Allocate a Picture object
    auto upDateObserverPicture = std::make_shared<Picture>();

    // Set the observer to a Picture object
    upDateObserver1.SetPicture(upDateObserverPicture);

    // Set the observer to a Picture object
    upDateObserver2.SetPicture(upDateObserverPicture);

    // Update the picture's observers
    upDateObserverPicture->UpdateObservers();

    // Assert true that both observers were updated
    ASSERT_TRUE(upDateObserver1.mUpdated && upDateObserver2.mUpdated);
}

TEST(PictureObserverTest, observerDestroyed){
    // Create a mock observer object
    PictureObserverMock destroyObserver1;

    // Allocate a Picture object
    auto destroyObserverPicture = std::make_shared<Picture>();

    // Set the observer to a Picture object
    destroyObserver1.SetPicture(destroyObserverPicture);

    // Create a mock observer object
    PictureObserverMock destroyObserver2;

    // Set the observer to the same Picture object
    destroyObserver2.SetPicture(destroyObserverPicture);

    // Update the picture's observers
    destroyObserverPicture->UpdateObservers();

    // Assert true that observer 1 was updated
    ASSERT_EQ(true, destroyObserver1.mUpdated);
}

