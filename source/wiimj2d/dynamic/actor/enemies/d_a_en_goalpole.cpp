// d_a_en_goalpole.cpp
// NSMBW: 0x80A096E0 - 0x80A0BE30

#include "d_a_en_goalpole.h"

#include <dynamic/actor/d_a_player_manager.h>

[[address(0x80A0B020)]]
bool daEnGlpole_c::isAllPlayerOnPole()
{
    int count = 0;
    for (int i = 0; i < PLAYER_COUNT; i++) {
        count += (mPlayerOnPoleFlag & (1 << i)) != 0;
    }

    return count == daPyMng_c::mNum;
}