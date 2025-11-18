// eggController.cpp
// NSMBW .text: 0x802BC9D0 - 0x802BE710

#include "eggController.h"

#include <d_system/d_pad_info.h>
#include <revolution/kpad.h>
#include <revolution/pad.h>
#include <revolution/wpad.h>


namespace EGG
{

// Data
// ^^^^^^

[[address_data(0x8042B150)]]
CoreControllerMgr* CoreControllerMgr::sInstance;

[[address_data(0x8042B154)]]
CoreControllerMgr::T__Disposer* CoreControllerMgr::T__Disposer::sStaticDisposer;

static PADStatus saPadStatus[4];

[[address_data(0x8042B160)]]
bool s_allocatorCreated;

// Functions
// ^^^^^^

[[address(0x802BC9E0)]]
u32 EGG::CoreStatus::getFSStickButton() const;

[[address(0x802BCA90)]]
CoreController::CoreController();

[[address(0x802BCAF0)]]
void CoreController::sceneReset();

[[address(0x802BCBB0)]]
Vector2f CoreController::getDpdRawPos();

[[address(0x802BCBF0)]]
void CoreController::startMotor()
{
    if (mChannel >= GC_CHANNEL_BEGIN && mChannel < GC_CHANNEL_END) {
        PADControlMotor(static_cast<int>(mChannel) - static_cast<int>(GC_CHANNEL_BEGIN), 1);
    } else {
        WPADControlMotor(mChannel, WPADMotorCommand::WPAD_MOTOR_RUMBLE);
    }
}

[[address(0x802BCC00)]]
void CoreController::stopMotor()
{
    if (mChannel >= GC_CHANNEL_BEGIN && mChannel < GC_CHANNEL_END) {
        PADControlMotor(static_cast<int>(mChannel) - static_cast<int>(GC_CHANNEL_BEGIN), 0);
    } else {
        WPADControlMotor(mChannel, WPADMotorCommand::WPAD_MOTOR_STOP);
    }
}

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

void CoreController::padToCoreStatus(PADStatus* restrict padStatus)
{
    u32 lastButton = maStatus->getHold();
    u32 button = padStatus->button;

    maStatus->init();

    // Convert to sideways Wii Remote buttons
    if (button & PADButton::PAD_BUTTON_LEFT) {
        maStatus->hold |= WPADButton::WPAD_BUTTON_UP;
    }
    if (button & PADButton::PAD_BUTTON_RIGHT) {
        maStatus->hold |= WPADButton::WPAD_BUTTON_DOWN;
    }
    if (button & PADButton::PAD_BUTTON_DOWN) {
        maStatus->hold |= WPADButton::WPAD_BUTTON_LEFT;
    }
    if (button & PADButton::PAD_BUTTON_UP) {
        maStatus->hold |= WPADButton::WPAD_BUTTON_RIGHT;
    }

    if (button & PADButton::PAD_BUTTON_A) {
        maStatus->hold |= WPADButton::WPAD_BUTTON_2;
    }
    if (button & PADButton::PAD_BUTTON_B) {
        maStatus->hold |= WPADButton::WPAD_BUTTON_1;
    }
    if (button & PADButton::PAD_TRIGGER_Z) {
        maStatus->hold |= WPADButton::WPAD_BUTTON_MINUS;
    }
    if (button & PADButton::PAD_BUTTON_START) {
        maStatus->hold |= WPADButton::WPAD_BUTTON_PLUS;
    }

    // Map stick to D-pad
    if (padStatus->stickX < -54 && !(maStatus->hold & WPADButton::WPAD_BUTTON_DOWN)) {
        maStatus->hold |= WPADButton::WPAD_BUTTON_UP;
    }
    if (padStatus->stickX > 54 && !(maStatus->hold & WPADButton::WPAD_BUTTON_UP)) {
        maStatus->hold |= WPADButton::WPAD_BUTTON_DOWN;
    }
    if (padStatus->stickY < -54 && !(maStatus->hold & WPADButton::WPAD_BUTTON_RIGHT)) {
        maStatus->hold |= WPADButton::WPAD_BUTTON_LEFT;
    }
    if (padStatus->stickY > 54 && !(maStatus->hold & WPADButton::WPAD_BUTTON_LEFT)) {
        maStatus->hold |= WPADButton::WPAD_BUTTON_RIGHT;
    }

    maStatus->trig = maStatus->hold & ~lastButton;
    maStatus->release = lastButton & ~maStatus->hold;
    maStatus->wpad_err = 0;
    maStatus->dev_type = static_cast<WPADDeviceType>(eCoreDevType::GCN);

    // For in-game but not for use in menus
    if (button & PADButton::PAD_BUTTON_Y) {
        maStatus->hold |= WPADButton::WPAD_BUTTON_1;
    }
    if (button & PADButton::PAD_BUTTON_X) {
        maStatus->hold |= WPADButton::WPAD_BUTTON_A;
    }

    // Map tilt to triggers
    float analogA = button & PADButton::PAD_TRIGGER_L ? 255 : padStatus->triggerL;
    float analogB = button & PADButton::PAD_TRIGGER_R ? 255 : padStatus->triggerR;

    float tilt = analogA / 255;
    tilt -= analogB / 255;

    maStatus->acc.z = tilt;
    maStatus->acc_vertical.y = -tilt;
}

[[address(0x802BD0D0)]]
void CoreController::beginFrame(PADStatus* padStatus)
{
    // Is padStatus meant to be an input? that's how we're using it here anyway
    if (padStatus) {
        mReadStatusIdx = padStatus->err >= 0 ? 1 : 0;

        if (mReadStatusIdx > 0) {
            padToCoreStatus(padStatus);
            mFlag.setBit(0);
        } else {
            mFlag.resetBit(0);
        }
    } else {
        s32 kpad_result;
        mReadStatusIdx = KPADReadEx(mChannel, maStatus, 0x10, &kpad_result);
        if (mReadStatusIdx == 0 &&
            kpad_result == -1 /* Rvl usually uses negative nums for results */) {
            mReadStatusIdx = 1;
        }

        u32 dev_type;
        switch (WPADProbe(mChannel, &dev_type)) {
        case WPADResult::WPAD_ERR_OK: {
            if (static_cast<WPADDeviceType>(dev_type) == WPADDeviceType::WPAD_DEV_NONE) {
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
        pStatus->trig &= ~0xF0000;
        pStatus->release &= ~0xF0000;
        pStatus->hold |= (mHeld & 0xF0000);
        pStatus->trig |= (mTriggered & 0xF0000);
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

[[address(0x802BDBB0)]]
void CoreControllerMgr::beginFrame()
{
    PADRead(saPadStatus);

    // OEM controllers have imperfections in their analog values
    // PADClamp is designed to remove these imperfections
    PADClamp(saPadStatus);

    // generate PADInfo structs out of PADStatus
    dPADInfo::convertPADStatus(saPadStatus);

    for (int i = 0; i < mControllers.getSize(); ++i) {
        WPADChannel chan = static_cast<WPADChannel>(i);

        PADStatus* padStatus = nullptr;
        if (chan >= GC_CHANNEL_BEGIN && chan < GC_CHANNEL_END) {
            padStatus = &saPadStatus[i - static_cast<int>(GC_CHANNEL_BEGIN)];
        }

        mControllers(i)->beginFrame(padStatus);
    }
}

[[address(0x802BDC60)]]
void CoreControllerMgr::endFrame()
{
    u32 gcResetMask = 0;

    for (int i = 0; i < mControllers.mSize; i++) {
        WPADChannel chan = static_cast<WPADChannel>(i);

        mControllers(i)->endFrame();

        if (chan >= GC_CHANNEL_BEGIN && chan < GC_CHANNEL_END) {
            eCoreDevType devType = eCoreDevType::GCN;

            if (mControllers(i)->mFlag.off(1)) {
                // Bit mask starting from the left
                gcResetMask |= 1 << (31 - (i - 4));
                devType = eCoreDevType::NONE;
            }

            mDevTypes(i) = devType;
            continue;
        }

        u32 devType;
        WPADResult result = WPADProbe(chan, &devType);

        WPADDeviceType resDevType;
        if (result == WPADResult::WPAD_ERR_OK) {
            resDevType = static_cast<WPADDeviceType>(devType);
        } else if (result == WPADResult::WPAD_ERR_NO_CONTROLLER) {
            resDevType = WPADDeviceType::WPAD_DEV_NONE;
        } else {
            continue;
        }

        mDevTypes(i) = static_cast<eCoreDevType>(resDevType);
    }

    PADReset(gcResetMask);
}

void CoreControllerMgr::recreateInstance()
{
    PADInit();

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

PADStatus* CoreControllerMgr::getPadStatus(WPADChannel chan)
{
    if (chan >= GC_CHANNEL_BEGIN && chan < GC_CHANNEL_END) {
        return &saPadStatus[static_cast<int>(chan) - static_cast<int>(GC_CHANNEL_BEGIN)];
    }

    return nullptr;
}

[[address(0x802BE150)]]
void ControllerRumbleMgr::calc();

} // namespace EGG
