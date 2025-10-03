// d_MiniGameCannon.cpp
// NSMBW d_bases.text: 0x8078BC60 - 0x8078DA20

#include "d_MiniGameCannon.h"

#include "d_player/d_WarningManager.h"
#include "d_system/d_a_player_manager.h"
#include "d_system/d_game_common.h"
#include "d_system/d_message.h"
#include "d_system/d_mj2d_game.h"

[[address(0x8078BC60)]]
dMiniGameCannon_c* dMiniGameCannon_c_classInit()
{
    return new dMiniGameCannon_c;
}

[[address(0x8078BC90)]]
dMiniGameCannon_c::dMiniGameCannon_c()
  : mStateMgr(*this, StateID_TitleOpenWait)
{
    mReady = false;
    mActive = false;
    m0x2DA = false;
    m0x2E0 = false;
    m0x2E1 = false;
    m0x2E2 = false;
    m0x2E3 = false;
    m0x2E4 = false;
}

[[address(0x8078BEA0)]]
dMiniGameCannon_c::~dMiniGameCannon_c()
{
    // mStateMgr.~sStateMgr_c();
    mLayout.~LytBase_c();
}

[[address(0x8078BF30)]]
fBase_c::PACK_RESULT_e dMiniGameCannon_c::create()
{
    if (mReady) {
        return PACK_RESULT_e::SUCCEEDED;
    }

    if (!createLayout()) {
        return PACK_RESULT_e::FAILED;
    }

    mLayout.AllAnimeEndSetup();
    mLayout.ReverseAnimeStartSetup(0, false);
    mLayout.AnimePlay();
    mLayout.calc();

    mpRootPane->SetVisible(false);

    m0x2C0 = false;
    for (std::size_t i = 0; i < std::size(mNumWon); i++) {
        mNumWon[i] = 0;
    }

    for (std::size_t i = 0; i < PLAYER_COUNT; i++) {
        mPlayerEntry.clearBit(i);
    }

    mReady = true;
    mActive = false;

    return PACK_RESULT_e::SUCCEEDED;
}

[[address(0x8078C000)]]
bool dMiniGameCannon_c::createLayout()
{
    if (!mLayout.ReadResource("miniGameCannon/miniGameCannon.arc", false)) {
        return false;
    }

    mLayout.build("miniGameCannon_15.brlyt", nullptr);
    mLayout.AnimeResRegister({
      "miniGameCannon_15_inWindow.brlan",
      "miniGameCannon_15_loopWindow.brlan",
      "miniGameCannon_15_loopYokoIncline.brlan",
      "miniGameCannon_15_inPlayer.brlan",
      "miniGameCannon_15_loop1UP.brlan",
      "miniGameCannon_15_inTitle.brlan",
      "miniGameCannon_15_weitTitle.brlan",
      "miniGameCannon_15_outTitle.brlan",
      "miniGameCannon_15_outWindow.brlan",
    });
    mLayout.GroupRegister(
      {
        "A00_Window",
        "A00_Window",
        "B00_Yokomochi",
        "D00_1P_00",
        "D01_2P_00",
        "D02_3P_00",
        "D03_4P_00",
        "D00_1P_00",
        "D01_2P_00",
        "D02_3P_00",
        "D03_4P_00",
        "E00_title",
        "E00_title",
        "E00_title",
        "A00_Window",
      },
      {0, 1, 2, 3, 3, 3, 3, 4, 4, 4, 4, 5, 6, 7, 8}
    );
    mLayout.TPaneNameRegister(
      300,
      {
        "T_info_01",
        "T_info_02",
        "T_infoS_00",
        "T_info_00",
        "T_info_03",
        "T_title_00",
      },
      {1, 2, 0, 0, 3, 5}
    );
    mpRootPane = mLayout.getRootPane();
    mLayout.NPaneRegister(
      &mpN4pPos[0],
      {
        "N_4P_Pos_00",
        "N_4P_Pos_01",
        "N_4P_Pos_02",
        "N_4P_Pos_03",

        "N_3P_Pos_00",
        "N_3P_Pos_01",
        "N_3P_Pos_02",

        "N_2P_Pos_00",
        "N_2P_Pos_01",

        "N_1P_Pos_00",

        "N_info_00",
        "N_result_00",
        "N_gameCannon_00",
        "N_result_01",

        "N_1P_00",
        "N_2P_00",
        "N_3P_00",
        "N_4P_00",
      }
    );
    mLayout.TPaneRegister(
      &mpT1up[0],
      {
        "T_1Up_00",
        "T_1Up_01",
        "T_1Up_02",
        "T_1Up_03",
        "T_info_04",
      }
    );
    mpTInfo->setMessage(dMessage_c::getMesRes(), 301, 7, 0);
    mLayout.PPaneRegister(
      &mpPPlayer[0],
      {
        "P_1P_00",
        "P_2P_00",
        "P_3P_00",
        "P_4P_00",
        "P_BG_00",
        "P_titleBase_00",
      }
    );
    mLayout.WPaneRegister(&mpWGameCannon, {"W_gameCannon_00"});

    return true;
}

[[address(0x8078C140)]]
fBase_c::PACK_RESULT_e dMiniGameCannon_c::preExecute()
{
    if (dBase_c::preExecute() == PACK_RESULT_e::NOT_READY) {
        return PACK_RESULT_e::NOT_READY;
    }

    return !dWarningManager_c::isWarning() ? PACK_RESULT_e::SUCCEEDED : PACK_RESULT_e::NOT_READY;
}

[[address(0x8078C180)]]
fBase_c::PACK_RESULT_e dMiniGameCannon_c::execute()
{
    if (mReady && mActive) {
        mStateMgr.executeState();
        mLayout.AnimePlay();
        mLayout.calc();
    }
    return PACK_RESULT_e::SUCCEEDED;
}

[[address(0x8078C200)]]
fBase_c::PACK_RESULT_e dMiniGameCannon_c::draw()
{
    if (mReady && mActive) {
        mLayout.entry();
    }
    return PACK_RESULT_e::SUCCEEDED;
}

[[address(0x8078C240)]]
fBase_c::PACK_RESULT_e dMiniGameCannon_c::doDelete()
{
    return mLayout.doDelete();
}

[[address(0x8078C250)]]
nw4r::lyt::Pane* dMiniGameCannon_c::getPositionPane(int player)
{
    using PaneList = u8[8][8];

#define OFFSET(_member)                                                                            \
    u8(((offsetof(dMiniGameCannon_c, _member) - offsetof(dMiniGameCannon_c, mpN4pPos[0])) >> 2) + 1)

    u8 posPane = PaneList{
      {
        OFFSET(mpN1pPos),
      },
      {
        OFFSET(mpN2pPos[0]),
        OFFSET(mpN2pPos[1]),
      },
      {
        OFFSET(mpN3pPos[0]),
        OFFSET(mpN3pPos[1]),
        OFFSET(mpN3pPos[2]),
      },
      {
        OFFSET(mpN4pPos[0]),
        OFFSET(mpN4pPos[1]),
        OFFSET(mpN4pPos[2]),
        OFFSET(mpN4pPos[3]),
      },
      {
        OFFSET(mpN4pPos[0]),
        OFFSET(mpN4pPos[1]),
        OFFSET(mpN4pPos[2]),
        OFFSET(mpN4pPos[3]),
        OFFSET(mpN3pPos[1]),
      },
      {
        OFFSET(mpN4pPos[0]),
        OFFSET(mpN4pPos[1]),
        OFFSET(mpN4pPos[2]),
        OFFSET(mpN4pPos[3]),
        OFFSET(mpN3pPos[0]),
        OFFSET(mpN3pPos[2]),
      },
      {
        OFFSET(mpN4pPos[0]),
        OFFSET(mpN4pPos[1]),
        OFFSET(mpN4pPos[2]),
        OFFSET(mpN4pPos[3]),
        OFFSET(mpN3pPos[0]),
        OFFSET(mpN3pPos[1]),
        OFFSET(mpN3pPos[2]),
      },
      {
        OFFSET(mpN4pPos[0]),
        OFFSET(mpN4pPos[1]),
        OFFSET(mpN4pPos[2]),
        OFFSET(mpN4pPos[3]),
        OFFSET(mpN3pPos[0]),
        OFFSET(mpN3pPos[1]),
        OFFSET(mpN3pPos[2]),
        OFFSET(mpN2pPos[0]),
      },
    }[mNumPlayers - 1][player];

#undef OFFSET

    if (posPane == 0) {
        return nullptr;
    }

    return mpN4pPos[posPane - 1];
}

[[address(0x8078C280)]]
void dMiniGameCannon_c::setPlayerPanePositions()
{
    for (std::size_t i = 0, j = 0; i < PLAYER_COUNT; i++) {
        if (!mPlayerEntry[i]) {
            continue;
        }

        nw4r::lyt::Pane* posPane = getPositionPane(j);
        if (posPane == nullptr) {
            continue;
        }

        int playerType = static_cast<int>(daPyMng_c::mPlayerType[i]);
        if (playerType < 4) {
            j++;
            const auto& gmtx = posPane->GetGlobalMtx();
            mpNPlayer[playerType]->SetTranslate(nw4r::math::VEC3(gmtx[0][3], gmtx[1][3], 0.0));
            mpNPlayer[playerType]->SetScale(nw4r::math::VEC2(gmtx[0][0], gmtx[1][1]));
            mpT1up[playerType]->SetAlpha(posPane->GetGlobalAlpha());
            mpPPlayer[playerType]->SetAlpha(posPane->GetGlobalAlpha());
        }
    }
}

[[address(0x8078C3F0)]]
void dMiniGameCannon_c::setAllText()
{
    MsgRes_c* msgRes = dMessage_c::getMesRes();

    for (int i = 0; i < PLAYER_COUNT; i++) {
        if (!mPlayerEntry[i]) {
            continue;
        }

        int playerType = static_cast<int>(daPyMng_c::mPlayerType[i]);
        if (playerType >= 4) {
            continue;
        }

        int rest = mNumWon[playerType];
        int digits = 1;
        for (int r = rest; r >= 10; digits++) {
            r /= 10;
        }
        wchar_t restStr[16];
        dMessage_c::itoaCustom(rest, restStr, std::size(restStr), digits, 0);
        mpT1up[playerType]->setMessage(msgRes, 300, 4, 1, restStr);
    }
}

[[address(0x8078C4D0)]]
bool dMiniGameCannon_c::isWin() const
{
    for (std::size_t i = 0; i < std::size(mNumWon); i++) {
        if (mNumWon[i] != 0) {
            return true;
        }
    }
    return false;
}

[[address(0x8078C530)]]
void dMiniGameCannon_c::initializeState_TitleOpenWait()
{
    mpRootPane->SetVisible(false);
    m0x2E1 = false;
    m0x2E2 = false;
}

[[address(0x8078C550)]]
void dMiniGameCannon_c::executeState_TitleOpenWait()
{
    if (!m0x2E0) {
        return;
    }
    m0x2E0 = false;
    return mStateMgr.changeState(StateID_TitleOpenAnimeEndWait);
}

[[address(0x8078C590)]]
void dMiniGameCannon_c::finalizeState_TitleOpenWait()
{
}

[[address(0x8078C5A0)]]
void dMiniGameCannon_c::initializeState_TitleOpenAnimeEndWait()
{
    mpRootPane->SetVisible(true);
    mpPBg->SetVisible(false);
    mpNInfo->SetVisible(false);
    mpNResult->SetVisible(false);
    mpNResult2->SetVisible(false);
    mpWGameCannon->SetVisible(false);
    mpPTitleBase->SetVisible(true);
    for (std::size_t i = 0; i < std::size(mpNPlayer); i++) {
        mpNPlayer[i]->SetVisible(false);
    }
    mpNGameCannon->SetAlpha(255);
    mLayout.AllAnimeEndSetup();
    mLayout.AnimeStartSetup(11, false);
    m0x2E1 = true;
}

[[address(0x8078C6B0)]]
void dMiniGameCannon_c::executeState_TitleOpenAnimeEndWait()
{
    if (!mLayout.isAnime(-1)) {
        return mStateMgr.changeState(StateID_TitleDisp);
    }
}

[[address(0x8078C710)]]
void dMiniGameCannon_c::finalizeState_TitleOpenAnimeEndWait()
{
    m0x2E1 = false;
}

[[address(0x8078C720)]]
void dMiniGameCannon_c::initializeState_TitleDisp()
{
    mLayout.LoopAnimeStartSetup(12);
}

[[address(0x8078C730)]]
void dMiniGameCannon_c::executeState_TitleDisp()
{
    if (!m0x2E2) {
        return;
    }
    return mStateMgr.changeState(StateID_TitleExitAnimeEndWait);
}

[[address(0x8078C760)]]
void dMiniGameCannon_c::finalizeState_TitleDisp()
{
    mLayout.AnimeEndSetup(12);
}

[[address(0x8078C770)]]
void dMiniGameCannon_c::initializeState_TitleExitAnimeEndWait()
{
    mLayout.AnimeStartSetup(13, false);
    m0x2E1 = true;
}

[[address(0x8078C7B0)]]
void dMiniGameCannon_c::executeState_TitleExitAnimeEndWait()
{
    if (!mLayout.isAnime(-1)) {
        mActive = false;
        return mStateMgr.changeState(StateID_StartWait);
    }
}

[[address(0x8078C810)]]
void dMiniGameCannon_c::finalizeState_TitleExitAnimeEndWait()
{
    mpRootPane->SetVisible(false);
    mpPBg->SetVisible(true);
    mpNInfo->SetVisible(true);
    mpNResult->SetVisible(true);
    mpWGameCannon->SetVisible(true);
    mpPTitleBase->SetVisible(false);
    m0x2E1 = false;
    m0x2E3 = false;
    m0x2E4 = false;
}

[[address(0x8078C8A0)]]
void dMiniGameCannon_c::initializeState_StartWait()
{
}

[[address(0x8078C8B0)]]
void dMiniGameCannon_c::executeState_StartWait()
{
    if (!m0x2DA) {
        return;
    }

    m0x2DA = 0;
    return mStateMgr.changeState(StateID_OpenAnimeEndWait);
}

[[address(0x8078C8E0)]]
void dMiniGameCannon_c::finalizeState_StartWait()
{
    mNumPlayers = 0;
    for (std::size_t i = 0; i < PLAYER_COUNT; i++) {
        if (dGameCom::PlayerEnterCheck(i)) {
            mPlayerEntry.setBit(i);
            mNumPlayers++;
        } else {
            mPlayerEntry.clearBit(i);
        }
    }
}

[[address(0x8078C970)]]
void dMiniGameCannon_c::initializeState_OpenAnimeEndWait()
{
    mLayout.AllAnimeEndSetup();

    mpRootPane->SetVisible(true);
    if (m0x2C0 == 0) {
        mpNInfo->SetVisible(true);
        mpNResult->SetVisible(false);
        mpNResult2->SetVisible(false);
        for (std::size_t i = 0; i < std::size(mpNPlayer); i++) {
            mpNPlayer[i]->SetVisible(false);
        }
    } else {
        mpNInfo->SetVisible(false);
        if (isWin()) {
            for (std::size_t i = 0; i < std::size(mpNPlayer); i++) {
                mpNPlayer[i]->SetVisible(true);
                mLayout.ReverseAnimeStartSetup(i + 3, false);
            }
            mpNResult->SetVisible(true);
            mpNResult2->SetVisible(false);
        } else {
            mpNResult->SetVisible(false);
            mpNResult2->SetVisible(true);
            for (std::size_t i = 0; i < std::size(mpNPlayer); i++) {
                mpNPlayer[i]->SetVisible(false);
            }
        }
    }

    mLayout.AnimeStartSetup(0, false);
    m0x2E1 = true;
}

[[address(0x8078CB80)]]
void dMiniGameCannon_c::executeState_OpenAnimeEndWait()
{
    if (mLayout.isAllAnime()) {
        return;
    }

    const auto* id = &StateID_NowDisp;
    if (m0x2C0 != 0) {
        if (isWin()) {
            id = &StateID_ResultDispAnimeEndWait;
        } else {
            id = &StateID_ResultNowDisp;
        }
    }

    return mStateMgr.changeState(*id);
}

[[address(0x8078CC40)]]
void dMiniGameCannon_c::finalizeState_OpenAnimeEndWait()
{
    m0x2E1 = false;
}

[[address(0x8078CC50)]]
void dMiniGameCannon_c::initializeState_NowDisp()
{
    mLayout.LoopAnimeStartSetup(2);
}

[[address(0x8078CC60)]]
void dMiniGameCannon_c::executeState_NowDisp()
{
    if (!m0x2E3) {
        return;
    }

    return mStateMgr.changeState(StateID_ExitAnimeEndWait);
}

[[address(0x8078CC90)]]
void dMiniGameCannon_c::finalizeState_NowDisp()
{
    mLayout.AnimeEndSetup(2);
}

[[address(0x8078CCA0)]]
void dMiniGameCannon_c::initializeState_ResultDispAnimeEndWait()
{
    setPlayerPanePositions();
    setAllText();

    for (std::size_t i = 0; i < PLAYER_COUNT; i++) {
        int playerType = static_cast<int>(daPyMng_c::mPlayerType[i]);
        if (playerType >= 4) {
            continue;
        }
        if (!mPlayerEntry[i]) {
            mpNPlayer[playerType]->SetVisible(false);
            return;
        }

        dGameCom::Player1upColor(mpT1up[playerType], playerType);
        mLayout.AnimeStartSetup(playerType + 3, false);
        mpNPlayer[playerType]->SetVisible(true);
    }

    m0x2E1 = true;
}

[[address(0x8078CE10)]]
void dMiniGameCannon_c::initializeState_ResultNowDisp()
{
    if (!isWin()) {
        return;
    }

    for (std::size_t i = 0; i < PLAYER_COUNT; i++) {
        if (mPlayerEntry[i]) {
            int playerType = static_cast<int>(daPyMng_c::mPlayerType[i]);
            if (playerType < 4) {
                mLayout.LoopAnimeStartSetup(playerType + 7);
            }
        }
    }
}

[[address(0x8078CE90)]]
void dMiniGameCannon_c::executeState_ResultNowDisp()
{
    if (!m0x2E4) {
        return;
    }
    return mStateMgr.changeState(StateID_ExitAnimeEndWait);
}

[[address(0x8078CEC0)]]
void dMiniGameCannon_c::finalizeState_ResultNowDisp()
{
    if (isWin()) {
        mLayout.AllAnimeEndSetup();
    }
}

[[address(0x8078CF00)]]
void dMiniGameCannon_c::initializeState_ExitAnimeEndWait()
{
    mLayout.AnimeStartSetup(14, false);
    m0x2E1 = true;
}

[[address(0x8078CF40)]]
void dMiniGameCannon_c::executeState_ExitAnimeEndWait()
{
    setPlayerPanePositions();
    if (!mLayout.isAnime(-1)) {
        mActive = false;
        return mStateMgr.changeState(StateID_StartWait);
    }
}

[[address(0x8078CFB0)]]
void dMiniGameCannon_c::finalizeState_ExitAnimeEndWait()
{
    m0x2E1 = false;
}
