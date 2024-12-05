// d_game_common.cpp
// NSMBW .text: 0x800B2E70 - 0x800B5930

#include "d_game_common.h"

#include <dynamic/actor/static/d_a_player_manager.h>
#include <dynamic/d_info.h>
#include <nw4r/ut/Color.h>
#include <dynamic/d_lyttextbox.h>

namespace dGameCom
{

[[address(0x800B2E70)]]
void initRandomSeed();

[[address(0x800B2EE0)]]
u32 rndInt(u32 max);

[[address(0x800B30C0)]]
f32 getDispCenterX();

[[address(0x800B5340)]]
bool chkContinue()
{
    // Original function is flawed as it indexes in mPlayerType twice (so like
    // mRest[int(mPlayerType[int(mPlayerType[i])])]). It doesn't matter but i think it's kinda
    // interesting.

    for (int i = 0; i < CHARACTER_COUNT; i++) {
        if (daPyMng_c::mRest[i] == 0) {
            return true;
        }
    }

    return false;
}

[[address(0x800B53F0)]]
bool chkCancelButton(int player);

[[address(0x800B3600)]]
void FUN_800B3600() ASM_METHOD(
  // clang-format off
/* 800B3600 800DAB64 */  lwz      r0, -21660(r13);
/* 800B3604 7C691B78 */  mr       r9, r3;
/* 800B3608 7C852378 */  mr       r5, r4;
/* 800B360C 2C000000 */  cmpwi    r0, 0;
/* 800B3610 4C820020 */  bnelr-;
/* 800B3614 3CC0802F */  lis      r6, UNDEF_802f0df8@ha;
/* 800B3618 80EDAC80 */  lwz      r7, -21376(r13);
/* 800B361C 38C60DF8 */  addi     r6, r6, UNDEF_802f0df8@l;
/* 800B3620 7C0620AE */  lbzx     r0, r6, r4;
/* 800B3624 2C000000 */  cmpwi    r0, 0;
/* 800B3628 41820068 */  beq-     UNDEF_800b3690;

                         addi     r11, r7, 0x368;
                         li       r0, PLAYER_COUNT;
                         mtctr    r0;

L_FUN_800B3600_InfoLoopStart:;
                         lbz      r0, 0x19(r11);
                         cmpwi    r0, 0;
                         beq-     L_FUN_800B3600_InfoLoopCond;

                         lwz      r0, 0x0(r11);
                         cmpw     r4, r0;
                         beqlr-;

L_FUN_800B3600_InfoLoopCond:;
                         addi     r11, r11, 0x23C;
                         bdnz+    L_FUN_800B3600_InfoLoopStart;

UNDEF_800b3690:;
                         lis      r8, m_instance__7dInfo_c@ha;
                         lwz      r8, m_instance__7dInfo_c@l(r8);
/* 800B3690 2C040001 */  cmpwi    r4, 1;
/* 800B3698 40820014 */  bne-     UNDEF_800b36ac;

/* 800B369C 7CC81A14 */  add      r6, r8, r3;
                         cmpwi    r3, 4;
                         blt-     L_FUN_800B3600_0xB56_NoAdjust;
                         addi     r6, r6, ADJUST_dInfo_c_mEx0xB56;
L_FUN_800B3600_0xB56_NoAdjust:;
/* 800B36A0 88060B56 */  lbz      r0, 0xB56(r6);
/* 800B36A4 2C000000 */  cmpwi    r0, 0;
/* 800B36A8 4C820020 */  bnelr-;

UNDEF_800b36ac:;
/* 800B36AC 2C070000 */  cmpwi    r7, 0;
/* 800B36B0 4D820020 */  beqlr-;
/* 800B36B4 1C030016 */  mulli    r0, r3, 22;
/* 800B36B8 7C080214 */  add      r0, r8, r0;
/* 800B36BC 7CC02214 */  add      r6, r0, r4;
                         cmpwi    r3, 4;
                         blt-     L_FUN_800B3600_0xAFE_NoAdjust;
                         addi     r6, r6, ADJUST_dInfo_c_mEx0xAFE;
L_FUN_800B3600_0xAFE_NoAdjust:;
/* 800B36C0 88060AFE */  lbz      r0, 0xAFE(r6);
/* 800B36C4 2C000000 */  cmpwi    r0, 0;
/* 800B36C8 4C820020 */  bnelr-;
/* 800B36CC 1C03023C */  mulli    r0, r3, 572;
/* 800B36D0 7CC70214 */  add      r6, r7, r0;
/* 800B36D4 88060381 */  lbz      r0, 897(r6);
/* 800B36D8 2C000000 */  cmpwi    r0, 0;
/* 800B36DC 41820028 */  beq-     UNDEF_800b3704;
/* 800B36E0 80060368 */  lwz      r0, 872(r6);
/* 800B36E4 7C040000 */  cmpw     r4, r0;
/* 800B36E8 4C820020 */  bnelr-;
/* 800B36EC 80660370 */  lwz      r3, 880(r6);
/* 800B36F0 38000000 */  li       r0, 0;
/* 800B36F4 9066036C */  stw      r3, 876(r6);
/* 800B36F8 9006037C */  stw      r0, 892(r6);
/* 800B36FC 4E800020 */  blr;
UNDEF_800b3704:;
/* 800B3704 7CE33B78 */  mr       r3, r7;
/* 800B3708 7D244B78 */  mr       r4, r9;
/* 800B370C 480A3BD4 */  b        UNDEF_801572e0;
/* 800B3710 4E800020 */  blr;
  // clang-format on
);

[[address(0x800B3B50)]]
bool isGameStop(u32 flag);

/* @unofficial */
[[address(0x800B3B60)]]
void setNumInTextBox(int* value, int* maxChars, LytTextBox_c* textBox, int itoaType);

[[address(0x800B4780)]]
void Player1upColor(LytTextBox_c* textBox, int player)
{
    static constinit const nw4r::ut::Color l_PLY_COLOR_0[] = {
      "#FFFF32", // Mario
      "#D2FF00", // Luigi
      "#D2F0FF", // Blue Toad
      "#FFFF64", // Yellow Toad
      "#FFBEFF", // Toadette
      "#FFFFFF", // Player 5
      "#FFFFFF", // Player 6
      "#FFFFFF", // Player 7
    };

    static constinit const nw4r::ut::Color l_PLY_COLOR_2[] = {
      "#E60000", // Mario
      "#197D0A", // Luigi
      "#1E2DF0", // Blue Toad
      "#FFBE00", // Yellow Toad
      "#D676D6", // Toadette
      "#FFFFFF", // Player 5
      "#FFFFFF", // Player 6
      "#FFFFFF", // Player 7
    };

    textBox->SetVtxColor(0, l_PLY_COLOR_0[player]);
    textBox->SetVtxColor(2, l_PLY_COLOR_2[player]);
}

} // namespace dGameCom