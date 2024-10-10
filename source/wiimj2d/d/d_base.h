#pragma once

#include <f/f_base.h>

/**
 * An extension of fBase_c with base kind and name strings. All bases should
 * inherit from this class, not from fBase_c.
 */
class dBase_c : public fBase_c
{
public:
    /* 0x8006C420 */
    dBase_c();

    /**
     * VT+0x48 0x8006C490
     * Destroys the base.
     */
    virtual ~dBase_c() override;

    /**
     * VT+0x0C 0x8006C540
     * pre method for the create operation.
     * @return A ::PACK_RESULT_e value.
     */
    virtual int preCreate() override;

    /**
     * VT+0x10 0x8006C570
     * post method for the create operation.
     */
    virtual void postCreate(MAIN_STATE_e state) override;

    /**
     * VT+0x18 0x8006C580
     * pre method for the delete operation.
     * @return A ::PACK_RESULT_e value.
     */
    virtual int preDelete() override;

    /**
     * VT+0x1C 0x8006C5B0
     * post method for the delete operation.
     */
    virtual void postDelete(MAIN_STATE_e state) override;

    /**
     * VT+0x24 0x8006C5C0
     * pre method for the execute operation.
     * @return A ::PACK_RESULT_e value.
     */
    virtual int preExecute() override;

    /**
     * VT+0x28 0x8006C600
     * post method for the execute operation.
     */
    virtual void postExecute(MAIN_STATE_e state) override;

    /**
     * VT+0x30 0x8006C610
     * pre method for the draw operation.
     * @return A ::PACK_RESULT_e value.
     */
    virtual int preDraw() override;

    /**
     * VT+0x34 0x8006C650
     * post method for the draw operation.
     */
    virtual void postDraw(MAIN_STATE_e state) override;

    /**
     * VT+0x4C 0x8006C660
     * Gets a string describing the kind of this base.
     */
    virtual const char* getKindString() const;

    /* 0x64 */ u32 m_0x64;

    /**
     * A string describing the kind of this base.
     */
    /* 0x68 */ const char* mpKindString;

    /**
     * A string representing the name of the profile this base belongs to.
     */
    /* 0x6C */ const char* mpNameString;
};

static_assert(sizeof(dBase_c) == 0x70);