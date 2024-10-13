// d_player_model.cpp
// NSMBW: 0x800D2EC0 - 0x800D5420

#include "d_player_model.h"

/* */
EXTERN_TEXT(
  0x800D2EC0, //
  dPlayerMdl_c::dPlayerMdl_c()
);

/* VT+0x08 */
EXTERN_TEXT(
  0x800D31D0, //
  dPlayerMdl_c::~dPlayerMdl_c()
);

/* VT+0x10 */
EXTERN_TEXT(
  0x800D3300, //
  void dPlayerMdl_c::createModel()
);

/* VT+0x14 */
EXTERN_TEXT(
  0x800D3370, //
  void dPlayerMdl_c::initialize()
);

/* VT+0x1C */
EXTERN_TEXT(
  0x800D37D0, //
  void dPlayerMdl_c::_calc()
);

/* VT+0x20 */
EXTERN_TEXT(
  0x800D3920, //
  void dPlayerMdl_c::calc2()
);

/* VT+0x18 */
EXTERN_TEXT(
  0x800D3990, //
  void dPlayerMdl_c::play()
);

/* VT+0x24 */
EXTERN_TEXT(
  0x800D3B20, //
  void dPlayerMdl_c::draw()
);

/* VT+0x80 */
EXTERN_TEXT(
  0x800D3CE0, //
  void dPlayerMdl_c::setTexAnmType(TexAnmType_e)
);

/* VT+0x7C */
EXTERN_TEXT(
  0x800D3DD0, //
  void dPlayerMdl_c::VT_0x7C()
);

/* VT+0x60 */
EXTERN_TEXT(
  0x800D3FE0, //
  void dPlayerMdl_c::VT_0x60()
);

/* VT+0x58 */
EXTERN_TEXT(
  0x800D4150, //
  void dPlayerMdl_c::VT_0x58()
);

/* VT+0x6C */
EXTERN_TEXT(
  0x800D41E0, //
  void dPlayerMdl_c::copyAnm()
);

/* VT+0x70 */
EXTERN_TEXT(
  0x800D4330, //
  void dPlayerMdl_c::VT_0x70()
);

/* VT+0x74 */
EXTERN_TEXT(
  0x800D44D0, //
  void dPlayerMdl_c::VT_0x74()
);

/* VT+0x78 */
EXTERN_TEXT(
  0x800D4610, //
  void dPlayerMdl_c::setAnmBind()
);

/* VT+0x30 */
EXTERN_TEXT(
  0x800D4760, //
  void dPlayerMdl_c::setPlayerMode(int)
);

/* VT+0x34 */
EXTERN_TEXT(
  0x800D4870, //
  void dPlayerMdl_c::setColorType(u8)
);

/* VT+0x38 */
EXTERN_TEXT(
  0x800D4880, //
  void dPlayerMdl_c::setDark(int)
);

/* VT+0x54 */
EXTERN_TEXT(
  0x800D4A70, //
  bool dPlayerMdl_c::getHeadPropelJointMtx(mMtx_c*)
);

/* VT+0x40 */
EXTERN_TEXT(
  0x800D4AC0, //
  void dPlayerMdl_c::onStarAnm()
);

/* VT+0x44 */
EXTERN_TEXT(
  0x800D4B40, //
  void dPlayerMdl_c::offStarAnm()
);
