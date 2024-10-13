#pragma once

#include "System.h"
#include <dynamic/d_base_actor.h>
#include <machine/m_sphere.h>

namespace m3d
{
class bmdl_c;
} // namespace m3d

/**
 * Base class for world map actors.
 */
class dWmActor_c : public dBaseActor_c
{
    SIZE_ASSERT(0x138);

public:
    /* 0x800F2820 */
    dWmActor_c();

    /**
     * VT+0x48 0x800F2880
     * Destroys the base.
     */
    virtual ~dWmActor_c() override;

    /**
     * VT+0x0C 0x800F28E0
     * pre method for the create operation.
     * @return A PACK_RESULT_e value.
     */
    virtual int preCreate() override;

    /**
     * VT+0x10 0x800F2910
     * post method for the create operation.
     */
    virtual void postCreate(fBase_c::MAIN_STATE_e status) override;

    /**
     * VT+0x18 0x800F2920
     * pre method for the delete operation.
     * @return A PACK_RESULT_e value.
     */
    virtual int preDelete() override;

    /**
     * VT+0x1C 0x800F2950
     * post method for the delete operation.
     */
    virtual void postDelete(fBase_c::MAIN_STATE_e status) override;

    /**
     * VT+0x24 0x800F2960
     * pre method for the execute operation.
     * @return A PACK_RESULT_e value.
     */
    virtual int preExecute() override;

    /**
     * VT+0x28 0x800F2A10
     * post method for the execute operation.
     */
    virtual void postExecute(fBase_c::MAIN_STATE_e status) override;

    /**
     * VT+0x30 0x800F2A20
     * pre method for the draw operation.
     * @return A PACK_RESULT_e value.
     */
    virtual int preDraw() override;

    /**
     * VT+0x34 0x800F2AF0
     * post method for the draw operation.
     */
    virtual void postDraw(fBase_c::MAIN_STATE_e status) override;

    /**
     * VT+0x58 0x800F2B60
     * Gets the actor kind. See dBaseActor_c::ACTOR_KIND_e.
     */
    virtual ACTOR_KIND_e GetActorType() override;

    /**
     * 0x800F2B00
     * Creates a world map actor without a parent. See dBaseActor_c::construct.
     */
    static dWmActor_c*
    construct(u16 profName, unsigned long param, const mVec3_c* position, const mAng3_c* rotation);

    /**
     * 0x800F2B10
     * Creates a child world map actor with the given parent. See dBaseActor_c::construct.
     */
    static dWmActor_c* construct(
      u16 profName, dBase_c* base, unsigned long param, const mVec3_c* position,
      const mAng3_c* rotation
    );

    /**
     * 0x800F2B20
     * Sets the soft light effect for map actors.
     */
    static void setSoftLight_Map(m3d::bmdl_c& mdl);

    /**
     * 0x800F2B30
     * Sets the soft light effect for map objects.
     */
    static void setSoftLight_MapObj(m3d::bmdl_c& mdl);

    /**
     * 0x800F2B40
     * Sets the soft light effect for enemies.
     */
    static void setSoftLight_Enemy(m3d::bmdl_c& mdl);

    /**
     * 0x800F2B50
     * Sets the soft light effect for bosses.
     */
    static void setSoftLight_Boss(m3d::bmdl_c& mdl);

private:
    /**
     * A sphere representing the actor's visible area.
     */
    /* 0x128 */ mSphere_c mCullSphere;
};
