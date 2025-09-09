// d_mj2d_header.cpp
// NSMBW .text: 0x800CE660 - 0x800CE7F0

#include "d_mj2d_header.h"

#include <cstring>

[[address(0x800CE660)]]
dMj2dHeader_c::dMj2dHeader_c();

[[address(0x800CE670)]]
void dMj2dHeader_c::initialize()
{
    std::memset(this, 0, sizeof(dMj2dHeader_c));

    std::memcpy(mMagic, "glup", 4);

    mRevision.mMajor = SAVE_REVISION_MAJOR;
    mRevision.mMinor = SAVE_REVISION_MINOR;
}

[[address(0x800CE6F0)]]
u16 dMj2dHeader_c::getPlayCountFreeMode(WORLD_e world, STAGE_e level) const
{
    return mPlayCountFreeMode[static_cast<int>(world)][static_cast<int>(level)];
}

[[address(0x800CE710)]]
void dMj2dHeader_c::setPlayCountFreeMode(WORLD_e world, STAGE_e level, int count)
{
    mPlayCountFreeMode[static_cast<int>(world)][static_cast<int>(level)] = count;
}

[[address(0x800CE730)]]
u16 dMj2dHeader_c::getPlayCountCoinBattle(WORLD_e world, STAGE_e level) const
{
    return mPlayCountCoinBattle[static_cast<int>(world)][static_cast<int>(level)];
}

[[address(0x800CE750)]]
void dMj2dHeader_c::setPlayCountCoinBattle(WORLD_e world, STAGE_e level, int count)
{
    mPlayCountCoinBattle[static_cast<int>(world)][static_cast<int>(level)] = count;
}

[[address(0x800CE770)]]
void dMj2dHeader_c::onMultiWorldOpenFlag(WORLD_e world)
{
    mMultiWorldOpenFlag |= 1 << static_cast<int>(world);
}

[[address(0x800CE790)]]
bool dMj2dHeader_c::isMultiWorldOpenFlag(WORLD_e world)
{
    return mMultiWorldOpenFlag & (1 << static_cast<int>(world));
}

[[address(0x800CE7B0)]]
void dMj2dHeader_c::versionUpdate()
{
    if (mRevision.mMajor != SAVE_REVISION_MAJOR) {
        initialize();
    }

    mRevision.mMajor = SAVE_REVISION_MAJOR;
}