#pragma once

#include <d/d_base.h>
#include <s/s_State.h>

class dScGameSetup_c : public dBase_c
{
public:
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