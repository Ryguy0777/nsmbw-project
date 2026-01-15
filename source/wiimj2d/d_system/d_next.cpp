// d_next.cpp
// NSMBW .text: 0x800CFCE0 - 0x800D03C0

#include "d_next.h"

[[nsmbw_data(0x8042A2A0)]]
dNext_c* dNext_c::m_instance;

[[nsmbw(0x800D0360)]]
void dNext_c::execute();