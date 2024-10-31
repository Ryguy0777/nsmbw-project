// d_remocon_mng.cpp
// NSMBW: 0x800DBFD0 - 0x800DDA40

#include "d_remocon_mng.h"

[[address_data(0x8042A308)]]
dRemoconMng_c* dRemoconMng_c::m_instance;