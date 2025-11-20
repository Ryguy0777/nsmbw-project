// d_a_en_remocon_cannon.cpp
// NSMBW .text: 0x80A94D90 - 0x80A97B30

#include "d_a_en_remocon_cannon.h"
#include "d_player/d_a_player.h"
#include "d_system/d_game_common.h"
#include "machine/m_3d_fanm.h"
#include "sound/SndID.h"

float remoCannonGuideColorSet(int playerNo)
{
    return static_cast<float>(playerNo);
}

[[address(0x80A950A0)]]
void daEnRemoconCannon_c::setupGuide(dRemoconCannonGuide_c** guide, int mPlayerNo) ASM_METHOD(
  // clang-format off
/* 80A950A0 9421FFD0 */  stwu     r1, -48(r1);
/* 80A950A4 7C0802A6 */  mflr     r0;
/* 80A950A8 90010034 */  stw      r0, 52(r1);
/* 80A950AC DBE10020 */  stfd     f31, 32(r1);
/* 80A950B0 F3E10028 */  .long    0xF3E10028; // psq_st   f31, 40(r1), 0, 0;
/* 80A950B4 93E1001C */  stw      r31, 28(r1);
/* 80A950B8 3FE080AD */  lis      r31, UNDEF_80ad4018@ha;
/* 80A950BC 3BFF4018 */  addi     r31, r31, UNDEF_80ad4018@l;
/* 80A950C0 93C10018 */  stw      r30, 24(r1);
/* 80A950C4 7C7E1B78 */  mr       r30, r3;
/* 80A950C8 7C832378 */  mr       r3, r4;
/* 80A950CC 4B5CA835 */  bl       UNDEF_8005f900;
/* 80A950D0 2C030000 */  cmpwi    r3, 0;
/* 80A950D4 C3FF0028 */  lfs      f31, 40(r31);
/* 80A950D8 41820084 */  beq-     UNDEF_80a9515c;
/* 80A950DC          */  lwz      r3, 5332(r3);
                         bl       remoCannonGuideColorSet__Fi;
                         fmr      f31, f0;
/* 80A9511C 387E0080 */  addi     r3, r30, 128;
/* 80A95120 38800001 */  li       r4, 1;
/* 80A95124 38A00000 */  li       r5, 0;
/* 80A95128 4B6D1F59 */  bl       UNDEF_80167080;
/* 80A9512C C03F0028 */  lfs      f1, 40(r31);
/* 80A95130 387E0004 */  addi     r3, r30, 4;
/* 80A95134 389E0080 */  addi     r4, r30, 128;
/* 80A95138 4B6D4F89 */  bl       UNDEF_8016a0c0;
/* 80A9513C FC20F890 */  fmr      f1, f31;
/* 80A95140 387E0080 */  addi     r3, r30, 128;
/* 80A95144 38800000 */  li       r4, 0;
/* 80A95148 4B6D1EE9 */  bl       UNDEF_80167030;
/* 80A9514C C03F0028 */  lfs      f1, 40(r31);
/* 80A95150 387E0080 */  addi     r3, r30, 128;
/* 80A95154 38800000 */  li       r4, 0;
/* 80A95158 4B6D1EF9 */  bl       UNDEF_80167050;
UNDEF_80a9515c:;
/* 80A9515C 3C8080B0 */  lis      r4, UNDEF_80b05864@ha;
/* 80A95160 7FC3F378 */  mr       r3, r30;
/* 80A95164 38845864 */  addi     r4, r4, UNDEF_80b05864@l;
/* 80A95168 4B7A5089 */  bl       UNDEF_8023a1f0;
/* 80A9516C 90610008 */  stw      r3, 8(r1);
/* 80A95170 387E0044 */  addi     r3, r30, 68;
/* 80A95174 389E0004 */  addi     r4, r30, 4;
/* 80A95178 38A10008 */  addi     r5, r1, 8;
/* 80A9517C 38C00001 */  li       r6, 1;
/* 80A95180 4B6D01B1 */  bl       UNDEF_80165330;
/* 80A95184 C03F0024 */  lfs      f1, 36(r31);
/* 80A95188 387E0044 */  addi     r3, r30, 68;
/* 80A9518C 4B6D3095 */  bl       UNDEF_80168220;
/* 80A95190 C03F0028 */  lfs      f1, 40(r31);
/* 80A95194 387E0004 */  addi     r3, r30, 4;
/* 80A95198 389E0044 */  addi     r4, r30, 68;
/* 80A9519C 4B6D4F25 */  bl       UNDEF_8016a0c0;
/* 80A951A0 80010034 */  lwz      r0, 52(r1);
/* 80A951A4 E3E10028 */  .long    0xE3E10028; // psq_l    f31, 40(r1), 0, 0;
/* 80A951A8 CBE10020 */  lfd      f31, 32(r1);
/* 80A951AC 83E1001C */  lwz      r31, 28(r1);
/* 80A951B0 83C10018 */  lwz      r30, 24(r1);
/* 80A951B4 7C0803A6 */  mtlr     r0;
/* 80A951B8 38210030 */  addi     r1, r1, 48;
/* 80A951BC 4E800020 */  blr      ;
  // clang-format on
);
[[address(0x80A95890)]]
void daEnRemoconCannon_c::setBodyColor()
{
    if (mPlayerNo > -1) {
        dAcPy_c* player = daPyMng_c::getPlayer(mPlayerNo);
        float frame = 0.0;
        if (player != nullptr) {
            frame = static_cast<float>(player->mPlayerType + 1);
            mAnmTexPat.setFrame(frame, 0);
            mAnmTexPat.setRate(0.0, 0);
            player->playSound(SndID::SE_OBJ_RC_CONTROL_ON, 0);
        }
        setupGuide(&mGuide, mPlayerNo);
        mHasPlayer = true;
        mPlayerNo2 = mPlayerNo;
        dGameCom::FUN_800B3600(mPlayerNo, 0xF);
    }
}

[[address(0x80A964E0)]]
bool daEnRemoconCannon_c::UNDEF_80a964e0(short target)
{
    return dGameCom::CalculateTiltShoulder(&mTargetAngle, target, 400, mPlayerNo, 0x3520);
}