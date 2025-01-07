#pragma once

#include "BasicSound.h"

namespace nw4r::snd
{

class SoundHandle
{
    SIZE_ASSERT(0x4);

public:
    // ------------
    // Constructors
    // ------------

    SoundHandle()
      : mpSound(nullptr)
    {
    }

    ~SoundHandle()
    {
        DetachSound();
    }

public:
    // ----------------
    // Member Functions
    // ----------------

    [[address(0x8027A340)]]
    void DetachSound();

public:
    // -----------
    // Member Data
    // -----------

    /* 0x0 */ detail::BasicSound* mpSound;
};

} // namespace nw4r::snd