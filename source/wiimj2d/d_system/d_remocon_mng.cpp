// d_remocon_mng.cpp
// NSMBW .text: 0x800DBFD0 - 0x800DDA40

#include "d_remocon_mng.h"

#include "machine/m_pad.h"
#include <cassert>
#include <egg/core/eggController.h>
#include <revolution/os.h>
#include <revolution/wpad.h>

[[address_data(0x80428280)]]
bool dRemoconMng_c::dConnect_c::m_isBoot;

[[address_data(0x8042A308)]]
dRemoconMng_c* dRemoconMng_c::m_instance;

[[address(0x800DC000)]]
void ClearDeviceCallback(s32);

[[address(0x800DC040)]]
dRemoconMng_c::dRemoconMng_c();

dRemoconMng_c::dRemoconMng_c(dRemoconMng_c* old)
{
    for (std::size_t connect = 0; connect < 4; connect++) {
        mpConnect[connect] = old->mpConnect[connect];
    }
    for (std::size_t connect = 4; connect < CONNECT_COUNT; connect++) {
        mpConnect[connect] = new dConnect_c(static_cast<mPad::CH_e>(connect));
    }

    operator delete(old);
}

[[address(0x800DC0D0)]]
dRemoconMng_c::~dRemoconMng_c()
{
    for (std::size_t connect = 0; connect < CONNECT_COUNT; connect++) {
        dConnect_c* pConnect = mpConnect[connect];
        mpConnect[connect] = nullptr;
        delete pConnect;
    }
}

[[address(0x800DC180)]]
dRemoconMng_c::dConnect_c::~dConnect_c()
{
#ifndef __has_macintosh_dt_fix
    mExtension.~dExtension_c();
#endif // !__has_macintosh_dt_fix
}

[[address(0x800DC360)]]
dRemoconMng_c::dConnect_c::dExtension_c::~dExtension_c()
{
}

[[address(0x800DC570)]]
void dRemoconMng_c::execute()
{
    for (int i = 0; i < CONNECT_COUNT; i++) {
        m_instance->mpConnect[i]->execute();
    }

    bool allowConnect = false;

    // Only the first 4 matter because the rest are GameCube controllers
    for (int i = 0; i < 4; i++) {
        dConnect_c* connect = m_instance->mpConnect[i];

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
dRemoconMng_c::dConnect_c::dConnect_c(mPad::CH_e channel)
  : mChannel(channel)
  , mExtension(channel)
  , mBattery(-1)
  , mAllowConnect(true)
  , mEnableMotor(false)
  , mStateMgr(*this, StateID_Shutdown)
{
    mPad::g_core[channel]->createRumbleMgr(8);
}

[[address(0x800DC7E0)]]
void dRemoconMng_c::dConnect_c::executeState_Shutdown()
{
    EGG::Controller* controller = mPad::g_core[mChannel];
    if (EGG::CoreController* core = controller->getCoreController()) {
        if (!core->connected()) {
            return;
        }
        if (mChannel >= mPad::CH_e::CHAN_0 && mChannel <= mPad::CH_e::CHAN_LAST) {
            if (core->mStatus->getDevType() != mPad::g_padMg->mDevTypes(mChannel)) {
                return;
            }
            if (!mAllowConnect) {
                WPADDisconnect(static_cast<WPADChannel>(mChannel));
                return;
            }
        } else if (!mAllowConnect) {
            return;
        }
    } else if (EGG::GCController* dolphin = controller->getGCController()) {
        if (!dolphin->connected()) {
            return;
        }
        if (!mAllowConnect) {
            // No WPADDisconnect for GameCube controllers
            return;
        }
    } else {
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

    if (mChannel < mPad::CH_e::CHAN_0 || mChannel > mPad::CH_e::CHAN_LAST) {
        return;
    }

    // Some Wii Remote speaker thing
    void UNDEF_802d6d50(mPad::CH_e channel, int param2);
    UNDEF_802d6d50(mChannel, 0);

    // The rumble when you connect a Wii Remote. I don't want this to play for GameCube
    // controllers preferably.
    if (!m_isBoot) {
        mPad::g_core[mChannel]->startPowerFrameRumble(1.0f, 10, false);
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
    EGG::Controller* controller = mPad::g_core[mChannel];
    if (EGG::CoreController* core = controller->getCoreController()) {
        if (!core->connected()) {
            return mStateMgr.changeState(StateID_Shutdown);
        }
        if (!mAllowConnect && mChannel >= mPad::CH_e::CHAN_0 && mChannel <= mPad::CH_e::CHAN_LAST) {
            WPADDisconnect(static_cast<WPADChannel>(mChannel));
            return mStateMgr.changeState(StateID_Shutdown);
        }
    } else if (EGG::GCController* gc = controller->getGCController()) {
        if (!gc->connected()) {
            return mStateMgr.changeState(StateID_Shutdown);
        }
    }

    mExtension.execute();

    mBattery = mPad::getBatteryLevel_ch(mChannel);
}

[[address(0x800DCA60)]]
void dRemoconMng_c::dConnect_c::execute();

[[address(0x800DCA80)]]
void dRemoconMng_c::dConnect_c::onRumbleEnable();

template <dRemoconMng_c::dConnect_c::dExtension_c::Type_e Current>
inline void dRemoconMng_c::dConnect_c::dExtension_c::checkState()
{
    EGG::CoreController* core = mPad::g_core[mChannel]->getCoreController();
    if (!core) {
        return;
    }

    if (mPad::g_padMg->mDevTypes(core->mChannel) != core->mStatus->getDevType()) {
        return;
    }

    switch (core->mStatus->getDevType()) {
    case EGG::cDEV_CORE:
        if constexpr (Current != Type_e::NONE) {
            mStateMgr.changeState(StateID_None);
        }
        break;
    case EGG::cDEV_FREESTYLE:
        if constexpr (Current != Type_e::FREESTYLE) {
            mStateMgr.changeState(StateID_Freestyle);
        }
        break;
    case EGG::cDEV_CLASSIC:
        if constexpr (Current != Type_e::CLASSIC) {
            mStateMgr.changeState(StateID_Classic);
        }
        break;

    case EGG::cDEV_FUTURE:
    case EGG::cDEV_NOT_SUPPORTED:
        if constexpr (Current != Type_e::OTHER) {
            mStateMgr.changeState(StateID_Other);
        }
        break;

    default:
        break;
    }
}

[[address(0x800DCAF0)]]
void dRemoconMng_c::dConnect_c::dExtension_c::initializeState_Wait()
{
    mType = Type_e::WAIT;
}

// Empty
[[address(0x800DCB00)]]
void dRemoconMng_c::dConnect_c::dExtension_c::finalizeState_Wait();

[[address(0x800DCB10)]]
void dRemoconMng_c::dConnect_c::dExtension_c::executeState_Wait()
{
    checkState<Type_e::WAIT>();
}

[[address(0x800DCC40)]]
void dRemoconMng_c::dConnect_c::dExtension_c::initializeState_None()
{
    mType = Type_e::NONE;
}

// Empty
[[address(0x800DCC50)]]
void dRemoconMng_c::dConnect_c::dExtension_c::finalizeState_None();

[[address(0x800DCC60)]]
void dRemoconMng_c::dConnect_c::dExtension_c::executeState_None()
{
    checkState<Type_e::NONE>();
}

[[address(0x800DCD70)]]
void dRemoconMng_c::dConnect_c::dExtension_c::initializeState_Freestyle()
{
    mType = Type_e::FREESTYLE;
}

// Empty
[[address(0x800DCC80)]]
void dRemoconMng_c::dConnect_c::dExtension_c::finalizeState_Freestyle();

[[address(0x800DCCA0)]]
void dRemoconMng_c::dConnect_c::dExtension_c::executeState_Freestyle()
{
    checkState<Type_e::FREESTYLE>();
}

[[address(0x800DCEA0)]]
void dRemoconMng_c::dConnect_c::dExtension_c::initializeState_Other()
{
    mType = Type_e::OTHER;
}

// Empty
[[address(0x800DCEB0)]]
void dRemoconMng_c::dConnect_c::dExtension_c::finalizeState_Other();

[[address(0x800DCEC0)]]
void dRemoconMng_c::dConnect_c::dExtension_c::executeState_Other()
{
    checkState<Type_e::OTHER>();
}

void dRemoconMng_c::dConnect_c::dExtension_c::initializeState_Classic()
{
    mType = Type_e::CLASSIC;
}

void dRemoconMng_c::dConnect_c::dExtension_c::finalizeState_Classic()
{
}

void dRemoconMng_c::dConnect_c::dExtension_c::executeState_Classic()
{
    checkState<Type_e::CLASSIC>();
}

void dRemoconMng_c::dConnect_c::dExtension_c::initializeState_Dolphin()
{
    mType = Type_e::DOLPHIN;
}

void dRemoconMng_c::dConnect_c::dExtension_c::finalizeState_Dolphin()
{
}

void dRemoconMng_c::dConnect_c::dExtension_c::executeState_Dolphin()
{
}

[[address(0x800DCFD0)]]
void dRemoconMng_c::dConnect_c::dExtension_c::shutdown();

[[address(0x800DCFF0)]]
void dRemoconMng_c::dConnect_c::dExtension_c::execute();
