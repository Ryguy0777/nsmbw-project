// d_switch_flag_mng.cpp
// NSMBW: 0x800E3BD0 - 0x800E46E0

#include "d_switch_flag_mng.h"

[[address_data(0x8042A358)]]
dSwitchFlagMng_c* dSwitchFlagMng_c::m_instance;

[[address(0x800E4100)]]
void dSwitchFlagMng_c::execute();
