// SndObjectMap.cpp
// NSMBW .text: 0x80198CF0 - 0x80199A20

#include "SndObjectMap.h"

/* VT+0x08 */
[[address(0x80198CF0)]]
SndObjctCmnMap::~SndObjctCmnMap()
{
}

/* VT+0x20 */
[[address(0x80198D70)]]
nw4r::snd::SoundHandle*
SndObjctCmnMap::startSound(u32 soundId, const nw4r::math::VEC2& position, u32 remoteMask);

/* VT+0x24 */
[[address(0x80199100)]]
nw4r::snd::SoundHandle* SndObjctCmnMap::startSound(
  u32 soundId, const nw4r::math::VEC2& position, short seqParam, u32 remoteMask
);

/* VT+0x2C */
[[address(0x801994D0)]]
nw4r::snd::SoundHandle*
SndObjctCmnMap::holdSound(u32 soundId, int, const nw4r::math::VEC2& position, u32 remoteMask);

/* VT+0x30 */
[[address(0x801996E0)]]
nw4r::snd::SoundHandle* SndObjctCmnMap::holdSound(
  u32 soundId, int, const nw4r::math::VEC2& position, short seqParam, u32 remoteMask
);

[[address(00x80199950)]]
void SndObjctCmnMap::stopSound(u32 soundId);