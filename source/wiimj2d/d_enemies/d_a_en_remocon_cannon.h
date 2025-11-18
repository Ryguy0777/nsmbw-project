#pragma once

#include "d_system/d_enemy.h"

class daEnRemoconCannon_c : public dEn_c
{
public:
    // Instance Methods
    // ^^^^^^

    /* 0x80A964E0 */
    bool UNDEF_80a964e0(short target);

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x524, 0x778);

    /* 0x778 */ int mPlayerNo;

    FILL(0x77C, 0x7A4);

    /* 0x7A4 */ short mTargetAngle;

    FILL(0x7A6, 0xB60);
};