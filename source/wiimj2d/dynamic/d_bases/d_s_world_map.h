#pragma once

#include <dynamic/d_mj2d_game.h>
#include <dynamic/d_scene.h>

class dScWMap_c : public dScene_c
{
public:
    // ----------------
    // Static Functions
    // ----------------

    /* 0x801027A0 @unofficial */
    static void EnterWorld(WORLD_e world, int node);

    /* 0x809271C0 */
    static bool createActorsPhase(dScWMap_c* self);
};