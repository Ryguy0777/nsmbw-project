#pragma once

#include <machine/m_vec.h>
#include <sound/SndAudioMgr.h>
#include <sound/SndObjectMap.h>
#include <sound/SndObjectPlayer.h>

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

class SndObjctCSPly_c final : public SndObjctPly
{
    SIZE_ASSERT(0xB5);

    /* 0x00 VTABLE 0x80321E88 */

public:
    // ------------
    // Constructors
    // ------------

    SndObjctCSPly_c()
      : SndObjctPly(*SndAudioMgr::sInstance->mpSoundArchivePlayer)
    {
    }

    /* VT+0x08 0x80104160 */
    virtual ~SndObjctCSPly_c() override;

public:
    // -----------------
    // Virtual Functions
    // -----------------

    /* VT+0x24 */
    [[address(0x801052C0)]]
    virtual nw4r::snd::SoundHandle* startSound(u32 soundId, u32 remoteMask) override;

    /* VT+0x28 */
    [[address(0x801050D0)]]
    virtual nw4r::snd::SoundHandle* holdSound(u32 soundId, u32 remoteMask) override;

    /* VT+0x30 */
    [[address(0x80106040)]]
    virtual nw4r::snd::SoundHandle*
    startSound(u32 soundId, short seqParam, u32 remoteMask) override;

    /* VT+0x34 */
    [[address(0x801050C0)]]
    virtual nw4r::snd::SoundHandle* holdSound(u32 soundId, short seqParam, u32 remoteMask) override;
};

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