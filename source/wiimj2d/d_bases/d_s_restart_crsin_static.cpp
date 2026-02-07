// d_s_restart_crsin_static.cpp
// NSMBW .text: 0x801018E0 - 0x80101A50

#include "d_bases/d_s_crsin.h"

#include "d_bases/d_s_stage.h"
#include "d_profile/d_profile.h"
#include "d_s_restart_crsin.h"
#include "d_system/d_fader.h"

[[nsmbw(0x80374060)]]
dInfo_c::StartGameInfo_s dScRestartCrsin_c::m_startGameInfo;

[[nsmbw(0x801018E0)]]
void dScRestartCrsin_c::startTitle(u8 isDemo, bool param2)
{
    /* 0x802F4CD0 */
    static constexpr dInfo_c::StageNo_s c_stage[dScStage_c::TITLE_REPLAY_COUNT] = {
      {WORLD_e::WORLD_1, STAGE_e::STAGE_4}, {WORLD_e::WORLD_1, STAGE_e::STAGE_6},
      {WORLD_e::WORLD_2, STAGE_e::STAGE_1}, {WORLD_e::WORLD_2, STAGE_e::STAGE_4},
      {WORLD_e::WORLD_3, STAGE_e::STAGE_1}, {WORLD_e::WORLD_3, STAGE_e::STAGE_5},
      {WORLD_e::WORLD_3, STAGE_e::TOWER},   {WORLD_e::WORLD_4, STAGE_e::STAGE_1},
      {WORLD_e::WORLD_4, STAGE_e::STAGE_5}, {WORLD_e::WORLD_5, STAGE_e::STAGE_4},
      {WORLD_e::WORLD_5, STAGE_e::STAGE_5}, {WORLD_e::WORLD_5, STAGE_e::GHOST_HOUSE},
      {WORLD_e::WORLD_6, STAGE_e::CASTLE},  {WORLD_e::WORLD_7, STAGE_e::STAGE_6},
      {WORLD_e::WORLD_8, STAGE_e::STAGE_7},
    };

    if (isDemo || fFeat::autoboot_title_demo) {
        if (fFeat::autoboot_title_demo) {
            dScStage_c::m_titleCount =
              (dScStage_c::m_titleCount + 1) % dScStage_c::TITLE_REPLAY_COUNT;
        }

        const dInfo_c::StageNo_s& stage =
          c_stage[dScStage_c::m_titleRandomTable[dScStage_c::m_titleCount]];
        m_startGameInfo.isDemo = true;
        m_startGameInfo.stage1 = c_stage[0];
        m_startGameInfo.stage2 = stage;
        m_startGameInfo.screenType = dInfo_c::ScreenType_e::TITLE_REPLAY;
    } else {
        m_startGameInfo.isDemo = false;
        m_startGameInfo.stage1 = {WORLD_e::WORLD_1, STAGE_e::TITLE};
        m_startGameInfo.stage2 = {WORLD_e::WORLD_1, STAGE_e::TITLE};
        m_startGameInfo.screenType = dInfo_c::ScreenType_e::TITLE;
    }

    m_startGameInfo.courseID = 0;
    m_startGameInfo.gotoID = -1;

    dFader_c::setFader(dFader_c::fader_type_e::FADE);
    dScCrsin_c::m_isDispOff = true;
    dScene_c::setNextScene(dProf::RESTART_CRSIN, param2, param2);
}
