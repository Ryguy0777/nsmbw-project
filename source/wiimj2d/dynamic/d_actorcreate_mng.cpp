// d_actorcreate_mng.cpp
// NSMBW: 0x80068040 - 0x80069020

#include "d_actorcreate_mng.h"

[[address_data(0x8042A028)]]
dActorCreateMng_c* dActorCreateMng_c::m_instance;

[[address(0x80068620)]]
void dActorCreateMng_c::execute();
