// d_s_game_setup.cpp
// NSMBW d_bases.text: 0x80917960 - 0x8091A2F0

#include "d_s_game_setup.h"

#include <dynamic/d_CharacterChangeSelectBase.h>
#include <dynamic/d_NumberOfPeopleChange.h>
#include <dynamic/d_base_actor.h>
#include <framework/f_base_profile.h>

[[address(0x80917EB0)]]
bool dScGameSetup_c::add2dPlayer()
{
    u32 id = mPlayerCreateIdx;

    dBaseActor_c* playerBase =
      dBaseActor_c::construct(+fBaseProfile_e::WM_2D_PLAYER, this, id, nullptr, nullptr);
    if (playerBase == nullptr) {
        return false;
    }

    da2DPlayer_c* player = reinterpret_cast<da2DPlayer_c*>(playerBase);

    if (id < 4) {
        mpa2DPlayer[id] = player;
        mpNumPyChg->mpaPlayers[id] = player;
    } else {
        mpNumPyChg->mpaExPlayers[id - 4] = player;
    }

    mPlayerCreateIdx++;
    if (mPlayerCreateIdx < CHARACTER_LIST_COUNT) {
        return false;
    }

    // Done
    mPlayerCreateIdx = 0;
    return true;
}

[[address(0x80918B00)]]
void dScGameSetup_c::executeState_StartMember() ASM_METHOD(
  // clang-format off
/* 80918B00 808300D0 */  lwz      r4, 208(r3);
/* 80918B04 3CC0809A */  lis      r6, UNDEF_809a14d0@ha;
/* 80918B08 38C614D0 */  addi     r6, r6, UNDEF_809a14d0@l;
/* 80918B0C 8804026B */  lbz      r0, 619(r4);
/* 80918B10 2C000000 */  cmpwi    r0, 0;
/* 80918B14 4D820020 */  beqlr-;
/* 80918B18 80040270 */  lwz      r0, 624(r4);
/* 80918B1C 2C000001 */  cmpwi    r0, 1;
/* 80918B20 408200AC */  bne-     UNDEF_80918bcc;
/* 80918B24 3C808043 */  lis      r4, m_instance__7dInfo_c@ha;
/* 80918B2C 8084A25C */  lwz      r4, m_instance__7dInfo_c@l(r4);
/* 80918B30 39000000 */  li       r8, 0;
                         // Don't automatically register Mario (store 0 instead of 3)
/* 80918B34          */  stw      r8, 900(r4);
/* 80918B38 91040388 */  stw      r8, 904(r4);
/* 80918B3C 9104038C */  stw      r8, 908(r4);
/* 80918B40 91040390 */  stw      r8, 912(r4);
                         // Don't skip character select with 1 player
// /* 80918B44 808300D0 */  lwz      r4, 208(r3);
// /* 80918B48 8004026C */  lwz      r0, 620(r4);
// /* 80918B4C 2C000000 */  cmpwi    r0, 0;
// /* 80918B50 41820038 */  beq-     UNDEF_80918b88;
/* 80918B54 80A300B8 */  lwz      r5, 184(r3);
/* 80918B58 38000001 */  li       r0, 1;
/* 80918B5C 38860150 */  addi     r4, r6, 336;
/* 80918B60 9805067E */  stb      r0, 1662(r5);
/* 80918B64 80C300D0 */  lwz      r6, 208(r3);
/* 80918B68 80A300B8 */  lwz      r5, 184(r3);
/* 80918B6C 80C6026C */  lwz      r6, 620(r6);
/* 80918B70 38060001 */  addi     r0, r6, 1;
/* 80918B74 900506C4 */  stw      r0, 1732(r5);
/* 80918B78 85830074 */  lwzu     r12, 116(r3);
/* 80918B7C 818C0018 */  lwz      r12, 24(r12);
/* 80918B80 7D8903A6 */  mtctr    r12;
/* 80918B84 4E800420 */  bctr;
// UNDEF_80918b88:;
// /* 80918B88 3C808043 */  lis      r4, UNDEF_8042a308@ha;
// /* 80918B8C 3CA08043 */  lis      r5, UNDEF_8042a5b8@ha;
// /* 80918B90 80E4A308 */  lwz      r7, UNDEF_8042a308@l(r4);
// /* 80918B94 388601D0 */  addi     r4, r6, 464;
// /* 80918B98 38000001 */  li       r0, 1;
// /* 80918B9C 80C70008 */  lwz      r6, 8(r7);
// /* 80918BA0 99060054 */  stb      r8, 84(r6);
// /* 80918BA4 80C7000C */  lwz      r6, 12(r7);
// /* 80918BA8 99060054 */  stb      r8, 84(r6);
// /* 80918BAC 80C70010 */  lwz      r6, 16(r7);
// /* 80918BB0 99060054 */  stb      r8, 84(r6);
// /* 80918BB4 80A5A5B8 */  lwz      r5, UNDEF_8042a5b8@l(r5);
// /* 80918BB8 98050B8D */  stb      r0, 2957(r5);
// /* 80918BBC 85830074 */  lwzu     r12, 116(r3);
// /* 80918BC0 818C0018 */  lwz      r12, 24(r12);
// /* 80918BC4 7D8903A6 */  mtctr    r12;
// /* 80918BC8 4E800420 */  bctr;
UNDEF_80918bcc:;
/* 80918BCC 2C00FFFF */  cmpwi    r0, -1;
/* 80918BD0 4C820020 */  bnelr-;
/* 80918BD4 38000000 */  li       r0, 0;
/* 80918BD8 98030108 */  stb      r0, 264(r3);
/* 80918BDC 38860090 */  addi     r4, r6, 144;
/* 80918BE0 85830074 */  lwzu     r12, 116(r3);
/* 80918BE4 818C0018 */  lwz      r12, 24(r12);
/* 80918BE8 7D8903A6 */  mtctr    r12;
/* 80918BEC 4E800420 */  bctr;
  // clang-format on
);
