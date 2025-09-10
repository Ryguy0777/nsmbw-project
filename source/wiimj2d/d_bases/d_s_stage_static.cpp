// d_s_stage_static.cpp
// NSMBW .text: 0x80101A50 - 0x80102770

#include "d_s_stage.h"
#include "d_system/d_mj2d_game.h"

#include <PatchRel.h>

[[address_data(0x8042A4A8)]]
dScStage_c* dScStage_c::m_instance;

[[address_data(0x8042A4DC)]]
s32 dScStage_c::m_goalType;

[[address_data(0x8042A4E0)]]
u32 dScStage_c::m_exeFrame;

[[address_data(0x8042A4E4)]]
dScStage_c::GAME_MODE_e dScStage_c::m_gameMode;

[[address_data(0x8042A4FC)]]
bool dScStage_c::m_isCourseIn;

[[address_data(0x8042A4FD)]]
bool dScStage_c::m_isCourseOut;

[[address_data(0x8042A4FE)]]
bool dScStage_c::m_isOtehonReturn;

[[address_data(0x8042A4FF)]]
bool dScStage_c::m_isStaffCredit;

[[address_data(0x8042A500)]]
s32 dScStage_c::m_miniGame;

[[address_data(0x8042A504)]]
u8 dScStage_c::m_replayMode;

[[address_data(0x8042A506)]]
bool dScStage_c::m_isReplayGoal;

[[address_data(0x803744B0)]]
PLAYER_TYPE_e dScStage_c::mCollectionCoin[COLLECTION_COIN_COUNT];

/* 0x803744D0 */
dReplayPlay_c* dScStage_c::m_replayPlay_p[REMOCON_CONNECT_COUNT];

[[address(0x80101A70)]]
dGameDisplay_c* dScStage_c::getGameDisplay();

[[address(0x80101AA0)]]
void dScStage_c::setLoopType() ASM_METHOD(
  // clang-format off
/* 80101AA0 9421FFE0 */  stwu     r1, -32(r1);
/* 80101AA4 7C0802A6 */  mflr     r0;
/* 80101AA8 90010024 */  stw      r0, 36(r1);
                         lis      r5, m_instance__10dScStage_c@ha;
                         lwz      r5, m_instance__10dScStage_c@l(r5);
                         lis      r3, UNDEF_8042a178@ha;
                         lwz      r3, UNDEF_8042a178@l(r3); // dCd_c::m_instance
/* 80101AB4 8805120E */  lbz      r0, 4622(r5);
/* 80101AB8 1C0003B0 */  mulli    r0, r0, 944;
/* 80101ABC 7C630214 */  add      r3, r3, r0;
/* 80101AC0 8003002C */  lwz      r0, 44(r3);
/* 80101AC4 2C000000 */  cmpwi    r0, 0;
/* 80101AC8 41820008 */  beq-     UNDEF_80101ad0;
/* 80101ACC 48000008 */  b        UNDEF_80101ad4;
UNDEF_80101ad0:;
/* 80101AD0 38600000 */  li       r3, 0;
UNDEF_80101ad4:;
/* 80101AD4 38000000 */  li       r0, 0;
                         lis      r4, UNDEF_8042a4e8@ha;
                         stw      r0, UNDEF_8042a4e8@l(r4); // dScStage_c::LoopType
/* 80101ADC 8083000C */  lwz      r4, 12(r3);
/* 80101AE0 A0040008 */  lhz      r0, 8(r4);
/* 80101AE4 540007FF */  clrlwi.  r0, r0, 31;
/* 80101AE8 418200AC */  beq-     UNDEF_80101b94;
/* 80101B1C 8885120F */  lbz      r4, 4623(r5);
/* 80101B20 4BF8CC21 */  bl       UNDEF_8008e740;
/* 80101B24 5463043E */  clrlwi   r3, r3, 16;
/* 80101B28 3C004330 */  lis      r0, 17200;
/* 80101B2C 6C638000 */  xoris    r3, r3, 32768;
/* 80101B30 9061000C */  stw      r3, 12(r1);
                         lis      r4, UNDEF_8042d408@ha;
                         lfdu     f3, UNDEF_8042d408@l(r4);
/* 80101B38 90010008 */  stw      r0, 8(r1);
/* 80101B3C          */  lfs      f1, -4(r4);
/* 80101B40 C8410008 */  lfd      f2, 8(r1);
/* 80101B44          */  lfs      f0, -8(r4);
/* 80101B48 EC421828 */  fsubs    f2, f2, f3;
/* 80101B4C EC220072 */  fmuls    f1, f2, f1;
/* 80101B50 EC00082A */  fadds    f0, f0, f1;
/* 80101B54 FC00001E */  fctiwz   f0, f0;
/* 80101B58 D8010010 */  stfd     f0, 16(r1);
/* 80101B5C 80010014 */  lwz      r0, 20(r1);
                         lis      r4, UNDEF_8042a4e8@ha;
/* 80101B60 2C00001A */  cmpwi    r0, 26;
/* 80101B64 4182001C */  beq-     UNDEF_80101b80;
/* 80101B68 2C000020 */  cmpwi    r0, 32;
/* 80101B6C 41820014 */  beq-     UNDEF_80101b80;
/* 80101B70 2C000023 */  cmpwi    r0, 35;
/* 80101B74 4182000C */  beq-     UNDEF_80101b80;
/* 80101B78 2C000025 */  cmpwi    r0, 37;
/* 80101B7C 40820010 */  bne-     UNDEF_80101b8c;
UNDEF_80101b80:;
/* 80101B80 38000001 */  li       r0, 1;
                         stw      r0, UNDEF_8042a4e8@l(r4); // dScStage_c::LoopType
/* 80101B88 4800000C */  b        UNDEF_80101b94;
UNDEF_80101b8c:;
/* 80101B8C 38000002 */  li       r0, 2;
                         stw      r0, UNDEF_8042a4e8@l(r4); // dScStage_c::LoopType
UNDEF_80101b94:;
/* 80101B94 80010024 */  lwz      r0, 36(r1);
/* 80101B98 7C0803A6 */  mtlr     r0;
/* 80101B9C 38210020 */  addi     r1, r1, 32;
/* 80101BA0 4E800020 */  blr;
  // clang-format on
);

[[address(0x801020E0)]]
void dScStage_c::setCollectionCoin(int coin, PLAYER_TYPE_e player);

[[address(0x801022C0)]]
bool dScStage_c::isNowReplay();

[[address(0x80102370)]]
void dScStage_c::goToSceneAfterLevel(
  int profile, int param2, int param3, dFader_c::fader_type_e faderType
);

PATCH_REFERENCES(
  dScStage_c::m_replayPlay_p,
  {
    {0x8006A18A, R_PPC_ADDR16_HA}, {0x8006A18E, R_PPC_ADDR16_LO}, {0x800B5CBA, R_PPC_ADDR16_HA},
    {0x800B5CC2, R_PPC_ADDR16_LO}, {0x800B61FA, R_PPC_ADDR16_HA}, {0x800B6202, R_PPC_ADDR16_LO},
    {0x800B62A6, R_PPC_ADDR16_HA}, {0x800B62AA, R_PPC_ADDR16_LO}, {0x80102142, R_PPC_ADDR16_HA},
    {0x8010214A, R_PPC_ADDR16_LO}, {0x80102182, R_PPC_ADDR16_HA}, {0x80102186, R_PPC_ADDR16_LO},
    {0x8010226A, R_PPC_ADDR16_HA}, {0x8010226E, R_PPC_ADDR16_LO}, {0x801022C2, R_PPC_ADDR16_HA},
    {0x801022C6, R_PPC_ADDR16_LO}, {0x8091F6FE, R_PPC_ADDR16_HA}, {0x8091F706, R_PPC_ADDR16_LO},
    {0x8091F79A, R_PPC_ADDR16_HA}, {0x8091F7B6, R_PPC_ADDR16_LO}, {0x809246AE, R_PPC_ADDR16_HA},
    {0x809246B6, R_PPC_ADDR16_LO},
  }
);