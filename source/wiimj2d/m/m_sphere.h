#pragma once

#include <cfloat>
#include <cmath>
#include <m/m_vec.h>

class mSphere_c
{
    SIZE_ASSERT(0x10);

public:
    mSphere_c()
      : mPos(mVec3_c::Zero)
      , mRadius(0.0)
    {
    }

    bool isZero()
    {
        return std::fabsf(mRadius) <= FLT_EPSILON;
    }

    /* 0x0 */ mVec3_c mPos;
    /* 0xC */ float mRadius;
};
