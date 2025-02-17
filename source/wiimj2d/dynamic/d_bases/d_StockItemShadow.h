#pragma once

#include <dynamic/d_base.h>
#include <dynamic/d_lytbase.h>

class dStockItemShadow_c : public dBase_c
{
    SIZE_ASSERT(0x280);

public:
    // -----------
    // Member Data
    // -----------

    /* 0x070 */ LytBase_c mLayout;

    FILL(0x208, 0x260);

    /* 0x260 */ u8 m0x260;
    /* 0x261 */ u8 m0x261;

    FILL(0x262, 0x280);
};