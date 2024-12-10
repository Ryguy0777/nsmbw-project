// d_CharacterChangeSelectBase.cpp
// NSMBW: 0x8076F350 - 0x80772A50

#include "d_CharacterChangeSelectBase.h"

#include <dynamic/bases/d_CharacterChangeSelectContents.h>
#include <dynamic/d_player_model_manager.h>
#include <dynamic/d_remocon_mng.h>
#include <revolution/os.h>

[[address(0x8076FAE0)]]
bool dCharacterChangeSelectBase_c::updateRemocon() ASM_METHOD(
  // clang-format off
/* 8076FAE0 9421FFE0 */  stwu     r1, -32(r1);
/* 8076FAE4 7C0802A6 */  mflr     r0;
/* 8076FAE8 90010024 */  stw      r0, 36(r1);
/* 8076FAEC 39610020 */  addi     r11, r1, 32;
/* 8076FAF0 4BB6D571 */  bl       UNDEF_802dd060;
/* 8076FAF4 800302D8 */  lwz      r0, 728(r3);
/* 8076FAF8 7C7F1B78 */  mr       r31, r3;
/* 8076FAFC 2C000000 */  cmpwi    r0, 0;
/* 8076FB00 4180006C */  blt-     UNDEF_8076fb6c;
/* 8076FB04 3C608043 */  lis      r3, m_instance__13dRemoconMng_c@ha;
/* 8076FB08 5400103A */  slwi     r0, r0, 2;
/* 8076FB0C 8063A308 */  lwz      r3, m_instance__13dRemoconMng_c@l(r3);
/* 8076FB10 7C630214 */  add      r3, r3, r0;
/* 8076FB14 80630004 */  lwz      r3, 4(r3);
/* 8076FB18 8583005C */  lwzu     r12, 92(r3);
/* 8076FB1C 818C0028 */  lwz      r12, 40(r12);
/* 8076FB20 7D8903A6 */  mtctr    r12;
/* 8076FB24 4E800421 */  bctrl;
/* 8076FB28 81830000 */  lwz      r12, 0(r3);
/* 8076FB2C 3C808037 */  lis      r4, UNDEF_80371b70@ha;
/* 8076FB30 38841B70 */  addi     r4, r4, UNDEF_80371b70@l;
/* 8076FB34 818C0010 */  lwz      r12, 16(r12);
/* 8076FB38 7D8903A6 */  mtctr    r12;
/* 8076FB3C 4E800421 */  bctrl;
/* 8076FB40 2C030000 */  cmpwi    r3, 0;
/* 8076FB44 40820114 */  bne-     UNDEF_8076fc58;
/* 8076FB48 801F02D8 */  lwz      r0, 728(r31);
/* 8076FB4C 38A00000 */  li       r5, 0;
/* 8076FB50 809F0280 */  lwz      r4, 640(r31);
/* 8076FB54 7FE3FB78 */  mr       r3, r31;
/* 8076FB58 5400103A */  slwi     r0, r0, 2;
/* 8076FB5C 7CA4012E */  stwx     r5, r4, r0;
/* 8076FB60 4BFFFEE1 */  bl       UNDEF_8076fa40;
/* 8076FB64 38600001 */  li       r3, 1;
/* 8076FB68 480000F4 */  b        UNDEF_8076fc5c;
UNDEF_8076fb6c:;
/* 8076FB6C 3B400000 */  li       r26, 0;
/* 8076FB70 3B600000 */  li       r27, 0;
/* 8076FB74 3F808043 */  lis      r28, m_instance__13dRemoconMng_c@ha;
/* 8076FB78 3FA08037 */  lis      r29, UNDEF_80371b70@ha;
/* 8076FB7C 3BC00004 */  li       r30, 4;
UNDEF_8076fb80:;
/* 8076FB80 801CA308 */  lwz      r0, m_instance__13dRemoconMng_c@l(r28);
/* 8076FB84 7C60DA14 */  add      r3, r0, r27;
/* 8076FB88 80630004 */  lwz      r3, 4(r3);
/* 8076FB8C 8583005C */  lwzu     r12, 92(r3);
/* 8076FB90 818C0028 */  lwz      r12, 40(r12);
/* 8076FB94 7D8903A6 */  mtctr    r12;
/* 8076FB98 4E800421 */  bctrl;
/* 8076FB9C 81830000 */  lwz      r12, 0(r3);
/* 8076FBA0 389D1B70 */  addi     r4, r29, UNDEF_80371b70@l;
/* 8076FBA4 818C0010 */  lwz      r12, 16(r12);
/* 8076FBA8 7D8903A6 */  mtctr    r12;
/* 8076FBAC 4E800421 */  bctrl;
/* 8076FBB0 2C030000 */  cmpwi    r3, 0;
/* 8076FBB4 41820094 */  beq-     UNDEF_8076fc48;
/* 8076FBB8 807F0284 */  lwz      r3, 644(r31);
/* 8076FBBC 38800000 */  li       r4, 0;
/* 8076FBC0 80030000 */  lwz      r0, 0(r3);
/* 8076FBC4 7C1A0000 */  cmpw     r26, r0;
/* 8076FBC8 41820038 */  beq-     UNDEF_8076fc00;
/* 8076FBCC 80030004 */  lwz      r0, 4(r3);
/* 8076FBD0 38800001 */  li       r4, 1;
/* 8076FBD4 7C1A0000 */  cmpw     r26, r0;
/* 8076FBD8 41820028 */  beq-     UNDEF_8076fc00;
/* 8076FBDC 80030008 */  lwz      r0, 8(r3);
/* 8076FBE0 38800002 */  li       r4, 2;
/* 8076FBE4 7C1A0000 */  cmpw     r26, r0;
/* 8076FBE8 41820018 */  beq-     UNDEF_8076fc00;
/* 8076FBEC 8003000C */  lwz      r0, 12(r3);
/* 8076FBF0 38800003 */  li       r4, 3;
/* 8076FBF4 7C1A0000 */  cmpw     r26, r0;
/* 8076FBF8 41820008 */  beq-     UNDEF_8076fc00;
/* 8076FBFC 38800004 */  li       r4, 4;
UNDEF_8076fc00:;
/* 8076FC00 2C040004 */  cmpwi    r4, 4;
/* 8076FC04 41800044 */  blt-     UNDEF_8076fc48;
/* 8076FC08 38A00000 */  li       r5, 0;
/* 8076FC0C 38600000 */  li       r3, 0;
/* 8076FC10 7FC903A6 */  mtctr    r30;
/* 8076FC14 60000000 */  nop;
UNDEF_8076fc18:;
/* 8076FC18 809F0284 */  lwz      r4, 644(r31);
/* 8076FC1C 7C04182E */  lwzx     r0, r4, r3;
/* 8076FC20 2C000000 */  cmpwi    r0, 0;
/* 8076FC24 40800018 */  bge-     UNDEF_8076fc3c;
/* 8076FC28 54A0103A */  slwi     r0, r5, 2;
/* 8076FC2C 38600001 */  li       r3, 1;
/* 8076FC30 7F44012E */  stwx     r26, r4, r0;
/* 8076FC34 935F02D8 */  stw      r26, 728(r31);
/* 8076FC38 48000024 */  b        UNDEF_8076fc5c;
UNDEF_8076fc3c:;
/* 8076FC3C 38630004 */  addi     r3, r3, 4;
/* 8076FC40 38A50001 */  addi     r5, r5, 1;
/* 8076FC44 4200FFD4 */  bdnz+    UNDEF_8076fc18;
UNDEF_8076fc48:;
/* 8076FC48 3B5A0001 */  addi     r26, r26, 1;
/* 8076FC4C 3B7B0004 */  addi     r27, r27, 4;
/* 8076FC50 2C1A0004 */  cmpwi    r26, REMOCON_CONNECT_COUNT;
/* 8076FC54 4180FF2C */  blt+     UNDEF_8076fb80;
UNDEF_8076fc58:;
/* 8076FC58 38600000 */  li       r3, 0;
UNDEF_8076fc5c:;
/* 8076FC5C 39610020 */  addi     r11, r1, 32;
/* 8076FC60 4BB6D44D */  bl       UNDEF_802dd0ac;
/* 8076FC64 80010024 */  lwz      r0, 36(r1);
/* 8076FC68 7C0803A6 */  mtlr     r0;
/* 8076FC6C 38210020 */  addi     r1, r1, 32;
/* 8076FC70 4E800020 */  blr;
  // clang-format on
);

dPyMdlMng_c::ModelType_e get_CHARACTER_FROM_BASE(u32 baseIndex)
{
    return dCharacterChangeSelectBase_c::CHARACTER_FROM_BASE[4 - baseIndex];
}

[[address(0x8076FC80)]]
bool dCharacterChangeSelectBase_c::isCharacterLocked(dPyMdlMng_c::ModelType_e character);

[[address(0x8076FD70)]]
void dCharacterChangeSelectBase_c::UNDEF_8076FD70(u32 swapIndex, u32 baseIndex)
{
    Icon_e iconIndex = ICON_FROM_BASE[4 - baseIndex];

    if (isCharacterLocked(get_CHARACTER_FROM_BASE(baseIndex))) {
        iconIndex = ICON_LOCKED_FROM_BASE[4 - baseIndex];
    }

    if (swapIndex == 0) {
        mpCcSelContents->m0x290 = iconIndex;
    } else {
        mpCcSelContents->m0x298 = iconIndex;
    }
}

[[address(0x8076FE40)]]
void dCharacterChangeSelectBase_c::UNDEF_8076FE40()
{
    mDecidedCharacter = get_CHARACTER_FROM_BASE(mSelectedBaseIndex);
}

u32 sSavedIndexToBaseIndex[] = {4, 3, 2, 1, 4, 4, 4, 4};

[[address(0x8076FEE0)]]
void dCharacterChangeSelectBase_c::UNDEF_8076FEE0() ASM_METHOD(
  // clang-format off
/* 8076FEE0 9421FFF0 */  stwu     r1, -16(r1);
/* 8076FEE4 7C0802A6 */  mflr     r0;
/* 8076FEE8 3C808093 */  lis      r4, sSavedIndexToBaseIndex@ha;
/* 8076FEEC 90010014 */  stw      r0, 20(r1);
/* 8076FEF0 38843D20 */  addi     r4, r4, sSavedIndexToBaseIndex@l;
/* 8076FEF4 93E1000C */  stw      r31, 12(r1);
/* 8076FEF8 7C7F1B78 */  mr       r31, r3;
/* 8076FEFC 800302D8 */  lwz      r0, 728(r3);
/* 8076FF00 80A30278 */  lwz      r5, 632(r3);
/* 8076FF04 5400103A */  slwi     r0, r0, 2;
/* 8076FF08 7C04002E */  lwzx     r0, r4, r0;
/* 8076FF0C 38800000 */  li       r4, 0;
/* 8076FF10 900302E0 */  stw      r0, 736(r3);
/* 8076FF14 880500BB */  lbz      r0, 187(r5);
/* 8076FF18 5400063C */  rlwinm   r0, r0, 0, 24, 30;
/* 8076FF1C 60000001 */  ori      r0, r0, 1;
/* 8076FF20 980500BB */  stb      r0, 187(r5);
/* 8076FF24 80A3027C */  lwz      r5, 636(r3);
/* 8076FF28 880500BB */  lbz      r0, 187(r5);
/* 8076FF2C 5400063C */  rlwinm   r0, r0, 0, 24, 30;
/* 8076FF30 980500BB */  stb      r0, 187(r5);
/* 8076FF34 80A302E0 */  lwz      r5, 736(r3);
/* 8076FF38 4BFFFE39 */  bl       UNDEF_8076fd70;
/* 8076FF3C 807F0074 */  lwz      r3, 116(r31);
/* 8076FF40 38800001 */  li       r4, 1;
/* 8076FF44 38000002 */  li       r0, 2;
/* 8076FF48 9883029D */  stb      r4, 669(r3);
/* 8076FF4C 807F0074 */  lwz      r3, 116(r31);
/* 8076FF50 809F02D8 */  lwz      r4, 728(r31);
/* 8076FF54 90830284 */  stw      r4, 644(r3);
/* 8076FF58 C01F02EC */  lfs      f0, 748(r31);
/* 8076FF5C 807F007C */  lwz      r3, 124(r31);
/* 8076FF60 9003024C */  stw      r0, 588(r3);
/* 8076FF64 D0030234 */  stfs     f0, 564(r3);
/* 8076FF68 83E1000C */  lwz      r31, 12(r1);
/* 8076FF6C 80010014 */  lwz      r0, 20(r1);
/* 8076FF70 7C0803A6 */  mtlr     r0;
/* 8076FF74 38210010 */  addi     r1, r1, 16;
/* 8076FF78 4E800020 */  blr;
  // clang-format on
);

[[address(0x807708E0)]]
void dCharacterChangeSelectBase_c::executeState_SelectWait() ASM_METHOD(
  // clang-format off
/* 807708E0 9421FFE0 */  stwu     r1, -32(r1);
/* 807708E4 7C0802A6 */  mflr     r0;
/* 807708E8 90010024 */  stw      r0, 36(r1);
/* 807708EC 93E1001C */  stw      r31, 28(r1);
/* 807708F0 3FE08099 */  lis      r31, UNDEF_80990948@ha;
/* 807708F4 3BFF0948 */  addi     r31, r31, UNDEF_80990948@l;
/* 807708F8 93C10018 */  stw      r30, 24(r1);
/* 807708FC 7C7E1B78 */  mr       r30, r3;
/* 80770900 93A10014 */  stw      r29, 20(r1);
/* 80770904 4BFFF1DD */  bl       UNDEF_8076fae0;
/* 80770908 2C030000 */  cmpwi    r3, 0;
/* 8077090C 41820028 */  beq-     UNDEF_80770934;
/* 80770910 3800FFFF */  li       r0, -1;
/* 80770914 901E02D8 */  stw      r0, 728(r30);
/* 80770918 387E0228 */  addi     r3, r30, 552;
/* 8077091C 389F0150 */  addi     r4, r31, 336;
// /* 80770920 819E0228 */  lwz      r12, 552(r30);
// /* 80770924 818C0018 */  lwz      r12, 24(r12);
// /* 80770928 7D8903A6 */  mtctr    r12;
// /* 8077092C 4E800421 */  bctrl;
/* 80770930 480001F4 */  b        L_CallChangeState;
UNDEF_80770934:;
/* 80770934 80BE02E0 */  lwz      r5, 736(r30);
/* 80770938 7FC3F378 */  mr       r3, r30;
/* 8077093C 38800000 */  li       r4, 0;
/* 80770940 4BFFF431 */  bl       UNDEF_8076fd70;
/* 80770944 801E02D8 */  lwz      r0, 728(r30);
/* 80770948 3C608037 */  lis      r3, g_core__4mPad@ha;
/* 8077094C 3CA08043 */  lis      r5, UNDEF_8042a230@ha;
/* 80770950 38800900 */  li       r4, 2304;
/* 80770954 5400103A */  slwi     r0, r0, 2;
/* 80770958 38637F88 */  addi     r3, r3, g_core__4mPad@l;
/* 8077095C 7C63002E */  lwzx     r3, r3, r0;
/* 80770960 83A5A230 */  lwz      r29, UNDEF_8042a230@l(r5);
/* 80770964 81830000 */  lwz      r12, 0(r3);
/* 80770968 818C0020 */  lwz      r12, 32(r12);
/* 8077096C 7D8903A6 */  mtctr    r12;
/* 80770970 4E800421 */  bctrl;
/* 80770974 2C030000 */  cmpwi    r3, 0;
/* 80770978 418200F4 */  beq-     UNDEF_80770a6c;

                         lwz      r3, 0x2E0(r30);
                         bl       get_CHARACTER_FROM_BASE__FUl;
                         mr       r4, r3;
/* 807709DC 7FC3F378 */  mr       r3, r30;
/* 807709E4 4BFFF29D */  bl       UNDEF_8076fc80;
/* 807709E8 2C030000 */  cmpwi    r3, 0;
/* 807709EC 40820138 */  bne-     UNDEF_80770b24;

UNDEF_807709f0:;
/* 807709F0 809E0288 */  lwz      r4, 648(r30);
/* 807709F4 80640000 */  lwz      r3, 0(r4);
/* 807709F8 38030001 */  addi     r0, r3, 1;
/* 807709FC 90040000 */  stw      r0, 0(r4);
/* 80770A00 809E0288 */  lwz      r4, 648(r30);
/* 80770A04 807E02E8 */  lwz      r3, 744(r30);
/* 80770A08 80040000 */  lwz      r0, 0(r4);
/* 80770A0C 7C001800 */  cmpw     r0, r3;
/* 80770A10 41800028 */  blt-     UNDEF_80770a38;
/* 80770A14 90640000 */  stw      r3, 0(r4);
/* 80770A18 3C608043 */  lis      r3, m_nowScene__8dScene_c@ha;
/* 80770A1C A0038A42 */  lhz      r0, m_nowScene__8dScene_c@l(r3);
/* 80770A20 28000003 */  cmplwi   r0, 3;
/* 80770A24 41820014 */  beq-     UNDEF_80770a38;
/* 80770A28 3C608043 */  lis      r3, UNDEF_8042a788@ha;
/* 80770A2C 38800003 */  li       r4, 3;
/* 80770A30 8063A788 */  lwz      r3, UNDEF_8042a788@l(r3);
/* 80770A34 4BA2B12D */  bl       UNDEF_8019bb60;
UNDEF_80770a38:;
/* 80770A38 801E02E0 */  lwz      r0, 736(r30);
/* 80770A3C 3CA08093 */  lis      r5, UNDEF_80933d30@ha;
/* 80770A40 38A53D30 */  addi     r5, r5, UNDEF_80933d30@l;
/* 80770A44 387E0228 */  addi     r3, r30, 552;
/* 80770A48 5400103A */  slwi     r0, r0, 2;
/* 80770A4C 389F02D0 */  addi     r4, r31, 720;
/* 80770A50 7C05002E */  lwzx     r0, r5, r0;
/* 80770A54 901E02A0 */  stw      r0, 672(r30);
// /* 80770A58 819E0228 */  lwz      r12, 552(r30);
// /* 80770A5C 818C0018 */  lwz      r12, 24(r12);
// /* 80770A60 7D8903A6 */  mtctr    r12;
// /* 80770A64 4E800421 */  bctrl;
/* 80770A68          */  b        L_CallChangeState;
UNDEF_80770a6c:;
/* 80770A6C 809E02D8 */  lwz      r4, 728(r30);
/* 80770A70 5480103A */  slwi     r0, r4, 2;
/* 80770A74 7C7D0214 */  add      r3, r29, r0;
/* 80770A78 80630004 */  lwz      r3, 4(r3);
/* 80770A7C 8003001C */  lwz      r0, 28(r3);
/* 80770A80 54000739 */  rlwinm.  r0, r0, 0, 28, 28;
/* 80770A84 41820048 */  beq-     UNDEF_80770acc;
/* 80770A88 807E02E0 */  lwz      r3, 736(r30);

                         // Changed from 3 to 4 to allow selecting Mario
/* 80770A8C          */  cmpwi    r3, 4;

/* 80770A90 4080003C */  bge-     UNDEF_80770acc;
/* 80770A94 38800005 */  li       r4, 5;
/* 80770A98 909E02A0 */  stw      r4, 672(r30);
/* 80770A9C 38030001 */  addi     r0, r3, 1;
/* 80770AA0 80BE0078 */  lwz      r5, 120(r30);
/* 80770AA4 901E02E0 */  stw      r0, 736(r30);
/* 80770AA8 38000001 */  li       r0, 1;
// /* 80770AAC 387E0228 */  addi     r3, r30, 552;
// /* 80770AB0 389F0290 */  addi     r4, r31, 656;
// /* 80770AB4 90050258 */  stw      r0, 600(r5);
// /* 80770AB8 819E0228 */  lwz      r12, 552(r30);
// /* 80770ABC 818C0018 */  lwz      r12, 24(r12);
// /* 80770AC0 7D8903A6 */  mtctr    r12;
// /* 80770AC4 4E800421 */  bctrl;
/* 80770AC8          */  b        L_CallChangeStateWithStw;
UNDEF_80770acc:;
/* 80770ACC 5480103A */  slwi     r0, r4, 2;
/* 80770AD0 7C7D0214 */  add      r3, r29, r0;
/* 80770AD4 80630004 */  lwz      r3, 4(r3);
/* 80770AD8 8003001C */  lwz      r0, 28(r3);
/* 80770ADC 5400077B */  rlwinm.  r0, r0, 0, 29, 29;
/* 80770AE0 41820044 */  beq-     UNDEF_80770b24;
/* 80770AE4 807E02E0 */  lwz      r3, 736(r30);

                         // Changed from 1 to 0 to allow selecting Toadette
/* 80770AE8          */  cmpwi    r3, 0;

/* 80770AEC 40810038 */  ble-     UNDEF_80770b24;
/* 80770AF0 38800004 */  li       r4, 4;
/* 80770AF4 909E02A0 */  stw      r4, 672(r30);
/* 80770AF8 3803FFFF */  subi     r0, r3, 1;
/* 80770AFC 80BE0078 */  lwz      r5, 120(r30);
/* 80770B00 901E02E0 */  stw      r0, 736(r30);
/* 80770B04 38000002 */  li       r0, 2;
L_CallChangeStateWithStw:;
/* 80770B08 387E0228 */  addi     r3, r30, 552;
/* 80770B0C 389F0290 */  addi     r4, r31, 656;
/* 80770B10 90050258 */  stw      r0, 600(r5);
L_CallChangeState:;
/* 80770B14 819E0228 */  lwz      r12, 552(r30);
/* 80770B18 818C0018 */  lwz      r12, 24(r12);
/* 80770B1C 7D8903A6 */  mtctr    r12;
/* 80770B20 4E800421 */  bctrl;
UNDEF_80770b24:;
/* 80770B24 80010024 */  lwz      r0, 36(r1);
/* 80770B28 83E1001C */  lwz      r31, 28(r1);
/* 80770B2C 83C10018 */  lwz      r30, 24(r1);
/* 80770B30 83A10014 */  lwz      r29, 20(r1);
/* 80770B34 7C0803A6 */  mtlr     r0;
/* 80770B38 38210020 */  addi     r1, r1, 32;
/* 80770B3C 4E800020 */  blr;

  // clang-format on
);

[[address(0x80771090)]]
void dCharacterChangeSelectBase_c::initializeState_PlayerOnStageWait() ASM_METHOD(
  // clang-format off
/* 80771090 9421FFF0 */  stwu     r1, -16(r1);
/* 80771094 7C0802A6 */  mflr     r0;
/* 80771098 90010014 */  stw      r0, 20(r1);
/* 8077109C 93E1000C */  stw      r31, 12(r1);
/* 807710A0 7C7F1B78 */  mr       r31, r3;
/* 807710A4 800302D4 */  lwz      r0, 724(r3);
                         cmpwi    r0, 0;
                         bne-     L_initializeState_PlayerOnStageWait_LuigiSound;
                         
                         // Mario voice
                         slwi     r0, r0, 2;
                         add      r3, r3, r0;
                         lwz      r3, 128(r3);
                         lwz      r0, 568(r3);
                         cmpwi    r0, 3;
                         bne-     L_initializeState_PlayerOnStageWait_MarioSoundNotMini;
                         lis      r3, UNDEF_8042a768@ha;
                         li       r4, 798; // SE_VOC_MA_PLAYER_JOIN_MAME
                         lwz      r3, UNDEF_8042a768@l(r3);
                         li       r5, 1;
                         bl       UNDEF_801954c0;
                         b        UNDEF_8077118c;
L_initializeState_PlayerOnStageWait_MarioSoundNotMini:;
                         lis      r3, UNDEF_8042a768@ha;
                         li       r4, 797; // SE_VOC_MA_PLAYER_JOIN
                         lwz      r3, UNDEF_8042a768@l(r3);
                         li       r5, 1;
                         bl       UNDEF_801954c0;
                         b        UNDEF_8077118c;

L_initializeState_PlayerOnStageWait_LuigiSound:;
/* 807710A8 2C000001 */  cmpwi    r0, 1;
/* 807710AC 4082004C */  bne-     L_initializeState_PlayerOnStageWait_BlueToadSound;
/* 807710B0 5400103A */  slwi     r0, r0, 2;
/* 807710B4 7C630214 */  add      r3, r3, r0;
/* 807710B8 80630080 */  lwz      r3, 128(r3);
/* 807710BC 80030238 */  lwz      r0, 568(r3);
/* 807710C0 2C000003 */  cmpwi    r0, 3;
/* 807710C4 4082001C */  bne-     UNDEF_807710e0;
/* 807710C8 3C608043 */  lis      r3, UNDEF_8042a768@ha;
/* 807710CC 38800366 */  li       r4, 870;
/* 807710D0 8063A768 */  lwz      r3, UNDEF_8042a768@l(r3);
/* 807710D4 38A00001 */  li       r5, 1;
/* 807710D8 4BA243E9 */  bl       UNDEF_801954c0;
/* 807710DC 480000B0 */  b        UNDEF_8077118c;
UNDEF_807710e0:;
/* 807710E0 3C608043 */  lis      r3, UNDEF_8042a768@ha;
/* 807710E4 38800365 */  li       r4, 869;
/* 807710E8 8063A768 */  lwz      r3, UNDEF_8042a768@l(r3);
/* 807710EC 38A00001 */  li       r5, 1;
/* 807710F0 4BA243D1 */  bl       UNDEF_801954c0;
/* 807710F4 48000098 */  b        UNDEF_8077118c;

L_initializeState_PlayerOnStageWait_BlueToadSound:;
/* 807710F8 2C000002 */  cmpwi    r0, 2;
/* 807710FC 4082004C */  bne-     L_initializeState_PlayerOnStageWait_YellowToadSound;
/* 80771100 5400103A */  slwi     r0, r0, 2;
/* 80771104 7C630214 */  add      r3, r3, r0;
/* 80771108 80630080 */  lwz      r3, 128(r3);
/* 8077110C 80030238 */  lwz      r0, 568(r3);
/* 80771110 2C000003 */  cmpwi    r0, 3;
/* 80771114 4082001C */  bne-     UNDEF_80771130;
/* 80771118 3C608043 */  lis      r3, UNDEF_8042a768@ha;
/* 8077111C 388003AD */  li       r4, 941;
/* 80771120 8063A768 */  lwz      r3, UNDEF_8042a768@l(r3);
/* 80771124 38A00001 */  li       r5, 1;
/* 80771128 4BA24399 */  bl       UNDEF_801954c0;
/* 8077112C 48000060 */  b        UNDEF_8077118c;
UNDEF_80771130:;
/* 80771130 3C608043 */  lis      r3, UNDEF_8042a768@ha;
/* 80771134 388003AC */  li       r4, 940;
/* 80771138 8063A768 */  lwz      r3, UNDEF_8042a768@l(r3);
/* 8077113C 38A00001 */  li       r5, 1;
/* 80771140 4BA24381 */  bl       UNDEF_801954c0;
/* 80771144 48000048 */  b        UNDEF_8077118c;

L_initializeState_PlayerOnStageWait_YellowToadSound:;
/* 80771148 5400103A */  slwi     r0, r0, 2;
/* 8077114C 7C630214 */  add      r3, r3, r0;
/* 80771150 80630080 */  lwz      r3, 128(r3);
/* 80771154 80030238 */  lwz      r0, 568(r3);
/* 80771158 2C000003 */  cmpwi    r0, 3;
/* 8077115C 4082001C */  bne-     UNDEF_80771178;
/* 80771160 3C608043 */  lis      r3, UNDEF_8042a768@ha;
/* 80771164 388003F3 */  li       r4, 1011;
/* 80771168 8063A768 */  lwz      r3, UNDEF_8042a768@l(r3);
/* 8077116C 38A00001 */  li       r5, 1;
/* 80771170 4BA24351 */  bl       UNDEF_801954c0;
/* 80771174 48000018 */  b        UNDEF_8077118c;
UNDEF_80771178:;
/* 80771178 3C608043 */  lis      r3, UNDEF_8042a768@ha;
/* 8077117C 388003F2 */  li       r4, 1010;
/* 80771180 8063A768 */  lwz      r3, UNDEF_8042a768@l(r3);
/* 80771184 38A00001 */  li       r5, 1;
/* 80771188 4BA24339 */  bl       UNDEF_801954c0;
UNDEF_8077118c:;
/* 8077118C 801F02D8 */  lwz      r0, 728(r31);
/* 80771190 3C608035 */  lis      r3, mPlayerType__9daPyMng_c@ha;
/* 80771194 80BF02D4 */  lwz      r5, 724(r31);
/* 80771198 38635160 */  addi     r3, r3, mPlayerType__9daPyMng_c@l;
/* 8077119C 5404103A */  slwi     r4, r0, 2;
/* 807711A0 54A0103A */  slwi     r0, r5, 2;
/* 807711A4 7CA3212E */  stwx     r5, r3, r4;
/* 807711A8 7C7F0214 */  add      r3, r31, r0;
/* 807711AC 80A30080 */  lwz      r5, 128(r3);
/* 807711B0 88050262 */  lbz      r0, 610(r5);
/* 807711B4 2C000000 */  cmpwi    r0, 0;
/* 807711B8 40820034 */  bne-     UNDEF_807711ec;
/* 807711BC 88050263 */  lbz      r0, 611(r5);
/* 807711C0 2C000000 */  cmpwi    r0, 0;
/* 807711C4 40820028 */  bne-     UNDEF_807711ec;
/* 807711C8 38800001 */  li       r4, 1;
/* 807711CC 98850263 */  stb      r4, 611(r5);
/* 807711D0 38000002 */  li       r0, 2;
/* 807711D4 3C608093 */  lis      r3, UNDEF_80933d50@ha;
/* 807711D8 9005023C */  stw      r0, 572(r5);
/* 807711DC C0033D50 */  lfs      f0, UNDEF_80933d50@l(r3);
/* 807711E0 90850240 */  stw      r4, 576(r5);
/* 807711E4 D0050250 */  stfs     f0, 592(r5);
/* 807711E8 98850265 */  stb      r4, 613(r5);
UNDEF_807711ec:;
/* 807711EC 807F02D4 */  lwz      r3, 724(r31);
/* 807711F0 38000001 */  li       r0, 1;
/* 807711F4 C01F02F0 */  lfs      f0, 752(r31);
/* 807711F8 5463103A */  slwi     r3, r3, 2;
/* 807711FC 7C7F1A14 */  add      r3, r31, r3;
/* 80771200 80630080 */  lwz      r3, 128(r3);
/* 80771204 D003025C */  stfs     f0, 604(r3);
/* 80771208 981F0296 */  stb      r0, 662(r31);
/* 8077120C 83E1000C */  lwz      r31, 12(r1);
/* 80771210 80010014 */  lwz      r0, 20(r1);
/* 80771214 7C0803A6 */  mtlr     r0;
/* 80771218 38210010 */  addi     r1, r1, 16;
/* 8077121C 4E800020 */  blr;
  // clang-format on
);