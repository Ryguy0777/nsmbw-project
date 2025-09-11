// d_a_mini_game_wire_mesh_mgr.cpp
// NSMBW d_bases.text: 0x8086A040 - 0x8086C8F0

#include "d_a_mini_game_wire_mesh_mgr.h"

#include "d_system/d_mj2d_game.h"
#include "d_system/d_save_manager.h"

[[address(0x8086B230)]]
void daMiniGameWireMeshMgrObj_c::updateStockItem()
{
    dMj2dGame_c* save = dSaveMng_c::m_instance->getSaveGame();

    if (mWinItemCount < 1) {
        return;
    }

    for (int i = 0; i < STOCK_ITEM_COUNT; i++) {
        if (mWinStockItem[i] > 0) {
            save->setStockItem(i, save->getStockItem(i) + mWinStockItem[i]);
        }
    }
}

// TODO: 0x8086AB90, 0x8086AEA0 decides the color of the thing circling around players