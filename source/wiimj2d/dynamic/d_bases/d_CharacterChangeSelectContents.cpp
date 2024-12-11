// d_CharacterChangeSelectContents.cpp
// NSMBW: 0x80772A50 - 0x80773F30

#include "d_CharacterChangeSelectContents.h"

#include <dynamic/d_a_player_manager.h>

[[address(0x80772A50)]]
dCharacterChangeSelectContents_c* dCharacterChangeSelectContents_c_classInit()
{
    return new dCharacterChangeSelectContents_c();
}

[[address(0x80772A80)]]
dCharacterChangeSelectContents_c::dCharacterChangeSelectContents_c();

[[address(0x80772E30)]]
bool dCharacterChangeSelectContents_c::createLayout()
{
    bool ret = mLayout.hasAccessor();
    if (!ret) {
        return ret;
    }

    using StringArray = const char*[];
    using IntArray = const int[];

    mLayout.build("characterChangeSelectContents_05.brlyt", nullptr);

    mLayout.AnimeResRegister(StringArray{"characterChangeSelectContents_05_hitButton.brlan"}, 1);

    mLayout.GroupRegister(StringArray{"A00_Shine"}, IntArray{0}, 1);

    mpRootPane = mLayout.getRootPane();

    mLayout.NPaneRegister(
      StringArray{
        "N_cSelectCon_00",
        "N_cSelectCon_01",
      },
      mpaSelectConPane, 2
    );

    mLayout.PPaneRegister(
      StringArray{
        "PbuttonShadow_00",
        "PbuttonShadow_01",
        "P_lui_00",
        "P_lui_01",
        "P_kinoB_00",
        "P_kinoB_01",
        "P_kinoY_00",
        "P_kinoY_01",
      },
      mpaPictures, 8
    );
    mLayout.TPaneRegister(
      StringArray{
        "T_zanki_01",
        "T_zanki_00",
        "T_kakeru_00",
        "T_kakeru_01",
      },
      mpaTextBoxes, 4
    );

    // Register the Mario panes as well
    mLayout.PPaneRegister(
      StringArray{
        "P_mar_00",
        "P_mar_01",
      },
      mpaMarioPictures, 2
    );

    return ret;
}

void dCharacterChangeSelectContents_c::setMarioIconVisible(u32 param_2) ASM_METHOD(
  // clang-format off
                         // Based on 0x807730A0
                         stwu     r1, -16(r1);
                         mflr     r0;
                         li       r6, 0;
                         stw      r0, 20(r1);
                         stw      r31, 12(r1);
                         mr       r31, r4;
                         slwi     r0, r31, 2;
                         lis      r4, UNDEF_8093f524@ha;
                         stw      r30, 8(r1);
                         add      r5, r3, r0;
                         mr       r30, r3;
                         addi     r4, r4, UNDEF_8093f524@l;
                         lwz      r5, 628(r5);
                         addi     r3, r3, 0x2A4; // Mario life count
                         bl       UNDEF_800b3b60;
                         // addi     r0, r31, 0;
                         slwi     r0, r31, 2;
                         add      r3, r30, r0;
                         lwz      r3, 0x2B8(r3);
                         lbz      r0, 187(r3);
                         rlwinm   r0, r0, 0, 24, 30;
                         ori      r0, r0, 1;
                         stb      r0, 187(r3);
                         lwz      r31, 12(r1);
                         lwz      r30, 8(r1);
                         lwz      r0, 20(r1);
                         mtlr     r0;
                         addi     r1, r1, 16;
                         blr;
  // clang-format on
);

[[address(0x80773220)]]
void dCharacterChangeSelectContents_c::UNDEF_80773220() ASM_METHOD(
  // clang-format off
/* 80773220 9421FFF0 */  stwu     r1, -16(r1);
/* 80773224 7C0802A6 */  mflr     r0;
/* 80773228 2C050007 */  cmpwi    r5, 7;
/* 8077322C 90010014 */  stw      r0, 20(r1);
/* 80773230 93E1000C */  stw      r31, 12(r1);
/* 80773234 7CBF2B78 */  mr       r31, r5;
/* 80773238 7FE6FB78 */  mr       r6, r31;
/* 8077323C 93C10008 */  stw      r30, 8(r1);
/* 80773240 7C7E1B78 */  mr       r30, r3;
/* 80773244 41810194 */  bgt-     UNDEF_807733d8;
/* 80773248 21450007 */  subfic   r10, r5, 7;
/* 8077324C 396A0002 */  addi     r11, r10, 2;
/* 80773250 55600FFE */  srwi     r0, r11, 31;
/* 80773254 7C005A14 */  add      r0, r0, r11;
/* 80773258 7C000E70 */  srawi    r0, r0, 1;
/* 8077325C 2C000008 */  cmpwi    r0, 8;
/* 80773260 40810144 */  ble-     UNDEF_807733a4;
/* 80773264 2C050008 */  cmpwi    r5, 8;
/* 80773268 38E00000 */  li       r7, 0;
/* 8077326C 39000000 */  li       r8, 0;
/* 80773270 39200000 */  li       r9, 0;
/* 80773274 38000000 */  li       r0, 0;
/* 80773278 40800008 */  bge-     UNDEF_80773280;
/* 8077327C 38000001 */  li       r0, 1;
UNDEF_80773280:;
/* 80773280 2C000000 */  cmpwi    r0, 0;
/* 80773284 41820014 */  beq-     UNDEF_80773298;
/* 80773288 3C058000 */  addis    r0, r5, 0x8000;
/* 8077328C 28000000 */  cmplwi   r0, 0;
/* 80773290 41820008 */  beq-     UNDEF_80773298;
/* 80773294 39200001 */  li       r9, 1;
UNDEF_80773298:;
/* 80773298 2C090000 */  cmpwi    r9, 0;
/* 8077329C 4182002C */  beq-     UNDEF_807732c8;
/* 807732A0 7C0500D0 */  neg      r0, r5;
/* 807732A4 39200001 */  li       r9, 1;
/* 807732A8 54000001 */  clrrwi.  r0, r0, 31;
/* 807732AC 40820010 */  bne-     UNDEF_807732bc;
/* 807732B0 55400001 */  clrrwi.  r0, r10, 31;
/* 807732B4 41820008 */  beq-     UNDEF_807732bc;
/* 807732B8 39200000 */  li       r9, 0;
UNDEF_807732bc:;
/* 807732BC 2C090000 */  cmpwi    r9, 0;
/* 807732C0 41820008 */  beq-     UNDEF_807732c8;
/* 807732C4 39000001 */  li       r8, 1;
UNDEF_807732c8:;
/* 807732C8 2C080000 */  cmpwi    r8, 0;
/* 807732CC 41820028 */  beq-     UNDEF_807732f4;
/* 807732D0 55400001 */  clrrwi.  r0, r10, 31;
/* 807732D4 39000001 */  li       r8, 1;
/* 807732D8 40820010 */  bne-     UNDEF_807732e8;
/* 807732DC 55600001 */  clrrwi.  r0, r11, 31;
/* 807732E0 41820008 */  beq-     UNDEF_807732e8;
/* 807732E4 39000000 */  li       r8, 0;
UNDEF_807732e8:;
/* 807732E8 2C080000 */  cmpwi    r8, 0;
/* 807732EC 41820008 */  beq-     UNDEF_807732f4;
/* 807732F0 38E00001 */  li       r7, 1;
UNDEF_807732f4:;
/* 807732F4 2C070000 */  cmpwi    r7, 0;
/* 807732F8 418200AC */  beq-     UNDEF_807733a4;
/* 807732FC 20050007 */  subfic   r0, r5, 7;
/* 80773300 54A7103A */  slwi     r7, r5, 2;
/* 80773304 5400E13E */  srwi     r0, r0, 4;
/* 80773308 7D033A14 */  add      r8, r3, r7;
/* 8077330C 7C0903A6 */  mtctr    r0;
/* 80773310 2C05FFF7 */  cmpwi    r5, -9;
/* 80773314 41810090 */  bgt-     UNDEF_807733a4;
UNDEF_80773318:;
/* 80773318 80E80254 */  lwz      r7, 596(r8);
/* 8077331C 38C60010 */  addi     r6, r6, 16;
/* 80773320 880700BB */  lbz      r0, 187(r7);
/* 80773324 5400063C */  rlwinm   r0, r0, 0, 24, 30;
/* 80773328 980700BB */  stb      r0, 187(r7);
/* 8077332C 80E8025C */  lwz      r7, 604(r8);
/* 80773330 880700BB */  lbz      r0, 187(r7);
/* 80773334 5400063C */  rlwinm   r0, r0, 0, 24, 30;
/* 80773338 980700BB */  stb      r0, 187(r7);
/* 8077333C 80E80264 */  lwz      r7, 612(r8);
/* 80773340 880700BB */  lbz      r0, 187(r7);
/* 80773344 5400063C */  rlwinm   r0, r0, 0, 24, 30;
/* 80773348 980700BB */  stb      r0, 187(r7);
/* 8077334C 80E8026C */  lwz      r7, 620(r8);
/* 80773350 880700BB */  lbz      r0, 187(r7);
/* 80773354 5400063C */  rlwinm   r0, r0, 0, 24, 30;
/* 80773358 980700BB */  stb      r0, 187(r7);
/* 8077335C 80E80274 */  lwz      r7, 628(r8);
/* 80773360 880700BB */  lbz      r0, 187(r7);
/* 80773364 5400063C */  rlwinm   r0, r0, 0, 24, 30;
/* 80773368 980700BB */  stb      r0, 187(r7);
/* 8077336C 80E8027C */  lwz      r7, 636(r8);
/* 80773370 880700BB */  lbz      r0, 187(r7);
/* 80773374 5400063C */  rlwinm   r0, r0, 0, 24, 30;
/* 80773378 980700BB */  stb      r0, 187(r7);
/* 8077337C 80E80284 */  lwz      r7, 644(r8);
/* 80773380 880700BB */  lbz      r0, 187(r7);
/* 80773384 5400063C */  rlwinm   r0, r0, 0, 24, 30;
/* 80773388 980700BB */  stb      r0, 187(r7);
/* 8077338C 80E8028C */  lwz      r7, 652(r8);
/* 80773390 39080040 */  addi     r8, r8, 64;
/* 80773394 880700BB */  lbz      r0, 187(r7);
/* 80773398 5400063C */  rlwinm   r0, r0, 0, 24, 30;
/* 8077339C 980700BB */  stb      r0, 187(r7);
/* 807733A0 4200FF78 */  bdnz+    UNDEF_80773318;
UNDEF_807733a4:;
/* 807733A4 20060009 */  subfic   r0, r6, 9;
/* 807733A8 54C7103A */  slwi     r10, r6, 2;
/* 807733AC 5400F87E */  srwi     r0, r0, 1;
/* 807733B0 7CE33A14 */  add      r7, r3, r10;
/* 807733B4 7C0903A6 */  mtctr    r0;
/* 807733B8 2C060007 */  cmpwi    r6, 7;
/* 807733BC 4181001C */  bgt-     UNDEF_807733d8;
UNDEF_807733c0:;
/* 807733C0 80C70254 */  lwz      r6, 0x254(r7);
/* 807733C4 38E70008 */  addi     r7, r7, 8;
/* 807733C8 880600BB */  lbz      r0, 187(r6);
/* 807733CC 5400063C */  rlwinm   r0, r0, 0, 24, 30;
/* 807733D0 980600BB */  stb      r0, 187(r6);
/* 807733D4 4200FFEC */  bdnz+    UNDEF_807733c0;

                         // Hide additional pictures (for Mario)
                         add      r7, r3, r10;
                         lwz      r7, 0x2B8(r7);
                         lbz      r0, 187(r7);
                         rlwinm   r0, r0, 0, 24, 30;
                         stb      r0, 187(r7);

UNDEF_807733d8:;
/* 807733D8 2C050004 */  cmpwi    r5, 4;
/* 807733DC 7FE6FB78 */  mr       r6, r31;
/* 807733E0 40800194 */  bge-     UNDEF_80773574;
/* 807733E4 21450004 */  subfic   r10, r5, 4;
/* 807733E8 396A0001 */  addi     r11, r10, 1;
/* 807733EC 55600FFE */  srwi     r0, r11, 31;
/* 807733F0 7C005A14 */  add      r0, r0, r11;
/* 807733F4 7C000E70 */  srawi    r0, r0, 1;
/* 807733F8 2C000008 */  cmpwi    r0, 8;
/* 807733FC 40810144 */  ble-     UNDEF_80773540;
/* 80773400 2C050005 */  cmpwi    r5, 5;
/* 80773404 38E00000 */  li       r7, 0;
/* 80773408 39000000 */  li       r8, 0;
/* 8077340C 39200000 */  li       r9, 0;
/* 80773410 38000000 */  li       r0, 0;
/* 80773414 40800008 */  bge-     UNDEF_8077341c;
/* 80773418 38000001 */  li       r0, 1;
UNDEF_8077341c:;
/* 8077341C 2C000000 */  cmpwi    r0, 0;
/* 80773420 41820014 */  beq-     UNDEF_80773434;
/* 80773424 3C058000 */  addis    r0, r5, 0x8000;
/* 80773428 28000000 */  cmplwi   r0, 0;
/* 8077342C 41820008 */  beq-     UNDEF_80773434;
/* 80773430 39200001 */  li       r9, 1;
UNDEF_80773434:;
/* 80773434 2C090000 */  cmpwi    r9, 0;
/* 80773438 4182002C */  beq-     UNDEF_80773464;
/* 8077343C 7C0500D0 */  neg      r0, r5;
/* 80773440 39200001 */  li       r9, 1;
/* 80773444 54000001 */  clrrwi.  r0, r0, 31;
/* 80773448 40820010 */  bne-     UNDEF_80773458;
/* 8077344C 55400001 */  clrrwi.  r0, r10, 31;
/* 80773450 41820008 */  beq-     UNDEF_80773458;
/* 80773454 39200000 */  li       r9, 0;
UNDEF_80773458:;
/* 80773458 2C090000 */  cmpwi    r9, 0;
/* 8077345C 41820008 */  beq-     UNDEF_80773464;
/* 80773460 39000001 */  li       r8, 1;
UNDEF_80773464:;
/* 80773464 2C080000 */  cmpwi    r8, 0;
/* 80773468 41820028 */  beq-     UNDEF_80773490;
/* 8077346C 55400001 */  clrrwi.  r0, r10, 31;
/* 80773470 39000001 */  li       r8, 1;
/* 80773474 40820010 */  bne-     UNDEF_80773484;
/* 80773478 55600001 */  clrrwi.  r0, r11, 31;
/* 8077347C 41820008 */  beq-     UNDEF_80773484;
/* 80773480 39000000 */  li       r8, 0;
UNDEF_80773484:;
/* 80773484 2C080000 */  cmpwi    r8, 0;
/* 80773488 41820008 */  beq-     UNDEF_80773490;
/* 8077348C 38E00001 */  li       r7, 1;
UNDEF_80773490:;
/* 80773490 2C070000 */  cmpwi    r7, 0;
/* 80773494 418200AC */  beq-     UNDEF_80773540;
/* 80773498 20050003 */  subfic   r0, r5, 3;
/* 8077349C 54A7103A */  slwi     r7, r5, 2;
/* 807734A0 5400E13E */  srwi     r0, r0, 4;
/* 807734A4 7D033A14 */  add      r8, r3, r7;
/* 807734A8 7C0903A6 */  mtctr    r0;
/* 807734AC 2C05FFF4 */  cmpwi    r5, -12;
/* 807734B0 40800090 */  bge-     UNDEF_80773540;
UNDEF_807734b4:;
/* 807734B4 80E80274 */  lwz      r7, 628(r8);
/* 807734B8 38C60010 */  addi     r6, r6, 16;
/* 807734BC 880700BB */  lbz      r0, 187(r7);
/* 807734C0 5400063C */  rlwinm   r0, r0, 0, 24, 30;
/* 807734C4 980700BB */  stb      r0, 187(r7);
/* 807734C8 80E8027C */  lwz      r7, 636(r8);
/* 807734CC 880700BB */  lbz      r0, 187(r7);
/* 807734D0 5400063C */  rlwinm   r0, r0, 0, 24, 30;
/* 807734D4 980700BB */  stb      r0, 187(r7);
/* 807734D8 80E80284 */  lwz      r7, 644(r8);
/* 807734DC 880700BB */  lbz      r0, 187(r7);
/* 807734E0 5400063C */  rlwinm   r0, r0, 0, 24, 30;
/* 807734E4 980700BB */  stb      r0, 187(r7);
/* 807734E8 80E8028C */  lwz      r7, 652(r8);
/* 807734EC 880700BB */  lbz      r0, 187(r7);
/* 807734F0 5400063C */  rlwinm   r0, r0, 0, 24, 30;
/* 807734F4 980700BB */  stb      r0, 187(r7);
/* 807734F8 80E80294 */  lwz      r7, 660(r8);
/* 807734FC 880700BB */  lbz      r0, 187(r7);
/* 80773500 5400063C */  rlwinm   r0, r0, 0, 24, 30;
/* 80773504 980700BB */  stb      r0, 187(r7);
/* 80773508 80E8029C */  lwz      r7, 668(r8);
/* 8077350C 880700BB */  lbz      r0, 187(r7);
/* 80773510 5400063C */  rlwinm   r0, r0, 0, 24, 30;
/* 80773514 980700BB */  stb      r0, 187(r7);
/* 80773518 80E802A4 */  lwz      r7, 676(r8);
/* 8077351C 880700BB */  lbz      r0, 187(r7);
/* 80773520 5400063C */  rlwinm   r0, r0, 0, 24, 30;
/* 80773524 980700BB */  stb      r0, 187(r7);
/* 80773528 80E802AC */  lwz      r7, 684(r8);
/* 8077352C 39080040 */  addi     r8, r8, 64;
/* 80773530 880700BB */  lbz      r0, 187(r7);
/* 80773534 5400063C */  rlwinm   r0, r0, 0, 24, 30;
/* 80773538 980700BB */  stb      r0, 187(r7);
/* 8077353C 4200FF78 */  bdnz+    UNDEF_807734b4;
UNDEF_80773540:;
/* 80773540 20060005 */  subfic   r0, r6, 5;
/* 80773544 54C7103A */  slwi     r7, r6, 2;
/* 80773548 5400F87E */  srwi     r0, r0, 1;
/* 8077354C 7CE33A14 */  add      r7, r3, r7;
/* 80773550 7C0903A6 */  mtctr    r0;
/* 80773554 2C060004 */  cmpwi    r6, 4;
/* 80773558 4080001C */  bge-     UNDEF_80773574;
UNDEF_8077355c:;
/* 8077355C 80C70274 */  lwz      r6, 628(r7);
/* 80773560 38E70008 */  addi     r7, r7, 8;
/* 80773564 880600BB */  lbz      r0, 187(r6);
/* 80773568 5400063C */  rlwinm   r0, r0, 0, 24, 30;
/* 8077356C 980600BB */  stb      r0, 187(r6);
/* 80773570 4200FFEC */  bdnz+    UNDEF_8077355c;
UNDEF_80773574:;
                         cmpwi    r4, 7;
                         beq-     L_UNDEF_80773220_MarioUnlocked;
/* 80773574 2C040002 */  cmpwi    r4, 2;
/* 80773578 41820030 */  beq-     UNDEF_807735a8;
/* 8077357C 2C040000 */  cmpwi    r4, 0;
/* 80773580 41820038 */  beq-     UNDEF_807735b8;
/* 80773584 2C040001 */  cmpwi    r4, 1;
/* 80773588 41820040 */  beq-     UNDEF_807735c8;
                         cmpwi    r4, 8;
                         beq-     L_UNDEF_80773220_MarioLocked;
/* 8077358C 2C040005 */  cmpwi    r4, 5;
/* 80773590 41820048 */  beq-     UNDEF_807735d8;
/* 80773594 2C040003 */  cmpwi    r4, 3;
/* 80773598 4182006C */  beq-     UNDEF_80773604;
/* 8077359C 2C040004 */  cmpwi    r4, 4;
/* 807735A0 41820090 */  beq-     UNDEF_80773630;
/* 807735A4 480000B4 */  b        UNDEF_80773658;
L_UNDEF_80773220_MarioUnlocked:;
                         mr       r3, r30;
                         mr       r4, r31;
                         bl       setMarioIconVisible__32dCharacterChangeSelectContents_cFUl;
                         b        UNDEF_80773658;
UNDEF_807735a8:;
/* 807735A8 7FC3F378 */  mr       r3, r30;
/* 807735AC 7FE4FB78 */  mr       r4, r31;
/* 807735B0 4BFFFAF1 */  bl       UNDEF_807730a0;
/* 807735B4 480000A4 */  b        UNDEF_80773658;
UNDEF_807735b8:;
/* 807735B8 7FC3F378 */  mr       r3, r30;
/* 807735BC 7FE4FB78 */  mr       r4, r31;
/* 807735C0 4BFFFB61 */  bl       UNDEF_80773120;
/* 807735C4 48000094 */  b        UNDEF_80773658;
UNDEF_807735c8:;
/* 807735C8 7FC3F378 */  mr       r3, r30;
/* 807735CC 7FE4FB78 */  mr       r4, r31;
/* 807735D0 4BFFFBD1 */  bl       UNDEF_807731a0;
/* 807735D4 48000084 */  b        UNDEF_80773658;
L_UNDEF_80773220_MarioLocked:;
                         slwi     r0, r5, 2;
                         mr       r4, r31;
                         add      r5, r3, r0;
                         mr       r3, r30;
                         lwz      r5, 596(r5);
                         lbz      r0, 187(r5);
                         rlwinm   r0, r0, 0, 24, 30;
                         ori      r0, r0, 1;
                         stb      r0, 187(r5);
                         bl       setMarioIconVisible__32dCharacterChangeSelectContents_cFUl;
                         b        UNDEF_80773658;
UNDEF_807735d8:;
/* 807735D8 54A0103A */  slwi     r0, r5, 2;
/* 807735DC 7FE4FB78 */  mr       r4, r31;
/* 807735E0 7CA30214 */  add      r5, r3, r0;
/* 807735E4 7FC3F378 */  mr       r3, r30;
/* 807735E8 80A50254 */  lwz      r5, 596(r5);
/* 807735EC 880500BB */  lbz      r0, 187(r5);
/* 807735F0 5400063C */  rlwinm   r0, r0, 0, 24, 30;
/* 807735F4 60000001 */  ori      r0, r0, 1;
/* 807735F8 980500BB */  stb      r0, 187(r5);
/* 807735FC 4BFFFAA5 */  bl       UNDEF_807730a0;
/* 80773600 48000058 */  b        UNDEF_80773658;
UNDEF_80773604:;
/* 80773604 54A0103A */  slwi     r0, r5, 2;
/* 80773608 7FE4FB78 */  mr       r4, r31;
/* 8077360C 7CA30214 */  add      r5, r3, r0;
/* 80773610 7FC3F378 */  mr       r3, r30;
/* 80773614 80A50254 */  lwz      r5, 596(r5);
/* 80773618 880500BB */  lbz      r0, 187(r5);
/* 8077361C 5400063C */  rlwinm   r0, r0, 0, 24, 30;
/* 80773620 60000001 */  ori      r0, r0, 1;
/* 80773624 980500BB */  stb      r0, 187(r5);
/* 80773628 4BFFFAF9 */  bl       UNDEF_80773120;
/* 8077362C 4800002C */  b        UNDEF_80773658;
UNDEF_80773630:;
/* 80773630 54A0103A */  slwi     r0, r5, 2;
/* 80773634 7FE4FB78 */  mr       r4, r31;
/* 80773638 7CA30214 */  add      r5, r3, r0;
/* 8077363C 7FC3F378 */  mr       r3, r30;
/* 80773640 80A50254 */  lwz      r5, 596(r5);
/* 80773644 880500BB */  lbz      r0, 187(r5);
/* 80773648 5400063C */  rlwinm   r0, r0, 0, 24, 30;
/* 8077364C 60000001 */  ori      r0, r0, 1;
/* 80773650 980500BB */  stb      r0, 187(r5);
/* 80773654 4BFFFB4D */  bl       UNDEF_807731a0;

UNDEF_80773658:;
/* 80773658 387F0002 */  addi     r3, r31, 2;
/* 8077365C 57E0103A */  slwi     r0, r31, 2;
/* 80773660 5463103A */  slwi     r3, r3, 2;
/* 80773664 7C9E1A14 */  add      r4, r30, r3;
/* 80773668 80840274 */  lwz      r4, 628(r4);
/* 8077366C 7C7E0214 */  add      r3, r30, r0;
/* 80773670 880400BB */  lbz      r0, 187(r4);
/* 80773674 5400063C */  rlwinm   r0, r0, 0, 24, 30;
/* 80773678 60000001 */  ori      r0, r0, 1;
/* 8077367C 980400BB */  stb      r0, 187(r4);
/* 80773680 80630274 */  lwz      r3, 628(r3);
/* 80773684 880300BB */  lbz      r0, 187(r3);
/* 80773688 5400063C */  rlwinm   r0, r0, 0, 24, 30;
/* 8077368C 60000001 */  ori      r0, r0, 1;
/* 80773690 980300BB */  stb      r0, 187(r3);
/* 80773694 83E1000C */  lwz      r31, 12(r1);
/* 80773698 83C10008 */  lwz      r30, 8(r1);
/* 8077369C 80010014 */  lwz      r0, 20(r1);
/* 807736A0 7C0803A6 */  mtlr     r0;
/* 807736A4 38210010 */  addi     r1, r1, 16;
/* 807736A8 4E800020 */  blr;
  // clang-format on
);

[[address(0x80773840)]]
void dCharacterChangeSelectContents_c::finalizeState_OnStageWait()
{
    for (int i = 0; i < 4; i++) {
        mLives[i] = daPyMng_c::mRest[i];
    }

    m0x28C = dCharacterChangeSelectBase_c::Icon_e::ICON_NONE;
    m0x294 = dCharacterChangeSelectBase_c::Icon_e::ICON_NONE;
    m0x29E = 0;
    m0x29F = 0;
}