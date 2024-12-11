// d_a_player.cpp
// NSMBW .text: 0x80126650 - 0x8014A480

#include "d_a_player.h"

#include <dynamic/d_player/d_a_yoshi.h>
#include <dynamic/d_bases/d_s_stage.h>
#include <dynamic/d_a_player_demo_manager.h>
#include <dynamic/d_a_player_manager.h>
#include <dynamic/d_fader.h>
#include <framework/f_base.h>

[[address(0x80138FA0)]]
bool dAcPy_c::setBalloonInDamage();

[[address(0x8013D7B0)]]
void dAcPy_c::checkRest()
{
    if (isItemKinopio()) {
        deleteRequest();
        return;
    }

    if (m0x1554 == 0) {
        setBalloonInDamage();
        return;
    }

    if (isStatus(5)) {
        return;
    }
    onStatus(5);

    bool gameOver = true;

    for (int i = 0; i < PLAYER_COUNT; i++) {
        if (daPyMng_c::mPlayerEntry[i] != 0 &&
            daPyMng_c::mRest[int(daPyMng_c::mPlayerType[i])] != 0) {
            gameOver = false;
            break;
        }
    }

    if (gameOver) {
        dScStage_c::goToSceneAfterLevel(
          +fBaseProfile_e::GAMEOVER, 0, 1, dFader_c::fader_type_e::BOWSER
        );
    } else {
        dScStage_c::goToSceneAfterLevel(
          +fBaseProfile_e::WORLD_MAP, 0, 1, dFader_c::fader_type_e::BOWSER
        );
    }
}

[[address(0x8013DA30)]]
void dAcPy_c::stopOtherDownDemo()
{
    if (isItemKinopio()) {
        return;
    }

    if (m0x1554 == 0) {
        stopOther();
        return;
    }

    daPyDemoMng_c::mspInstance->mOwnedPlayer = mPlayerNo;
    dActor_c::mExecStopReq |= 0xF;

    for (int i = 0; i < PLAYER_COUNT; i++) {
        dAcPy_c* player = daPyMng_c::getPlayer(i);
        if (player != nullptr && !player->isStatus(83) && !player->isItemKinopio()) {
            player->m0x38E &= 0xFD;
        }

        daPlBase_c* yoshi = daPyMng_c::getYoshi(i);
        if (yoshi != nullptr && !yoshi->isStatus(83)) {
            yoshi->m0x38E &= 0xFD;
        }
    }

    dActor_c::mExecStopReq |= 0xD;
}

/**
 * VT+0x28C
 */
[[address(0x801400B0)]]
void dAcPy_c::executeDemoGoal_Run() ASM_METHOD(
  // clang-format off
/* 801400B0 9421FFE0 */  stwu     r1, -32(r1);
/* 801400B4 7C0802A6 */  mflr     r0;
/* 801400B8 90010024 */  stw      r0, 36(r1);
/* 801400BC 93E1001C */  stw      r31, 28(r1);
/* 801400C0 7C7F1B78 */  mr       r31, r3;
/* 801400C4 93C10018 */  stw      r30, 24(r1);
/* 801400C8 880303F4 */  lbz      r0, 1012(r3);
/* 801400CC 7C040774 */  extsb    r4, r0;
/* 801400D0 3804FFFF */  subi     r0, r4, 1;
/* 801400D4 28000001 */  cmplwi   r0, 1;
/* 801400D8 408100BC */  ble-     UNDEF_80140194;
/* 801400DC 2C040000 */  cmpwi    r4, 0;
/* 801400E0 41820028 */  beq-     UNDEF_80140108;
/* 801400E4 2C040003 */  cmpwi    r4, 3;
/* 801400E8 4182016C */  beq-     UNDEF_80140254;
/* 801400EC 2C040004 */  cmpwi    r4, 4;
/* 801400F0 4182022C */  beq-     UNDEF_8014031c;
/* 801400F4 2C040006 */  cmpwi    r4, 6;
/* 801400F8 41820230 */  beq-     UNDEF_80140328;
/* 801400FC 2C040007 */  cmpwi    r4, 7;
/* 80140100 418202C8 */  beq-     UNDEF_801403c8;
/* 80140104 4800031C */  b        UNDEF_80140420;
UNDEF_80140108:;
                         // There's a 50% chance the fourth player will lag behind in walking to the
                         // castle. This fixes it by making it the last player regardless of player
                         // count (as long as it's at least 4).

                         lis      r9, mspInstance__13daPyDemoMng_c@ha;
                         lwz      r9, mspInstance__13daPyDemoMng_c@l(r9);
                         lwz      r9, 0x1C(r9);
                         cmpwi    r9, 4;
                         blt-     UNDEF_80140138;

                         subi     r9, r9, 1;
/* 80140108 80030434 */  lwz      r0, 0x434(r3);
/* 8014010C          */  cmpw     r0, r9;
/* 80140110          */  bne-     UNDEF_80140138;
/* 80140114 4BF72DED */  bl       UNDEF_800b2f00;
/* 80140118 C002A6E4 */  lfs      f0, -22812(r2);
/* 8014011C FC010040 */  fcmpo    cr0, f1, f0;
/* 80140120 40800018 */  bge-     UNDEF_80140138;
/* 80140124 3860003C */  li       r3, 60;
/* 80140128 38000002 */  li       r0, 2;
/* 8014012C 907F145C */  stw      r3, 5212(r31);
/* 80140130 981F03F4 */  stb      r0, 1012(r31);
/* 80140134 48000020 */  b        UNDEF_80140154;
UNDEF_80140138:;
/* 80140138 807F0434 */  lwz      r3, 1076(r31);
/* 8014013C 38000001 */  li       r0, 1;
/* 80140140 981F03F4 */  stb      r0, 1012(r31);
/* 80140144 5460103A */  slwi     r0, r3, 2;
/* 80140148 7C601A14 */  add      r3, r0, r3;
/* 8014014C 3803000A */  addi     r0, r3, 10;
/* 80140150 901F145C */  stw      r0, 5212(r31);
UNDEF_80140154:;
/* 80140154 3BC00000 */  li       r30, 0;
UNDEF_80140158:;
/* 80140158 7FC3F378 */  mr       r3, r30;
/* 8014015C 4BF1F905 */  bl       getYoshi__9daPyMng_cFi;
/* 80140160 2C030000 */  cmpwi    r3, 0;
/* 80140164 41820024 */  beq-     UNDEF_80140188;
/* 80140168 38800065 */  li       r4, 101;
/* 8014016C 4BF16B85 */  bl       isStatus__10daPlBase_cFi;
/* 80140170 2C030000 */  cmpwi    r3, 0;
/* 80140174 41820014 */  beq-     UNDEF_80140188;
/* 80140178 807F145C */  lwz      r3, 5212(r31);
/* 8014017C 3803000E */  addi     r0, r3, 14;
/* 80140180 901F145C */  stw      r0, 5212(r31);
/* 80140184 48000010 */  b        UNDEF_80140194;
UNDEF_80140188:;
/* 80140188 3BDE0001 */  addi     r30, r30, 1;
/* 8014018C 2C1E0004 */  cmpwi    r30, 4;
/* 80140190 4180FFC8 */  blt+     UNDEF_80140158;
UNDEF_80140194:;
/* 80140194 801F145C */  lwz      r0, 5212(r31);
/* 80140198 2C000000 */  cmpwi    r0, 0;
/* 8014019C 40820284 */  bne-     UNDEF_80140420;
/* 801401A0 806DA5F4 */  lwz      r3, -23052(r13);
/* 801401A4 80030010 */  lwz      r0, 16(r3);
/* 801401A8 60000020 */  ori      r0, r0, 32;
/* 801401AC 90030010 */  stw      r0, 16(r3);
/* 801401B0 801F0434 */  lwz      r0, 1076(r31);
/* 801401B4 2C000000 */  cmpwi    r0, 0;
/* 801401B8 40820014 */  bne-     UNDEF_801401cc;
/* 801401BC 806DA5F4 */  lwz      r3, -23052(r13);
/* 801401C0 38800002 */  li       r4, 2;
/* 801401C4 38A00000 */  li       r5, 0;
/* 801401C8 4BF1B3F9 */  bl       setDemoMode__13daPyDemoMng_cFQ213daPyDemoMng_c6Mode_ei;
UNDEF_801401cc:;
/* 801401CC 801F1090 */  lwz      r0, 4240(r31);
/* 801401D0 38800000 */  li       r4, 0;
/* 801401D4 C042A6D8 */  lfs      f2, -22824(r2);
/* 801401D8 3860003C */  li       r3, 60;
/* 801401DC C002A910 */  lfs      f0, -22256(r2);
/* 801401E0 2C000003 */  cmpwi    r0, 3;
/* 801401E4 989F0348 */  stb      r4, 840(r31);
/* 801401E8 C022A914 */  lfs      f1, -22252(r2);
/* 801401EC D05F00E8 */  stfs     f2, 232(r31);
/* 801401F0 D05F00EC */  stfs     f2, 236(r31);
/* 801401F4 D05F00F0 */  stfs     f2, 240(r31);
/* 801401F8 907F145C */  stw      r3, 5212(r31);
/* 801401FC D01F010C */  stfs     f0, 268(r31);
/* 80140200 40820010 */  bne-     UNDEF_80140210;
/* 80140204 C002A6E8 */  lfs      f0, -22808(r2);
/* 80140208 EC200072 */  fmuls    f1, f0, f1;
/* 8014020C 4800001C */  b        UNDEF_80140228;
UNDEF_80140210:;
/* 80140210 881F03F4 */  lbz      r0, 1012(r31);
/* 80140214 2C000002 */  cmpwi    r0, 2;
/* 80140218 40820010 */  bne-     UNDEF_80140228;
/* 8014021C C002A734 */  lfs      f0, -22732(r2);
/* 80140220 D01F010C */  stfs     f0, 268(r31);
/* 80140224 C022A6FC */  lfs      f1, -22788(r2);
UNDEF_80140228:;
/* 80140228 807F2A64 */  lwz      r3, 10852(r31);
/* 8014022C 38800002 */  li       r4, 2;
/* 80140230 C042A798 */  lfs      f2, -22632(r2);
/* 80140234 81830000 */  lwz      r12, 0(r3);
/* 80140238 C062A6D8 */  lfs      f3, -22824(r2);
/* 8014023C 818C005C */  lwz      r12, 92(r12);
/* 80140240 7D8903A6 */  mtctr    r12;
/* 80140244 4E800421 */  bctrl;
/* 80140248 38000003 */  li       r0, 3;
/* 8014024C 981F03F4 */  stb      r0, 1012(r31);
/* 80140250 480001D0 */  b        UNDEF_80140420;
UNDEF_80140254:;
/* 80140254 81830060 */  lwz      r12, 96(r3);
/* 80140258 818C0448 */  lwz      r12, 1096(r12);
/* 8014025C 7D8903A6 */  mtctr    r12;
/* 80140260 4E800421 */  bctrl;
/* 80140264 C03F00AC */  lfs      f1, 172(r31);
/* 80140268 C01F03FC */  lfs      f0, 1020(r31);
/* 8014026C FC010040 */  fcmpo    cr0, f1, f0;
/* 80140270 40810048 */  ble-     UNDEF_801402b8;
/* 80140274 387F00AC */  addi     r3, r31, 172;
/* 80140278 38810008 */  addi     r4, r1, 8;
/* 8014027C 38A00000 */  li       r5, 0;
/* 80140280 38C00001 */  li       r6, 1;
/* 80140284 38E0FFFF */  li       r7, -1;
/* 80140288 4BF35529 */  bl       UNDEF_800757b0;
/* 8014028C 2C030000 */  cmpwi    r3, 0;
/* 80140290 41820020 */  beq-     UNDEF_801402b0;
/* 80140294 C022A704 */  lfs      f1, -22780(r2);
/* 80140298 C0010008 */  lfs      f0, 8(r1);
/* 8014029C C05F00B0 */  lfs      f2, 176(r31);
/* 801402A0 EC01002A */  fadds    f0, f1, f0;
/* 801402A4 FC020040 */  fcmpo    cr0, f2, f0;
/* 801402A8 40800008 */  bge-     UNDEF_801402b0;
/* 801402AC D01F00B0 */  stfs     f0, 176(r31);
UNDEF_801402b0:;
/* 801402B0 C002A918 */  lfs      f0, -22248(r2);
/* 801402B4 D01F00B4 */  stfs     f0, 180(r31);
UNDEF_801402b8:;
/* 801402B8 C022A8A0 */  lfs      f1, -22368(r2);
/* 801402BC 387F00AC */  addi     r3, r31, 172;
/* 801402C0 C01F03FC */  lfs      f0, 1020(r31);
/* 801402C4 C05F010C */  lfs      f2, 268(r31);
/* 801402C8 EC21002A */  fadds    f1, f1, f0;
/* 801402CC 4801F2E5 */  bl       UNDEF_8015f5b0; // chase__4sLibFPfff
/* 801402D0 2C030000 */  cmpwi    r3, 0;
/* 801402D4 4182014C */  beq-     UNDEF_80140420;
/* 801402D8 807F2A64 */  lwz      r3, 10852(r31);
/* 801402DC 3CA08037 */  lis      r5, m_hio__11dPyMdlMng_c@ha;
/* 801402E0 38A510A0 */  addi     r5, r5, m_hio__11dPyMdlMng_c@l;
/* 801402E4 C062A6D8 */  lfs      f3, -22824(r2);
/* 801402E8 81830000 */  lwz      r12, 0(r3);
/* 801402EC 38800000 */  li       r4, 0;
/* 801402F0 C025002C */  lfs      f1, 44(r5);
/* 801402F4 818C005C */  lwz      r12, 92(r12);
/* 801402F8 C0450030 */  lfs      f2, 48(r5);
/* 801402FC 7D8903A6 */  mtctr    r12;
/* 80140300 4E800421 */  bctrl;
/* 80140304 38000004 */  li       r0, 4;
/* 80140308 981F03F4 */  stb      r0, 1012(r31);
/* 8014030C 7FE3FB78 */  mr       r3, r31;
/* 80140310 3880006E */  li       r4, 110;
/* 80140314 4BF1695D */  bl       onStatus__10daPlBase_cFi;
/* 80140318 48000108 */  b        UNDEF_80140420;
UNDEF_8014031c:;
/* 8014031C C002A918 */  lfs      f0, -22248(r2);
/* 80140320 D00300B4 */  stfs     f0, 180(r3);
/* 80140324 480000FC */  b        UNDEF_80140420;
UNDEF_80140328:;
/* 80140328 4BF0C2F9 */  bl       UNDEF_8004c620; // setNormalJumpGravity__10daPlBase_cFv
/* 8014032C C05F00EC */  lfs      f2, 236(r31);
/* 80140330 C03F0114 */  lfs      f1, 276(r31);
/* 80140334 C00287E4 */  lfs      f0, -30748(r2);
/* 80140338 EC22082A */  fadds    f1, f2, f1;
/* 8014033C D03F00EC */  stfs     f1, 236(r31);
/* 80140340 FC010040 */  fcmpo    cr0, f1, f0;
/* 80140344 40800008 */  bge-     UNDEF_8014034c;
/* 80140348 D01F00EC */  stfs     f0, 236(r31);
UNDEF_8014034c:;
/* 8014034C C07F00B0 */  lfs      f3, 176(r31);
/* 80140350 C05F00EC */  lfs      f2, 236(r31);
/* 80140354 801F10D4 */  lwz      r0, 4308(r31);
/* 80140358 EC43102A */  fadds    f2, f3, f2;
/* 8014035C C03F00AC */  lfs      f1, 172(r31);
/* 80140360 C01F010C */  lfs      f0, 268(r31);
/* 80140364 540007FF */  clrlwi.  r0, r0, 31;
/* 80140368 D05F00B0 */  stfs     f2, 176(r31);
/* 8014036C EC01002A */  fadds    f0, f1, f0;
/* 80140370 D01F00AC */  stfs     f0, 172(r31);
/* 80140374 418200AC */  beq-     UNDEF_80140420;
/* 80140378 C062A6D8 */  lfs      f3, -22824(r2);
/* 8014037C 3CA08037 */  lis      r5, UNDEF_803710a0@ha;
/* 80140380 D07F010C */  stfs     f3, 268(r31);
/* 80140384 38A510A0 */  addi     r5, r5, UNDEF_803710a0@l;
/* 80140388 807F2A64 */  lwz      r3, 10852(r31);
/* 8014038C 38800007 */  li       r4, 7;
/* 80140390 C0250080 */  lfs      f1, 128(r5);
/* 80140394 81830000 */  lwz      r12, 0(r3);
/* 80140398 C0450084 */  lfs      f2, 132(r5);
/* 8014039C 818C005C */  lwz      r12, 92(r12);
/* 801403A0 7D8903A6 */  mtctr    r12;
/* 801403A4 4E800421 */  bctrl;
/* 801403A8 819F0060 */  lwz      r12, 96(r31);
/* 801403AC 7FE3FB78 */  mr       r3, r31;
/* 801403B0 818C0414 */  lwz      r12, 1044(r12);
/* 801403B4 7D8903A6 */  mtctr    r12;
/* 801403B8 4E800421 */  bctrl;
/* 801403BC 38000007 */  li       r0, 7;
/* 801403C0 981F03F4 */  stb      r0, 1012(r31);
/* 801403C4 4800005C */  b        UNDEF_80140420;
UNDEF_801403c8:;
/* 801403C8 80632A64 */  lwz      r3, 10852(r3);
/* 801403CC 38630028 */  addi     r3, r3, 40;
/* 801403D0 48028D91 */  bl       UNDEF_80169160; // isStop__Q23m3d6fanm_cCFv
/* 801403D4 2C030000 */  cmpwi    r3, 0;
/* 801403D8 41820048 */  beq-     UNDEF_80140420;
/* 801403DC 807F2A64 */  lwz      r3, 10852(r31);
/* 801403E0 3CA08037 */  lis      r5, m_hio__11dPyMdlMng_c@ha;
/* 801403E4 38A510A0 */  addi     r5, r5, m_hio__11dPyMdlMng_c@l;
/* 801403E8 C062A6D8 */  lfs      f3, -22824(r2);
/* 801403EC 81830000 */  lwz      r12, 0(r3);
/* 801403F0 38800000 */  li       r4, 0;
/* 801403F4 C025002C */  lfs      f1, 44(r5);
/* 801403F8 818C005C */  lwz      r12, 92(r12);
/* 801403FC C0450030 */  lfs      f2, 48(r5);
/* 80140400 7D8903A6 */  mtctr    r12;
/* 80140404 4E800421 */  bctrl;
/* 80140408 807F0434 */  lwz      r3, 1076(r31);
/* 8014040C 38000001 */  li       r0, 1;
/* 80140410 981F03F4 */  stb      r0, 1012(r31);
/* 80140414 5460103A */  slwi     r0, r3, 2;
/* 80140418 7C001A14 */  add      r0, r0, r3;
/* 8014041C 901F145C */  stw      r0, 5212(r31);
UNDEF_80140420:;
/* 80140420 80010024 */  lwz      r0, 36(r1);
/* 80140424 83E1001C */  lwz      r31, 28(r1);
/* 80140428 83C10018 */  lwz      r30, 24(r1);
/* 8014042C 7C0803A6 */  mtlr     r0;
/* 80140430 38210020 */  addi     r1, r1, 32;
/* 80140434 4E800020 */  blr;
  // clang-format on
);

/**
 * VT+0x08
 * do method for the create operation.
 *
 * @return A PACK_RESULT_e value.
 */
[[address(0x80144EA0)]]
int dAcPy_c::create() ASM_METHOD(
  // clang-format off
/* 80144EA0 9421FFF0 */  stwu     r1, -16(r1);
/* 80144EA4 7C0802A6 */  mflr     r0;
/* 80144EA8 38C00000 */  li       r6, 0;
/* 80144EAC 90010014 */  stw      r0, 20(r1);
/* 80144EB0 93E1000C */  stw      r31, 12(r1);
/* 80144EB4 7C7F1B78 */  mr       r31, r3;
/* 80144EB8 80031090 */  lwz      r0, 4240(r3);
/* 80144EBC 8883038D */  lbz      r4, 909(r3);
/* 80144EC0 38632A60 */  addi     r3, r3, 10848;
/* 80144EC4 5405063E */  clrlwi   r5, r0, 24;
/* 80144EC8 4BF92019 */  bl       UNDEF_800d6ee0;
/* 80144ECC 809F1090 */  lwz      r4, 4240(r31);
/* 80144ED0 7FE3FB78 */  mr       r3, r31;
/* 80144ED4 909F14E0 */  stw      r4, 5344(r31);
/* 80144ED8 38A00001 */  li       r5, 1;
/* 80144EDC 909F14DC */  stw      r4, 5340(r31);
/* 80144EE0 819F0060 */  lwz      r12, 96(r31);
/* 80144EE4 818C00E4 */  lwz      r12, 228(r12);
/* 80144EE8 7D8903A6 */  mtctr    r12;
/* 80144EEC 4E800421 */  bctrl;
/* 80144EF0 801F0004 */  lwz      r0, 4(r31);
/* 80144EF4 7FE3FB78 */  mr       r3, r31;
/* 80144EF8 540447FE */  extrwi   r4, r0, 1, 7;
/* 80144EFC 989F0348 */  stb      r4, 840(r31);
/* 80144F00 819F0060 */  lwz      r12, 96(r31);
/* 80144F04 818C0444 */  lwz      r12, 1092(r12);
/* 80144F08 7D8903A6 */  mtctr    r12;
/* 80144F0C 4E800421 */  bctrl;
/* 80144F10 C022A6D8 */  lfs      f1, -22824(r2);
/* 80144F14 C00287E4 */  lfs      f0, -30748(r2);
/* 80144F18 B07F0102 */  sth      r3, 258(r31);
/* 80144F1C 7FE3FB78 */  mr       r3, r31;
/* 80144F20 D03F00F4 */  stfs     f1, 244(r31);
/* 80144F24 D03F00F8 */  stfs     f1, 248(r31);
/* 80144F28 D03F00FC */  stfs     f1, 252(r31);
/* 80144F2C D01F0118 */  stfs     f0, 280(r31);
/* 80144F30 819F0060 */  lwz      r12, 96(r31);
/* 80144F34 818C03C4 */  lwz      r12, 964(r12);
/* 80144F38 7D8903A6 */  mtctr    r12;
/* 80144F3C 4E800421 */  bctrl;
/* 80144F40 C0230000 */  lfs      f1, 0(r3);
/* 80144F44 7FE3FB78 */  mr       r3, r31;
/* 80144F48 C002A704 */  lfs      f0, -22780(r2);
/* 80144F4C 38800000 */  li       r4, 0;
/* 80144F50 D03F0114 */  stfs     f1, 276(r31);
/* 80144F54 D01F00DC */  stfs     f0, 220(r31);
/* 80144F58 D01F00E0 */  stfs     f0, 224(r31);
/* 80144F5C D01F00E4 */  stfs     f0, 228(r31);
/* 80144F60 D01F1544 */  stfs     f0, 5444(r31);
/* 80144F64 4BF11CCD */  bl       UNDEF_80056c30;
/* 80144F68 38000000 */  li       r0, 0;
/* 80144F6C 901F2A78 */  stw      r0, 10872(r31);
/* 80144F70 7FE3FB78 */  mr       r3, r31;
/* 80144F74 901F1008 */  stw      r0, 4104(r31);
/* 80144F78 901F100C */  stw      r0, 4108(r31);
/* 80144F7C 819F0060 */  lwz      r12, 96(r31);
/* 80144F80 818C00E0 */  lwz      r12, 224(r12);
/* 80144F84 7D8903A6 */  mtctr    r12;
/* 80144F88 4E800421 */  bctrl;
/* 80144F8C 2C030000 */  cmpwi    r3, 0;
/* 80144F90 41820014 */  beq-     UNDEF_80144fa4;
/* 80144F94 7FE3FB78 */  mr       r3, r31;
/* 80144F98 38800001 */  li       r4, 1;
/* 80144F9C 480023F5 */  bl       UNDEF_80147390;
/* 80144FA0 48000010 */  b        UNDEF_80144fb0;
UNDEF_80144fa4:;
/* 80144FA4 7FE3FB78 */  mr       r3, r31;
/* 80144FA8 38800000 */  li       r4, 0;
/* 80144FAC 480023E5 */  bl       UNDEF_80147390;
UNDEF_80144fb0:;
/* 80144FB0 C05F00AC */  lfs      f2, 172(r31);
/* 80144FB4 7FE4FB78 */  mr       r4, r31;
/* 80144FB8 C03F00B0 */  lfs      f1, 176(r31);
/* 80144FBC 387F2BA8 */  addi     r3, r31, 11176;
/* 80144FC0 C01F00B4 */  lfs      f0, 180(r31);
/* 80144FC4 D05F152C */  stfs     f2, 5420(r31);
/* 80144FC8 D03F1530 */  stfs     f1, 5424(r31);
/* 80144FCC D01F1534 */  stfs     f0, 5428(r31);
/* 80144FD0 4BF933A1 */  bl       UNDEF_800d8370;
/* 80144FD4 7FE3FB78 */  mr       r3, r31;
/* 80144FD8 4BFFE629 */  bl       UNDEF_80143600;
/* 80144FDC 7FE3FB78 */  mr       r3, r31;
/* 80144FE0 4BFFE641 */  bl       UNDEF_80143620;
/* 80144FE4 819F0060 */  lwz      r12, 96(r31);
/* 80144FE8 7FE3FB78 */  mr       r3, r31;
/* 80144FEC 801F0004 */  lwz      r0, 4(r31);
/* 80144FF0 818C0270 */  lwz      r12, 624(r12);
/* 80144FF4 5404863E */  extrwi   r4, r0, 8, 8;
/* 80144FF8 7D8903A6 */  mtctr    r12;
/* 80144FFC 4E800421 */  bctrl;
/* 80145000 7FE3FB78 */  mr       r3, r31;
/* 80145004 4800078D */  bl       UNDEF_80145790;
/* 80145008 7FE4FB78 */  mr       r4, r31;
/* 8014500C 387F14FC */  addi     r3, r31, 5372;
/* 80145010 38A00001 */  li       r5, 1;
/* 80145014 4BF8C5DD */  bl       UNDEF_800d15f0;
/* 80145018 800DAB80 */  lwz      r0, -21632(r13);
/* 8014501C 2C000000 */  cmpwi    r0, 0;
/* 80145020 408200A8 */  bne-     UNDEF_801450c8;
/* 80145024 806DAB28 */  lwz      r3, -21720(r13);
/* 80145028 8803120D */  lbz      r0, 4621(r3);
/* 8014502C 28000028 */  cmplwi   r0, 40;
/* 80145030 41820098 */  beq-     UNDEF_801450c8;
/* 80145034 881F038D */  lbz      r0, 909(r31);
/* 80145038 3C808035 */  lis      r4, mPlayerType__9daPyMng_c@ha;
/* 8014503C 3C608035 */  lis      r3, mCreateItem__9daPyMng_c@ha;
/* 80145040 7C050774 */  extsb    r5, r0;
/* 80145044 38845160 */  addi     r4, r4, mPlayerType__9daPyMng_c@l;
/* 80145048 54A0103A */  slwi     r0, r5, 2;
/* 8014504C 38635180 */  addi     r3, r3, mCreateItem__9daPyMng_c@l;
/* 80145050 7C04002E */  lwzx     r0, r4, r0;
/* 80145054 5400103A */  slwi     r0, r0, 2;
/* 80145058 7C03002E */  lwzx     r0, r3, r0;
/* 8014505C 540007FF */  clrlwi.  r0, r0, 31;
/* 80145060 41820024 */  beq-     UNDEF_80145084;
/* 80145064 819F0060 */  lwz      r12, 96(r31);
/* 80145068 7FE3FB78 */  mr       r3, r31;
/* 8014506C 38800002 */  li       r4, 2;
/* 80145070 38A00294 */  li       r5, 660;
/* 80145074 818C03D8 */  lwz      r12, 984(r12);
/* 80145078 7D8903A6 */  mtctr    r12;
/* 8014507C 4E800421 */  bctrl;
/* 80145080 48000048 */  b        UNDEF_801450c8;
UNDEF_80145084:;
/* 80145084          */  slwi     r3, r5, 1;
/* 80145088          */  addis    r3, r3, m_star_time__9daPyMng_c@ha;
/* 8014508C          */  lha      r5, m_star_time__9daPyMng_c@l(r3);
/* 80145090 2C050000 */  cmpwi    r5, 0;
/* 80145094 4182001C */  beq-     UNDEF_801450b0;
/* 80145098 819F0060 */  lwz      r12, 96(r31);
/* 8014509C 7FE3FB78 */  mr       r3, r31;
/* 801450A0 38800002 */  li       r4, 2;
/* 801450A4 818C03D8 */  lwz      r12, 984(r12);
/* 801450A8 7D8903A6 */  mtctr    r12;
/* 801450AC 4E800421 */  bctrl;
UNDEF_801450b0:;
/* 801450B0 881F038D */  lbz      r0, 909(r31);
/* 801450BC          */  slwi     r3, r0, 1;
/* 801450B4          */  addis    r3, r3, m_star_count__9daPyMng_c@ha;
/* 801450C0          */  lha      r0, m_star_count__9daPyMng_c@l(r3);
/* 801450C4 981F1081 */  stb      r0, 4225(r31);
UNDEF_801450c8:;
/* 801450C8 819F0060 */  lwz      r12, 96(r31);
/* 801450CC 7FE3FB78 */  mr       r3, r31;
/* 801450D0 818C00E0 */  lwz      r12, 224(r12);
/* 801450D4 7D8903A6 */  mtctr    r12;
/* 801450D8 4E800421 */  bctrl;
/* 801450DC 2C030000 */  cmpwi    r3, 0;
/* 801450E0 40820020 */  bne-     UNDEF_80145100;
/* 801450E4 800DAB64 */  lwz      r0, -21660(r13);
/* 801450E8 2C000000 */  cmpwi    r0, 0;
/* 801450EC 40820014 */  bne-     UNDEF_80145100;
/* 801450F0 887F038D */  lbz      r3, 909(r31);
/* 801450F4 7C630774 */  extsb    r3, r3;
/* 801450F8 4BF24439 */  bl       UNDEF_80069530;
/* 801450FC 907F0E44 */  stw      r3, 3652(r31);
UNDEF_80145100:;
                         // Proper offset for character sounds
/* 80145100 801F14D4 */  lwz      r0, 0x14D4(r31); // mPlayerType
/* 80145148          */  stw      r0, 0xE98(r31); // mSndObjctPly.mPlayerSndIndex

/* 8014514C 7FE3FB78 */  mr       r3, r31;
/* 80145150 4BF08451 */  bl       UNDEF_8004d5a0;
/* 80145154 7FE3FB78 */  mr       r3, r31;
/* 80145158 4BF018F9 */  bl       UNDEF_80046a50;
/* 8014515C 881F038D */  lbz      r0, 909(r31);
/* 80145160 38600001 */  li       r3, 1;
/* 80145164 7C000774 */  extsb    r0, r0;
/* 80145168 901F0EA4 */  stw      r0, 3748(r31);
/* 8014516C 83E1000C */  lwz      r31, 12(r1);
/* 80145170 80010014 */  lwz      r0, 20(r1);
/* 80145174 7C0803A6 */  mtlr     r0;
/* 80145178 38210010 */  addi     r1, r1, 16;
/* 8014517C 4E800020 */  blr;
  // clang-format on
)