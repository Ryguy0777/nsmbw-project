#pragma once

class dWarningManager_c
{
public:
    // ----------------
    // Member Functions
    // ----------------

    /* 0x8010E710 */
    void onControllerCut(int player);

public:
    // -----------
    // Member Data
    // -----------

    FILL(0x000, 0xB8D);

    /* 0xB8D */ bool m0xB8D;

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

    /* 0x8042A5B8 */ static dWarningManager_c* m_instance;
    /* 0x8042A5C0 */ static s32 m_WarningForbid;
};
