#pragma once

#include <machine/m_vec.h>
#include <sound/SndObjctCmnMap.h>

namespace dAudio
{

// -------------------
// Constants and Types
// -------------------

class SndObjctCmnEmy_c;

class SndObjctCmnMap_c final : public SndObjctCmnMap
{
};

class NonPosSndObjctPly_c;

// ----------------
// Global Variables
// ----------------

/* 0x8042A03C */
extern SndObjctCmnEmy_c* g_pSndObjEmy;

/* 0x8042A040 */
extern SndObjctCmnMap_c* g_pSndObjMap;

// ---------
// Functions
// ---------

/* 0x80069530 */
u32 getRemotePlayer(int player);

/* 0x8006A3F0 */
nw4r::math::VEC2 cvtSndObjctPos(const mVec2_c& pos);

} // namespace dAudio