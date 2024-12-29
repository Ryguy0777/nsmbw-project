#pragma once

#include <dynamic/d_a_player_manager.h>
#include <dynamic/d_enemy.h>
#include <machine/m_vec.h>

class daEnRedRing_c : public dEn_c
{
public:
    // -----------------
    // Virtual Functions
    // -----------------

    /**
     * VT+0x08 0x80A92820
     * do method for the create operation.
     */
    PACK_RESULT_e create() override;

    /* 0x80A93140 */
    void executeState_Wait();

public:
    // ----------------
    // Member Functions
    // ----------------

    /* 0x80A92E80 */
    void UNDEF_80A92E80();

public:
    // -----------
    // Member Data
    // -----------

    FILL(0x524, 0x688);

    static_assert(PLAYER_COUNT <= 8, "Adapt this to support more players pleeease");
#define OFFSET_daEnRedRing_c_mPlayerDelta 0x688
    /* 0x688 */ mVec2_c mPlayerDelta[8];

    FILL(0x6C8, 0x800);
    OFFSET_ASSERT(0x800);

#define OFFSET_daEnRedRing_c_mPrevPlayerDelta 0x800
    /* 0x800 */ mVec2_c mPrevPlayerDelta[8];
};