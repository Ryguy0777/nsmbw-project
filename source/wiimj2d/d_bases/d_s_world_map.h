#pragma once

#include "d_system/d_mj2d_game.h"
#include "d_system/d_scene.h"

class dScWMap_c : public dScene_c
{
public:
    // ----------------
    // Static Functions
    // ----------------

    /* 0x801027A0 @unofficial */
    static void EnterWorld(WORLD_e world, int node);

    /* 0x80102B50 */
    static u32 CreateBootParam();

    /* 0x80102B90 */
    static void initLoadGame();

    /* 0x809271C0 */
    static bool createActorsPhase(dScWMap_c* self);

public:
    // -----------
    // Static Data
    // -----------

    /* 0x8042A538 */
    static bool m_GameOver;
};