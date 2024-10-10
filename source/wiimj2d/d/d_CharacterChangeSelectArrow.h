#pragma once

#include <d/d_base.h>
#include <s/s_State.h>

class dCharacterChangeSelectArrow_c : public dBase_c
{
public:
    sState_Extern(0x80990818, dCharacterChangeSelectArrow_c, OnStageWait);
    sState_Extern(0x80990858, dCharacterChangeSelectArrow_c, OnStageAnimeEndWait);
    sState_Extern(0x80990898, dCharacterChangeSelectArrow_c, ExitWait);
    sState_Extern(0x809908D8, dCharacterChangeSelectArrow_c, HitAnimeEndWait);
    sState_Extern(0x80990918, dCharacterChangeSelectArrow_c, ExitAnimeEndWait);
};