// f_feature.cpp
// NSMBW: ----

#include "f_feature.h"

namespace fFeature
{

// Use alignment padding space in .text functions for storing settings set by Riivolution

[[address_data(0x80006784)]]
bool UNLOCKED_ALL_WORLDS;

[[address_data(0x80006785)]]
bool COMPLETED_ALL_LEVELS;

[[address_data(0x80006786)]]
bool DISABLE_POWERUP_CHANGE_PAUSE;

[[address_data(0x80006787)]]
bool INFINITE_LIVES;

[[address_data(0x80006788)]]
DEATH_MESSAGES_MODE_e DEATH_MESSAGES;

[[address_data(0x80006789)]]
bool FALL_DAMAGE;

[[address_data(0x8000678A)]]
bool DISABLE_OPENING_MOVIE;

[[address_data(0x8000678B)]]
bool ALWAYS_CAN_EXIT_COURSE;

} // namespace fFeature