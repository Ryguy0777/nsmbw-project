// d_remocon_mng.cpp
// NSMBW .text: 0x800DBFD0 - 0x800DDA40

#include "d_remocon_mng.h"

#include "machine/m_heap.h"
#include "machine/m_pad.h"
#include <egg/core/eggController.h>
#include <revolution/os.h>
#include <revolution/wpad.h>

[[address_data(0x80428280)]]
bool dRemoconMng_c::dConnect_c::m_isBoot;

[[address_data(0x8042A308)]]
dRemoconMng_c* dRemoconMng_c::m_instance;

namespace
{
[[address(0x800DC000)]]
void ClearDeviceCallback(s32);
}

[[address(0x800DC040)]]
dRemoconMng_c::dRemoconMng_c();

dRemoconMng_c::dRemoconMng_c(dRemoconMng_c* old)
{
    for (std::size_t connect = 0; connect < 4; connect++) {
        mpaConnect[connect] = old->mpaConnect[connect];
    }
    for (std::size_t connect = 4; connect < CONNECT_COUNT; connect++) {
        mpaConnect[connect] = new dConnect_c(static_cast<mPad::CH_e>(connect));
    }

    operator delete(old);
}

[[address(0x800DC0D0)]]
dRemoconMng_c::~dRemoconMng_c()
{
    for (std::size_t connect; connect < CONNECT_COUNT; connect++) {
        dConnect_c* pConnect = mpaConnect[connect];
        mpaConnect[connect] = nullptr;
        delete pConnect;
    }
}

[[address(0x800DC570)]]
void dRemoconMng_c::execute()
{
    for (int i = 0; i < CONNECT_COUNT; i++) {
        m_instance->mpaConnect[i]->execute();
    }

    bool allowConnect = false;

    // Only the first 4 matter because the rest are GameCube controllers
    for (int i = 0; i < 4; i++) {
        dConnect_c* connect = m_instance->mpaConnect[i];

        if (!connect->mAllowConnect) {
            continue;
        }

        if (!connect->mStateMgr.getStateID()->isEqual(connect->StateID_Setup)) {
            allowConnect = true;
            break;
        }
    }

    WPADSetAcceptConnection(allowConnect);
}

[[address(0x800DC660)]]
dRemoconMng_c::dConnect_c::dConnect_c(mPad::CH_e channel);

[[address(0x800DC7E0)]]
void dRemoconMng_c::dConnect_c::executeState_Shutdown()
{
    std::size_t chanIndex = static_cast<std::size_t>(mChannel);

    WPADDeviceType devType = mPad::g_core[chanIndex]->maStatus->dev_type;

    if (static_cast<EGG::eCoreDevType>(devType) != mPad::g_padMg->mDevTypes(chanIndex)) {
        return;
    }

    if (mPad::g_core[static_cast<int>(mChannel)]->mFlag.off(1)) {
        return;
    }

    if (!mAllowConnect && (mChannel < mPad::CH_e::CHAN_GC_0 || mChannel > mPad::CH_e::CHAN_GC_3)) {
        WPADDisconnect(static_cast<WPADChannel>(mChannel));
        return;
    }

    if (m0x58 == 0) {
        m0x58 = 1;
        return;
    }

    mStateMgr.changeState(StateID_Setup);
}

[[address(0x800DC910)]]
void dRemoconMng_c::dConnect_c::initializeState_Setup()
{
    // Call to dRemoconMng_c::dConnect_c::dExtension_c::setup removed because it's just a blr

    OS_REPORT("SETUP CONTROLLER %d\n", static_cast<int>(mChannel));

    mBattery = mPad::getBatteryLevel_ch(mChannel);

    if (mChannel < mPad::CH_e::CHAN_GC_0) {
        // Some Wii Remote speaker thing
        void UNDEF_802d6d50(mPad::CH_e channel, int param2);
        UNDEF_802d6d50(mChannel, 0);

        // The rumble when you connect a Wii Remote. I don't want this to play for GameCube
        // controllers preferably.
        if (!m_isBoot) {
            mPad::g_core[static_cast<int>(mChannel)]->startPowerFrameRumble(1.0, 10, false);
        }
    }
}

[[address(0x800DC990)]]
void dRemoconMng_c::dConnect_c::finalizeState_Setup()
{
    mExtension.shutdown();

    if (mChannel < mPad::CH_e::CHAN_GC_0) {
        // Some Wii Remote speaker thing
        void UNDEF_802d6db0(mPad::CH_e channel, int param2);
        UNDEF_802d6db0(mChannel, 0);
    }
}

[[address(0x800DC9D0)]]
void dRemoconMng_c::dConnect_c::executeState_Setup()
{
    if (mPad::g_core[static_cast<std::size_t>(mChannel)]->mFlag.off(1)) {
        mStateMgr.changeState(dRemoconMng_c::dConnect_c::StateID_Shutdown);
        return;
    }

    if (!mAllowConnect && (mChannel < mPad::CH_e::CHAN_GC_0 || mChannel > mPad::CH_e::CHAN_GC_3)) {
        WPADDisconnect(static_cast<WPADChannel>(mChannel));
    }

    mExtension.execute();

    mBattery = mPad::getBatteryLevel_ch(mChannel);
}

[[address(0x800DCA60)]]
void dRemoconMng_c::dConnect_c::execute();

[[address(0x800DCA80)]]
void dRemoconMng_c::dConnect_c::onRumbleEnable();

[[address(0x800DCFD0)]]
void dRemoconMng_c::dConnect_c::dExtension_c::shutdown();

[[address(0x800DCFF0)]]
void dRemoconMng_c::dConnect_c::dExtension_c::execute();
