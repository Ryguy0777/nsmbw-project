#pragma once

namespace nw4r::math
{
    [[nsmbw(0x80237D10)]]
    float SinFIdx(float idx);

    [[nsmbw(0x80237D80)]]
    float CosFIdx(float idx);

    [[nsmbw(0x80237DE0)]]
    void SinCosFIdx(f32* pSin, f32* pCos, f32 fidx);
}

#include "mtx.h"
#include "vec.h"
