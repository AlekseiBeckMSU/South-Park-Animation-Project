/**
 * @file PictureFactory.h
 * @author Alex Beck
 *
 * PictureFactory class that creates the picture
 */

#ifndef CANADIANEXPERIENCE_CANADIANEXPERIENCELIB_PICTUREFACTORY_H
#define CANADIANEXPERIENCE_CANADIANEXPERIENCELIB_PICTUREFACTORY_H

class Picture;
/**
 * Class that is a factory for creating te picture object
 */
class PictureFactory
{
private:

public:

    std::shared_ptr<Picture> Create(std::wstring imagesDir);

};

#endif //CANADIANEXPERIENCE_CANADIANEXPERIENCELIB_PICTUREFACTORY_H
