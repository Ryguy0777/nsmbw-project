// d_a_player.cpp
// NSMBW: 0x80126650 - 0x8014A480

#include "d_a_player.h"
#include "dynamic/d_fader.h"
#include "dynamic/scene/d_s_stage.h"

#include <dynamic/actor/d_a_player_manager.h>
#include <framework/f_base.h>

[[address(0x80138FA0)]]
bool dAcPy_c::setBalloonInDamage();

[[address(0x8013D7B0)]]
void dAcPy_c::checkRest()
{
    if (isItemKinopio()) {
        deleteRequest();
        return;
    }

    if (m0x14F0 == 0) {
        setBalloonInDamage();
        return;
    }

    if (isStatus(5)) {
        return;
    }
    onStatus(5);

    bool gameOver = true;

    for (int i = 0; i < PLAYER_COUNT; i++) {
        if (daPyMng_c::mPlayerEntry[i] != 0 &&
            daPyMng_c::mRest[int(daPyMng_c::mPlayerType[i])] != 0) {
            gameOver = false;
            break;
        }
    }

    if (gameOver) {
        dScStage_c::goToSceneAfterLevel(
          +fBaseProfile_e::GAMEOVER, 0, 1, dFader_c::fader_type_e::BOWSER
        );
    }
}