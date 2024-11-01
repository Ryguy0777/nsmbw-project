#pragma once

#include "System.h"

class daPyDemoMng_c
{
public:
    // ------------
    // Constructors
    // ------------

    /* 0x8005B3A0 */
    daPyDemoMng_c();

    /* VT+0x8 0x8005B3E0 */
    virtual ~daPyDemoMng_c();

public:
    // ---------
    // Functions
    // ---------

    /* 0x8005B430 */
    void initStage();

    /* 0x8005B4A0 */
    void init();

    /* 0x8005B6A0 */
    void calcNotGoalPlayer();

    /* 0x8005B780 */
    int setGoalDemoList(int param);

    /* 0x8005B840 */
    int getPoleBelowPlayer(int param);

    /* 0x8005B8A0 */
    void executeGoalDemo_Pole();

    /* 0x8005BCF0 */
    void executeGoalDemo_PoleDown();

    /* 0x8005BD60 */
    void executeGoalDemo_JumpCheck();

    /* 0x8005BE30 */
    void executeGoalDemo_Jump();

    /* 0x8005BF10 */
    void executeGoalDemo_Land();

    /* 0x8005BFD0 */
    void executeGoalDemo_KimeWait();

    /* 0x8005C130 */
    void setGoalDemoKimeAll();

    /* 0x8005C1A0 */
    void setGoalDemoRunCastle();

    /* 0x8005C210 */
    bool isAllPlayerGoalIn();

    /* 0x8005C6D0 */
    void calcGoalCenterPos();

    /* 0x8005C930 */
    bool startControlDemoAll();

    /* 0x8005C9D0 */
    bool isAllPlayerControlDemo();

    /* 0x8005CA50 */
    void endControlDemoAll(int param);

    /* 0x8005CAD0 */
    int getControlDemoPlayerNum();

    /* 0x8005CB70 */
    void onLandStopReq();

    /* 0x8005CC00 */
    bool startControlDemoLandPlayer();

    /* 0x8005CDD0 */
    bool isLandAll();

    /* 0x8005CE50 */
    void UNDEF_8005CE50(int param);

    /* 0x8005CED0 */
    void executeStartToride();

    /* 0x8005D050 */
    void setCourseOutList();

    /* 0x8005D280 */
    void genCourseInList();

public:
    // -----------
    // Static Data
    // -----------

    /* 0x80429F74 */ static daPyDemoMng_c* mspInstance;

public:
    // -----------
    // Member Data
    // -----------

    FILL(0x04, 0x1C);

    /* 0x1C */ int mPlayerCount;
    /* 0x20 */ int mPlayerIDs[4];

    FILL(0x30, 0x84);

    /* 0x84 */ int mOwnedPlayer;

    FILL(0x88, 0x98);
    OFFSET_ASSERT(0x98);

    /* 0x98 */ int mExPlayerIDs[4];
};