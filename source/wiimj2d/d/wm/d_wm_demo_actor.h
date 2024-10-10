#pragma once

#include <d/wm/d_wm_actor.h>

class dWmDemoActor_c : public dWmActor_c
{
    /* 0x060 VTABLE 0x8031C170 */

public:
    /* 0x800F60E0 */
    dWmDemoActor_c();

    /**
     * VT+0x48 0x800F6F40
     * Destroys the base.
     */
    virtual ~dWmDemoActor_c() override;

    /**
     * VT+0x08 0x800F6F30
     * do method for the create operation.
     *
     * @return A PACK_RESULT_e value.
     */
    virtual int create() override;

    /**
     * VT+0x14 0x800F6F10
     * do method for the delete operation. This method was renamed due to conflict with the delete
     * C++ keyword.
     *
     * @return A PACK_RESULT_e value.
     */
    virtual int doDelete() override;

    /**
     * VT+0x20
     * do method for the execute operation.
     *
     * @return A PACK_RESULT_e value.
     */
    virtual int execute() override = 0;

    /**
     * VT+0x2C 0x800F6F20
     * do method for the draw operation.
     *
     * @return A PACK_RESULT_e value.
     */
    virtual int draw() override;

    /* VT+0x60 0x800F61C0 */
    virtual void VT_0x60();

    /* VT+0x64 0x800F6EF0, 0x808C82F0 */
    virtual bool checkCutEnd();

    /* VT+0x68 0x800F61E0, 0x808C82D0 */
    virtual void setCutEnd();

    /* VT+0x6C 0x800F6EE0, 0x808C82E0 */
    virtual void clearCutEnd();

    /* 800F6820 */
    void UNDEF_800F6820(const char* param_1, const char* param_2, const char* param_3, s32 param_4);

    FILL(0x138, 0x174);
};

static_assert(sizeof(dWmDemoActor_c) == 0x174);