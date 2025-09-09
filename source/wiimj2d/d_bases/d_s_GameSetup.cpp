// d_s_GameSetup.cpp
// NSMBW d_bases.text: 0x80917960 - 0x8091A2F0

#include "d_s_GameSetup.h"

#include "d_bases/d_CharacterChangeSelectBase.h"
#include "d_bases/d_NumberOfPeopleChange.h"
#include "d_bases/d_SelectPlayer.h"
#include "d_bases/d_s_world_map.h"
#include "d_system/d_a_player_manager.h"
#include "d_system/d_base_actor.h"
#include "d_system/d_info.h"
#include "d_system/d_mj2d_game.h"
#include "d_system/d_save_manager.h"
#include "d_system/d_scene.h"
#include "framework/f_base_profile.h"
#include "framework/f_feature.h"
#include <algorithm>

[[address(0x80917EB0)]]
bool dScGameSetup_c::add2dPlayer()
{
    u32 id = mPlayerCreateIdx;

    dBaseActor_c* playerBase =
      dBaseActor_c::construct(+fBaseProfile_e::WM_2D_PLAYER, this, id, nullptr, nullptr);
    if (playerBase == nullptr) {
        return false;
    }

    da2DPlayer_c* player = reinterpret_cast<da2DPlayer_c*>(playerBase);

    if (id < 4) {
        mpa2DPlayer[id] = player;
        // mpNumPyChg->mpaPlayers_Removed[id] = player;
    }
    mpNumPyChg->mpaPlayers[id] = player;

    mPlayerCreateIdx++;
    if (mPlayerCreateIdx < CHARACTER_LIST_COUNT) {
        return false;
    }

    // Done
    mPlayerCreateIdx = 0;
    return true;
}

[[address(0x80918780)]]
void dScGameSetup_c::executeState_FileSelect() ASM_METHOD(
  // clang-format off
/* 80918780 9421FFE0 */  stwu     r1, -32(r1);
/* 80918784 7C0802A6 */  mflr     r0;
/* 80918788 90010024 */  stw      r0, 36(r1);
/* 8091878C 93E1001C */  stw      r31, 28(r1);
/* 80918790 7C7F1B78 */  mr       r31, r3;
/* 80918794 93C10018 */  stw      r30, 24(r1);
/* 80918798 93A10014 */  stw      r29, 20(r1);
/* 8091879C 4BFFFCB5 */  bl       UNDEF_80918450;
/* 809187A0 807F00E8 */  lwz      r3, 232(r31);
/* 809187A4 880302DB */  lbz      r0, 731(r3);
/* 809187A8 2C000000 */  cmpwi    r0, 0;
/* 809187AC 41820118 */  beq-     UNDEF_809188c4;
/* 809187B0 880302DC */  lbz      r0, 732(r3);
/* 809187B4 2C000000 */  cmpwi    r0, 0;
/* 809187B8 41820030 */  beq-     UNDEF_809187e8;
/* 809187BC 38600000 */  li       r3, 0;
/* 809187C0 38800000 */  li       r4, 0;
/* 809187C4 4B7E911D */  bl       UNDEF_801018e0;
/* 809187C8 819F0074 */  lwz      r12, 116(r31);
/* 809187CC 3C80809A */  lis      r4, UNDEF_809a1760@ha;
/* 809187D0 387F0074 */  addi     r3, r31, 116;
/* 809187D4 818C0018 */  lwz      r12, 24(r12);
/* 809187D8 38841760 */  addi     r4, r4, UNDEF_809a1760@l;
/* 809187DC 7D8903A6 */  mtctr    r12;
/* 809187E0 4E800421 */  bctrl;
/* 809187E4 480000E0 */  b        UNDEF_809188c4;
UNDEF_809187e8:;
/* 809187E8 80A302A4 */  lwz      r5, 676(r3);
/* 809187EC 38800000 */  li       r4, 0;
/* 809187F0 807F00D0 */  lwz      r3, 208(r31);
/* 809187F4 38000001 */  li       r0, 1;
/* 809187F8 7CBD0774 */  extsb    r29, r5;
/* 809187FC 9083026C */  stw      r4, 620(r3);
/* 80918800 2C1D0002 */  cmpwi    r29, 2;
/* 80918804 981F0108 */  stb      r0, 264(r31);
/* 80918808 41810048 */  bgt-     UNDEF_80918850;
/* 8091880C 3C808043 */  lis      r4, UNDEF_8042a260@ha;
/* 80918810 3C608043 */  lis      r3, m_instance__10dSaveMng_c@ha;
/* 80918814 8004A260 */  lwz      r0, UNDEF_8042a260@l(r4);
/* 80918818 83C3A320 */  lwz      r30, m_instance__10dSaveMng_c@l(r3);
/* 8091881C 54000730 */  rlwinm   r0, r0, 0, 28, 24;
/* 80918820 9004A260 */  stw      r0, UNDEF_8042a260@l(r4);
/* 80918824 807F00E8 */  lwz      r3, 232(r31);
/* 80918828 880302DD */  lbz      r0, 733(r3);
/* 8091882C 2C000000 */  cmpwi    r0, 0;
/* 80918830 41820010 */  beq-     UNDEF_80918840;
/* 80918834 7FC3F378 */  mr       r3, r30;
/* 80918838 57A4063E */  clrlwi   r4, r29, 24;
/* 8091883C 4B7C91F5 */  bl       UNDEF_800e1a30;
UNDEF_80918840:;
/* 80918840 7FC3F378 */  mr       r3, r30;
/* 80918844 7FA4EB78 */  mr       r4, r29;
/* 80918848 4B7C90E9 */  bl       UNDEF_800e1930;
/* 8091884C 4800005C */  b        UNDEF_809188a8;
UNDEF_80918850:;
/* 80918850 3C608035 */  lis      r3, mRest__9daPyMng_c@ha;
/* 80918854 38000005 */  li       r0, 5;
/* 80918858 94035190 */  stwu     r0, mRest__9daPyMng_c@l(r3);

                         li       r4, CHARACTER_COUNT - 1;
                         mtctr    r4;
L_StoreLivesLoop_Start:;
                         stwu     r0, 0x4@l(r3);
                         bdnz+    L_StoreLivesLoop_Start;
                         
/* 80918868 4B748689 */  bl       checkBonusNoCap__9daPyMng_cFv;
/* 8091886C 3CA08043 */  lis      r5, UNDEF_8042a260@ha;
/* 80918870 8005A260 */  lwz      r0, UNDEF_8042a260@l(r5);
/* 80918874 60040010 */  ori      r4, r0, 16;
/* 80918878 9085A260 */  stw      r4, UNDEF_8042a260@l(r5);
/* 8091887C 807F00E8 */  lwz      r3, 232(r31);
/* 80918880 800302A4 */  lwz      r0, 676(r3);
/* 80918884 2C000003 */  cmpwi    r0, 3;
/* 80918888 40820014 */  bne-     UNDEF_8091889c;
/* 8091888C 60800020 */  ori      r0, r4, 32;
/* 80918890 540006B0 */  rlwinm   r0, r0, 0, 26, 24;
/* 80918894 9005A260 */  stw      r0, UNDEF_8042a260@l(r5);
/* 80918898 48000010 */  b        UNDEF_809188a8;
UNDEF_8091889c:;
/* 8091889C 548006F2 */  rlwinm   r0, r4, 0, 27, 25;
/* 809188A0 60000040 */  ori      r0, r0, 64;
/* 809188A4 9005A260 */  stw      r0, UNDEF_8042a260@l(r5);
UNDEF_809188a8:;
/* 809188A8 819F0074 */  lwz      r12, 116(r31);
/* 809188AC 3C80809A */  lis      r4, UNDEF_809a1560@ha;
/* 809188B0 387F0074 */  addi     r3, r31, 116;
/* 809188B4 818C0018 */  lwz      r12, 24(r12);
/* 809188B8 38841560 */  addi     r4, r4, UNDEF_809a1560@l;
/* 809188BC 7D8903A6 */  mtctr    r12;
/* 809188C0 4E800421 */  bctrl;
UNDEF_809188c4:;
/* 809188C4 80010024 */  lwz      r0, 36(r1);
/* 809188C8 83E1001C */  lwz      r31, 28(r1);
/* 809188CC 83C10018 */  lwz      r30, 24(r1);
/* 809188D0 83A10014 */  lwz      r29, 20(r1);
/* 809188D4 7C0803A6 */  mtlr     r0;
/* 809188D8 38210020 */  addi     r1, r1, 32;
/* 809188DC 4E800020 */  blr;
  // clang-format on
);

[[address(0x809188E0)]]
void dScGameSetup_c::finalizeState_FileSelect()
{
    for (int i = 0; i < CHARACTER_COUNT; i++) {
        daPyMng_c::mPlayerType[i] = dMj2dGame_c::scDefaultPlayerTypes[i];
    }
}

[[address(0x80918B00)]]
void dScGameSetup_c::executeState_StartMember()
{
    dSelectPlayer_c* selPly = mpSelectPlayer;

    if (selPly->m0x26B == 0) {
        return;
    }

    if (selPly->mActDirection == -1) {
        // Back
        mInPlayerSelect = false;
        return mStateMgr.changeState(dScGameSetup_c::StateID_FadeOut);
    } else if (selPly->mActDirection != 1) {
        return;
    }

    dInfo_c* info = dInfo_c::m_instance;
    for (u32 i = 0; i < 4; i++) {
        info->mPlayerActiveMode[i] = 0;
    }
    for (u32 i = 4; i < PLAYER_COUNT; i++) {
        info->mExPlayerActiveMode[i - 4] = 0;
    }

    // Switch to dNumberOfPeopleChange_c
    dNumberOfPeopleChange_c* numPyChg = mpNumPyChg;
    numPyChg->m0x67E = true;
    numPyChg->mRealPlayerCount = selPly->mCurrentButton + 1;
    // Cap the normal player count field to 4
    numPyChg->mPlayerCount = std::min(numPyChg->mRealPlayerCount, 4);

    mStateMgr.changeState(dScGameSetup_c::StateID_ConnectionCheck);
}

[[address(0x80919190)]]
void dScGameSetup_c::finalizeState_VoiceEndWait()
{
    dMj2dGame_c* save = dSaveMng_c::m_instance->getSaveGame();
    if (save->isEmpty() && !fFeature::DISABLE_OPENING_MOVIE) {
        dScene_c::setNextScene(+fBaseProfile_e::MOVIE, 0, false);
    } else {
        dScene_c::setNextScene(+fBaseProfile_e::WORLD_MAP, dScWMap_c::CreateBootParam(), false);
    }
}