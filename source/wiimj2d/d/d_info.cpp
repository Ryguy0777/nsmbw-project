// d_info.cpp
// NSMBW .text: 0x800BB0E0 - 0x800BBD80
// NSMBW .data: 0x80315E90 - 0x80315EB0
// NSMBW .bss: 0x80359054 - 0x803590F0
// NSMBW .sbss: 0x8042A25C - 0x8042A268

#include "d_info.h"

#include <d/a/d_a_player_manager.h>

//
// .text
//

EXTERN_SYMBOL(0x800BB0E0, "__ct__7dInfo_cFv");

EXTERN_TEXT(
  0x800BB130, //
  dInfo_c::~dInfo_c()
);

REPLACE(
  0x800BB180, //
  void dInfo_c::PlayerStateInit()
)
{
    daPyMng_c::mPlayerType[0] = 0;
    daPyMng_c::mPlayerType[1] = 1;
    daPyMng_c::mPlayerType[2] = 3;
    daPyMng_c::mPlayerType[3] = 2;

    for (s32 i = 0; i < 4; i++) {
        mPlayerActiveMode[i] = 0;
    }
}

EXTERN_SYMBOL(0x800BB1C0, "CourseSelectInit__7dInfo_cFv");

EXTERN_SYMBOL(0x800BB330, "addStockItem__7dInfo_cFi");

EXTERN_SYMBOL(0x800BB380, "subStockItem__7dInfo_cFi");

EXTERN_SYMBOL(0x800BB3D0, "getStockItem__7dInfo_cCFi");

EXTERN_SYMBOL(0x800BB410, "clsStockItem__7dInfo_cFi");

EXTERN_SYMBOL(0x800BB450, "initGame__7dInfo_cFv");

EXTERN_SYMBOL(0x800BB5B0, "initMultiMode__7dInfo_cFv");

EXTERN_SYMBOL(0x800BB7D0, "startGame__7dInfo_cFRCQ27dInfo_c15StartGameInfo_s");

EXTERN_SYMBOL(0x800BB8D0, "startStaffCredit__7dInfo_cFv");

EXTERN_SYMBOL(0x800BB940, "initStage__7dInfo_cFv");

EXTERN_SYMBOL(0x800BBBC0, "SetWorldMapEnemy__7dInfo_cFiiRCQ27dInfo_c7enemy_s");

EXTERN_SYMBOL(0x800BBC00, "GetWorldMapEnemy__7dInfo_cFii");

EXTERN_SYMBOL(0x800BBC20, "SetMapEnemyInfo__7dInfo_cFiiii");

EXTERN_SYMBOL(0x800BBC40, "#0A406FBE");

EXTERN_SYMBOL(0x800BBC60, "GetMapEnemyInfo__7dInfo_cFiiRQ27dInfo_c7enemy_s");

EXTERN_SYMBOL(0x800BBCA0, "#2E37A2E4");

EXTERN_SYMBOL(0x800BBCB0, "#9F1989F5");

EXTERN_SYMBOL(0x800BBCC0, "GetIbaraNow__7dInfo_cFi");

EXTERN_SYMBOL(0x800BBCD0, "GetIbaraOld__7dInfo_cFi");

EXTERN_SYMBOL(0x800BBCE0, "__sinit_\\d_info_cpp");

EXTERN_SYMBOL(0x800BBD60, "__arraydtor$68604");

//
// .data
//

EXTERN_SYMBOL(0x80315E90, "m_startGameInfo__7dInfo_c");

EXTERN_SYMBOL(0x80315EA0, "__vt__7dInfo_c");

//
// .bss
//

EXTERN_SYMBOL(0x80359054, "m_startInfo__7dInfo_c");

//
// .sbss
//

EXTERN_DATA(
  0x8042A25C, //
  dInfo_c* dInfo_c::m_instance
);

EXTERN_SYMBOL(0x8042A260, "mGameFlag__7dInfo_c");