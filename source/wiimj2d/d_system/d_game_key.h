#pragma once

#include "d_system/d_a_player_manager.h"
#include "d_system/d_game_key_core.h"
#include <egg/core/eggHeap.h>

class dGameKey_c
{
    /* 0x00 VTABLE 0x80315900 */

public:
    // -------------------
    // Constants and Types
    // -------------------

    static constexpr int CORE_COUNT = PLAYER_COUNT;

public:
    // ------------
    // Constructors
    // ------------

    /* 0x800B5980 */
    dGameKey_c();

    /* VT+0x8 0x800B5A00 */
    virtual ~dGameKey_c();

public:
    // -----------
    // Static Data
    // -----------

    /* 0x8042A230 */ static dGameKey_c* m_instance;

public:
    // ----------------
    // Static Functions
    // ----------------

    /* 0x800B5930 */
    static dGameKey_c* createInstance(EGG::Heap* heap);

public:
    // ---------
    // Functions
    // ---------

    /* 0x800B5AB0 */
    void allclear();

    /* 0x800B5B00 */
    int read();

public:
    // -----------
    // Member Data
    // -----------

    /* 0x04 */ dGameKeyCore_c* mpCores[CORE_COUNT];
};