// d_s_boot.cpp
// NSMBW .text: 0x8015C270 - 0x8015F270

#include "d_s_boot.h"
#include "revolution/os/OSError.h"

#include <d_system/d_a_player_manager.h>
#include <d_bases/d_ControllerInformation.h>
#include <d_bases/d_s_stage.h>
#include <d_bases/d_s_world_map.h>
#include <d_system/d_fader.h>
#include <d_system/d_game_common.h>
#include <d_system/d_info.h>
#include <d_system/d_mj2d_game.h>
#include <d_player/d_WiiStrap.h>
#include <d_system/d_resource_manager.h>
#include <d_system/d_scene.h>
#include <d_system/d_system.h>
#include <egg/core/eggHeap.h>
#include <machine/m_fader.h>
#include <machine/m_heap.h>

[[address(0x8042A620)]]
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
    // Setup players for title screen test
    for (int i = 0; i < PLAYER_COUNT; i++) {
        // daPyMng_c::mPlayerType[i] = daPyMng_c::PlayerType_e::TOADETTE;
        daPyMng_c::mPlayerEntry[i] = 1;

        daPyMng_c::mPlayerMode[i] = int(PLAYER_POWERUP_e::PROPELLER_SHROOM);
        daPyMng_c::mCreateItem[i] = 0;

        if (i < 4) {
            dInfo_c::m_instance->mPlayerActiveMode[i] = 3;
        } else {
            dInfo_c::m_instance->mExPlayerActiveMode[i - 4] = 3;
        }
    }

    // daPyMng_c::mPlayerType[5] = daPyMng_c::PlayerType_e::MARIO;

    // daPyMng_c::mPlayerEntry[4] = 1;

    dInfo_c::m_instance->startGame(dInfo_c::StartGameInfo_s{
      .demoTime = 0,
      .demoType = 0,
      .gotoID = 0,
      .courseID = 0,
      .isDemo = false,
      .screenType = dInfo_c::ScreenType_e::NORMAL,
      .world1 = WORLD_e::WORLD_1,
      .stage1 = STAGE_e::STAGE_3,
      .world2 = WORLD_e::WORLD_1,
      .stage2 = STAGE_e::STAGE_3,
    });
}
#endif
