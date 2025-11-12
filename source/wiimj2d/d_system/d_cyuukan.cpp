// d_cyuukan.cpp
// NSMBW .text: 0x8008ED70 - 0x8008F110

#include "d_cyuukan.h"

[[address(0x8008ED70)]]
dCyuukan_c::dCyuukan_c();

[[address(0x8008EDB0)]]
void dCyuukan_c::clear()
{
    m0x14 = 0;
    mWorld = WORLD_e(-1);
    mStage = STAGE_e(-1);
    mCourse = -1;
    mIsKinopioInChukan = false;
    mPlayerSetPos = {};
    mState = -1;
    for (int i = 0; i < std::size(mCollectionCoin); i++) {
        mCollectionCoin[i] = PLAYER_TYPE_e::COUNT;
    }
    for (int i = 0; i < std::size(m0x2C); i++) {
        m0x2C[i] = PLAYER_TYPE_e::COUNT;
    }
}

[[address(0x8008EE00)]]
void dCyuukan_c::courseIN();

[[address(0x8008EEC0)]]
bool dCyuukan_c::checkEntry();
