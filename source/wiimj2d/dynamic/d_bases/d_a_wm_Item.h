#pragma once

#include <dynamic/d_base_actor.h>

class daWmItem_c : public dBaseActor_c
{
    SIZE_ASSERT(0x210);

public:
    // ----------------
    // Member Functions
    // ----------------

    /* 0x808D4F40 */
    void updateVisiblity();

public:
    // -----------
    // Member Data
    // -----------

    FILL(0x125, 0x209);

    /* 0x209 */ bool mVisible;

    FILL(0x20A, 0x210);
};