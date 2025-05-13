#pragma once

#include <egg/prim/eggBitFlag.h>

class dQuake_c
{
public:
    // -------------------
    // Constants and Types
    // -------------------

    enum class TYPE_QUAKE_e {
    };

    enum class TYPE_SHOCK_e {
        PLAYER_DAMAGE = 4,
    };

public:
    // ----------------
    // Member Functions
    // ----------------

    /* 0x800D8CA0 */
    void shockMotor(s8 player, TYPE_SHOCK_e type, int flag, bool grabActive);

public:
    // -----------
    // Member Data
    // -----------

    FILL(0x00, 0x30);

    /* 0x30 */ EGG::TBitFlag<u32> mFlags;

public:
    // -----------
    // Static Data
    // -----------

    /* 0x8042A2E8 */ static dQuake_c* m_instance;
};