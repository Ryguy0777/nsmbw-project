// d_gamewatch_model.cpp
// nsmbw-project

#include "d_gamewatch_model.h"

#include "d_system/d_player_model.h"
#include "d_system/d_player_model_manager.h"
#include "machine/m_3d_anmtexpat.h"
#include "machine/m_3d_mdl.h"
#include <nw4r/g3d/g3d_resmdl.h>

dGameWatchMdl_c::dGameWatchMdl_c(u8 index)
  : dPlayerMdl_c(index)
{
    static ModelData l_modelData = {
      "GameWatch",
      "L_rcha",
      {"MB_model", "SMB_model", "PLMB_model", "PMB_model"},
      {"MH_model", "SMH_model", "PLMH_model", "PMH_model"},
      13.0,
      10.0,
      13.0,
      13.0,
    };

    mpModelData = &l_modelData;

    mFaceJointIdx = 16;
}

dGameWatchMdl_c::~dGameWatchMdl_c()
{
}

void dGameWatchMdl_c::createAnim(m3d::anmTexPat_c& anm, const char* name, u8 modelIdx)
{
    nw4r::g3d::ResAnmTexPat anmTexPat = mModelResFile.GetResAnmTexPat(name);
    nw4r::g3d::ResMdl mdl = mModelResFile.GetResMdl(
      modelIdx < MODEL_COUNT ? mpModelData->mBodyModels[modelIdx]
                             : mpModelData->mHeadModels[modelIdx - MODEL_COUNT]
    );
    anm.create(mdl, anmTexPat, &mAllocator, nullptr, 2);
}

void dGameWatchMdl_c::createPlayerModel()
{
    dPlayerMdl_c::createPlayerModel();

    createAnim(mHeadSwitchAnim, "PH_wait", MODEL_COUNT + MODEL_NORMAL);
    createAnim(mBodySwitchAnim, "PB_switch", MODEL_NORMAL);

    createAnim(mPropelHeadSwitchAnim, "PH_wait", MODEL_COUNT + MODEL_PROPELLER);

    createAnim(mPenguinHeadSwitchAnim, "PH_wait", MODEL_COUNT + MODEL_PENGUIN);
}

m3d::anmTexPat_c* dGameWatchMdl_c::getBodyTexAnm()
{
    return &mBodySwitchAnim;
}

float dGameWatchMdl_c::VT_0xB4()
{
    MODEL_e model = mModelIdx;
    if (mFlags & 0x800000 || mFlags & 0x1000000) {
        model = MODEL_NORMAL;
    }

    using FloatArray = float[];

    float length = FloatArray{1.0, 0.546, 1.0, 0.72}[model];

    if (!(mFlags & 0x8)) {
        length += FloatArray{0.0, 0.0, 0.0, 0.55}[model];
    }

    return length;
}
