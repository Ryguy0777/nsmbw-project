// d_s_world_map_static.cpp
// NSMBW .text: 0x80102770 - 0x80102DB0

#include "d_s_world_map.h"

/* @unofficial */
[[address(0x801027A0)]]
void dScWMap_c::EnterWorld(WORLD_e world, int node);

[[address(0x80102B50)]]
u32 dScWMap_c::CreateBootParam();