#pragma once

#include <common/c_bitmask.h>
#include <dynamic/d_actor.h>
#include <dynamic/d_rc.h>

class daLineTrain_c : public dActor_c
{
public:
    // ----------------
    // Member Functions
    // ----------------

    /* 0x8085A990 */
    int numPlayersRide();

public:
    // -----------
    // Member Data
    // -----------

    FILL(0x0392, 0x1044);

    dRide2Point_c maRide2Point[9];

    FILL(0x1380, 0x1393);
    OFFSET_ASSERT(0x1393);

    // /* 0x1393 */ u8 mPlayerRideMask_Removed;
    // /* 0x1394 */ u8 mPrevPlayerRideMask_Removed;

    
#define TEMP_RIDE_MASK_SIZE 8 // TODO

#define OFFSET_dLineTrain_c_mPlayerRideMask 0x1393
    /* 0x1393 */ cBitmask_c<TEMP_RIDE_MASK_SIZE> mPlayerRideMask;
#define OFFSET_dLineTrain_c_mPrevPlayerRideMask                                                    \
    (OFFSET_dLineTrain_c_mPlayerRideMask + cBitmask_c_SIZE_ASM(TEMP_RIDE_MASK_SIZE))
    /* 0x1395? */ cBitmask_c<TEMP_RIDE_MASK_SIZE> mPrevPlayerRideMask;
};