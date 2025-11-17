#pragma once

namespace sLib
{

/* 0x8015F340 */
short addCalcAngle(short *target_var, short target_value, short div, short accel, short min);

/* 0x8015F630 */
bool chaseAngle(short *target_var, short target_value, short increment);

} // namespace sLib