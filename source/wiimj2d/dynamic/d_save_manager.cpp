// d_save_manager.cpp
// NSMBW .text: 0x800E0270 - 0x800E1AA0

#include "d_save_manager.h"

[[address_data(0x8042A320)]]
dSaveMng_c* dSaveMng_c::m_instance;

[[address(0x800E0470)]]
dMj2dGame_c* dSaveMng_c::getSaveGame(s8 slot);