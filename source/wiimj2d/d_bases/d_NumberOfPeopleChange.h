#pragma once

#include <d_system/d_a_player_manager.h>
#include <d_system/d_base.h>
#include <d_bases/d_CharacterChangeIndicator.h>
#include <d_bases/d_CharacterChangeSelectArrow.h>
#include <d_bases/d_CharacterChangeSelectBase.h>
#include <d_bases/d_CharacterChangeSelectContents.h>
#include <state/s_FStateFct.h>
#include <state/s_State.h>
#include <state/s_StateMethodUsr_FI.h>
#include <state/s_StateMgr.h>

class da2DPlayer_c;

class dNumberOfPeopleChange_c : public dBase_c
{
public:
#define NUM_PY_CHANGE_PLAYER_COUNT 8

    // ------------
    // Constructors
    // ------------

    /* 0x8079F660 */
    dNumberOfPeopleChange_c();

public:
    // ----------------
    // Member Functions
    // ----------------

    void UNDEF_807A0060();
    void UNDEF_807A0170();

    /* 0x807A0440 */
    void assignPositions();

    /* 0x807A07C0 */
    void disableInactiveControllers();

    /* 0x807A09B0 */
    int getBaseForPlayerCount(int playerCount, int player);

    /* 0x807A09D0 */
    void calcBasesForPlayerCount();

    /* 0x807A0BF0 */
    void setupPlayerTypes();

    /* 0x807A0D20 */
    bool checkCancel();

    void setPlayer(u32 playerIndex, da2DPlayer_c* player)
    {
        if (playerIndex < 4) {
            mpaPlayers_Removed[playerIndex] = player;
        }
        mpaPlayers[playerIndex] = player;
    }

    da2DPlayer_c* getPlayer(u32 playerIndex)
    {
        return mpaPlayers[playerIndex];
    }

    void setControllerActive(u32 playerIndex, u32 active)
    {
        if (playerIndex < 4) {
            mControllerActive[playerIndex] = active;
        } else {
            mExControllerActive[playerIndex - 4] = active;
        }
    }

    u32 getControllerActive(u32 playerIndex)
    {
        if (playerIndex < 4) {
            return mControllerActive[playerIndex];
        } else {
            return mExControllerActive[playerIndex - 4];
        }
    }

    void setDecidedPlrType(u32 playerIndex, daPyMng_c::PlayerType_e value)
    {
        if (playerIndex < 4) {
            maDecidedPlayerType[playerIndex] = value;
        } else {
            maExDecidedPlayerType[playerIndex - 4] = value;
        }
    }

    daPyMng_c::PlayerType_e getDecidedPlrType(u32 playerIndex)
    {
        if (playerIndex < 4) {
            return maDecidedPlayerType[playerIndex];
        } else {
            return maExDecidedPlayerType[playerIndex - 4];
        }
    }

    void set0x6F0(u32 playerIndex, u32 value)
    {
        if (playerIndex < 4) {
            m0x6F0[playerIndex] = value;
        } else {
            mEx0x6F0[playerIndex - 4] = value;
        }
    }

    u32 get0x6F0(u32 playerIndex)
    {
        if (playerIndex < 4) {
            return m0x6F0[playerIndex];
        } else {
            return mEx0x6F0[playerIndex - 4];
        }
    }

public:
    // ---------
    // State IDs
    // ---------

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

public:
    // -----------
    // Member Data
    // -----------

    FILL(0x70, 0x74);

    /* 0x74 */ dCharacterChangeSelectBase_c* mpaCcSelBase[4];
    /* 0x84 */ dCharacterChangeSelectContents_c* mpaCcSelContents[4];
    /* 0x94 */ dCharacterChangeSelectArrow_c* mpaCcSelArrow[4];
    /* 0xA4 */ dCharacterChangeIndicator_c* mpaCcIndicator[4];

    FILL(0xB4, 0x404);

    /* 0x404 */ LytBase_c m0x404;

    /* 0x59C */ sStateMgr_c<
      dNumberOfPeopleChange_c, sStateMethodUsr_FI_c, sFStateFct_c, sStateIDChk_c>
      mStateMgr;

    FILL(0x5D8, 0x64C);

    /* 0x64C */ da2DPlayer_c* mpaPlayers_Removed[4];

    FILL(0x65C, 0x67F);

    /* 0x67F */ u8 m0x67F;
    /* 0x680 */ u8 m0x680;

    FILL(0x681, 0x687);

    /* 0x687 */ u8 m0x687;
    /* 0x688 */ u8 m0x688;

    FILL(0x689, 0x690);

    /* 0x690 */ u32 mControllerActive[4];
    /* 0x6A0 */ int m0x6A0;
    /* 0x6A4 */ u32 maPlrBaseIndex[4];
    /* 0x6B4 */ u32 maPlrBaseIndex2[4];
    /* 0x6C4 */ int mPlayerCount;
    /* 0x6C8 */ int mSelectedButton;
    /* 0x6CC */ int mLastSelectedButton;

    FILL(0x6D0, 0x6E0);

    /* 0x6E0 */ daPyMng_c::PlayerType_e maDecidedPlayerType[4];
    /* 0x6F0 */ u32 m0x6F0[4];

    FILL(0x700, 0x710);
    OFFSET_ASSERT(0x710);

#define OFFSET_dNumberOfPeopleChange_c_mRealPlayerCount 0x710
    /* 0x710 */ int mRealPlayerCount;

#define OFFSET_dNumberOfPeopleChange_c_mpaPlayers OFFSET_dNumberOfPeopleChange_c_mRealPlayerCount + 4
    /* 0x714 */ da2DPlayer_c* mpaPlayers[PLAYER_COUNT];

#define OFFSET_dNumberOfPeopleChange_c_mExControllerActive OFFSET_dNumberOfPeopleChange_c_mpaPlayers + 4 * PLAYER_COUNT
    /* 0x724 */ u32 mExControllerActive[PLAYER_COUNT - 4];
    /* 0x734 */ daPyMng_c::PlayerType_e maExDecidedPlayerType[PLAYER_COUNT - 4];
    /* 0x744 */ u32 mEx0x6F0[PLAYER_COUNT - 4];
};