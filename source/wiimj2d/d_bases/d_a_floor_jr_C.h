#pragma once

#include "d_system/d_base.h"
#include "d_system/d_mj2d_game.h"

class daFloorJrC_c : public dBase_c
{
public:
    // ------------
    // Constructors
    // ------------

    /* 0x807F20B0 */
    daFloorJrC_c();

public:
    // ----------------
    // Member Functions
    // ----------------

    /* 0x807F28E0 */
    void clearPlayerInfo();

    /* 0x807F2940 */
    bool checkPlayerFlag(int player);

public:
    // -----------
    // Member Data
    // -----------

    FILL(0x070, 0x66C);

    /* 0x66C */ float m0x66C;
    /* 0x670 */ float m0x670;
    /* 0x674 */ float m0x674;

    FILL(0x678, 0x684);

    /* 0x684 */ u8 m0x684;
    /* 0x685 */ u8 m0x685;

#if PLAYER_COUNT > 7
    /* 0x686 */ bool m0x686_Removed[4];
#else
    /* 0x686 */ bool m0x686[4];
#endif
    /* 0x68A */ bool m0x68A_Removed[4];

    FILL(0x68E, 0x6A8);
    OFFSET_ASSERT(0x6A8);

#if PLAYER_COUNT > 7
    bool m0x686[PLAYER_COUNT];
#endif

    bool m0x68A[PLAYER_COUNT];
};
