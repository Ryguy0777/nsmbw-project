#pragma once

class dStageTimer_c
{
public:
    // Instance Methods
    // ^^^^^^

    /* 0x800E3A20 */
    void execute();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x00, 0x0C);

    /* 0x0C */ bool mPause;

public:
    // Static Variables
    // ^^^^^^

    /* 0x8042A350 */ static dStageTimer_c* m_instance;
};
