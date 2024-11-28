// d_enemy_manager.cpp
// NSMBW: 0x800A7450 - 0x800A7DA0

#include "d_enemy_manager.h"

[[address_data(0x8042A1F0)]]
dEnemyMng_c* dEnemyMng_c::m_instance;

[[address(0x800A7D30)]]
void dEnemyMng_c::execute();
