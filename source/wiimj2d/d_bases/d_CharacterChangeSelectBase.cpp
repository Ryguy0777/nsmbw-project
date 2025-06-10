// d_CharacterChangeSelectBase.cpp
// NSMBW: 0x8076F350 - 0x80772A50

#include "d_CharacterChangeSelectBase.h"

#include <d_bases/d_CharacterChangeSelectContents.h>
#include <d_system/d_player_model_manager.h>
#include <d_system/d_remocon_mng.h>
#include <revolution/os.h>

daPyMng_c::PlayerType_e g_CHARACTER_FROM_BASE[] = {
  daPyMng_c::PlayerType_e::MARIO,       daPyMng_c::PlayerType_e::LUIGI,
  daPyMng_c::PlayerType_e::YELLOW_TOAD, daPyMng_c::PlayerType_e::BLUE_TOAD,
  daPyMng_c::PlayerType_e::TOADETTE,    daPyMng_c::PlayerType_e::PURPLE_TOADETTE,
  daPyMng_c::PlayerType_e::ORANGE_TOAD, daPyMng_c::PlayerType_e::BLACK_TOAD,
};

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

daPyMng_c::PlayerType_e  get_CHARACTER_FROM_BASE(u32 baseIndex)
{
    return dCharacterChangeSelectBase_c::CHARACTER_FROM_BASE[4 - baseIndex];
}

[[address(0x8076FC80)]]
bool dCharacterChangeSelectBase_c::isCharacterLocked(daPyMng_c::PlayerType_e  character);

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

[[address(0x807702A0)]]
void dCharacterChangeSelectBase_c::executeState_OnStageAnimeEndWait() ASM_METHOD(
  // clang-format off
/* 807702A0 9421FFE0 */  stwu     r1, -32(r1);
/* 807702A4 7C0802A6 */  mflr     r0;
/* 807702A8 90010024 */  stw      r0, 36(r1);
/* 807702AC 93E1001C */  stw      r31, 28(r1);
/* 807702B0 7C7F1B78 */  mr       r31, r3;
/* 807702B4 93C10018 */  stw      r30, 24(r1);
/* 807702B8 3FC08099 */  lis      r30, UNDEF_80990948@ha;
/* 807702BC 3BDE0948 */  addi     r30, r30, UNDEF_80990948@l;
/* 807702C0 88030299 */  lbz      r0, 665(r3);
/* 807702C4 2C000000 */  cmpwi    r0, 0;
/* 807702C8 41820108 */  beq-     UNDEF_807703d0;
/* 807702CC 3C808043 */  lis      r4, m_nowScene__8dScene_c@ha;
/* 807702D0 A0A48A42 */  lhz      r5, m_nowScene__8dScene_c@l(r4);
/* 807702D4 28050003 */  cmplwi   r5, 3;
/* 807702D8 408200B8 */  bne-     UNDEF_80770390;
/* 807702DC 800302D8 */  lwz      r0, 728(r3);
/* 807702E0 80830280 */  lwz      r4, 640(r3);
/* 807702E4 5400103A */  slwi     r0, r0, 2;
/* 807702E8 7C04002E */  lwzx     r0, r4, r0;
/* 807702EC 2C000003 */  cmpwi    r0, 3;
/* 807702F0 408200A0 */  bne-     UNDEF_80770390;
/* 807702F4 4BFFFB6D */  bl       UNDEF_8076fe60;
/* 807702F8 7FE3FB78 */  mr       r3, r31;
/* 807702FC 4BFFFB45 */  bl       UNDEF_8076fe40;
/* 80770300 80BF02DC */  lwz      r5, 732(r31);
/* 80770304 387F0228 */  addi     r3, r31, 552;
/* 80770308 801F02D4 */  lwz      r0, 724(r31);
/* 8077030C 389E03D0 */  addi     r4, r30, 976;
/* 80770310 1CA5000C */  mulli    r5, r5, 12;
/* 80770314 C07F02F0 */  lfs      f3, 752(r31);
/* 80770318 5400103A */  slwi     r0, r0, 2;
/* 8077031C 7CDF2A14 */  add      r6, r31, r5;
/* 80770320          */  lwz      r5, 0x80(r31);
/* 80770324 C00602AC */  lfs      f0, 684(r6);
/* 80770328 C02602A8 */  lfs      f1, 680(r6);
/* 8077032C C04602A4 */  lfs      f2, 676(r6);
/* 80770330          */  lwzx     r5, r5, r0; 
/* 80770334 D0410008 */  stfs     f2, 8(r1);
/* 80770338 D065025C */  stfs     f3, 604(r5);
/* 80770340 D021000C */  stfs     f1, 12(r1);
/* 8077034C D0010010 */  stfs     f0, 16(r1);
/* 80770354 D045022C */  stfs     f2, 556(r5);
/* 80770358 D0250230 */  stfs     f1, 560(r5);
/* 8077035C D0050234 */  stfs     f0, 564(r5);
/* 80770370 D04500AC */  stfs     f2, 172(r5);
/* 80770374 D02500B0 */  stfs     f1, 176(r5);
/* 80770378 D00500B4 */  stfs     f0, 180(r5);
/* 8077037C 819F0228 */  lwz      r12, 552(r31);
/* 80770380 818C0018 */  lwz      r12, 24(r12);
/* 80770384 7D8903A6 */  mtctr    r12;
/* 80770388 4E800421 */  bctrl;
/* 8077038C 48000044 */  b        UNDEF_807703d0;
UNDEF_80770390:;
/* 80770390 28050003 */  cmplwi   r5, 3;
/* 80770394 41820028 */  beq-     UNDEF_807703bc;
/* 80770398 800302D8 */  lwz      r0, 728(r3);
/* 8077039C 2C000000 */  cmpwi    r0, 0;
/* 807703A0 4180001C */  blt-     UNDEF_807703bc;
/* 807703A4 85830228 */  lwzu     r12, 552(r3);
/* 807703A8 389E0210 */  addi     r4, r30, 528;
/* 807703AC 818C0018 */  lwz      r12, 24(r12);
/* 807703B0 7D8903A6 */  mtctr    r12;
/* 807703B4 4E800421 */  bctrl;
/* 807703B8 48000018 */  b        UNDEF_807703d0;
UNDEF_807703bc:;
/* 807703BC 85830228 */  lwzu     r12, 552(r3);
/* 807703C0 389E00D0 */  addi     r4, r30, 208;
/* 807703C4 818C0018 */  lwz      r12, 24(r12);
/* 807703C8 7D8903A6 */  mtctr    r12;
/* 807703CC 4E800421 */  bctrl;
UNDEF_807703d0:;
/* 807703D0 80010024 */  lwz      r0, 36(r1);
/* 807703D4 83E1001C */  lwz      r31, 28(r1);
/* 807703D8 83C10018 */  lwz      r30, 24(r1);
/* 807703DC 7C0803A6 */  mtlr     r0;
/* 807703E0 38210020 */  addi     r1, r1, 32;
/* 807703E4 4E800020 */  blr;
  // clang-format on
)

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

                         // Changed from 1 to -3 to allow selecting four extra characters
/* 80770AE8          */  cmpwi    r3, 5 - CHARACTER_LIST_COUNT;

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

[[address(0x80770EE0)]]
void dCharacterChangeSelectBase_c::initializeState_ExitAnimeEndForPlayerOnStageWait() ASM_METHOD(
  // clang-format off
/* 80770EE0 9421FFD0 */  stwu     r1, -48(r1);
/* 80770EE4 7C0802A6 */  mflr     r0;
/* 80770EE8 3C808093 */  lis      r4, UNDEF_80933d48@ha;
/* 80770EEC 3CE08093 */  lis      r7, UNDEF_80933d40@ha;
/* 80770EF0 90010034 */  stw      r0, 52(r1);
/* 80770EF4 3C004330 */  lis      r0, 17200;
/* 80770EF8 C8443D48 */  lfd      f2, UNDEF_80933d48@l(r4);
/* 80770EFC 93E1002C */  stw      r31, 44(r1);
/* 80770F00 7C7F1B78 */  mr       r31, r3;
/* 80770F04 C0273D40 */  lfs      f1, UNDEF_80933d40@l(r7);
/* 80770F08 93C10028 */  stw      r30, 40(r1);
/* 80770F0C 3BC00001 */  li       r30, 1;
/* 80770F10 80C302DC */  lwz      r6, 732(r3);
/* 80770F14 80A302D4 */  lwz      r5, 724(r3);
/* 80770F18 1D06000C */  mulli    r8, r6, 12;
/* 80770F1C 3CC08093 */  lis      r6, UNDEF_809352b0@ha;
/* 80770F20 54A5103A */  slwi     r5, r5, 2;
/* 80770F24 90010020 */  stw      r0, 32(r1);
/* 80770F28 7D234214 */  add      r9, r3, r8;
                         lwz      r12, 0x80(r3);
/* 80770F30 C06902AC */  lfs      f3, 684(r9);
/* 80770F34 3D008043 */  lis      r8, UNDEF_8042a760@ha;
/* 80770F38 C08902A8 */  lfs      f4, 680(r9);
/* 80770F40          */  lwzx     r10, r12, r5;
/* 80770F3C 38A00000 */  li       r5, 0;
/* 80770F44 38800004 */  li       r4, 4;
/* 80770F48 C00902A4 */  lfs      f0, 676(r9);
/* 80770F4C D00A022C */  stfs     f0, 556(r10);
/* 80770F50 C00652B0 */  lfs      f0, UNDEF_809352b0@l(r6);
/* 80770F54 D08A0230 */  stfs     f4, 560(r10);
/* 80770F58 EC010032 */  fmuls    f0, f1, f0;
/* 80770F5C D06A0234 */  stfs     f3, 564(r10);
/* 80770F60 80C8A760 */  lwz      r6, UNDEF_8042a760@l(r8);
/* 80770F64 C0A30104 */  lfs      f5, 260(r3);
/* 80770F68 80C60000 */  lwz      r6, 0(r6);
/* 80770F6C 800302D4 */  lwz      r0, 724(r3);
/* 80770F70 A0C60004 */  lhz      r6, 4(r6);
/* 80770F74 90C10024 */  stw      r6, 36(r1);
/* 80770F78 5400103A */  slwi     r0, r0, 2;
/* 80770F7C          */  lwz      r6, 0x80(r3);
/* 80770F80 C0C30108 */  lfs      f6, 264(r3);
/* 80770F84 C8210020 */  lfd      f1, 32(r1);
/* 80770F88          */  lwzx     r6, r6, r0;
/* 80770F8C EC211028 */  fsubs    f1, f1, f2;
/* 80770F90 D0810014 */  stfs     f4, 20(r1);
/* 80770F94 D0610018 */  stfs     f3, 24(r1);
/* 80770F98 EC212824 */  fdivs    f1, f1, f5;
/* 80770F9C D0A10008 */  stfs     f5, 8(r1);
/* 80770FA0 D0C1000C */  stfs     f6, 12(r1);
/* 80770FA4 EC01002A */  fadds    f0, f1, f0;
/* 80770FA8 D00600AC */  stfs     f0, 172(r6);
/* 80770FAC D08600B0 */  stfs     f4, 176(r6);
/* 80770FB0 D06600B4 */  stfs     f3, 180(r6);
/* 80770FB8 D0010010 */  stfs     f0, 16(r1);
/* 80770FC8 9BC60267 */  stb      r30, 615(r6);
/* 80770FD8 38630090 */  addi     r3, r3, 144;
/* 80770FE0 9BC60261 */  stb      r30, 609(r6);
/* 80770FE4 4B9583FD */  bl       UNDEF_800c93e0;
/* 80770FE8 9BDF0296 */  stb      r30, 662(r31);
/* 80770FEC 83E1002C */  lwz      r31, 44(r1);
/* 80770FF0 83C10028 */  lwz      r30, 40(r1);
/* 80770FF4 80010034 */  lwz      r0, 52(r1);
/* 80770FF8 7C0803A6 */  mtlr     r0;
/* 80770FFC 38210030 */  addi     r1, r1, 48;
/* 80771000 4E800020 */  blr;
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
                         lwz      r3, 0x80(r3);
                         lwzx     r3, r3, r0;
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
/* 807710B4          */  lwz      r3, 0x80(r3);
/* 807710B8          */  lwzx     r3, r3, r0;
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
/* 80771104          */  lwz      r3, 0x80(r3);
/* 80771108          */  lwzx     r3, r3, r0;
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
/* 8077114C          */  lwz      r3, 0x80(r3);
/* 80771150          */  lwzx     r3, r3, r0;
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
/* 807711A8          */  lwz      r3, 0x80(r31);
/* 807711AC          */  lwzx     r5, r3, r0;
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
/* 807711FC          */  lwz      r4, 0x80(r31);
/* 80771200          */  lwzx     r3, r4, r3;
/* 80771204 D003025C */  stfs     f0, 604(r3);
/* 80771208 981F0296 */  stb      r0, 662(r31);
/* 8077120C 83E1000C */  lwz      r31, 12(r1);
/* 80771210 80010014 */  lwz      r0, 20(r1);
/* 80771214 7C0803A6 */  mtlr     r0;
/* 80771218 38210010 */  addi     r1, r1, 16;
/* 8077121C 4E800020 */  blr;
  // clang-format on
);

[[address(0x80771220)]]
void dCharacterChangeSelectBase_c::executeState_PlayerOnStageWait() ASM_METHOD(
  // clang-format off
/* 80771220 800302D4 */  lwz      r0, 724(r3);
/* 80771224 5400103A */  slwi     r0, r0, 2;
/* 80771228          */  lwz      r4, 0x80(r3);
/* 8077122C 80840080 */  lwzx     r4, r4, r0;
/* 80771230 88040263 */  lbz      r0, 611(r4);
/* 80771234 2C000000 */  cmpwi    r0, 0;
/* 80771238 4C820020 */  bnelr-;
/* 8077123C 88040262 */  lbz      r0, 610(r4);
/* 80771240 2C000000 */  cmpwi    r0, 0;
/* 80771244 41820008 */  beq-     UNDEF_8077124c;
/* 80771248 4E800020 */  blr;
UNDEF_8077124c:;
/* 8077124C 85830228 */  lwzu     r12, 552(r3);
/* 80771250 3C808099 */  lis      r4, UNDEF_80990d18@ha;
/* 80771254 38840D18 */  addi     r4, r4, UNDEF_80990d18@l;
/* 80771258 818C0018 */  lwz      r12, 24(r12);
/* 8077125C 7D8903A6 */  mtctr    r12;
/* 80771260 4E800420 */  bctr;
  // clang-format on
);

[[address(0x80771270)]]
void dCharacterChangeSelectBase_c::finalizeState_PlayerOnStageWait() ASM_METHOD(
  // clang-format off
/* 80771270 808302D4 */  lwz      r4, 724(r3);
/* 80771274 38A00000 */  li       r5, 0;
/* 80771278 38000001 */  li       r0, 1;
/* 8077127C 5484103A */  slwi     r4, r4, 2;
/* 80771280          */  lwz      r6, 0x80(r3);
/* 80771284          */  lwzx     r4, r6, r4;
/* 80771288 98A40267 */  stb      r5, 615(r4);
/* 8077128C C00302EC */  lfs      f0, 748(r3);
/* 80771290 8083007C */  lwz      r4, 124(r3);
/* 80771294 9004024C */  stw      r0, 588(r4);
/* 80771298 D0040234 */  stfs     f0, 564(r4);
/* 8077129C 98A30296 */  stb      r5, 662(r3);
/* 807712A0 4E800020 */  blr;
  // clang-format on
);

[[address(0x807712B0)]]
void dCharacterChangeSelectBase_c::initializeState_PlayerDisp() ASM_METHOD(
  // clang-format off
/* 807712B0 808302D4 */  lwz      r4, 724(r3);
/* 807712B4 38000001 */  li       r0, 1;
/* 807712B8 80A302D8 */  lwz      r5, 728(r3);
/* 807712BC 5484103A */  slwi     r4, r4, 2;
/* 807712C0          */  lwz      r6, 0x80(r3);
/* 807712C4          */  lwzx     r4, r6, r4;
/* 807712C8 90A40248 */  stw      r5, 584(r4);
/* 807712CC 9803029A */  stb      r0, 666(r3);
/* 807712D0 4E800020 */  blr;
  // clang-format on
);

[[address(0x807712E0)]]
void dCharacterChangeSelectBase_c::executeState_PlayerDisp() ASM_METHOD(
  // clang-format off
/* 807712E0 9421FFF0 */  stwu     r1, -16(r1);
/* 807712E4 7C0802A6 */  mflr     r0;
/* 807712E8 90010014 */  stw      r0, 20(r1);
/* 807712EC 93E1000C */  stw      r31, 12(r1);
/* 807712F0 7C7F1B78 */  mr       r31, r3;
/* 807712F4 4BFFE7ED */  bl       UNDEF_8076fae0;
/* 807712F8 2C030000 */  cmpwi    r3, 0;
/* 807712FC 41820050 */  beq-     UNDEF_8077134c;
/* 80771300 801F02D4 */  lwz      r0, 724(r31);
/* 80771304 38C00001 */  li       r6, 1;
/* 80771308 3C808099 */  lis      r4, UNDEF_80990dd8@ha;
/* 8077130C 98DF0299 */  stb      r6, 665(r31);
/* 80771310 5403103A */  slwi     r3, r0, 2;
/* 80771314 3800FFFF */  li       r0, -1;
/* 80771318          */  lwz      r5, 0x80(r31);
/* 8077131C 38840DD8 */  addi     r4, r4, UNDEF_80990dd8@l;
/* 80771320          */  lwzx     r5, r5, r3;
/* 80771324 387F0228 */  addi     r3, r31, 552;
/* 80771328 98C50269 */  stb      r6, 617(r5);
/* 8077132C 80BF0074 */  lwz      r5, 116(r31);
/* 80771330 98C5029F */  stb      r6, 671(r5);
/* 80771334 901F02D8 */  stw      r0, 728(r31);
/* 80771338 819F0228 */  lwz      r12, 552(r31);
/* 8077133C 818C0018 */  lwz      r12, 24(r12);
/* 80771340 7D8903A6 */  mtctr    r12;
/* 80771344 4E800421 */  bctrl;
/* 80771348 4800006C */  b        UNDEF_807713b4;
UNDEF_8077134c:;
/* 8077134C 807F02D8 */  lwz      r3, 728(r31);
/* 80771350 4B9440A1 */  bl       UNDEF_800b53f0;
/* 80771354 2C030000 */  cmpwi    r3, 0;
/* 80771358 4182005C */  beq-     UNDEF_807713b4;
/* 8077135C 3C608043 */  lis      r3, UNDEF_8042a768@ha;
/* 80771360 3880007A */  li       r4, 122;
/* 80771364 8063A768 */  lwz      r3, UNDEF_8042a768@l(r3);
/* 80771368 38A00001 */  li       r5, 1;
/* 8077136C 4BA24155 */  bl       UNDEF_801954c0;
/* 80771370 809F0288 */  lwz      r4, 648(r31);
/* 80771374 80640000 */  lwz      r3, 0(r4);
/* 80771378 3803FFFF */  subi     r0, r3, 1;
/* 8077137C 90040000 */  stw      r0, 0(r4);
/* 80771380 807F0288 */  lwz      r3, 648(r31);
/* 80771384 80030000 */  lwz      r0, 0(r3);
/* 80771388 2C000000 */  cmpwi    r0, 0;
/* 8077138C 4080000C */  bge-     UNDEF_80771398;
/* 80771390 38000000 */  li       r0, 0;
/* 80771394 90030000 */  stw      r0, 0(r3);
UNDEF_80771398:;
/* 80771398 819F0228 */  lwz      r12, 552(r31);
/* 8077139C 3C808099 */  lis      r4, UNDEF_80990d58@ha;
/* 807713A0 387F0228 */  addi     r3, r31, 552;
/* 807713A4 818C0018 */  lwz      r12, 24(r12);
/* 807713A8 38840D58 */  addi     r4, r4, UNDEF_80990d58@l;
/* 807713AC 7D8903A6 */  mtctr    r12;
/* 807713B0 4E800421 */  bctrl;
UNDEF_807713b4:;
/* 807713B4 80010014 */  lwz      r0, 20(r1);
/* 807713B8 83E1000C */  lwz      r31, 12(r1);
/* 807713BC 7C0803A6 */  mtlr     r0;
/* 807713C0 38210010 */  addi     r1, r1, 16;
/* 807713C4 4E800020 */  blr;
  // clang-format on
);

[[address(0x807713E0)]]
void dCharacterChangeSelectBase_c::initializeState_PlayerExitWait() ASM_METHOD(
  // clang-format off
/* 807713E0 800302D4 */  lwz      r0, 724(r3);
/* 807713E4 3C808093 */  lis      r4, UNDEF_809352b0@ha;
/* 807713E8 C00452B0 */  lfs      f0, UNDEF_809352b0@l(r4);
/* 807713EC 5400103A */  slwi     r0, r0, 2;
/* 807713F0          */  lwz      r4, 0x80(r3);
/* 807713F4          */  lwzx     r6, r4, r0;
/* 807713F8 D004022C */  stfs     f0, 556(r6);
/* 8077140C 88060262 */  lbz      r0, 610(r6);
/* 80771410 2C000000 */  cmpwi    r0, 0;
/* 80771414 40820034 */  bne-     UNDEF_80771448;
/* 80771418 88060263 */  lbz      r0, 611(r6);
/* 8077141C 2C000000 */  cmpwi    r0, 0;
/* 80771420 40820028 */  bne-     UNDEF_80771448;
/* 80771424 38A00001 */  li       r5, 1;
/* 80771428 98A60263 */  stb      r5, 611(r6);
/* 8077142C 38000003 */  li       r0, 3;
/* 80771430 3C808093 */  lis      r4, UNDEF_80933d50@ha;
/* 80771434 9006023C */  stw      r0, 572(r6);
/* 80771438 C0043D50 */  lfs      f0, UNDEF_80933d50@l(r4);
/* 8077143C 90A60240 */  stw      r5, 576(r6);
/* 80771440 D0060250 */  stfs     f0, 592(r6);
/* 80771444 98A60265 */  stb      r5, 613(r6);
UNDEF_80771448:;
/* 80771448 800302D4 */  lwz      r0, 724(r3);
/* 8077144C 38A00001 */  li       r5, 1;
/* 80771450 5400103A */  slwi     r0, r0, 2;
/* 80771454          */  lwz      r4, 0x80(r3);
/* 80771458          */  lwzx     r4, r4, r0;
/* 8077145C 98A40267 */  stb      r5, 615(r4);
/* 80771460 80830074 */  lwz      r4, 116(r3);
/* 80771464 98A30296 */  stb      r5, 662(r3);
/* 80771468 98A4029F */  stb      r5, 671(r4);
/* 8077146C 4E800020 */  blr;
  // clang-format on
);

[[address(0x80771470)]]
void dCharacterChangeSelectBase_c::executeState_PlayerExitWait() ASM_METHOD(
  // clang-format off
/* 80771470 800302D4 */  lwz      r0, 724(r3);
/* 80771474 5400103A */  slwi     r0, r0, 2;
/* 80771478          */  lwz      r4, 0x80(r3);
/* 8077147C          */  lwzx     r4, r4, r0;
/* 80771480 88040263 */  lbz      r0, 611(r4);
/* 80771484 2C000000 */  cmpwi    r0, 0;
/* 80771488 4C820020 */  bnelr-;
/* 8077148C 88040262 */  lbz      r0, 610(r4);
/* 80771490 2C000000 */  cmpwi    r0, 0;
/* 80771494 41820008 */  beq-     UNDEF_8077149c;
/* 80771498 4E800020 */  blr;
UNDEF_8077149c:;
/* 8077149C 85830228 */  lwzu     r12, 552(r3);
/* 807714A0 3C808099 */  lis      r4, UNDEF_80990d98@ha;
/* 807714A4 38840D98 */  addi     r4, r4, UNDEF_80990d98@l;
/* 807714A8 818C0018 */  lwz      r12, 24(r12);
/* 807714AC 7D8903A6 */  mtctr    r12;
/* 807714B0 4E800420 */  bctr;
  // clang-format on
);

[[address(0x807714C0)]]
void dCharacterChangeSelectBase_c::finalizeState_PlayerExitWait() ASM_METHOD(
  // clang-format off
/* 807714C0 800302D8 */  lwz      r0, 728(r3);
/* 807714C4 3CA08093 */  lis      r5, g_CHARACTER_FROM_BASE@ha;
/* 807714C8 80C30280 */  lwz      r6, 640(r3);
/* 807714CC 3C808035 */  lis      r4, mPlayerType__9daPyMng_c@ha;
/* 807714D0 5400103A */  slwi     r0, r0, 2;
/* 807714D4 38E00001 */  li       r7, 1;
/* 807714D8 7CE6012E */  stwx     r7, r6, r0;
/* 807714DC 38A53CC0 */  addi     r5, r5, g_CHARACTER_FROM_BASE@l;
/* 807714E0 38845160 */  addi     r4, r4, mPlayerType__9daPyMng_c@l;
/* 807714E4 38000000 */  li       r0, 0;
/* 807714E8 80C302D4 */  lwz      r6, 724(r3);
/* 807714EC 54C6103A */  slwi     r6, r6, 2;
/* 807714F0          */  lwz      r8, 0x80(r3);
/* 807714F4          */  lwzx     r6, r8, r6;
/* 807714F8 98E60267 */  stb      r7, 615(r6);
/* 807714FC 80E30264 */  lwz      r7, 612(r3);
/* 80771500 88C700BB */  lbz      r6, 187(r7);
/* 80771504 54C6063C */  rlwinm   r6, r6, 0, 24, 30;
/* 80771508 60C60001 */  ori      r6, r6, 1;
/* 8077150C 98C700BB */  stb      r6, 187(r7);
/* 80771510 80C302D8 */  lwz      r6, 728(r3);
/* 80771514 54C6103A */  slwi     r6, r6, 2;
/* 80771518 7CA5302E */  lwzx     r5, r5, r6;
/* 8077151C 7CA4312E */  stwx     r5, r4, r6;
/* 80771520 98030296 */  stb      r0, 662(r3);
/* 80771524 4E800020 */  blr;
  // clang-format on
);
