#pragma once

class dActor_c;

class dCc_c
{
public:
    // ------------
    // Constructors
    // ------------

    virtual ~dCc_c() = 0;

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
};