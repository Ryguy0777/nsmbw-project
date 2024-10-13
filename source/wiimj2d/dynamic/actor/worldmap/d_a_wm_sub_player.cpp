// d_a_wm_sub_player.cpp
// NSMBW d_bases.text: 0x808E8AA0 - 0x808EF8D0

#include "d_a_wm_sub_player.h"

#include <dynamic/actor/worldmap/d_a_wm_player.h>

REPLACE(
  0x808EE0C0, //
  s32 daWmSubPlayer_c::getPlayerOrder()
)
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