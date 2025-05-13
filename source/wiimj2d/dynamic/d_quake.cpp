// d_quake.cpp
// NSMBW .text: 0x800D8940 - 0x800D91B0

#include "d_quake.h"

[[address_data(0x8042A2E8)]]
dQuake_c* dQuake_c::m_instance;

[[address(0x800D8CA0)]]
void dQuake_c::shockMotor(s8 player, TYPE_SHOCK_e type, int flag, bool grabActive);