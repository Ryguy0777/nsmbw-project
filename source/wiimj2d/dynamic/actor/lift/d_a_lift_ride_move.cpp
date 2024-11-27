// d_a_lift_ride_move.cpp
// NSMBW: 0x80845940 - 0x808468E0

[[address(0x80845D60)]]
bool daLiftRideMove_c_isAllPlayerOnLift(void* this_) ASM_METHOD(
  // clang-format off
/* 80845D60 9421FFE0 */  stwu     r1, -32(r1);
/* 80845D64 7C0802A6 */  mflr     r0;
/* 80845D68 90010024 */  stw      r0, 36(r1);
/* 80845D6C 39610020 */  addi     r11, r1, 32;
/* 80845D70 4BA972F5 */  bl       UNDEF_802dd064;
/* 80845D78 83630518 */  lwz      r27, 1304(r3);
/* 80845D7C 7C7F1B78 */  mr       r31, r3;
/* 80845D80 3B800000 */  li       r28, 0;
/* 80845D88 480000C0 */  b        UNDEF_80845e48;
UNDEF_80845d8c:;
/* 80845D8C 83BB0004 */  lwz      r29, 4(r27);
/* 80845D90 2C9D0000 */  cmpwi    cr1, r29, 0;
/* 80845D94 418600B0 */  beq-     cr1, UNDEF_80845e44;
/* 80845D98 881D038C */  lbz      r0, 908(r29);
/* 80845D9C 28000001 */  cmplwi   r0, 1;
/* 80845DA0 4082005C */  bne-     UNDEF_80845dfc;
                         
                         addi     r28, r28, 1;

/* 80845DBC 7FA3EB78 */  mr       r3, r29;
/* 80845DCC 4B8E7F55 */  bl       UNDEF_8012dd20; // getCarryPlayer__7dAcPy_cFv
/* 80845DD0 2C030000 */  cmpwi    r3, 0;
/* 80845DD4 41820070 */  beq-     UNDEF_80845e44;
                         
                         addi     r28, r28, 1;

/* 80845DF8 4800004C */  b        UNDEF_80845e44;
UNDEF_80845dfc:;
/* 80845DFC 28000002 */  cmplwi   r0, 2;
/* 80845E00 40820044 */  bne-     UNDEF_80845e44;
/* 80845E04 41860040 */  beq-     cr1, UNDEF_80845e44;
/* 80845E08 801D1524 */  lwz      r0, 5412(r29);
/* 80845E0C 2C000000 */  cmpwi    r0, 0;
/* 80845E10 41820034 */  beq-     UNDEF_80845e44;
/* 80845E14 819D0060 */  lwz      r12, 96(r29);
/* 80845E18 7FA3EB78 */  mr       r3, r29;
/* 80845E1C 818C006C */  lwz      r12, 108(r12);
/* 80845E20 7D8903A6 */  mtctr    r12;
/* 80845E24 4E800421 */  bctrl;
/* 80845E28 88030000 */  lbz      r0, 0(r3);
/* 80845E30          */  cmplwi   r0, 0xFF;
/* 80845E34 41820010 */  beq-     UNDEF_80845e44;

                         addi     r28, r28, 1;
UNDEF_80845e44:;
/* 80845E44 837B000C */  lwz      r27, 12(r27);
UNDEF_80845e48:;
/* 80845E48 2C1B0000 */  cmpwi    r27, 0;
/* 80845E4C 4082FF40 */  bne+     UNDEF_80845d8c;

UNDEF_80845e88:;
/* 80845E88 3C608043 */  lis      r3, mNum__9daPyMng_c@ha;
/* 80845E8C 80639F80 */  lwz      r3, mNum__9daPyMng_c@l(r3);
/* 80845E90 7C041800 */  cmpw     r28, r3;
/* 80845E94 41800014 */  blt-     UNDEF_80845ea8;
/* 80845E98 7C0300D0 */  neg      r0, r3;
/* 80845E9C 7C001B78 */  or       r0, r0, r3;
/* 80845EA0 54030FFE */  srwi     r3, r0, 31;
/* 80845EA4 48000024 */  b        UNDEF_80845ec8;
UNDEF_80845ea8:;
/* 80845EA8 2C040001 */  cmpwi    r28, 1;
/* 80845EAC 41800018 */  blt-     UNDEF_80845ec4;
/* 80845EB0 801F0004 */  lwz      r0, 4(r31);
/* 80845EB4 540027FF */  extrwi.  r0, r0, 1, 3;
/* 80845EB8 4182000C */  beq-     UNDEF_80845ec4;
/* 80845EBC 38600001 */  li       r3, 1;
/* 80845EC0 48000008 */  b        UNDEF_80845ec8;
UNDEF_80845ec4:;
/* 80845EC4 38600000 */  li       r3, 0;
UNDEF_80845ec8:;
/* 80845EC8 39610020 */  addi     r11, r1, 32;
/* 80845ECC 4BA971E5 */  bl       UNDEF_802dd0b0;
/* 80845ED0 80010024 */  lwz      r0, 36(r1);
/* 80845ED4 7C0803A6 */  mtlr     r0;
/* 80845ED8 38210020 */  addi     r1, r1, 32;
/* 80845EDC 4E800020 */  blr;
  // clang-format on
);