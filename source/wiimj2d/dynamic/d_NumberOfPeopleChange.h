#pragma once

#include <dynamic/d_CharacterChangeSelectBase.h>
#include <dynamic/d_base.h>
#include <state/s_State.h>

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

    /* 0x74 */ dCharacterChangeSelectBase_c* mCcSelBase[4];
};