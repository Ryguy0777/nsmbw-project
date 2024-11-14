// d_a_en_jimen_pakkun_base.cpp
// NSMBW: 0x8002EF50 - 0x800311E0

#include "d_a_en_jimen_pakkun_base.h"

[[address(0x8002F870)]]
void daEnJimenPakkunBase_c::Normal_VsPlHitCheck(dCc_c* main, dCc_c* other) ASM_METHOD(
  // clang-format off
/* 8002F870 9421FFE0 */  stwu     r1, -32(r1);
/* 8002F874 7C0802A6 */  mflr     r0;
/* 8002F878 90010024 */  stw      r0, 36(r1);
/* 8002F87C 93E1001C */  stw      r31, 28(r1);
/* 8002F880 93C10018 */  stw      r30, 24(r1);
/* 8002F884 7CBE2B78 */  mr       r30, r5;
/* 8002F888 93A10014 */  stw      r29, 20(r1);
/* 8002F88C 7C7D1B78 */  mr       r29, r3;
/* 8002F890 83E50004 */  lwz      r31, 4(r5);
/* 8002F894 7FE4FB78 */  mr       r4, r31;
/* 8002F898 48067959 */  bl       UNDEF_800971f0;
/* 8002F89C 2C030000 */  cmpwi    r3, 0;
/* 8002F8A0 40820054 */  bne-     UNDEF_8002f8f4;
/* 8002F8A4 819D0060 */  lwz      r12, 96(r29);
/* 8002F8A8 7FA3EB78 */  mr       r3, r29;
/* 8002F8AC 7FE4FB78 */  mr       r4, r31;
/* 8002F8B0 818C0220 */  lwz      r12, 544(r12);
/* 8002F8B4 7D8903A6 */  mtctr    r12;
/* 8002F8B8 4E800421 */  bctrl;
/* 8002F8BC 881E002D */  lbz      r0, 45(r30);
/* 8002F8C0 2800000A */  cmplwi   r0, 10;
/* 8002F8C4 40820030 */  bne-     UNDEF_8002f8f4;

                         mr       r3, r29;
/* 8002F8C8          */  mr       r4, r31;
/* 8002F8CC          */  li       r5, 28;
                         bl       setCollTimer__5dEn_cFP8dActor_cUc;
UNDEF_8002f8f4:;
/* 8002F8F4 80010024 */  lwz      r0, 36(r1);
/* 8002F8F8 83E1001C */  lwz      r31, 28(r1);
/* 8002F8FC 83C10018 */  lwz      r30, 24(r1);
/* 8002F900 83A10014 */  lwz      r29, 20(r1);
/* 8002F904 7C0803A6 */  mtlr     r0;
/* 8002F908 38210020 */  addi     r1, r1, 32;
/* 8002F90C 4E800020 */  blr;
  // clang-format on
);