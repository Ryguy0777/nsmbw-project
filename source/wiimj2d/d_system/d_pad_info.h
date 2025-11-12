#pragma once

#include <machine/m_vec.h>
#include <revolution/pad.h>
#include <revolution/wpad.h>

struct dPADInfo {
    static void convertPADStatus(PADStatus* status);

    static dPADInfo* getPADInfo(WPADChannel channel);

    u32 mHold, mPrevHold;
    u32 mTrig, mPrevTrig;
    u32 mRelease, mPrevRelease;
    mVec2_c mStick;
    mVec2_c mSubstick;
    float mLTrigger, mRTrigger;
};