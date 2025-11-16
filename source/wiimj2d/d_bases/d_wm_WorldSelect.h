#pragma once

#include "d_system/d_base.h"

class daWmIsland_c;
class dWorldSelectGuide_c;

class dWorldSelect_c : public dBase_c
{
public:
    // Instance Variables
    // ^^^^^^

    FILL(0x070, 0x248);

    /* 0x248 */ daWmIsland_c* mpaIsland[9];
    /* 0x26C */ dWorldSelectGuide_c* mpWSelectGuide;
};
