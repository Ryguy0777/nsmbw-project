// f_feature.cpp
// NSMBW: ----

#include "f_feature.h"

namespace fFeature
{

// Use alignment padding space in .text functions for storing settings set by Riivolution

[[nsmbw_data(0x80006784)]]
bool UNLOCKED_ALL_WORLDS;

[[nsmbw_data(0x80006785)]]
bool COMPLETED_ALL_LEVELS;

[[nsmbw_data(0x80006786)]]
bool DISABLE_POWERUP_CHANGE_PAUSE;

[[nsmbw_data(0x80006787)]]
bool INFINITE_LIVES;

[[nsmbw_data(0x80006788)]]
DEATH_MESSAGES_MODE_e DEATH_MESSAGES;

[[nsmbw_data(0x80006789)]]
bool FALL_DAMAGE;

[[nsmbw_data(0x8000678A)]]
bool DISABLE_OPENING_MOVIE;

[[nsmbw_data(0x8000678B)]]
bool ALWAYS_CAN_EXIT_COURSE;

[[nsmbw_data(0x8000678C)]]
bool SHAKE_WITH_BUTTON;

[[nsmbw_data(0x8000678D)]]
FUKIDASHI_MODE_e FUKIDASHI_MODE;

[[nsmbw_data(0x8000678E)]]
YOSHI_COLOR_MODE_e YOSHI_COLOR_MODE;

} // namespace fFeature