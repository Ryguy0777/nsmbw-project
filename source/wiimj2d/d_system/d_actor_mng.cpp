// d_actor_mng.cpp
// NSMBW .text: 0x80066380 - 0x80066FB0

#include "d_actor_mng.h"

[[address_data(0x8042A020)]]
dActorMng_c* dActorMng_c::m_instance;

[[address(0x80066EC0)]]
void dActorMng_c::finalUpdate();

[[address(0x80066F70)]]
void dActorMng_c::execute();
