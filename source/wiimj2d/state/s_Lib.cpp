// s_Lib.cpp
// NSMBW .text: 0x8015F280 - 0x8015F740

namespace sLib
{

[[nsmbw(0x8015F340)]]
short addCalcAngle(short* target_var, short target_value, short div, short accel, short min);

[[nsmbw(0x8015F630)]]
bool chaseAngle(short* target_var, short target_value, short increment);

} // namespace sLib