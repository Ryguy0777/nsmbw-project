#pragma once

#include <dynamic/d_player_model_manager.h>

class daPyMng_c
{
public:
    //
    // Constants
    //

#define CHARACTER_COUNT 5
    enum class PlayerType_e {
        MARIO = 0,
        LUIGI = 1,
        BLUE_TOAD = 2,
        YELLOW_TOAD = 3,
        TOADETTE = 4,

        COUNT = 5,
    };

#define POWERUP_COUNT 7

#define MAX_LIVES 99

#define MAX_COINS 99

#define MAX_SCORE 999999999

    //
    // Static Functions
    //

    /* 0x80060200 */
    static int getCoinAll();

    /* 0x80061110 */
    static bool isCreateBalloon(int index);

    /* 0x80061160 */
    static void checkCorrectCreateInfo();

    //
    // Static Data
    //

    /* 0x80355110 */
    static s32 m_playerID[4];

    /* 0x80355120 */
    static s32 m_yoshiID[4];

    /* 0x80355130 */
    static s32 mCourseInList[4];

    /* 0x80355140 */
    static s32 m_yoshiFruit[4];

    /* 0x80355150 */
    static s32 mPlayerEntry[4];

    /* 0x80355160 */
    static PlayerType_e mPlayerType[CHARACTER_COUNT];

    /* 0x80355170 */
    static s32 mPlayerMode[CHARACTER_COUNT];

    /* 0x80355180 */
    static s32 mCreateItem[CHARACTER_COUNT];

    /* 0x80355190 */
    static s32 mRest[CHARACTER_COUNT];

    /* 0x803551A0 */
    static s32 mCoin[CHARACTER_COUNT];

    /* 0x80429FA0 */
    static s32 mScore;
};