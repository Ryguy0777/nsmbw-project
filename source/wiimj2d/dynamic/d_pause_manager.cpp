// d_pause_manager.cpp
// NSMBW: 0x800D0A90 - 0x800D15F0

#include "d_pause_manager.h"

[[address_data(0x8042A2B8)]]
PauseManager_c* PauseManager_c::m_instance;

[[address_data(0x8042A2C2)]]
bool PauseManager_c::m_OtasukeAfter;

[[address(0x800D1350)]]
void PauseManager_c::setPause();