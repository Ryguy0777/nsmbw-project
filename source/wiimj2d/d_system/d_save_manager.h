#pragma once

class dMj2dGame_c;

class dSaveMng_c
{
public:
    // ---------
    // Functions
    // ---------

    /* 0x800E0470 */
    dMj2dGame_c* getSaveGame(s8 slot = -1);

public:
    // -----------
    // Static Data
    // -----------

    /* 0x8042A320 */ static dSaveMng_c* m_instance;
};