// d_s_world_map.cpp
// NSMBW d_bases.text: 0x80926740 - 0x80928840

#include "d_s_world_map.h"

#include <dynamic/d_CourseSelectManager.h>
#include <dynamic/d_bases/d_NumberOfPeopleChange.h>
#include <dynamic/d_bases/d_StockItem.h>
#include <dynamic/d_bases/d_a_wm_KoopaShip.h>
#include <dynamic/d_bases/d_a_wm_Map.h>
#include <dynamic/d_bases/d_wm_WorldSelect.h>
#include <dynamic/d_wm_actor.h>
#include <framework/f_base_profile.h>
#include <iterator>

[[address(0x809271C0)]]
bool dScWMap_c::createActorsPhase(dScWMap_c* self)
{
    dWmActor_c::construct(+fBaseProfile_e::WM_MAP, self, 0, nullptr, nullptr);
    dWmActor_c::construct(+fBaseProfile_e::WM_CS_SEQ_MNG, self, 0, nullptr, nullptr);
    dWmActor_c::construct(+fBaseProfile_e::WM_PLAYER, self, 0, nullptr, nullptr);
    dWmActor_c::construct(+fBaseProfile_e::WORLD_CAMERA, self, 0, nullptr, nullptr);

    daWmMap_c* wmMap = daWmMap_c::m_instance;

    wmMap->createMapActors();
    wmMap->createEnemyActors();

    daWmKoopaShip_c::setup();

    dCourseSelectManager_c* crsSelMng = dCourseSelectManager_c::m_instance;
    dNumberOfPeopleChange_c* numPyChg = crsSelMng->mpNumPyChg;
    dStockItem_c* stockItem = crsSelMng->mpStockItem;

    for (int i = 0; i < PLAYER_COUNT; i++) {
        crsSelMng->mpa2DPlayer[i] = reinterpret_cast<da2DPlayer_c*>(
          dBaseActor_c::construct(+fBaseProfile_e::WM_2D_PLAYER, self, i, nullptr, nullptr)
        );

        if (numPyChg != nullptr) {
            numPyChg->setPlayer(i, crsSelMng->mpa2DPlayer[i]);
        }
        if (stockItem != nullptr) {
            stockItem->mpa2DPlayer[i] = crsSelMng->mpa2DPlayer[i];
            if (i < 4) {
                stockItem->mpa2DPlayer_Removed[i] = crsSelMng->mpa2DPlayer[i];
            }
        }
    }

    if (stockItem != nullptr) {
        for (int i = 0; i < std::size(stockItem->mpaItem); i++) {
            stockItem->mpaItem[i] = reinterpret_cast<daWmItem_c*>(
              dBaseActor_c::construct(+fBaseProfile_e::WM_ITEM, self, i, nullptr, nullptr)
            );
        }
    }

    dWorldSelect_c* wSelect = crsSelMng->mpWSelect;
    if (wSelect != nullptr) {
        for (int i = 0; i < std::size(wSelect->mpaIsland); i++) {
            wSelect->mpaIsland[i] = reinterpret_cast<daWmIsland_c*>(
              dBaseActor_c::construct(+fBaseProfile_e::WM_ISLAND, self, i, nullptr, nullptr)
            );
        }
    }

    return true;
}