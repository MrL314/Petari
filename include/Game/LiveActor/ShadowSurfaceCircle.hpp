#pragma once

#include "Game/LiveActor/ShadowSurfaceDrawer.hpp"

class ShadowSurfaceCircle : public ShadowSurfaceDrawer {
public:
    ShadowSurfaceCircle();

    virtual ~ShadowSurfaceCircle();

    virtual void draw() const;
    
    void setRadius(f32);

    f32 _10;
};
