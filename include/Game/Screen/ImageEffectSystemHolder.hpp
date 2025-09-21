#pragma once

#include "Game/NameObj/NameObj.hpp"

class ImageEffectDirector;
class ImageEffectResource;

class ImageEffectSystemHolder : public NameObj {
public:
    /// @brief Creates a new `ImageEffectSystemHolder`.
    ImageEffectSystemHolder();

    /// @brief Destroys the `ImageEffectSystemHolder`.
    virtual ~ImageEffectSystemHolder() {}

    void pauseOff();

private:
    /* 0x0C */ ImageEffectResource* mResource;
    /* 0x10 */ ImageEffectDirector* mDirector;
};

namespace MR {
    void createImageEffectSystemHolder();
    ImageEffectSystemHolder* getImageEffectSystemHolder();
    bool isExistImageEffectDirector();
    ImageEffectDirector* getImageEffectDirector();
    ImageEffectResource* getImageEffectResource();
};
