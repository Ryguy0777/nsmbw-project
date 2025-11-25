// d_s_crsin.cpp
// NSMBW d_bases.text: 0x8091EC10 - 0x80921060

#include "d_s_crsin.h"

#include "d_bases/d_s_stage.h"
#include "d_system/d_a_player_manager.h"
#include "d_system/d_info.h"
#include "d_system/d_mj2d_game.h"
#include "d_system/d_remocon_mng.h"
#include "d_system/d_resource_manager.h"

[[address(0x8091EC50)]]
int dScCrsin_c::loadDefaultObjectResPhase()
{
    static const char* l_objectRes[] = {
      "Mario",
      "Luigi",
      "Kinopio",
      "Kinopico", // Added
      "Yoshi",
      "P_rcha",
      "L_rcha",
      "K_rcha",
      "C_rcha", // Added
      "Y_rcha",
      "Y_TexGreen",
      "Y_TexRed",
      "Y_TexYellow",
      "Y_TexBlue",
      "Y_TexCrimson", // Added
      "Y_TexOrange", // Added
      "Y_TexPurple", // Added
      "Y_TexAzure", // Added
      "obj_coin",
      "balloon",
      "I_kinoko",
      "I_fireflower",
      "I_iceflower",
      "I_star",
      "I_propeller",
      "I_penguin",
      "I_yoshi_egg",
      "block_tsuta",
      "teresa",
      "jump_step",
      "ice",
      "ice_piece",
      "obj_dokan",
      "obj_door",
      "obj_kusa",
      "obj_hana",
      "obj_hana_daishizen",
      "block_jump",
      "obj_chikuwa_block",
      "lift_rakka_ashiba",
      "Mask",
    };

    dResMng_c::m_instance->setRes(
      "Object", l_objectRes, sizeof(l_objectRes) / sizeof(l_objectRes[0]), nullptr
    );

    return 1;
}

[[address(0x8091EFD0)]]
dScCrsin_c::~dScCrsin_c()
{
    mPreGameLyt.~dPreGameLyt_c();
}

[[address(0x8091F560)]]
bool dScCrsin_c::isDoneLoading();

[[address(0x8091FE20)]]
void dScCrsin_c::executeState_resWaitProc2()
{
    if (!isDoneLoading()) {
        return;
    }

    if (dInfo_c::m_instance->m_startGameInfo.screenType == dInfo_c::ScreenType_e::TITLE) {
        // Setup players for title screen
        for (int i = 0; i < 8; i++) {
            daPyMng_c::mPlayerType[i] = dMj2dGame_c::scDefaultPlayerTypes[i];
            daPyMng_c::mPlayerEntry[i] = 1;

            int playerType = int(dMj2dGame_c::scDefaultPlayerTypes[i]);
            daPyMng_c::mPlayerMode[playerType] = PLAYER_MODE_e::MUSHROOM;
            daPyMng_c::mCreateItem[playerType] = PLAYER_CREATE_ITEM_e::NONE;
        }
    } else if (dScStage_c::m_isStaffCredit) {
        // Setup players for credits
        for (int i = 0; i < PLAYER_COUNT; i++) {
            daPyMng_c::mPlayerEntry[i] = 1;

            dRemoconMng_c::m_instance->mpConnect[i]->setAllowConnect(true);

            int playerType = int(daPyMng_c::mPlayerType[i]);

            daPyMng_c::mPlayerMode[playerType] = PLAYER_MODE_e::MUSHROOM;
            if (daPyMng_c::mRest[playerType] < 5) {
                daPyMng_c::mRest[playerType] = 5;
            }

            daPyMng_c::mCreateItem[playerType] = PLAYER_CREATE_ITEM_e::NONE;
        }
    }

    mStateMgr.changeState(StateID_createReplayHeapProc);
}
