// d_game_key_core.cpp
// NSMBW .text: 0x800B5B50 - 0x800B64A0

#include "d_game_key_core.h"

#include "d_bases/d_s_stage.h"
#include "d_player/d_a_player.h"
#include "d_system/d_a_player_manager.h"
#include "d_system/d_remocon_mng.h"
#include "framework/f_feature.h"
#include <cmath>
#include <egg/core/eggController.h>
#include <revolution/pad.h>
#include "d_system/d_pad_info.h"
#include "machine/m_vec.h"
#include "revolution/os/OSError.h"

[[address(0x800B5B50)]]
dGameKeyCore_c::dGameKeyCore_c(mPad::CH_e channel);

[[address(0x800B5BE0)]]
void dGameKeyCore_c::allclear();

[[address(0x800B5CB0)]]
void dGameKeyCore_c::read()
{
    mPrevRawHeld = mRawHeld;
    mPrevHeld = mHeld;
    mAccelOld = mAccel;
    mAccelVerticalXOld = mAccelVerticalX;
    mAccelVerticalYOld = mAccelVerticalY;
    mAngleOld = mAngle;
    mMoveDistanceOld = mMoveDistance;

    EGG::CoreController *coreCont = getCoreController();

    dReplayPlay_c *replayData = dScStage_c::m_replayPlay_p[static_cast<int>(mChannel)];
    if (replayData == nullptr) {
        // Replay is not active for this channel

        // Assign controller type
        PADStatus* padStatus = EGG::CoreControllerMgr::getPadStatus(static_cast<WPADChannel>(mChannel));
        if (padStatus != nullptr) {
            // GameCube controller
            mType = Type_e::DOLPHIN;
        } else {
            using Extension_e = dRemoconMng_c::dConnect_c::dExtension_c::Type_e;
            Extension_e devType = dRemoconMng_c::m_instance->mpaConnect[static_cast<int>(mChannel)]->getExtension()->getType();
            if (devType == Extension_e::NONE) {
                // Sideways Wii Remote
                mType = Type_e::CORE;
            } else if (devType == Extension_e::FREESTYLE) {
                // Wii Remote + Nunchuck
                mType = Type_e::FREESTYLE;
            } else if (devType == Extension_e::CLASSIC) {
                // Wii Remote + Classic controller
                mType = Type_e::CLASSIC;
            }
        }

        // Set raw button input from EGG::CoreController
        mRawHeld = coreCont->maStatus->hold & 0x7fffffff;

        // Accelerometer data from EGG::CoreController
        mAccel.x = coreCont->mAccel.x;
        mAccel.y = coreCont->mAccel.y;
        mAccel.z = coreCont->mAccel.z;

        mAccelVerticalX.x = coreCont->maStatus->acc_vertical.x;
        mAccelVerticalX.y = coreCont->maStatus->acc_vertical.y;

        mAccelVerticalY.x = mPad::g_PadAdditionalData[static_cast<int>(mChannel)][2];
        mAccelVerticalY.y = mPad::g_PadAdditionalData[static_cast<int>(mChannel)][3];

        mAccelVerticalZ.x = mPad::g_PadAdditionalData[static_cast<int>(mChannel)][4];
        mAccelVerticalZ.y = mPad::g_PadAdditionalData[static_cast<int>(mChannel)][5];
    } else {
        // Replay is active, assign data from current replay
        mType = Type_e::CORE;
        if (replayData->mFrameFlags & 0x10000000) {
            mPrevRawHeld = replayData->mPrevFrameInput;
        }
        mRawHeld = replayData->mFrameInput;
        mAccel = replayData->mFrameAccel;
        mAccelVerticalX = replayData->mFrameAccelVertX;
        mAccelVerticalY = replayData->mFrameAccelVertY;
        mAccelVerticalZ = replayData->mFrameAccelVertZ;
    }

    // Pointer
    mAngle.x = coreCont->maStatus->horizon.x;
    mAngle.y = coreCont->maStatus->horizon.y;

    // "Process" inputs for Nunchuck mode
    mPrevHeld = setConfigKey(mPrevRawHeld);
    mHeld = setConfigKey(mRawHeld);
    mTriggered = mHeld & (mHeld ^ mPrevHeld);

    // Flip accelerometer data for Nunchuck mode
    // TODO: Seems to be broken
    if (mType == Type_e::FREESTYLE) {
        mAccel.x = mAccel.z;
        mAccel.z = mAccel.x;
    }

    // Not sure what this does
    int uVar10 = 0;
    for (int i = 0; i < 2; i++) {
        int uVar14 = 1 << (uVar10 & 0x3f);
        if (!(mTriggered & uVar14)) {
            if (mHeld & uVar14) {
                if (m0x24 == 0) {
                    m0x20 |= uVar14;
                    m0x24 = m0x2C;
                } else {
                    m0x24--;
                }
            }
        } else {
            m0x20 |= uVar14;
            m0x24 = m0x28;
        }
        uVar14 = 1 << (uVar10 + 1 & 0x3f);
        if (!(mTriggered & uVar14)) {
            if (mHeld & uVar14) {
                if (m0x24 == 0) {
                    m0x20 |= uVar14;
                    m0x24 = m0x2C;
                } else {
                    m0x24--;
                }
            }
        } else {
            m0x20 |= uVar14;
            m0x24 = m0x28;
        }
        uVar10 += 2;
    }
    handleTilting();
    mMoveDistance = EGG::Math<float>::sqrt(static_cast<float>(mAccel.z * mAccel.z + mAccel.x * mAccel.x + mAccel.y * mAccel.y));
    if (mMoveDistance < 1.2) {
        mMoveDistance = 1.0;
    }
    setShakeY();
    if (m0x30) {
        m0x30 = 0;
        mTriggered |= m0x30;
    }
    if (mShakeOld) {
        mShake = mShakeOld;
        mShakeOld = 0;
    }
}

[[address(0x800B60D0)]]
u32 dGameKeyCore_c::setConfigKey(u32 button);

[[address(0x800B61F0)]]
void dGameKeyCore_c::handleTilting();

[[address(0x800B62A0)]]
void dGameKeyCore_c::setShakeY()
{
    if (dScStage_c::m_replayPlay_p[static_cast<int>(mChannel)] != nullptr) {
        mShake = dScStage_c::m_replayPlay_p[static_cast<int>(mChannel)]->mFrameFlags & (1 << 29);
        return;
    }

    dPADInfo* padInfo = dPADInfo::getPADInfo(static_cast<WPADChannel>(mChannel));
    if (padInfo != nullptr) {
        // GameCube controller

        if (mShakeTimer3 != 0) {
            mShakeTimer3--;
            mShake = false;
            return;
        }

        // Z trigger
        mShake = padInfo->mTrig & PADButton::PAD_TRIGGER_Z;

        // In my opinion, we don't need the cooldown
        // Since shake is now triggered by the press of a button
        // Instead of holding a button down

        /* if (mShake) {
            // Set cooldown
            mShakeTimer3 = 5 + 3;
        } */
        return;
    }

    // Wii Remote

    if (mShakeTimer3 != 0) {
        mShakeTimer3--;
        mShake = false;
        return;
    }

    bool isButtonShake = false;
    if (fFeature::SHAKE_WITH_BUTTON) {
        if (mType == Type_e::FREESTYLE) {
            // Shake with 1/2 Buttons on in Nunchuck Mode
            // NOTE:
            // We need to access the inputs from EGG::CoreController
            // Because dGameKeyCore_c converts Z/B/A button presses into 1/2 button presses
            isButtonShake = getCoreController()->downTrigger(
              (WPADButton::WPAD_BUTTON_1 | WPADButton::WPAD_BUTTON_2)
            );
        } else {
            // Shake with B Button on sideways Wii Remote
            isButtonShake = mTriggered & WPADButton::WPAD_BUTTON_B;
        }
    }

    if (isButtonShake == false) {
        float accXDiff = fabsf(mAccel.x - mAccelOld.x);
        float accYDiff = fabsf(mAccel.y - mAccelOld.y);
        float accZDiff = fabsf(mAccel.z - mAccelOld.z);

        if (accYDiff >= 0.28) {
            mShakeTimer1++;
            if (mShakeTimer1 >= 4 && (accZDiff <= accYDiff || accZDiff <= accXDiff)) {
                mShakeTimer3 = 5;
                mShakeTimer1 = 0;
                mShake = true;
            } else {
                mShake = false;
            }
            return;
        }

        if (mShakeTimer1 != 0 && mShakeTimer2++ >= 2) {
            mShakeTimer1 = 0;
            mShakeTimer2 = 0;
        }

        mShake = false;
    } else {
        mShake = true;
    }
}
