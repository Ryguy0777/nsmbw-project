// d_wm_lib.cpp
// NSMBW .text: 0x800F9380 - 0x800FD6A0

#include "d_wm_lib.h"

namespace dWmLib
{

[[address(0x800FBAF0)]]
void procCourseClear(bool isSecretExit, bool isSuperGuide, WORLD_e world, STAGE_e stage);

} // namespace dWmLib