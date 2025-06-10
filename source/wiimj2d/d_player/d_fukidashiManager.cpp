// d_fukidashiManager.cpp
// NSMBW .text: 0x80156FE0 - 0x80157820

#include "d_fukidashiManager.h"

#include <d_system/d_a_player_manager.h>
#include <d_system/d_info.h>

[[address_data(0x8042A600)]]
dfukidashiManager_c* dfukidashiManager_c::m_instance;

[[address(0x80156FE0)]]
dfukidashiManager_c* dfukidashiManager_c_classInit()
{
    return new dfukidashiManager_c();
}

[[address(0x80157010)]]
dfukidashiManager_c::dfukidashiManager_c() ASM_METHOD(
  // clang-format off
/* 80157010 9421FFF0 */  stwu     r1, -16(r1);
/* 80157014 7C0802A6 */  mflr     r0;
/* 80157018 90010014 */  stw      r0, 20(r1);
/* 8015701C 93E1000C */  stw      r31, 12(r1);
/* 80157020 7C7F1B78 */  mr       r31, r3;
/* 80157024 4BF153FD */  bl       UNDEF_8006c420;
/* 80157028 3C808032 */  lis      r4, UNDEF_80327618@ha;
/* 8015702C 387F0074 */  addi     r3, r31, 116;
/* 80157030 38847618 */  addi     r4, r4, UNDEF_80327618@l;
/* 80157034 909F0060 */  stw      r4, 96(r31);
/* 80157038 4BEAFA69 */  bl       UNDEF_80006aa0;
/* 8015703C 3C80800B */  lis      r4, UNDEF_800b14e0@ha;
/* 80157040 3CA0800B */  lis      r5, UNDEF_800b16e0@ha;
/* 80157044 387F0148 */  addi     r3, r31, 0x148;
/* 80157048 38C0023C */  li       r6, 0x23C;
/* 8015704C 388414E0 */  addi     r4, r4, UNDEF_800b14e0@l;
/* 80157050 38A516E0 */  addi     r5, r5, UNDEF_800b16e0@l;
/* 80157054          */  li       r7, PLAYER_COUNT;
/* 80157058 48185C39 */  bl       UNDEF_802dcc90;
/* 8015705C 93EDAC80 */  stw      r31, UNDEF_8042a600@sda21;
/* 80157060 7FE3FB78 */  mr       r3, r31;
/* 80157064 83E1000C */  lwz      r31, 12(r1);
/* 80157068 80010014 */  lwz      r0, 20(r1);
/* 8015706C 7C0803A6 */  mtlr     r0;
/* 80157070 38210010 */  addi     r1, r1, 16;
/* 80157074 4E800020 */  blr;
  // clang-format on
);

/* VT+0x48 */
[[address(0x80157080)]]
dfukidashiManager_c::~dfukidashiManager_c() ASM_METHOD(
  // clang-format off
/* 80157080 9421FFF0 */  stwu     r1, -16(r1);
/* 80157084 7C0802A6 */  mflr     r0;
/* 80157088 2C030000 */  cmpwi    r3, 0;
/* 8015708C 90010014 */  stw      r0, 20(r1);
/* 80157090 93E1000C */  stw      r31, 12(r1);
/* 80157094 7C9F2378 */  mr       r31, r4;
/* 80157098 93C10008 */  stw      r30, 8(r1);
/* 8015709C 7C7E1B78 */  mr       r30, r3;
/* 801570A0 4182004C */  beq-     UNDEF_801570ec;
/* 801570A4 38000000 */  li       r0, 0;
/* 801570A8 3C80800B */  lis      r4, UNDEF_800b16e0@ha; // __dt__16dfukidashiInfo_cFv
/* 801570AC 900DAC80 */  stw      r0, UNDEF_8042a600@sda21;
/* 801570B0 388416E0 */  addi     r4, r4, UNDEF_800b16e0@l; // __dt__16dfukidashiInfo_cFv
/* 801570B4 38A0023C */  li       r5, 0x23C;
/* 801570B8          */  li       r6, PLAYER_COUNT;
/* 801570BC 38630148 */  addi     r3, r3, 0x148;
/* 801570C0 48185CC9 */  bl       UNDEF_802dcd88; // __destroy_arr
/* 801570C4 387E0074 */  addi     r3, r30, 116;
/* 801570C8 3880FFFF */  li       r4, -1;
/* 801570CC 4BEAFA25 */  bl       UNDEF_80006af0; // __dt__Q23d2d18ResAccMultLoader_cFv
/* 801570D0 7FC3F378 */  mr       r3, r30;
/* 801570D4 38800000 */  li       r4, 0;
/* 801570D8 4BF153B9 */  bl       __dt__7dBase_cFv;
/* 801570DC 2C1F0000 */  cmpwi    r31, 0;
/* 801570E0 4081000C */  ble-     UNDEF_801570ec;
/* 801570E4 7FC3F378 */  mr       r3, r30;
/* 801570E8 4800B979 */  bl       __dl__7fBase_cFPv;
UNDEF_801570ec:;
/* 801570EC 7FC3F378 */  mr       r3, r30;
/* 801570F0 83E1000C */  lwz      r31, 12(r1);
/* 801570F4 83C10008 */  lwz      r30, 8(r1);
/* 801570F8 80010014 */  lwz      r0, 20(r1);
/* 801570FC 7C0803A6 */  mtlr     r0;
/* 80157100 38210010 */  addi     r1, r1, 16;
/* 80157104 4E800020 */  blr;
  // clang-format on
);

/**
 * VT+0x08
 * do method for the create operation.
 */
[[address(0x80157110)]]
fBase_c::PACK_RESULT_e dfukidashiManager_c::create() ASM_METHOD(
  // clang-format off
/* 80157110 9421FFE0 */  stwu     r1, -32(r1);
/* 80157114 7C0802A6 */  mflr     r0;
/* 80157118 3C808032 */  lis      r4, UNDEF_803275ec@ha;
/* 8015711C 90010024 */  stw      r0, 36(r1);
/* 80157120 388475EC */  addi     r4, r4, UNDEF_803275ec@l;
/* 80157124 93E1001C */  stw      r31, 28(r1);
/* 80157128 93C10018 */  stw      r30, 24(r1);
/* 8015712C 93A10014 */  stw      r29, 20(r1);
/* 80157130 7C7D1B78 */  mr       r29, r3;
/* 80157134 38630074 */  addi     r3, r3, 116;
/* 80157138 4BEAFAA9 */  bl       UNDEF_80006be0;
/* 8015713C 2C030000 */  cmpwi    r3, 0;
/* 80157140 4082000C */  bne-     UNDEF_8015714c;
/* 80157144 38600000 */  li       r3, 0;
/* 80157148 4800003C */  b        UNDEF_80157184;
UNDEF_8015714c:;
/* 8015714C 3BFD0148 */  addi     r31, r29, 328;
/* 80157150 3BC00000 */  li       r30, 0;
UNDEF_80157154:;
/* 80157154 7FE3FB78 */  mr       r3, r31;
/* 80157158 389D0074 */  addi     r4, r29, 116;
/* 8015715C 4BF5A605 */  bl       UNDEF_800b1760;
/* 80157160 2C030000 */  cmpwi    r3, 0;
/* 80157164 4082000C */  bne-     UNDEF_80157170;
/* 80157168 38600000 */  li       r3, 0;
/* 8015716C 48000018 */  b        UNDEF_80157184;
UNDEF_80157170:;
/* 80157170 3BDE0001 */  addi     r30, r30, 1;
/* 80157174 3BFF023C */  addi     r31, r31, 572;
/* 80157178          */  cmpwi    r30, PLAYER_COUNT;
/* 8015717C 4180FFD8 */  blt+     UNDEF_80157154;
/* 80157180 38600001 */  li       r3, 1;
UNDEF_80157184:;
/* 80157184 80010024 */  lwz      r0, 36(r1);
/* 80157188 83E1001C */  lwz      r31, 28(r1);
/* 8015718C 83C10018 */  lwz      r30, 24(r1);
/* 80157190 83A10014 */  lwz      r29, 20(r1);
/* 80157194 7C0803A6 */  mtlr     r0;
/* 80157198 38210020 */  addi     r1, r1, 32;
/* 8015719C 4E800020 */  blr;
  // clang-format on
);

/**
 * VT+0x20
 * do method for the execute operation.
 */
[[address(0x801571A0)]]
fBase_c::PACK_RESULT_e dfukidashiManager_c::execute() ASM_METHOD(
  // clang-format off
/* 801571A0 9421FFF0 */  stwu     r1, -16(r1);
/* 801571A4 7C0802A6 */  mflr     r0;
/* 801571A8 90010014 */  stw      r0, 20(r1);
/* 801571AC 93E1000C */  stw      r31, 12(r1);
/* 801571B0 93C10008 */  stw      r30, 8(r1);
/* 801571B4 7C7E1B78 */  mr       r30, r3;
/* 801571B8 3860FFFF */  li       r3, -1;
/* 801571BC 4BF5C995 */  bl       UNDEF_800b3b50;
/* 801571C0 2C030000 */  cmpwi    r3, 0;
/* 801571C4 4182000C */  beq-     UNDEF_801571d0;
/* 801571C8 38600001 */  li       r3, 1;
/* 801571CC 48000028 */  b        UNDEF_801571f4;
UNDEF_801571d0:;
/* 801571D0 3BFE0148 */  addi     r31, r30, 328;
/* 801571D4 3BC00000 */  li       r30, 0;
UNDEF_801571d8:;
/* 801571D8 7FE3FB78 */  mr       r3, r31;
/* 801571DC 4BF5A735 */  bl       UNDEF_800b1910;
/* 801571E0 3BDE0001 */  addi     r30, r30, 1;
/* 801571E4 3BFF023C */  addi     r31, r31, 572;
/* 801571E8          */  cmpwi    r30, PLAYER_COUNT;
/* 801571EC 4180FFEC */  blt+     UNDEF_801571d8;
/* 801571F0 38600001 */  li       r3, 1;
UNDEF_801571f4:;
/* 801571F4 80010014 */  lwz      r0, 20(r1);
/* 801571F8 83E1000C */  lwz      r31, 12(r1);
/* 801571FC 83C10008 */  lwz      r30, 8(r1);
/* 80157200 7C0803A6 */  mtlr     r0;
/* 80157204 38210010 */  addi     r1, r1, 16;
/* 80157208 4E800020 */  blr;
  // clang-format on
);

/**
 * VT+0x2C
 * do method for the draw operation.
 */
[[address(0x80157210)]]
fBase_c::PACK_RESULT_e dfukidashiManager_c::draw() ASM_METHOD(
  // clang-format off
/* 80157210 9421FFF0 */  stwu     r1, -16(r1);
/* 80157214 7C0802A6 */  mflr     r0;
/* 80157218 90010014 */  stw      r0, 20(r1);
/* 8015721C 93E1000C */  stw      r31, 12(r1);
/* 80157220 3BE30148 */  addi     r31, r3, 328;
/* 80157224 93C10008 */  stw      r30, 8(r1);
/* 80157228 3BC00000 */  li       r30, 0;
UNDEF_8015722c:;
/* 8015722C 7FE3FB78 */  mr       r3, r31;
/* 80157230 4BF5A761 */  bl       UNDEF_800b1990;
/* 80157234 3BDE0001 */  addi     r30, r30, 1;
/* 80157238 3BFF023C */  addi     r31, r31, 572;
/* 8015723C          */  cmpwi    r30, PLAYER_COUNT;
/* 80157240 4180FFEC */  blt+     UNDEF_8015722c;
/* 80157244 83E1000C */  lwz      r31, 12(r1);
/* 80157248 38600001 */  li       r3, 1;
/* 8015724C 83C10008 */  lwz      r30, 8(r1);
/* 80157250 80010014 */  lwz      r0, 20(r1);
/* 80157254 7C0803A6 */  mtlr     r0;
/* 80157258 38210010 */  addi     r1, r1, 16;
/* 8015725C 4E800020 */  blr;
  // clang-format on
);

/**
 * VT+0x14
 * do method for the delete operation. This method was renamed due to conflict with the delete
 * C++ keyword.
 */
[[address(0x80157260)]]
fBase_c::PACK_RESULT_e dfukidashiManager_c::doDelete() ASM_METHOD(
  // clang-format off
/* 80157260 9421FFF0 */  stwu     r1, -16(r1);
/* 80157264 7C0802A6 */  mflr     r0;
/* 80157268 90010014 */  stw      r0, 20(r1);
/* 8015726C 93E1000C */  stw      r31, 12(r1);
/* 80157270 93C10008 */  stw      r30, 8(r1);
/* 80157274 7C7E1B78 */  mr       r30, r3;
/* 80157278 38630074 */  addi     r3, r3, 116;
/* 8015727C 4BEAF975 */  bl       UNDEF_80006bf0;
/* 80157280 2C030000 */  cmpwi    r3, 0;
/* 80157284 4082000C */  bne-     UNDEF_80157290;
/* 80157288 38600000 */  li       r3, 0;
/* 8015728C 48000038 */  b        UNDEF_801572c4;
UNDEF_80157290:;
/* 80157290 3BFE0148 */  addi     r31, r30, 328;
/* 80157294 3BC00000 */  li       r30, 0;
UNDEF_80157298:;
/* 80157298 7FE3FB78 */  mr       r3, r31;
/* 8015729C 4BF5A715 */  bl       UNDEF_800b19b0;
/* 801572A0 2C030000 */  cmpwi    r3, 0;
/* 801572A4 4082000C */  bne-     UNDEF_801572b0;
/* 801572A8 38600000 */  li       r3, 0;
/* 801572AC 48000018 */  b        UNDEF_801572c4;
UNDEF_801572b0:;
/* 801572B0 3BDE0001 */  addi     r30, r30, 1;
/* 801572B4 3BFF023C */  addi     r31, r31, 572;
/* 801572B8 2C1E0004 */  cmpwi    r30, PLAYER_COUNT;
/* 801572BC 4180FFDC */  blt+     UNDEF_80157298;
/* 801572C0 38600001 */  li       r3, 1;
UNDEF_801572c4:;
/* 801572C4 80010014 */  lwz      r0, 20(r1);
/* 801572C8 83E1000C */  lwz      r31, 12(r1);
/* 801572CC 83C10008 */  lwz      r30, 8(r1);
/* 801572D0 7C0803A6 */  mtlr     r0;
/* 801572D4 38210010 */  addi     r1, r1, 16;
/* 801572D8 4E800020 */  blr;
  // clang-format on
);

[[address(0x80157360)]]
void dfukidashiManager_c::FUN_80157360(int param1, int param2, int param3)
{
    if (param2 == 8) {
        param1 = 1;
    }

    for (int i = 0; i < PLAYER_COUNT; i++) {
        if (maInfo[i].mDisplayed && maInfo[i].m0x220 == param2 && maInfo[i].mPlayerID == param1) {
            maInfo[i].m0x230 = param3;
        }
    }
}

[[address(0x80157450)]]
void dfukidashiManager_c::FUN_80157450(int param1, int param2)
{
    if (param2 < 0 || param2 >= 22) {
        return;
    }

    if (param2 == 8) {
        param1 = 1;
    }

    if (param1 < 0 || param2 >= PLAYER_COUNT) {
        return;
    }

    dInfo_c* dInfo = dInfo_c::m_instance;

    u8* afeValue = param1 < 4 ? dInfo->m0xAFE[param1] : dInfo->mEx0xAFE[param1 - 4];
    *afeValue = 1;
}

[[address(0x801574A0)]]
void dfukidashiManager_c::FUN_801574A0(int param1, int param2)
{
    if (param2 < 0 || param2 >= 22) {
        return;
    }

    if (param2 == 8) {
        param1 = 1;
    }

    if (param1 < 0 || param2 >= PLAYER_COUNT) {
        return;
    }

    dInfo_c* dInfo = dInfo_c::m_instance;

    u8* afeValue = param1 < 4 ? dInfo->m0xAFE[param1] : dInfo->mEx0xAFE[param1 - 4];
    *afeValue = 0;
}