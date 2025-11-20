// d_a_jr_clown_for_player.cpp
// NSMBW .text: 0x8080F910 - 0x80813760

#include "d_a_jr_clown_for_player.h"
#include "machine/m_3d_fanm.h"

[[address(0x808116B0)]]
void daJrClownForPlayer_c::setPlayerEmblem(int playerNo)
{
    mResPat = mRes.GetResAnmTexPat("ply_change");

    mPlyChangePat.setAnm(mModel, mResPat, 0, m3d::playMode_e::PLAY_MODE_1);
    float frame = 0.0;
    frame = static_cast<float>(playerNo + 1);

    mPlyChangePat.setFrame(frame, 0);
    mPlyChangePat.setRate(0.0, 0);
}