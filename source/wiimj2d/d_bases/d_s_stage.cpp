// d_s_stage.cpp
// NSMBW d_bases.text: 0x80923C10 - 0x80926740

#include "d_s_stage.h"

#include "d_system/d_a_player_manager.h"
#include "d_system/d_cyuukan.h"
#include "d_system/d_info.h"
#include "d_system/d_mj2d_game.h"
#include "d_system/d_save_manager.h"
#include "d_system/d_start_info.h"
#include "d_system/d_wm_lib.h"

[[address(0x809251F0)]]
void dScStage_c::courseClear()
{
    WORLD_e world = m_instance->mWorld;
    STAGE_e stage = m_instance->mStage;

    if (world >= WORLD_e::COUNT || stage >= STAGE_e::COUNT) {
        return;
    }

    dInfo_c* info = dInfo_c::m_instance;
    dCyuukan_c* cyuukan = &info->mCyuukan;
    dStartInfo_c& startInfo = info->m_startInfo;

    if (m_miniGame == 0) {
        for (int i = 0; i < PLAYER_COUNT; i++) {
            daPyMng_c::mCreateItem[i] = startInfo.mCreateItem[i];
        }
    }

    dMj2dGame_c* save = dSaveMng_c::m_instance->getSaveGame();

    dInfo_c::StartGameInfo_s& startGameInfo = info->m_startGameInfo;

    if (startGameInfo.screenType == dInfo_c::ScreenType_e::NORMAL) {
        if ((startGameInfo.stage1 < STAGE_e::KINOKO_HOUSE ||
             startGameInfo.stage1 > STAGE_e::KINOKO_HOUSE_7) &&
            startGameInfo.stage1 != STAGE_e::PEACH_CASTLE) {
            cyuukan->clear();
        }

        if (daPyMng_c::isOnePlayer()) {
            save->setDeathCount(world, stage, info->mSwitchOn, 0);
        }

        for (int i = 0; i < COLLECTION_COIN_COUNT; i++) {
            static constexpr dMj2dGame_c::COURSE_COMPLETION_e COLLECTION_COIN_FLAGS[] = {
              dMj2dGame_c::COURSE_COMPLETION_e::COIN1_COLLECTED,
              dMj2dGame_c::COURSE_COMPLETION_e::COIN2_COLLECTED,
              dMj2dGame_c::COURSE_COMPLETION_e::COIN3_COLLECTED,
            };

            if (mCollectionCoin[i] != dCyuukan_c::COLLECTION_COIN_STATUS_e::NOT_COLLECTED) {
                save->setCollectCoin(world, stage, COLLECTION_COIN_FLAGS[i]);
            }
        }

        extern u8 UNDEF_8042a458;
        extern u8 UNDEF_8042a460;

        UNDEF_8042a458 = 0;
        UNDEF_8042a460 = 0;
    }

    bool isSecretExit = m_goalType == 1;
    if (startGameInfo.screenType != dInfo_c::ScreenType_e::NORMAL &&
        (world != WORLD_e::WORLD_3 || stage != STAGE_e::STAGE_4)) {
        isSecretExit = false;
    }

    dWmLib::procCourseClear(
      isSecretExit, startGameInfo.screenType == dInfo_c::ScreenType_e::SUPER_GUIDE, world, stage
    );

    if (startGameInfo.screenType != dInfo_c::ScreenType_e::NORMAL) {
        restoreStartInfo();
    }
}

[[address(0x809253E0)]]
void dScStage_c::restoreStartInfo()
{
    dInfo_c* info = dInfo_c::m_instance;
    dCyuukan_c* cyuukan = &info->mCyuukan;
    dStartInfo_c& startInfo = info->m_startInfo;

    cyuukan->m0x04 = startInfo.mCyuukan.m0x04;
    cyuukan->mPlayerSetPos = startInfo.mCyuukan.mPlayerSetPos;
    cyuukan->m0x14 = startInfo.mCyuukan.m0x14;
    cyuukan->mWorld = startInfo.mCyuukan.mWorld;
    cyuukan->mStage = startInfo.mCyuukan.mStage;
    cyuukan->mCourse = startInfo.mCyuukan.mCourse;
    cyuukan->mGoto = startInfo.mCyuukan.mGoto;
    cyuukan->mIsKinopioInChukan = startInfo.mCyuukan.mIsKinopioInChukan;
    cyuukan->mCollectionCoin[0] = startInfo.mCyuukan.mCollectionCoin[0];
    cyuukan->mCollectionCoin[1] = startInfo.mCyuukan.mCollectionCoin[1];
    cyuukan->mCollectionCoin[2] = startInfo.mCyuukan.mCollectionCoin[2];
    cyuukan->m0x2C[0] = startInfo.mCyuukan.m0x2C[0];
    cyuukan->m0x2C[1] = startInfo.mCyuukan.m0x2C[1];
    info->mSwitchOn = startInfo.mSwitchOn;

    for (int i = 0; i < PLAYER_COUNT; i++) {
        int index = startInfo.mPlayerIndex[i];
        daPyMng_c::mPlayerType[index] = static_cast<daPyMng_c::PlayerType_e>(i);
        daPyMng_c::mPlayerMode[i] = static_cast<s32>(startInfo.mPlayerMode[i]);
        daPyMng_c::mPlayerEntry[index] = startInfo.mIsEntry[i];
        daPyMng_c::mCoin[i] = startInfo.mCoin[i];
        daPyMng_c::mRest[i] = startInfo.mRest[i];
        daPyMng_c::mCreateItem[i] = startInfo.mCreateItem[i];
    }

    daPyMng_c::mScore = startInfo.mScore;

    extern u8 UNDEF_8042a458, UNDEF_8042a459;
    extern u8 UNDEF_8042a460, UNDEF_8042a461;

    UNDEF_8042a458 = UNDEF_8042a459;
    UNDEF_8042a460 = UNDEF_8042a461;

    info->m0x06C = 0;
}
