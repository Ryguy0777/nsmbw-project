// d_kinopico_model.cpp
// NSMBW: ---

#include "d_kinopico_model.h"

#include <dynamic/d_player_model.h>
#include <dynamic/d_player_model_manager.h>
#include <machine/m3d/m_anmtexpat.h>
#include <machine/m3d/m_mdl.h>
#include <nw4r/g3d/g3d_resmdl.h>

dKinopicoMdl_c::dKinopicoMdl_c(u8 index)
  : dPlayerMdl_c(index)
{
    static ModelData l_modelData = {
      "Kinopico",
      "K_rcha",
      {"CB_model", "SCB_model", "PLCB_model", "PCB_model"},
      {"CH_model", "SCH_model", "PLCH_model", "PCH_model"},
      18.0,
      13.0,
      18.0,
      18.0,
    };

    static ModelData l_modelDataPurple = {
      "KinopicoPurple",
      "K_rcha",
      {"CB_model", "SCB_model", "PLCB_model", "PCB_model"},
      {"CH_model", "SCH_model", "PLCH_model", "PCH_model"},
      18.0,
      13.0,
      18.0,
      18.0,
    };

    switch (static_cast<dPyMdlMng_c::ModelType_e>(index)) {
    case dPyMdlMng_c::ModelType_e::MODEL_TOADETTE:
    default:
        mpModelData = &l_modelData;
        break;

    case dPyMdlMng_c::ModelType_e::MODEL_TOADETTE_PURPLE:
        mpModelData = &l_modelDataPurple;
        break;
    };

    mFaceJointIdx = 15;
}

dKinopicoMdl_c::~dKinopicoMdl_c()
{
}

void dKinopicoMdl_c::createAnim(m3d::anmTexPat_c& anm, const char* name, u8 modelIdx)
{
    nw4r::g3d::ResAnmTexPat anmTexPat = mModelResFile.GetResAnmTexPat(name);
    nw4r::g3d::ResMdl mdl = mModelResFile.GetResMdl(
      modelIdx < MODEL_COUNT ? mpModelData->mBodyModels[modelIdx]
                             : mpModelData->mHeadModels[modelIdx - MODEL_COUNT]
    );
    anm.create(mdl, anmTexPat, &mAllocator, nullptr, 2);
}

void dKinopicoMdl_c::createPlayerModel()
{
    dPlayerMdl_c::createPlayerModel();

    createAnim(mHeadSwitchAnim, "PH_wait", MODEL_COUNT + MODEL_NORMAL);
    createAnim(mBodySwitchAnim, "KB_switch", MODEL_NORMAL);

    createAnim(mPropelHeadSwitchAnim, "PH_wait", MODEL_COUNT + MODEL_PROPELLER);
    createAnim(mPropelBodySwitchAnim, "PLKB_switch", MODEL_PROPELLER);

    createAnim(mPenguinHeadSwitchAnim, "PH_wait", MODEL_COUNT + MODEL_PENGUIN);
    createAnim(mPenguinBodySwitchAnim, "PKB_switch", MODEL_PENGUIN);
}

m3d::anmTexPat_c* dKinopicoMdl_c::getBodyTexAnm()
{
    switch (mModelIdx) {
    default:
        return &mBodySwitchAnim;
    case MODEL_PROPELLER:
        return &mPropelBodySwitchAnim;
    case MODEL_PENGUIN:
        return &mPenguinBodySwitchAnim;
    }
}

void dKinopicoMdl_c::setColorType(u8 colorType)
{
    if (mCurColorType == colorType) {
        return;
    }

    mCurColorType = colorType;
    int modelIdx = static_cast<int>(mModelIdx);

    float frame = 0;
    if (colorType == 1) {
        frame = 1;
    } else if (colorType == 2) {
        frame = 2;
    }

    using StringArray = const char* const[];

    // Head animation
    {
        m3d::anmTexPat_c* headTexAnm = getHeadTexAnm();

        nw4r::g3d::ResAnmTexPat anmTexPat = mModelResFile.GetResAnmTexPat(
          StringArray{"KH_switch", "KH_switch", "PLKH_switch", "PKH_switch"}[modelIdx]
        );
        headTexAnm->setAnm(mModels[modelIdx].mHead, anmTexPat, 0, m3d::PLAY_MODE_4);

        headTexAnm->setRate(0.0, 0);
        headTexAnm->setFrame(frame, 0);
        mModels[modelIdx].mHead.setAnm(*headTexAnm);
    }

    // Body animation
    {
        m3d::anmTexPat_c* bodyTexAnm = getBodyTexAnm();

        nw4r::g3d::ResAnmTexPat anmTexPat = mModelResFile.GetResAnmTexPat(
          StringArray{"KB_switch", "KB_switch", "PLKB_switch", "PKB_switch"}[modelIdx]
        );
        m3d::mdl_c* bodyMdl = getBodyMdl();

        bodyTexAnm->setAnm(*bodyMdl, anmTexPat, 0, m3d::PLAY_MODE_4);

        bodyTexAnm->setRate(0.0, 0);
        bodyTexAnm->setFrame(frame, 0);
        bodyMdl->setAnm(*bodyTexAnm);
    }
}

float dKinopicoMdl_c::VT_0xB4()
{
    MODEL_e model = mModelIdx;
    if (mFlags & 0x800000 || mFlags & 0x1000000) {
        model = MODEL_NORMAL;
    }

    using FloatArray = float[];

    float length;
    if (mFlags & 0x400000) {
        // Big
        length = FloatArray{1.0, 0.628, 1.0, 1.0}[model];
    } else {
        // Small
        length = FloatArray{0.6, 0.377, 0.6, 0.45}[model];
    }

    if (mFlags & 0x8) {
        length += FloatArray{0.15, 0.2, 0.15, 0.37}[model];

        if (mPowerupID == 3) {
            length -= 0.05;
        }
    }

    return length;
}