#pragma once

#include <dynamic/d_a_boss_demo.h>
#include <dynamic/d_a_player_manager.h>

class dAcPy_c;

class daCastleKokoopaDemo1st_c : public daBossDemo_c
{
public:
    // ------------
    // Constructors
    // ------------

    daCastleKokoopaDemo1st_c();

public:
    // -----------------
    // Virtual Functions
    // -----------------

    /* 0x807DACB0 */
    /* virtual */ bool checkBattleStDemo();

    /* 0x807DB2E0 */
    /* virtual */ bool demoScroll();

public:
    // ----------------
    // Member Functions
    // ----------------

    /* 0x807DB440 */
    bool calcBattleStDemoControl();

    /* 0x807DB740 */
    bool calcIggyDemoScroll();

    /* 0x807DB920 */
    bool isPlayerEntry(int player);

    /* 0x807DB950 */
    void setFlag115();

    /* 0x807DBA20 */
    void killPlayerFireball();

public:
    // -----------
    // Member Data
    // -----------

    FILL(0x3DC, 0x3E8);

    /* 0x3E8 */ f32 mLeftBoundary;
    /* 0x3EC */ f32 mRightBoundary;
    /* 0x3F0 */ f32 maWalkToPos_Removed[4];

    FILL(0x400, 0x408);

    /* 0x408 */ s32 mCheckBattleStDemoStep;
    /* 0x40C */ int m0x40C_Removed[4];
    /* 0x41C */ int m0x41C_Removed[4];

    /* 0x42C */ dAcPy_c* mpaPlayersInOrder_Removed[4];

    FILL(0x43C, 0x460);

    /* 0x460 */ u8 mLevelEffect[0x128];

    FILL(0x588, 0x590);
    OFFSET_ASSERT(0x590);

    /* 0x590 */ dAcPy_c* mpaPlayersInOrder[PLAYER_COUNT];
    /* 0x5B0 */ f32 maWalkToPos[PLAYER_COUNT];
    /* 0x5D0 */ int maBattleStControlStep[PLAYER_COUNT];
    /* 0x5F0 */ int maIggyDemoScrollStep[PLAYER_COUNT];
};