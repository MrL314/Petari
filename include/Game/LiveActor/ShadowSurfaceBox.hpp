#pragma once

#include "Game/LiveActor/ShadowSurfaceDrawer.hpp"
#include "Game/Util.hpp"

class ShadowSurfaceBox : public ShadowSurfaceDrawer {
public:
    ShadowSurfaceBox();

    virtual ~ShadowSurfaceBox();

    virtual void draw() const;
    
    void setSize(const TVec3f &);
};
