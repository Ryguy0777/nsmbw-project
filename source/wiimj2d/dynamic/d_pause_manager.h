#pragma once

class PauseManager_c
{
public:
    // ----------------
    // Member Functions
    // ----------------

    /* 0x800D1350 */
    void setPause();

public:
    // -----------
    // Static Data
    // -----------

    /* 0x8042A2B8 */ static PauseManager_c* m_instance;

    /* 0x8042A2C2 */ static bool m_OtasukeAfter;
};