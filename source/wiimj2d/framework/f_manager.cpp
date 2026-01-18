// f_manager.cpp
// NSMBW .text: 0x80162E30 - 0x80163140

#include "f_manager.h"

[[nsmbw(0x80162E40)]]
fBase_c* fManager_c::searchBaseByID(fBaseID_e id);

[[nsmbw(0x80162E90)]]
fBase_c* fManager_c::searchBaseByProfName(fProfName profName, const fBase_c* from);
