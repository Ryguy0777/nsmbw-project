#pragma once

#include "eggSoundHeapMgr.h"

namespace EGG
{

class IAudioMgr
{
public:
    // -------------------
    // Constants and Types
    // -------------------

    class Arg
    {
    };

public:
    // -----------------
    // Virtual Functions
    // -----------------

    /* VT+0x8 */
    virtual void initialize(Arg*)
    {
    }

    /* VT+0xC */
    virtual void calc() = 0;
};

class SimpleAudioMgr : public IAudioMgr
{
public:
    // -----------
    // Member Data
    // -----------

    FILL(0x004, 0x008);

    /* 0x008 */ EGG::SoundHeapMgr mHeapMgr;
};

class ExpAudioMgr : public SimpleAudioMgr
{
};

} // namespace EGG