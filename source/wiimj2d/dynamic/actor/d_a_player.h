#pragma once

#include "d_a_player_base.h"
#include "d_a_player_manager.h"

class dAcPy_c : public daPlBase_c
{
public:
    // ---------
    // Functions
    // ---------

    /* 0x80138FA0 */
    bool setBalloonInDamage();

    /* 0x8013D7B0 */
    void checkRest();

public:
    // -----------
    // Member Data
    // -----------

    /* 0x14D4 */ daPyMng_c::PlayerType_e mPlayerType;

    FILL(0x14D8, 0x14F0);

    /* 0x14F0 */ s32 m0x14F0;

    FILL(0x14F4, 0x153C);

    /* 0x153C */ u8 mScrollType;
};