// m_mdl.cpp
// NSMBW .text: 0x801696A0 - 0x8016A150

#include "m_3d_mdl.h"

namespace m3d
{

[[nsmbw(0x8016A070)]]
void mdl_c::setAnm(banm_c&);

[[nsmbw(0x8016A0C0)]]
void mdl_c::setAnm(banm_c&, f32);

} // namespace m3d