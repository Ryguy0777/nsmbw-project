#pragma once

#include <dynamic/d_mj2d_game.h>
#include <machine/m_vec.h>

class dCyuukan_c
{
    SIZE_ASSERT(0x34);

public:
    // ------------
    // Constructors
    // ------------

    /* 0x8008ED70 */
    dCyuukan_c();

public:
    // -------------------
    // Constants and Types
    // -------------------

    /* @unofficial */
    enum class COLLECTION_COIN_STATUS_e : s32 {
        NOT_COLLECTED = 4,
    };

public:
    // ----------------
    // Member Functions
    // ----------------

    /* 0x8008EDB0 */
    void clear();

    /* 0x8008EE00 */
    void courseIN();

public:
    // -----------
    // Member Data
    // -----------

    FILL(0x00, 0x04);

    /* 0x04 */ u32 m0x04;
    /* 0x08 */ mVec3_c mPlayerSetPos;
    /* 0x14 */ u32 m0x14;
    /* 0x18 */ WORLD_e mWorld;
    /* 0x19 */ STAGE_e mStage;
    /* 0x1A */ u8 mCourse; // A.k.a. Area
    /* 0x1B */ u8 mGoto;
    /* 0x1C */ bool mIsKinopioInChukan;
    /* 0x20 */ COLLECTION_COIN_STATUS_e mCollectionCoin[3];
    /* 0x2C */ s32 m0x2C[2];
};