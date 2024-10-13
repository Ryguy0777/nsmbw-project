// d_player_model_manager.cpp
// NSMBW: 0x800D6DB0 - 0x800D7190

#include "d_player_model_manager.h"

EXTERN_TEXT(
  0x800D6DB0, //
  dPyMdlMng_c::dPyMdlMng_c(dPyMdlMng_c::ModelType_e modelType)
);

EXTERN_TEXT(
  0x800D6E00, //
  void dPyMdlMng_c::construct(u8 index)
);

EXTERN_TEXT(
  0x800D6EE0, //
  void dPyMdlMng_c::loadModel(s32 param_1, u8 param_2, s32 param_3)
);

// EXTERN_TEXT(
//   0x800D6EF0, //
//   dPyMdlMng_c::~dPyMdlMng_c()
// );

EXTERN_TEXT(
  0x800D6F80, //
  void dPyMdlMng_c::play()
);

EXTERN_TEXT(
  0x800D6FA0, //
  void dPyMdlMng_c::calc(mMtx_c& mtx)
);

EXTERN_TEXT(
  0x800D7030, //
  void dPyMdlMng_c::calc(mVec3_c vec, mAng3_c angle, mVec3_c vec2)
);

EXTERN_TEXT(
  0x800D70F0, //
  void dPyMdlMng_c::calc2()
);

EXTERN_TEXT(
  0x800D7110, //
  void dPyMdlMng_c::draw()
);

// 0x800D7140: __sinit_\d_player_model_manager_cpp