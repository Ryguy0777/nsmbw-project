#pragma once

#include "machine/m_vec.h"

class dAcPy_c;

class dBgGm_c
{
public:
    // Instance Methods
    // ^^^^^^

    /* 0x80154F90 @unofficial */
    bool inW2CastleMazeBounds(float param1, float param2);

    /* 0x801550A0 */
    int execute();

    /* 0x80156960 */
    dAcPy_c* getNumberPlayerP(int player);

    /* 0x80156A10 */
    int getActScrPlayerNum();

    /* 0x80156BF0 */
    bool UNDEF_80156BF0(void* param1, void* param2, void* param3);

    /* 0x80156D70 @unofficial */
    bool isManualZoomActive(void* param1);

    bool isAutoscroll() const
    {
        return mIsAutoscroll;
    }

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x00000, 0x00110);

    /* 0x00110 */ float m0x00110;
    /* 0x00114 */ u8 m0x00114;

    FILL(0x00115, 0x900C6);

    /* 0x900C6 */ bool mIsAutoscroll;
};
