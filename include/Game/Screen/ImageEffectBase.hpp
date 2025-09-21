#pragma once

#include "Game/NameObj/NameObj.hpp"

class ImageEffectBase : public NameObj {
public:
    /// @brief Creates a new `ImageEffectBase`.
    /// @param pName The pointer to the null-terminated name of the object.
    ImageEffectBase(const char* pName);

    /// @brief Destroys the `ImageEffectBase`.
    virtual ~ImageEffectBase() {}

    virtual void calcAnim();
    virtual void calcAnimSub();
    virtual void notifyTurnOn();
    virtual void notifyTurnOff();
    virtual void notifyForceOn();
    virtual void notifyForceOff();

    bool isSomething() const {
        return _C || _D;
    }

private:
    /* 0x0C */ bool _C;
    /* 0x0D */ bool _D;
    /* 0x10 */ f32 _10;
};
