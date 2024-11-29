#pragma once

#include <dynamic/d_player_model_manager.h>
#include <framework/f_base_id.h>

class dAcPy_c;
class daYoshi_c;
class daPlBase_c;
class daPyDemoMng_c;

class daPyMng_c
{
public:
    // ---------
    // Constants
    // ---------

#define CHARACTER_COUNT 8
#define PLAYER_COUNT 8 // Same as CHARACTER_COUNT

    enum class PlayerType_e {
        MARIO = 0,
        LUIGI = 1,
        BLUE_TOAD = 2,
        YELLOW_TOAD = 3,
        TOADETTE = 4,
        PLAYER_5 = 5,
        PLAYER_6 = 6,
        PLAYER_7 = 7,

        COUNT = 8,
    };

    static constexpr PlayerType_e DEFAULT_PLAYER_ORDER[CHARACTER_COUNT] = {
      PlayerType_e::MARIO,     PlayerType_e::LUIGI,    PlayerType_e::YELLOW_TOAD,
      PlayerType_e::BLUE_TOAD, PlayerType_e::TOADETTE, PlayerType_e::PLAYER_5,
      PlayerType_e::PLAYER_6,  PlayerType_e::PLAYER_7
    };

#define POWERUP_COUNT 7

#define MAX_LIVES 99

#define MAX_COINS 99

#define MAX_SCORE 999999999

    // ----------------
    // Static Functions
    // ----------------

    [[nodiscard]]
    static bool isOnePlayer()
    {
        return getEntryNum() == 1;
    }

    /* 0x8005EA60 */
    static void initGame();

    /* 0x8005EB10 */
    static void initStage();

    /* 0x8005ECE0 */
    static void setDefaultParam();

    /* 0x8005ED90 */
    [[nodiscard]]
    static mVec3_c getPlayerSetPos(u8 course, u8 gotoID);

    /* 0x8005EE90 */
    [[nodiscard]]
    static u8 getPlayerCreateAction();

    /* 0x8005EEE0 @unofficial */
    static bool createPlayer(int player, mVec3_c position, s32 gotoKind, bool faceLeft);

    /* 0x8005EF50 */
    static void createCourseInit();

    /* 0x8005F570 @unofficial */
    static void initKinopioPlayer(int kinopioMode, int index);

    /* 0x8005F5C0 */
    static void update();

    /* 0x8005F8C0 */
    static void setPlayer(int index, dAcPy_c* player);

    /* 0x8005F900 */
    [[nodiscard]]
    static dAcPy_c* getPlayer(int index);

    /* 0x8005F920 */
    static void decideCtrlPlrNo();

    /* 0x8005F990 */
    static bool setYoshi(daPlBase_c* yoshi);

    /* 0x8005FA00 */
    static void releaseYoshi(daPlBase_c* yoshi);

    /* 0x8005FA60 */
    [[nodiscard]]
    static daYoshi_c* getYoshi(int index);

    /* 0x8005FB00 */
    static int getYoshiNum();

    /* 0x8005FB90 */
    static daPlBase_c* getCtrlPlayer(int index);

    /* 0x8005FBE0 */
    static dPyMdlMng_c::ModelType_e getCourseInPlayerModelType(u8 index);

    /* 0x8005FC70 */
    [[nodiscard]]
    static u8 getActScrollInfo();

    /* 0x8005FD20 */
    [[nodiscard]]
    static u8 getScrollNum();

    /* 0x8005FDB0 */
    static bool addNum(int num);

    /* 0x8005FEB0 */
    static void addNum();

    /* 0x8005FEF0 */
    static int getNumInGame();

    /* 0x8005FFB0 */
    static int getEntryNum();

    /* 0x80060110 @unofficial */
    static int findPlayerWithType(PlayerType_e playerType);

    /* 0x80060200 */
    [[nodiscard]]
    static int getCoinAll();

    /* 0x80060250 */
    static void incCoin(int player);

    /* 0x80060460 */
    static void addRest(int player, int num, bool playEffect);

    /* 0x80060590 */
    static void incRestAll(bool playEffect);

    /* 0x80060690 */
    static void addScore(int score, int player);

    /* 0x80060750 */
    static void stopStarBGM();

    /* 0x80060860 */
    static void stopYoshiBGM();

    /* 0x80060970 */
    static void executeLastPlayer();

    /* 0x80060A10 */
    static void executeLastAll();

    /* 0x80060AB0 */
    static void deleteCullingYoshi();

    /* 0x80060C10 */
    static void setHipAttackQuake(int param1, u8 param2);

    /* 0x80060DB0 */
    static void FUN_0x80060DB0();

    /* 0x80060EF0 */
    static void checkBonusNoCap();

    /* 0x80060F20 */
    static void initYoshiPriority();

    /* 0x80060FE0 */
    static void setYoshiPriority();

    /* 0x80061110 */
    [[nodiscard]]
    static bool isCreateBalloon(int index);

    /* 0x80061160 */
    static void checkCorrectCreateInfo();

    // -----------
    // Static Data
    // -----------

    /* 0x80355110 */
    static fBaseID_e m_playerID[PLAYER_COUNT];

    /* 0x80355120 */
    static fBaseID_e m_yoshiID[PLAYER_COUNT];

    /* 0x80355130 */
    static s32 mCourseInList[PLAYER_COUNT];

    /* 0x80355140 */
    static s32 m_yoshiFruit[PLAYER_COUNT];

    /* 0x80355150 */
    static s32 mPlayerEntry[PLAYER_COUNT];

    /* 0x80355160 */
    static PlayerType_e mPlayerType[PLAYER_COUNT];

    /* 0x80355170 */
    static s32 mPlayerMode[CHARACTER_COUNT];

    /* 0x80355180 */
    static s32 mCreateItem[CHARACTER_COUNT];

    /* 0x80355190 */
    static s32 mRest[CHARACTER_COUNT];

    /* 0x803551A0 */
    static s32 mCoin[CHARACTER_COUNT];

    /* 0x803551B0 */
    static s32 m_quakeTimer[CHARACTER_COUNT];

    /* 0x803551C0 */
    static s32 m_quakeEffectFlag[CHARACTER_COUNT];

    /* 0x803551E0 */
    static daPyDemoMng_c mDemoManager;

    /* 0x80429F80 */
    static int mNum;

    /* 0x80429F84 */
    static s32 mCtrlPlrNo;

    /* 0x80429F88 */
    static u8 mActPlayerInfo;

    /* 0x80429F90 */
    static u16 m_star_time[CHARACTER_COUNT];

    /* 0x80429F98 */
    static u16 m_star_count[CHARACTER_COUNT];

    /* 0x80429FA0 */
    static s32 mScore;

    // This is some enum idk what it is
    /* 0x80429FA4 */
    static int mKinopioMode;

    /* 0x80429FA8 */
    static s32 mTimeUpPlayerNum;

    /* 0x80429FAC */
    static s32 mAllBalloon;

    /* 0x80429FB0 */
    static s32 mPauseEnableInfo;

    /* 0x80429FB4 */
    static s32 mPauseDisable;

    /* 0x80429FB8 */
    static s32 mStopTimerInfo;

    /* 0x80429FBC */
    static s32 mStopTimerInfoOld;

    /* 0x80429FC0 */
    static s32 mQuakeTrigger;

    /* 0x80429FC4 */
    static s32 mBgmState;

    /* 0x80429FC8 */
    static int mBonusNoCap;

    /* 0x80429FCC */
    static int mKinopioCarryCount;
};