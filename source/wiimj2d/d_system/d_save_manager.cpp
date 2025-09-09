// d_save_manager.cpp
// NSMBW .text: 0x800E0270 - 0x800E1AA0

#include "d_save_manager.h"

#include "d_bases/d_s_world_map.h"
#include "d_nand_thread.h"
#include "d_system/d_a_player_manager.h"
#include "d_system/d_game_common.h"
#include "d_system/d_info.h"
#include "d_system/d_mj2d_data.h"
#include "d_system/d_mj2d_game.h"
#include "machine/m_heap.h"
#include <cstring>
#include <revolution/os/OSError.h>

[[address_data(0x8042A320)]]
dSaveMng_c* dSaveMng_c::m_instance;

[[address(0x800E0270)]]
void dSaveMng_c::create(EGG::Heap* heap)
{
    EGG::Heap* prev = mHeap::setCurrentHeap(heap);
    m_instance = new dSaveMng_c();
    mHeap::setCurrentHeap(prev);
}

[[address(0x800E02C0)]]
dSaveMng_c::dSaveMng_c();

[[address(0x800E03C0)]]
void dSaveMng_c::refresh()
{
    const void* data = dNandThread_c::getSaveData();
    ASSERT(data != nullptr);

    std::memcpy(static_cast<void*>(&mData), data, sizeof(mData));
    mData.mHeader.versionUpdate();

    for (s8 i = 0; i < SAVE_SLOT_COUNT; i++) {
        mData.mSaveGames[i].versionUpdate();
        mData.mTempGames[i].versionUpdate();
    }
}

[[address(0x800E0470)]]
dMj2dGame_c* dSaveMng_c::getSaveGame(s8 slot)
{
    if (slot == -1) {
        slot = mData.mHeader.mLastSelectedFile;
    }
    return &mData.mSaveGames[slot];
}

[[address(0x800E04A0)]]
dMj2dGame_c* dSaveMng_c::getTempGame(s8 slot)
{
    if (slot == -1) {
        slot = mData.mHeader.mLastSelectedFile;
    }
    return &mData.mTempGames[slot];
}

[[address(0x800E04D0)]]
void dSaveMng_c::saveGameCopy(s8 to, s8 from)
{
    std::memcpy(
      static_cast<void*>(&mData.mSaveGames[to]), static_cast<void*>(&mData.mSaveGames[from]),
      sizeof(dMj2dGame_c)
    );
    mData.mTempGames[to].initialize();
}

[[address(0x800E05A0)]]
void dSaveMng_c::calcCRC()
{
    // Do nothing
}

[[address(0x800E0630)]]
bool dSaveMng_c::startNandSave()
{
    return mSaving = dNandThread_c::m_instance->cmdSave(&mData);
}

[[address(0x800E0D10)]]
bool dSaveMng_c::startMultiModeNandSave()
{
    dMj2dData_c* oldData = dNandThread_c::getSaveData();
    dMj2dData_c nextData;
    std::memcpy(static_cast<void*>(&nextData.mHeader), &mData.mHeader, sizeof(dMj2dHeader_c));
    std::memcpy(
      static_cast<void*>(&nextData.mSaveGames), &oldData->mSaveGames, sizeof(nextData.mSaveGames)
    );
    std::memcpy(
      static_cast<void*>(&nextData.mTempGames), &oldData->mTempGames, sizeof(nextData.mTempGames)
    );

    return mSaving = dNandThread_c::m_instance->cmdSave(&nextData);
}

[[address(0x800E0E10)]]
bool dSaveMng_c::startQuickNandSave()
{
    dMj2dData_c* oldData = dNandThread_c::getSaveData();
    dMj2dData_c nextData;
    std::memcpy(static_cast<void*>(&nextData), oldData, sizeof(dMj2dData_c));
    std::memcpy(
      static_cast<void*>(&nextData.mTempGames[mData.mHeader.mLastSelectedFile]),
      &mData.mSaveGames[mData.mHeader.mLastSelectedFile], sizeof(dMj2dGame_c)
    );
    return mSaving = dNandThread_c::m_instance->cmdSave(&nextData);
}

[[address(0x800E12C0)]]
bool dSaveMng_c::startDeleteQuickNandSave()
{
    dMj2dData_c* oldData = dNandThread_c::getSaveData();
    dMj2dData_c nextData;
    std::memcpy(static_cast<void*>(&nextData), oldData, sizeof(dMj2dData_c));
    std::memcpy(
      static_cast<void*>(&nextData.mTempGames[mData.mHeader.mLastSelectedFile]),
      &mData.mTempGames[mData.mHeader.mLastSelectedFile], sizeof(dMj2dGame_c)
    );
    return mSaving = dNandThread_c::m_instance->cmdSave(&nextData);
}

[[address(0x800E1A30)]]
void dSaveMng_c::loadQuickSaveData(u8 file)
{
    mData.mHeader.mLastSelectedFile = file;
    std::memcpy(
      static_cast<void*>(&mData.mSaveGames[file]), static_cast<void*>(&mData.mTempGames[file]),
      sizeof(dMj2dGame_c)
    );
}

[[address(0x800E1780)]]
void dSaveMng_c::prepareSave()
{
    dMj2dGame_c* game = getSaveGame();
    dGameCom::setWorldClearFlag();

    game->setScore(daPyMng_c::mScore);
    for (int i = 0; i < PLAYER_COUNT; i++) {
        game->setPlrID(i, daPyMng_c::mPlayerType[i]);
        u32 index = static_cast<u32>(daPyMng_c::mPlayerType[i]);
        game->setPlrMode(index, daPyMng_c::mPlayerMode[index]);
        game->setRest(index, daPyMng_c::mRest[index]);
        game->setCreateItem(index, daPyMng_c::mCreateItem[index]);
        game->setCoin(index, daPyMng_c::mCoin[index]);
    }

    for (int w = 0; w < WORLD_COUNT; w++) {
        for (int e = 0; e < AMBUSH_ENEMY_COUNT; e++) {
            const dInfo_c::enemy_s& enemy = dInfo_c::m_instance->GetWorldMapEnemy(w, e);
            game->setCSEnemySceneNo(static_cast<WORLD_e>(w), e, enemy.mSceneNo);
            game->setCSEnemyPosIndex(static_cast<WORLD_e>(w), e, enemy.mPosIndex);
            game->setCSEnemyWalkDir(
              static_cast<WORLD_e>(w), e, static_cast<PATH_DIRECTION_e>(enemy.mWalkDir)
            );
        }
        game->setKinopioCourseNo(static_cast<WORLD_e>(w), dInfo_c::m_instance->mKinopioCourseNo[w]);
    }
    game->setIbaraNow(static_cast<int>(dInfo_c::m_instance->GetIbaraNow(4)));
    game->mSwitchOn = dInfo_c::m_instance->mSwitchOn;
    game->mGameCompletion &= ~dMj2dGame_c::GAME_COMPLETION_e::SAVE_EMPTY;
}

[[address(0x800E1930)]]
void dSaveMng_c::initLoadGame(s8 file)
{
    mData.mHeader.mLastSelectedFile = file;
    dMj2dGame_c* game = dSaveMng_c::getSaveGame(file);

    daPyMng_c::mScore = game->getScore();
    for (int i = 0; i < PLAYER_COUNT; i++) {
        daPyMng_c::mPlayerType[static_cast<int>(game->getPlrID(i))] = static_cast<PLAYER_TYPE_e>(i);
        daPyMng_c::mPlayerMode[i] = game->getPlrMode(i);
        daPyMng_c::mRest[i] = game->getRest(i);
        daPyMng_c::mCreateItem[i] = game->getCreateItem(i);
        daPyMng_c::mCoin[i] = game->getCoin(i);
    }
    daPyMng_c::checkBonusNoCap();
    dScWMap_c::initLoadGame();
}