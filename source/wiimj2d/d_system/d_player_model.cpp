// d_player_model.cpp
// NSMBW .text: 0x800D2EC0 - 0x800D5420

#include "d_player_model.h"

[[address(0x800D2EC0)]]
dPlayerMdl_c::dPlayerMdl_c(u8 index);

/* VT+0x08 */
[[address(0x800D31D0)]]
dPlayerMdl_c::~dPlayerMdl_c();

/* VT+0x10 */
[[address(0x800D3300)]]
void dPlayerMdl_c::createModel();

/* VT+0xB4 */
[[address(0x800D3360)]]
float dPlayerMdl_c::VT_0xB4();

/* VT+0x14 */
[[address(0x800D3370)]]
void dPlayerMdl_c::initialize();

/* VT+0xB8 */
[[address(0x800D3470)]]
void dPlayerMdl_c::createPlayerModel();

/* VT+0x1C */
[[address(0x800D37D0)]]
void dPlayerMdl_c::_calc();

/* VT+0x20 */
[[address(0x800D3920)]]
void dPlayerMdl_c::calc2();

/* VT+0x18 */
[[address(0x800D3990)]]
void dPlayerMdl_c::play();

/* VT+0x24 */
[[address(0x800D3B20)]]
void dPlayerMdl_c::draw();

/* VT+0x80 */
[[address(0x800D3CE0)]]
void dPlayerMdl_c::setTexAnmType(TexAnmType_e);

[[address(0x800D3DA0)]]
m3d::anmTexPat_c* dPlayerMdl_c::getHeadTexAnm();

/* VT+0x7C */
[[address(0x800D3DD0)]]
void dPlayerMdl_c::VT_0x7C();

/* VT+0x60 */
[[address(0x800D3FE0)]]
bool dPlayerMdl_c::prepareBodyAnm(ChrAnmType_e type, nw4r::g3d::ResAnmChr* anm, bool noUpdate);

/* VT+0x58 */
[[address(0x800D4150)]]
void dPlayerMdl_c::VT_0x58();

/* VT+0x6C */
[[address(0x800D41E0)]]
void dPlayerMdl_c::copyAnm();

/* VT+0x70 */
[[address(0x800D4330)]]
void dPlayerMdl_c::VT_0x70();

/* VT+0x74 */
[[address(0x800D44D0)]]
void dPlayerMdl_c::VT_0x74();

/* VT+0x78 */
[[address(0x800D4610)]]
void dPlayerMdl_c::setAnmBind();

/* VT+0xAC */
[[address(0x800D4750)]]
void dPlayerMdl_c::setCurrentModel(MODEL_e model);

/* VT+0x30 */
[[address(0x800D4760)]]
void dPlayerMdl_c::setPlayerMode(int);

/* VT+0x34 */
[[address(0x800D4870)]]
void dPlayerMdl_c::setColorType(u8);

/* VT+0x38 */
[[address(0x800D4880)]]
void dPlayerMdl_c::setDark(int);

/* VT+0x54 */
[[address(0x800D4A70)]]
bool dPlayerMdl_c::getHeadPropelJointMtx(mMtx_c*);

/* VT+0x40 */
[[address(0x800D4AC0)]]
void dPlayerMdl_c::onStarAnm();

/* VT+0x44 */
[[address(0x800D4B40)]]
void dPlayerMdl_c::offStarAnm();

/* VT+0xB0 */
[[address(0x800D4E70)]]
void dPlayerMdl_c::callbackTimingA(void* param_1, void* param_2);
