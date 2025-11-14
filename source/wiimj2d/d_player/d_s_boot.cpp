// d_s_boot.cpp
// NSMBW .text: 0x8015BA70 - 0x8015F270

#include "d_s_boot.h"

#include "d_bases/d_ControllerInformation.h"
#include "d_bases/d_s_stage.h"
#include "d_bases/d_s_world_map.h"
#include "d_player/d_WiiStrap.h"
#include "d_system/d_a_player_manager.h"
#include "d_system/d_fader.h"
#include "d_system/d_game_common.h"
#include "d_system/d_info.h"
#include "d_system/d_mj2d_game.h"
#include "d_system/d_resource_manager.h"
#include "d_system/d_scene.h"
#include "d_system/d_system.h"
#include "machine/m_fader.h"
#include "machine/m_heap.h"
#include <egg/core/eggHeap.h>

[[address_data(0x8042A620)]]
dScBoot_c* dScBoot_c::m_instance;

int dScBoot_c::recreate()
{
    // why did i make dScBoot_c recreate dInfo_c

    u8 dInfo_data[dInfo_c::ORIGINAL_SIZE];
    bool dInfo_copy = false;
    if (dInfo_c::m_instance != nullptr) {
        std::memcpy(dInfo_data, static_cast<void*>(dInfo_c::m_instance), dInfo_c::ORIGINAL_SIZE);
        operator delete(dInfo_c::m_instance);
        dInfo_copy = true;
    }

    dInfo_c* newInfo = new (mHeap::g_gameHeaps[0], alignof(dInfo_c)) dInfo_c();
    if (dInfo_copy) {
        std::memcpy(static_cast<void*>(newInfo), dInfo_data, dInfo_c::ORIGINAL_SIZE);
        std::memset(
          reinterpret_cast<u8*>(newInfo) + dInfo_c::ORIGINAL_SIZE, 0,
          sizeof(dInfo_c) - dInfo_c::ORIGINAL_SIZE
        );
    }

    return 1;
}

[[address(0x8015D010)]]
void dScBoot_c::executeState_WiiStrapFadeOut()
{
    if (!mFader_c::isStatus(mFaderBase_c::OPAQUE)) {
        return;
    }

    if (mControllerInformation == nullptr || !mControllerInformation->mReady) {
        return;
    }

    mWiiStrap->mVisible = false;

    changeState(StateID_ControllerInformationFadeIn);
}

#if 0
[[address(0x8015D850)]]
void dScBoot_c::executeState_ProcEnd()
{
    if (false) {
        dScene_c::setNextScene(+fBaseProfile_e::MOVIE, 2, false);
        return;
    } else if (false) {
        dInfo_c::m_instance->startStaffCredit();
        return;
    } else if (true) {
        // Setup players for title screen test
        for (int i = 0; i < 8; i++) {
            // daPyMng_c::mPlayerType[i] = PLAYER_TYPE_e::TOADETTE;
            daPyMng_c::mPlayerEntry[i] = 1;

            daPyMng_c::mPlayerMode[i] = PLAYER_MODE_e::PROPELLER_SHROOM;
            daPyMng_c::mCreateItem[i] = PLAYER_CREATE_ITEM_e::NONE;

            dInfo_c::m_instance->setPlyConnectStage(dInfo_c::PlyConnectStage_e::ENTER);
        }

        //    daPyMng_c::mPlayerType[0] = PLAYER_TYPE_e::PURPLE_TOADETTE;
        //    daPyMng_c::mPlayerEntry[0] = 1;
        //    daPyMng_c::mRest[static_cast<std::size_t>(PLAYER_TYPE_e::PURPLE_TOADETTE)] = 1;

        dInfo_c::m_instance->startGame(dInfo_c::StartGameInfo_s{
          .demoTime = 0,
          .demoType = 0,
          .gotoID = 2,
          .courseID = 0,
          .isDemo = false,
          .screenType = dInfo_c::ScreenType_e::NORMAL,
          .world1 = WORLD_e::WORLD_8,
          .stage1 = STAGE_e::DOOMSHIP,
          .world2 = WORLD_e::WORLD_8,
          .stage2 = STAGE_e::DOOMSHIP,
        });
    }
}
#endif
