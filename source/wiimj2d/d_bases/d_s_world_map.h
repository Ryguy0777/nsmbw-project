#pragma once

#include "d_system/d_mj2d_game.h"
#include "d_system/d_scene.h"

class dSelectCursor_c;

class dScWMap_c : public dScene_c
{
    SIZE_ASSERT(0xEC);

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

public:
    // ----------------
    // Member Functions
    // ----------------

    /* 0x80926E10 */
    bool createLayoutPhase();

    /* 0x809271C0 */
    bool createActorsPhase();

public:
    // -----------
    // Member Data
    // -----------

    FILL(0x74, 0x7C);

    /* 0x7C */ dSelectCursor_c* mpSelectCursor;

    FILL(0x80, 0xEC);

public:
    // -----------
    // Static Data
    // -----------

    /* 0x8042A538 */
    static bool m_GameOver;
};
