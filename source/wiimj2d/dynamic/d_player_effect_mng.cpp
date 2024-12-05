// d_player_effect_mng.cpp
// NSMBW: 0x800D2D10 - 0x800D2EC0

#include "d_player_effect_mng.h"

[[address_data(0x8042A2D0)]]
dPyEffectMng_c* dPyEffectMng_c::mspInstance;

[[address(0x800D2E70)]]
void dPyEffectMng_c::update();