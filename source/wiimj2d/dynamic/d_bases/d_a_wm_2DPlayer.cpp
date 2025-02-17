// d_a_wm_2DPlayer.cpp
// NSMBW d_bases.text: 0x808C5100 - 0x808C7D10

#include "d_a_wm_2DPlayer.h"

#include <dynamic/d_a_player_manager.h>

[[address(0x808C5990)]]
void da2DPlayer_c::loadPlayer()
{
    u32 id = mParam & 0xF;
    s32 powerup = daPyMng_c::mPlayerMode[id];
    mPowerup = static_cast<PLAYER_POWERUP_e>(powerup);

    mModelMng =
      new dPyMdlMng_c(daPyMng_c::getPlayerTypeModelType(static_cast<daPyMng_c::PlayerType_e>(id)));
    mModelMng->loadModel(id, powerup, 2);

    mModelMng->mModel->setAnm(0, 1.2, 10.0, 0.0);
}