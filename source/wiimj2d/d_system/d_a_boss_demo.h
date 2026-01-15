#pragma once

#include "d_system/d_actor_state.h"
#include "framework/f_base_id.h"

class daBossDemo_c : public dActorState_c
{
    SIZE_ASSERT(0x3DC);

public:
    // Instance Variables
    // ^^^^^^

    /* 0x3D0 */ s32 m0x3D0;
    /* 0x3D4 */ s32 mIsBattleEndDemo;
    /* 0x3D8 */ fBaseID_e mBossId;
};
