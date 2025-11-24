// d_a_yoshi_egg.cpp
// NSMBW d_bases.text: 0x80910F00 - 0x809125E0

#include "d_system/d_actor.h"

[[address(0x80911610)]]
void daYoshiEgg_c_spawnEggBreakEffect(dActor_c *egg);

[[address(0x80911680)]]
void daYoshiEgg_c_hatchYoshi(dActor_c *egg)
{   
    int color = egg->mParam & 0xF;
    int defaultYoshiColors[dYoshiMdl_c::COLOR_COUNT] = {
        dYoshiMdl_c::COLOR_GREEN,
        dYoshiMdl_c::COLOR_YELLOW,
        dYoshiMdl_c::COLOR_BLUE,
        dYoshiMdl_c::COLOR_RED,
        dYoshiMdl_c::COLOR_CRIMSON,
        dYoshiMdl_c::COLOR_ORANGE,
        dYoshiMdl_c::COLOR_PURPLE,
        dYoshiMdl_c::COLOR_BLACK,
    };

    if (color < 4) {
        daYoshiEgg_c_spawnEggBreakEffect(egg);
    }
    daPyMng_c::createYoshi(egg->mPos, defaultYoshiColors[color], nullptr);
    egg->deleteRequest();
}