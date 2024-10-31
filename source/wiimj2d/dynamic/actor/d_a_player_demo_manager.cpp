// d_a_player_demo_manager.cpp
// NSMBW: 0x8005B3A0 - 0x8005D7E0

#include "d_a_player_demo_manager.h"

[[address(0x80429F74)]]
daPyDemoMng_c* daPyDemoMng_c::mspInstance;

[[address(0x8005B430)]]
void daPyDemoMng_c::initStage();

[[address(0x8005B4A0)]]
void daPyDemoMng_c::init();