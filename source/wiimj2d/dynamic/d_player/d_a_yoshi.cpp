// d_a_yoshi.cpp
// NSMBW .text: 0x8014B400 - 0x80154800

#include "d_a_yoshi.h"

#include <dynamic/d_a_player_manager.h>
#include <framework/f_feature.h>

/* VT+0x0DC */
[[address(0x0x80150E10)]]
void daYoshi_c::executeLastAll()
{
    if (!isStatus(1)) {
        return;
    }

    setHitTongueReserve();
    calcHeadAttentionAngle();
    mModelMng.calc2();

    if (!fFeature::DISABLE_POWERUP_CHANGE_PAUSE) {
        if (isStatus(198)) {
            offStatus(198);
            stopOther();
            daPyMng_c::mStopTimerInfo |= 1 << mPlayerNo;
        }

        if (isStatus(199)) {
            offStatus(199);
            playOther();
            daPyMng_c::mStopTimerInfo &= ~(1 << mPlayerNo);
        }
    }
}

[[address(0x80150420)]]
void daYoshi_c::setHitTongueReserve();