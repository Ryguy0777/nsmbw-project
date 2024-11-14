#pragma once

#include "Resources.h"
#include "System.h"
#include "Types.h"
#include <nw4r/ut/Color.h>
#include <nw4r/ut/LinkList.h>

namespace nw4r::lyt
{

class Material
{
    SIZE_ASSERT(0x5A);

public:
    // ----------------
    // Inline Functions
    // ----------------

    void SetTevColor(u32 idx, const GXColorS10& color)
    {
        mTevCols[idx] = color;
    }

protected:
    // -----------
    // Member Data
    // -----------

    FILL(0x00, 0x04);

    /* 0x04 */ ut::LinkList<AnimationLink, 0> mAnimList;
    /* 0x10 */ GXColorS10 mTevCols[3];
    /* 0x28 */ ut::Color mTevKCols[4];
    /* 0x38 */ detail::BitGXNums mGXMemCap;
    /* 0x3C */ detail::BitGXNums mGXMemNum;
    /* 0x40 */ void* mpGXMem;
    /* 0x44 */ char mName[res::MATERIAL_NAME_SIZE + 1];
    /* 0x59 */ bool mbUserAllocated;
};

} // namespace nw4r::lyt