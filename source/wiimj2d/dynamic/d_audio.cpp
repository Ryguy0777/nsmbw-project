// d_audio.cpp
// NSMBW .text: 0x80069500 - 0x8006C0B0
// NSMBW .bss:  0x803561E8 - 0x80356208

#include "d_audio.h"

#include <dynamic/d_a_player_manager.h>
#include <revolution/os/OSLink.h>

namespace dAudio
{

/* 0x803561F8 */
NonPosSndObjctPly_c* g_pNonPosSndObjctPly[PLAYER_COUNT];

PATCH_REFERENCES(
  g_pNonPosSndObjctPly,
  {
    {0x80069E66, R_PPC_ADDR16_HA},
    {0x80069E76, R_PPC_ADDR16_LO},
    {0x8006A02A, R_PPC_ADDR16_HA},
    {0x8006A02E, R_PPC_ADDR16_LO},
    {0x800D72D2, R_PPC_ADDR16_HA},
    {0x800D72E2, R_PPC_ADDR16_LO},
    {0x800D7356, R_PPC_ADDR16_HA},
    {0x800D7366, R_PPC_ADDR16_LO},
    {0x800D73B6, R_PPC_ADDR16_HA},
    {0x800D73BA, R_PPC_ADDR16_LO},
  }
)

} // namespace dAudio