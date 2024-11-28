// d_attention.cpp
// NSMBW: 0x800690F0 - 0x80069500

#include "d_attention.h"

[[address_data(0x8042A030)]]
dAttention_c* dAttention_c::mspInstance;

[[address(0x800691B0)]]
void dAttention_c::update();
