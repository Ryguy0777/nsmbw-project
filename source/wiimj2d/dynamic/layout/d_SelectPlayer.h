#pragma once

#include <dynamic/d_base.h>
#include <state/s_State.h>

class dSelectPlayer_c : public dBase_c
{
public:
    //
    // State IDs
    //

    sState_Extern(0x809953A0, dSelectPlayer_c, StartWait);
    sState_Extern(0x809953E0, dSelectPlayer_c, OnStageAnimeEndWait);
    sState_Extern(0x80995420, dSelectPlayer_c, InfoOnStageAnimeEndWait);
    sState_Extern(0x80995460, dSelectPlayer_c, ButtonChangeAnimeEndWait);
    sState_Extern(0x809954A0, dSelectPlayer_c, StartMemberSelect);
    sState_Extern(0x809954E0, dSelectPlayer_c, MultiStartMemberSelect);
    sState_Extern(0x80995520, dSelectPlayer_c, StartMemberButtonAnime);
    sState_Extern(0x80995560, dSelectPlayer_c, ExitAnimeEndWait);
};