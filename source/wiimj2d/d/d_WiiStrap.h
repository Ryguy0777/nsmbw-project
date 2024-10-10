#pragma once

#include <d/d_base.h>

class dWiiStrap_c : public dBase_c
{
public:
    /* 0x60 VTABLE 0x80323118 */

    FILL(0x70, 0x208);

    /* 0x208 */ bool mReady;
    /* 0x209 */ bool mVisible;
};

static_assert(sizeof(dWiiStrap_c) == 0x20C);