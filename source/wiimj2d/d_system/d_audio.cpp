// d_audio.cpp
// NSMBW .text: 0x80069500 - 0x8006C0B0
// NSMBW .bss:  0x803561E8 - 0x80356208

#include "d_audio.h"

#include <mkwcat/Relocate.hpp>
#include "d_system/d_a_player_manager.h"

namespace dAudio
{

[[address_data(0x8042A03C)]]
SndObjctCmnEmy_c* g_pSndObjEmy;

[[address_data(0x8042A040)]]
SndObjctCmnMap_c* g_pSndObjMap;

/* 0x803561F8 */
NonPosSndObjctPly_c* g_pNonPosSndObjctPly[PLAYER_COUNT];

[[address(0x80069520)]] [[nodiscard]]
bool isForbidRemoteSE();

[[address(0x80069530)]]
u32 getRemotePlayer(int player)
{
    if (isForbidRemoteSE()) {
        return 0;
    }

    if (player >= 4) {
        return 0;
    }

    return 0b10 << player;
}

[[address(0x8006A3F0)]]
nw4r::math::VEC2 cvtSndObjctPos(const mVec2_c& pos);

PATCH_REFERENCES(&
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

[[address(0x8006A7D0)]]
void pauseMove(int player);

[[address(0x8006A7F0)]]
void pauseOffMove(int player);

/* VT+0x08 - Moved here */
[[address(0x80104160)]]
SndObjctCSPly_c::~SndObjctCSPly_c()
{
}

} // namespace dAudio
