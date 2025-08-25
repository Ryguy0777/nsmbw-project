#pragma once

#include "d_system/d_actor_state.h"

class daBossDemo_c : public dActorState_c
{
    SIZE_ASSERT(0x3DC);

public:
    // -----------
    // Member Data
    // -----------

    /* 0x3D0 */ s32 m0x3D0;
    /* 0x3D4 */ s32 mIsBattleEndDemo;
    /* 0x3D8 */ s32 mBossType;
};