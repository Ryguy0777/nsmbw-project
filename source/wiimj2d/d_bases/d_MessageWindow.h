#pragma once

#include "d_system/d_base.h"

class dMessageWindow_c : public dBase_c
{
public:
    FILL(0x070, 0x254);

    /* 0x254 */ bool mReady;
};
