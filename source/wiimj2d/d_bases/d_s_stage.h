#pragma once

#include "d_system/d_base.h"
#include "d_system/d_cyuukan.h"
#include "d_system/d_fader.h"
#include "d_system/d_mj2d_game.h"
#include "d_system/d_remocon_mng.h"
#include "framework/f_base_profile.h"

class dGameDisplay_c;
class dMiniGameCannon_c;
class dMiniGameWire_c;
class dModelPlayManager_c;
class dMessageWindow_c;
class dStaffCreditScore_c;

// TODO
struct dReplayPlay_c {
    FILL(0x00, 0x64);

    /* 0x64 */ u8 mFrameFlags;
};

class dScStage_c : public dBase_c
{
public:
    // -------------------
    // Constants and Types
    // -------------------

    // @unofficial
    enum class GAME_MODE_e {
        UNKNOWN_0 = 0,
        UNKNOWN_2 = 2,
    };

public:
    // ----------------
    // Static Functions
    // ----------------

    /* 0x8005EC90 */
    static bool getCourseIn()
    {
        return m_isCourseIn;
    }

    /* 0x80101A70 */
    static dGameDisplay_c* getGameDisplay();

    static inline dMiniGameCannon_c* getMiniGameCannon()
    {
        if (dScStage_c::m_instance == nullptr) {
            return nullptr;
        }
        return dScStage_c::m_instance->mpMiniGameCannon;
    }

    /* 0x80101AA0 */
    static void setLoopType();

    /* 0x801020E0 @unofficial */
    static void setCollectionCoin(int coin, PLAYER_TYPE_e player);

    /* 0x801022C0 */
    static bool isNowReplay();

    /* 0x80102370 @unofficial */
    static void
    goToSceneAfterLevel(int profile, int param2, int param3, dFader_c::fader_type_e faderType);

public:
    // ----------------
    // Member Functions
    // ----------------

    /* 0x80924950 */
    bool CreatedLayouts() const;

    /* 0x809251F0 */
    void courseClear();

    /* 0x809253E0 */
    void restoreStartInfo();

public:
    // -----------
    // Static Data
    // -----------

    /* 0x8042A4A8 */
    static dScStage_c* m_instance;

    /* 0x8042A4DC */
    static s32 m_goalType;

    /* 0x8042A4E0 */
    static u32 m_exeFrame;

    /* 0x8042A4E4 */
    static GAME_MODE_e m_gameMode;

    /* 0x8042A4FC */
    static bool m_isCourseIn;

    /* 0x8042A4FD */
    static bool m_isCourseOut;

    /* 0x8042A4FE */
    static bool m_isOtehonReturn;

    /* 0x8042A4FF */
    static bool m_isStaffCredit;

    /* 0x8042A500 */
    static s32 m_miniGame;

    /* 0x8042A504 */
    static u8 m_replayMode;

    /* 0x8042A506 */
    static bool m_isReplayGoal;

    /* 0x803744B0 */
    static PLAYER_TYPE_e mCollectionCoin[COLLECTION_COIN_COUNT];

    /* 0x803744D0 */
    static dReplayPlay_c* m_replayPlay_p[REMOCON_CONNECT_COUNT];

public:
    // -----------
    // Member Data
    // -----------

    FILL(0x0070, 0x11D4);

    /* 0x11D4 */ dGameDisplay_c* mpGameDisplay;

    FILL(0x11D8, 0x11E8);

    /* 0x11E8 */ dMiniGameCannon_c* mpMiniGameCannon;
    /* 0x11EC */ dMiniGameWire_c* mpMiniGameWire;
    /* 0x11F0 */ dModelPlayManager_c* mpModelPlayManager;
    /* 0x11F4 */ dMessageWindow_c* mpMessageWindow;
    FILL(0x11F8, 0x11FC);
    /* 0x11FC */ dStaffCreditScore_c* mpStaffCreditScore;

    FILL(0x1200, 0x120C);

    /* 0x120C */ WORLD_e mWorld;
    /* 0x120D */ STAGE_e mStage;
    /* 0x120E */ u8 mCourse; // A.k.a. Area
    /* 0x120F */ u8 mArea; // A.k.a. Zone
    /* 0x1210 */ u8 mLayer;
    /* 0x1211 */ u8 mGoto; // A.k.a Entrance

    OFFSET_ASSERT(0x1212);
};
