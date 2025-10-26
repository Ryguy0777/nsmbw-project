// d_game_key_core.cpp
// NSMBW .text: 0x800B5B50 - 0x800B64A0

#include "d_game_key_core.h"

#include <cmath>
#include "d_player/d_a_player.h"
#include "d_system/d_a_player_manager.h"
#include "d_bases/d_s_stage.h"
#include <egg/core/eggController.h>
#include <revolution/pad.h>

[[address(0x800B5B50)]]
dGameKeyCore_c::dGameKeyCore_c(mPad::CH_e channel);

[[address(0x800B5BE0)]]
void dGameKeyCore_c::allclear();

[[address(0x800B5CB0)]]
void dGameKeyCore_c::read();

[[address(0x800B62A0)]]
void dGameKeyCore_c::setShakeY()
{
    if (dScStage_c::m_replayPlay_p[static_cast<int>(mChannel)] != nullptr) {
        mShake = dScStage_c::m_replayPlay_p[static_cast<int>(mChannel)]->mFrameFlags & (1 << 29);
        return;
    }

    PADInfo* padInfo = EGG::CoreControllerMgr::getPadInfo(static_cast<WPADChannel>(mChannel));
    if (padInfo != nullptr) {
        // GameCube controller

        bool fullShake = padInfo->trig & PADButton::PAD_TRIGGER_Z;

        if (fullShake) {
            mShake = true;
        } else {
            mShake = false;
        }
    } else {
        // Wii Remote

        if (mShakeTimer3 != 0) {
            mShakeTimer3--;
            mShake = false;
            return;
        }

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
    }
}