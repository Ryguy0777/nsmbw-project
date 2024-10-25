// d_player_model_manager.cpp
// NSMBW: 0x800D6DB0 - 0x800D7190

#include "d_player_model_manager.h"

#include "d_kinopico_model.h"
#include "d_kinopio_model.h"
#include "d_mario_model.h"
#include "d_yoshi_model.h"
#include <machine/m_heap.h>

[[address(0x800D6DB0)]]
dPyMdlMng_c::dPyMdlMng_c(dPyMdlMng_c::ModelType_e modelType);

[[address(0x800D6E00)]]
void dPyMdlMng_c::construct(u8 index)
{
    switch (static_cast<ModelType_e>(index)) {
    case ModelType_e::MODEL_MARIO:
    case ModelType_e::MODEL_LUIGI:
        mModel = new (mHeap::g_gameHeaps[0], 4) dMarioMdl_c(index);
        break;

    case ModelType_e::MODEL_BLUE_TOAD:
    case ModelType_e::MODEL_YELLOW_TOAD:
    case ModelType_e::MODEL_RED_TOAD:
        mModel = new (mHeap::g_gameHeaps[0], 4) dKinopioMdl_c(index);
        break;

    case ModelType_e::MODEL_YOSHI:
        mModel = new (mHeap::g_gameHeaps[0], 4) dYoshiMdl_c(index);
        break;

    case ModelType_e::MODEL_TOADETTE:
        mModel = new (mHeap::g_gameHeaps[0], 4) dKinopicoMdl_c(index);
        break;

    default:
        mModel = nullptr;
        break;
    }
}

[[address(0x800D6EE0)]]
void dPyMdlMng_c::loadModel(s32 param_1, u8 param_2, s32 param_3);

[[address(0x800D6EF0)]]
dPyMdlMng_c::~dPyMdlMng_c();

[[address(0x800D6F80)]]
void dPyMdlMng_c::play();

[[address(0x800D6FA0)]]
void dPyMdlMng_c::calc(mMtx_c& mtx);

[[address(0x800D7030)]]
void dPyMdlMng_c::calc(mVec3_c vec, mAng3_c angle, mVec3_c vec2);

[[address(0x800D70F0)]]
void dPyMdlMng_c::calc2();

[[address(0x800D7110)]]
void dPyMdlMng_c::draw();

// 0x800D7140: __sinit_\d_player_model_manager_cpp