// d_wm_demo_actor.cpp
// NSMBW: 0x800F60E0 - 0x800F7050

#include "d_wm_demo_actor.h"

EXTERN_TEXT(
  0x800F60E0, //
  dWmDemoActor_c::dWmDemoActor_c()
);

/* VT+0x60 */
EXTERN_TEXT(
  0x800F61C0, //
  void dWmDemoActor_c::VT_0x60()
);

/* VT+0x68 */
EXTERN_TEXT(
  0x800F61E0, //
  void dWmDemoActor_c::setCutEnd()
);

/* VT+0x6C */
EXTERN_TEXT(
  0x800F6EE0, //
  void dWmDemoActor_c::clearCutEnd()
);

/* VT+0x64 */
EXTERN_TEXT(
  0x800F6EF0, //
  bool dWmDemoActor_c::checkCutEnd()
);

/**
 * VT+0x48
 * Destroys the base.
 */
EXTERN_TEXT(
  0x800F6F40, //
  dWmDemoActor_c::~dWmDemoActor_c()
);

/**
 * VT+0x14
 * do method for the delete operation. This method was renamed due to conflict with the delete
 * C++ keyword.
 *
 * @return A PACK_RESULT_e value.
 */
EXTERN_TEXT(
  0x800F6F10, //
  int dWmDemoActor_c::doDelete()
);

/**
 * VT+0x2C
 * do method for the draw operation.
 *
 * @return A PACK_RESULT_e value.
 */
EXTERN_TEXT(
  0x800F6F20, //
  int dWmDemoActor_c::draw()
);

/**
 * VT+0x08
 * do method for the create operation.
 *
 * @return A PACK_RESULT_e value.
 */
EXTERN_TEXT(
  0x800F6F30, //
  int dWmDemoActor_c::create()
);