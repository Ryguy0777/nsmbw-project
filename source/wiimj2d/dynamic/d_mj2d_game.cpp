// d_mj2d_game.cpp
// NSMBW .text: 0x800CDFB0 - 0x800CE660

#include "d_mj2d_game.h"

/**
 * Checks if the completion flag(s) for the given world is set. See WORLD_COMPLETION_e.
 */
[[address(0x800CE440)]]
u8 dMj2dGame_c::isWorldDataFlag(WORLD_e world, WORLD_COMPLETION_e flag) const;

/**
 * Sets the specified flag(s) for the given world. See WORLD_COMPLETION_e.
 */
[[address(0x800CE450)]]
void dMj2dGame_c::onWorldDataFlag(WORLD_e world, WORLD_COMPLETION_e flag);

/**
 * Unsets the specified flag(s) for the given world. See WORLD_COMPLETION_e.
 */
[[address(0x800CE470)]]
void dMj2dGame_c::offWorldDataFlag(WORLD_e world, WORLD_COMPLETION_e flag);