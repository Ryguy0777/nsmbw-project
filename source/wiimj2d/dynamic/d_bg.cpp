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