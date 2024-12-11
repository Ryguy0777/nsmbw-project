// d_a_en_redcoin.cpp
// NSMBW d_enemies.text: 0x80A93990 - 0x80A94D90

#include "d_a_en_redcoin.h"

#include <dynamic/d_player/d_a_player.h>

u32 daEnRedcoin_c_sizeof()
{
    return sizeof(daEnRedcoin_c);
}

[[address(0x80A93990)]]
daEnRedcoin_c* daEnRedcoin_c_classInit() ASM_METHOD(
  // clang-format off
/* 80A93990 9421FFF0 */  stwu     r1, -16(r1);
/* 80A93994 7C0802A6 */  mflr     r0;
/* 80A9399C 90010014 */  stw      r0, 20(r1);
/* 80A939A0 93E1000C */  stw      r31, 12(r1);
                         bl       daEnRedcoin_c_sizeof__Fv;
/* 80A939A4 4B6CF05D */  bl       UNDEF_80162a00;
/* 80A939A8 2C030000 */  cmpwi    r3, 0;
/* 80A939AC 7C7F1B78 */  mr       r31, r3;
/* 80A939B0 41820034 */  beq-     UNDEF_80a939e4;
/* 80A939B4 4B6014CD */  bl       UNDEF_80094e80;
/* 80A939B8 3C8080B0 */  lis      r4, UNDEF_80b05448@ha;
/* 80A939BC 387F0524 */  addi     r3, r31, 1316;
/* 80A939C0 38845448 */  addi     r4, r4, UNDEF_80b05448@l;
/* 80A939C4 909F0060 */  stw      r4, 96(r31);
/* 80A939C8 4B5D5659 */  bl       UNDEF_80069020;
/* 80A939CC 38000000 */  li       r0, 0;
/* 80A939D0 901F0540 */  stw      r0, 1344(r31);
/* 80A939D4 387F0544 */  addi     r3, r31, 1348;
/* 80A939D8 4B6D6439 */  bl       UNDEF_80169e10;
/* 80A939DC 387F0584 */  addi     r3, r31, 1412;
/* 80A939E0 4B5EBDC1 */  bl       UNDEF_8007f7a0;
UNDEF_80a939e4:;
/* 80A939E4 7FE3FB78 */  mr       r3, r31;
/* 80A939E8 83E1000C */  lwz      r31, 12(r1);
/* 80A939EC 80010014 */  lwz      r0, 20(r1);
/* 80A939F0 7C0803A6 */  mtlr     r0;
/* 80A939F4 38210010 */  addi     r1, r1, 16;
/* 80A939F8 4E800020 */  blr;
  // clang-format on
);

[[address(0x80A94250)]]
void daEnRedcoin_c::selectItems()
{
    for (int i = 0; i < PLAYER_COUNT; i++) {
        mPlyItemSpawnMode[i] = 0;

        if (!daPyMng_c::isPlayerActive(i)) {
            continue;
        }

        dAcPy_c* player = daPyMng_c::getPlayer(i);
        if (player == nullptr || player->isStatus(83) || player->isItemKinopio()) {
            continue;
        }

        mPlyItemSpawnMode[i] = 1;

        using IntArray = int[];
        switch (player->mPlayerMode) {
        case PLAYER_POWERUP_e::NONE:
        case PLAYER_POWERUP_e::MUSHROOM:
            mPlyItem[i] = IntArray{9, 21, 17, 14}[mItemType % 4];
            break;

        default:
            mPlyItem[i] = 7; // 1-Up
            break;
        }
    }
}

[[address(0x80A94340)]]
void daEnRedcoin_c_awardItems() ASM_METHOD(
  // clang-format off
/* 80A94340 9421FFA0 */  stwu     r1, -96(r1);
/* 80A94344 7C0802A6 */  mflr     r0;
/* 80A94348 90010064 */  stw      r0, 100(r1);
/* 80A9434C 39610040 */  addi     r11, r1, 64;
/* 80A94350 DBE10050 */  stfd     f31, 80(r1);
/* 80A94354 F3E10058 */  .long    0xF3E10058; // psq_st   f31, 88(r1), 0, 0;
/* 80A94358 DBC10040 */  stfd     f30, 64(r1);
/* 80A9435C F3C10048 */  .long    0xF3C10048; // psq_st   f30, 72(r1), 0, 0;
/* 80A94360 4B848CFD */  bl       UNDEF_802dd05c;
/* 80A94364 3CA080AD */  lis      r5, UNDEF_80ad3fd8@ha;
/* 80A94368 3C8080AD */  lis      r4, UNDEF_80ad3f98@ha;
/* 80A9436C C3C53FD8 */  lfs      f30, UNDEF_80ad3fd8@l(r5);
/* 80A94370 7C7C1B78 */  mr       r28, r3;
/* 80A94374 C3E43F98 */  lfs      f31, UNDEF_80ad3f98@l(r4);
/* 80A94378 3B400000 */  li       r26, 0;
/* 80A9437C 3B600000 */  li       r27, 0;
/* 80A94380 3FE08043 */  lis      r31, UNDEF_8042a0e0@ha; // ms_Instance_p__14dBgParameter_c
/* 80A94384 3FA08043 */  lis      r29, mActPlayerInfo__9daPyMng_c@ha;
/* 80A94388 3BC00001 */  li       r30, 1;
UNDEF_80a9438c:;
/* 80A9438C 801C067C */  lwz      r0, OFFSET_mPlyItemSpawnMode(r28);
/* 80A94390 2C000000 */  cmpwi    r0, 0;
/* 80A94394 418200A8 */  beq-     UNDEF_80a9443c;
/* 80A94398 7F43D378 */  mr       r3, r26;
/* 80A9439C 4B5CB565 */  bl       UNDEF_8005f900;
/* 80A943A0 2C030000 */  cmpwi    r3, 0;
/* 80A943A4 7C791B78 */  mr       r25, r3;
/* 80A943A8 41820094 */  beq-     UNDEF_80a9443c;
/* 80A943AC 5740063E */  clrlwi   r0, r26, 24;
/* 80A943B0 889D9F88 */  lbz      r4, mActPlayerInfo__9daPyMng_c@l(r29);
/* 80A943B4 7FC00030 */  slw      r0, r30, r0;
/* 80A943B8 7C800039 */  and.     r0, r4, r0;
/* 80A943BC 41820080 */  beq-     UNDEF_80a9443c;
/* 80A943C0 38800053 */  li       r4, 83;
/* 80A943C4 4B5C292D */  bl       isStatus__10daPlBase_cFi;
/* 80A943C8 2C030000 */  cmpwi    r3, 0;
/* 80A943CC 40820070 */  bne-     UNDEF_80a9443c;
/* 80A943D0 81990060 */  lwz      r12, 96(r25);
/* 80A943D4 7F23CB78 */  mr       r3, r25;
/* 80A943D8 818C00E0 */  lwz      r12, 224(r12);
/* 80A943DC 7D8903A6 */  mtctr    r12;
/* 80A943E0 4E800421 */  bctrl;
/* 80A943E4 2C030000 */  cmpwi    r3, 0;
/* 80A943E8 40820054 */  bne-     UNDEF_80a9443c;
/* 80A943EC 807FA0E0 */  lwz      r3, UNDEF_8042a0e0@l(r31); // ms_Instance_p__14dBgParameter_c
/* 80A943F0 63602080 */  ori      r0, r27, 8320;
/* 80A943F4 C01900B4 */  lfs      f0, 180(r25);
/* 80A943F8 38A10008 */  addi     r5, r1, 8;
/* 80A943FC C063003C */  lfs      f3, 60(r3);
/* 80A94400 3860003C */  li       r3, 60;
/* 80A94404 C03900B0 */  lfs      f1, 176(r25);
/* 80A94408 38C00000 */  li       r6, 0;
/* 80A9440C C05900AC */  lfs      f2, 172(r25);
/* 80A94410 EC7E182A */  fadds    f3, f30, f3;
/* 80A94414 D0410008 */  stfs     f2, 8(r1);
/* 80A94418 38E00000 */  li       r7, 0;
/* 80A9441C D061000C */  stfs     f3, 12(r1);
/* 80A94420 D3E10010 */  stfs     f31, 16(r1);
/* 80A94424 809C068C */  lwz      r4, OFFSET_mPlyItem(r28);
/* 80A94428 D0410014 */  stfs     f2, 20(r1);
/* 80A9442C 7C840378 */  or       r4, r4, r0;
/* 80A94430 D0210018 */  stfs     f1, 24(r1);
/* 80A94434 D001001C */  stfs     f0, 28(r1);
/* 80A94438 4B5D01D9 */  bl       UNDEF_80064610;
UNDEF_80a9443c:;
/* 80A9443C 3B5A0001 */  addi     r26, r26, 1;
/* 80A94440 3F7B0001 */  addis    r27, r27, 1;
/* 80A94444 2C1A0004 */  cmpwi    r26, PLAYER_COUNT;
/* 80A94448 3B9C0004 */  addi     r28, r28, 4;
/* 80A9444C 4180FF40 */  blt+     UNDEF_80a9438c;
/* 80A94450 39610040 */  addi     r11, r1, 64;
/* 80A94454 E3E10058 */  .long    0xE3E10058; // psq_l    f31, 88(r1), 0, 0;
/* 80A94458 CBE10050 */  lfd      f31, 80(r1);
/* 80A9445C E3C10048 */  .long    0xE3C10048; // psq_l    f30, 72(r1), 0, 0;
/* 80A94460 CBC10040 */  lfd      f30, 64(r1);
/* 80A94464 4B848C45 */  bl       UNDEF_802dd0a8;
/* 80A94468 80010064 */  lwz      r0, 100(r1);
/* 80A9446C 7C0803A6 */  mtlr     r0;
/* 80A94470 38210060 */  addi     r1, r1, 96;
/* 80A94474 4E800020 */  blr;
  // clang-format on
);