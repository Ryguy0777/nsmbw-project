// d_wm_demo_actor.cpp
// NSMBW .text: 0x800F60E0 - 0x800F7050

#include "d_wm_demo_actor.h"

[[nsmbw(0x800F60E0)]]
dWmDemoActor_c::dWmDemoActor_c();

/* VT+0x60 */
[[nsmbw(0x800F61C0)]]
void dWmDemoActor_c::VT_0x60();

/* VT+0x68 */
[[nsmbw(0x800F61E0)]]
void dWmDemoActor_c::setCutEnd();

[[nsmbw(0x800F6820)]]
void dWmDemoActor_c::CreateShadowModel(
  const char* param1, const char* param2, const char* param3, bool param4
);

/* VT+0x6C */
[[nsmbw(0x800F6EE0)]]
void dWmDemoActor_c::clearCutEnd();

/* VT+0x64 */
[[nsmbw(0x800F6EF0)]]
bool dWmDemoActor_c::checkCutEnd();

/**
 * VT+0x48
 * Destroys the base.
 */
[[nsmbw(0x800F6F40)]]
dWmDemoActor_c::~dWmDemoActor_c();

/**
 * VT+0x14
 * do method for the delete operation. This method was renamed due to conflict with the delete
 * C++ keyword.
 */
[[nsmbw(0x800F6F10)]]
fBase_c::PACK_RESULT_e dWmDemoActor_c::doDelete();

/**
 * VT+0x2C
 * do method for the draw operation.
 */
[[nsmbw(0x800F6F20)]]
fBase_c::PACK_RESULT_e dWmDemoActor_c::draw();

/**
 * VT+0x08
 * do method for the create operation.
 */
[[nsmbw(0x800F6F30)]]
fBase_c::PACK_RESULT_e dWmDemoActor_c::create();