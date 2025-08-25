#pragma once

#include "d_system/d_base.h"
#include "state/s_State.h"

class da2DPlayer_c;
class dNumberOfPeopleChange_c;
class dSelectPlayer_c;

class dScGameSetup_c : public dBase_c
{
public:
    // ----------------
    // Member Functions
    // ----------------

    /* 0x80917EB0 */
    bool add2dPlayer();

public:
    // -----------
    // Member Data
    // -----------

    FILL(0x070, 0x0B8);

    /* 0x0B8 */ dNumberOfPeopleChange_c* mpNumPyChg;

    FILL(0x0BC, 0x0C0);

    /* 0x0C0 */ da2DPlayer_c* mpa2DPlayer[4];
    /* 0x0D0 */ dSelectPlayer_c* mpSelectPlayer;

    FILL(0x0D4, 0x0F8);

    /* 0x0F8 */ u32 mPlayerCreateIdx;

public:
    // ---------
    // State IDs
    // ---------

    sState_Extern(0x809A14E0, dScGameSetup_c, FadeInEndWait);
    sState_Extern(0x809A1520, dScGameSetup_c, FileSelect);
    sState_Extern(0x809A1560, dScGameSetup_c, FadeOut);
    sState_Extern(0x809A15A0, dScGameSetup_c, FadeIn);
    sState_Extern(0x809A15E0, dScGameSetup_c, StartMember);
    sState_Extern(0x809A1620, dScGameSetup_c, ConnectionCheck);
    sState_Extern(0x809A1660, dScGameSetup_c, EasyPairingWait);
    sState_Extern(0x809A16A0, dScGameSetup_c, LowBatteryCheck);
    sState_Extern(0x809A16E0, dScGameSetup_c, NandAccess);
    sState_Extern(0x809A1720, dScGameSetup_c, VoiceEndWait);
    sState_Extern(0x809A1760, dScGameSetup_c, NextSceneWait);
};