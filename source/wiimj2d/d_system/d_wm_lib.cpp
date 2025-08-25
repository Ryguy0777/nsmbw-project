// d_wm_lib.cpp
// NSMBW .text: 0x800F9380 - 0x800FD6A0

#include "d_wm_lib.h"

namespace dWmLib
{

[[address_data(0x8031D6B4)]]
float sc_0x8031D6B4;

[[address(0x800FBAF0)]]
void procCourseClear(bool isSecretExit, bool isSuperGuide, WORLD_e world, STAGE_e stage);

[[address(0x800FCAD0)]]
bool IsSingleEntry();

[[address(0x800FD1C0)]]
void RestoreKinopioHelpGameInfo();

} // namespace dWmLib