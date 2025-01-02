// d_a_wm_SubPlayer.cpp
// NSMBW d_bases.text: 0x808E8AA0 - 0x808EF8D0

#include "d_a_wm_SubPlayer.h"

#include <dynamic/d_bases/d_a_wm_player.h>
#include <dynamic/d_player_model_manager.h>

dPyMdlMng_c::ModelType_e l_SUBPLAYER_MODEL_LIST[] = {
  dPyMdlMng_c::ModelType_e::MODEL_MARIO,       dPyMdlMng_c::ModelType_e::MODEL_LUIGI,
  dPyMdlMng_c::ModelType_e::MODEL_YELLOW_TOAD, dPyMdlMng_c::ModelType_e::MODEL_BLUE_TOAD,
  dPyMdlMng_c::ModelType_e::MODEL_MARIO,       dPyMdlMng_c::ModelType_e::MODEL_MARIO,
  dPyMdlMng_c::ModelType_e::MODEL_MARIO,       dPyMdlMng_c::ModelType_e::MODEL_MARIO,
};

[[address(0x808EB7D0)]]
void daWmSubPlayer_c::loadModel() ASM_METHOD(
  // clang-format off
/* 808EB7D0 9421FFE0 */  stwu     r1, -32(r1);
/* 808EB7D4 7C0802A6 */  mflr     r0;
/* 808EB7D8 3CA08035 */  lis      r5, mPlayerType__9daPyMng_c@ha;
/* 808EB7DC 3C808035 */  lis      r4, mPlayerMode__9daPyMng_c@ha;
/* 808EB7E0 90010024 */  stw      r0, 36(r1);
/* 808EB7E4 38A55160 */  addi     r5, r5, mPlayerType__9daPyMng_c@l;
/* 808EB7E8 38845170 */  addi     r4, r4, mPlayerMode__9daPyMng_c@l;
/* 808EB7EC 93E1001C */  stw      r31, 28(r1);
/* 808EB7F0 93C10018 */  stw      r30, 24(r1);
/* 808EB7F4 93A10014 */  stw      r29, 20(r1);
/* 808EB7F8 93810010 */  stw      r28, 16(r1);
/* 808EB7FC 7C7C1B78 */  mr       r28, r3;
/* 808EB800 80030004 */  lwz      r0, 4(r3);
/* 808EB804 3860000C */  li       r3, 12;
/* 808EB808 541D16BA */  clrlslwi r29, r0, 28, 2;
/* 808EB80C 541F073E */  clrlwi   r31, r0, 28;
/* 808EB810 7CA5E82E */  lwzx     r5, r5, r29;
/* 808EB814 54A0103A */  slwi     r0, r5, 2;
/* 808EB818 7FC4002E */  lwzx     r30, r4, r0;
/* 808EB81C 4B9CDB35 */  bl       UNDEF_802b9350;
/* 808EB820 2C030000 */  cmpwi    r3, 0;
/* 808EB824 41820014 */  beq-     UNDEF_808eb838;
/* 808EB828          */  lis      r4, l_SUBPLAYER_MODEL_LIST@ha;
/* 808EB82C          */  addi     r4, r4, l_SUBPLAYER_MODEL_LIST@l;
/* 808EB830 7C84E82E */  lwzx     r4, r4, r29;
/* 808EB834 4B7EB57D */  bl       UNDEF_800d6db0;
UNDEF_808eb838:;
/* 808EB838 907C01CC */  stw      r3, 460(r28);
/* 808EB83C 7FE4FB78 */  mr       r4, r31;
/* 808EB840 57C5063E */  clrlwi   r5, r30, 24;
/* 808EB844 38C00001 */  li       r6, 1;
/* 808EB848 4B7EB699 */  bl       UNDEF_800d6ee0;
/* 808EB84C 38000015 */  li       r0, 21;
/* 808EB850 901C0290 */  stw      r0, 656(r28);
/* 808EB854 38600054 */  li       r3, 84;
/* 808EB858 4B9CDB39 */  bl       UNDEF_802b9390;
/* 808EB85C 907C028C */  stw      r3, 652(r28);
/* 808EB860 3BA00000 */  li       r29, 0;
/* 808EB864 3BC00000 */  li       r30, 0;
/* 808EB868 4800001C */  b        UNDEF_808eb884;
UNDEF_808eb86c:;
/* 808EB86C 3860000C */  li       r3, 12;
/* 808EB870 4B9CDAE1 */  bl       UNDEF_802b9350;
/* 808EB874 809C028C */  lwz      r4, 652(r28);
/* 808EB878 3BBD0001 */  addi     r29, r29, 1;
/* 808EB87C 7C64F12E */  stwx     r3, r4, r30;
/* 808EB880 3BDE0004 */  addi     r30, r30, 4;
UNDEF_808eb884:;
/* 808EB884 801C0290 */  lwz      r0, 656(r28);
/* 808EB888 7C1D0000 */  cmpw     r29, r0;
/* 808EB88C 4180FFE0 */  blt+     UNDEF_808eb86c;
/* 808EB890 3C808098 */  lis      r4, UNDEF_80985b28@ha;
/* 808EB894 3CA08098 */  lis      r5, UNDEF_80985b38@ha;
/* 808EB898 38845B28 */  addi     r4, r4, UNDEF_80985b28@l;
/* 808EB89C 7F83E378 */  mr       r3, r28;
/* 808EB8A0 7C862378 */  mr       r6, r4;
/* 808EB8A4 38A55B38 */  addi     r5, r5, UNDEF_80985b38@l;
/* 808EB8A8 38E00001 */  li       r7, 1;
/* 808EB8AC 4B80AF75 */  bl       UNDEF_800f6820;
/* 808EB8B0 80010024 */  lwz      r0, 36(r1);
/* 808EB8B4 83E1001C */  lwz      r31, 28(r1);
/* 808EB8B8 83C10018 */  lwz      r30, 24(r1);
/* 808EB8BC 83A10014 */  lwz      r29, 20(r1);
/* 808EB8C0 83810010 */  lwz      r28, 16(r1);
/* 808EB8C4 7C0803A6 */  mtlr     r0;
/* 808EB8C8 38210020 */  addi     r1, r1, 32;
/* 808EB8CC 4E800020 */  blr;
  // clang-format on
);

[[address(0x808EE0C0)]]
s32 daWmSubPlayer_c::getPlayerOrder()
{
    s32 order = 1;
    s32 playerNo = getPlayerNo();
    dWmPlayerBase_c* player = daWmPlayer_c::ms_instance->mNextPlayer;

    for (s32 i = 0; i < playerNo; i++) {
        if (player->mVisible) {
            order++;
        }

        player = player->mNextPlayer;
    }

    return order;
}

[[address(0x808EE950)]]
int daWmSubPlayer_c::getSubPlayerNum();

[[address(0x808EEA00)]]
s32 daWmSubPlayer_c::UNDEF_808EEA00(int playerOrder)
{
    int subPlayerNum = getSubPlayerNum();
    if (subPlayerNum == 0) {
        return 0;
    }

    static constexpr s32 UNK_TABLE[] = {0, 2, 5, 5, 5, 5, 5, 5};

    return playerOrder + UNK_TABLE[subPlayerNum - 1];
}

[[address(0x808EF2B0)]]
bool daWmSubPlayer_c::isPlayerType(daPyMng_c::PlayerType_e playerType)
{
    return daPyMng_c::DEFAULT_PLAYER_ORDER[getPlayerNo()] == playerType;
}