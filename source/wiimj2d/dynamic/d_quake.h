#pragma once

#include <egg/prim/eggBitFlag.h>

class dQuake_c
{
public:
    // -----------
    // Static Data
    // -----------

    /* 0x8042A2E8 */ static dQuake_c* m_instance;

public:
    // -----------
    // Member Data
    // -----------

    FILL(0x00, 0x30);

    /* 0x30 */ EGG::TBitFlag<u32> mFlags;
};