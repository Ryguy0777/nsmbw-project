#pragma once

class SndSceneMgr
{
public:
    // ----------------
    // Member Functions
    // ----------------

    /* 0x8019BB60 @unofficial */
    void setGameSetupTrack(int track);

    /* 0x8019C010 @unofficial */
    void setMiniGameTrack(int track);

    /* 0x8019CDB0 */
    void closeWindow();

public:
    // -----------
    // Static Data
    // -----------

    /* 0x8042A788 */ static SndSceneMgr* sInstance;
};
