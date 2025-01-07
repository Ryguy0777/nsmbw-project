// snd_SoundActor.cpp
// NSMBW: 0x80275530 - 0x80275780

#include "SoundActor.h"

namespace nw4r::snd
{

[[address(0x80275530)]]
SoundActor::SoundActor(nw4r::snd::SoundArchivePlayer&);

[[address(0x802755F0)]]
SoundActor::~SoundActor();

[[address(0x802756A0)]]
u32 SoundActor::GetPlayingSoundCount(int) const;

[[address(0x802756B0)]]
void SoundActor::SetPlayableSoundCount(int, int);

[[address(0x802756D0)]]
SoundActor::StartResult
SoundActor::SetupSound(SoundHandle* pHandle, u32 id, bool hold, const StartInfo* pStartInfo, void*);

[[address(0x802756F0)]]
SoundActor::StartResult SoundActor::
  detail_SetupSoundWithAmbientInfo(SoundHandle* pHandle, u32 id, bool hold, const StartInfo* pStartInfo, detail::BasicSound::AmbientArgInfo* pAmbientArgInfo, void*);

[[address(0x80275710)]]
SoundActor::StartResult
SoundActor::detail_SetupSound(SoundHandle* pHandle, u32 id, bool hold, const StartInfo* pStartInfo);

[[address(0x80275750)]]
u32 SoundActor::detail_ConvertLabelStringToSoundId(const char* pLabel);

} // namespace nw4r::snd