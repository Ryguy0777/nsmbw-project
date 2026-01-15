#pragma once

#include "framework/f_base_id.h"

class dBalloonMng_c
{
public:
    // Constants
    // ^^^^^^

    static constexpr int TIMER_MAX = 30 * 60; // 30 seconds

public:
    // Instance Methods
    // ^^^^^^

    /* 0x8006C0B0 */
    void BalloonInfoClear();

    /* 0x8006C0E0 */
    void setItemId(fBaseID_e id);

    /* 0x8006C120 */
    bool item_max_check();

    /* 0x8006C1C0 */
    void execute();

public:
    // Instance Variables
    // ^^^^^^

    /* 0x00 */ fBaseID_e mLastBalloonId;
    /* 0x04 */ fBaseID_e mItemId[5];
    /* 0x18 */ int mCreateTimer;
    /* 0x1C */ int m0x1C;
    /* 0x20 */ int mBossDead;

public:
    // Static Variables
    // ^^^^^^

    /* 0x8042A068 */ static dBalloonMng_c* m_instance;
};
