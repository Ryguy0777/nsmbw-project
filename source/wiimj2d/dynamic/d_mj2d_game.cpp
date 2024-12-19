// d_mj2d_game.cpp
// NSMBW .text: 0x800CDFB0 - 0x800CE660

#include "d_mj2d_game.h"

#include <framework/f_feature.h>

/**
 * Gets the obtainable Star Coin count for the given world.
 */
[[address(0x800CE280)]]
int dMj2dGame_c::getTotalWorldCollectCoin(WORLD_e world)
{
    if (fFeature::UNLOCKED_ALL_WORLDS) {
        return STAR_COIN_COUNT * STAGE_COUNT;
    }

    int coinCount = 0;
    for (int level = 0; level < STAGE_COUNT; level++) {
        for (u32 coin = 0; coin < STAR_COIN_COUNT; coin++) {
            if (isCollectCoin(world, static_cast<STAGE_e>(level), coin) & 0xFF) {
                coinCount++;
            }
        }
    }

    return coinCount;
}

/**
 * Checks if the completion flag(s) for the given world is set.
 */
[[address(0x800CE440)]]
dMj2dGame_c::WORLD_COMPLETION_e
dMj2dGame_c::isWorldDataFlag(WORLD_e world, WORLD_COMPLETION_e flag) const
{
    if (fFeature::UNLOCKED_ALL_WORLDS) {
        return flag;
    }

    return flag & mWorldCompletion[static_cast<u8>(world)];
}

/**
 * Sets the specified flag(s) for the given world.
 */
[[address(0x800CE450)]]
void dMj2dGame_c::onWorldDataFlag(WORLD_e world, WORLD_COMPLETION_e flag);

/**
 * Unsets the specified flag(s) for the given world.
 */
[[address(0x800CE470)]]
void dMj2dGame_c::offWorldDataFlag(WORLD_e world, WORLD_COMPLETION_e flag);

/**
 * Checks if the completion flag for the given world/level is set.
 */
[[address(0x800CE4B0)]]
bool dMj2dGame_c::isCourseDataFlag(WORLD_e world, STAGE_e level, COURSE_COMPLETION_e flag) const
{
    if (fFeature::COMPLETED_ALL_LEVELS) {
        return true;
    }

    return !!(flag & mCourseCompletion[static_cast<u8>(world)][static_cast<u8>(level)]);
}

/**
 * Sets the completion flag(s) for the given world/level.
 */
[[address(0x800CE4E0)]]
void dMj2dGame_c::onCourseDataFlag(WORLD_e world, STAGE_e level, COURSE_COMPLETION_e flag);

/**
 * Unsets the completion flag(s) for the given world/level.
 */
[[address(0x800CE500)]]
void dMj2dGame_c::offCourseDataFlag(WORLD_e world, STAGE_e level, COURSE_COMPLETION_e flag);

/**
 * Gets all the completion flags for the given world/level.
 */
[[address(0x800CE490)]]
dMj2dGame_c::COURSE_COMPLETION_e dMj2dGame_c::getCourseDataFlag(WORLD_e world, STAGE_e level) const
{
    u8 worldIndex = static_cast<u8>(world);
    u8 levelIndex = static_cast<u8>(level);
    dMj2dGame_c::COURSE_COMPLETION_e completion = mCourseCompletion[worldIndex][levelIndex];

    if (fFeature::COMPLETED_ALL_LEVELS) {
        completion |= COURSE_COMPLETION_e::GOAL_MASK;
    }

    return completion;
}