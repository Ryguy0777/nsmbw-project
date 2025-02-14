// d_StockItem.cpp
// NSMBW d_bases.text: 0x807AF370 - 0x807B2030

#include "d_StockItem.h"

[[address(0x807AF370)]]
dStockItem_c* dStockItem_c_classInit()
{
    return new dStockItem_c();
}

[[address(0x807AF3A0)]]
dStockItem_c::dStockItem_c();

[[address(0x807B00A0)]]
void dStockItem_c::calc2DPlayerItemUpdate() ASM_METHOD(
  // clang-format off
/* 807B00A0 9421FF90 */  stwu     r1, -112(r1);
/* 807B00A4 7C0802A6 */  mflr     r0;
/* 807B00A8 90010074 */  stw      r0, 116(r1);
/* 807B00AC 39610070 */  addi     r11, r1, 112;
/* 807B00B0 4BB2CF9D */  bl       UNDEF_802dd04c;
/* 807B00B4 800308A0 */  lwz      r0, 2208(r3);
/* 807B00B8 7C771B78 */  mr       r23, r3;
/* 807B00BC 3B400000 */  li       r26, 0;
/* 807B00C0 2C000006 */  cmpwi    r0, 6;
/* 807B00C4 40820104 */  bne-     UNDEF_807b01c8;
/* 807B00C8 3EC08035 */  lis      r22, mCreateItem__9daPyMng_c@ha;
/* 807B00CC 3F608035 */  lis      r27, mPlayerType__9daPyMng_c@ha;
/* 807B00D0 7EFCBB78 */  mr       r28, r23;
/* 807B00D4 3BA00000 */  li       r29, 0;
/* 807B00D8 3B7B5160 */  addi     r27, r27, mPlayerType__9daPyMng_c@l;
/* 807B00DC 3AD65180 */  addi     r22, r22, mCreateItem__9daPyMng_c@l;
/* 807B00E0 3B000001 */  li       r24, 1;
UNDEF_807b00e4:;
/* 807B00E4 801B0000 */  lwz      r0, 0(r27);
/* 807B00E8 5400103A */  slwi     r0, r0, 2;
/* 807B00EC 7C16002E */  lwzx     r0, r22, r0;
/* 807B00F0 540007FF */  clrlwi.  r0, r0, 31;
/* 807B00F4 408200BC */  bne-     UNDEF_807b01b0;

                         cmpwi    r29, 4;
                         bge-     UNDEF_807b0108;

/* 807B00F8 7C77EA14 */  add      r3, r23, r29;
/* 807B00FC 880308D8 */  lbz      r0, 0x8D8(r3);
/* 807B0100 2C000000 */  cmpwi    r0, 0;
/* 807B0104 418200AC */  beq-     UNDEF_807b01b0;
UNDEF_807b0108:;
/* 807B0108 2C1A0000 */  cmpwi    r26, 0;
/* 807B010C 40820008 */  bne-     UNDEF_807b0114;
/* 807B0110 4B951111 */  bl       startStarSound__12daWmPlayer_cFv;
UNDEF_807b0114:;
/* 807B0114 833B0000 */  lwz      r25, 0(r27);
/* 807B0118 5720103A */  slwi     r0, r25, 2;
/* 807B011C 7F16012E */  stwx     r24, r22, r0;
/* 807B0120 7FD70214 */  add      r30, r23, r0;
/* 807B0124          */  lwz      r4, dStockItem_c_OFFSET_mpa2DPlayer(r30);
/* 807B0128 80640128 */  lwz      r3, 296(r4);
/* 807B012C C00400B4 */  lfs      f0, 180(r4);
/* 807B0130 80630004 */  lwz      r3, 4(r3);
/* 807B0134 C02400B0 */  lfs      f1, 176(r4);
/* 807B0138 81830000 */  lwz      r12, 0(r3);
/* 807B013C C04400AC */  lfs      f2, 172(r4);
/* 807B0140 818C0040 */  lwz      r12, 64(r12);
/* 807B0144 D0410030 */  stfs     f2, 48(r1);
/* 807B0148 D0210034 */  stfs     f1, 52(r1);
/* 807B014C D0010038 */  stfs     f0, 56(r1);
/* 807B0150 7D8903A6 */  mtctr    r12;
/* 807B0154 4E800421 */  bctrl;
/* 807B0158          */  lwz      r3, dStockItem_c_OFFSET_mpa2DPlayer(r30);
/* 807B015C 80630128 */  lwz      r3, 296(r3);
/* 807B0160 80630004 */  lwz      r3, 4(r3);
/* 807B0164 81830000 */  lwz      r12, 0(r3);
/* 807B0168 818C0048 */  lwz      r12, 72(r12);
/* 807B016C 7D8903A6 */  mtctr    r12;
/* 807B0170 4E800421 */  bctrl;
/* 807B0190 3B400001 */  li       r26, 1;

                         // Can't play the item use effect here yet for 5+
                         cmpwi    r29, 4;
                         bge-     UNDEF_807b01b0;

/* 807B0174 933C0890 */  stw      r25, 0x890(r28);
/* 807B0178 7EE3BB78 */  mr       r3, r23;
/* 807B017C C0010038 */  lfs      f0, 56(r1);
/* 807B0180 7FA6EB78 */  mr       r6, r29;
/* 807B0184 C0210034 */  lfs      f1, 52(r1);
/* 807B0188 38A10018 */  addi     r5, r1, 24;
/* 807B018C C0410030 */  lfs      f2, 48(r1);
/* 807B0194 D0410018 */  stfs     f2, 24(r1);
/* 807B0198 D021001C */  stfs     f1, 28(r1);
/* 807B019C D0010020 */  stfs     f0, 32(r1);
/* 807B01A0 809E02E4 */  lwz      r4, 740(r30);
/* 807B01A4 80040004 */  lwz      r0, 4(r4);
/* 807B01A8 5404073E */  clrlwi   r4, r0, 28;
/* 807B01AC 480001B5 */  bl       UNDEF_807b0360;
UNDEF_807b01b0:;
/* 807B01B0 3BBD0001 */  addi     r29, r29, 1;
/* 807B01B4 3B9C0004 */  addi     r28, r28, 4;
/* 807B01B8          */  cmpwi    r29, PLAYER_COUNT;
/* 807B01BC 3B7B0004 */  addi     r27, r27, 4;
/* 807B01C0 4180FF24 */  blt+     UNDEF_807b00e4;
/* 807B01C4 480000EC */  b        UNDEF_807b02b0;
UNDEF_807b01c8:;
/* 807B01C8 3F808035 */  lis      r28, mPlayerType__9daPyMng_c@ha;
/* 807B01CC 3FC08035 */  lis      r30, mCreateItem__9daPyMng_c@ha;
/* 807B01D0 3FE08035 */  lis      r31, mPlayerMode__9daPyMng_c@ha;
/* 807B01D4 3EC08093 */  lis      r22, UNDEF_809359d8@ha;
/* 807B01D8 83230328 */  lwz      r25, 808(r3);
/* 807B01DC 7EFBBB78 */  mr       r27, r23;
/* 807B01E0 3B9C5160 */  addi     r28, r28, mPlayerType__9daPyMng_c@l;
/* 807B01E4 3BDE5180 */  addi     r30, r30, mCreateItem__9daPyMng_c@l;
/* 807B01E8 3BFF5170 */  addi     r31, r31, mPlayerMode__9daPyMng_c@l;
/* 807B01EC 3AD659D8 */  addi     r22, r22, UNDEF_809359d8@l;
/* 807B01F0 3B000000 */  li       r24, 0;
UNDEF_807b01f4:;
/* 807B01F4 83BC0000 */  lwz      r29, 0(r28);
/* 807B01F8 7F23CB78 */  mr       r3, r25;
/* 807B01FC 38A10008 */  addi     r5, r1, 8;
/* 807B0200 57B5103A */  slwi     r21, r29, 2;
/* 807B0204 7C1EA82E */  lwzx     r0, r30, r21;
/* 807B0208 7C9FA82E */  lwzx     r4, r31, r21;
/* 807B020C 540007FE */  clrlwi   r0, r0, 31;
/* 807B0210 98010008 */  stb      r0, 8(r1);
/* 807B0214 4B94C74D */  bl       UNDEF_800fc960;
/* 807B0218 7C1FA82E */  lwzx     r0, r31, r21;
/* 807B021C 7C030000 */  cmpw     r3, r0;
/* 807B0220 4182007C */  beq-     UNDEF_807b029c;

                         cmpwi    r24, 4;
                         bge-     UNDEF_807b0234;

/* 807B0224 7C97C214 */  add      r4, r23, r24;
/* 807B0228 880408D8 */  lbz      r0, 0x8D8(r4);
/* 807B022C 2C000000 */  cmpwi    r0, 0;
/* 807B0230 4182006C */  beq-     UNDEF_807b029c;
UNDEF_807b0234:;
/* 807B0234 7C7FA92E */  stwx     r3, r31, r21;
/* 807B0238 7EB7AA14 */  add      r21, r23, r21;
/* 807B023C 801708A0 */  lwz      r0, 0x8A0(r23);
/* 807B0240          */  lwz      r3, dStockItem_c_OFFSET_mpa2DPlayer(r21);
/* 807B0244 5400103A */  slwi     r0, r0, 2;
/* 807B0248 7C96002E */  lwzx     r4, r22, r0;
/* 807B024C 48116BA5 */  bl       UNDEF_808c6df0;
/* 807B0250          */  lwz      r4, dStockItem_c_OFFSET_mpa2DPlayer(r21);
/* 807B0254 7EE3BB78 */  mr       r3, r23;
/* 807B0258 7F06C378 */  mr       r6, r24;
/* 807B025C 38A1000C */  addi     r5, r1, 12;
/* 807B0260 C00400B4 */  lfs      f0, 180(r4);
/* 807B0264 3B400001 */  li       r26, 1;
/* 807B0268 C02400B0 */  lfs      f1, 176(r4);
/* 807B026C C04400AC */  lfs      f2, 172(r4);
/* 807B0270 D0410024 */  stfs     f2, 36(r1);

                         // Can't play the item use effect here yet for 5+
                         cmpwi    r24, 4;
                         bge-     UNDEF_807b029c;

/* 807B0274 93BB0890 */  stw      r29, 0x890(r27);
/* 807B0278 D041000C */  stfs     f2, 12(r1);
/* 807B027C D0210010 */  stfs     f1, 16(r1);
/* 807B0280 D0010014 */  stfs     f0, 20(r1);
/* 807B0284          */  lwz      r4, dStockItem_c_OFFSET_mpa2DPlayer(r21);
/* 807B0288 D0210028 */  stfs     f1, 40(r1);
/* 807B028C 80040004 */  lwz      r0, 4(r4);
/* 807B0290 D001002C */  stfs     f0, 44(r1);
/* 807B0294 5404073E */  clrlwi   r4, r0, 28;
/* 807B0298 480000C9 */  bl       UNDEF_807b0360;
UNDEF_807b029c:;
/* 807B029C 3B180001 */  addi     r24, r24, 1;
/* 807B02A0 3B7B0004 */  addi     r27, r27, 4;
/* 807B02A4          */  cmpwi    r24, PLAYER_COUNT;
/* 807B02A8 3B9C0004 */  addi     r28, r28, 4;
/* 807B02AC 4180FF48 */  blt+     UNDEF_807b01f4;
UNDEF_807b02b0:;
/* 807B02B0 2C1A0000 */  cmpwi    r26, 0;
/* 807B02B4 41820068 */  beq-     UNDEF_807b031c;
/* 807B02B8 3C608043 */  lis      r3, m_instance__7dInfo_c@ha;
/* 807B02BC 809708A0 */  lwz      r4, 2208(r23);
/* 807B02C0 8063A25C */  lwz      r3, m_instance__7dInfo_c@l(r3);
/* 807B02C4 4B90B0BD */  bl       UNDEF_800bb380; // subStockItem__7dInfo_cFi
/* 807B02C8 801708A0 */  lwz      r0, 2208(r23);
/* 807B02CC 7EE3BB78 */  mr       r3, r23;
/* 807B02D0 5400103A */  slwi     r0, r0, 2;
/* 807B02D4 7CB70214 */  add      r5, r23, r0;
/* 807B02D8 808508B4 */  lwz      r4, 2228(r5);
/* 807B02DC 3804FFFF */  subi     r0, r4, 1;
/* 807B02E0 900508B4 */  stw      r0, 2228(r5);
/* 807B02E4 80B708A0 */  lwz      r5, 2208(r23);
/* 807B02E8 54A0103A */  slwi     r0, r5, 2;
/* 807B02EC 7C970214 */  add      r4, r23, r0;
/* 807B02F0 808408B4 */  lwz      r4, 2228(r4);
/* 807B02F4 4800004D */  bl       UNDEF_807b0340;
/* 807B02F8 801708A0 */  lwz      r0, 2208(r23);
/* 807B02FC 5400103A */  slwi     r0, r0, 2;
/* 807B0300 7C770214 */  add      r3, r23, r0;
/* 807B0304 800308B4 */  lwz      r0, 2228(r3);
/* 807B0308 2C000000 */  cmpwi    r0, 0;
/* 807B030C 40820010 */  bne-     UNDEF_807b031c;
/* 807B0310 806302F4 */  lwz      r3, 756(r3);
/* 807B0314 38000001 */  li       r0, 1;
/* 807B0318 90030204 */  stw      r0, 516(r3);
UNDEF_807b031c:;
/* 807B031C 39610070 */  addi     r11, r1, 112;
/* 807B0320 4BB2CD79 */  bl       UNDEF_802dd098;
/* 807B0324 80010074 */  lwz      r0, 116(r1);
/* 807B0328 7C0803A6 */  mtlr     r0;
/* 807B032C 38210070 */  addi     r1, r1, 112;
/* 807B0330 4E800020 */  blr;
  // clang-format on
);