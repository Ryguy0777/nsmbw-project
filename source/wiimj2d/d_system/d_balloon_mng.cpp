// d_balloon_mng.cpp
// NSMBW .text: 0x8006C0B0 - 0x8006C420

#include "d_balloon_mng.h"

[[nsmbw_data(0x8042A068)]]
dBalloonMng_c* dBalloonMng_c::m_instance;

[[nsmbw(0x8006C1C0)]]
void dBalloonMng_c::execute();
