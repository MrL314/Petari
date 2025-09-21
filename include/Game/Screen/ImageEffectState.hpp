#pragma once

#include <revolution/types.h>

class ImageEffectBase;
class ImageEffectDirector;

class ImageEffectState {
public:
    /// @brief Creates a new `ImageEffectState`.
    ImageEffectState(ImageEffectDirector* pHost) :
        mHost(pHost)
    {}

    /// @brief Destroys the `ImageEffectState`.
    virtual ~ImageEffectState() {}

    virtual void update();
    virtual bool doesEffectExist() const;
    virtual ImageEffectBase* getEffect() const;
    virtual void onChange();

    void forceOff();

private:
    /* 0x4 */ ImageEffectDirector* mHost;
};

namespace ImageEffectStateImpl {
    class StateNull : public ImageEffectState {
    public:
        /// @brief Creates a new `StateNull`.
        /// @param pHost The pointer to the owning `ImageEffectDirector` instance.
        StateNull(ImageEffectDirector* pHost);
        
        /// @brief Destroys the `StateNull`.
        virtual ~StateNull() {}

        virtual bool doesEffectExist() const;
        virtual ImageEffectBase* getEffect() const;
    };

    class StateBloomNormal : public ImageEffectState {
        /// @brief Creates a new `StateBloomNormal`.
        /// @param pHost The pointer to the owning `ImageEffectDirector` instance.
        StateBloomNormal(ImageEffectDirector* pHost);
        
        /// @brief Destroys the `StateBloomNormal`.
        virtual ~StateBloomNormal() {}

        virtual void update();
        virtual bool doesEffectExist() const;
        virtual ImageEffectBase* getEffect() const;
        virtual void onChange();

        void setBloomIntensity(u8 bloomIntensity);
        void setThreshold(u8 threshold);
        void setIntensity1(u8 intensity1);
        void setIntensity1Default();
        void setIntensity2(u8 intensity2);
        void setIntensity2Default();

    private:
        /* 0x08 */ bool _8;
        /* 0x0C */ u32 _C;
        /* 0x10 */ f32 _10;
        /* 0x14 */ u8 mBloomIntensity;
        /* 0x18 */ f32 _18;
        /* 0x1C */ u8 mThreshold;
        /* 0x20 */ f32 _20;
        /* 0x24 */ u32 mIntensity1;
        /* 0x28 */ f32 _28;
        /* 0x2C */ u32 mIntensity2;
    };

    class StateBloomSimple : public ImageEffectState {
    public:    
    /// @brief Creates a new `StateBloomSimple`.
        /// @param pHost The pointer to the owning `ImageEffectDirector` instance.
        StateBloomSimple(ImageEffectDirector* pHost);
        
        /// @brief Destroys the `StateBloomSimple`.
        virtual ~StateBloomSimple() {}

        virtual bool doesEffectExist() const;
        virtual ImageEffectBase* getEffect() const;

        void setMaskFilterAll();
        void setMaskFilterRed();
        void setMaskFilterGreen();
        void setMaskFilterBlue();
        void setThreshold(u8 threshold);
        void setIntensity(f32 intensity);
    };

    class StateScreenBlur : public ImageEffectState {
    public:
        /// @brief Creates a new `StateScreenBlur`.
        /// @param pHost The pointer to the owning `ImageEffectDirector` instance.
        StateScreenBlur(ImageEffectDirector* pHost);
        
        /// @brief Destroys the `StateScreenBlur`.
        virtual ~StateScreenBlur() {}

        virtual bool doesEffectExist() const;
        virtual ImageEffectBase* getEffect() const;

        void setIntensity(f32 intensity);
    };

    class StateDepthOfField : public ImageEffectState {
    public:
        /// @brief Creates a new `StateDepthOfField`.
        /// @param pHost The pointer to the owning `ImageEffectDirector` instance.
        StateDepthOfField(ImageEffectDirector* pHost);
        
        /// @brief Destroys the `StateDepthOfField`.
        virtual ~StateDepthOfField() {}

        virtual bool doesEffectExist() const;
        virtual ImageEffectBase* getEffect() const;

        void setIntensity(f32 intensity);
        void setBlurMaxDist(s32 blurMaxDist);
        void setBlurMinDist(s32 blurMinDist);
    };
};
