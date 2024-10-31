#pragma once

#include <dynamic/d_mj2d_game.h>
#include <machine/m_vec.h>


class dCyuukan_c
{
    SIZE_ASSERT(0x34);

public:
    //
    // Member Data
    //

    FILL(0x00, 0x08);

    /* 0x08 */ mVec3_c mPlayerSetPos;
    /* 0x14 */ u32 m0x14;
    /* 0x18 */ WORLD_e mWorld;
    /* 0x19 */ STAGE_e mStage;
    /* 0x1A */ u8 mCourse; // A.k.a. Area
    /* 0x1B */ u8 mGoto;
    /* 0x1C */ bool mIsKinopioInChukan;

    FILL(0x1D, 0x34);
};