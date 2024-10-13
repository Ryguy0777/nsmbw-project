// d_kinopico_model.cpp
// NSMBW: ---

#include "d_kinopico_model.h"

dKinopicoMdl_c::dKinopicoMdl_c()
  : dPlayerMdl_c()
{
    static ModelData l_modelData = {
      "Kinopico",
      "C_rcha",
      {"CB_model", "SCB_model", "PLCB_model", "PCB_model"},
      {"CH_model", "SCH_model", "PLCH_model", "PCH_model"},
      18.0,
      13.0,
      18.0,
      18.0,
    };

    mpModelData = &l_modelData;

    mFaceJointIdx = 15;
}

dKinopicoMdl_c::~dKinopicoMdl_c()
{
}

float dKinopicoMdl_c::getLegLengthP(u8 param_1)
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