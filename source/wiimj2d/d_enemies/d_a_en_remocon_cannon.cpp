// d_a_en_remocon_cannon.cpp
// NSMBW .text: 0x80A94D90 - 0x80A97B30

#include "d_a_en_remocon_cannon.h"
#include "d_player/d_a_player.h"
#include "d_system/d_game_common.h"
#include "sound/SndID.h"

[[address(0x80A95890)]]
void daEnRemoconCannon_c::setBodyColor()
{
    if (mPlayerNo > -1) {
        dAcPy_c* player = daPyMng_c::getPlayer(mPlayerNo);
        float frame = 0.0;
        if (player != nullptr) {
            frame = static_cast<float>(player->mPlayerType + 1);
            mAnmTexPat.setFrame(frame, 0);
            mAnmTexPat.setRate(0.0, 0);
            daPlBase_c::playSound(player, SndID::SE_OBJ_RC_CONTROL_ON, 0);
        }
        // TODO: This function
        //setArrowColor(mRes, mPlayerNo);
        mHasPlayer = true;
        mPlayerNo2 = mPlayerNo;
        dGameCom::FUN_800B3600(mPlayerNo, 0xF);
    }
}

[[address(0x80A964E0)]]
bool daEnRemoconCannon_c::UNDEF_80a964e0(short target)
{
    return dGameCom::CalculateTiltShoulder(&mTargetAngle, target, 400, mPlayerNo, 0x3520);
}