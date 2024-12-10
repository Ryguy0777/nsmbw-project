#pragma once

#include <dynamic/d_a_player_manager.h>
#include <dynamic/d_enemy.h>

class daEnRedcoin_c : public dEn_c
{
public:
    // ----------------
    // Member Functions
    // ----------------

    /* 0x80A94250 */
    void selectItems();

public:
    // -----------
    // Member Data
    // -----------

    FILL(0x524, 0x66C);

    /* 0x66C */ int mItemType;

    FILL(0x670, 0x67C);

    /* 0x67C */ int mPlyItemSpawnMode_Removed[4];
    /* 0x68C */ int mPlyItem_Removed[4];

    FILL(0x69C, 0x6A8);
    OFFSET_ASSERT(0x6A8);

#define OFFSET_mPlyItemSpawnMode 0x6A8
    /* 0x6A8 */ int mPlyItemSpawnMode[PLAYER_COUNT];

#define OFFSET_mPlyItem (0x6A8 + PLAYER_COUNT * 4)
    int mPlyItem[PLAYER_COUNT];
};