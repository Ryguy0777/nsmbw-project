#pragma once

class dEnemyMng_c
{
public:
    // ----------------
    // Member Functions
    // ----------------

    /* 0x800A7D30 @unofficial */
    void execute();

public:
    // -----------
    // Static Data
    // -----------

    /* 0x8042A1F0 */ static dEnemyMng_c* m_instance;

public:
    // -----------
    // Member Data
    // -----------

    FILL(0x000, 0x138);

    /* 0x138 */ u32 m0x138;

    FILL(0x13C, 0x174);

    /* 0x174 */ s32 mPokeyTimer;
};