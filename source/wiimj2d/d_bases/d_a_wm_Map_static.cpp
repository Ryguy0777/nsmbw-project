// d_a_wm_Map_static.cpp
// NSMBW .text: 0x80100140 - 0x80100A10

#include "d_a_wm_Map.h"

[[address_data(0x8042A46C)]]
daWmMap_c* daWmMap_c::m_instance;

[[address(0x80100310)]]
mVec3_c daWmMap_c::GetPos(int node);
