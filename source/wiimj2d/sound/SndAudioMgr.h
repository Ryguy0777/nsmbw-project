#pragma once

#include <nw4r/snd/SoundArchivePlayer.h>

class SndAudioMgr
{
public:
    // ----------------
    // Member Functions
    // ----------------

    /* 0x801954C0 */
    void startSystemSe(unsigned int sound, u32 param2);

    /* 0x80196FD0 */
    void setIsReplay(bool value);

public:
    // -----------
    // Member Data
    // -----------

    FILL(0x000, 0x5BC);

    /* 0x5BC */ nw4r::snd::SoundArchivePlayer* mpSoundArchivePlayer;

public:
    // -----------
    // Static Data
    // -----------

    /* 0x8042A768 */ static SndAudioMgr* sInstance;
};