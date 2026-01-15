// d_s_boot.cpp
// NSMBW .text: 0x8015BA70 - 0x8015F270

#include "d_s_boot.h"

#include "d_bases/d_ControllerInformation.h"
#include "d_player/d_WiiStrap.h"
#include "machine/m_fader.h"
#include <egg/core/eggHeap.h>

[[nsmbw_data(0x804296E8)]]
constinit const dBaseCtor_s g_profile_BOOT{};
[[nsmbw(0x8015BA70)]]
fBase_c* dScBoot_c_classInit();

[[nsmbw_data(0x8042A620)]]
dScBoot_c* dScBoot_c::m_instance;

[[nsmbw(0x8015D010)]]
void dScBoot_c::executeState_WiiStrapFadeOut()
{
    if (!mFader_c::isStatus(mFaderBase_c::OPAQUE)) {
        return;
    }

    if (mControllerInformation == nullptr || !mControllerInformation->mReady) {
        return;
    }

    mWiiStrap->mVisible = false;

    return mStateMgr.changeState(StateID_ControllerInformationFadeIn);
}

[[nsmbw(0x8015D850)]]
void dScBoot_c::executeState_ProcEnd();