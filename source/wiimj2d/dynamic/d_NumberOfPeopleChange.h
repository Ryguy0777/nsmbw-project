#pragma once

#include <dynamic/d_CharacterChangeIndicator.h>
#include <dynamic/d_CharacterChangeSelectArrow.h>
#include <dynamic/d_CharacterChangeSelectBase.h>
#include <dynamic/d_CharacterChangeSelectContents.h>
#include <dynamic/d_base.h>
#include <state/s_State.h>


class da2DPlayer_c;

class dNumberOfPeopleChange_c : public dBase_c
{
public:
    void UNDEF_807A0060();
    void UNDEF_807A0170();

    /* 0x807A0440 */
    void assignPositions();

    /* 0x807A0D20 */
    bool checkCancel();

    //
    // State IDs
    //

    sState_Extern(0x809944C8, dNumberOfPeopleChange_c, InitialSetup);
    sState_Extern(0x80994508, dNumberOfPeopleChange_c, OnStageAnimeEndWait);
    sState_Extern(0x80994548, dNumberOfPeopleChange_c, InfoOnStageAnimeEndWait);
    sState_Extern(0x80994588, dNumberOfPeopleChange_c, NowEntrantRecruit);
    sState_Extern(0x809945C8, dNumberOfPeopleChange_c, StoryModeCourseSelectExitWait);
    sState_Extern(0x80994608, dNumberOfPeopleChange_c, InfoWindowExitWait);
    sState_Extern(0x80994648, dNumberOfPeopleChange_c, ButtonOnStageAnimeEndWait);
    sState_Extern(0x80994688, dNumberOfPeopleChange_c, ButtonChangeAnimeEndWait);
    sState_Extern(0x809946C8, dNumberOfPeopleChange_c, ButtonSelect);
    sState_Extern(0x80994708, dNumberOfPeopleChange_c, ButtonDecision);
    sState_Extern(0x80994748, dNumberOfPeopleChange_c, ExitAnimeEndCheck);

    //
    // Member Data
    //

    FILL(0x70, 0x74);

    /* 0x74 */ dCharacterChangeSelectBase_c* mpaCcSelBase[4];
    /* 0x84 */ dCharacterChangeSelectContents_c* mpaCcSelContents[4];
    /* 0x94 */ dCharacterChangeSelectArrow_c* mpaCcSelArrow[4];
    /* 0xA4 */ dCharacterChangeIndicator_c* mpaCcIndicator[4];

    FILL(0xB4, 0x64C);

    /* 0x64C */ da2DPlayer_c* mpaPlayers[4];

    FILL(0x65C, 0x690);

    /* 0x690 */ u32 m0x690[4];
    /* 0x6A0 */ u32 m0x6A0[4];
  
    FILL(0x6B0, 0x6E0);

    /* 0x6E0 */ u32 m0x6E0[4];
    /* 0x6F0 */ u32 m0x6F0[4];

    FILL(0x700, 0x710);

    OFFSET_ASSERT(0x710);

    // The offsets are fixed because ASM
    /* 0x710 */ da2DPlayer_c* mpaExPlayers[4];

    /* 0x720 */ u32 mEx0x690[4];
    /* 0x730 */ u32 mEx0x6A0[4];
    /* 0x740 */ u32 mEx0x6E0[4];
    /* 0x750 */ u32 mEx0x6F0[4];
};