// d_a_wm_2DPlayer.cpp
// NSMBW d_bases.text: 0x808C5100 - 0x808C7D10

#include "d_a_wm_2DPlayer.h"

#include "d_system/d_a_player_manager.h"

[[address(0x808C5990)]]
void da2DPlayer_c::loadPlayer()
{
    u32 id = mParam & 0xF;
    mPowerup = daPyMng_c::mPlayerMode[id];

    mModelMng = new dPyMdlMng_c(daPyMng_c::getPlayerTypeModelType(static_cast<PLAYER_TYPE_e>(id)));
    mModelMng->create(id, static_cast<u8>(mPowerup), dPyMdlMng_c::SceneType_c::SCENE_TYPE_2);

    mModelMng->mModel->setAnm(0, 1.2, 10.0, 0.0);
}