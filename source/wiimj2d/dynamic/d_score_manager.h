#pragma once

class dScoreMng_c
{
public:
    // ----------------
    // Member Functions
    // ----------------

    /* 0x800E25A0 */
    void UNDEF_800E25A0(u32 scoreType, int playerId, u32 param3);

public:
    // -----------
    // Static Data
    // -----------

    /* 0x8042A330 */ static dScoreMng_c* m_instance;
};