#pragma once

#include "d_system/d_base.h"
#include "d_system/d_lytbase.h"
#include "state/s_State.h"

class dCharacterChangeSelectArrow_c : public dBase_c
{
public:
    sState_Extern(0x80990818, dCharacterChangeSelectArrow_c, OnStageWait);
    sState_Extern(0x80990858, dCharacterChangeSelectArrow_c, OnStageAnimeEndWait);
    sState_Extern(0x80990898, dCharacterChangeSelectArrow_c, ExitWait);
    sState_Extern(0x809908D8, dCharacterChangeSelectArrow_c, HitAnimeEndWait);
    sState_Extern(0x80990918, dCharacterChangeSelectArrow_c, ExitAnimeEndWait);

public:
    // -----------
    // Member Data
    // -----------

    /* 0x070 */ LytBase_c mLayout;

    FILL(0x208, 0x26C);

    /* 0x26C */ u8 m0x26C;
};
