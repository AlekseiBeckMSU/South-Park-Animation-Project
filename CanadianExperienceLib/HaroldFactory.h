/**
 * @file HaroldFactory.h
 * @author Alex Beck
 *
 * Harold factory class that is a factory for harold character
 */

#ifndef CANADIANEXPERIENCE_CANADIANEXPERIENCELIB_HAROLDFACTORY_H
#define CANADIANEXPERIENCE_CANADIANEXPERIENCELIB_HAROLDFACTORY_H


/**
 * Actor class
 */
class Actor;
/**
 * Factory class that builds the Harold character
 */
class HaroldFactory
{
private:

public:

    std::shared_ptr<Actor> Create(std::wstring imagesDir);

};

#endif //CANADIANEXPERIENCE_CANADIANEXPERIENCELIB_HAROLDFACTORY_H
