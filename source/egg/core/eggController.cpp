// eggController.cpp
// NSMBW: 0x802BC9D0 - 0x802BE710

#include "eggController.h"

#include <revolution/kpad.h>
#include <revolution/wpad.h>

namespace EGG
{

// ----
// Data
// ----

[[address_data(0x8042B150)]]
CoreControllerMgr* CoreControllerMgr::sInstance;

[[address_data(0x8042B154)]]
CoreControllerMgr::T__Disposer* CoreControllerMgr::T__Disposer::sStaticDisposer;

// ---------
// Functions
// ---------

[[address(0x802BC9E0)]]
u32 EGG::CoreStatus::getFSStickButton() const;

[[address(0x802BCA90)]]
CoreController::CoreController();

[[address(0x802BCAF0)]]
void CoreController::sceneReset();

[[address(0x802BCBB0)]]
Vector2f CoreController::getDpdRawPos();

[[address(0x802BCBF0)]]
void CoreController::startMotor();

[[address(0x802BCC00)]]
void CoreController::stopMotor();

[[address(0x802BCC10)]]
void CoreController::createRumbleMgr(u8 numUnits);

[[address(0x802BCC70)]]
void CoreController::startPatternRumble(const char* pattern, int duration, bool bGrabActive);

[[address(0x802BCC90)]]
void CoreController::startPowerFrameRumble(float param1, int duration, bool bGrabActive);

[[address(0x802BCCB0)]]
void CoreController::stopRumbleMgr();

[[address(0x802BCCD0)]]
void CoreController::calc_posture_matrix(Matrix34f& posture, bool checkStable);

[[address(0x802BD0D0)]]
void CoreController::beginFrame(PADStatus* padStatus)
{
    s32 kpad_result;
    mReadStatusIdx = KPADReadEx(mChannel, maStatus, 0x10, &kpad_result);
    if (mReadStatusIdx == 0 && kpad_result == -1 /* Rvl usually uses negative nums for results */) {
        mReadStatusIdx = 1;
    }

    WPADDeviceType dev_type;
    switch (WPADProbe(mChannel, &dev_type)) {
    case WPADResult::WPAD_ERR_OK: {
        if (dev_type == WPADDeviceType::WPAD_DEV_NONE) {
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
        CoreStatus* pStatus = maStatus;
        u32 prev_held = mHeld;
        if (pStatus->isFreestyle()) {
            mHeld = pStatus->getFSStickButton();
        } else {
            mHeld = 0;
        }

        mTriggered = mHeld & ~prev_held;
        mReleased = prev_held & ~mHeld;
        pStatus->hold &= ~0xF0000;
        pStatus->trigger &= ~0xF0000;
        pStatus->release &= ~0xF0000;
        pStatus->hold |= (mHeld & 0xF0000);
        pStatus->trigger |= (mTriggered & 0xF0000);
        pStatus->release |= (mReleased & 0xF0000);
    }

    mPostureMatrixPrev.copyFrom(mPostureMatrix);
    mAccelFlags.makeAllZero();
    Vector3f acc = maStatus->getAccel();

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

    if (maStatus->getHold() != 0) {
        increment = false;
    }

    if (increment) {
        Vector3f diff = (mAccel - maStatus->getAccel());
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
        // I dont know what this is for...
        //   if no interaction, this increments? (30fps -> 2hrs)
        if (mIdleTime < 216000) {
            mIdleTime++;
        }
    } else {
        mIdleTime = 0;
    }
}

[[address(0x802BD790)]]
CoreControllerMgr::CoreControllerMgr();

void CoreControllerMgr::recreateInstance()
{
    if (sInstance != nullptr) {
        delete sInstance;
    }

    sInstance = new CoreControllerMgr();
    T__Disposer::sStaticDisposer = &sInstance->mDisposer;

    // Add new controllers

    // Moving this object's storage, it will be destroyed once this function returns
    EGG::TBuffer<CoreController*> controllers = sInstance->mControllers.move();
    EGG::TBuffer<eCoreDevType> devTypes = sInstance->mDevTypes.move();

    sInstance->mControllers.allocate(CORE_COUNT, 0);
    sInstance->mDevTypes.allocate(CORE_COUNT, 0);

    for (int i = 0; i < CORE_COUNT; i++) {
        if (i < 4) {
            sInstance->mControllers(i) = controllers(i);
            sInstance->mDevTypes(i) = devTypes(i);
        }

        sInstance->mControllers(i) = new CoreController();
        sInstance->mControllers(i)->mChannel = static_cast<WPADChannel>(i);
        sInstance->mDevTypes(i) = eCoreDevType::NONE;
    }
}

[[address(0x802BE150)]]
void ControllerRumbleMgr::calc();

} // namespace EGG