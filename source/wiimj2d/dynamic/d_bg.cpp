// d_bg.cpp
// NSMBW: 0x80076FD0 - 0x8007E180

#include "d_bg.h"

#include <dynamic/actor/d_a_player.h>
#include <dynamic/actor/d_a_player_manager.h>


[[address(0x800785E0)]]
bool dBg_c::UNDEF_800785E0()
{
    u8 mask = daPyMng_c::getActScrollInfo();

    for (int i = 0; i < PLAYER_COUNT; i++) {
        if (mask & (1 << i)) {
            dAcPy_c* player = daPyMng_c::getPlayer(i);
            if (player != nullptr && player->mScrollType == 6) {
                return true;
            }
        }
    }

    return false;
}

[[address(0x80078670)]]
bool UNDEF_80078670() ASM_METHOD(
    // clang-format off
/* 80078670 9421FFB0 */  stwu     r1, -80(r1);
/* 80078674 7C0802A6 */  mflr     r0;
/* 80078678 90010054 */  stw      r0, 84(r1);
/* 8007867C 39610020 */  addi     r11, r1, 32;
/* 80078680 DBE10040 */  stfd     f31, 64(r1);
/* 80078684 F3E10048 */  .long    0xF3E10048; // psq_st   f31, 72(r1), 0, 0;
/* 80078688 DBC10030 */  stfd     f30, 48(r1);
/* 8007868C F3C10038 */  .long    0xF3C10038; // psq_st   f30, 56(r1), 0, 0;
/* 80078690 DBA10020 */  stfd     f29, 32(r1);
/* 80078694 F3A10028 */  .long    0xF3A10028; // psq_st   f29, 40(r1), 0, 0;
/* 80078698 482649CD */  bl       UNDEF_802dd064;
/* 8007869C 7C7B1B78 */  mr       r27, r3;
/* 800786A0 3BA00000 */  li       r29, 0;
/* 800786A4 4BFE75CD */  bl       UNDEF_8005fc70;
/* 800786A8 C3A28CB8 */  lfs      f29, -29512(r2);
/* 800786AC 7C7E1B78 */  mr       r30, r3;
/* 800786B0 C3C28CBC */  lfs      f30, -29508(r2);
/* 800786B4 3B800000 */  li       r28, 0;
/* 800786B8 C3E28CC0 */  lfs      f31, -29504(r2);
/* 800786BC 3BE00001 */  li       r31, 1;
UNDEF_800786c0:;
/* 800786C0 7F83E378 */  mr       r3, r28;
/* 800786C4 4BFE723D */  bl       UNDEF_8005f900;
/* 800786C8 2C030000 */  cmpwi    r3, 0;
/* 800786CC 41820074 */  beq-     UNDEF_80078740;
/* 800786D0 57C4063E */  clrlwi   r4, r30, 24;
/* 800786D4 7FE0E030 */  slw      r0, r31, r28;
/* 800786D8 7C800039 */  and.     r0, r4, r0;
/* 800786DC 41820064 */  beq-     UNDEF_80078740;
/* 800786E0 8803153C */  lbz      r0, 5436(r3);
/* 800786E4 2C000006 */  cmpwi    r0, 6;
/* 800786E8 40820058 */  bne-     UNDEF_80078740;
/* 800786EC 80ADA760 */  lwz      r5, -22688(r13);
/* 800786F0 C0231530 */  lfs      f1, 5424(r3);
/* 800786F4 C005003C */  lfs      f0, 60(r5);
/* 800786F8 EC00E828 */  fsubs    f0, f0, f29;
/* 800786FC FC010040 */  fcmpo    cr0, f1, f0;
/* 80078700 40810014 */  ble-     UNDEF_80078714;
/* 80078704 3C9B0009 */  addis    r4, r27, 9;
/* 80078708 C004000C */  lfs      f0, 12(r4);
/* 8007870C FC00F040 */  fcmpo    cr0, f0, f30;
/* 80078710 4180002C */  blt-     UNDEF_8007873c;
UNDEF_80078714:;
/* 80078714 3C9B0009 */  addis    r4, r27, 9;
/* 80078718 C004000C */  lfs      f0, 12(r4);
/* 8007871C FC00F040 */  fcmpo    cr0, f0, f30;
/* 80078720 4C411382 */  cror     2, 1, 2;
/* 80078724 4082001C */  bne-     UNDEF_80078740;
/* 80078728 C005003C */  lfs      f0, 60(r5);
/* 8007872C C0231530 */  lfs      f1, 5424(r3);
/* 80078730 EC00F828 */  fsubs    f0, f0, f31;
/* 80078734 FC010040 */  fcmpo    cr0, f1, f0;
/* 80078738 40810008 */  ble-     UNDEF_80078740;
UNDEF_8007873c:;
/* 8007873C 3BA00001 */  li       r29, 1;
UNDEF_80078740:;
/* 80078740 3B9C0001 */  addi     r28, r28, 1;
/* 80078744 2C1C0004 */  cmpwi    r28, PLAYER_COUNT;
/* 80078748 4180FF78 */  blt+     UNDEF_800786c0;
/* 8007874C E3E10048 */  .long    0xE3E10048; // psq_l    f31, 72(r1), 0, 0;
/* 80078750 7FA3EB78 */  mr       r3, r29;
/* 80078754 CBE10040 */  lfd      f31, 64(r1);
/* 80078758 E3C10038 */  .long    0xE3C10038; // psq_l    f30, 56(r1), 0, 0;
/* 8007875C CBC10030 */  lfd      f30, 48(r1);
/* 80078760 E3A10028 */  .long    0xE3A10028; // psq_l    f29, 40(r1), 0, 0;
/* 80078764 CBA10020 */  lfd      f29, 32(r1);
/* 80078768 39610020 */  addi     r11, r1, 32;
/* 8007876C 48264945 */  bl       UNDEF_802dd0b0;
/* 80078770 80010054 */  lwz      r0, 84(r1);
/* 80078774 7C0803A6 */  mtlr     r0;
/* 80078778 38210050 */  addi     r1, r1, 80;
/* 8007877C 4E800020 */  blr;
    // clang-format on
);

[[address(0x8007CA90)]]
void UNDEF_8007ca90() ASM_METHOD(
    // clang-format off
/* 8007CA90          */  stwu     r1, -0x50(r1);
/* 8007CA94 7C0802A6 */  mflr     r0;
/* 8007CA98          */  stw      r0, 0x54(r1);
/* 8007CA9C          */  addi     r11, r1, 0x50;
/* 8007CAA0 482605B1 */  bl       UNDEF_802dd050;
/* 8007CAA4 7C781B78 */  mr       r24, r3;
/* 8007CAA8 7C992378 */  mr       r25, r4;
/* 8007CAAC 7CBA2B78 */  mr       r26, r5;
/* 8007CAB0 7CDB3378 */  mr       r27, r6;
/* 8007CAB4 3BE10008 */  addi     r31, r1, 8;
/* 8007CAB8 3EE30009 */  addis    r23, r3, 9;
/* 8007CABC 3BC00000 */  li       r30, 0;
/* 8007CAC0 3BA00000 */  li       r29, 0;
/* 8007CAC4 3B800000 */  li       r28, 0;
/* 8007CAC8 3AC00000 */  li       r22, 0;
UNDEF_8007cacc:;
/* 8007CACC 7F83E378 */  mr       r3, r28;
/* 8007CAD0 4BFE2E31 */  bl       UNDEF_8005f900;
/* 8007CAD4 2C030000 */  cmpwi    r3, 0;
/* 8007CAD8 907F0000 */  stw      r3, 0(r31);
/* 8007CADC 41820024 */  beq-     UNDEF_8007cb00;
/* 8007CAE0 8803153C */  lbz      r0, 5436(r3);
/* 8007CAE4 2C000001 */  cmpwi    r0, 1;
/* 8007CAE8 40820008 */  bne-     UNDEF_8007caf0;
/* 8007CAEC 92DF0000 */  stw      r22, 0(r31);
UNDEF_8007caf0:;
/* 8007CAF0 8803153C */  lbz      r0, 5436(r3);
/* 8007CAF4 2C000003 */  cmpwi    r0, 3;
/* 8007CAF8 40820008 */  bne-     UNDEF_8007cb00;
/* 8007CAFC 3BBD0001 */  addi     r29, r29, 1;
UNDEF_8007cb00:;
/* 8007CB00 801F0000 */  lwz      r0, 0(r31);
/* 8007CB04 2C000000 */  cmpwi    r0, 0;
/* 8007CB08 41820008 */  beq-     UNDEF_8007cb10;
/* 8007CB0C 3BDE0001 */  addi     r30, r30, 1;
UNDEF_8007cb10:;
/* 8007CB10 88170079 */  lbz      r0, 121(r23);
/* 8007CB14 28000001 */  cmplwi   r0, 1;
/* 8007CB18 4082001C */  bne-     UNDEF_8007cb34;
/* 8007CB1C 2C030000 */  cmpwi    r3, 0;
/* 8007CB20 41820014 */  beq-     UNDEF_8007cb34;
/* 8007CB24 8803153C */  lbz      r0, 5436(r3);
/* 8007CB28 2C000003 */  cmpwi    r0, 3;
/* 8007CB2C 40820008 */  bne-     UNDEF_8007cb34;
/* 8007CB30 92DF0000 */  stw      r22, 0(r31);
UNDEF_8007cb34:;
/* 8007CB34 3B9C0001 */  addi     r28, r28, 1;
/* 8007CB38 3BFF0004 */  addi     r31, r31, 4;
/* 8007CB3C          */  cmpwi    r28, 8;
/* 8007CB40 4180FF8C */  blt+     UNDEF_8007cacc;
/* 8007CB44 7C1EE800 */  cmpw     r30, r29;
/* 8007CB48 93D90030 */  stw      r30, 48(r25);
/* 8007CB4C 41810018 */  bgt-     UNDEF_8007cb64;
/* 8007CB50 806DA730 */  lwz      r3, -22736(r13);
/* 8007CB54 38000001 */  li       r0, 1;
/* 8007CB58 3C630009 */  addis    r3, r3, 9;
/* 8007CB5C 980309CA */  stb      r0, 2506(r3);
/* 8007CB60 480001F8 */  b        UNDEF_8007cd58;
UNDEF_8007cb64:;
/* 8007CB64 806DA730 */  lwz      r3, -22736(r13);
/* 8007CB68 3F80802F */  lis      r28, UNDEF_802efbb0@ha;
/* 8007CB6C 38000000 */  li       r0, 0;
/* 8007CB70 3AC10008 */  addi     r22, r1, 8;
/* 8007CB74 3C630009 */  addis    r3, r3, 9;
/* 8007CB78 575D15BA */  clrlslwi r29, r26, 24, 2;
/* 8007CB7C 980309CA */  stb      r0, 2506(r3);
/* 8007CB80 3B9CFBB0 */  addi     r28, r28, UNDEF_802efbb0@l;
/* 8007CB84 3BC00000 */  li       r30, 0;
UNDEF_8007cb88:;
/* 8007CB88 3BFE0001 */  addi     r31, r30, 1;
/* 8007CB8C 3AE10008 */  addi     r23, r1, 8;
/* 8007CB90 57E0103A */  slwi     r0, r31, 2;
/* 8007CB94 7EF70214 */  add      r23, r23, r0;
/* 8007CB98 48000054 */  b        UNDEF_8007cbec;
UNDEF_8007cb9c:;
/* 8007CB9C 80770000 */  lwz      r3, 0(r23);
/* 8007CBA0 80960000 */  lwz      r4, 0(r22);
/* 8007CBA4 2C030000 */  cmpwi    r3, 0;
/* 8007CBA8 4182003C */  beq-     UNDEF_8007cbe4;
/* 8007CBAC 2C040000 */  cmpwi    r4, 0;
/* 8007CBB0 40820014 */  bne-     UNDEF_8007cbc4;
/* 8007CBB4 7EC3B378 */  mr       r3, r22;
/* 8007CBB8 7EE4BB78 */  mr       r4, r23;
/* 8007CBBC 4BFFFEB5 */  bl       UNDEF_8007ca70;
/* 8007CBC0 48000024 */  b        UNDEF_8007cbe4;
UNDEF_8007cbc4:;
/* 8007CBC4 7D9CE82E */  lwzx     r12, r28, r29;
/* 8007CBC8 7D8903A6 */  mtctr    r12;
/* 8007CBCC 4E800421 */  bctrl    ;
/* 8007CBD0 2C030000 */  cmpwi    r3, 0;
/* 8007CBD4 41820010 */  beq-     UNDEF_8007cbe4;
/* 8007CBD8 7EC3B378 */  mr       r3, r22;
/* 8007CBDC 7EE4BB78 */  mr       r4, r23;
/* 8007CBE0 4BFFFE91 */  bl       UNDEF_8007ca70;
UNDEF_8007cbe4:;
/* 8007CBE4 3AF70004 */  addi     r23, r23, 4;
/* 8007CBE8 3BFF0001 */  addi     r31, r31, 1;
UNDEF_8007cbec:;
/* 8007CBEC          */  cmpwi    r31, 8;
/* 8007CBF0 4180FFAC */  blt+     UNDEF_8007cb9c;
/* 8007CBF4 3BDE0001 */  addi     r30, r30, 1;
/* 8007CBF8 3AD60004 */  addi     r22, r22, 4;
/* 8007CBFC          */  cmpwi    r30, 8 - 1;
/* 8007CC00 4180FF88 */  blt+     UNDEF_8007cb88;
/* 8007CC04 381BFFFF */  subi     r0, r27, 1;
/* 8007CC08 2C1A0000 */  cmpwi    r26, 0;
/* 8007CC0C 541B103A */  slwi     r27, r0, 2;
/* 8007CC10 3AC10008 */  addi     r22, r1, 8;
/* 8007CC14 83810008 */  lwz      r28, 8(r1);
/* 8007CC18 7EF6D82E */  lwzx     r23, r22, r27;
/* 8007CC1C 41820020 */  beq-     UNDEF_8007cc3c;
/* 8007CC20 2C1A0002 */  cmpwi    r26, 2;
/* 8007CC24 41820068 */  beq-     UNDEF_8007cc8c;
/* 8007CC28 2C1A0001 */  cmpwi    r26, 1;
/* 8007CC2C 418200B0 */  beq-     UNDEF_8007ccdc;
/* 8007CC30 2C1A0003 */  cmpwi    r26, 3;
/* 8007CC34 418200E8 */  beq-     UNDEF_8007cd1c;
/* 8007CC38 48000120 */  b        UNDEF_8007cd58;
UNDEF_8007cc3c:;
/* 8007CC3C 2C1C0000 */  cmpwi    r28, 0;
/* 8007CC40 41820020 */  beq-     UNDEF_8007cc60;
/* 8007CC44 93990014 */  stw      r28, 20(r25);
/* 8007CC48 7F03C378 */  mr       r3, r24;
/* 8007CC4C C03C152C */  lfs      f1, 5420(r28);
/* 8007CC50 4BFFFB81 */  bl       UNDEF_8007c7d0;
/* 8007CC54 D0390004 */  stfs     f1, 4(r25);
/* 8007CC58 801C14D4 */  lwz      r0, 5332(r28);
/* 8007CC5C 90190024 */  stw      r0, 36(r25);
UNDEF_8007cc60:;
/* 8007CC60 7C16D82E */  lwzx     r0, r22, r27;
/* 8007CC64 2C000000 */  cmpwi    r0, 0;
/* 8007CC68 418200F0 */  beq-     UNDEF_8007cd58;
/* 8007CC6C 90190010 */  stw      r0, 16(r25);
/* 8007CC70 7F03C378 */  mr       r3, r24;
/* 8007CC74 C037152C */  lfs      f1, 5420(r23);
/* 8007CC78 4BFFFB59 */  bl       UNDEF_8007c7d0;
/* 8007CC7C D0390000 */  stfs     f1, 0(r25);
/* 8007CC80 801714D4 */  lwz      r0, 5332(r23);
/* 8007CC84 90190020 */  stw      r0, 32(r25);
/* 8007CC88 480000D0 */  b        UNDEF_8007cd58;
UNDEF_8007cc8c:;
/* 8007CC8C 2C170000 */  cmpwi    r23, 0;
/* 8007CC90 41820020 */  beq-     UNDEF_8007ccb0;
/* 8007CC94 92F90014 */  stw      r23, 20(r25);
/* 8007CC98 7F03C378 */  mr       r3, r24;
/* 8007CC9C C037152C */  lfs      f1, 5420(r23);
/* 8007CCA0 4BFFFB31 */  bl       UNDEF_8007c7d0;
/* 8007CCA4 D0390004 */  stfs     f1, 4(r25);
/* 8007CCA8 801714D4 */  lwz      r0, 5332(r23);
/* 8007CCAC 90190024 */  stw      r0, 36(r25);
UNDEF_8007ccb0:;
/* 8007CCB0 80010008 */  lwz      r0, 8(r1);
/* 8007CCB4 2C000000 */  cmpwi    r0, 0;
/* 8007CCB8 418200A0 */  beq-     UNDEF_8007cd58;
/* 8007CCBC 90190010 */  stw      r0, 16(r25);
/* 8007CCC0 7F03C378 */  mr       r3, r24;
/* 8007CCC4 C03C152C */  lfs      f1, 5420(r28);
/* 8007CCC8 4BFFFB09 */  bl       UNDEF_8007c7d0;
/* 8007CCCC D0390000 */  stfs     f1, 0(r25);
/* 8007CCD0 801C14D4 */  lwz      r0, 5332(r28);
/* 8007CCD4 90190020 */  stw      r0, 32(r25);
/* 8007CCD8 48000080 */  b        UNDEF_8007cd58;
UNDEF_8007ccdc:;
/* 8007CCDC 2C1C0000 */  cmpwi    r28, 0;
/* 8007CCE0 41820018 */  beq-     UNDEF_8007ccf8;
/* 8007CCE4 93990018 */  stw      r28, 24(r25);
/* 8007CCE8 C01C1530 */  lfs      f0, 5424(r28);
/* 8007CCEC D0190008 */  stfs     f0, 8(r25);
/* 8007CCF0 801C14D4 */  lwz      r0, 5332(r28);
/* 8007CCF4 90190028 */  stw      r0, 40(r25);
UNDEF_8007ccf8:;
/* 8007CCF8 7C16D82E */  lwzx     r0, r22, r27;
/* 8007CCFC 2C000000 */  cmpwi    r0, 0;
/* 8007CD00 41820058 */  beq-     UNDEF_8007cd58;
/* 8007CD04 9019001C */  stw      r0, 28(r25);
/* 8007CD08 C0171530 */  lfs      f0, 5424(r23);
/* 8007CD0C D019000C */  stfs     f0, 12(r25);
/* 8007CD10 801714D4 */  lwz      r0, 5332(r23);
/* 8007CD14 9019002C */  stw      r0, 44(r25);
/* 8007CD18 48000040 */  b        UNDEF_8007cd58;
UNDEF_8007cd1c:;
/* 8007CD1C 2C170000 */  cmpwi    r23, 0;
/* 8007CD20 41820018 */  beq-     UNDEF_8007cd38;
/* 8007CD24 92F90018 */  stw      r23, 24(r25);
/* 8007CD28 C0171530 */  lfs      f0, 5424(r23);
/* 8007CD2C D0190008 */  stfs     f0, 8(r25);
/* 8007CD30 801714D4 */  lwz      r0, 5332(r23);
/* 8007CD34 90190028 */  stw      r0, 40(r25);
UNDEF_8007cd38:;
/* 8007CD38 80010008 */  lwz      r0, 8(r1);
/* 8007CD3C 2C000000 */  cmpwi    r0, 0;
/* 8007CD40 41820018 */  beq-     UNDEF_8007cd58;
/* 8007CD44 9019001C */  stw      r0, 28(r25);
/* 8007CD48 C01C1530 */  lfs      f0, 5424(r28);
/* 8007CD4C D019000C */  stfs     f0, 12(r25);
/* 8007CD50 801C14D4 */  lwz      r0, 5332(r28);
/* 8007CD54 9019002C */  stw      r0, 44(r25);
UNDEF_8007cd58:;
/* 8007CD58          */  addi     r11, r1, 0x50;
/* 8007CD5C 48260341 */  bl       UNDEF_802dd09c;
/* 8007CD60          */  lwz      r0, 0x54(r1);
/* 8007CD64 7C0803A6 */  mtlr     r0;
/* 8007CD68          */  addi     r1, r1, 0x50;
/* 8007CD6C 4E800020 */  blr;
    // clang-format on
);