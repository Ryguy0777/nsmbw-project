#pragma once

#include <dynamic/d_cyuukan.h>
#include <dynamic/d_a_player_manager.h>

class dStartInfo_c
{
    /* Original size: 0x9C */

public:
    // ------------
    // Constructors
    // ------------

    /* 0x800E3BA0 */
    dStartInfo_c();

public:
    // -----------
    // Member Data
    // -----------

    /* 0x00 */ dCyuukan_c mCyuukan;

    /**
     * The status of the worldmap switch.
     */
    /* 0x34 */ bool mSwitchOn;

    FILL(0x35, 0x44);

    // Offsets here assume PLAYER_COUNT is 4.

    /* 0x44 */ u32 mScore;
    /* 0x48 */ u32 mPlayerIndex[PLAYER_COUNT];
    /* 0x58 */ PLAYER_POWERUP_e mPlayerMode[PLAYER_COUNT];
    /* 0x68 */ bool mIsEntry[PLAYER_COUNT];
    /* 0x6C */ int mCoin[PLAYER_COUNT];
    /* 0x7C */ int mRest[PLAYER_COUNT];
    /* 0x8C */ int mCreateItem[PLAYER_COUNT];
};