// SndSceneMgr.cpp
// NSMBW .text: 0x8019B500 - 0x8019DE90

#include "SndSceneMgr.h"

[[address_data(0x8042A788)]]
SndSceneMgr* SndSceneMgr::sInstance;

[[address(0x8019C010)]]
void SndSceneMgr::setMiniGameTrack(int track);

[[address(0x8019CDB0)]]
void SndSceneMgr::closeWindow();
