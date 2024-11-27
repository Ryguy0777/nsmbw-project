#pragma once

class SndAudioMgr {
public:
    // ----------------
    // Member Functions
    // ----------------

    /* 0x80196FD0 */
    void setIsReplay(bool value);

public:
    // -----------
    // Static Data
    // -----------

    /* 0x8042A768 */ static SndAudioMgr* sInstance;
};