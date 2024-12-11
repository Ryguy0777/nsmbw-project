// d_a_line_train.cpp
// NSMBW d_bases.text: 0x80859440 - 0x8085BCB0

#include "d_a_line_train.h"

[[address(0x8085A990)]]
int daLineTrain_c::numPlayersInMask()
{
    int count = 0;
    for (int i = 0; i < PLAYER_COUNT; i++) {
        if (mPlayerMask & (1 << i)) {
            count++;
        }
    }
    return count;
}
