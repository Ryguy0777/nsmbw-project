// d_effactor_mng.cpp
// NSMBW .text: 0x8008FE30 - 0x80092C00

#include "d_effactor_mng.h"

[[address_data(0x8042A1C8)]]
dEffActorMng_c* dEffActorMng_c::m_instance;

[[address(0x800923D0)]]
void dEffActorMng_c::execute();
