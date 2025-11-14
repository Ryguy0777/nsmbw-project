#pragma once

#include "d_system/d_mj2d_game.h"
#include "machine/m_vec.h"

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
    // ----------------
    // Member Functions
    // ----------------

    /* 0x8008EDB0 */
    void clear();

    /* 0x8008EE00 */
    void courseIN();

    /* 0x8008EEC0 */
    bool checkEntry();

public:
    // -----------
    // Member Data
    // -----------

    FILL(0x00, 0x04);

    /* 0x04 */ int mState;
    /* 0x08 */ mVec3_c mPlayerSetPos;
    /* 0x14 */ s32 m0x14;
    /* 0x18 */ WORLD_e mWorld;
    /* 0x19 */ STAGE_e mStage;
    /* 0x1A */ u8 mCourse; // A.k.a. Area
    /* 0x1B */ u8 mGoto;
    /* 0x1C */ bool mIsKinopioInChukan;
    /* 0x20 */ PLAYER_TYPE_e mCollectionCoin[3];
    /* 0x2C */ PLAYER_TYPE_e m0x2C[2];
};
