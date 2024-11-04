// d_game_common.cpp
// NSMBW .text: 0x800B2E70 - 0x800B5930

#include "d_game_common.h"

#include <dynamic/actor/d_a_player_manager.h>

namespace dGameCom
{

[[address(0x800B2E70)]]
void initRandomSeed();

[[address(0x800B30C0)]]
f32 getDispCenterX();

[[address(0x800B5340)]]
bool chkContinue()
{
    // Original function is flawed as it indexes in mPlayerType twice (so like
    // mRest[int(mPlayerType[int(mPlayerType[i])])]). It doesn't matter but i think it's kinda
    // interesting.

    for (int i = 0; i < CHARACTER_COUNT; i++) {
        if (daPyMng_c::mRest[i] == 0) {
            return true;
        }
    }

    return false;
}

[[address(0x800B53F0)]]
bool chkCancelButton(int player);

} // namespace dGameCom