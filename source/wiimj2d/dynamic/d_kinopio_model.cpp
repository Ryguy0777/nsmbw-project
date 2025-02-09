// d_kinopio_model.cpp
// NSMBW .text: 0x800BCBD0 - 0x800BD7F0

#include "d_kinopio_model.h"

#include <dynamic/d_player_model_manager.h>

[[address(0x800BCBD0)]]
dKinopioMdl_c::dKinopioMdl_c(u8 index)
  : dPlayerMdl_c(index)
{
    static ModelData l_modelData = {
      "Kinopio",
      "K_rcha",
      {"KB_model", "SKB_model", "PLKB_model", "PKB_model"},
      {"KH_model", "SKH_model", "PLKH_model", "PKH_model"},
      18.0,
      13.0,
      18.0,
      18.0,
    };

    static ModelData l_modelDataBlackOrange = {
      "KinopioBlackOrange",
      "K_rcha",
      {"KB_model", "SKB_model", "PLKB_model", "PKB_model"},
      {"KH_model", "SKH_model", "PLKH_model", "PKH_model"},
      18.0,
      13.0,
      18.0,
      18.0,
    };

    switch (static_cast<dPyMdlMng_c::ModelType_e>(index)) {
    case dPyMdlMng_c::ModelType_e::MODEL_TOAD_BLUE:
    case dPyMdlMng_c::ModelType_e::MODEL_TOAD_YELLOW:
    case dPyMdlMng_c::ModelType_e::MODEL_TOAD_RED:
    default:
        mpModelData = &l_modelData;
        break;

    case dPyMdlMng_c::ModelType_e::MODEL_TOAD_BLACK:
        mCharaID = static_cast<u8>(dPyMdlMng_c::ModelType_e::MODEL_TOAD_BLUE);
        mpModelData = &l_modelDataBlackOrange;
        break;

    case dPyMdlMng_c::ModelType_e::MODEL_TOAD_ORANGE:
        mCharaID = static_cast<u8>(dPyMdlMng_c::ModelType_e::MODEL_TOAD_YELLOW);
        mpModelData = &l_modelDataBlackOrange;
        break;
    };

    mFaceJointIdx = 15;
}

/* VT+0x08 */
dKinopioMdl_c::~dKinopioMdl_c()
{
}

/* VT+0xB8 */
[[address(0x800BCD20)]]
void dKinopioMdl_c::createPlayerModel();

/* VT+0x34 */
[[address(0x800BCF30)]]
void dKinopioMdl_c::setColorType(u8 colorType);

/* VT+0x80 */
[[address(0x800BD160)]]
void dKinopioMdl_c::setTexAnmType(TexAnmType_e);

/* VT+0x60 */
[[address(0x800BD260)]]
s32 dKinopioMdl_c::VT_0x60(s32 param1, s32 param2, s32 param3);

/* VT+0x7C */
[[address(0x800BD5D0)]]
void dKinopioMdl_c::VT_0x7C();

/* VT+0xB4 */
[[address(0x800BD670)]]
float dKinopioMdl_c::VT_0xB4();

/* VT+0xB0 */
[[address(0x800BD6F0)]]
void dKinopioMdl_c::callbackTimingA(void* param_1, void* param_2);
