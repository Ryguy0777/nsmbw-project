// d_a_en_remocon_cannon.cpp
// NSMBW .text: 0x80A94D90 - 0x80A97B30

#include "d_a_en_remocon_cannon.h"
#include "d_system/d_game_common.h"
#include "revolution/os/OSError.h"

[[address(0x80A964E0)]]
bool daEnRemoconCannon_c::UNDEF_80a964e0(short target)
{
    return dGameCom::CalculateTiltShoulder(&mTargetAngle, target, 400, mPlayerNo, 0x3520);
}