// d_a_2d_player.cpp
// NSMBW d_bases.text: 0x808C5100 - 0x808C7D10

#include "d_a_2d_player.h"

#include <dynamic/actor/bases/d_a_player_manager.h>

[[address(0x808C5990)]]
void da2DPlayer_c::loadPlayer()
{
    u32 id = mParam & 0xF;
    s32 powerup = daPyMng_c::mPlayerMode[id];
    mPowerup = powerup;

    static constexpr dPyMdlMng_c::ModelType_e sPlayerModelType[] = {
      dPyMdlMng_c::ModelType_e::MODEL_MARIO,     dPyMdlMng_c::ModelType_e::MODEL_LUIGI,
      dPyMdlMng_c::ModelType_e::MODEL_BLUE_TOAD, dPyMdlMng_c::ModelType_e::MODEL_YELLOW_TOAD,
      dPyMdlMng_c::ModelType_e::MODEL_TOADETTE,
    };

    mModelMng = new dPyMdlMng_c(sPlayerModelType[id]);
    mModelMng->loadModel(id, powerup, 2);

    mModelMng->mModel->setAnm(0, 1.2, 10.0, 0.0);
}