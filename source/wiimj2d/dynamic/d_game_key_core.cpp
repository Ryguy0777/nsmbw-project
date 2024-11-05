// d_game_key_core.cpp
// NSMBW: 0x800B5B50 - 0x800B64A0

#include "d_game_key_core.h"

[[address(0x800B5B50)]]
dGameKeyCore_c::dGameKeyCore_c(mPad::CH_e channel);

[[address(0x800B5BE0)]]
void dGameKeyCore_c::allclear();

[[address(0x800B5CB0)]]
void dGameKeyCore_c::read();