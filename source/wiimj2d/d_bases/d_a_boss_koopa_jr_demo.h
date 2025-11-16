#pragma once

#include "d_system/d_a_boss_demo.h"

class dAcPy_c;

// TODO
class daKameckForAirshipDemo_c : public dActor_c
{
public:
    // Instance Variables
    // ^^^^^^

    FILL(0x392, 0x858);

    /* 0x858 */ float mBossDemoX;
};

// TODO
class daPeachForAirshipDemo_c : public dActor_c
{
};

class daBossKoopaJrDemo_c : public daBossDemo_c
{
public:
    // Structors
    // ^^^^^^

    daBossKoopaJrDemo_c();

public:
    // Virtual Functions
    // ^^^^^^

    /* 0x807D00D0 */
    /* virtual */ void initialize();

public:
    // Instance Methods
    // ^^^^^^

    /* 0x807D03B0 */
    void sortPlayers();

    /* 0x807D0490 */
    void calcPlayerWalkPos();

    /* 0x807D0800 */
    bool isPlayerEntry(int player);

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x3DC, 0x3E0);

    /* 0x3E0 */ int mDemoNum;
    /* 0x3E4 */ float mXBased;
    /* 0x3E8 */ float mPlayerStandCenter;
    /* 0x3EC */ float mPlayerWalkPos_Removed[4];
    /* 0x3FC */ float mAirshipDemoX;
    /* 0x400 */ float mAirshipDemoY;
    /* 0x404 */ float m0x404;
    /* 0x408 */ dAcPy_c* mpPlayersInOrder_Removed[4];
    /* 0x418 */ float m0x418;
    /* 0x41C */ float m0x41C;
    /* 0x420 */ daKameckForAirshipDemo_c* mpKamek;
    /* 0x424 */ daPeachForAirshipDemo_c* mpPeach;
    /* 0x428 */ float mPlrYPos_Removed[4];
    /* 0x438 */ bool m0x438_Removed[4];

    FILL(0x43C, 0x448);

    /* 0x448 */ float m0x448;
    /* 0x44C */ float m0x44C;
    /* 0x450 */ float mBaseXCopy;
    /* 0x454 */ float m0x454;

    FILL(0x458, 0x460);

    /* 0x460 */ float mScreenTopCopy;
    /* 0x464 */ float mBaseYCopy;

    FILL(0x468, 0x470);

    /* 0x470 */ dAcPy_c* mpFirstPlr;
    /* 0x474 */ float m0x474;
    /* 0x478 */ float mBaseX;
    /* 0x47C */ float mScreenTop;
    /* 0x480 */ float mBaseY;
    /* 0x484 */ float m0x484;

    FILL(0x488, 0x490);
    OFFSET_ASSERT(0x490);

    float mPlayerWalkPos[PLAYER_COUNT];
    dAcPy_c* mpPlayersInOrder[PLAYER_COUNT];
    float mPlrYPos[PLAYER_COUNT];
    bool m0x438[PLAYER_COUNT];
};
