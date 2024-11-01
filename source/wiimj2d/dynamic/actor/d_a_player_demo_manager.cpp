// d_a_player_demo_manager.cpp
// NSMBW: 0x8005B3A0 - 0x8005D7E0

#include "d_a_player_demo_manager.h"

#include <dynamic/actor/d_a_player_manager.h>

[[address(0x80429F74)]]
daPyDemoMng_c* daPyDemoMng_c::mspInstance;

[[address(0x8005B3A0)]]
daPyDemoMng_c::daPyDemoMng_c();

/* VT+0x8 */
[[address(0x8005B3E0)]]
daPyDemoMng_c::~daPyDemoMng_c();

[[address(0x8005B430)]]
void daPyDemoMng_c::initStage();

[[address(0x8005B4A0)]]
void daPyDemoMng_c::init();

[[address(0x8005B6A0)]]
void daPyDemoMng_c::calcNotGoalPlayer() ASM_METHOD(
  // clang-format off
/* 8005B6A0 9421FFF0 */  stwu     r1, -16(r1);
/* 8005B6A4 7C0802A6 */  mflr     r0;
/* 8005B6A8 90010014 */  stw      r0, 20(r1);
/* 8005B6AC 93E1000C */  stw      r31, 12(r1);
/* 8005B6B0 93C10008 */  stw      r30, 8(r1);
/* 8005B6B4 8003003C */  lwz      r0, 60(r3);
/* 8005B6B8 2C000000 */  cmpwi    r0, 0;
/* 8005B6BC 418200A4 */  beq-     UNDEF_8005b760;
/* 8005B6C0 3400FFFF */  subic.   r0, r0, 1;
/* 8005B6C4 9003003C */  stw      r0, 60(r3);
/* 8005B6C8 40820098 */  bne-     UNDEF_8005b760;
/* 8005B6CC 880DA658 */  lbz      r0, -22952(r13);
/* 8005B6D0 3BE00000 */  li       r31, 0;
/* 8005B6D4 54000636 */  rlwinm   r0, r0, 0, 24, 27;
/* 8005B6D8 980DA658 */  stb      r0, -22952(r13);
UNDEF_8005b6dc:;
/* 8005B6DC 7FE3FB78 */  mr       r3, r31;
/* 8005B6E0 480044B1 */  bl       UNDEF_8005fb90;
/* 8005B6E4 2C030000 */  cmpwi    r3, 0;
UNDEF_8005b6e8:;
/* 8005B6E8 41820014 */  beq-     UNDEF_8005b6fc;
/* 8005B6EC 81830060 */  lwz      r12, 96(r3);
/* 8005B6F0 818C012C */  lwz      r12, 300(r12);
/* 8005B6F4 7D8903A6 */  mtctr    r12;
/* 8005B6F8 4E800421 */  bctrl;
UNDEF_8005b6fc:;
/* 8005B6FC 3BFF0001 */  addi     r31, r31, 1;
/* 8005B700 2C1F0004 */  cmpwi    r31, PLAYER_COUNT;
/* 8005B704 4180FFD8 */  blt+     UNDEF_8005b6dc;
/* 8005B708 3BC00000 */  li       r30, 0;
UNDEF_8005b70c:;
/* 8005B70C 7FC3F378 */  mr       r3, r30;
/* 8005B710 48004461 */  bl       UNDEF_8005fb70;
/* 8005B714 2C030000 */  cmpwi    r3, 0;
/* 8005B718 7C7F1B78 */  mr       r31, r3;
/* 8005B71C 41820038 */  beq-     UNDEF_8005b754;
/* 8005B720 81830060 */  lwz      r12, 96(r3);
/* 8005B724 818C006C */  lwz      r12, 108(r12);
/* 8005B728 7D8903A6 */  mtctr    r12;
/* 8005B72C 4E800421 */  bctrl;
/* 8005B730 88030000 */  lbz      r0, 0(r3);
/* 8005B734 7C000774 */  extsb    r0, r0;
/* 8005B738 2C00FFFF */  cmpwi    r0, -1;
/* 8005B73C 40820018 */  bne-     UNDEF_8005b754;
/* 8005B740 819F0060 */  lwz      r12, 96(r31);
/* 8005B744 7FE3FB78 */  mr       r3, r31;
/* 8005B748 818C012C */  lwz      r12, 300(r12);
/* 8005B74C 7D8903A6 */  mtctr    r12;
/* 8005B750 4E800421 */  bctrl;
UNDEF_8005b754:;
/* 8005B754 3BDE0001 */  addi     r30, r30, 1;
/* 8005B758 2C1E0004 */  cmpwi    r30, PLAYER_COUNT;
/* 8005B75C 4180FFB0 */  blt+     UNDEF_8005b70c;
UNDEF_8005b760:;
/* 8005B760 80010014 */  lwz      r0, 20(r1);
/* 8005B764 83E1000C */  lwz      r31, 12(r1);
/* 8005B768 83C10008 */  lwz      r30, 8(r1);
/* 8005B76C 7C0803A6 */  mtlr     r0;
/* 8005B770 38210010 */  addi     r1, r1, 16;
/* 8005B774 4E800020 */  blr;
  // clang-format on
);

[[gnu::const]]
static int convIdx(int index)
{
    if (index < 4) {
        return index;
    }

    return index + (offsetof(daPyDemoMng_c, mExPlayerIDs) - offsetof(daPyDemoMng_c, mPlayerIDs)) /
                     sizeof(int);
}

[[address(0x8005B780)]]
int daPyDemoMng_c::setGoalDemoList(int param)
{
    for (int i = 0; i < PLAYER_COUNT; i++) {
        if (mPlayerIDs[convIdx(i)] == -1) {
            mPlayerIDs[convIdx(i)] = param;
            return convIdx(i);
        }
    }

    return -1;
}

[[address(0x8005B840)]]
int daPyDemoMng_c::getPoleBelowPlayer(int param)
{
    for (int i = 0; i < mPlayerCount; i++) {
        if (mPlayerIDs[convIdx(i)] && i > 0) {
            return mPlayerIDs[convIdx(i - 1)];
        }
    }

    return -1;
}

// TODO
[[address(0x8005B8A0)]]
void daPyDemoMng_c::executeGoalDemo_Pole();

// TODO
[[address(0x8005BCF0)]]
void daPyDemoMng_c::executeGoalDemo_PoleDown();

// TODO
[[address(0x8005BD60)]]
void daPyDemoMng_c::executeGoalDemo_JumpCheck();

// TODO
[[address(0x8005BE30)]]
void daPyDemoMng_c::executeGoalDemo_Jump();

// TODO
[[address(0x8005BF10)]]
void daPyDemoMng_c::executeGoalDemo_Land();

// TODO
[[address(0x8005BFD0)]]
void daPyDemoMng_c::executeGoalDemo_KimeWait();

// TODO
[[address(0x8005C130)]]
void daPyDemoMng_c::setGoalDemoKimeAll();

// TODO
[[address(0x8005C1A0)]]
void daPyDemoMng_c::setGoalDemoRunCastle();

// TODO
[[address(0x8005C210)]]
bool daPyDemoMng_c::isAllPlayerGoalIn();

// TODO
[[address(0x8005C6D0)]]
void daPyDemoMng_c::calcGoalCenterPos();

// TODO
[[address(0x8005C930)]]
bool daPyDemoMng_c::startControlDemoAll();

// TODO
[[address(0x8005C9D0)]]
bool daPyDemoMng_c::isAllPlayerControlDemo();

// TODO
[[address(0x8005CA50)]]
void daPyDemoMng_c::endControlDemoAll(int param);

// TODO
[[address(0x8005CAD0)]]
int daPyDemoMng_c::getControlDemoPlayerNum();

// TODO
[[address(0x8005CB70)]]
void daPyDemoMng_c::onLandStopReq();

// TODO
[[address(0x8005CC00)]]
bool daPyDemoMng_c::startControlDemoLandPlayer();

// TODO
[[address(0x8005CDD0)]]
bool daPyDemoMng_c::isLandAll();

// TODO
[[address(0x8005CE50)]]
void daPyDemoMng_c::UNDEF_8005CE50(int param);

// TODO
[[address(0x8005CED0)]]
void daPyDemoMng_c::executeStartToride();

// TODO
[[address(0x8005D050)]]
void daPyDemoMng_c::setCourseOutList();

// TODO
[[address(0x8005D280)]]
void daPyDemoMng_c::genCourseInList();
