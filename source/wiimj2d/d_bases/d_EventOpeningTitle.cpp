// d_EventOpeningTitle.cpp
// NSMBW d_bases.text: 0x80781980 - 0x80782AB0

#include "d_EventOpeningTitle.h"

#include "d_bases/d_s_restart_crsin.h"
#include "d_bases/d_s_stage.h"
#include "d_profile/d_profile.h"
#include "d_system/d_info.h"

[[nsmbw(0x80782340)]]
void dEventOpeningTitle_c::executeState_PressButtonExitAnimeEndWait()
{
    if (dScStage_c::m_gameMode == dScStage_c::GAME_MODE_e::UNKNOWN_2 && m_layout.isAnime()) {
        return;
    }

    if (dScStage_c::m_gameMode == dScStage_c::GAME_MODE_e::UNKNOWN_2) {
        return dScStage_c::setNextScene(
          dProf::GAME_SETUP, 0, dScStage_c::Exit_e(0), dFader_c::fader_type_e::UNKNOWN_5
        );
    }

    dInfo_c::clearGameFlag(dInfo_c::GameFlag_e::MULTI_MODE);
    dScRestartCrsin_c::startTitle(false, false);
}