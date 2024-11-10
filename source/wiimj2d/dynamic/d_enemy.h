#pragma once

#include <dynamic/d_actor.h>

class dCc_c;

class dEn_c : public dActor_c{
public:
    /* 0x80095950 */
    static void normal_collcheck(dCc_c* object, dCc_c* other);
};