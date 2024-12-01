#pragma once

#include "BasicSound.h"

namespace nw4r::snd
{

struct SoundHandle {
    SIZE_ASSERT(0x4);

    detail::BasicSound* mpSound;
};

} // namespace nw4r::snd