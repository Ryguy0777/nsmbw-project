#pragma once

class dBlockMng_c
{
public:
    // ----------------
    // Member Functions
    // ----------------

    /* 0x80087F40 */
    void brickHit(...);

public:
    // -----------
    // Member Data
    // -----------

    /* 0x0 */ int mDisableDonutLift;

public:
    // -----------
    // Static Data
    // -----------

    /* 0x8042A0F8 */ static dBlockMng_c* m_instance;
};