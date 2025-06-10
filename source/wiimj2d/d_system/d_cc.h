#pragma once

class dActor_c;

class dCc_c
{
    SIZE_ASSERT(0xA4);

    /* 0x00 VTABLE 0x803110F0 */

public:
    // ------------
    // Constructors
    // ------------

    /* 0x8008C200 */
    dCc_c();

    /* VT+0x8 0x8008C260 */
    virtual ~dCc_c();

public:
    // ----------------
    // Member Functions
    // ----------------

    /* 0x8008C380 */
    void release();

public:
    // ----------------
    // Static Functions
    // ----------------

    /* 0x8008C9E0 */
    static void execute();

public:
    // -----------
    // Member Data
    // -----------

    /* 0x04 */ dActor_c* mpOwner;

    FILL(0x08, 0xA4);
};