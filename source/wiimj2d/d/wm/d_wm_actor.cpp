// d_wm_actor.cpp
// NSMBW: 0x800F2820 - 0x800F2C00

#include "d_wm_actor.h"

EXTERN_TEXT(
  0x800F2820, //
  dWmActor_c::dWmActor_c()
);

/**
 * VT+0x48
 * Destroys the base.
 */
EXTERN_TEXT(
  0x800F2880, //
  dWmActor_c::~dWmActor_c()
);

/**
 * VT+0x0C
 * pre method for the create operation.
 * @return A PACK_RESULT_e value.
 */
EXTERN_TEXT(
  0x800F28E0, //
  int dWmActor_c::preCreate()
);

/**
 * VT+0x10
 * post method for the create operation.
 */
EXTERN_TEXT(
  0x800F2910, //
  void dWmActor_c::postCreate(fBase_c::MAIN_STATE_e status)
);

/**
 * VT+0x18
 * pre method for the delete operation.
 * @return A PACK_RESULT_e value.
 */
EXTERN_TEXT(
  0x800F2920, //
  int dWmActor_c::preDelete()
);

/**
 * VT+0x1C
 * post method for the delete operation.
 */
EXTERN_TEXT(
  0x800F2950, //
  void dWmActor_c::postDelete(fBase_c::MAIN_STATE_e status)
);

/**
 * VT+0x24
 * pre method for the execute operation.
 * @return A PACK_RESULT_e value.
 */
EXTERN_TEXT(
  0x800F2960, //
  int dWmActor_c::preExecute()
);

/**
 * VT+0x28
 * post method for the execute operation.
 */
EXTERN_TEXT(
  0x800F2A10, //
  void dWmActor_c::postExecute(fBase_c::MAIN_STATE_e status)
);

/**
 * VT+0x30
 * pre method for the draw operation.
 * @return A PACK_RESULT_e value.
 */
EXTERN_TEXT(
  0x800F2A20, //
  int dWmActor_c::preDraw()
);

/**
 * VT+0x34
 * post method for the draw operation.
 */
EXTERN_TEXT(
  0x800F2AF0, //
  void dWmActor_c::postDraw(fBase_c::MAIN_STATE_e status)
);

/**
 * VT+0x58
 * Gets the actor kind. See dBaseActor_c::ACTOR_KIND_e.
 */
EXTERN_TEXT(
  0x800F2B60, //
  dBaseActor_c::ACTOR_KIND_e dWmActor_c::GetActorType()
);

/**
 * Creates a world map actor without a parent. See dBaseActor_c::construct.
 */
EXTERN_TEXT(
  0x800F2B00, //
  dWmActor_c* dWmActor_c::construct(
    u16 profName, unsigned long param, const mVec3_c* position, const mAng3_c* rotation
  )
);

/**
 * Creates a child world map actor with the given parent. See dBaseActor_c::construct.
 */
EXTERN_TEXT(
  0x800F2B10, //
  dWmActor_c* dWmActor_c::construct(
    u16 profName, dBase_c* base, unsigned long param, const mVec3_c* position,
    const mAng3_c* rotation
  )
);

/**
 * Sets the soft light effect for map actors.
 */
EXTERN_TEXT(
  0x800F2B20, //
  void dWmActor_c::setSoftLight_Map(m3d::bmdl_c& mdl)
);

/**
 * Sets the soft light effect for map objects.
 */
EXTERN_TEXT(
  0x800F2B30, //
  void dWmActor_c::setSoftLight_MapObj(m3d::bmdl_c& mdl)
);

/**
 * Sets the soft light effect for enemies.
 */
EXTERN_TEXT(
  0x800F2B40, //
  void dWmActor_c::setSoftLight_Enemy(m3d::bmdl_c& mdl)
);

/**
 * Sets the soft light effect for bosses.
 */
EXTERN_TEXT(
  0x800F2B50, //
  void dWmActor_c::setSoftLight_Boss(m3d::bmdl_c& mdl)
);