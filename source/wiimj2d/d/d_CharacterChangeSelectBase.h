#pragma once

#include <d/d_base.h>
#include <s/s_State.h>

class dCharacterChangeSelectBase_c : public dBase_c
{
public:
    //
    // Functions
    //

    /* 0x8076FC80 */
    bool isCharacterLocked(u32 character);

    /* 0x8076FD70 */
    void UNDEF_8076FD70(u32 character, u32 baseIndex);

    /* 0x8076FE40 */
    void UNDEF_8076FE40();

    /* 0x8076FEE0 */
    void UNDEF_8076FEE0();

    //
    // Member Data
    //

    FILL(0x070, 0x074);

    /* 0x074 */ u32* m0x074;

    FILL(0x078, 0x07C);

    /* 0x07C */ u32* m0x07C;

    FILL(0x080, 0x29A);

    /* 0x29A */ bool mDecided;

    FILL(0x29B, 0x2D4);

    /* 0x2D4 */ u32 mDecidedCharacter;
    /* 0x2D8 */ u32 mSelectedCharacter;
    /* 0x2DC */ u32 m0x2DC;
    /* 0x2E0 */ u32 mSelectedBaseIndex;

    //
    // State IDs
    //

    sState_Extern(0x80990958, dCharacterChangeSelectBase_c, initial);
    sState_Extern(0x80990998, dCharacterChangeSelectBase_c, OnStageWait);
    sState_Extern(0x809909D8, dCharacterChangeSelectBase_c, OnStageAnimeEndWait);
    sState_Extern(0x80990A18, dCharacterChangeSelectBase_c, ConnectWait);
    sState_Extern(0x80990A58, dCharacterChangeSelectBase_c, SelectStartWait);
    sState_Extern(0x80990A98, dCharacterChangeSelectBase_c, ButtonExitAnimeEndWait);
    sState_Extern(0x80990AD8, dCharacterChangeSelectBase_c, ButtonOnStageAnimeEndWait);
    sState_Extern(0x80990B18, dCharacterChangeSelectBase_c, ArrowDispWait);
    sState_Extern(0x80990B58, dCharacterChangeSelectBase_c, SelectWait);
    sState_Extern(0x80990B98, dCharacterChangeSelectBase_c, MoveAnimeStartWait);
    sState_Extern(0x80990BD8, dCharacterChangeSelectBase_c, MoveAnimeEndWait);
    sState_Extern(0x80990C18, dCharacterChangeSelectBase_c, HitAnimeEndWait);
    sState_Extern(0x80990C58, dCharacterChangeSelectBase_c, HitAfterExitWait);
    sState_Extern(0x80990C98, dCharacterChangeSelectBase_c, ExitAnimeEndForPlayerOnStageWait);
    sState_Extern(0x80990CD8, dCharacterChangeSelectBase_c, PlayerOnStageWait);
    sState_Extern(0x80990D18, dCharacterChangeSelectBase_c, PlayerDisp);
    sState_Extern(0x80990D58, dCharacterChangeSelectBase_c, PlayerExitWait);
    sState_Extern(0x80990D98, dCharacterChangeSelectBase_c, PlayerExitEndClearWaKu);
    sState_Extern(
      // This one is so LONG!!!
      0x80990DD8, dCharacterChangeSelectBase_c, ConnectCutEnterWaitWindowOnStageAnimeEndWait
    );
    sState_Extern(0x80990E18, dCharacterChangeSelectBase_c, ExitAnimeEndWait);
};