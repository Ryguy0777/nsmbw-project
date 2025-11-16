#pragma once

#include "d_system/d_a_player_manager.h"
#include "d_system/d_enemy.h"

class daEnGlpole_c : public dEn_c
{
public:
    // Constants and Types
    // ^^^^^^

    struct UNKPlayerPos {
        FILL(0x00, 0x10);
    };

public:
    // Structors
    // ^^^^^^

    /* 0x80A09710 */
    daEnGlpole_c();

public:
    // Virtual Functions
    // ^^^^^^

    /**
     * VT+0x08 0x80A09980
     * do method for the create operation.
     */
    PACK_RESULT_e create() override;

public:
    // Functions
    // ^^^^^^

    /* 0x80A0A700 */
    bool isTopOfFlagPole(u32 mask, int player);

    /* 0x80A0B020 */
    bool isAllPlayerOnPole();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x524, 0xAAC);

    /* 0x0AAC */ u8 mPlayerOnPoleFlag;

    FILL(0xAAD, 0xAB0);
    OFFSET_ASSERT(0xAB0);

#define daEnGlpole_c_OFFSET_mPlayerPos (0xAB0)
#define daEnGlpole_c_ADJUST_mPlayerPos (0xAB0 - 0xA38)
    /* 0x0AB0 */ UNKPlayerPos mPlayerPos[PLAYER_COUNT];
};
