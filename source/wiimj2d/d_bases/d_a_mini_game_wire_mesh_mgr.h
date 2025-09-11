#pragma once

#include "d_system/d_base.h"
#include "d_system/d_mj2d_game.h"

class daMiniGameWireMeshMgrObj_c : dBase_c
{
public:
    // ----------------
    // Member Functions
    // ----------------

    /* 0x8086B230 */
    void updateStockItem();

public:
    // -----------
    // Member Data
    // -----------

    FILL(0x070, 0x1E8);
    OFFSET_ASSERT(0x1E8);

    /* 0x1E8 */ int mWinItemCount;
    /* 0x1EC */ int mWinStockItem[STOCK_ITEM_COUNT];
};