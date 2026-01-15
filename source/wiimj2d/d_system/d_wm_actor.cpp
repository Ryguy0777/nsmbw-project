// d_wm_actor.cpp
// NSMBW .text: 0x800F2820 - 0x800F2C00

#include "d_wm_actor.h"

[[nsmbw(0x800F2820)]]
dWmActor_c::dWmActor_c();

/**
 * VT+0x48
 * Destroys the base.
 */
[[nsmbw(0x800F2880)]]
dWmActor_c::~dWmActor_c();

/**
 * VT+0x0C
 * pre method for the create operation.
 */
[[nsmbw(0x800F28E0)]]
fBase_c::PACK_RESULT_e dWmActor_c::preCreate();

/**
 * VT+0x10
 * post method for the create operation.
 */
[[nsmbw(0x800F2910)]]
void dWmActor_c::postCreate(fBase_c::MAIN_STATE_e status);

/**
 * VT+0x18
 * pre method for the delete operation.
 */
[[nsmbw(0x800F2920)]]
fBase_c::PACK_RESULT_e dWmActor_c::preDelete();

/**
 * VT+0x1C
 * post method for the delete operation.
 */
[[nsmbw(0x800F2950)]]
void dWmActor_c::postDelete(fBase_c::MAIN_STATE_e status);

/**
 * VT+0x24
 * pre method for the execute operation.
 */
[[nsmbw(0x800F2960)]]
fBase_c::PACK_RESULT_e dWmActor_c::preExecute();

/**
 * VT+0x28
 * post method for the execute operation.
 */
[[nsmbw(0x800F2A10)]]
void dWmActor_c::postExecute(fBase_c::MAIN_STATE_e status);

/**
 * VT+0x30
 * pre method for the draw operation.
 */
[[nsmbw(0x800F2A20)]]
fBase_c::PACK_RESULT_e dWmActor_c::preDraw();

/**
 * VT+0x34
 * post method for the draw operation.
 */
[[nsmbw(0x800F2AF0)]]
void dWmActor_c::postDraw(fBase_c::MAIN_STATE_e status);

/**
 * VT+0x58
 * Gets the actor kind. See dBaseActor_c::ACTOR_KIND_e.
 */
[[nsmbw(0x800F2B60)]]
dBaseActor_c::ACTOR_KIND_e dWmActor_c::GetActorType();

/**
 * Creates a world map actor without a parent. See dBaseActor_c::construct.
 */
[[nsmbw(0x800F2B00)]]
dWmActor_c* dWmActor_c::construct(
  u16 profName, unsigned long param, const mVec3_c* position, const mAng3_c* rotation
);

/**
 * Creates a child world map actor with the given parent. See dBaseActor_c::construct.
 */
[[nsmbw(0x800F2B10)]]
dWmActor_c* dWmActor_c::construct(
  u16 profName, dBase_c* base, unsigned long param, const mVec3_c* position, const mAng3_c* rotation
);

/**
 * Sets the soft light effect for map actors.
 */
[[nsmbw(0x800F2B20)]]
void dWmActor_c::setSoftLight_Map(m3d::bmdl_c& mdl);

/**
 * Sets the soft light effect for map objects.
 */
[[nsmbw(0x800F2B30)]]
void dWmActor_c::setSoftLight_MapObj(m3d::bmdl_c& mdl);

/**
 * Sets the soft light effect for enemies.
 */
[[nsmbw(0x800F2B40)]]
void dWmActor_c::setSoftLight_Enemy(m3d::bmdl_c& mdl);

/**
 * Sets the soft light effect for bosses.
 */
[[nsmbw(0x800F2B50)]]
void dWmActor_c::setSoftLight_Boss(m3d::bmdl_c& mdl);