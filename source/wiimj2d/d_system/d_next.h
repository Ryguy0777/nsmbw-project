#pragma once

class dNext_c
{
public:
    // Instance Methods
    // ^^^^^^

    /* 0x800D0360 */
    void execute();

public:
    // Static Variables
    // ^^^^^^

    /* 0x8042A2A0 */ static dNext_c* m_instance;

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x00, 0x18);

    /* 0x18 */ bool mExitReq;
    /* 0x1C */ s32 mTimer;
};
