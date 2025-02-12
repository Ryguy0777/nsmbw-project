#pragma once

#include <dynamic/d_a_player_manager.h>
#include <dynamic/d_cyuukan.h>
#include <dynamic/d_mj2d_game.h>
#include <dynamic/d_start_info.h>

class dInfo_c
{
    /* 0x000 VTABLE 0x80315EA0 */

public:
    // -------------------
    // Constants and Types
    // -------------------

    /* @unofficial */
    enum class ScreenType_e {
        NORMAL = 0,
        SUPER_GUIDE = 1,
        TITLE = 2,
        TITLE_REPLAY = 3,
        HINT_MOVIE = 4,
    };

    struct StartGameInfo_s {
        SIZE_ASSERT(0x10);

        /* 0x00 */ u32 demoTime;

        /**
         * Hint movie type (0 = Super Skills, 1 = 1UP, 2 = Star Coin, 3 = Secret Exit)
         */
        /* 0x04 */ u8 demoType;

        /**
         * Goto ID (a.k.a. entrance)
         */
        /* 0x05 */ u8 gotoID;

        /**
         * Course ID (a.k.a. area)
         */
        /* 0x06 */ u8 courseID;

        /* 0x07 */ bool isDemo;

        /* 0x08 */ ScreenType_e screenType;

        /* 0x0C */ WORLD_e world1;
        /* 0x0D */ STAGE_e stage1;
        /* 0x0E */ WORLD_e world2;
        /* 0x0F */ STAGE_e stage2;
    };

    static constexpr u32 ORIGINAL_SIZE = 0xB5C;

public:
    // ------------
    // Constructors
    // ------------

    /* 0x800BB0E0 */
    dInfo_c();

    /* VT+0x8 0x800BB130 */
    virtual ~dInfo_c();

public:
    // ---------
    // Functions
    // ---------

    /* 0x800BB180 */
    void PlayerStateInit();

    /* 0x800BB7D0 */
    void startGame(const StartGameInfo_s& startGameInfo);

    /* 0x800BB940 */
    void initStage();

public:
    // -----------
    // Member Data
    // -----------

    /* 0x004 */ s32 m0x004;

    /* 0x008 */ dCyuukan_c mCyuukan;

    /* 0x03C */ s32 mWorld;
    /* 0x040 */ s32 mLevel;
    /* 0x044 */ s32 mWmNode;

    FILL(0x048, 0x060);

    /* 0x060 */ s32 m0x060;
    /* 0x064 */ s32 m0x064;
    /* 0x068 */ s32 m0x068;
    /* 0x06C */ u8 m0x06C;

    FILL(0x06D, 0x380);

    /**
     * The status of the worldmap switch.
     */
    /* 0x380 */ bool mSwitchOn;

    /* 0x384 */ s32 mPlayerActiveMode[4];

    FILL(0x394, 0xAF4);

    /* 0xAF4 */ s32 m0xAF4;

    FILL(0xAF8, 0xAFC);

    /* 0xAFC */ u8 m0xAFC;

    FILL(0xAFD, 0xAFE);

    /* 0xAFE */ u8 m0xAFE[4][22];

    /* 0xB56 */ u8 m0xB56[4];

    FILL(0xB5A, 0xB5C);
    OFFSET_ASSERT(0xB5C);

#define OFFSET_dInfo_c_mExPlayerActiveMode 0xB5C
    /* 0xB5C */ s32 mExPlayerActiveMode[PLAYER_COUNT - 4];

#define OFFSET_dInfo_c_mEx0xAFE 0xB6C
#define ADJUST_dInfo_c_mEx0xAFE 0xB6C - 0xAFE - 4 * 22
    /* 0xB6C */ u8 mEx0xAFE[PLAYER_COUNT - 4][22];

#define OFFSET_dInfo_c_mEx0xB56 0xBC4
#define ADJUST_dInfo_c_mEx0xB56 0xBC4 - 0xB56 - 4
    /* 0xBC4 */ u8 mEx0xB56[PLAYER_COUNT - 4];

    OFFSET_ASSERT(0xBC8);

public:
    // -----------
    // Static Data
    // -----------

    /* 0x80315E98 */ static StartGameInfo_s m_startGameInfo;

    /* 0x80359054 */ static dStartInfo_c m_startInfo;

    /* 0x8042A25C */ static dInfo_c* m_instance;

    /* 0x8042A260 */ static u32 mGameFlag;
};