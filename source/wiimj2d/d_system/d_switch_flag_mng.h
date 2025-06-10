#pragma once

class dSwitchFlagMng_c
{
public:
    // ----------------
    // Member Functions
    // ----------------

    /* 0x800E4100 */
    void execute();

public:
    // -----------
    // Static Data
    // -----------

    /* 0x8042A358 */ static dSwitchFlagMng_c* m_instance;
};