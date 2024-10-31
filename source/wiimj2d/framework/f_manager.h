#pragma once

#include "f_base.h"
#include "f_base_id.h"

class fManager_c
{
public:
    // ----------------
    // Static Functions
    // ----------------

    /* 0x80162E40 */
    static fBase_c* searchBaseByID(fBaseID_e id);
};