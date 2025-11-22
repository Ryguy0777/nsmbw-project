// eggController.cpp
// NSMBW .text: 0x802BC9D0 - 0x802BE710

#include "eggController.h"

#include <iterator>
#include <revolution/kpad.h>
#include <revolution/pad.h>
#include <revolution/wpad.h>

namespace EGG
{

// Variables
// ^^^^^^

[[address_data(0x8042B150)]]
CoreControllerMgr* CoreControllerMgr::sInstance;

[[address_data(0x8042B160)]]
bool s_allocatorCreated;

// Functions
// ^^^^^^

namespace
{
u32 getStickButton(const f32& x, const f32& y)
{
    u32 result = 0;

    if (x <= -0.5f) {
        result |= cCORE_FSSTICK_LEFT;
    } else if (x >= 0.5f) {
        result |= cCORE_FSSTICK_RIGHT;
    }

    if (y <= -0.5f) {
        result |= cCORE_FSSTICK_DOWN;
    } else if (y >= 0.5f) {
        result |= cCORE_FSSTICK_UP;
    }

    return result;
}
} // namespace

[[address(0x802BC9E0)]]
u32 CoreStatus::getFSStickButton() const
{
    return getStickButton(getFSStickX(), getFSStickY());
}

[[address(0x802BCA90)]]
CoreController::CoreController();

[[address(0x802BCAF0)]]
void CoreController::sceneReset();

[[address(0x802BCBB0)]]
Vector2f CoreController::getDpdRawPos();

[[address(0x802BCBF0)]]
void Controller::startMotor()
{
    if (getClassicController()) {
        return;
    }

    if (auto* core = getCoreController()) {
        return ::WPADControlMotor(core->mChannel, WPAD_MOTOR_RUMBLE);
    }

    if (auto* gc = getGCController()) {
        return ::PADControlMotor(gc->mChannel, 1);
    }
}

[[address(0x802BCC00)]]
void Controller::stopMotor()
{
    if (getClassicController()) {
        return;
    }

    if (auto* core = getCoreController()) {
        return ::WPADControlMotor(core->mChannel, WPAD_MOTOR_STOP);
    }

    if (auto* gc = getGCController()) {
        return ::PADControlMotor(gc->mChannel, 0);
    }
}

[[address(0x802BCC10)]]
void Controller::createRumbleMgr(u8 overlap_num)
{
    if (getClassicController()) {
        return;
    }

    EGG::ControllerRumbleMgr* mgr = new ControllerRumbleMgr();

    if (auto* core = getCoreController(); core) {
        core->mRumbleMgr = mgr;
    } else if (auto* gc = getGCController(); gc) {
        gc->mRumbleMgr = mgr;
    }

    mgr->createUnit(overlap_num, this);
}

[[address(0x802BCC70)]]
void Controller::startPatternRumble(const char* pattern, int frame, bool force)
{
    if (getClassicController()) {
        return;
    }

    if (auto* core = getCoreController(); core && core->mRumbleMgr) {
        return core->mRumbleMgr->startPattern(pattern, frame, force);
    }

    if (auto* gc = getGCController(); gc && gc->mRumbleMgr) {
        return gc->mRumbleMgr->startPattern(pattern, frame, force);
    }
}

[[address(0x802BCC90)]]
void Controller::startPowerFrameRumble(f32 power, int frame, bool force)
{
    if (getClassicController()) {
        return;
    }

    if (auto* core = getCoreController(); core && core->mRumbleMgr) {
        return core->mRumbleMgr->startPowerFrame(power, frame, force);
    }

    if (auto* gc = getGCController(); gc && gc->mRumbleMgr) {
        return gc->mRumbleMgr->startPowerFrame(power, frame, force);
    }
}

[[address(0x802BCCB0)]]
void Controller::stopRumbleMgr()
{
    if (getClassicController()) {
        return;
    }

    if (auto* core = getCoreController(); core && core->mRumbleMgr) {
        return core->mRumbleMgr->stop();
    }

    if (auto* gc = getGCController(); gc && gc->mRumbleMgr) {
        return gc->mRumbleMgr->stop();
    }
}

[[address(0x802BCCD0)]]
void CoreController::calc_posture_matrix(Matrix34f& posture, bool checkStable);

[[address(0x802BD0D0)]]
void CoreController::beginFrame(PADStatus*)
{
    s32 kpad_result;
    mReadStatusIdx = KPADReadEx(mChannel, mStatus, std::size(mStatus), &kpad_result);
    if (mReadStatusIdx == 0 && kpad_result == -1) {
        mReadStatusIdx = 1;
    }

    u32 dev_type;
    switch (WPADProbe(mChannel, &dev_type)) {
    case WPADResult::WPAD_ERR_OK: {
        if (dev_type == cDEV_NULL) {
            mFlag.resetBit(0);
        } else {
            mFlag.setBit(0);
        }
    } break;

    case WPADResult::WPAD_ERR_NO_CONTROLLER: {
        mFlag.resetBit(0);
    } break;

    default:
    }

    if (mReadStatusIdx > 0) {
        CoreStatus* pStatus = mStatus;
        u32 prev_held = mHeld;
        mHeld = 0;
        if (pStatus->isFreestyle()) {
            mHeld = pStatus->getFSStickButton();
        }

        if (mpClassic) {
            if (pStatus->isClassic()) {
                mpClassic->mFlag.setBit(1);
                mpClassic->beginFrame(nullptr);
            } else {
                mpClassic->mFlag.resetBit(1);
            }
        }

        mTriggered = mHeld & ~prev_held;
        mReleased = prev_held & ~mHeld;
        pStatus->hold &= ~cCORE_FSSTICK_BUTTONS;
        pStatus->trig &= ~cCORE_FSSTICK_BUTTONS;
        pStatus->release &= ~cCORE_FSSTICK_BUTTONS;
        pStatus->hold |= (mHeld & cCORE_FSSTICK_BUTTONS);
        pStatus->trig |= (mTriggered & cCORE_FSSTICK_BUTTONS);
        pStatus->release |= (mReleased & cCORE_FSSTICK_BUTTONS);
    }

    mPostureMatrixPrev.copyFrom(mPostureMatrix);
    mAccelFlags.makeAllZero();
    Vector3f acc = mStatus->getAccel();

    for (int i = 0; i < 3; i++) {
        if (acc(i) - mAccel(i) < mMaxAccelDiff) {
            if (mMaxAccelFrameTime <= ++mAccelFrameTime[i]) {
                mAccelFrameTime[i] = mMaxAccelFrameTime;
                mAccelFlags.set(1 << i);
                mPrevAccel(i) = acc(i);
            }
        } else {
            mAccelFlags.value &= ~(1 << i); // ?
            mAccelFrameTime[i] = 0;
        }
    }

    calc_posture_matrix(mPostureMatrix, true);

    if (mEnableMotor) {
        if (mMotorPattern & (1 << mMotorPatternPos)) {
            startMotor();
        } else {
            stopMotor();
        }

        if (mMotorPatternPos == 0) {
            mMotorPatternPos = mMotorPatternLength - 1;
        } else {
            mMotorPatternPos = mMotorPatternPos - 1;
        }

        if (--mMotorFrameDuration == 0) {
            stopMotor();
            mEnableMotor = false;
        }
    }

    if (mRumbleMgr) {
        mRumbleMgr->calc();
    }
    bool increment = true;

    if (mStatus->getHold() != 0) {
        increment = false;
    }

    if (increment) {
        Vector3f diff = (mAccel - mStatus->getAccel());
        if (diff.squaredLength() > 0.01f) {
            increment = false;
        }
    }
    if (increment) {
        Vector2f diff = (mDpdPos - getDpdRawPos());
        if (diff.squaredLength() > 0.05f) {
            increment = false;
        }
    }

    if (increment) {
        if (mIdleTime < 216000) {
            mIdleTime++;
        }
    } else {
        mIdleTime = 0;
    }
}

[[address(0x802BD660)]]
CoreController* CoreControllerMgr::getNthController(int n);

[[address(0x802BD790)]]
CoreControllerMgr::CoreControllerMgr();

void CoreControllerMgr::initClassic()
{
    for (int i = 0; i < mControllers.mSize; i++) {
        CoreController* core = mControllers(i);
        if (core->mpClassic == nullptr) {
            core->mpClassic = new ClassicController(core);
        }
    }
}

[[address(0x802BDBB0)]]
void CoreControllerMgr::beginFrame();

[[address(0x802BDC60)]]
void CoreControllerMgr::endFrame();

void GCController::beginFrame(PADStatus* status)
{
    mpStatus = status;
    if (status->err < 0) {
        mFlag.resetBit(1);
        return;
    }
    mFlag.setBit(1);

    // Buttons
    u32 prev_down = mDown;
    mDown = status->button;
    mTrig = mDown & ~prev_down;
    mUp = ~mDown & prev_down;

    // Triggers
    // OEM controllers never report a full analog value
    // So we report a full press if the digital input is being pressed
    mLTrigger = mDown & PADButton::PAD_TRIGGER_L ? 1.0f : float(status->triggerL) / 255.0f;
    mRTrigger = mDown & PADButton::PAD_TRIGGER_R ? 1.0f : float(status->triggerR) / 255.0f;

    // Sticks
    mStick.x = float(status->stickX) / 110.0f;
    mStick.y = float(status->stickY) / 110.0f;
    mSubstick.x = float(status->substickX) / 110.0f;
    mSubstick.y = float(status->substickY) / 110.0f;

    if (mRumbleMgr) {
        mRumbleMgr->calc();
    }

    if (mEnableMotor) {
        if (mMotorPattern & (1 << mMotorPatternPos)) {
            startMotor();
        } else {
            stopMotor();
        }

        if (mMotorPatternPos == 0) {
            mMotorPatternPos = mMotorPatternLength - 1;
        } else {
            mMotorPatternPos = mMotorPatternPos - 1;
        }

        if (--mMotorFrameDuration == 0) {
            stopMotor();
            mEnableMotor = false;
        }
    }

    if (mDown) {
        if (mIdleTime < 216000) {
            mIdleTime++;
        }
    } else {
        mIdleTime = 0;
    }
}

void GCController::endFrame()
{
}

EGG_SINGLETON_IMPL(GCControllerMgr);

GCController* GCControllerMgr::getNthController(int n)
{
    return mControllers(n);
}

GCControllerMgr::GCControllerMgr()
{
    mControllers.allocate(4);
    for (int i = 0; i < mControllers.mSize; i++) {
        mControllers(i) = new GCController(i);
    }
}

void GCControllerMgr::beginFrame()
{
    ::PADRead(mPadStatus);

    // OEM controllers have imperfections in their analog values
    // PADClamp is designed to remove these imperfections
    ::PADClamp(mPadStatus);

    for (int i = 0; i < mControllers.mSize; i++) {
        mControllers(i)->beginFrame(&mPadStatus[i]);
    }
}

void GCControllerMgr::endFrame()
{
    u32 mask = 0;

    for (int i = 0; i < mControllers.mSize; i++) {
        mControllers(i)->endFrame();

        if (mControllers(i)->mFlag.off(1)) {
            // Bit mask starting from the left
            mask |= 1 << (31 - (i - 4));
        }
    }

    PADReset(mask);
}

void ClassicController::beginFrame(PADStatus*)
{
    if (mDown) {
        if (mIdleTime < 216000) {
            mIdleTime++;
        }
    } else {
        mIdleTime = 0;
    }
}

void ClassicController::endFrame()
{
}

[[address(0x802BDFF0)]]
ControllerRumbleMgr::ControllerRumbleMgr();

[[address(0x802BE3B0)]]
ControllerRumbleMgr::~ControllerRumbleMgr();

[[address(0x802BE050)]]
void ControllerRumbleMgr::createUnit(u8 overlap_num, Controller* pController);

[[address(0x802BE0E0)]]
void ControllerRumbleMgr::stop();

[[address(0x802BE150)]]
void ControllerRumbleMgr::calc();

[[address(0x802BE260)]]
void ControllerRumbleMgr::startPattern(const char* pPattern, int frame, bool force);

[[address(0x802BE2B0)]]
void ControllerRumbleMgr::startPowerFrame(f32 power, int frame, bool force);

} // namespace EGG
