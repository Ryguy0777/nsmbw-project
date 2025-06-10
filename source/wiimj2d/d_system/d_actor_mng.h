#pragma once

class dActorMng_c
{
public:
    // ----------------
    // Member Functions
    // ----------------

    /* 0x80066EC0 */
    void finalUpdate();

    /* 0x80066F70 */
    void execute();

public:
    // -----------
    // Static Data
    // -----------

    /* 0x8042A020 */ static dActorMng_c* m_instance;
};