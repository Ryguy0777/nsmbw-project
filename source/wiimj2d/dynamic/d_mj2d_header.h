#pragma once

#include <dynamic/d_mj2d_game.h>

class dSaveMng_c;

/**
 * Represents the header of the game's save file. The save file header contains data that is not
 * related to a specific save slot, along with basic information required to identify the data and
 * preserve its integrity. For the slot-specific save data, refer to dMj2dGame_c.
 */
class dMj2dHeader_c
{
public:
    /**
     * Constructs the holder.
     */
    dMj2dHeader_c();

    /**
     * Initializes the header data.
     */
    void initialize();

    /**
     * Gets the Free Mode play count for the given world/level. See mPlayCountFreeMode.
     */
    u16 getPlayCountFreeMode(WORLD_e world, STAGE_e level) const;

    /**
     * Sets the Free Mode play count for the given world/level. See mPlayCountFreeMode.
     */
    void setPlayCountFreeMode(WORLD_e world, STAGE_e level, int count);

    /**
     * Gets the Coin Battle play count for the given world/level. See mPlayCountCoinBattle.
     */
    u16 getPlayCountCoinBattle(WORLD_e world, STAGE_e level) const;

    /**
     * Sets the Coin Battle play count for the given world/level. See mPlayCountCoinBattle.
     */
    void setPlayCountCoinBattle(WORLD_e world, STAGE_e level, int count);

    /**
     * Unlocks the given world in extra modes.
     */
    void onMultiWorldOpenFlag(WORLD_e world);

    /**
     * Checks if the given world is unlocked in extra modes.
     */
    bool isMultiWorldOpenFlag(WORLD_e world);

private:
    /**
     * Ensures that the save's major revision number matches the current one.
     * If the revision number does not match, the header data is reset.
     */
    void versionUpdate();

    /**
     * Sets the last used save data slot.
     */
    void setSelectFileNo(s8 file);

    /**
     * The savegame magic.
     */
    char mMagic[4];

    /**
     * The save revision numbers.
     */
    u8 mRevision[2];

    /**
     * The last selected save data slot.
     */
    u8 mLastSelectedFile;

    /**
     * @unused Padding.
     */
    u8 mUnknown7;

    /**
     * The play count of each level in Free Mode.
     */
    u16 mPlayCountFreeMode[WORLD_COUNT][STAGE_COUNT];

    /**
     * The play count of each level in Coin Battle.
     */
    u16 mPlayCountCoinBattle[WORLD_COUNT][STAGE_COUNT];

    /**
     * The worlds unlocked in Extra Modes.
     */
    u16 mMultiWorldOpenFlag;

    /**
     * @unused Padding.
     */
    u16 mUnknown69A;

    /**
     * The CRC32 checksum of the above data (excluding ::mMagic).
     */
    u32 mChecksum;

    friend class dSaveMng_c;
};