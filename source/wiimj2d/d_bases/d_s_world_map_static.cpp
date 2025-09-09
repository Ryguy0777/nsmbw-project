// d_s_world_map_static.cpp
// NSMBW .text: 0x80102770 - 0x80102DB0

#include "d_s_world_map.h"

#include "d_system/d_info.h"
#include "d_system/d_mj2d_game.h"
#include "d_system/d_save_manager.h"
#include "d_system/d_wm_lib.h"

[[address_data(0x8042A538)]]
bool dScWMap_c::m_GameOver;

/* @unofficial */
[[address(0x801027A0)]]
void dScWMap_c::EnterWorld(WORLD_e world, int node);

[[address(0x80102B50)]]
u32 dScWMap_c::CreateBootParam();

[[address(0x80102B90)]]
void dScWMap_c::initLoadGame()
{
    dMj2dGame_c* save = dSaveMng_c::m_instance->getSaveGame(-1);
    dInfo_c* info = dInfo_c::m_instance;

    info->mWorld = save->mCurrentWorld;
    info->mWmSceneNo = save->mCurrentSubWorld;
    info->mWmNode = save->mCurrentPathNode;
    info->m0x048 = -1;
    info->SetIbaraNow(4, static_cast<dInfo_c::IbaraMode_e>(save->getIbaraNow()));
    info->SetIbaraOld(4, static_cast<dInfo_c::IbaraMode_e>(save->getIbaraNow()));
    info->mSwitchOn = save->mSwitchOn;

    for (int w = 0; w < WORLD_COUNT; w++) {
        for (int e = 0; e < AMBUSH_ENEMY_COUNT; e++) {
            info->SetWorldMapEnemy(
              w, e,
              {save->getCSEnemySceneNo(static_cast<WORLD_e>(w), e),
               save->getCSEnemyPosIndex(static_cast<WORLD_e>(w), e),
               save->getCSEnemyWalkDir(static_cast<WORLD_e>(w), e),
               save->getCSEnemyRevivalCnt(static_cast<WORLD_e>(w), e)}
            );
            info->mKinopioCourseNo[w] = save->getKinopioCourseNo(static_cast<WORLD_e>(w));
            info->mKinopioCourseInvalid[w] = info->mKinopioCourseNo[w] == STAGE_e::COUNT;
            info->mStage0x39F[w] = STAGE_e::COUNT;
        }
    }
    m_GameOver = false;
    dWmLib::ClearKinopioChukan();
}
