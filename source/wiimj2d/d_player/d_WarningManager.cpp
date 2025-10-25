// d_WarningManager.cpp
// NSMBW .text: 0x8010D270 - 0x8010F080

#include "d_WarningManager.h"

[[address_data(0x8042A5B8)]]
dWarningManager_c* dWarningManager_c::m_instance;

[[address_data(0x8042A5C0)]]
s32 dWarningManager_c::m_WarningForbid;
