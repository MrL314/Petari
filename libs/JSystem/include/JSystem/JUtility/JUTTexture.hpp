#pragma once

#include <revolution.h>

class JUTPalette;

struct ResTIMG {
    /* 0x00 */ u8 mFormat;
    /* 0x01 */ u8 mTransparency;
    /* 0x02 */ u16 mWidth;
    /* 0x04 */ u16 mHeight;
    /* 0x06 */ u8 mWrapS;
    /* 0x07 */ u8 mWrapT;
    /* 0x08 */ u8 mPaletteName;
    /* 0x09 */ u8 mPaletteFormat;
    /* 0x0A */ u16 mPaletteNum;
    /* 0x0C */ u32 mPaletteDataOffset;
    /* 0x10 */ bool mMipmap;
    /* 0x11 */ bool mDoEdgeLod;
    /* 0x12 */ bool mBiasClamp;
    /* 0x13 */ u8 mMaxAnisotropy;
    /* 0x14 */ u8 mMinType;
    /* 0x15 */ u8 mMagType;
    /* 0x16 */ u8 mMinLod;
    /* 0x17 */ u8 mMaxLod;
    /* 0x18 */ u8 mImageNum;
    /* 0x1A */ s16 mLodBias;
    /* 0x1C */ u32 mImageDataOffset;
};

class JUTTexture {
public:
    /// @brief Creates a new `JUTTexture`.
    JUTTexture();

    /// @brief Creates a new `JUTTexture`.
    /// @param width The width of the texture, in pixels.
    /// @param height The height of the texture, in pixels.
    /// @param format The type of the texture.
    JUTTexture(int width, int height, GXTexFmt format);

    /// @brief Creates a new `JUTTexture`.
    /// @param pTIMG TODO.
    /// @param param2 TODO.
    JUTTexture(const ResTIMG* pTIMG, u8 param2);

    /// @brief Destroys the `JUTTexture`.
    ~JUTTexture();

    void storeTIMG(const ResTIMG *, u8);
    void storeTIMG(const ResTIMG *, JUTPalette *);
    void storeTIMG(const ResTIMG *, JUTPalette *, GXTlut);
    void attachPalette(JUTPalette *);
    void init();
    void initTexObj();
    void initTexObj(_GXTlut);
    void load(_GXTexMapID);
    void capture(int, int, GXTexFmt, bool, u8);
    void setCaptureFlag(bool);
    void setEmbPaletteDelFlag(bool);

    /* 0x00 */ GXTexObj mObj;
    /* 0x20 */ ResTIMG* mTIMG;
    /* 0x24 */ u8* mImage;
    /* 0x28 */ JUTPalette* mEmbPalette;
    /* 0x2C */ JUTPalette* mPalette;
    /* 0x30 */ u8 mWrapS;
    /* 0x31 */ u8 mWrapT;
    /* 0x32 */ u8 mMagType;
    /* 0x33 */ u8 mMinType;
    /* 0x34 */ u16 mMinLod;
    /* 0x36 */ u16 mMaxLod;
    /* 0x38 */ u16 mLodBias;
    /* 0x3A */ u8 _3A;
    /* 0x3B */ u8 mFlag;
    /* 0x3C */ ResTIMG* _3C;
};
