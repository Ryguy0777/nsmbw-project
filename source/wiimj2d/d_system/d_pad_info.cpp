// d_pad_info.cpp
// NSMBW: ---

// Struct for getting processed GameCube controller data at any time.

#include "d_pad_info.h"
#include <egg/core/eggController.h>

static dPADInfo saPadInfo[4];

void dPADInfo::convertPADStatus(PADStatus* status)
{
    for (int i = 0; i < 4; i++) {
        // Get raw inputs
        PADStatus padStatus = status[i];
        dPADInfo* padInfo = &saPadInfo[i];

        // Assign button data from previous frame
        padInfo->mPrevHold = padInfo->mHold;
        padInfo->mPrevTrig = padInfo->mTrig;
        padInfo->mPrevRelease = padInfo->mRelease;

        // Buttons
        padInfo->mHold = padStatus.button;

        padInfo->mTrig = padInfo->mHold & ~padInfo->mPrevHold;
        padInfo->mRelease = padInfo->mPrevHold & padInfo->mHold;

        // Triggers
        // OEM controllers never report a full analog value
        // So we report a full press if the digital input is being pressed
        padInfo->mLTrigger =
          padInfo->mHold & PADButton::PAD_TRIGGER_L ? 1.0f : padStatus.triggerL / 255;
        padInfo->mRTrigger =
          padInfo->mHold & PADButton::PAD_TRIGGER_R ? 1.0f : padStatus.triggerR / 255;

        // Sticks
        padInfo->mStick.x = padStatus.stickX / 110;
        padInfo->mStick.y = padStatus.stickY / 110;
        padInfo->mSubstick.x = padStatus.substickX / 110;
        padInfo->mSubstick.y = padStatus.substickY / 110;
    }
}

dPADInfo* dPADInfo::getPADInfo(WPADChannel chan)
{
    if (chan >= EGG::GC_CHANNEL_BEGIN && chan < EGG::GC_CHANNEL_END) {
        return &saPadInfo[static_cast<int>(chan) - static_cast<int>(EGG::GC_CHANNEL_BEGIN)];
    }

    return nullptr;
}