#pragma once

#include "machine/m_vec.h"

class dActor_c;

class dRc_c
{
public:
    /* VT+0x08 */
    virtual ~dRc_c();

public:
    // Instance Variables
    // ^^^^^^

    /* 0x04 */ dActor_c* mpOwner;
    /* 0x08 */ mVec3_c* mpOwnerPos;
    /* 0x0C */ dRc_c* mpNext;
};

class dRide_ctr_c
{
    SIZE_ASSERT(0x4C);

    /* 0x00 VTABLE 0x80319158 */

public:
    // Structors
    // ^^^^^^

    /* 0x800DAEA0 */
    dRide_ctr_c();

    /* VT+0x08 0x800DAEF0 */
    virtual ~dRide_ctr_c();

public:
    // Instance Variables
    // ^^^^^^

    /* 0x04 */ dActor_c* mpOwner;
    /* 0x08 */ dRide_ctr_c* mpPrev;
    /* 0x0C */ dRide_ctr_c* mpNext;
    /* 0x10 */ dRc_c* mpChain;

    FILL(0x14, 0x4C);
};

class dRideRoll_c : public dRide_ctr_c
{
    SIZE_ASSERT(0x60);

public:
    // Structors
    // ^^^^^^

    dRideRoll_c();

    /* VT+0x08 */
    virtual ~dRideRoll_c() override;

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x4C, 0x60);
};

class dRide2Point_c : public dRide_ctr_c
{
    SIZE_ASSERT(0x5C);

public:
    // Structors
    // ^^^^^^

    /* 0x800DB540 */
    dRide2Point_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x4C, 0x5C);
};
