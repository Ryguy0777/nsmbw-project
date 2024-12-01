#pragma once

#include "BasicSound.h"
#include "SoundStartable.h"

namespace nw4r::snd
{

class SoundArchivePlayer;

class SoundActor : public SoundStartable
{
    SIZE_ASSERT(0x54);

    /* 0x00 VTABLE 0x8034F3F8 */

public:
    // ------------
    // Constructors
    // ------------

    SoundActor();

    /* VT+0x08 0x802755F0 */
    virtual ~SoundActor();

public:
    // -----------------
    // Virtual Functions
    // -----------------

    /* VT+0x0C 0x80275710 */
    virtual StartResult detail_SetupSound(
      SoundHandle* pHandle, u32 id, bool hold, const StartInfo* pStartInfo
    ) override;

    /* VT+0x10 0x80275750 */
    virtual u32 detail_ConvertLabelStringToSoundId(const char* pLabel) override;

    /* VT+0x14 0x802756D0 */
    virtual StartResult
    StartSound(SoundHandle* pHandle, u32 id, bool hold, const StartInfo* pStartInfo, void*);

    /* VT+0x18 0x802756F0 */
    virtual StartResult
    detail_SetupSoundWithAmbientInfo(SoundHandle* pHandle, u32 id, bool hold, const StartInfo* pStartInfo, detail::BasicSound::AmbientArgInfo* pAmbientArgInfo, void*);

public:
    // ----------------
    // Member Functions
    // ----------------

    [[address(0x802756A0)]]
    u32 GetPlayingSoundCount(int) const;

    [[address(0x802756B0)]]
    void SetPlayableSoundCount(int, int);

public:
    // -----------
    // Member Data
    // -----------

    /* 0x04 */ SoundArchivePlayer& mSoundArchivePlayer;

    FILL(0x08, 0x54);
};

} // namespace nw4r::snd