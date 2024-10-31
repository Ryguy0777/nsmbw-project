#pragma once

class dRemoconMng_c
{
public:
    // -------------------
    // Constants and Types
    // -------------------

    class dConnect_c
    {
    public:
        FILL(0x00, 0x54);

        /* 0x54 */ u8 m0x54;
    };

public:
    // -----------
    // Member Data
    // -----------

    FILL(0x00, 0x04);

    /* 0x00 */ dConnect_c* mpaConnect[4];

    // -----------
    // Static Data
    // -----------

    /* 0x8042A308 */
    static dRemoconMng_c* m_instance;
};