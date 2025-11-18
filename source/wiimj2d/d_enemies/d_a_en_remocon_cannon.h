#pragma once

#include "d_system/d_enemy.h"
#include "machine/m_3d_anmtexpat.h"
#include <nw4r/g3d/g3d_resfile.h>

class daEnRemoconCannon_c : public dEn_c
{
public:
    // Instance Methods
    // ^^^^^^

    /* 0x80A95890 */
    void setBodyColor();

    /* 0x80A964E0 */
    bool UNDEF_80a964e0(short target);

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x524, 0x778);

    /* 0x778 */ int mPlayerNo;

    FILL(0x77C, 0x7A4);

    /* 0x7A4 */ short mTargetAngle;

    FILL(0x7A6, 0x7BC);

    /* 0x7BC */ nw4r::g3d::ResFile mRes;

    FILL(0x7C0, 0x888);

    /* 0x888 */ bool mHasPlayer;

    FILL(0x889, 0x898);

    /* 0x898 */ m3d::anmTexPat_c mAnmTexPat;

    FILL(0x8C4, 0xB54);

    /* 0xB54 */ int mPlayerNo2;

    FILL(0xB58, 0xB60);
};