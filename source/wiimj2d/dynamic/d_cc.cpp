// d_cc.cpp
// NSMBW .text: 0x8008C200 - 0x8008DC80

#include "d_cc.h"

[[address(0x8008C200)]]
dCc_c::dCc_c();

/* VT+0x8 */
[[address(0x8008C260)]]
dCc_c::~dCc_c();

[[address(0x8008C380)]]
void dCc_c::release();

[[address(0x8008C9E0)]]
void dCc_c::execute();