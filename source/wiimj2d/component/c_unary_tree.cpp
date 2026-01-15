// c_unary_tree.cpp
// NSMBW .text: 0x80161880 - 0x80161A60

#include "c_unary_tree.h"

/**
 * @unofficial
 * Looks like a badly stripped assert.
 */
[[nsmbw(0x80161880)]]
void cUnaryTree_Fatal();

[[nsmbw(0x80161890)]]
void cUnaryTreeMg_c::add(cUnaryTreeNd_c* nd, void* owner);

[[nsmbw(0x80161940)]]
void cUnaryTreeMg_c::remove(cUnaryTreeNd_c* nd, void* owner);

[[nsmbw(0x80161A00)]]
void cUnaryTreeMg_c::clear();
