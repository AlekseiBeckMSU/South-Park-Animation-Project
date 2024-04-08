/**
 * @file AlexFactory.h
 * @author Alex Beck
 *
 * Alex factory class that is a factory for alex character
 */

#ifndef CANADIANEXPERIENCE_CANADIANEXPERIENCELIB_ALEXFACTORY_H
#define CANADIANEXPERIENCE_CANADIANEXPERIENCELIB_ALEXFACTORY_H


/**
 * Actor class
 */
class Actor;
/**
 * Factory class that builds the Alex character
 */
class AlexFactory
{
private:

public:

    std::shared_ptr<Actor> Create(std::wstring imagesDir);

};
#endif //CANADIANEXPERIENCE_CANADIANEXPERIENCELIB_ALEXFACTORY_H
