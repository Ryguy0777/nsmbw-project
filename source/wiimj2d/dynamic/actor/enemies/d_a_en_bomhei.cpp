// d_a_en_bomhei.cpp
// NSMBW: 0x809C8D30 - 0x809CDE70

#include <dynamic/actor/bases/d_a_player_manager.h>

[[address(0x809C9DD0)]]
void UNDEF_809C9DD0() ASM_METHOD(
  // clang-format off
/* 809C9DD0 9421FFC0 */  stwu     r1, -64(r1);
/* 809C9DD4 7C0802A6 */  mflr     r0;
/* 809C9DD8 90010044 */  stw      r0, 68(r1);
/* 809C9DDC 39610040 */  addi     r11, r1, 64;
/* 809C9DE0 4B91327D */  bl       UNDEF_802dd05c;
/* 809C9DE4 3CC080AD */  lis      r6, UNDEF_80ace5dc@ha;
/* 809C9DE8 3FE080B1 */  lis      r31, UNDEF_80b12a38@ha;
/* 809C9DEC C0240058 */  lfs      f1, 88(r4);
/* 809C9DF0 7C7C1B78 */  mr       r28, r3;
/* 809C9DF4 C006E5DC */  lfs      f0, UNDEF_80ace5dc@l(r6);
/* 809C9DF8 7C9D2378 */  mr       r29, r4;
/* 809C9DFC 83450004 */  lwz      r26, 4(r5);
/* 809C9E00 7CBE2B78 */  mr       r30, r5;
/* 809C9E04 FC010040 */  fcmpo    cr0, f1, f0;
/* 809C9E08 3BFF2A38 */  addi     r31, r31, UNDEF_80b12a38@l;
/* 809C9E0C 4C411382 */  cror     2, 1, 2;
/* 809C9E10 7C000026 */  mfcr     r0;
/* 809C9E14 819A0060 */  lwz      r12, 96(r26);
/* 809C9E18 54001FFE */  extrwi   r0, r0, 1, 2;
/* 809C9E1C 7F43D378 */  mr       r3, r26;
/* 809C9E20 7C000034 */  cntlzw   r0, r0;
/* 809C9E24 818C006C */  lwz      r12, 108(r12);
/* 809C9E28 5419DE3E */  extrwi   r25, r0, 8, 19;
/* 809C9E2C 7D8903A6 */  mtctr    r12;
/* 809C9E30 4E800421 */  bctrl;
/* 809C9E34 8B630000 */  lbz      r27, 0(r3);
/* 809C9E38 7F83E378 */  mr       r3, r28;
/* 809C9E3C 7FA4EB78 */  mr       r4, r29;
/* 809C9E40 7FC5F378 */  mr       r5, r30;
/* 809C9E44 38C00000 */  li       r6, 0;
/* 809C9E48 4B6CC659 */  bl       UNDEF_800964a0; // Enfumi_check__5dEn_cFP5dCc_cP5dCc_ci
/* 809C9E4C 2C030000 */  cmpwi    r3, 0;
/* 809C9E50 40820140 */  bne-     UNDEF_809c9f90;
/* 809C9E54 819C0394 */  lwz      r12, 916(r28);
/* 809C9E58 387C0394 */  addi     r3, r28, 916;
/* 809C9E5C 818C0028 */  lwz      r12, 40(r12);
/* 809C9E60 7D8903A6 */  mtctr    r12;
/* 809C9E64 4E800421 */  bctrl;
/* 809C9E68 81830000 */  lwz      r12, 0(r3);
/* 809C9E6C 389F0050 */  addi     r4, r31, 80;
/* 809C9E70 818C0014 */  lwz      r12, 20(r12);
/* 809C9E74 7D8903A6 */  mtctr    r12;
/* 809C9E78 4E800421 */  bctrl;
/* 809C9E7C 7C0300D0 */  neg      r0, r3;
/* 809C9E80 7C001B78 */  or       r0, r0, r3;
/* 809C9E84 54000FFF */  srwi.    r0, r0, 31;
/* 809C9E88 40820074 */  bne-     UNDEF_809c9efc;
/* 809C9E8C 819C0394 */  lwz      r12, 916(r28);
/* 809C9E90 387C0394 */  addi     r3, r28, 916;
/* 809C9E94 818C0028 */  lwz      r12, 40(r12);
/* 809C9E98 7D8903A6 */  mtctr    r12;
/* 809C9E9C 4E800421 */  bctrl;
/* 809C9EA0 81830000 */  lwz      r12, 0(r3);
/* 809C9EA4 389F00D0 */  addi     r4, r31, 208;
/* 809C9EA8 818C0014 */  lwz      r12, 20(r12);
/* 809C9EAC 7D8903A6 */  mtctr    r12;
/* 809C9EB0 4E800421 */  bctrl;
/* 809C9EB4 7C0300D0 */  neg      r0, r3;
/* 809C9EB8 7C001B78 */  or       r0, r0, r3;
/* 809C9EBC 54000FFF */  srwi.    r0, r0, 31;
/* 809C9EC0 4082003C */  bne-     UNDEF_809c9efc;
/* 809C9EC4 819C0394 */  lwz      r12, 916(r28);
/* 809C9EC8 387C0394 */  addi     r3, r28, 916;
/* 809C9ECC 818C0028 */  lwz      r12, 40(r12);
/* 809C9ED0 7D8903A6 */  mtctr    r12;
/* 809C9ED4 4E800421 */  bctrl;
/* 809C9ED8 81830000 */  lwz      r12, 0(r3);
/* 809C9EDC 389F0110 */  addi     r4, r31, 272;
/* 809C9EE0 818C0014 */  lwz      r12, 20(r12);
/* 809C9EE4 7D8903A6 */  mtctr    r12;
/* 809C9EE8 4E800421 */  bctrl;
/* 809C9EEC 7C0300D0 */  neg      r0, r3;
/* 809C9EF0 7C001B78 */  or       r0, r0, r3;
/* 809C9EF4 54000FFF */  srwi.    r0, r0, 31;
/* 809C9EF8 41820084 */  beq-     UNDEF_809c9f7c;
UNDEF_809c9efc:;
/* 809C9EFC          */  cmplwi   r27, PLAYER_COUNT;
/* 809C9F00 408000D4 */  bge-     UNDEF_809c9fd4;

                         // Damage cooldown
                         mr       r3, r28;
                         mr       r4, r27;
                         li       r5, 32;
                         bl       setCollTimer__5dEn_cFiUc;

/* 809C9F08 9B3C0348 */  stb      r25, 840(r28);
/* 809C9F10 7F84E378 */  mr       r4, r28;
/* 809C9F14 9B7C038D */  stb      r27, 909(r28);
/* 809C9F1C 38610010 */  addi     r3, r1, 16;
/* 809C9F24 9B7C0284 */  stb      r27, 644(r28);
/* 809C9F28 4B6A2FA9 */  bl       UNDEF_8006ced0; // getCenterPos__12dBaseActor_cCFv
/* 809C9F2C 7F63DB78 */  mr       r3, r27;
/* 809C9F30 4B69F601 */  bl       UNDEF_80069530; // getRemotePlayer__6dAudioFi
/* 809C9F34 3C808043 */  lis      r4, UNDEF_8042a03c@ha;
/* 809C9F38 7C7B1B78 */  mr       r27, r3;
/* 809C9F3C 83A4A03C */  lwz      r29, UNDEF_8042a03c@l(r4);
/* 809C9F40 38610008 */  addi     r3, r1, 8;
/* 809C9F44 38810010 */  addi     r4, r1, 16;
/* 809C9F48 4B6A0569 */  bl       UNDEF_8006a4b0; // cvtSndObjctPos__6dAudioFRC7mVec3_c
/* 809C9F4C 7FA3EB78 */  mr       r3, r29;
/* 809C9F50 7F66DB78 */  mr       r6, r27;
/* 809C9F54 38A10008 */  addi     r5, r1, 8;
/* 809C9F58 38800195 */  li       r4, 405;
/* 809C9F5C 4B7CE0E5 */  bl       UNDEF_80198040; // startSound__14SndObjctCmnEmyFUlRCQ34nw4r4math4VEC2Ul
/* 809C9F60 819C0060 */  lwz      r12, 96(r28);
/* 809C9F64 7F83E378 */  mr       r3, r28;
/* 809C9F68 389F0110 */  addi     r4, r31, 272;
/* 809C9F6C 818C00D4 */  lwz      r12, 212(r12);
/* 809C9F70 7D8903A6 */  mtctr    r12;
/* 809C9F74 4E800421 */  bctrl;
/* 809C9F78 4800005C */  b        UNDEF_809c9fd4;
UNDEF_809c9f7c:;
/* 809C9F7C 7F83E378 */  mr       r3, r28;
/* 809C9F80 7FA4EB78 */  mr       r4, r29;
/* 809C9F84 7FC5F378 */  mr       r5, r30;
/* 809C9F88 4B6CBCF9 */  bl       UNDEF_80095c80; // Normal_VsYoshiHitCheck__5dEn_cFP5dCc_cP5dCc_c
/* 809C9F8C 48000048 */  b        UNDEF_809c9fd4;
UNDEF_809c9f90:;
/* 809C9F90 819C0394 */  lwz      r12, 916(r28);
/* 809C9F94 387C0394 */  addi     r3, r28, 916;
/* 809C9F98 818C0028 */  lwz      r12, 40(r12);
/* 809C9F9C 7D8903A6 */  mtctr    r12;
/* 809C9FA0 4E800421 */  bctrl;
/* 809C9FA4 81830000 */  lwz      r12, 0(r3);
/* 809C9FA8 389F01D0 */  addi     r4, r31, 464;
/* 809C9FAC 818C0014 */  lwz      r12, 20(r12);
/* 809C9FB0 7D8903A6 */  mtctr    r12;
/* 809C9FB4 4E800421 */  bctrl;
/* 809C9FB8 7C0300D0 */  neg      r0, r3;
/* 809C9FBC 7C001B78 */  or       r0, r0, r3;
/* 809C9FC0 54000FFF */  srwi.    r0, r0, 31;
/* 809C9FC4 40820010 */  bne-     UNDEF_809c9fd4;
/* 809C9FC8 7F83E378 */  mr       r3, r28;
/* 809C9FCC 7F44D378 */  mr       r4, r26;
/* 809C9FD0 4B6D6FE1 */  bl       UNDEF_800a0fb0; // setDeathInfo_YoshiFumi__5dEn_cFP8dActor_c
UNDEF_809c9fd4:;
/* 809C9FD4 39610040 */  addi     r11, r1, 64;
/* 809C9FD8 4B9130D1 */  bl       UNDEF_802dd0a8;
/* 809C9FDC 80010044 */  lwz      r0, 68(r1);
/* 809C9FE0 7C0803A6 */  mtlr     r0;
/* 809C9FE4 38210040 */  addi     r1, r1, 64;
/* 809C9FE8 4E800020 */  blr;
  // clang-format on
);