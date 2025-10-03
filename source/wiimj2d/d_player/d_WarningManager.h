#pragma once

class dWarningManager_c
{
public:
    // ----------------
    // Static Functions
    // ----------------

    // Normally inline
    [[address(0x800B3B20)]]
    static bool isWarning();

public:
    // -----------
    // Static Data
    // -----------

    /* 0x8042A5C0 */
    static s32 m_WarningForbid;
};
