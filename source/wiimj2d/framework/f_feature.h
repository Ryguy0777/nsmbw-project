#pragma once

namespace fFeature
{

extern bool UNLOCKED_ALL_WORLDS;
extern bool COMPLETED_ALL_LEVELS;
extern bool DISABLE_POWERUP_CHANGE_PAUSE;

// Replace life counter with a death counter
extern bool INFINITE_LIVES;

// Enable death messages in the bottom left of the screen
extern enum class DEATH_MESSAGES_MODE_e : u8 {
    DISABLED = 0,
    DEATH_AND_DAMAGE = 1,
    DEATH_ONLY = 2,
} DEATH_MESSAGES;

// Enable fall damage mod
extern bool FALL_DAMAGE;

extern bool DISABLE_OPENING_MOVIE;

extern bool ALWAYS_CAN_EXIT_COURSE;

} // namespace fFeature