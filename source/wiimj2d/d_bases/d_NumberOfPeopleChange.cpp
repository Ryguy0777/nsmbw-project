// d_NumberOfPeopleChange.cpp
// NSMBW d_bases.text: 0x8079F630 - 0x807A2CF0

#include "d_NumberOfPeopleChange.h"

#include "d_CharacterChangeIndicator.h"
#include "d_system/d_a_player_manager.h"
#include <d_bases/d_a_wm_2DPlayer.h>
#include <d_system/d_game_common.h>
#include <d_system/d_game_key_core.h>
#include <d_system/d_info.h>
#include <d_system/d_remocon_mng.h>
#include <d_system/d_scene.h>
#include <framework/f_base_profile.h>
#include <framework/f_sound_id.h>
#include <machine/m_pad.h>
#include <sound/SndAudioMgr.h>

[[address(0x8079F630)]]
dNumberOfPeopleChange_c* dNumberOfPeopleChange_c_classInit()
{
    dNumberOfPeopleChange_c* base = new dNumberOfPeopleChange_c();
    base->mRealPlayerCount = 4;
    return base;
}

[[address(0x8079F660)]]
dNumberOfPeopleChange_c::dNumberOfPeopleChange_c();

[[address(0x807A0060)]]
void dNumberOfPeopleChange_c::UNDEF_807A0060() ASM_METHOD(
  // clang-format off
/* 807A0060 9421FFD0 */  stwu     r1, -48(r1);
/* 807A0064 7C0802A6 */  mflr     r0;
/* 807A0068 90010034 */  stw      r0, 52(r1);
/* 807A006C 39610020 */  addi     r11, r1, 32;
/* 807A0070 DBE10020 */  stfd     f31, 32(r1);
/* 807A0074 F3E10028 */  .long    0xF3E10028; // psq_st   f31, 40(r1), 0, 0;
/* 807A0078 4BB3CFED */  bl       UNDEF_802dd064;
/* 807A007C 3C808093 */  lis      r4, UNDEF_8093531c@ha;
/* 807A0080 7C7F1B78 */  mr       r31, r3;
/* 807A0084 C3E4531C */  lfs      f31, UNDEF_8093531c@l(r4);
                         // Patch to include Mario
/* 807A0088          */  addi     r28, r3, 0;
/* 807A008C          */  li       r27, 0;
/* 807A0090 3FC08093 */  lis      r30, UNDEF_80935320@ha;
UNDEF_807a0094:;
/* 807A0094 83BC00A4 */  lwz      r29, 164(r28);
/* 807A0098 38800000 */  li       r4, 0;
/* 807A009C 387D0070 */  addi     r3, r29, 112;
/* 807A00A0 4B929661 */  bl       UNDEF_800c9700;
/* 807A00A4 2C030000 */  cmpwi    r3, 0;
/* 807A00A8 41820014 */  beq-     UNDEF_807a00bc;
/* 807A00AC 807D01F4 */  lwz      r3, 500(r29);
/* 807A00B0 80630000 */  lwz      r3, 0(r3);
/* 807A00B4 C0030008 */  lfs      f0, 8(r3);
/* 807A00B8 48000008 */  b        UNDEF_807a00c0;
UNDEF_807a00bc:;
/* 807A00BC C01E5320 */  lfs      f0, UNDEF_80935320@l(r30);
UNDEF_807a00c0:;
/* 807A00C0 FC00F840 */  fcmpo    cr0, f0, f31;
/* 807A00C4 4C411382 */  cror     2, 1, 2;
/* 807A00C8 40820040 */  bne-     UNDEF_807a0108;
/* 807A00CC 5760103A */  slwi     r0, r27, 2;
/* 807A00D0 38800000 */  li       r4, 0;
/* 807A00D4 7C7F0214 */  add      r3, r31, r0;
/* 807A00D8 83A300A4 */  lwz      r29, 164(r3);
/* 807A00DC 387D0070 */  addi     r3, r29, 112;
/* 807A00E0 4B929621 */  bl       UNDEF_800c9700;
/* 807A00E4 2C030000 */  cmpwi    r3, 0;
/* 807A00E8 41820014 */  beq-     UNDEF_807a00fc;
/* 807A00EC 807D01F4 */  lwz      r3, 500(r29);
/* 807A00F0 80630000 */  lwz      r3, 0(r3);
/* 807A00F4 C3E30008 */  lfs      f31, 8(r3);
/* 807A00F8 48000020 */  b        UNDEF_807a0118;
UNDEF_807a00fc:;
/* 807A00FC 3C608093 */  lis      r3, UNDEF_80935320@ha;
/* 807A0100 C3E35320 */  lfs      f31, UNDEF_80935320@l(r3);
/* 807A0104 48000014 */  b        UNDEF_807a0118;
UNDEF_807a0108:;
/* 807A0108 3B7B0001 */  addi     r27, r27, 1;
/* 807A010C 3B9C0004 */  addi     r28, r28, 4;
/* 807A0110 2C1B0004 */  cmpwi    r27, 4;
/* 807A0114 4180FF80 */  blt+     UNDEF_807a0094;
UNDEF_807a0118:;
/* 807A0118 807F0078 */  lwz      r3, 120(r31);
/* 807A011C D3E302EC */  stfs     f31, 748(r3);
/* 807A0120 807F0088 */  lwz      r3, 136(r31);
/* 807A0124 D3E302B4 */  stfs     f31, 692(r3);
/* 807A0128 807F007C */  lwz      r3, 124(r31);
/* 807A012C D3E302EC */  stfs     f31, 748(r3);
/* 807A0130 807F008C */  lwz      r3, 140(r31);
/* 807A0134 D3E302B4 */  stfs     f31, 692(r3);
/* 807A0138 807F0080 */  lwz      r3, 128(r31);
/* 807A013C D3E302EC */  stfs     f31, 748(r3);
/* 807A0140 807F0090 */  lwz      r3, 144(r31);
/* 807A0144 D3E302B4 */  stfs     f31, 692(r3);
/* 807A0148 E3E10028 */  .long    0xE3E10028; // psq_l    f31, 40(r1), 0, 0;
/* 807A014C CBE10020 */  lfd      f31, 32(r1);
/* 807A0150 39610020 */  addi     r11, r1, 32;
/* 807A0154 4BB3CF5D */  bl       UNDEF_802dd0b0;
/* 807A0158 80010034 */  lwz      r0, 52(r1);
/* 807A015C 7C0803A6 */  mtlr     r0;
/* 807A0160 38210030 */  addi     r1, r1, 48;
/* 807A0164 4E800020 */  blr;
  // clang-format on
);

[[address(0x807A0170)]]
void dNumberOfPeopleChange_c::UNDEF_807A0170() ASM_METHOD(
  // clang-format off
/* 807A0170 9421FED0 */  stwu     r1, -304(r1);
/* 807A0174 7C0802A6 */  mflr     r0;
/* 807A0178 90010134 */  stw      r0, 308(r1);
/* 807A017C 39610130 */  addi     r11, r1, 304;
/* 807A0180 4BB3CEB1 */  bl       UNDEF_802dd030;
/* 807A0184 3CC08093 */  lis      r6, UNDEF_80935324@ha;
/* 807A0188 3CA08093 */  lis      r5, UNDEF_8093531c@ha;
/* 807A018C          */  li       r0, 4;
/* 807A0190          */  mr       r4, r3;
/* 807A0194 C0A65324 */  lfs      f5, UNDEF_80935324@l(r6);
/* 807A0198 C085531C */  lfs      f4, UNDEF_8093531c@l(r5);
/* 807A019C 7C0903A6 */  mtctr    r0;
UNDEF_807a01a0:;
/* 807A01A0 800406B4 */  lwz      r0, 1716(r4);
/* 807A01A4 2C00000A */  cmpwi    r0, 10;
/* 807A01A8 41820270 */  beq-     UNDEF_807a0418;
/* 807A01AC 5400103A */  slwi     r0, r0, 2;
/* 807A01B0 80C40074 */  lwz      r6, 116(r4);
/* 807A01B4 7CA30214 */  add      r5, r3, r0;
/* 807A01B8 D0810018 */  stfs     f4, 24(r1);
/* 807A01BC 80A505DC */  lwz      r5, 1500(r5);
/* 807A01C0 81460264 */  lwz      r10, 612(r6);
/* 807A01C4 800500A0 */  lwz      r0, 160(r5);
/* 807A01C8 900100CC */  stw      r0, 204(r1);
/* 807A01CC 80050090 */  lwz      r0, 144(r5);
/* 807A01D0 900100BC */  stw      r0, 188(r1);
/* 807A01D4 81250084 */  lwz      r9, 132(r5);
/* 807A01D8 81050088 */  lwz      r8, 136(r5);
/* 807A01DC 80E5008C */  lwz      r7, 140(r5);
/* 807A01E0 80C50094 */  lwz      r6, 148(r5);
/* 807A01E4 80050098 */  lwz      r0, 152(r5);
/* 807A01E8 81E5009C */  lwz      r15, 156(r5);
/* 807A01EC 820500A4 */  lwz      r16, 164(r5);
/* 807A01F0 822500A8 */  lwz      r17, 168(r5);
/* 807A01F4 824500AC */  lwz      r18, 172(r5);
/* 807A01F8 826500B0 */  lwz      r19, 176(r5);
/* 807A01FC C00100CC */  lfs      f0, 204(r1);
/* 807A0200 C06100BC */  lfs      f3, 188(r1);
/* 807A0204 D06A002C */  stfs     f3, 44(r10);
/* 807A0208 EC45002A */  fadds    f2, f5, f0;
/* 807A020C D04A0030 */  stfs     f2, 48(r10);
/* 807A0210 D08A0034 */  stfs     f4, 52(r10);
/* 807A0214 80A40094 */  lwz      r5, 148(r4);
/* 807A0218 912100B0 */  stw      r9, 176(r1);
/* 807A021C 80A50244 */  lwz      r5, 580(r5);
/* 807A0220 900100C4 */  stw      r0, 196(r1);
/* 807A0224 C02100B0 */  lfs      f1, 176(r1);
/* 807A0228 D065002C */  stfs     f3, 44(r5);
/* 807A022C C00100C4 */  lfs      f0, 196(r1);
/* 807A0230 D0450030 */  stfs     f2, 48(r5);
/* 807A0234 D0850034 */  stfs     f4, 52(r5);
/* 807A0238 80A400A4 */  lwz      r5, 164(r4);
/* 807A023C 90C100C0 */  stw      r6, 192(r1);
/* 807A0240 80A50208 */  lwz      r5, 520(r5);
/* 807A0244 910100B4 */  stw      r8, 180(r1);
/* 807A0248 D065002C */  stfs     f3, 44(r5);
/* 807A024C D0450030 */  stfs     f2, 48(r5);
/* 807A0250 D0850034 */  stfs     f4, 52(r5);
/* 807A0254 D0250044 */  stfs     f1, 68(r5);
/* 807A0258 D0050048 */  stfs     f0, 72(r5);
/* 807A025C 80A40074 */  lwz      r5, 116(r4);
/* 807A0260 90E100B8 */  stw      r7, 184(r1);
/* 807A0264 80C50270 */  lwz      r6, 624(r5);
/* 807A0268 83C50268 */  lwz      r30, 616(r5);
/* 807A026C 80A60090 */  lwz      r5, 144(r6);
/* 807A0270 90A1002C */  stw      r5, 44(r1);
/* 807A0274 800600A0 */  lwz      r0, 160(r6);
/* 807A0278 9001003C */  stw      r0, 60(r1);
/* 807A027C 82860084 */  lwz      r20, 132(r6);
/* 807A0280 82A60088 */  lwz      r21, 136(r6);
/* 807A0284 82C6008C */  lwz      r22, 140(r6);
/* 807A0288 82E60094 */  lwz      r23, 148(r6);
/* 807A028C 83060098 */  lwz      r24, 152(r6);
/* 807A0290 8326009C */  lwz      r25, 156(r6);
/* 807A0294 834600A4 */  lwz      r26, 164(r6);
/* 807A0298 836600A8 */  lwz      r27, 168(r6);
/* 807A029C 838600AC */  lwz      r28, 172(r6);
/* 807A02A0 83A600B0 */  lwz      r29, 176(r6);
/* 807A02A4 83FE0084 */  lwz      r31, 132(r30);
/* 807A02A8 819E0088 */  lwz      r12, 136(r30);
/* 807A02AC 817E008C */  lwz      r11, 140(r30);
/* 807A02B0 815E0090 */  lwz      r10, 144(r30);
/* 807A02B4 813E0094 */  lwz      r9, 148(r30);
/* 807A02B8 811E0098 */  lwz      r8, 152(r30);
/* 807A02BC 80FE009C */  lwz      r7, 156(r30);
/* 807A02C0 80DE00A0 */  lwz      r6, 160(r30);
/* 807A02C4 80BE00A4 */  lwz      r5, 164(r30);
/* 807A02C8 801E00A8 */  lwz      r0, 168(r30);
/* 807A02CC 81DE00AC */  lwz      r14, 172(r30);
/* 807A02D0 83DE00B0 */  lwz      r30, 176(r30);
/* 807A02D4 91E100C8 */  stw      r15, 200(r1);
/* 807A02D8 C021002C */  lfs      f1, 44(r1);
/* 807A02DC 920100D0 */  stw      r16, 208(r1);
/* 807A02E0 C001003C */  lfs      f0, 60(r1);
/* 807A02E4 922100D4 */  stw      r17, 212(r1);
/* 807A02E8 924100D8 */  stw      r18, 216(r1);
/* 807A02EC 926100DC */  stw      r19, 220(r1);
/* 807A02F0 92810020 */  stw      r20, 32(r1);
/* 807A02F4 92A10024 */  stw      r21, 36(r1);
/* 807A02F8 92C10028 */  stw      r22, 40(r1);
/* 807A02FC 92E10030 */  stw      r23, 48(r1);
/* 807A0300 93010034 */  stw      r24, 52(r1);
/* 807A0304 93210038 */  stw      r25, 56(r1);
/* 807A0308 93410040 */  stw      r26, 64(r1);
/* 807A030C 93610044 */  stw      r27, 68(r1);
/* 807A0310 93810048 */  stw      r28, 72(r1);
/* 807A0314 93A1004C */  stw      r29, 76(r1);
/* 807A0318 93E10050 */  stw      r31, 80(r1);
/* 807A031C 91810054 */  stw      r12, 84(r1);
/* 807A0320 91610058 */  stw      r11, 88(r1);
/* 807A0324 9141005C */  stw      r10, 92(r1);
/* 807A0328 91210060 */  stw      r9, 96(r1);
/* 807A032C 91010064 */  stw      r8, 100(r1);
/* 807A0330 90E10068 */  stw      r7, 104(r1);
/* 807A0334 90C1006C */  stw      r6, 108(r1);
/* 807A0338 90A10070 */  stw      r5, 112(r1);
/* 807A033C 90010074 */  stw      r0, 116(r1);
/* 807A0340 91C10078 */  stw      r14, 120(r1);
/* 807A0344 93C1007C */  stw      r30, 124(r1);
/* 807A0348 80A40084 */  lwz      r5, 132(r4);
/* 807A034C C0610050 */  lfs      f3, 80(r1);
/* 807A0350 80A50250 */  lwz      r5, 592(r5);
/* 807A0354 C0410064 */  lfs      f2, 100(r1);
/* 807A0358 D025002C */  stfs     f1, 44(r5);
/* 807A035C D0050030 */  stfs     f0, 48(r5);
/* 807A0360 D0850034 */  stfs     f4, 52(r5);
/* 807A0364 D0650044 */  stfs     f3, 68(r5);
/* 807A0368 D0450048 */  stfs     f2, 72(r5);
/* 807A036C 80C40074 */  lwz      r6, 116(r4);
/* 807A0370 80A40084 */  lwz      r5, 132(r4);
/* 807A0374 8206026C */  lwz      r16, 620(r6);
/* 807A0378 8225024C */  lwz      r17, 588(r5);
/* 807A037C 80100090 */  lwz      r0, 144(r16);
/* 807A0380 9001008C */  stw      r0, 140(r1);
/* 807A0384 81F00084 */  lwz      r15, 132(r16);
/* 807A0388 81D00088 */  lwz      r14, 136(r16);
/* 807A038C 8190008C */  lwz      r12, 140(r16);
/* 807A0390 81700094 */  lwz      r11, 148(r16);
/* 807A0394 81500098 */  lwz      r10, 152(r16);
/* 807A0398 8130009C */  lwz      r9, 156(r16);
/* 807A039C 80B000A0 */  lwz      r5, 160(r16);
/* 807A03A0 811000A4 */  lwz      r8, 164(r16);
/* 807A03A4 80F000A8 */  lwz      r7, 168(r16);
/* 807A03A8 80D000AC */  lwz      r6, 172(r16);
/* 807A03AC 801000B0 */  lwz      r0, 176(r16);
/* 807A03B0 C021008C */  lfs      f1, 140(r1);
/* 807A03B4 90A1009C */  stw      r5, 156(r1);
/* 807A03B8 C001009C */  lfs      f0, 156(r1);
/* 807A03BC D031002C */  stfs     f1, 44(r17);
/* 807A03C0 D0110030 */  stfs     f0, 48(r17);
/* 807A03C4 D0910034 */  stfs     f4, 52(r17);
/* 807A03C8 D0710044 */  stfs     f3, 68(r17);
/* 807A03CC D0510048 */  stfs     f2, 72(r17);
/* 807A03D0 80A40094 */  lwz      r5, 148(r4);
/* 807A03D4 D0610008 */  stfs     f3, 8(r1);
/* 807A03D8 80A50244 */  lwz      r5, 580(r5);
/* 807A03DC D041000C */  stfs     f2, 12(r1);
/* 807A03E0 D0650044 */  stfs     f3, 68(r5);
/* 807A03E4 91E10080 */  stw      r15, 128(r1);
/* 807A03E8 91C10084 */  stw      r14, 132(r1);
/* 807A03EC 91810088 */  stw      r12, 136(r1);
/* 807A03F0 91610090 */  stw      r11, 144(r1);
/* 807A03F4 91410094 */  stw      r10, 148(r1);
/* 807A03F8 91210098 */  stw      r9, 152(r1);
/* 807A03FC 910100A0 */  stw      r8, 160(r1);
/* 807A0400 90E100A4 */  stw      r7, 164(r1);
/* 807A0404 90C100A8 */  stw      r6, 168(r1);
/* 807A0408 900100AC */  stw      r0, 172(r1);
/* 807A040C D0210010 */  stfs     f1, 16(r1);
/* 807A0410 D0010014 */  stfs     f0, 20(r1);
/* 807A0414 D0450048 */  stfs     f2, 72(r5);
UNDEF_807a0418:;
/* 807A0418 38840004 */  addi     r4, r4, 4;
/* 807A041C 4200FD84 */  bdnz+    UNDEF_807a01a0;
/* 807A0420 39610130 */  addi     r11, r1, 304;
/* 807A0424 4BB3CC59 */  bl       UNDEF_802dd07c;
/* 807A0428 80010134 */  lwz      r0, 308(r1);
/* 807A042C 7C0803A6 */  mtlr     r0;
/* 807A0430 38210130 */  addi     r1, r1, 304;
/* 807A0434 4E800020 */  blr;
  // clang-format on
);

[[address(0x807A0440)]]
void dNumberOfPeopleChange_c::assignPositions() ASM_METHOD(
  // clang-format off
/* 807A0440 9421FEF0 */  stwu     r1, -272(r1);
/* 807A0444 7C0802A6 */  mflr     r0;
/* 807A0448 90010114 */  stw      r0, 276(r1);
/* 807A044C 396100E0 */  addi     r11, r1, 224;
/* 807A0450 DBE10100 */  stfd     f31, 256(r1);
/* 807A0454 F3E10108 */  .long    0xF3E10108; // psq_st   f31, 264(r1), 0, 0;
/* 807A0458 DBC100F0 */  stfd     f30, 240(r1);
/* 807A045C F3C100F8 */  .long    0xF3C100F8; // psq_st   f30, 248(r1), 0, 0;
/* 807A0460 DBA100E0 */  stfd     f29, 224(r1);
/* 807A0464 F3A100E8 */  .long    0xF3A100E8; // psq_st   f29, 232(r1), 0, 0;
/* 807A0468 4BB3CBF1 */  bl       UNDEF_802dd058;
/* 807A046C 3C808043 */  lis      r4, m_nowScene__8dScene_c@ha;
/* 807A0470 3FC08093 */  lis      r30, UNDEF_809352a0@ha;
/* 807A0474 A0048A42 */  lhz      r0, m_nowScene__8dScene_c@l(r4);
/* 807A0478 7C7A1B78 */  mr       r26, r3;
/* 807A047C 3BDE52A0 */  addi     r30, r30, UNDEF_809352a0@l;
/* 807A0480 28000003 */  cmplwi   r0, 3;
/* 807A0484 4082014C */  bne-     UNDEF_807a05d0;
/* 807A0488 C3BE007C */  lfs      f29, 124(r30);
/* 807A048C 7F5FD378 */  mr       r31, r26;
/* 807A0490 C3DE0088 */  lfs      f30, 136(r30);
/* 807A0494 7F5DD378 */  mr       r29, r26;
/* 807A0498 C3FE008C */  lfs      f31, 140(r30);
/* 807A049C 3B600000 */  li       r27, 0;
UNDEF_807a04a0:;
/* 807A04A0 839F06F0 */  lwz      r28, 1776(r31);
/* 807A04A4 807F06A4 */  lwz      r3, 1700(r31);
/* 807A04A8 2C1C0000 */  cmpwi    r28, 0;
/* 807A04AC 4180010C */  blt-     UNDEF_807a05b8;
/* 807A04B0 801D0690 */  lwz      r0, 1680(r29);
/* 807A04B4 2C000003 */  cmpwi    r0, 3;
/* 807A04B8 40820100 */  bne-     UNDEF_807a05b8;
/* 807A04BC 5460103A */  slwi     r0, r3, 2;
/* 807A04C0 38610024 */  addi     r3, r1, 36;
/* 807A04C4 7FDA0214 */  add      r30, r26, r0;
/* 807A04C8 38810054 */  addi     r4, r1, 84;
/* 807A04CC 831E05DC */  lwz      r24, 1500(r30);
/* 807A04D0 80B80090 */  lwz      r5, 144(r24);
/* 807A04D4 90A1009C */  stw      r5, 156(r1);
/* 807A04D8 801800A0 */  lwz      r0, 160(r24);
/* 807A04DC 900100AC */  stw      r0, 172(r1);
/* 807A04E0 83380084 */  lwz      r25, 132(r24);
/* 807A04E4 81980088 */  lwz      r12, 136(r24);
/* 807A04E8 8178008C */  lwz      r11, 140(r24);
/* 807A04EC 81580094 */  lwz      r10, 148(r24);
/* 807A04F0 81380098 */  lwz      r9, 152(r24);
/* 807A04F4 8118009C */  lwz      r8, 156(r24);
/* 807A04F8 80F800A4 */  lwz      r7, 164(r24);
/* 807A04FC 80D800A8 */  lwz      r6, 168(r24);
/* 807A0500 80B800AC */  lwz      r5, 172(r24);
/* 807A0504 801800B0 */  lwz      r0, 176(r24);
/* 807A0508 C021009C */  lfs      f1, 156(r1);
/* 807A050C C00100AC */  lfs      f0, 172(r1);
/* 807A0510 93210090 */  stw      r25, 144(r1);
/* 807A0514 91810094 */  stw      r12, 148(r1);
/* 807A0518 91610098 */  stw      r11, 152(r1);
/* 807A051C 914100A0 */  stw      r10, 160(r1);
/* 807A0520 912100A4 */  stw      r9, 164(r1);
/* 807A0524 910100A8 */  stw      r8, 168(r1);
/* 807A0528 90E100B0 */  stw      r7, 176(r1);
/* 807A052C 90C100B4 */  stw      r6, 180(r1);
/* 807A0530 90A100B8 */  stw      r5, 184(r1);
/* 807A0534 900100BC */  stw      r0, 188(r1);
/* 807A0538 D0210054 */  stfs     f1, 84(r1);
/* 807A053C D0010058 */  stfs     f0, 88(r1);
/* 807A0540 D3A1005C */  stfs     f29, 92(r1);
/* 807A0544 4B912D9D */  bl       UNDEF_800b32e0;
/* 807A0548 C0410024 */  lfs      f2, 36(r1);
/* 807A054C 5780103A */  slwi     r0, r28, 2;
/* 807A0550 C0210028 */  lfs      f1, 40(r1);
/* 807A0554 7CBA0214 */  add      r5, r26, r0;
/* 807A0558 C001002C */  lfs      f0, 44(r1);
/* 807A055C D0410054 */  stfs     f2, 84(r1);
/* 807A0560 D0210058 */  stfs     f1, 88(r1);
/* 807A0564 D001005C */  stfs     f0, 92(r1);
/* 807A0568 8065064C */  lwz      r3, OFFSET_dNumberOfPeopleChange_c_mpaPlayers(r5);
/* 807A056C D3C10050 */  stfs     f30, 80(r1);
/* 807A0570 D04300AC */  stfs     f2, 172(r3);
/* 807A0574 C0010058 */  lfs      f0, 88(r1);
/* 807A0578 D00300B0 */  stfs     f0, 176(r3);
/* 807A057C C001005C */  lfs      f0, 92(r1);
/* 807A0580 D00300B4 */  stfs     f0, 180(r3);
/* 807A0584 807E05DC */  lwz      r3, 1500(r30);
/* 807A0588 8085064C */  lwz      r4, OFFSET_dNumberOfPeopleChange_c_mpaPlayers(r5);
/* 807A058C C0030048 */  lfs      f0, 72(r3);
/* 807A0590 C0230044 */  lfs      f1, 68(r3);
/* 807A0594 D0240220 */  stfs     f1, 544(r4);
/* 807A0598 D0040224 */  stfs     f0, 548(r4);
/* 807A059C D3C40228 */  stfs     f30, 552(r4);
/* 807A05A0 8065064C */  lwz      r3, OFFSET_dNumberOfPeopleChange_c_mpaPlayers(r5);
/* 807A05A4 D0210010 */  stfs     f1, 16(r1);
/* 807A05A8 D0010014 */  stfs     f0, 20(r1);
/* 807A05AC D0210048 */  stfs     f1, 72(r1);
/* 807A05B0 D001004C */  stfs     f0, 76(r1);
/* 807A05B4 D3E3025C */  stfs     f31, 604(r3);
UNDEF_807a05b8:;
/* 807A05B8 3B7B0001 */  addi     r27, r27, 1;
/* 807A05BC 3BBD0004 */  addi     r29, r29, 4;
/* 807A05C0          */  cmpwi    r27, NUM_PY_CHANGE_PLAYER_COUNT;
/* 807A05C4 3BFF0004 */  addi     r31, r31, 4;
/* 807A05C8 4180FED8 */  blt+     UNDEF_807a04a0;
/* 807A05CC 480001B8 */  b        UNDEF_807a0784;
UNDEF_807a05d0:;
/* 807A05D0 800306A4 */  lwz      r0, 1700(r3);
/* 807A05D4 3881003C */  addi     r4, r1, 60;
/* 807A05D8 C01E007C */  lfs      f0, 124(r30);
/* 807A05DC 5400103A */  slwi     r0, r0, 2;
/* 807A05E0 7FE30214 */  add      r31, r3, r0;
/* 807A05E4 38610018 */  addi     r3, r1, 24;
/* 807A05E8 839F05DC */  lwz      r28, 1500(r31);
/* 807A05EC 80BC0090 */  lwz      r5, 144(r28);
/* 807A05F0 90A1006C */  stw      r5, 108(r1);
/* 807A05F4 801C00A0 */  lwz      r0, 160(r28);
/* 807A05F8 9001007C */  stw      r0, 124(r1);
/* 807A05FC 837C0084 */  lwz      r27, 132(r28);
/* 807A0600 819C0088 */  lwz      r12, 136(r28);
/* 807A0604 817C008C */  lwz      r11, 140(r28);
/* 807A0608 815C0094 */  lwz      r10, 148(r28);
/* 807A060C 813C0098 */  lwz      r9, 152(r28);
/* 807A0610 811C009C */  lwz      r8, 156(r28);
/* 807A0614 80FC00A4 */  lwz      r7, 164(r28);
/* 807A0618 80DC00A8 */  lwz      r6, 168(r28);
/* 807A061C 80BC00AC */  lwz      r5, 172(r28);
/* 807A0620 801C00B0 */  lwz      r0, 176(r28);
/* 807A0624 C041006C */  lfs      f2, 108(r1);
/* 807A0628 C021007C */  lfs      f1, 124(r1);
/* 807A062C 93610060 */  stw      r27, 96(r1);
/* 807A0630 91810064 */  stw      r12, 100(r1);
/* 807A0634 91610068 */  stw      r11, 104(r1);
/* 807A0638 91410070 */  stw      r10, 112(r1);
/* 807A063C 91210074 */  stw      r9, 116(r1);
/* 807A0640 91010078 */  stw      r8, 120(r1);
/* 807A0644 90E10080 */  stw      r7, 128(r1);
/* 807A0648 90C10084 */  stw      r6, 132(r1);
/* 807A064C 90A10088 */  stw      r5, 136(r1);
/* 807A0650 9001008C */  stw      r0, 140(r1);
/* 807A0654 D041003C */  stfs     f2, 60(r1);
/* 807A0658 D0210040 */  stfs     f1, 64(r1);
/* 807A065C D0010044 */  stfs     f0, 68(r1);
/* 807A0660 4B912C81 */  bl       UNDEF_800b32e0;
/* 807A0664 C0610018 */  lfs      f3, 24(r1);
/* 807A0668 38000002 */  li       r0, NUM_PY_CHANGE_PLAYER_COUNT >> 1;
/* 807A066C C001001C */  lfs      f0, 28(r1);
/* 807A0670 C0410020 */  lfs      f2, 32(r1);
/* 807A0674 D0010040 */  stfs     f0, 64(r1);
/* 807A0678 C03E0088 */  lfs      f1, 136(r30);
/* 807A067C D061003C */  stfs     f3, 60(r1);
/* 807A0680 C01E008C */  lfs      f0, 140(r30);
/* 807A0684 D0410044 */  stfs     f2, 68(r1);

                         // Don't hardcode Mario's position
// /* 807A0688 807A064C */  lwz      r3, 1612(r26);
// /* 807A068C D06300AC */  stfs     f3, 172(r3);
// /* 807A0690 C0410040 */  lfs      f2, 64(r1);
// /* 807A0694 D04300B0 */  stfs     f2, 176(r3);
// /* 807A0698 C0410044 */  lfs      f2, 68(r1);
// /* 807A069C D04300B4 */  stfs     f2, 180(r3);

/* 807A06A0 C0A10040 */  lfs      f5, 64(r1);
/* 807A06A4 7C0903A6 */  mtctr    r0;
UNDEF_807a06a8:;
/* 807A06A8 807A064C */  lwz      r3, OFFSET_dNumberOfPeopleChange_c_mpaPlayers(r26);
/* 807A06AC D0210038 */  stfs     f1, 56(r1);
/* 807A06B0 C08300AC */  lfs      f4, 172(r3);
/* 807A06B4 D081003C */  stfs     f4, 60(r1);
/* 807A06B8 C04300B0 */  lfs      f2, 176(r3);
/* 807A06BC D0410040 */  stfs     f2, 64(r1);
/* 807A06C0 C04300B4 */  lfs      f2, 180(r3);
/* 807A06C4 D0410044 */  stfs     f2, 68(r1);
/* 807A06C8 D0A10040 */  stfs     f5, 64(r1);
/* 807A06CC D08300AC */  stfs     f4, 172(r3);
/* 807A06D0 C0410040 */  lfs      f2, 64(r1);
/* 807A06D4 D04300B0 */  stfs     f2, 176(r3);
/* 807A06D8 C0410044 */  lfs      f2, 68(r1);
/* 807A06DC D04300B4 */  stfs     f2, 180(r3);
/* 807A06E0 807F05DC */  lwz      r3, 1500(r31);
/* 807A06E4 809A064C */  lwz      r4, OFFSET_dNumberOfPeopleChange_c_mpaPlayers(r26);
/* 807A06E8 C0430048 */  lfs      f2, 72(r3);
/* 807A06EC C0630044 */  lfs      f3, 68(r3);
/* 807A06F0 D0640220 */  stfs     f3, 544(r4);
/* 807A06F4 D0440224 */  stfs     f2, 548(r4);
/* 807A06F8 D0240228 */  stfs     f1, 552(r4);
/* 807A06FC 807A064C */  lwz      r3, OFFSET_dNumberOfPeopleChange_c_mpaPlayers(r26);
/* 807A0700 D041000C */  stfs     f2, 12(r1);
/* 807A0704 D003025C */  stfs     f0, 604(r3);
/* 807A0708 807A0650 */  lwz      r3, OFFSET_dNumberOfPeopleChange_c_mpaPlayers+4(r26);
/* 807A070C D0410034 */  stfs     f2, 52(r1);
/* 807A0710 C08300AC */  lfs      f4, 172(r3);
/* 807A0714 D081003C */  stfs     f4, 60(r1);
/* 807A0718 C04300B0 */  lfs      f2, 176(r3);
/* 807A071C D0410040 */  stfs     f2, 64(r1);
/* 807A0720 C04300B4 */  lfs      f2, 180(r3);
/* 807A0724 D0410044 */  stfs     f2, 68(r1);
/* 807A0728 D0A10040 */  stfs     f5, 64(r1);
/* 807A072C D08300AC */  stfs     f4, 172(r3);
/* 807A0730 C0410040 */  lfs      f2, 64(r1);
/* 807A0734 D04300B0 */  stfs     f2, 176(r3);
/* 807A0738 C0410044 */  lfs      f2, 68(r1);
/* 807A073C D04300B4 */  stfs     f2, 180(r3);
/* 807A0740 807F05DC */  lwz      r3, 1500(r31);
/* 807A0744 809A0650 */  lwz      r4, OFFSET_dNumberOfPeopleChange_c_mpaPlayers+4(r26);
/* 807A0748 C0430048 */  lfs      f2, 72(r3);
/* 807A074C D0610008 */  stfs     f3, 8(r1);
/* 807A0750 D0610030 */  stfs     f3, 48(r1);
/* 807A0754 C0630044 */  lfs      f3, 68(r3);
/* 807A0758 D0640220 */  stfs     f3, 544(r4);
/* 807A075C D0440224 */  stfs     f2, 548(r4);
/* 807A0760 D0240228 */  stfs     f1, 552(r4);
/* 807A0764 807A0650 */  lwz      r3, OFFSET_dNumberOfPeopleChange_c_mpaPlayers+4(r26);
/* 807A0768 3B5A0008 */  addi     r26, r26, 8;
/* 807A076C D0610008 */  stfs     f3, 8(r1);
/* 807A0770 D041000C */  stfs     f2, 12(r1);
/* 807A0774 D0610030 */  stfs     f3, 48(r1);
/* 807A0778 D0410034 */  stfs     f2, 52(r1);
/* 807A077C D003025C */  stfs     f0, 604(r3);
/* 807A0780 4200FF28 */  bdnz+    UNDEF_807a06a8;
UNDEF_807a0784:;
/* 807A0784 396100E0 */  addi     r11, r1, 224;
/* 807A0788 E3E10108 */  .long    0xE3E10108; // psq_l    f31, 264(r1), 0, 0;
/* 807A078C CBE10100 */  lfd      f31, 256(r1);
/* 807A0790 E3C100F8 */  .long    0xE3C100F8; // psq_l    f30, 248(r1), 0, 0;
/* 807A0794 CBC100F0 */  lfd      f30, 240(r1);
/* 807A0798 E3A100E8 */  .long    0xE3A100E8; // psq_l    f29, 232(r1), 0, 0;
/* 807A079C CBA100E0 */  lfd      f29, 224(r1);
/* 807A07A0 4BB3C905 */  bl       UNDEF_802dd0a4;
/* 807A07A4 80010114 */  lwz      r0, 276(r1);
/* 807A07A8 7C0803A6 */  mtlr     r0;
/* 807A07AC 38210110 */  addi     r1, r1, 272;
/* 807A07B0 4E800020 */  blr;
  // clang-format on
);

[[address(0x807A07C0)]]
void dNumberOfPeopleChange_c::disableInactiveControllers()
{
    dRemoconMng_c* remoconMng = dRemoconMng_c::m_instance;
    dInfo_c* info = dInfo_c::m_instance;

    for (int i = 0; i < 4; i++) {
        if (mControllerActive[i] == 3) {
            remoconMng->mpaConnect[i]->m0x54 = true;
            info->mPlayerActiveMode[i] = 0x3;
        } else {
            remoconMng->mpaConnect[i]->m0x54 = false;
        }
    }

    for (int i = 4; i < dRemoconMng_c::CONNECT_COUNT; i++) {
        // Use mRealPlayerCount for meow
        if (i < mRealPlayerCount) {
            info->mExPlayerActiveMode[i - 4] = 0x3;
        }
    }
}

[[address(0x807A09B0)]]
int dNumberOfPeopleChange_c::getBaseForPlayerCount(int playerCount, int player);

[[address(0x807A09D0)]]
void dNumberOfPeopleChange_c::calcBasesForPlayerCount()
{
    int playerCount = mPlayerCount;

    // Cap the player count to 4 currently
    // TODO
    if (playerCount > 4) {
        playerCount = 4;
    }

    for (int i = 0; i < 4; i++) {
        maPlrBaseIndex[i] = getBaseForPlayerCount(playerCount - 1, i);
        maPlrBaseIndex2[i] = maPlrBaseIndex[i];
    }
}

[[address(0x807A0BF0)]]
void dNumberOfPeopleChange_c::setupPlayerTypes()
{
    bool typeActive[PLAYER_COUNT] = {};

    for (int i = 0; i < 4; i++) {
        if (getControllerActive(i) == 3) {
            daPyMng_c::mPlayerType[i] = getDecidedPlrType(i);
            typeActive[int(daPyMng_c::mPlayerType[i])] = true;
        }
    }

    // Hardcode player 5 to black toad (REMOVE LATER)
    if (!typeActive[int(daPyMng_c::PlayerType_e::BLACK_TOAD)]) {
        daPyMng_c::mPlayerType[4] = daPyMng_c::PlayerType_e::BLACK_TOAD;
        typeActive[int(daPyMng_c::PlayerType_e::BLACK_TOAD)] = true;
    }

    // All indices need to have a unique player type, regardless of whether that player type is even
    // used
    for (int c = 0, i = 0; c < PLAYER_COUNT; c++) {
        if (typeActive[c]) {
            continue;
        }

        // Find the next unused player index (REMOVE CHECK FOR 5)
        while ((i < 4 && getControllerActive(i) == 3) || i == 4) {
            i++;
        }

        daPyMng_c::mPlayerType[i++] = daPyMng_c::PlayerType_e(c);
    }
}

[[address(0x807A0D20)]]
bool dNumberOfPeopleChange_c::checkCancel()
{
    bool p1Active = mpaCcSelBase[0]->mDecided;

    if (dScene_c::m_nowScene == +fBaseProfile_e::WORLD_MAP) {
        if (!p1Active) {
            // We can't allow the player to cancel when player 1 isn't even registered
            return false;
        }

        return mPad::g_currentCore->downTrigger(0x900) != 0;
    }

    // But here the cancel button is 1, and we prioritize player 1 cancelling over leaving the whole
    // menu
    if (p1Active) {
        return false;
    }

    return dGameCom::chkCancelButton(0);
}

[[address(0x807A0DB0)]]
void dNumberOfPeopleChange_c::initializeState_InitialSetup() ASM_METHOD(
  // clang-format off
/* 807A0DB0 9421FFF0 */  stwu     r1, -16(r1);
/* 807A0DB4 7C0802A6 */  mflr     r0;
/* 807A0DB8 3C808043 */  lis      r4, UNDEF_8042a260@ha;
/* 807A0DBC 3CA08043 */  lis      r5, UNDEF_8042a25c@ha;
/* 807A0DC0 90010014 */  stw      r0, 20(r1);
/* 807A0DC4 93E1000C */  stw      r31, 12(r1);
/* 807A0DC8 93C10008 */  stw      r30, 8(r1);
/* 807A0DCC 7C7E1B78 */  mr       r30, r3;
/* 807A0DD0 8004A260 */  lwz      r0, UNDEF_8042a260@l(r4);
/* 807A0DD4 83E5A25C */  lwz      r31, UNDEF_8042a25c@l(r5);
/* 807A0DD8 540006F7 */  rlwinm.  r0, r0, 0, 27, 27;
/* 807A0DDC 4182000C */  beq-     UNDEF_807a0de8;
/* 807A0DE0 7FE3FB78 */  mr       r3, r31;
/* 807A0DE4 4B91A39D */  bl       UNDEF_800bb180;
UNDEF_807a0de8:;
/* 807A0DE8 38000001 */  li       r0, 1;
/* 807A0DEC 981F0AFC */  stb      r0, 0xAFC(r31);
/* 807A0DF0 38000000 */  li       r0, 0;
/* 807A0DF4 3C808035 */  lis      r4, mPlayerType__9daPyMng_c@ha;
/* 807A0DF8 901E06A0 */  stw      r0, 0x6A0(r30);
/* 807A0DFC 84045160 */  lwzu     r0, mPlayerType__9daPyMng_c@l(r4);
/* 807A0E00 901E06E0 */  stw      r0, 0x6E0(r30);
/* 807A0E04 901E06F0 */  stw      r0, 0x6F0(r30);
/* 807A0E08 801F0384 */  lwz      r0, 0x384(r31);
/* 807A0E0C 901E0690 */  stw      r0, 0x690(r30);
/* 807A0E10 2C000003 */  cmpwi    r0, 3;
/* 807A0E14 40820010 */  bne-     UNDEF_807a0e24;
/* 807A0E18 807E06A0 */  lwz      r3, 0x6A0(r30);
/* 807A0E1C 38030001 */  addi     r0, r3, 1;
/* 807A0E20 901E06A0 */  stw      r0, 0x6A0(r30);
UNDEF_807a0e24:;
/* 807A0E24 80040004 */  lwz      r0, 0x4(r4);
/* 807A0E28 901E06E4 */  stw      r0, 0x6E4(r30);
/* 807A0E2C 901E06F4 */  stw      r0, 0x6F4(r30);
/* 807A0E30 801F0388 */  lwz      r0, 0x388(r31);
/* 807A0E34 901E0694 */  stw      r0, 0x694(r30);
/* 807A0E38 2C000003 */  cmpwi    r0, 3;
/* 807A0E3C 40820010 */  bne-     UNDEF_807a0e4c;
/* 807A0E40 807E06A0 */  lwz      r3, 0x6A0(r30);
/* 807A0E44 38030001 */  addi     r0, r3, 1;
/* 807A0E48 901E06A0 */  stw      r0, 0x6A0(r30);
UNDEF_807a0e4c:;
/* 807A0E4C 80040008 */  lwz      r0, 0x8(r4);
/* 807A0E50 38BE0008 */  addi     r5, r30, 8;
/* 807A0E54 901E06E8 */  stw      r0, 0x6E8(r30);
/* 807A0E58 38DF0008 */  addi     r6, r31, 8;
/* 807A0E5C 901E06F8 */  stw      r0, 0x6F8(r30);
/* 807A0E60 801F038C */  lwz      r0, 0x38C(r31);
/* 807A0E64 901E0698 */  stw      r0, 0x698(r30);
/* 807A0E68 2C000003 */  cmpwi    r0, 3;
/* 807A0E6C 40820010 */  bne-     UNDEF_807a0e7c;
/* 807A0E70 807E06A0 */  lwz      r3, 0x6A0(r30);
/* 807A0E74 38030001 */  addi     r0, r3, 1;
/* 807A0E78 901E06A0 */  stw      r0, 0x6A0(r30);
UNDEF_807a0e7c:;
/* 807A0E7C 8004000C */  lwz      r0, 0xC(r4);
/* 807A0E80 900506E4 */  stw      r0, 0x6E4(r5);
/* 807A0E84 900506F4 */  stw      r0, 0x6F4(r5);
/* 807A0E88 80060388 */  lwz      r0, 0x388(r6);
/* 807A0E8C 90050694 */  stw      r0, 0x694(r5);
/* 807A0E90 2C000003 */  cmpwi    r0, 3;
/* 807A0E94 40820010 */  bne-     UNDEF_807a0ea4;
/* 807A0E98 807E06A0 */  lwz      r3, 0x6A0(r30);
/* 807A0E9C 38030001 */  addi     r0, r3, 1;
/* 807A0EA0 901E06A0 */  stw      r0, 0x6A0(r30);
UNDEF_807a0ea4:;
/* 807A0EA4 7FC3F378 */  mr       r3, r30;
/* 807A0EA8 4BFFFB29 */  bl       UNDEF_807a09d0;
/* 807A0EAC 3C808035 */  lis      r4, mPlayerType__9daPyMng_c@ha;
/* 807A0EB0 3CE08093 */  lis      r7, UNDEF_80935370@ha;
/* 807A0EB4 3C608093 */  lis      r3, UNDEF_8093532c@ha;
/* 807A0EB8 C0475370 */  lfs      f2, UNDEF_80935370@l(r7);
/* 807A0EBC C003532C */  lfs      f0, UNDEF_8093532c@l(r3);
/* 807A0EC0          */  li       r6, 4;
/* 807A0EC4 7FC5F378 */  mr       r5, r30;
/* 807A0EC8 38845160 */  addi     r4, r4, mPlayerType__9daPyMng_c@l;
/* 807A0ECC 381E0690 */  addi     r0, r30, 0x690;
/* 807A0ED0 393E06A0 */  addi     r9, r30, 0x6A0;
/* 807A0ED4 38600001 */  li       r3, 1;
/* 807A0ED8 38E0FFFF */  li       r7, -1;
/* 807A0EDC 7CC903A6 */  mtctr    r6;
UNDEF_807a0ee0:;
/* 807A0EE0 80C50690 */  lwz      r6, 0x690(r5);
/* 807A0EE4 81040000 */  lwz      r8, 0(r4);
/* 807A0EE8 2C060003 */  cmpwi    r6, 3;
/* 807A0EEC 40820020 */  bne-     UNDEF_807a0f0c;
/* 807A0EF0 5506103A */  slwi     r6, r8, 2;
/* 807A0EF4 7CDE3214 */  add      r6, r30, r6;
/* 807A0EF8 80C6064C */  lwz      r6, OFFSET_dNumberOfPeopleChange_c_mpaPlayers(r6);
/* 807A0EFC 98660261 */  stb      r3, 0x261(r6);
/* 807A0F00 C02600B0 */  lfs      f1, 0xB0(r6);
/* 807A0F04 EC21102A */  fadds    f1, f1, f2;
/* 807A0F08 D02600B0 */  stfs     f1, 0xB0(r6);
UNDEF_807a0f0c:;
/* 807A0F0C 5506103A */  slwi     r6, r8, 2;
/* 807A0F10 38840004 */  addi     r4, r4, 4;
/* 807A0F14 7CDE3214 */  add      r6, r30, r6;
/* 807A0F18 80C6064C */  lwz      r6, OFFSET_dNumberOfPeopleChange_c_mpaPlayers(r6);
/* 807A0F1C 98660267 */  stb      r3, 615(r6);
/* 807A0F20 80C50074 */  lwz      r6, 0x74(r5);
/* 807A0F24 90060280 */  stw      r0, 640(r6);
/* 807A0F28 80C50074 */  lwz      r6, 0x74(r5);
/* 807A0F2C 81050084 */  lwz      r8, 0x84(r5);
/* 807A0F30 91060074 */  stw      r8, 116(r6);
/* 807A0F34 80C50074 */  lwz      r6, 0x74(r5);
/* 807A0F38 81050094 */  lwz      r8, 0x94(r5);
/* 807A0F3C 91060078 */  stw      r8, 120(r6);
/* 807A0F40 80C50074 */  lwz      r6, 0x74(r5);
/* 807A0F44 810500A4 */  lwz      r8, 164(r5);
/* 807A0F48 9106007C */  stw      r8, 124(r6);
/* 807A0F4C 80C50084 */  lwz      r6, 132(r5);
/* 807A0F50 810500A4 */  lwz      r8, 164(r5);
/* 807A0F54 91060208 */  stw      r8, 520(r6);
/* 807A0F58 80C50074 */  lwz      r6, 116(r5);
/* 807A0F5C 811E06C4 */  lwz      r8, 0x6C4(r30);
/* 807A0F60 910602E8 */  stw      r8, 744(r6);
/* 807A0F64 80C50074 */  lwz      r6, 116(r5);
/* 807A0F68 91260288 */  stw      r9, 648(r6);
/* 807A0F6C 80C50074 */  lwz      r6, 116(r5);
                         la       r8, OFFSET_dNumberOfPeopleChange_c_mpaPlayers(r30);
                         stw      r8, 0x80(r6);
// /* 807A0F70 811E064C */  lwz      r8, OFFSET_dNumberOfPeopleChange_c_mpaPlayers(r30);
// /* 807A0F74 91060080 */  stw      r8, 128(r6);
// /* 807A0F78 80C50074 */  lwz      r6, 116(r5);
// /* 807A0F7C 811E0650 */  lwz      r8, OFFSET_dNumberOfPeopleChange_c_mpaPlayers + 4(r30);
// /* 807A0F80 91060084 */  stw      r8, 132(r6);
// /* 807A0F84 80C50074 */  lwz      r6, 116(r5);
// /* 807A0F88 811E0654 */  lwz      r8, OFFSET_dNumberOfPeopleChange_c_mpaPlayers + 8(r30);
// /* 807A0F8C 91060088 */  stw      r8, 136(r6);
// /* 807A0F90 80C50074 */  lwz      r6, 116(r5);
// /* 807A0F94 811E0658 */  lwz      r8, OFFSET_dNumberOfPeopleChange_c_mpaPlayers + 12(r30);
// /* 807A0F98 9106008C */  stw      r8, 140(r6);
/* 807A0F9C 90E506D0 */  stw      r7, 0x6D0(r5);
/* 807A0FA0 810500A4 */  lwz      r8, 164(r5);
/* 807A0FA4 8148021C */  lwz      r10, 540(r8);
/* 807A0FA8 88CA00BB */  lbz      r6, 187(r10);
/* 807A0FAC 54C6063C */  rlwinm   r6, r6, 0, 24, 30;
/* 807A0FB0 60C60001 */  ori      r6, r6, 1;
/* 807A0FB4 98CA00BB */  stb      r6, 187(r10);
/* 807A0FB8 81080220 */  lwz      r8, 544(r8);
/* 807A0FBC 88C800BB */  lbz      r6, 187(r8);
/* 807A0FC0 54C6063C */  rlwinm   r6, r6, 0, 24, 30;
/* 807A0FC4 60C60001 */  ori      r6, r6, 1;
/* 807A0FC8 98C800BB */  stb      r6, 187(r8);
/* 807A0FCC 80C5064C */  lwz      r6, OFFSET_dNumberOfPeopleChange_c_mpaPlayers(r5);
/* 807A0FD0 D006025C */  stfs     f0, 604(r6);
/* 807A0FD4 80C50074 */  lwz      r6, 116(r5);
/* 807A0FD8 38A50004 */  addi     r5, r5, 4;
/* 807A0FDC D00602F0 */  stfs     f0, 752(r6);
/* 807A0FE0 4200FF00 */  bdnz+    UNDEF_807a0ee0;

                         // Allow player 1 to register
// /* 807A0FE4 38000000 */  li       r0, 0;
// /* 807A0FE8 901E06D0 */  stw      r0, 1744(r30);

/* 807A0FEC 3C608043 */  lis      r3, m_nowScene__8dScene_c@ha;
/* 807A0FF0 A0038A42 */  lhz      r0, m_nowScene__8dScene_c@l(r3);
/* 807A0FF4 28000003 */  cmplwi   r0, 3;
/* 807A0FF8 40820064 */  bne-     UNDEF_807a105c;
/* 807A0FFC 807E061C */  lwz      r3, 1564(r30);
/* 807A1000 880300BB */  lbz      r0, 187(r3);
/* 807A1004 5400063C */  rlwinm   r0, r0, 0, 24, 30;
/* 807A1008 60000001 */  ori      r0, r0, 1;
/* 807A100C 980300BB */  stb      r0, 187(r3);
/* 807A1010 807E0620 */  lwz      r3, 1568(r30);
/* 807A1014 880300BB */  lbz      r0, 187(r3);
/* 807A1018 5400063C */  rlwinm   r0, r0, 0, 24, 30;
/* 807A101C 60000001 */  ori      r0, r0, 1;
/* 807A1020 980300BB */  stb      r0, 187(r3);
/* 807A1024 807E0624 */  lwz      r3, 1572(r30);
/* 807A1028 880300BB */  lbz      r0, 187(r3);
/* 807A102C 5400063C */  rlwinm   r0, r0, 0, 24, 30;
/* 807A1030 980300BB */  stb      r0, 187(r3);
/* 807A1034 807E0604 */  lwz      r3, 1540(r30);
/* 807A1038 880300BB */  lbz      r0, 187(r3);
/* 807A103C 5400063C */  rlwinm   r0, r0, 0, 24, 30;
/* 807A1040 60000001 */  ori      r0, r0, 1;
/* 807A1044 980300BB */  stb      r0, 187(r3);
/* 807A1048 807E0608 */  lwz      r3, 1544(r30);
/* 807A104C 880300BB */  lbz      r0, 187(r3);
/* 807A1050 5400063C */  rlwinm   r0, r0, 0, 24, 30;
/* 807A1054 980300BB */  stb      r0, 187(r3);
/* 807A1058 48000084 */  b        UNDEF_807a10dc;
UNDEF_807a105c:;
/* 807A105C 807E0624 */  lwz      r3, 1572(r30);
/* 807A1060 880300BB */  lbz      r0, 187(r3);
/* 807A1064 5400063C */  rlwinm   r0, r0, 0, 24, 30;
/* 807A1068 60000001 */  ori      r0, r0, 1;
/* 807A106C 980300BB */  stb      r0, 187(r3);
/* 807A1070 807E061C */  lwz      r3, 1564(r30);
/* 807A1074 880300BB */  lbz      r0, 187(r3);
/* 807A1078 5400063C */  rlwinm   r0, r0, 0, 24, 30;
/* 807A107C 980300BB */  stb      r0, 187(r3);
/* 807A1080 807E0620 */  lwz      r3, 1568(r30);
/* 807A1084 880300BB */  lbz      r0, 187(r3);
/* 807A1088 5400063C */  rlwinm   r0, r0, 0, 24, 30;
/* 807A108C 980300BB */  stb      r0, 187(r3);
/* 807A1090 807E0604 */  lwz      r3, 1540(r30);
/* 807A1094 880300BB */  lbz      r0, 187(r3);
/* 807A1098 5400063C */  rlwinm   r0, r0, 0, 24, 30;
/* 807A109C 980300BB */  stb      r0, 187(r3);
/* 807A10A0 807E0608 */  lwz      r3, 1544(r30);
/* 807A10A4 880300BB */  lbz      r0, 187(r3);
/* 807A10A8 5400063C */  rlwinm   r0, r0, 0, 24, 30;
/* 807A10AC 60000001 */  ori      r0, r0, 1;
/* 807A10B0 980300BB */  stb      r0, 187(r3);
/* 807A10B4 4B92CC9D */  bl       UNDEF_800cdd50;
/* 807A10B8 801E06C4 */  lwz      r0, 1732(r30);
/* 807A10BC 7C641B78 */  mr       r4, r3;
/* 807A10C0 901F03CC */  stw      r0, 972(r31);
/* 807A10C4 38A00002 */  li       r5, 2;
/* 807A10C8 38C0001C */  li       r6, 28;
/* 807A10CC 38E00000 */  li       r7, 0;
/* 807A10D0 807E0608 */  lwz      r3, 1544(r30);
/* 807A10D4 4CC63182 */  crclr    6;
/* 807A10D8 4B928A79 */  bl       UNDEF_800c9b50;
UNDEF_807a10dc:;
/* 807A10DC 387E0404 */  addi     r3, r30, 1028;
/* 807A10E0 4B928511 */  bl       UNDEF_800c95f0;
/* 807A10E4 387E0404 */  addi     r3, r30, 1028;
/* 807A10E8 38800002 */  li       r4, 2;
/* 807A10EC 38A00000 */  li       r5, 0;
/* 807A10F0 4B9283D1 */  bl       UNDEF_800c94c0;
/* 807A10F4 387E0404 */  addi     r3, r30, 1028;
/* 807A10F8 38800003 */  li       r4, 3;
/* 807A10FC 38A00000 */  li       r5, 0;
/* 807A1100 4B9283C1 */  bl       UNDEF_800c94c0;
/* 807A1104 80DE05D8 */  lwz      r6, 1496(r30);
/* 807A1108 3C808099 */  lis      r4, UNDEF_80994508@ha;
/* 807A110C 38000000 */  li       r0, 0;
/* 807A1110 387E059C */  addi     r3, r30, 1436;
/* 807A1114 88A600BB */  lbz      r5, 187(r6);
/* 807A1118 38844508 */  addi     r4, r4, UNDEF_80994508@l;
/* 807A111C 54A5063C */  rlwinm   r5, r5, 0, 24, 30;
/* 807A1120 60A50001 */  ori      r5, r5, 1;
/* 807A1124 98A600BB */  stb      r5, 187(r6);
/* 807A1128 981E0680 */  stb      r0, 1664(r30);
/* 807A112C 819E059C */  lwz      r12, 1436(r30);
/* 807A1130 818C0018 */  lwz      r12, 24(r12);
/* 807A1134 7D8903A6 */  mtctr    r12;
/* 807A1138 4E800421 */  bctrl;
/* 807A113C 80010014 */  lwz      r0, 20(r1);
/* 807A1140 83E1000C */  lwz      r31, 12(r1);
/* 807A1144 83C10008 */  lwz      r30, 8(r1);
/* 807A1148 7C0803A6 */  mtlr     r0;
/* 807A114C 38210010 */  addi     r1, r1, 16;
/* 807A1150 4E800020 */  blr;

  // clang-format on
);

[[address(0x807A11A0)]]
void dNumberOfPeopleChange_c::initializeState_OnStageAnimeEndWait() ASM_METHOD(
  // clang-format off
/* 807A11A0 9421FFE0 */  stwu     r1, -32(r1);
/* 807A11A4 7C0802A6 */  mflr     r0;
/* 807A11A8 38800001 */  li       r4, 1;
/* 807A11AC 38A00000 */  li       r5, 0;
/* 807A11B0 90010024 */  stw      r0, 36(r1);
/* 807A11B4 93E1001C */  stw      r31, 28(r1);
/* 807A11B8 7C7F1B78 */  mr       r31, r3;
/* 807A11BC 93C10018 */  stw      r30, 24(r1);
/* 807A11C0 3BC00000 */  li       r30, 0;
/* 807A11C4 93A10014 */  stw      r29, 20(r1);
/* 807A11C8 3BA00001 */  li       r29, 1;
/* 807A11CC 9BA30687 */  stb      r29, 1671(r3);
/* 807A11D0 9BC30688 */  stb      r30, 1672(r3);
/* 807A11D4 38630404 */  addi     r3, r3, 1028;
/* 807A11D8 4B928209 */  bl       UNDEF_800c93e0;
/* 807A11DC 387F0404 */  addi     r3, r31, 1028;
/* 807A11E0 38800000 */  li       r4, 0;
/* 807A11E4 38A00000 */  li       r5, 0;
/* 807A11E8 4B9281F9 */  bl       UNDEF_800c93e0;
/* 807A11EC 3C608093 */  lis      r3, UNDEF_8093531c@ha;
/* 807A11F0          */  mr       r8, r31;
/* 807A11F4 C003531C */  lfs      f0, UNDEF_8093531c@l(r3);
/* 807A11F8 38DF06D0 */  addi     r6, r31, 1744;
/* 807A11FC 38BF06E0 */  addi     r5, r31, 1760;
/* 807A1200 389F06F0 */  addi     r4, r31, 1776;
/* 807A1204          */  li       r9, 0;
/* 807A1208 38E00003 */  li       r7, 3;
/* 807A120C 48000044 */  b        UNDEF_807a1250;
UNDEF_807a1210:;
/* 807A1210 80680074 */  lwz      r3, 116(r8);
/* 807A1214 39290001 */  addi     r9, r9, 1;
/* 807A1218 9BA30295 */  stb      r29, 661(r3);
/* 807A121C 806800A4 */  lwz      r3, 164(r8);
/* 807A1220 93C3023C */  stw      r30, 572(r3);
/* 807A1224 9BA30239 */  stb      r29, 569(r3);
/* 807A1228 90E30248 */  stw      r7, 584(r3);
/* 807A122C 93C3024C */  stw      r30, 588(r3);
/* 807A1230 D0030234 */  stfs     f0, 564(r3);
/* 807A1234 80680074 */  lwz      r3, 116(r8);
/* 807A1238 90C30284 */  stw      r6, 644(r3);
/* 807A123C 80680074 */  lwz      r3, 116(r8);
/* 807A1240 90A3028C */  stw      r5, 652(r3);
/* 807A1244 80680074 */  lwz      r3, 116(r8);
/* 807A1248 39080004 */  addi     r8, r8, 4;
/* 807A124C 90830290 */  stw      r4, 656(r3);
UNDEF_807a1250:;
/* 807A1250 801F06C4 */  lwz      r0, 1732(r31);
/* 807A1254 7C090000 */  cmpw     r9, r0;
/* 807A1258 4180FFB8 */  blt+     UNDEF_807a1210;
/* 807A125C 7FFDFB78 */  mr       r29, r31;
/* 807A1260 3BC00000 */  li       r30, 0;
UNDEF_807a1264:;
/* 807A1264 807D064C */  lwz      r3, OFFSET_dNumberOfPeopleChange_c_mpaPlayers(r29);
/* 807A1268 80630128 */  lwz      r3, 296(r3);
/* 807A126C 80630004 */  lwz      r3, 4(r3);
/* 807A1270 81830000 */  lwz      r12, 0(r3);
/* 807A1274 818C00AC */  lwz      r12, 172(r12);
/* 807A1278 7D8903A6 */  mtctr    r12;
/* 807A127C 4E800421 */  bctrl;
/* 807A1280 3BDE0001 */  addi     r30, r30, 1;
/* 807A1284 3BBD0004 */  addi     r29, r29, 4;
/* 807A1288          */  cmpwi    r30, NUM_PY_CHANGE_PLAYER_COUNT;
/* 807A128C 4180FFD8 */  blt+     UNDEF_807a1264;

                         // Don't prevent 2D Mario from jumping on this screen
// /* 807A1290 3C608043 */  lis      r3, m_nowScene__8dScene_c@ha;
// /* 807A1294 A0038A42 */  lhz      r0, m_nowScene__8dScene_c@l(r3);
// /* 807A1298 28000003 */  cmplwi   r0, 3;
// /* 807A129C 40820010 */  bne-     UNDEF_807a12ac;
// /* 807A12A0 807F064C */  lwz      r3, OFFSET_dNumberOfPeopleChange_c_mpaPlayers(r31);
// /* 807A12A4 38000001 */  li       r0, 1;
// /* 807A12A8 9803026A */  stb      r0, 618(r3);

UNDEF_807a12ac:;
/* 807A12AC 80010024 */  lwz      r0, 36(r1);
/* 807A12B0 83E1001C */  lwz      r31, 28(r1);
/* 807A12B4 83C10018 */  lwz      r30, 24(r1);
/* 807A12B8 83A10014 */  lwz      r29, 20(r1);
/* 807A12BC 7C0803A6 */  mtlr     r0;
/* 807A12C0 38210020 */  addi     r1, r1, 32;
/* 807A12C4 4E800020 */  blr;
  // clang-format on
);

[[address(0x807A1340)]]
void dNumberOfPeopleChange_c::finalizeState_OnStageAnimeEndWait()
{
    m0x687 = 0;
    for (int i = 0; i < NUM_PY_CHANGE_PLAYER_COUNT; i++) {
        mpaPlayers[i]->m0x267 = 0;
    }
}

[[address(0x807A1380)]]
void dNumberOfPeopleChange_c::executeState_InfoOnStageAnimeEndWait() ASM_METHOD(
  // clang-format off
/* 807A1380 9421FFE0 */  stwu     r1, -32(r1);
/* 807A1384 7C0802A6 */  mflr     r0;
/* 807A1388 90010024 */  stw      r0, 36(r1);
/* 807A138C 39610020 */  addi     r11, r1, 32;
/* 807A1390 4BB3BCD1 */  bl       UNDEF_802dd060;
/* 807A1394 3C808043 */  lis      r4, m_nowScene__8dScene_c@ha;
/* 807A1398 3FA08099 */  lis      r29, UNDEF_809944b8@ha;
/* 807A139C A0048A42 */  lhz      r0, m_nowScene__8dScene_c@l(r4);
/* 807A13A0 7C7A1B78 */  mr       r26, r3;
/* 807A13A4 3BBD44B8 */  addi     r29, r29, UNDEF_809944b8@l;
/* 807A13A8 28000003 */  cmplwi   r0, 3;
/* 807A13AC 40820080 */  bne-     UNDEF_807a142c;
/* 807A13B0 3B600000 */  li       r27, 0;
/* 807A13B4 3B800000 */  li       r28, 0;
/* 807A13B8 3FC08043 */  lis      r30, m_instance__13dRemoconMng_c@ha;
/* 807A13BC 3FE08037 */  lis      r31, UNDEF_80371b70@ha;
UNDEF_807a13c0:;
/* 807A13C0 801EA308 */  lwz      r0, m_instance__13dRemoconMng_c@l(r30);
/* 807A13C4 7C60E214 */  add      r3, r0, r28;
/* 807A13C8 80630004 */  lwz      r3, 4(r3);
/* 807A13CC 8583005C */  lwzu     r12, 92(r3);
/* 807A13D0 818C0028 */  lwz      r12, 40(r12);
/* 807A13D4 7D8903A6 */  mtctr    r12;
/* 807A13D8 4E800421 */  bctrl;
/* 807A13DC 81830000 */  lwz      r12, 0(r3);
/* 807A13E0 389F1B70 */  addi     r4, r31, UNDEF_80371b70@l;
/* 807A13E4 818C0010 */  lwz      r12, 16(r12);
/* 807A13E8 7D8903A6 */  mtctr    r12;
/* 807A13EC 4E800421 */  bctrl;
/* 807A13F0 2C030000 */  cmpwi    r3, 0;
/* 807A13F4 40820028 */  bne-     UNDEF_807a141c;
/* 807A13F8 7F63DB78 */  mr       r3, r27;
/* 807A13FC 4B913365 */  bl       UNDEF_800b4760;
/* 807A1400 2C030000 */  cmpwi    r3, 0;
/* 807A1404 41820018 */  beq-     UNDEF_807a141c;
/* 807A1408 3C608043 */  lis      r3, UNDEF_8042a5b8@ha;
/* 807A140C 7F64DB78 */  mr       r4, r27;
/* 807A1410 8063A5B8 */  lwz      r3, UNDEF_8042a5b8@l(r3);
/* 807A1414 4B96D2FD */  bl       UNDEF_8010e710;
/* 807A1418 4800008C */  b        UNDEF_807a14a4;
UNDEF_807a141c:;
/* 807A141C 3B7B0001 */  addi     r27, r27, 1;
/* 807A1420 3B9C0004 */  addi     r28, r28, 4;
/* 807A1424          */  cmpwi    r27, 4; // TODO
/* 807A1428 4180FF98 */  blt+     UNDEF_807a13c0;
UNDEF_807a142c:;
/* 807A142C 807A06A0 */  lwz      r3, 1696(r26);
/* 807A1430 801A06C4 */  lwz      r0, 1732(r26);
/* 807A1434 7C030000 */  cmpw     r3, r0;
/* 807A1438 41800054 */  blt-     UNDEF_807a148c;
/* 807A143C 3C608043 */  lis      r3, m_nowScene__8dScene_c@ha;
/* 807A1440 A0038A42 */  lhz      r0, m_nowScene__8dScene_c@l(r3);
/* 807A1444 28000003 */  cmplwi   r0, 3;
/* 807A1448 40820028 */  bne-     UNDEF_807a1470;
/* 807A144C 7F43D378 */  mr       r3, r26;
/* 807A1450 4BFFF601 */  bl       UNDEF_807a0a50;
/* 807A1454 819A059C */  lwz      r12, 1436(r26);
/* 807A1458 387A059C */  addi     r3, r26, 1436;
/* 807A145C 389D0110 */  addi     r4, r29, 272;
/* 807A1460 818C0018 */  lwz      r12, 24(r12);
/* 807A1464 7D8903A6 */  mtctr    r12;
/* 807A1468 4E800421 */  bctrl;
/* 807A146C 48000038 */  b        UNDEF_807a14a4;
UNDEF_807a1470:;
/* 807A1470 819A059C */  lwz      r12, 1436(r26);
/* 807A1474 387A059C */  addi     r3, r26, 1436;
/* 807A1478 389D0190 */  addi     r4, r29, 400;
/* 807A147C 818C0018 */  lwz      r12, 24(r12);
/* 807A1480 7D8903A6 */  mtctr    r12;
/* 807A1484 4E800421 */  bctrl;
/* 807A1488 4800001C */  b        UNDEF_807a14a4;
UNDEF_807a148c:;
/* 807A148C 819A059C */  lwz      r12, 1436(r26);
/* 807A1490 387A059C */  addi     r3, r26, 1436;
/* 807A1494 389D00D0 */  addi     r4, r29, 208;
/* 807A1498 818C0018 */  lwz      r12, 24(r12);
/* 807A149C 7D8903A6 */  mtctr    r12;
/* 807A14A0 4E800421 */  bctrl;
UNDEF_807a14a4:;
/* 807A14A4 39610020 */  addi     r11, r1, 32;
/* 807A14A8 4BB3BC05 */  bl       UNDEF_802dd0ac;
/* 807A14AC 80010024 */  lwz      r0, 36(r1);
/* 807A14B0 7C0803A6 */  mtlr     r0;
/* 807A14B4 38210020 */  addi     r1, r1, 32;
/* 807A14B8 4E800020 */  blr;
  // clang-format on
);

[[address(0x807A14D0)]]
void dNumberOfPeopleChange_c::initializeState_NowEntrantRecruit() ASM_METHOD(
  // clang-format off
/* 807A14D0 38A00001 */  li       r5, 1;
/* 807A14D4 98A30680 */  stb      r5, 1664(r3);
/* 807A14D8          */  mr       r6, r3;
/* 807A14DC          */  li       r7, 0;
/* 807A14E0 48000018 */  b        UNDEF_807a14f8;
UNDEF_807a14e8:;
/* 807A14E8 80860074 */  lwz      r4, 116(r6);
/* 807A14EC 38C60004 */  addi     r6, r6, 4;
/* 807A14F0 38E70001 */  addi     r7, r7, 1;
/* 807A14F4 98A40299 */  stb      r5, 665(r4);
UNDEF_807a14f8:;
/* 807A14F8 800306C4 */  lwz      r0, 1732(r3);
/* 807A14FC 7C070000 */  cmpw     r7, r0;
/* 807A1500 4180FFE8 */  blt+     UNDEF_807a14e8;
/* 807A1504 4BFFF54C */  b        UNDEF_807a0a50;
  // clang-format on
);

[[address(0x807A1510)]]
void dNumberOfPeopleChange_c::executeState_NowEntrantRecruit() ASM_METHOD(
  // clang-format off
/* 807A1510 9421FFF0 */  stwu     r1, -16(r1);
/* 807A1514 7C0802A6 */  mflr     r0;
/* 807A1518          */  mr       r4, r3;
/* 807A151C 90010014 */  stw      r0, 20(r1);
/* 807A1520 93E1000C */  stw      r31, 12(r1);
/* 807A1524 7C7F1B78 */  mr       r31, r3;
/* 807A1528 80A306C4 */  lwz      r5, 1732(r3);
/* 807A1530          */  mtctr    r5;
/* 807A1534          */  cmpwi    r5, 0;
/* 807A1538 40810020 */  ble-     UNDEF_807a1558;
UNDEF_807a1540:;
/* 807A1540 80640074 */  lwz      r3, 116(r4);
/* 807A1544 88030296 */  lbz      r0, 662(r3);
/* 807A1548 2C000000 */  cmpwi    r0, 0;
/* 807A154C 40820154 */  bne-     UNDEF_807a16a0;
/* 807A1550 38840004 */  addi     r4, r4, 4;
/* 807A1554 4200FFEC */  bdnz+    UNDEF_807a1540;
UNDEF_807a1558:;
/* 807A1558 7FE3FB78 */  mr       r3, r31;
/* 807A155C 4BFFF7C5 */  bl       UNDEF_807a0d20;
/* 807A1560 2C030000 */  cmpwi    r3, 0;
/* 807A1564 418200B0 */  beq-     UNDEF_807a1614;
/* 807A1568 3C608043 */  lis      r3, m_nowScene__8dScene_c@ha;
/* 807A156C A0038A42 */  lhz      r0, m_nowScene__8dScene_c@l(r3);
/* 807A1570 28000003 */  cmplwi   r0, 3;
/* 807A1574 4082001C */  bne-     UNDEF_807a1590;
/* 807A1578 3C608043 */  lis      r3, UNDEF_8042a768@ha;
/* 807A157C 38800079 */  li       r4, 121;
/* 807A1580 8063A768 */  lwz      r3, UNDEF_8042a768@l(r3);
/* 807A1584 38A00001 */  li       r5, 1;
/* 807A1588 4B9F3F39 */  bl       UNDEF_801954c0;
/* 807A158C 48000018 */  b        UNDEF_807a15a4;
UNDEF_807a1590:;
/* 807A1590 3C608043 */  lis      r3, UNDEF_8042a768@ha;
/* 807A1594 3880007A */  li       r4, 122;
/* 807A1598 8063A768 */  lwz      r3, UNDEF_8042a768@l(r3);
/* 807A159C 38A00001 */  li       r5, 1;
/* 807A15A0 4B9F3F21 */  bl       UNDEF_801954c0;
UNDEF_807a15a4:;
/* 807A15A4 3C608043 */  lis      r3, m_nowScene__8dScene_c@ha;
/* 807A15A8 A0038A42 */  lhz      r0, m_nowScene__8dScene_c@l(r3);
/* 807A15AC 28000003 */  cmplwi   r0, 3;
/* 807A15B0 40820010 */  bne-     UNDEF_807a15c0;
/* 807A15B4 38000000 */  li       r0, 0;
/* 807A15B8 901F06C8 */  stw      r0, 1736(r31);
/* 807A15BC 4800000C */  b        UNDEF_807a15c8;
UNDEF_807a15c0:;
/* 807A15C0 38000001 */  li       r0, 1;
/* 807A15C4 901F06C8 */  stw      r0, 1736(r31);
UNDEF_807a15c8:;
/* 807A15C8          */  mr       r5, r31;
/* 807A15CC          */  li       r6, 0;
/* 807A15D0 38800001 */  li       r4, 1;
/* 807A15D4 48000014 */  b        UNDEF_807a15e8;
UNDEF_807a15d8:;
/* 807A15D8 80650074 */  lwz      r3, 116(r5);
/* 807A15DC 38A50004 */  addi     r5, r5, 4;
/* 807A15E0 38C60001 */  addi     r6, r6, 1;
/* 807A15E4 9883029B */  stb      r4, 667(r3);
UNDEF_807a15e8:;
/* 807A15E8 801F06C4 */  lwz      r0, 1732(r31);
/* 807A15EC 7C060000 */  cmpw     r6, r0;
/* 807A15F0 4180FFE8 */  blt+     UNDEF_807a15d8;
/* 807A15F4 819F059C */  lwz      r12, 1436(r31);
/* 807A15F8 3C808099 */  lis      r4, UNDEF_80994748@ha;
/* 807A15FC 387F059C */  addi     r3, r31, 1436;
/* 807A1600 818C0018 */  lwz      r12, 24(r12);
/* 807A1604 38844748 */  addi     r4, r4, UNDEF_80994748@l;
/* 807A1608 7D8903A6 */  mtctr    r12;
/* 807A160C 4E800421 */  bctrl;
/* 807A1610 48000090 */  b        UNDEF_807a16a0;
UNDEF_807a1614:;
/* 807A1614 3C608043 */  lis      r3, m_nowScene__8dScene_c@ha;
/* 807A1618 A0038A42 */  lhz      r0, m_nowScene__8dScene_c@l(r3);
/* 807A161C 28000003 */  cmplwi   r0, 3;
/* 807A1620 41820080 */  beq-     UNDEF_807a16a0;
/* 807A1624 807F06C4 */  lwz      r3, 1732(r31);
/* 807A1628          */  mr       r4, r31;
/* 807A1630          */  mtctr    r3;
/* 807A1634          */  cmpwi    r3, 0;
/* 807A1638 40810020 */  ble-     UNDEF_807a1658;
UNDEF_807a1640:;
/* 807A1640 80640074 */  lwz      r3, 116(r4);
/* 807A1644 8803029A */  lbz      r0, 666(r3);
/* 807A1648 2C000000 */  cmpwi    r0, 0;
/* 807A164C 41820054 */  beq-     UNDEF_807a16a0;
/* 807A1650 38840004 */  addi     r4, r4, 4;
/* 807A1654 4200FFEC */  bdnz+    UNDEF_807a1640;
UNDEF_807a1658:;
/* 807A1658          */  mr       r5, r31;
/* 807A165C          */  li       r6, 0;
/* 807A1660 38800001 */  li       r4, 1;
/* 807A1664 48000014 */  b        UNDEF_807a1678;
UNDEF_807a1668:;
/* 807A1668 80650074 */  lwz      r3, 116(r5);
/* 807A166C 38A50004 */  addi     r5, r5, 4;
/* 807A1670 38C60001 */  addi     r6, r6, 1;
/* 807A1674 9883029B */  stb      r4, 667(r3);
UNDEF_807a1678:;
/* 807A1678 801F06C4 */  lwz      r0, 1732(r31);
/* 807A167C 7C060000 */  cmpw     r6, r0;
/* 807A1680 4180FFE8 */  blt+     UNDEF_807a1668;
/* 807A1684 819F059C */  lwz      r12, 1436(r31);
/* 807A1688 3C808099 */  lis      r4, UNDEF_80994608@ha;
/* 807A168C 387F059C */  addi     r3, r31, 1436;
/* 807A1690 818C0018 */  lwz      r12, 24(r12);
/* 807A1694 38844608 */  addi     r4, r4, UNDEF_80994608@l;
/* 807A1698 7D8903A6 */  mtctr    r12;
/* 807A169C 4E800421 */  bctrl;
UNDEF_807a16a0:;
/* 807A16A0 80010014 */  lwz      r0, 20(r1);
/* 807A16A4 83E1000C */  lwz      r31, 12(r1);
/* 807A16A8 7C0803A6 */  mtlr     r0;
/* 807A16AC 38210010 */  addi     r1, r1, 16;
/* 807A16B0 4E800020 */  blr;
  // clang-format on
);

[[address(0x807A16D0)]]
void dNumberOfPeopleChange_c::initializeState_StoryModeCourseSelectExitWait() ASM_METHOD(
  // clang-format off
/* 807A16D0 38A00001 */  li       r5, 1;
/* 807A16D4 98A30680 */  stb      r5, 1664(r3);
/* 807A16D8          */  mr       r6, r3;
/* 807A16DC          */  li       r7, 0;
/* 807A16E0 48000020 */  b        UNDEF_807a1700;
UNDEF_807a16e8:;
/* 807A16E8 80860074 */  lwz      r4, 116(r6);
/* 807A16EC 38E70001 */  addi     r7, r7, 1;
/* 807A16F0 98A40295 */  stb      r5, 661(r4);
/* 807A16F4 80860074 */  lwz      r4, 116(r6);
/* 807A16F8 38C60004 */  addi     r6, r6, 4;
/* 807A16FC 98A40299 */  stb      r5, 665(r4);
UNDEF_807a1700:;
/* 807A1700 800306C4 */  lwz      r0, 1732(r3);
/* 807A1704 7C070000 */  cmpw     r7, r0;
/* 807A1708 4180FFE0 */  blt+     UNDEF_807a16e8;
/* 807A170C 4E800020 */  blr;
  // clang-format on
);

[[address(0x807A1710)]]
void dNumberOfPeopleChange_c::executeState_StoryModeCourseSelectExitWait() ASM_METHOD(
  // clang-format off
/* 807A1710 9421FFF0 */  stwu     r1, -16(r1);
/* 807A1714 7C0802A6 */  mflr     r0;
/* 807A1718          */  mr       r4, r3;
/* 807A171C 90010014 */  stw      r0, 20(r1);
/* 807A1720 93E1000C */  stw      r31, 12(r1);
/* 807A1724 7C7F1B78 */  mr       r31, r3;
/* 807A1728 80A306C4 */  lwz      r5, 1732(r3);
/* 807A1730          */  mtctr    r5;
/* 807A1734          */  cmpwi    r5, 0;
/* 807A1738 40810020 */  ble-     UNDEF_807a1758;
UNDEF_807a1740:;
/* 807A1740 80640074 */  lwz      r3, 116(r4);
/* 807A1744 88030296 */  lbz      r0, 662(r3);
/* 807A1748 2C000000 */  cmpwi    r0, 0;
/* 807A174C 408200AC */  bne-     UNDEF_807a17f8;
/* 807A1750 38840004 */  addi     r4, r4, 4;
/* 807A1754 4200FFEC */  bdnz+    UNDEF_807a1740;
UNDEF_807a1758:;
/* 807A1758 7FE3FB78 */  mr       r3, r31;
/* 807A175C 4BFFF5C5 */  bl       UNDEF_807a0d20;
/* 807A1760 2C030000 */  cmpwi    r3, 0;
/* 807A1764 41820094 */  beq-     UNDEF_807a17f8;
/* 807A1768 3C608043 */  lis      r3, m_nowScene__8dScene_c@ha;
/* 807A176C A0038A42 */  lhz      r0, m_nowScene__8dScene_c@l(r3);
/* 807A1770 28000003 */  cmplwi   r0, 3;
/* 807A1774 4082001C */  bne-     UNDEF_807a1790;
/* 807A1778 3C608043 */  lis      r3, UNDEF_8042a768@ha;
/* 807A177C 38800079 */  li       r4, 121;
/* 807A1780 8063A768 */  lwz      r3, UNDEF_8042a768@l(r3);
/* 807A1784 38A00001 */  li       r5, 1;
/* 807A1788 4B9F3D39 */  bl       UNDEF_801954c0;
/* 807A178C 48000018 */  b        UNDEF_807a17a4;
UNDEF_807a1790:;
/* 807A1790 3C608043 */  lis      r3, UNDEF_8042a768@ha;
/* 807A1794 3880007A */  li       r4, 122;
/* 807A1798 8063A768 */  lwz      r3, UNDEF_8042a768@l(r3);
/* 807A179C 38A00001 */  li       r5, 1;
/* 807A17A0 4B9F3D21 */  bl       UNDEF_801954c0;
UNDEF_807a17a4:;
/* 807A17A4 38000000 */  li       r0, 0;
/* 807A17A8 901F06C8 */  stw      r0, 1736(r31);
/* 807A17AC          */  mr       r5, r31;
/* 807A17B0          */  li       r6, 0;
/* 807A17B4 38800001 */  li       r4, 1;
/* 807A17B8 48000018 */  b        UNDEF_807a17d0;
UNDEF_807a17c0:;
/* 807A17C0 80650074 */  lwz      r3, 116(r5);
/* 807A17C4 38A50004 */  addi     r5, r5, 4;
/* 807A17C8 38C60001 */  addi     r6, r6, 1;
/* 807A17CC 9883029B */  stb      r4, 667(r3);
UNDEF_807a17d0:;
/* 807A17D0 801F06C4 */  lwz      r0, 1732(r31);
/* 807A17D4 7C060000 */  cmpw     r6, r0;
/* 807A17D8 4180FFE8 */  blt+     UNDEF_807a17c0;
/* 807A17DC 819F059C */  lwz      r12, 1436(r31);
/* 807A17E0 3C808099 */  lis      r4, UNDEF_80994748@ha;
/* 807A17E4 387F059C */  addi     r3, r31, 1436;
/* 807A17E8 818C0018 */  lwz      r12, 24(r12);
/* 807A17EC 38844748 */  addi     r4, r4, UNDEF_80994748@l;
/* 807A17F0 7D8903A6 */  mtctr    r12;
/* 807A17F4 4E800421 */  bctrl;
UNDEF_807a17f8:;
/* 807A17F8 80010014 */  lwz      r0, 20(r1);
/* 807A17FC 83E1000C */  lwz      r31, 12(r1);
/* 807A1800 7C0803A6 */  mtlr     r0;
/* 807A1804 38210010 */  addi     r1, r1, 16;
/* 807A1808 4E800020 */  blr;
  // clang-format on
);

[[address(0x807A1860)]]
void dNumberOfPeopleChange_c::initializeState_ButtonOnStageAnimeEndWait()
{
    m0x404.AnimeStartSetup(4, false);
    m0x404.AnimeStartSetup(2, false);
    m0x404.AnimeStartSetup(5, false);
    m0x404.AnimeStartSetup(3, false);

    for (int i = 0; i < NUM_PY_CHANGE_PLAYER_COUNT; i++) {
        mpaPlayers[i]->m0x266 = 1;
    }

    for (int i = 0; i < 4; i++) {
        auto* cc = mpaCcIndicator[i];
        cc->mp0x21C->SetVisible(false);
        cc->mp0x220->SetVisible(false);
    }

    m0x688 = 1;
    m0x680 = 0;
}

[[address(0x807A1B60)]]
void dNumberOfPeopleChange_c::executeState_ButtonSelect()
{
    int newBtn = mSelectedButton;
    if (newBtn == 0 &&
        dGameKey_c::m_instance->mpCores[int(mPad::g_currentCoreID)]->mTriggered & 0x8) {
        newBtn = 1;
    }
    if (newBtn == 1 &&
        dGameKey_c::m_instance->mpCores[int(mPad::g_currentCoreID)]->mTriggered & 0x4) {
        newBtn = 0;
    }

    if (newBtn != mSelectedButton) {
        SndAudioMgr::sInstance->startSystemSe(SE_SYS_CURSOR, 1);
        mLastSelectedButton = mSelectedButton;
        mSelectedButton = newBtn;
        mStateMgr.changeState(StateID_ButtonChangeAnimeEndWait);
        return;
    }

    if (mPad::g_currentCore->downTrigger(0x900)) {
        if (mSelectedButton == 0) {
            SndAudioMgr::sInstance->startSystemSe(SE_SYS_DECIDE, 1);
            if (!(dInfo_c::m_instance->mGameFlag & 0x10)) {
                // TODO: Mini-mario pitch up
                static const u16 PlayerDecideSounds[] = {
                  SE_VOC_MA_PLAYER_DECIDE,   SE_VOC_LU_CS_DECIDE_JOIN,  SE_VOC_KO_CS_DECIDE_JOIN,
                  SE_VOC_KO2_CS_DECIDE_JOIN, SE_VOC_KC_PLAYER_DECIDE,   SE_VOC_KC_CS_DECIDE_JOIN,
                  SE_VOC_KO_CS_DECIDE_JOIN,  SE_VOC_KO2_CS_DECIDE_JOIN,
                };

                u16 sound = PlayerDecideSounds[int(daPyMng_c::mPlayerType[0]) % 8];
                SndAudioMgr::sInstance->startSystemSe(sound, 1);
            }
        } else {
            SndAudioMgr::sInstance->startSystemSe(SE_SYS_BACK, 1);
        }
        mStateMgr.changeState(StateID_ButtonDecision);
        return;
    }
}

[[address(0x807A1E80)]]
void dNumberOfPeopleChange_c::executeState_ExitAnimeEndCheck() ASM_METHOD(
  // clang-format off
/* 807A1E80 9421FFF0 */  stwu     r1, -16(r1);
/* 807A1E84 7C0802A6 */  mflr     r0;
/* 807A1E88 3880FFFF */  li       r4, -1;
/* 807A1E8C 90010014 */  stw      r0, 20(r1);
/* 807A1E90 93E1000C */  stw      r31, 12(r1);
/* 807A1E94 7C7F1B78 */  mr       r31, r3;
/* 807A1E98 38630404 */  addi     r3, r3, 1028;
/* 807A1E9C 4B927865 */  bl       UNDEF_800c9700;
/* 807A1EA0 2C030000 */  cmpwi    r3, 0;
/* 807A1EA4 408201C4 */  bne-     UNDEF_807a2068;
/* 807A1EA8 80BF05D8 */  lwz      r5, 1496(r31);
/* 807A1EAC 3C808099 */  lis      r4, UNDEF_809944c8@ha;
/* 807A1EB0 387F059C */  addi     r3, r31, 1436;
/* 807A1EB4 880500BB */  lbz      r0, 187(r5);
/* 807A1EB8 388444C8 */  addi     r4, r4, UNDEF_809944c8@l;
/* 807A1EBC 5400063C */  rlwinm   r0, r0, 0, 24, 30;
/* 807A1EC0 980500BB */  stb      r0, 187(r5);
/* 807A1EC4 819F059C */  lwz      r12, 1436(r31);
/* 807A1EC8 818C0018 */  lwz      r12, 24(r12);
/* 807A1ECC 7D8903A6 */  mtctr    r12;
/* 807A1ED0 4E800421 */  bctrl    ;
/* 807A1ED4 38000000 */  li       r0, 0;
/* 807A1ED8 981F067E */  stb      r0, 1662(r31);
/* 807A1EDC 3C608043 */  lis      r3, m_instance__7dInfo_c@ha;
/* 807A1EE0 3C808093 */  lis      r4, UNDEF_809352a0@ha;
/* 807A1EE4 8103A25C */  lwz      r8, m_instance__7dInfo_c@l(r3);
/* 807A1EE8 3CC08035 */  lis      r6, mPlayerType__9daPyMng_c@ha;
/* 807A1EEC 39200004 */  li       r9, 4;
/* 807A1EF0 7FE5FB78 */  mr       r5, r31;
/* 807A1EF4 7D074378 */  mr       r7, r8;
/* 807A1EF8 98080AFC */  stb      r0, 2812(r8);
/* 807A1EFC 388452A0 */  addi     r4, r4, UNDEF_809352a0@l;
/* 807A1F00 38C65160 */  addi     r6, r6, mPlayerType__9daPyMng_c@l;
/* 807A1F04 3C608043 */  lis      r3, m_nowScene__8dScene_c@ha;
/* 807A1F08 39600001 */  li       r11, 1;
/* 807A1F0C 7D2903A6 */  mtctr    r9;
UNDEF_807a1f10:;
/* 807A1F10 813F06C8 */  lwz      r9, 1736(r31);
/* 807A1F14 2C090001 */  cmpwi    r9, 1;
/* 807A1F18 4082001C */  bne-     UNDEF_807a1f34;
/* 807A1F1C A1238A42 */  lhz      r9, m_nowScene__8dScene_c@l(r3);
/* 807A1F20 2809000A */  cmplwi   r9, 10;
/* 807A1F24 40820010 */  bne-     UNDEF_807a1f34;
/* 807A1F28 81240000 */  lwz      r9, 0(r4);
/* 807A1F2C 912506E0 */  stw      r9, 1760(r5);
/* 807A1F30 91260000 */  stw      r9, 0(r6);
UNDEF_807a1f34:;
/* 807A1F34 81260000 */  lwz      r9, 0(r6);
/* 807A1F38 5529103A */  slwi     r9, r9, 2;
/* 807A1F3C 7D3F4A14 */  add      r9, r31, r9;
/* 807A1F40 8149064C */  lwz      r10, OFFSET_dNumberOfPeopleChange_c_mpaPlayers(r9);
/* 807A1F44 892A0261 */  lbz      r9, 609(r10);
/* 807A1F48 2C090000 */  cmpwi    r9, 0;
/* 807A1F4C 41820008 */  beq-     UNDEF_807a1f54;
/* 807A1F50 996A0269 */  stb      r11, 617(r10);
UNDEF_807a1f54:;
/* 807A1F54 90070384 */  stw      r0, 900(r7);
/* 807A1F58 38840004 */  addi     r4, r4, 4;
/* 807A1F5C 38C60004 */  addi     r6, r6, 4;
/* 807A1F60 38E70004 */  addi     r7, r7, 4;
/* 807A1F64 818500A4 */  lwz      r12, 164(r5);
/* 807A1F68 814C020C */  lwz      r10, 524(r12);
/* 807A1F6C 892A00BB */  lbz      r9, 187(r10);
/* 807A1F70 5529063C */  rlwinm   r9, r9, 0, 24, 30;
/* 807A1F74 992A00BB */  stb      r9, 187(r10);
/* 807A1F78 814C0210 */  lwz      r10, 528(r12);
/* 807A1F7C 892A00BB */  lbz      r9, 187(r10);
/* 807A1F80 5529063C */  rlwinm   r9, r9, 0, 24, 30;
/* 807A1F84 992A00BB */  stb      r9, 187(r10);
/* 807A1F88 814C0214 */  lwz      r10, 532(r12);
/* 807A1F8C 892A00BB */  lbz      r9, 187(r10);
/* 807A1F90 5529063C */  rlwinm   r9, r9, 0, 24, 30;
/* 807A1F94 992A00BB */  stb      r9, 187(r10);
/* 807A1F98 814C0218 */  lwz      r10, 536(r12);
/* 807A1F9C 892A00BB */  lbz      r9, 187(r10);
/* 807A1FA0 5529063C */  rlwinm   r9, r9, 0, 24, 30;
/* 807A1FA4 992A00BB */  stb      r9, 187(r10);
/* 807A1FA8 812500A4 */  lwz      r9, 164(r5);
/* 807A1FAC 38A50004 */  addi     r5, r5, 4;
/* 807A1FB0 9009023C */  stw      r0, 572(r9);
/* 807A1FB4 98090239 */  stb      r0, 569(r9);
/* 807A1FB8 4200FF58 */  bdnz+    UNDEF_807a1f10;
/* 807A1FBC 801F06C8 */  lwz      r0, 1736(r31);
/* 807A1FC0 2C000001 */  cmpwi    r0, 1;
/* 807A1FC4 40820060 */  bne-     UNDEF_807a2024;
/* 807A1FC8 801F0690 */  lwz      r0, 1680(r31);
/* 807A1FCC 2C000003 */  cmpwi    r0, 3;
/* 807A1FD0 41820008 */  beq-     UNDEF_807a1fd8;
/* 807A1FD4 38000000 */  li       r0, 0;
UNDEF_807a1fd8:;
/* 807A1FD8 90080384 */  stw      r0, 900(r8);
/* 807A1FDC 801F0694 */  lwz      r0, 1684(r31);
/* 807A1FE0 2C000003 */  cmpwi    r0, 3;
/* 807A1FE4 41820008 */  beq-     UNDEF_807a1fec;
/* 807A1FE8 38000000 */  li       r0, 0;
UNDEF_807a1fec:;
/* 807A1FEC 90080388 */  stw      r0, 904(r8);
/* 807A1FF0 387F0008 */  addi     r3, r31, 8;
/* 807A1FF4 38880008 */  addi     r4, r8, 8;
/* 807A1FF8 801F0698 */  lwz      r0, 1688(r31);
/* 807A1FFC 2C000003 */  cmpwi    r0, 3;
/* 807A2000 41820008 */  beq-     UNDEF_807a2008;
/* 807A2004 38000000 */  li       r0, 0;
UNDEF_807a2008:;
/* 807A2008 90040384 */  stw      r0, 900(r4);
/* 807A200C 80030694 */  lwz      r0, 1684(r3);
/* 807A2010 2C000003 */  cmpwi    r0, 3;
/* 807A2014 41820008 */  beq-     UNDEF_807a201c;
/* 807A2018 38000000 */  li       r0, 0;
UNDEF_807a201c:;
/* 807A201C 90040388 */  stw      r0, 904(r4);
/* 807A2020 48000024 */  b        UNDEF_807a2044;
UNDEF_807a2024:;
/* 807A2024 7FE3FB78 */  mr       r3, r31;
/* 807A2028 4BFFEBC9 */  bl       UNDEF_807a0bf0;
/* 807A202C 7FE3FB78 */  mr       r3, r31;
/* 807A2030 4BFFE791 */  bl       UNDEF_807a07c0;
/* 807A2034 3C608043 */  lis      r3, UNDEF_8042a5b8@ha;
/* 807A2038 38000001 */  li       r0, 1;
/* 807A203C 8063A5B8 */  lwz      r3, UNDEF_8042a5b8@l(r3);
/* 807A2040 98030B8D */  stb      r0, 2957(r3);
UNDEF_807a2044:;
/* 807A2044 3C608043 */  lis      r3, UNDEF_8042a25c@ha;
/* 807A2048 8063A25C */  lwz      r3, UNDEF_8042a25c@l(r3);
/* 807A204C 3BE30008 */  addi     r31, r3, 8;
/* 807A2050 7FE3FB78 */  mr       r3, r31;
/* 807A2054 4B8ECE6D */  bl       UNDEF_8008eec0;
/* 807A2058 2C030000 */  cmpwi    r3, 0;
/* 807A205C 4082000C */  bne-     UNDEF_807a2068;
/* 807A2060 7FE3FB78 */  mr       r3, r31;
/* 807A2064 4B8ECD4D */  bl       UNDEF_8008edb0;
UNDEF_807a2068:;
/* 807A2068 80010014 */  lwz      r0, 20(r1);
/* 807A206C 83E1000C */  lwz      r31, 12(r1);
/* 807A2070 7C0803A6 */  mtlr     r0;
/* 807A2074 38210010 */  addi     r1, r1, 16;
/* 807A2078 4E800020 */  blr;
  // clang-format on
);

[[address(0x807A2080)]]
void dNumberOfPeopleChange_c::finalizeState_ExitAnimeEndCheck()
{
    for (int i = 0; i < NUM_PY_CHANGE_PLAYER_COUNT; i++) {
        mpaPlayers[i]->m0x266 = 0;
        mpaPlayers[i]->m0x269 = 1;

        if (dScene_c::m_nowScene == 3) {
            mpaPlayers[i]->m0x26A = 0;
        }
    }

    for (int i = 0; i < 4; i++) {
        mpaCcSelBase[i]->m0x298 = 1;
        mpaCcSelContents[i]->m0x2A0 = 1;
        mpaCcSelArrow[i]->m0x26C = 1;
    }
}

// Notes:
// 807a09d0 chooses which bases are used