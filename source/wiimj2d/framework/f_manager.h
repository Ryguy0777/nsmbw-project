#pragma once

#include "f_base.h"
#include "f_base_id.h"
#include "f_profile.h"

class fManager_c
{
public:
    // Static Methods
    // ^^^^^^

    /* 0x80162E40 */
    static fBase_c* searchBaseByID(fBaseID_e id);

    /* 0x80162E90 */
    static fBase_c* searchBaseByProfName(fProfName profName, const fBase_c* from = nullptr);

    /* 0x80162EF0 */
    static fBase_c* searchBaseByGroupType(u8 groupType, const fBase_c* from = nullptr);
};
