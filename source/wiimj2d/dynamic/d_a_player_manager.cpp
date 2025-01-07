// d_a_player_manager.cpp
// NSMBW .text: 0x8005E9A0 - 0x800613B0

#include "d_a_player_manager.h"

#include <dynamic/d_a_player_demo_manager.h>
#include <dynamic/d_audio.h>
#include <dynamic/d_bases/d_s_stage.h>
#include <dynamic/d_bg_parameter.h>
#include <dynamic/d_course_data.h>
#include <dynamic/d_game_common.h>
#include <dynamic/d_info.h>
#include <dynamic/d_multi_manager.h>
#include <dynamic/d_next.h>
#include <dynamic/d_pause_manager.h>
#include <dynamic/d_player/d_a_player.h>
#include <dynamic/d_player/d_a_yoshi.h>
#include <dynamic/d_player/d_gamedisplay.h>
#include <dynamic/d_player_effect_mng.h>
#include <dynamic/d_player_model_manager.h>
#include <dynamic/d_quake.h>
#include <dynamic/d_score_manager.h>
#include <dynamic/d_stage_timer.h>
#include <framework/f_manager.h>
#include <framework/f_sound_id.h>
#include <machine/m_vec.h>
#include <revolution/os.h>
#include <revolution/os/OSLink.h>

const daPyMng_c::PlayerType_e daPyMng_c::DEFAULT_PLAYER_ORDER[CHARACTER_COUNT] = {
  PlayerType_e::TOADETTE,  PlayerType_e::LUIGI,   PlayerType_e::YELLOW_TOAD,
  PlayerType_e::BLUE_TOAD, PlayerType_e::MARIO,   PlayerType_e::PLAYER_5,
  PlayerType_e::PLAYER_6,  PlayerType_e::PLAYER_7
};

/* 0x80355110 */
fBaseID_e daPyMng_c::m_playerID[PLAYER_COUNT];

/* 0x80355120 */
fBaseID_e daPyMng_c::m_yoshiID[PLAYER_COUNT];

/* 0x80355130 */
s32 daPyMng_c::mCourseInList[PLAYER_COUNT];

/* 0x80355140 */
s32 daPyMng_c::m_yoshiFruit[PLAYER_COUNT];

/* 0x80355150 */
s32 daPyMng_c::mPlayerEntry[PLAYER_COUNT];

/* 0x80355160 */
// Index is player ID
daPyMng_c::PlayerType_e daPyMng_c::mPlayerType[PLAYER_COUNT] = {
  DEFAULT_PLAYER_ORDER[0], DEFAULT_PLAYER_ORDER[1], DEFAULT_PLAYER_ORDER[2],
  DEFAULT_PLAYER_ORDER[3], DEFAULT_PLAYER_ORDER[4], DEFAULT_PLAYER_ORDER[5],
  DEFAULT_PLAYER_ORDER[6], DEFAULT_PLAYER_ORDER[7]
};

/* 0x80355170 */
// Index is player type
s32 daPyMng_c::mPlayerMode[CHARACTER_COUNT];

/* 0x80355180 */
// Index is player type
s32 daPyMng_c::mCreateItem[CHARACTER_COUNT];

/* 0x80355190 */
// Index is player type
int daPyMng_c::mRest[CHARACTER_COUNT] = {5, 5, 5, 5, 5, 5, 5, 5};

/* 0x803551A0 */
// Index is player type
s32 daPyMng_c::mCoin[CHARACTER_COUNT];

/* 0x803551B0 */
s32 daPyMng_c::m_quakeTimer[CHARACTER_COUNT];

/* 0x803551C0 */
s32 daPyMng_c::m_quakeEffectFlag[CHARACTER_COUNT];

/* 0x803551E0 */
static daPyDemoMng_c mDemoManager;

[[address_data(0x80429F80)]]
int daPyMng_c::mNum;

[[address_data(0x80429F84)]]
s32 daPyMng_c::mCtrlPlrNo;

static_assert(PLAYER_COUNT <= 8, "Bitfield only supports 8 players");
[[address_data(0x80429F88)]]
u8 daPyMng_c::mActPlayerInfo;

/* 0x80429F90 */
u16 daPyMng_c::m_star_time[CHARACTER_COUNT];

/* 0x80429F98 */
u16 daPyMng_c::m_star_count[CHARACTER_COUNT];

[[address_data(0x80429FA0)]]
int daPyMng_c::mScore;

[[address_data(0x80429FA4)]]
int daPyMng_c::mKinopioMode;

[[address_data(0x80429FA8)]]
s32 daPyMng_c::mTimeUpPlayerNum;

[[address_data(0x80429FAC)]]
s32 daPyMng_c::mAllBalloon;

[[address_data(0x80429FB0)]]
s32 daPyMng_c::mPauseEnableInfo;

[[address_data(0x80429FB4)]]
s32 daPyMng_c::mPauseDisable;

[[address_data(0x80429FB8)]]
s32 daPyMng_c::mStopTimerInfo;

[[address_data(0x80429FBC)]]
s32 daPyMng_c::mStopTimerInfoOld;

[[address_data(0x80429FC0)]]
s32 daPyMng_c::mQuakeTrigger;

[[address_data(0x80429FC4)]]
s32 daPyMng_c::mBgmState;

[[address_data(0x80429FC8)]]
int daPyMng_c::mBonusNoCap;

[[address_data(0x80429FCC)]]
int daPyMng_c::mKinopioCarryCount;

// ---------
// Functions
// ---------

[[address(0x8005EA60)]]
void daPyMng_c::initGame()
{
    mActPlayerInfo |= 1;

    for (int i = 0; i < PLAYER_COUNT; i++) {
        mPlayerType[i] = DEFAULT_PLAYER_ORDER[i];
        mPlayerEntry[i] = 0;

        int playerIndex = int(DEFAULT_PLAYER_ORDER[i]);
        mPlayerMode[playerIndex] = 0;
        mCreateItem[playerIndex] = 0;
    }

    setDefaultParam();

    mBonusNoCap = 0;
    mKinopioCarryCount = 0;
}

[[address(0x8005EB10)]]
void daPyMng_c::initStage()
{
    checkCorrectCreateInfo();

    mNum = 0;
    mActPlayerInfo = 0;

    for (int i = 0; i < PLAYER_COUNT; i++) {
        setPlayer(i, nullptr);
        m_star_time[i] = 0;
        m_star_count[i] = 0;
    }

    for (int i = 0; i < PLAYER_COUNT; i++) {
        if (mPlayerEntry[i] != 0) {
            addNum(i);
        }
    }

    if (dScStage_c::getCourseIn() && dInfo_c::m_instance->m0xAF4 >= 0 && isOnePlayer() &&
        dInfo_c::m_instance->mCyuukan.mIsKinopioInChukan) {
        for (int i = 0; i < PLAYER_COUNT; i++) {
            if (mPlayerEntry[i] == 0) {
                initKinopioPlayer(0, i);
            }
        }
    }

    mTimeUpPlayerNum = 0;
    mAllBalloon = 0;
    mPauseEnableInfo = 0;
    mPauseDisable = 0;
    mStopTimerInfo = 0;
    mStopTimerInfoOld = 0;
    mQuakeTrigger = 0;

    for (int i = 0; i < CHARACTER_COUNT; i++) {
        m_quakeTimer[i] = 0;
        m_quakeEffectFlag[i] = 0;
    }

    mBgmState = 0;

    checkBonusNoCap();

    mKinopioCarryCount = 0;

    daPyDemoMng_c::mspInstance->initStage();
    dMultiMng_c::mspInstance->initStage();
}

[[address(0x8005ECE0)]]
void daPyMng_c::setDefaultParam()
{
    for (int i = 0; i < PLAYER_COUNT; i++) {
        int playerIndex = int(mPlayerType[i]);
        mRest[playerIndex] = 5;
        mCoin[playerIndex] = 0;
        m_playerID[i] = fBaseID_e::NULL;
        m_yoshiID[i] = fBaseID_e::NULL;
    }

    mScore = 0;
}

[[address(0x8005ED90)]]
mVec3_c daPyMng_c::getPlayerSetPos(u8 course, u8 gotoID);

[[address(0x8005EE90)]]
u8 daPyMng_c::getPlayerCreateAction();

[[address(0x8005EEE0)]]
bool daPyMng_c::createPlayer(int player, mVec3_c position, s32 gotoKind, bool faceLeft);

[[address(0x8005EF50)]]
void daPyMng_c::createCourseInit()
{
    dScStage_c* stage = dScStage_c::m_instance;
    mVec3_c playerSetPos = getPlayerSetPos(stage->mCourse, stage->mGoto);

    u8 entType = getPlayerCreateAction();

    OS_REPORT(
      "daPyMng_c::createCourseInit: Course(%d) Goto(%d) EntranceType(%d) Position(%f, %f, %f)\n",
      stage->mCourse, stage->mGoto, entType, playerSetPos.x, playerSetPos.y, playerSetPos.z
    );

    if (entType != 0 /* NORMAL */ && entType != 1 /* NORMAL1 */ && entType != 27 /* BOSS_STAND */) {
        // Handle any other entType values
        daPyDemoMng_c::mspInstance->genCourseInList();
        f32 dispCenter = dGameCom::getDispCenterX();
        for (int i = 0; i < PLAYER_COUNT; i++) {
            createPlayer(i, playerSetPos, entType, dispCenter < 0);
        }

        return;
    }

    // Handle NORMAL, NORMAL1, BOSS_STAND
    daPyDemoMng_c::mspInstance->init();
    decideCtrlPlrNo();

    if (!dScStage_c::m_isStaffCredit) {
        bool isAmbush;

        if (stage->m_isCourseIn && dInfo_c::m_instance->m0xAF4 >= 0) {
            playerSetPos = dInfo_c::m_instance->mCyuukan.mPlayerSetPos;
            isAmbush = dInfo_c::m_instance->mCyuukan.m0x14 & 1;
        } else {
            isAmbush = dCd_c::getFileP(stage->mCourse)->mpCourseInfo->mIsAmbush;
        }

        int spawnOrder[8] = {0, 1, 2, 3, 4, 5, 6, 7};

        if (dInfo_c::m_startGameInfo.screenType != dInfo_c::ScreenType_e::TITLE) {
            // Randomize the spawn order
            for (int i = 0; i < PLAYER_COUNT; i++) {
                int randomIndex = dGameCom::rndInt(PLAYER_COUNT);
                int temp = spawnOrder[i];
                spawnOrder[i] = spawnOrder[randomIndex];
                spawnOrder[randomIndex] = temp;
            }
        }

        int livePlayerCount = 0;
        for (int i = 0; i < PLAYER_COUNT; i++) {
            if (mPlayerEntry[i] != 0 && !isCreateBalloon(i)) {
                livePlayerCount++;
            }
        }

        f32 playerSetDist = 24.0f;

        if (PLAYER_COUNT > 4) {
            playerSetDist -= 2.0 * (PLAYER_COUNT - 4);
        }

        if (isAmbush) {
            playerSetPos.x -= playerSetDist / 2 * livePlayerCount;
        } else {
            playerSetPos.x += playerSetDist / 2 * livePlayerCount;
        }

        for (int i = 0; i < PLAYER_COUNT; i++) {
            if (spawnOrder[i] == -1) {
                continue;
            }

            bool result = createPlayer(spawnOrder[i], playerSetPos, entType, isAmbush);

            if (result && !isCreateBalloon(spawnOrder[i])) {
                if (isAmbush) {
                    playerSetPos.x += playerSetDist;
                } else {
                    playerSetPos.x -= playerSetDist;
                }
            }
        }
    } else {
        // Setup spawn for staff credits
        static_assert(
          PLAYER_COUNT <= 8, "Please update the staff credit positions for more than 8 players"
        );

        playerSetPos.x += 512 - 320;

        static const f32 l_STAFF_CREDIT_POS[8][2] = {
          {-192, -48},
          {192, -48},
          {-216, 0},
          {216, 0},

          // New positions
          {-168, -80},
          {168, -80},
          {-144, -80},
          {144, -80},
        };

        for (int i = 0; i < PLAYER_COUNT; i++) {
            if (mPlayerEntry[i] != 0) {
                mVec3_c pos = {
                  playerSetPos.x + l_STAFF_CREDIT_POS[i][0],
                  playerSetPos.y + l_STAFF_CREDIT_POS[i][1],
                  playerSetPos.z,
                };
                createPlayer(i, pos, 0, l_STAFF_CREDIT_POS[i][0] > 0);
            }
        }
    }
}

[[address(0x8005F570)]]
void daPyMng_c::initKinopioPlayer(int kinopioMode, int index)
{
    mActPlayerInfo |= 1 << index;
    mPlayerEntry[index] = 1;
    mCreateItem[int(mPlayerType[index])] = 8;
    mKinopioMode = kinopioMode;
}

[[address(0x8005F5C0)]]
void daPyMng_c::update()
{
    updateBGM();
    if (dGameDisplay_c* display = dScStage_c::getGameDisplay()) {
        display->updatePlayNum(mRest);
        display->setCoinNum(getCoinAll());
        display->setScore(mScore);
        display->setCollect();
    }

    for (int i = 0; i < PLAYER_COUNT; i++) {
        if (m_quakeTimer[i] != 0) {
            m_quakeTimer[i]--;
            if (m_quakeTimer[i] == 0) {
                m_quakeEffectFlag[i] = 0;
            }
        }
    }

    if (dNext_c::m_instance->mExitReq) {
        bool wait = false;

        for (int i = 0; i < PLAYER_COUNT; i++) {
            if (!isPlayerActive(i)) {
                continue;
            }

            if (daPlBase_c* player = getCtrlPlayer(i);
                player && !player->isStatus(100) && !player->isWaitFrameCountMax()) {
                wait = true;
            }
        }

        if (!wait) {
            dNext_c::m_instance->mTimer = 0;
        }
    }

    if (dQuake_c::m_instance->mFlags.off(0x38)) {
        mQuakeTrigger = 0;
    } else if (mQuakeTrigger == 0) {
        for (int i = 0; i < PLAYER_COUNT; i++) {
            daPlBase_c* player = getCtrlPlayer(i);
            if (player == nullptr) {
                continue;
            }

            if (dQuake_c::m_instance->mFlags.on(0x20)) {
                player->onStatus(139);
            } else if (dQuake_c::m_instance->mFlags.on(0x8) || m_quakeEffectFlag[i] == 0) {
                player->onStatus(140);
            }
        }

        mQuakeTrigger = 1;
    } else {
        mQuakeTrigger = 1;
    }

    PauseManager_c::m_instance->setPauseEnable(mPauseDisable == 0);

    if (mStopTimerInfo != mStopTimerInfoOld) {
        dStageTimer_c::m_instance->mPause = mStopTimerInfo != 0;
        mStopTimerInfoOld = mStopTimerInfo;
    }

    daPyDemoMng_c::mspInstance->update();
    dPyEffectMng_c::mspInstance->update();
}

[[address(0x8005F8C0)]]
void daPyMng_c::setPlayer(int index, dAcPy_c* player);

[[address(0x8005F900)]]
dAcPy_c* daPyMng_c::getPlayer(int index);

[[address(0x8005F920)]]
void daPyMng_c::decideCtrlPlrNo()
{
    for (int i = 0; i < PLAYER_COUNT; i++) {
        if (mActPlayerInfo & (1 << i)) {
            mCtrlPlrNo = i;
            return;
        }
    }
}

[[address(0x8005F990)]]
bool daPyMng_c::setYoshi(daPlBase_c* yoshi)
{
    if (yoshi == nullptr) {
        return false;
    }

    for (int i = 0; i < PLAYER_COUNT; i++) {
        if (m_yoshiID[i] == fBaseID_e::NULL) {
            m_yoshiID[i] = yoshi->mUniqueID;
            return true;
        }
    }
    return false;
}

[[address(0x8005FA00)]]
void daPyMng_c::releaseYoshi(daPlBase_c* yoshi)
{
    for (int i = 0; i < PLAYER_COUNT; i++) {
        if (m_yoshiID[i] == yoshi->mUniqueID) {
            m_yoshiID[i] = fBaseID_e::NULL;
            return;
        }
    }
}

[[address(0x8005FA60)]]
daYoshi_c* daPyMng_c::getYoshi(int index)
{
    for (int i = 0; i < PLAYER_COUNT; i++) {
        daYoshi_c* yoshi = static_cast<daYoshi_c*>(fManager_c::searchBaseByID(m_yoshiID[i]));
        if (yoshi != nullptr && *yoshi->getPlrNo() == index) {
            return yoshi;
        }
    }

    return nullptr;
}

[[address(0x8005FB00)]]
int daPyMng_c::getYoshiNum()
{
    int yoshiNum = 0;
    for (int i = 0; i < CHARACTER_COUNT; i++) {
        if (fManager_c::searchBaseByID(m_yoshiID[i]) != nullptr) {
            yoshiNum++;
        }
    }
    return yoshiNum;
}

[[address(0x8005FB90)]]
daPlBase_c* daPyMng_c::getCtrlPlayer(int index);

daPyMng_c::PlayerType_e daPyMng_c::getModelPlayerType(dPyMdlMng_c::ModelType_e modelType)
{
    int modelIndex = static_cast<int>(modelType);

    using PlayerTypeArray = PlayerType_e[];
    return PlayerTypeArray{
      PlayerType_e::MARIO,       PlayerType_e::LUIGI,     PlayerType_e::BLUE_TOAD,
      PlayerType_e::YELLOW_TOAD, PlayerType_e::BLUE_TOAD, PlayerType_e::LUIGI,
      PlayerType_e::TOADETTE,
    }[modelIndex];
}

dPyMdlMng_c::ModelType_e daPyMng_c::getPlayerTypeModelType(PlayerType_e playerType)
{
    int playerTypeInt = static_cast<int>(playerType);

    if (mCreateItem[playerTypeInt] & 8) {
        return dPyMdlMng_c::ModelType_e::MODEL_RED_TOAD;
    }

    using ModelTypeArray = dPyMdlMng_c::ModelType_e[];
    return ModelTypeArray{
      dPyMdlMng_c::ModelType_e::MODEL_MARIO,     dPyMdlMng_c::ModelType_e::MODEL_LUIGI,
      dPyMdlMng_c::ModelType_e::MODEL_BLUE_TOAD, dPyMdlMng_c::ModelType_e::MODEL_YELLOW_TOAD,
      dPyMdlMng_c::ModelType_e::MODEL_TOADETTE,  dPyMdlMng_c::ModelType_e::MODEL_RED_TOAD,
      dPyMdlMng_c::ModelType_e::MODEL_LUIGI,     dPyMdlMng_c::ModelType_e::MODEL_RED_TOAD,
    }[playerTypeInt];
}

[[address(0x8005FBE0)]]
dPyMdlMng_c::ModelType_e daPyMng_c::getCourseInPlayerModelType(u8 index)
{
    return getPlayerTypeModelType(mPlayerType[index]);
}

int daPyMng_c::getPlayerColorType(PlayerType_e playerType)
{
    return static_cast<int>(getModelPlayerType(getPlayerTypeModelType(playerType)));
}

[[address(0x8005FC70)]]
u8 daPyMng_c::getActScrollInfo()
{
    u8 info = 0;
    for (int i = 0; i < PLAYER_COUNT; i++) {
        if (mPlayerEntry[i] == 0) {
            continue;
        }

        dAcPy_c* player = getPlayer(i);
        if (player == nullptr || player->mScrollType != 1) {
            info |= 1 << i;
        }
    }
    return info;
}

[[address(0x8005FD20)]]
u8 daPyMng_c::getScrollNum()
{
    int scrollNum = 0;
    for (int i = 0; i < PLAYER_COUNT; i++) {
        if (mPlayerEntry[i] == 0) {
            continue;
        }

        dAcPy_c* player = getPlayer(i);
        if (player == nullptr || player->mScrollType != 1) {
            scrollNum++;
        }
    }
    return scrollNum;
}

[[address(0x8005FDB0)]]
bool daPyMng_c::addNum(int num);

[[address(0x8005FEB0)]]
void daPyMng_c::addNum()
{
    if (mNum < PLAYER_COUNT) {
        mNum++;
    }
}

[[address(0x8005FEF0)]]
int daPyMng_c::getNumInGame()
{
    int inGameCount = 0;
    for (int i = 0; i < CHARACTER_COUNT; i++) {
        if (mPlayerEntry[i] != 0 && mRest[int(mPlayerType[i])] > 0) {
            inGameCount++;
        }
    }
    return inGameCount;
}

[[address(0x8005FFB0)]]
int daPyMng_c::getEntryNum()
{
    int entryNum = 0;
    for (int i = 0; i < PLAYER_COUNT; i++) {
        if (mPlayerEntry[i] != 0) {
            entryNum++;
        }
    }
    return entryNum;
}

[[address(0x80060110)]]
int daPyMng_c::findPlayerWithType(PlayerType_e playerType)
{
    for (int i = 0; i < CHARACTER_COUNT; i++) {
        if (mPlayerType[i] == playerType) {
            return i;
        }
    }
    return -1;
}

[[address(0x80060170)]]
bool daPyMng_c::getIsItemKinopio(int* ownedPlayer);

[[address(0x80060200)]]
int daPyMng_c::getCoinAll()
{
    int totalCoins = 0;
    for (int i = 0; i < CHARACTER_COUNT; i++) {
        totalCoins += mCoin[i];
    }
    return totalCoins;
}

[[address(0x80060250)]]
void daPyMng_c::incCoin(int player)
{
    getIsItemKinopio(&player);
    dMultiMng_c::mspInstance->incCoin(player);

    if (getCoinAll() < MAX_COINS) {
        mCoin[player]++;
        return;
    }

    int noEntry = getEntryNum() <= 0;
    if (!noEntry) {
        dBgParameter_c* bgParam = dBgParameter_c::ms_Instance_p;
        nw4r::math::VEC2 pos = dAudio::cvtSndObjctPos({
          bgParam->mScreenLeft + bgParam->mScreenWidth / 2,
          bgParam->mScreenTop - bgParam->mScreenHeight / 2,
        });

        u32 remoteMask = 0;
        for (int i = 0; i < PLAYER_COUNT; i++) {
            if (mPlayerEntry[i] != 0) {
                remoteMask |= dAudio::getRemotePlayer(i);
            }
        }

        dAudio::SndObjctCmnMap_c* objMap = dAudio::g_pSndObjMap;
        objMap->startSound(SE_SYS_100COIN_ONE_UP, pos, remoteMask);
        objMap->startSound(SE_SYS_100COIN_ONE_UP_RC, pos, remoteMask);
    }

    for (int i = 0; i < PLAYER_COUNT; i++) {
        if (mPlayerEntry[i] == 0) {
            continue;
        }

        dAcPy_c* player = getPlayer(i);
        if (player == nullptr || player->isStatus(4)) {
            addRest(i, 1, !noEntry);
        } else {
            dScoreMng_c::m_instance->UNDEF_800E25A0(8, i, noEntry);
        }
    }

    for (int i = 0; i < PLAYER_COUNT; i++) {
        mCoin[static_cast<int>(mPlayerType[i])] = 0;
    }
}

[[address(0x80060460)]]
void daPyMng_c::addRest(int player, int num, bool playEffect);

[[address(0x80060590)]]
void daPyMng_c::incRestAll(bool playEffect)
{
    for (int i = 0; i < PLAYER_COUNT; i++) {
        if (mPlayerEntry[i] != 0) {
            addRest(i, 1, playEffect);
        }
    }
}

// TODO (not that important)
[[address(0x80060690)]]
void daPyMng_c::addScore(int score, int player);

// TODO (not that important)
[[address(0x80060750)]]
void daPyMng_c::stopStarBGM();

// TODO (not that important)
[[address(0x80060860)]]
void daPyMng_c::stopYoshiBGM();

/* 0x800608E0 @unofficial */
[[address(0x800608E0)]]
void daPyMng_c::updateBGM();

[[address(0x80060970)]]
void daPyMng_c::executeLastPlayer()
{
    for (int i = 0; i < PLAYER_COUNT; i++) {
        daYoshi_c* yoshi = static_cast<daYoshi_c*>(fManager_c::searchBaseByID(m_yoshiID[i]));
        if (yoshi != nullptr) {
            yoshi->executeLastPlayer();
        }
    }

    for (int i = 0; i < PLAYER_COUNT; i++) {
        dAcPy_c* player = getPlayer(i);
        if (player != nullptr) {
            player->executeLastPlayer();
        }
    }
}

[[address(0x80060A10)]]
void daPyMng_c::executeLastAll()
{
    for (int i = 0; i < PLAYER_COUNT; i++) {
        daYoshi_c* yoshi = static_cast<daYoshi_c*>(fManager_c::searchBaseByID(m_yoshiID[i]));
        if (yoshi != nullptr) {
            yoshi->executeLastAll();
        }
    }

    for (int i = 0; i < PLAYER_COUNT; i++) {
        dAcPy_c* player = getPlayer(i);
        if (player != nullptr) {
            player->executeLastAll();
        }
    }
}

// TODO (not important)
[[address(0x80060AB0)]]
void daPyMng_c::deleteCullingYoshi();

[[gnu::used]]
int l_QUAKE_SOUND_LIST[] = {
  SE_PLY_HPDP_SPECIAL_TWO,
  SE_PLY_HPDP_SPECIAL_THREE,
  SE_PLY_HPDP_SPECIAL_FOUR,
};

[[address(0x80060C10)]]
void daPyMng_c::setHipAttackQuake(int param1, u8 param2) ASM_METHOD(
  // clang-format off
/* 80060C10 9421FFF0 */  stwu     r1, -16(r1);
/* 80060C14 7C0802A6 */  mflr     r0;
/* 80060C18 2C04FFFF */  cmpwi    r4, -1;
/* 80060C1C 3D008035 */  lis      r8, m_playerID__9daPyMng_c@ha;
/* 80060C20 90010014 */  stw      r0, 20(r1);
/* 80060C24 39085110 */  addi     r8, r8, m_playerID__9daPyMng_c@l;
/* 80060C28 41820178 */  beq-     UNDEF_80060da0;
/* 80060C2C 2C030002 */  cmpwi    r3, 2;
/* 80060C30 40820020 */  bne-     UNDEF_80060c50;
/* 80060C34 806DA968 */  lwz      r3, -22168(r13);
/* 80060C38 7C840774 */  extsb    r4, r4;
/* 80060C3C 38A00007 */  li       r5, 7;
/* 80060C40 38C00000 */  li       r6, 0;
/* 80060C44 38E00000 */  li       r7, 0;
/* 80060C48 48078059 */  bl       UNDEF_800d8ca0;
/* 80060C4C 48000154 */  b        UNDEF_80060da0;
UNDEF_80060c50:;
/* 80060C50 880DAB7F */  lbz      r0, -21633(r13);
/* 80060C54 548915BA */  clrlslwi r9, r4, 24, 2;
                         lis      r6, m_quakeTimer__9daPyMng_c@ha;
/* 80060C58          */  addi     r6, r6, m_quakeTimer__9daPyMng_c@l;
/* 80060C5C 38E00005 */  li       r7, 5;
/* 80060C60 2C000000 */  cmpwi    r0, 0;
                         lis      r5, m_quakeEffectFlag__9daPyMng_c@ha;
/* 80060C64          */  addi     r5, r5, m_quakeEffectFlag__9daPyMng_c@l;
/* 80060C68 38000000 */  li       r0, 0;
/* 80060C6C 7CE6492E */  stwx     r7, r6, r9;
/* 80060C70 39400000 */  li       r10, 0;
/* 80060C74 7C05492E */  stwx     r0, r5, r9;
/* 80060C78 40820084 */  bne-     UNDEF_80060cfc;

                         li       r11, 0;
L_daPyMng_c_setHipAttackQuake_LoopStart:;
                         cmpw     r11, r4;
                         beq-     L_daPyMng_c_setHipAttackQuake_LoopCond;

                         lwz      r0, 0(r6);
                         cmpwi    r0, 0;
                         beq-     L_daPyMng_c_setHipAttackQuake_LoopCond;

                         stw      r7, 0(r6);
                         addi     r10, r10, 1;
                        
L_daPyMng_c_setHipAttackQuake_LoopCond:;
                         addi     r6, r6, 4;
                         addi     r11, r11, 1;
                         cmpwi    r11, PLAYER_COUNT;
                         blt+     L_daPyMng_c_setHipAttackQuake_LoopStart;

UNDEF_80060cfc:;
/* 80060CFC 2C0A0000 */  cmpwi    r10, 0;
/* 80060D00 41820060 */  beq-     UNDEF_80060d60;

                         subic.   r0, r10, 1;
                         blt-     UNDEF_80060d58;
                         cmpwi    r0, 2;
                         blt-     L_daPyMng_c_setHipAttackQuake_ValidNumber;
                         li       r0, 2;
L_daPyMng_c_setHipAttackQuake_ValidNumber:;

/* 80060D40 5400103A */  slwi     r0, r0, 2;
                         lis      r4, l_QUAKE_SOUND_LIST@ha;
/* 80060D44          */  addi     r4, r4, l_QUAKE_SOUND_LIST@l;
/* 80060D48 806DADE8 */  lwz      r3, -21016(r13);
/* 80060D4C 38A00001 */  li       r5, 1;
/* 80060D50 7C84002E */  lwzx     r4, r4, r0;
/* 80060D54 4813475D */  bl       UNDEF_801954b0;
UNDEF_80060d58:;
/* 80060D58 48000059 */  bl       UNDEF_80060db0;
/* 80060D5C 48000044 */  b        UNDEF_80060da0;
UNDEF_80060d60:;
/* 80060D60 2C030001 */  cmpwi    r3, 1;
/* 80060D64 40820024 */  bne-     UNDEF_80060d88;
/* 80060D68 806DA968 */  lwz      r3, -22168(r13);
/* 80060D6C 7C840774 */  extsb    r4, r4;
/* 80060D70 38A00003 */  li       r5, 3;
/* 80060D74 38C00003 */  li       r6, 3;
/* 80060D78 38E00000 */  li       r7, 0;
/* 80060D7C 39000000 */  li       r8, 0;
/* 80060D80 48077E71 */  bl       UNDEF_800d8bf0;
/* 80060D84 4800001C */  b        UNDEF_80060da0;
UNDEF_80060d88:;
/* 80060D88 806DA968 */  lwz      r3, -22168(r13);
/* 80060D8C 7C840774 */  extsb    r4, r4;
/* 80060D90 38A00004 */  li       r5, 4;
/* 80060D94 38C00000 */  li       r6, 0;
/* 80060D98 38E00000 */  li       r7, 0;
/* 80060D9C 48077F05 */  bl       UNDEF_800d8ca0;
UNDEF_80060da0:;
/* 80060DA0 80010014 */  lwz      r0, 20(r1);
/* 80060DA4 7C0803A6 */  mtlr     r0;
/* 80060DA8 38210010 */  addi     r1, r1, 16;
/* 80060DAC 4E800020 */  blr;
  // clang-format on
);

// TODO (not important?)
[[address(0x80060DB0)]]
void daPyMng_c::FUN_0x80060DB0() ASM_METHOD(
  // clang-format off
/* 80060DB0 9421FFB0 */  stwu     r1, -80(r1);
/* 80060DB4 7C0802A6 */  mflr     r0;
/* 80060DB8 90010054 */  stw      r0, 84(r1);
/* 80060DBC 39610040 */  addi     r11, r1, 64;
/* 80060DC0 DBE10040 */  stfd     f31, 64(r1);
/* 80060DC4 F3E10048 */  .long    0xF3E10048; // psq_st   f31, 72(r1), 0, 0;
/* 80060DC8 4827C295 */  bl       UNDEF_802dd05c;
/* 80060DCC 806DAE08 */  lwz      r3, -20984(r13);
/* 80060DD0 4813B851 */  bl       UNDEF_8019c620; // onPowerImpact__11SndSceneMgrFv
/* 80060DD4 3F808035 */  lis      r28, m_quakeTimer__9daPyMng_c@ha;
/* 80060DD8 3F608035 */  lis      r27, m_quakeEffectFlag__9daPyMng_c@ha;
/* 80060DDC C3E28A1C */  lfs      f31, -30180(r2);
/* 80060DE0 3B9C51B0 */  addi     r28, r28, m_quakeTimer__9daPyMng_c@l;
/* 80060DE4 3B7B51C0 */  addi     r27, r27, m_quakeEffectFlag__9daPyMng_c@l;
/* 80060DE8 3B400000 */  li       r26, 0;
/* 80060DEC 3BA00001 */  li       r29, 1;
/* 80060DF0 3FC08031 */  lis      r30, UNDEF_80309a28@ha;
/* 80060DF4 3FE08031 */  lis      r31, UNDEF_80309a3c@ha;
UNDEF_80060df8:;
/* 80060DF8 801C0000 */  lwz      r0, 0(r28);
/* 80060DFC 2C000000 */  cmpwi    r0, 0;
/* 80060E00 418200B4 */  beq-     UNDEF_80060eb4;
/* 80060E04 801B0000 */  lwz      r0, 0(r27);
/* 80060E08 2C000000 */  cmpwi    r0, 0;
/* 80060E0C 408200A8 */  bne-     UNDEF_80060eb4;
/* 80060E10 93BB0000 */  stw      r29, 0(r27);
/* 80060E14 7F43D378 */  mr       r3, r26;
/* 80060E18 4BFFEAE9 */  bl       getPlayer__9daPyMng_cFi;
/* 80060E1C 2C030000 */  cmpwi    r3, 0;
/* 80060E20 7C791B78 */  mr       r25, r3;
/* 80060E24 41820090 */  beq-     UNDEF_80060eb4;
/* 80060E28 3880004B */  li       r4, 75;
/* 80060E2C 4BFF5EC5 */  bl       isStatus__10daPlBase_cFi;
/* 80060E30 2C030000 */  cmpwi    r3, 0;
/* 80060E34 41820010 */  beq-     UNDEF_80060e44;
/* 80060E38 7F23CB78 */  mr       r3, r25;
/* 80060E3C 480D8C55 */  bl       UNDEF_80139a90; // getRideYoshi__7dAcPy_cFv
/* 80060E40 7C791B78 */  mr       r25, r3;
UNDEF_80060e44:;
/* 80060E44 2C190000 */  cmpwi    r25, 0;
/* 80060E48 4182006C */  beq-     UNDEF_80060eb4;
/* 80060E4C C01900AC */  lfs      f0, 172(r25);
/* 80060E50 387E9A28 */  addi     r3, r30, UNDEF_80309a28@l;
/* 80060E54 D0010008 */  stfs     f0, 8(r1);
/* 80060E58 38A10008 */  addi     r5, r1, 8;
/* 80060E5C 38800000 */  li       r4, 0;
/* 80060E60 38C00000 */  li       r6, 0;
/* 80060E64 C01900B0 */  lfs      f0, 176(r25);
/* 80060E68 38E00000 */  li       r7, 0;
/* 80060E6C D001000C */  stfs     f0, 12(r1);
/* 80060E70 C01900B4 */  lfs      f0, 180(r25);
/* 80060E74 D0010010 */  stfs     f0, 16(r1);
/* 80060E78 4810BB59 */  bl       UNDEF_8016c9d0; // createEffect__3mEfFPCcUlPC7mVec3_cPC7mAng3_cPC7mVec3_c
/* 80060E7C D3E10010 */  stfs     f31, 16(r1);
/* 80060E80 387F9A3C */  addi     r3, r31, UNDEF_80309a3c@l;
/* 80060E84 38A10008 */  addi     r5, r1, 8;
/* 80060E88 38800000 */  li       r4, 0;
/* 80060E8C 38C00000 */  li       r6, 0;
/* 80060E90 38E00000 */  li       r7, 0;
/* 80060E94 4810BB3D */  bl       UNDEF_8016c9d0; // createEffect__3mEfFPCcUlPC7mVec3_cPC7mAng3_cPC7mVec3_c
/* 80060E98 806DA968 */  lwz      r3, -22168(r13);
/* 80060E9C 7F440774 */  extsb    r4, r26;
/* 80060EA0 38A00003 */  li       r5, 3;
/* 80060EA4 38C00003 */  li       r6, 3;
/* 80060EA8 38E00012 */  li       r7, 18;
/* 80060EAC 39000000 */  li       r8, 0;
/* 80060EB0 48077D41 */  bl       UNDEF_800d8bf0;
UNDEF_80060eb4:;
/* 80060EB4 3B5A0001 */  addi     r26, r26, 1;
/* 80060EB8 3B7B0004 */  addi     r27, r27, 4;
/* 80060EBC 2C1A0004 */  cmpwi    r26, PLAYER_COUNT;
/* 80060EC0 3B9C0004 */  addi     r28, r28, 4;
/* 80060EC4 4180FF34 */  blt+     UNDEF_80060df8;
/* 80060EC8 39610040 */  addi     r11, r1, 64;
/* 80060ECC E3E10048 */  .long    0xE3E10048; // psq_l    f31, 72(r1), 0, 0;
/* 80060ED0 CBE10040 */  lfd      f31, 64(r1);
/* 80060ED4 4827C1D5 */  bl       UNDEF_802dd0a8;
/* 80060ED8 80010054 */  lwz      r0, 84(r1);
/* 80060EDC 7C0803A6 */  mtlr     r0;
/* 80060EE0 38210050 */  addi     r1, r1, 80;
/* 80060EE4 4E800020 */  blr;
  // clang-format on
);

[[address(0x80060EF0)]]
void daPyMng_c::checkBonusNoCap()
{
    mBonusNoCap = mRest[int(PlayerType_e::MARIO)] >= MAX_LIVES;
}

// TODO
[[address(0x80060F20)]]
void daPyMng_c::initYoshiPriority();

// TODO
[[address(0x80060FE0)]]
void daPyMng_c::setYoshiPriority();

[[address(0x80061110)]]
bool daPyMng_c::isCreateBalloon(int index)
{
    int playerType = int(mPlayerType[index]);

    return mCreateItem[playerType] & 0x4 || mRest[playerType] <= 0;
}

[[address(0x80061160)]]
void daPyMng_c::checkCorrectCreateInfo()
{
    for (int i = 0; i < CHARACTER_COUNT; i++) {
        if (mPlayerType[i] >= PlayerType_e::COUNT || mPlayerType[i] < PlayerType_e::MARIO) {
            mPlayerType[i] = PlayerType_e::MARIO;
        }

        int playerType = int(mPlayerType[i]);

        if (mPlayerMode[playerType] > POWERUP_COUNT || mPlayerMode[playerType] < 0) {
            mPlayerMode[playerType] = 0;
        }

        if (mRest[playerType] > MAX_LIVES || mRest[playerType] < 0) {
            mRest[playerType] = 5;
        }
    }

    if (int coinCount = getCoinAll(); coinCount < 0 || coinCount > MAX_COINS) {
        for (int i = 0; i < CHARACTER_COUNT; i++) {
            mCoin[i] = 0;
        }
    }

    if (mScore > MAX_SCORE) {
        mScore = MAX_SCORE;
    }
}

PATCH_REFERENCES(
  daPyMng_c::m_playerID,
  {
    {0x8005EA6A, R_PPC_ADDR16_HA}, {0x8005EA76, R_PPC_ADDR16_LO}, {0x8005EB26, R_PPC_ADDR16_HA},
    {0x8005EB2A, R_PPC_ADDR16_LO}, {0x8005ECE6, R_PPC_ADDR16_HA}, {0x8005ECEA, R_PPC_ADDR16_LO},
    {0x8005F572, R_PPC_ADDR16_HA}, {0x8005F57A, R_PPC_ADDR16_LO}, {0x8005F5D6, R_PPC_ADDR16_HA},
    {0x8005F5DA, R_PPC_ADDR16_LO}, {0x8005F8CA, R_PPC_ADDR16_HA}, {0x8005F8D2, R_PPC_ADDR16_LO},
    {0x8005F8E2, R_PPC_ADDR16_HA}, {0x8005F8EA, R_PPC_ADDR16_LO}, {0x8005F902, R_PPC_ADDR16_HA},
    {0x8005F90A, R_PPC_ADDR16_LO}, {0x8005FEF2, R_PPC_ADDR16_HA}, {0x8005FEFA, R_PPC_ADDR16_LO},
    {0x8006026A, R_PPC_ADDR16_HA}, {0x8006026E, R_PPC_ADDR16_LO}, {0x80060C1E, R_PPC_ADDR16_HA},
    {0x80060C26, R_PPC_ADDR16_LO}, {0x80061112, R_PPC_ADDR16_HA}, {0x8006111A, R_PPC_ADDR16_LO},
    {0x80061182, R_PPC_ADDR16_HA}, {0x80061186, R_PPC_ADDR16_LO}, {0x80061322, R_PPC_ADDR16_HA},
    {0x80061326, R_PPC_ADDR16_LO},
  }
);

PATCH_REFERENCES(
  daPyMng_c::m_yoshiID,
  {
    {0x8005F9A2, R_PPC_ADDR16_HA}, {0x8005F9AA, R_PPC_ADDR16_LO}, {0x8005F9C6, R_PPC_ADDR16_HA},
    {0x8005F9D6, R_PPC_ADDR16_LO}, {0x8005FA0A, R_PPC_ADDR16_HA}, {0x8005FA12, R_PPC_ADDR16_LO},
    {0x8005FA32, R_PPC_ADDR16_HA}, {0x8005FA3A, R_PPC_ADDR16_LO}, {0x8005FA72, R_PPC_ADDR16_HA},
    {0x8005FA76, R_PPC_ADDR16_LO}, {0x8005FB12, R_PPC_ADDR16_HA}, {0x8005FB16, R_PPC_ADDR16_LO},
    {0x8005FB72, R_PPC_ADDR16_HA}, {0x8005FB7A, R_PPC_ADDR16_LO}, {0x80060982, R_PPC_ADDR16_HA},
    {0x80060986, R_PPC_ADDR16_LO}, {0x80060A22, R_PPC_ADDR16_HA}, {0x80060A26, R_PPC_ADDR16_LO},
    {0x80060AD2, R_PPC_ADDR16_HA}, {0x80060AD6, R_PPC_ADDR16_LO}, {0x80060F3A, R_PPC_ADDR16_HA},
    {0x80060F46, R_PPC_ADDR16_LO}, {0x80060FFA, R_PPC_ADDR16_HA}, {0x80060FFE, R_PPC_ADDR16_LO},
  }
);

PATCH_REFERENCES(
  daPyMng_c::mCourseInList,
  {
    {0x8005D656, R_PPC_ADDR16_HA},
    {0x8005D65E, R_PPC_ADDR16_LO},
    {0x8005D662, R_PPC_ADDR16_LO},
    {0x800601E2, R_PPC_ADDR16_HA},
    {0x800601EA, R_PPC_ADDR16_LO},
  }
);

PATCH_REFERENCES(
  daPyMng_c::m_yoshiFruit,
  {
    {0x8005FC22, R_PPC_ADDR16_HA},
    {0x8005FC32, R_PPC_ADDR16_LO},
    {0x8005FC52, R_PPC_ADDR16_HA},
    {0x8005FC5A, R_PPC_ADDR16_LO},
  }
);

PATCH_REFERENCES(
  daPyMng_c::mPlayerEntry,
  {
    {0x8005D31A, R_PPC_ADDR16_HA}, {0x8005D32E, R_PPC_ADDR16_LO}, {0x8005EEEA, R_PPC_ADDR16_HA},
    {0x8005EEF6, R_PPC_ADDR16_LO}, {0x8005F38A, R_PPC_ADDR16_HA}, {0x8005F392, R_PPC_ADDR16_LO},
    {0x8005FC8A, R_PPC_ADDR16_HA}, {0x8005FC8E, R_PPC_ADDR16_LO}, {0x8005FD32, R_PPC_ADDR16_HA},
    {0x8005FD36, R_PPC_ADDR16_LO}, {0x8005FFB6, R_PPC_ADDR16_LO}, {0x800605A2, R_PPC_ADDR16_HA},
    {0x800605A6, R_PPC_ADDR16_LO}, {0x800BB96A, R_PPC_ADDR16_HA}, {0x800BB99E, R_PPC_ADDR16_LO},
    {0x80101AF2, R_PPC_ADDR16_LO}, {0x8013D826, R_PPC_ADDR16_LO}, {0x80144762, R_PPC_ADDR16_HA},
    {0x8014476E, R_PPC_ADDR16_LO}, {0x80144E0E, R_PPC_ADDR16_HA}, {0x80144E2A, R_PPC_ADDR16_LO},
    {0x801586E2, R_PPC_ADDR16_HA}, {0x8015870A, R_PPC_ADDR16_LO}, {0x8090CE32, R_PPC_ADDR16_HA},
    {0x8090CE56, R_PPC_ADDR16_LO}, {0x8091AC92, R_PPC_ADDR16_HA}, {0x8091ACA6, R_PPC_ADDR16_LO},
    {0x8091F786, R_PPC_ADDR16_HA}, {0x8091F7A2, R_PPC_ADDR16_LO}, {0x8091FE66, R_PPC_ADDR16_HA},
    {0x8091FE6E, R_PPC_ADDR16_LO}, {0x8091FE9E, R_PPC_ADDR16_LO}, {0x8091FEDA, R_PPC_ADDR16_HA},
    {0x8091FEF2, R_PPC_ADDR16_LO}, {0x80924EC6, R_PPC_ADDR16_LO}, {0x8092542A, R_PPC_ADDR16_HA},
    {0x8092545A, R_PPC_ADDR16_LO}, {0x80B6C712, R_PPC_ADDR16_HA}, {0x80B6C722, R_PPC_ADDR16_LO},
    {0x80B6C932, R_PPC_ADDR16_HA}, {0x80B6C93A, R_PPC_ADDR16_LO}, {0x80B6CE56, R_PPC_ADDR16_LO},
    {0x80B6CFBE, R_PPC_ADDR16_HA}, {0x80B6CFC6, R_PPC_ADDR16_LO},
  }
);

PATCH_REFERENCES(
  daPyMng_c::mPlayerType,
  {
    {0x8001B7E2, R_PPC_ADDR16_HA}, {0x8001B7F2, R_PPC_ADDR16_LO}, {0x8001CD52, R_PPC_ADDR16_HA},
    {0x8001CD5A, R_PPC_ADDR16_LO}, {0x8005D31E, R_PPC_ADDR16_HA}, {0x8005D336, R_PPC_ADDR16_LO},
    {0x8005FBE2, R_PPC_ADDR16_HA}, {0x8005FBEE, R_PPC_ADDR16_LO}, {0x80060116, R_PPC_ADDR16_LO},
    {0x80060202, R_PPC_ADDR16_HA}, {0x8006020A, R_PPC_ADDR16_LO}, {0x8006020E, R_PPC_ADDR16_LO},
    {0x8006052A, R_PPC_ADDR16_HA}, {0x8006053A, R_PPC_ADDR16_LO}, {0x80060636, R_PPC_ADDR16_HA},
    {0x80060642, R_PPC_ADDR16_LO}, {0x8008EF42, R_PPC_ADDR16_HA}, {0x8008EF4E, R_PPC_ADDR16_LO},
    {0x800B1CD6, R_PPC_ADDR16_HA}, {0x800B1CDE, R_PPC_ADDR16_LO}, {0x800B34E6, R_PPC_ADDR16_HA},
    {0x800B34EE, R_PPC_ADDR16_LO}, {0x800B3522, R_PPC_ADDR16_HA}, {0x800B352A, R_PPC_ADDR16_LO},
    {0x800B3566, R_PPC_ADDR16_HA}, {0x800B356E, R_PPC_ADDR16_LO}, {0x800B35E6, R_PPC_ADDR16_HA},
    {0x800B35EE, R_PPC_ADDR16_LO}, {0x800B5346, R_PPC_ADDR16_LO}, {0x800BB182, R_PPC_ADDR16_HA},
    {0x800BB18A, R_PPC_ADDR16_LO}, {0x800BB19E, R_PPC_ADDR16_LO}, {0x800BB95A, R_PPC_ADDR16_HA},
    {0x800BB99A, R_PPC_ADDR16_LO}, {0x800D0C8A, R_PPC_ADDR16_HA}, {0x800D0C9A, R_PPC_ADDR16_LO},
    {0x800E17B6, R_PPC_ADDR16_HA}, {0x800E17CA, R_PPC_ADDR16_LO}, {0x800E196A, R_PPC_ADDR16_HA},
    {0x800E1982, R_PPC_ADDR16_LO}, {0x800E2556, R_PPC_ADDR16_HA}, {0x800E255E, R_PPC_ADDR16_LO},
    {0x801011A2, R_PPC_ADDR16_HA}, {0x801011AA, R_PPC_ADDR16_LO}, {0x801023FE, R_PPC_ADDR16_HA},
    {0x80102406, R_PPC_ADDR16_LO}, {0x8010B74E, R_PPC_ADDR16_HA}, {0x8010B756, R_PPC_ADDR16_LO},
    {0x8010DA36, R_PPC_ADDR16_HA}, {0x8010DA3E, R_PPC_ADDR16_LO}, {0x8010DAE6, R_PPC_ADDR16_HA},
    {0x8010DAEE, R_PPC_ADDR16_LO}, {0x8010DB96, R_PPC_ADDR16_HA}, {0x8010DB9E, R_PPC_ADDR16_LO},
    {0x80138896, R_PPC_ADDR16_HA}, {0x801388A6, R_PPC_ADDR16_LO}, {0x8013D82A, R_PPC_ADDR16_HA},
    {0x8013D83A, R_PPC_ADDR16_LO}, {0x80140FA2, R_PPC_ADDR16_HA}, {0x80140FAE, R_PPC_ADDR16_LO},
    {0x801446F6, R_PPC_ADDR16_HA}, {0x8014470A, R_PPC_ADDR16_LO}, {0x80144DCE, R_PPC_ADDR16_HA},
    {0x80144DDE, R_PPC_ADDR16_LO}, {0x80144E0A, R_PPC_ADDR16_HA}, {0x80144E22, R_PPC_ADDR16_LO},
    {0x8014503A, R_PPC_ADDR16_HA}, {0x80145046, R_PPC_ADDR16_LO}, {0x8076FE66, R_PPC_ADDR16_HA},
    {0x8076FE72, R_PPC_ADDR16_LO}, {0x80771192, R_PPC_ADDR16_HA}, {0x8077119A, R_PPC_ADDR16_LO},
    {0x807714CE, R_PPC_ADDR16_HA}, {0x807714E2, R_PPC_ADDR16_LO}, {0x80777EE6, R_PPC_ADDR16_HA},
    {0x80777EFE, R_PPC_ADDR16_LO}, {0x80788FDA, R_PPC_ADDR16_HA}, {0x80788FE2, R_PPC_ADDR16_LO},
    {0x80788FE6, R_PPC_ADDR16_LO}, {0x80789082, R_PPC_ADDR16_HA}, {0x807890BE, R_PPC_ADDR16_LO},
    {0x8078C2A2, R_PPC_ADDR16_HA}, {0x8078C2AE, R_PPC_ADDR16_LO}, {0x8078C40E, R_PPC_ADDR16_HA},
    {0x8078C416, R_PPC_ADDR16_LO}, {0x8078CCC6, R_PPC_ADDR16_HA}, {0x8078CCCE, R_PPC_ADDR16_LO},
    {0x8078CE3A, R_PPC_ADDR16_HA}, {0x8078CE42, R_PPC_ADDR16_LO}, {0x8079A002, R_PPC_ADDR16_HA},
    {0x8079A00A, R_PPC_ADDR16_LO}, {0x8079A00E, R_PPC_ADDR16_LO}, {0x8079A056, R_PPC_ADDR16_LO},
    {0x807A0BFA, R_PPC_ADDR16_HA}, {0x807A0C02, R_PPC_ADDR16_LO}, {0x807A0C6E, R_PPC_ADDR16_HA},
    {0x807A0C7A, R_PPC_ADDR16_LO}, {0x807A0DFE, R_PPC_ADDR16_LO}, {0x807A0EAE, R_PPC_ADDR16_HA},
    {0x807A0ECA, R_PPC_ADDR16_LO}, {0x807A1EEA, R_PPC_ADDR16_HA}, {0x807A1F02, R_PPC_ADDR16_LO},
    {0x807A53CE, R_PPC_ADDR16_HA}, {0x807A53DE, R_PPC_ADDR16_LO}, {0x807A7FFA, R_PPC_ADDR16_HA},
    {0x807A8006, R_PPC_ADDR16_LO}, {0x807AA146, R_PPC_ADDR16_HA}, {0x807AA14E, R_PPC_ADDR16_LO},
    {0x807AA3F2, R_PPC_ADDR16_HA}, {0x807AA3FA, R_PPC_ADDR16_LO}, {0x807AE142, R_PPC_ADDR16_HA},
    {0x807AE14A, R_PPC_ADDR16_LO}, {0x807AE5D2, R_PPC_ADDR16_HA}, {0x807AE5DA, R_PPC_ADDR16_LO},
    {0x807AFBF2, R_PPC_ADDR16_HA}, {0x807AFC12, R_PPC_ADDR16_LO}, {0x807B00CE, R_PPC_ADDR16_HA},
    {0x807B00DA, R_PPC_ADDR16_LO}, {0x807B01CA, R_PPC_ADDR16_HA}, {0x807B01E2, R_PPC_ADDR16_LO},
    {0x807B070A, R_PPC_ADDR16_HA}, {0x807B0712, R_PPC_ADDR16_LO}, {0x807B072E, R_PPC_ADDR16_HA},
    {0x807B073E, R_PPC_ADDR16_LO}, {0x807B07BA, R_PPC_ADDR16_HA}, {0x807B07CA, R_PPC_ADDR16_LO},
    {0x807B09F2, R_PPC_ADDR16_HA}, {0x807B0A02, R_PPC_ADDR16_LO}, {0x807B13CA, R_PPC_ADDR16_HA},
    {0x807B13D6, R_PPC_ADDR16_LO}, {0x808EB7DA, R_PPC_ADDR16_HA}, {0x808EB7E6, R_PPC_ADDR16_LO},
    {0x80902B4E, R_PPC_ADDR16_HA}, {0x80902B6A, R_PPC_ADDR16_LO}, {0x80903022, R_PPC_ADDR16_HA},
    {0x8090302A, R_PPC_ADDR16_LO}, {0x809093D6, R_PPC_ADDR16_HA}, {0x809093DE, R_PPC_ADDR16_LO},
    {0x8090947E, R_PPC_ADDR16_HA}, {0x80909492, R_PPC_ADDR16_LO}, {0x8090CE36, R_PPC_ADDR16_HA},
    {0x8090CE5A, R_PPC_ADDR16_LO}, {0x809188E2, R_PPC_ADDR16_HA}, {0x809188EA, R_PPC_ADDR16_LO},
    {0x809188FA, R_PPC_ADDR16_LO}, {0x80918C36, R_PPC_ADDR16_HA}, {0x80918C46, R_PPC_ADDR16_LO},
    {0x8091AC96, R_PPC_ADDR16_HA}, {0x8091ACAA, R_PPC_ADDR16_LO}, {0x8091D3F6, R_PPC_ADDR16_LO},
    {0x8091F78A, R_PPC_ADDR16_HA}, {0x8091F7A6, R_PPC_ADDR16_LO}, {0x8091FE72, R_PPC_ADDR16_HA},
    {0x8091FE82, R_PPC_ADDR16_LO}, {0x8091FEA2, R_PPC_ADDR16_LO}, {0x8091FEDE, R_PPC_ADDR16_HA},
    {0x8091FEF6, R_PPC_ADDR16_LO}, {0x80925422, R_PPC_ADDR16_HA}, {0x80925452, R_PPC_ADDR16_LO},
    {0x8092F772, R_PPC_ADDR16_HA}, {0x8092F77A, R_PPC_ADDR16_LO}, {0x8092F87E, R_PPC_ADDR16_HA},
    {0x8092F88E, R_PPC_ADDR16_LO}, {0x8092FAFA, R_PPC_ADDR16_HA}, {0x8092FB0A, R_PPC_ADDR16_LO},
    {0x8092FE02, R_PPC_ADDR16_HA}, {0x8092FE0A, R_PPC_ADDR16_LO}, {0x8092FE12, R_PPC_ADDR16_LO},
    {0x809311E2, R_PPC_ADDR16_HA}, {0x809311EA, R_PPC_ADDR16_LO}, {0x8093352E, R_PPC_ADDR16_HA},
    {0x80933556, R_PPC_ADDR16_LO}, {0x80A2B70A, R_PPC_ADDR16_HA}, {0x80A2B71A, R_PPC_ADDR16_LO},
    {0x80B6BCE6, R_PPC_ADDR16_HA}, {0x80B6BCFA, R_PPC_ADDR16_LO},
  }
);

PATCH_REFERENCES(
  daPyMng_c::mPlayerMode,
  {
    {0x8001B7E6, R_PPC_ADDR16_HA}, {0x8001B7FE, R_PPC_ADDR16_LO}, {0x800BB96E, R_PPC_ADDR16_HA},
    {0x800BB9A2, R_PPC_ADDR16_LO}, {0x800E17BA, R_PPC_ADDR16_HA}, {0x800E17CE, R_PPC_ADDR16_LO},
    {0x800E196E, R_PPC_ADDR16_HA}, {0x800E1986, R_PPC_ADDR16_LO}, {0x801446FE, R_PPC_ADDR16_HA},
    {0x8014470E, R_PPC_ADDR16_LO}, {0x80144DD2, R_PPC_ADDR16_HA}, {0x80144DE6, R_PPC_ADDR16_LO},
    {0x80144E12, R_PPC_ADDR16_HA}, {0x80144E36, R_PPC_ADDR16_LO}, {0x807786BA, R_PPC_ADDR16_HA},
    {0x807786CE, R_PPC_ADDR16_LO}, {0x80789056, R_PPC_ADDR16_HA}, {0x8078906E, R_PPC_ADDR16_LO},
    {0x807B01D2, R_PPC_ADDR16_HA}, {0x807B01EA, R_PPC_ADDR16_LO}, {0x807B070E, R_PPC_ADDR16_HA},
    {0x807B0716, R_PPC_ADDR16_LO}, {0x807B07C2, R_PPC_ADDR16_HA}, {0x807B07D2, R_PPC_ADDR16_LO},
    {0x808C59B2, R_PPC_ADDR16_HA}, {0x808C59C2, R_PPC_ADDR16_LO}, {0x808C5C5E, R_PPC_ADDR16_HA},
    {0x808C5C66, R_PPC_ADDR16_LO}, {0x808EB7DE, R_PPC_ADDR16_HA}, {0x808EB7EA, R_PPC_ADDR16_LO},
    {0x80902B4A, R_PPC_ADDR16_HA}, {0x80902B56, R_PPC_ADDR16_LO}, {0x8090CE3A, R_PPC_ADDR16_HA},
    {0x8090CE5E, R_PPC_ADDR16_LO}, {0x80918C3A, R_PPC_ADDR16_HA}, {0x80918C4A, R_PPC_ADDR16_LO},
    {0x8091AC9A, R_PPC_ADDR16_HA}, {0x8091ACAE, R_PPC_ADDR16_LO}, {0x8091F78E, R_PPC_ADDR16_HA},
    {0x8091F7AA, R_PPC_ADDR16_LO}, {0x8091FE5E, R_PPC_ADDR16_HA}, {0x8091FE6A, R_PPC_ADDR16_LO},
    {0x8091FEE2, R_PPC_ADDR16_HA}, {0x8091FEFA, R_PPC_ADDR16_LO}, {0x8092540A, R_PPC_ADDR16_HA},
    {0x8092543A, R_PPC_ADDR16_LO}, {0x8092FAFE, R_PPC_ADDR16_HA}, {0x8092FB0E, R_PPC_ADDR16_LO},
    {0x8093352A, R_PPC_ADDR16_HA}, {0x80933536, R_PPC_ADDR16_LO},
  }
);

PATCH_REFERENCES(
  daPyMng_c::mCreateItem,
  {
    {0x8005D326, R_PPC_ADDR16_HA}, {0x8005D342, R_PPC_ADDR16_LO}, {0x8005FBE6, R_PPC_ADDR16_HA},
    {0x8005FBF2, R_PPC_ADDR16_LO}, {0x800BB97A, R_PPC_ADDR16_HA}, {0x800BB9B2, R_PPC_ADDR16_LO},
    {0x800E17C2, R_PPC_ADDR16_HA}, {0x800E17D6, R_PPC_ADDR16_LO}, {0x800E1976, R_PPC_ADDR16_HA},
    {0x800E198E, R_PPC_ADDR16_LO}, {0x801011A6, R_PPC_ADDR16_HA}, {0x801011AE, R_PPC_ADDR16_LO},
    {0x80140FA6, R_PPC_ADDR16_HA}, {0x80140FB6, R_PPC_ADDR16_LO}, {0x80144706, R_PPC_ADDR16_HA},
    {0x80144716, R_PPC_ADDR16_LO}, {0x80144DD6, R_PPC_ADDR16_HA}, {0x80144DEE, R_PPC_ADDR16_LO},
    {0x80144E1A, R_PPC_ADDR16_HA}, {0x80144E3E, R_PPC_ADDR16_LO}, {0x8014503E, R_PPC_ADDR16_HA},
    {0x8014504E, R_PPC_ADDR16_LO}, {0x807786B6, R_PPC_ADDR16_HA}, {0x807786CA, R_PPC_ADDR16_LO},
    {0x8078905E, R_PPC_ADDR16_HA}, {0x80789076, R_PPC_ADDR16_LO}, {0x807B00CA, R_PPC_ADDR16_HA},
    {0x807B00DE, R_PPC_ADDR16_LO}, {0x807B01CE, R_PPC_ADDR16_HA}, {0x807B01E6, R_PPC_ADDR16_LO},
    {0x807B0732, R_PPC_ADDR16_HA}, {0x807B0742, R_PPC_ADDR16_LO}, {0x807B07BE, R_PPC_ADDR16_HA},
    {0x807B07CE, R_PPC_ADDR16_LO}, {0x808C5C9A, R_PPC_ADDR16_HA}, {0x808C5C9E, R_PPC_ADDR16_LO},
    {0x808EF2D6, R_PPC_ADDR16_HA}, {0x808EF2DA, R_PPC_ADDR16_LO}, {0x80903026, R_PPC_ADDR16_HA},
    {0x80903036, R_PPC_ADDR16_LO}, {0x8090947A, R_PPC_ADDR16_HA}, {0x80909486, R_PPC_ADDR16_LO},
    {0x80918C3E, R_PPC_ADDR16_HA}, {0x80918C4E, R_PPC_ADDR16_LO}, {0x8091AC9E, R_PPC_ADDR16_HA},
    {0x8091ACB6, R_PPC_ADDR16_LO}, {0x8091F792, R_PPC_ADDR16_HA}, {0x8091F7AE, R_PPC_ADDR16_LO},
    {0x8091FE7A, R_PPC_ADDR16_HA}, {0x8091FE7E, R_PPC_ADDR16_LO}, {0x8091FEEA, R_PPC_ADDR16_HA},
    {0x8091FF02, R_PPC_ADDR16_LO}, {0x80925242, R_PPC_ADDR16_HA}, {0x8092524E, R_PPC_ADDR16_LO},
    {0x8092525E, R_PPC_ADDR16_LO}, {0x80925416, R_PPC_ADDR16_HA}, {0x80925446, R_PPC_ADDR16_LO},
  }
);

PATCH_REFERENCES(
  daPyMng_c::mRest,
  {
    {0x80010822, R_PPC_ADDR16_HA}, {0x80010832, R_PPC_ADDR16_LO}, {0x8001CD56, R_PPC_ADDR16_HA},
    {0x8001CD62, R_PPC_ADDR16_LO}, {0x8006052E, R_PPC_ADDR16_HA}, {0x80060542, R_PPC_ADDR16_LO},
    {0x8006055E, R_PPC_ADDR16_HA}, {0x80060566, R_PPC_ADDR16_LO}, {0x8006063A, R_PPC_ADDR16_HA},
    {0x8006064A, R_PPC_ADDR16_LO}, {0x80060EF2, R_PPC_ADDR16_HA}, {0x80060EFA, R_PPC_ADDR16_LO},
    {0x800B534A, R_PPC_ADDR16_HA}, {0x800B5356, R_PPC_ADDR16_LO}, {0x800BB972, R_PPC_ADDR16_HA},
    {0x800BB9AA, R_PPC_ADDR16_LO}, {0x800E17BE, R_PPC_ADDR16_HA}, {0x800E17D2, R_PPC_ADDR16_LO},
    {0x800E1972, R_PPC_ADDR16_HA}, {0x800E198A, R_PPC_ADDR16_LO}, {0x80102402, R_PPC_ADDR16_HA},
    {0x8010240E, R_PPC_ADDR16_LO}, {0x8010B752, R_PPC_ADDR16_HA}, {0x8010B75E, R_PPC_ADDR16_LO},
    {0x8013889A, R_PPC_ADDR16_HA}, {0x801388AE, R_PPC_ADDR16_LO}, {0x8013D82E, R_PPC_ADDR16_HA},
    {0x8013D83E, R_PPC_ADDR16_LO}, {0x80777EEA, R_PPC_ADDR16_HA}, {0x80777F02, R_PPC_ADDR16_LO},
    {0x807786C2, R_PPC_ADDR16_HA}, {0x807786D2, R_PPC_ADDR16_LO}, {0x80788FDE, R_PPC_ADDR16_HA},
    {0x80788FEE, R_PPC_ADDR16_LO}, {0x8078904A, R_PPC_ADDR16_HA}, {0x8078905A, R_PPC_ADDR16_LO},
    {0x8091885A, R_PPC_ADDR16_LO}, {0x8091D3FA, R_PPC_ADDR16_HA}, {0x8091D402, R_PPC_ADDR16_LO},
    {0x8091F796, R_PPC_ADDR16_HA}, {0x8091F7B2, R_PPC_ADDR16_LO}, {0x8091FEE6, R_PPC_ADDR16_HA},
    {0x8091FEFE, R_PPC_ADDR16_LO}, {0x80925412, R_PPC_ADDR16_HA}, {0x80925442, R_PPC_ADDR16_LO},
    {0x8092F776, R_PPC_ADDR16_HA}, {0x8092F782, R_PPC_ADDR16_LO}, {0x8092F882, R_PPC_ADDR16_HA},
    {0x8092F892, R_PPC_ADDR16_LO}, {0x80B6BCEA, R_PPC_ADDR16_HA}, {0x80B6BCFE, R_PPC_ADDR16_LO},
  }
);

PATCH_REFERENCES(
  daPyMng_c::mCoin,
  {
    {0x80060206, R_PPC_ADDR16_HA},
    {0x80060216, R_PPC_ADDR16_LO},
    {0x800BB982, R_PPC_ADDR16_HA},
    {0x800BB9B6, R_PPC_ADDR16_LO},
    {0x800E17C6, R_PPC_ADDR16_HA},
    {0x800E17DA, R_PPC_ADDR16_LO},
    {0x800E197A, R_PPC_ADDR16_HA},
    {0x800E1992, R_PPC_ADDR16_LO},
    {0x8078904E, R_PPC_ADDR16_HA},
    {0x8078906A, R_PPC_ADDR16_LO},
    {0x8091F79E, R_PPC_ADDR16_HA},
    {0x8091F7BA, R_PPC_ADDR16_LO},
    {0x8092541A, R_PPC_ADDR16_HA},
    {0x8092544A, R_PPC_ADDR16_LO},
    {0x80A2B70E, R_PPC_ADDR16_HA},
    {0x80A2B722, R_PPC_ADDR16_LO},
  }
);