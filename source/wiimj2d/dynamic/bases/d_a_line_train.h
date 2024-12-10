#pragma once

#include <dynamic/d_actor.h>

class daLineTrain_c : public dActor_c
{
public:
    // ----------------
    // Member Functions
    // ----------------

    /* 0x8085A990 */
    int numPlayersInMask();

public:
    // -----------
    // Member Data
    // -----------

    FILL(0x0394, 0x1393);

    static_assert(PLAYER_COUNT <= 8, "Adapt this mask to support more players");
    /* 0x1393 */ u8 mPlayerMask;
};