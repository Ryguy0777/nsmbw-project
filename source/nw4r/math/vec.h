#pragma once

namespace nw4r::math
{

struct VEC2 {
    SIZE_ASSERT(0x8);

    /* 0x0 */ f32 x;
    /* 0x4 */ f32 y;
};

struct VEC3 {
    SIZE_ASSERT(0xC);

    /* 0x0 */ f32 x;
    /* 0x4 */ f32 y;
    /* 0x8 */ f32 z;
};

} // namespace nw4r::math