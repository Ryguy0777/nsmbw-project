#pragma once

#include <cstdlib>
#include <framework/f_base_id.h>

class fBase_c
{
    SIZE_ASSERT(0x64);

public:
    // ------------
    // Constructors
    // ------------

    /* 0x80161C10 */
    fBase_c();

    /**
     * 0x80162A00
     * Operator new override for all bases. Bases are allocated in mHeap::g_gameHeaps[0] in a
     * top-down direction, and are zero-initialized.
     */
    static void* operator new(size_t);

    /**
     * 0x80162A60
     * Operator delete override for all bases.
     */
    static void operator delete(void*);

public:
    // -------------------
    // Constants and Types
    // -------------------

    /**
     * The possible lifecycle states.
     */
    enum LIFECYCLE_e {
        /**
         * The base's create operation has yet to conclude.
         */
        CREATING,
        /**
         * The base is in the main execution cycle.
         */
        ACTIVE,
        /**
         * The base's delete operation is about to run.
         */
        DELETING,
    };

    /**
     * The possible group types.
     */
    enum GROUP_TYPE_e {
        /**
         * The base is a dBase_c "generic process".
         */
        OTHER,
        /**
         * The base is a dScene_c "scene".
         */
        SCENE,
        /**
         * The base is an dBaseActor_c "actor".
         */
        ACTOR,
    };

    /**
     * The possible operation results.
     */
    enum MAIN_STATE_e {
        /**
         * The operation was canceled early.
         */
        CANCELED,
        /**
         * The operation could not be completed.
         */
        ERROR,
        /**
         * The operation was completed successfully.
         */
        SUCCESS,
        /**
         * The operation is waiting for something and cannot be completed yet.
         */
        WAITING,
    };

    /**
     * The possible operation step results.
     */
    enum PACK_RESULT_e {
        /**
         * The step could not completed at this time.
         */
        NOT_READY,
        /**
         * The step was completed successfully.
         */
        SUCCEEDED,
        /**
         * The step could not be completed.
         */
        FAILED,
    };

    /**
     * Controls if the execute and draw operations should be skipped.
     */
    enum PROC_DISABLE_e {
        /**
         * Execution is disabled, and this is a root base.
         */
        ROOT_DISABLE_EXECUTE = 1,
        /**
         * Execution is disabled.
         */
        DISABLE_EXECUTE = 2,
        /**
         * Drawing is disabled, and this is a root base.
         */
        ROOT_DISABLE_DRAW = 4,
        /**
         * Drawing is disabled.
         */
        DISABLE_DRAW = 8,
    };

public:
    // -----------
    // Member Data
    // -----------

    /**
     * Unique ID that is incremented for every created base.
     */
    /* 0x00 */ fBaseID_e mUniqueID;

    /**
     * The current unique ID.
     */
    /* 0x80429748 */ static fBaseID_e m_rootUniqueID;

    /**
     * A bitfield that configures the base's behaviour. (Represents nybbles 5 to 12 of Reggie's
     * spritedata).
     */
    /* 0x04 */ u32 mParam;

    /**
     * The base's profile name
     */
    /* 0x08 */ u16 mProfName; // The base's profile name.

    /**
     * The temporary state value for the profile name.
     */
    /* 0x8042A678 */ static u16 m_tmpCtProfName;

protected:
    /**
     * The base's lifecycle state. Value is a ::LIFECYCLE_e.
     */
    /* 0x0A */ u8 mLifecycleState;

    /**
     * If deletion of the base was requested, but the corresponding operation has not been scheduled
     * yet.
     */
    /* 0x0B */ bool mDeleteRequested;

    /**
     * If the create operation was completed, but scheduling the execute and draw operations isn't
     * possible at this time. If true, scheduling will be deferred to the next connect
     * operation.
     */
    /* 0x0C */ bool mDeferExecute;

    /**
     * If the create operation has not been completed, and rescheduling it isn't possible at this
     * time.If true, rescheduling will be deferred to the next connect
     * operation.
     */
    /* 0x0D */ bool mDeferRetryCreate;

    /**
     * The base's group type. Value is a ::GROUP_TYPE_e.
     */
    /* 0x0E */ u8 mGroupType;

    /**
     * The operations to be skipped. Value is a ::PROC_DISABLE_e.
     */
    /* 0x0F */ u8 mProcControl;

    /**
     * Checks if a flag is set in ::mProcControl.
     */
    bool isProcControlFlag(u8 flag) const
    {
        return (mProcControl & flag) != 0;
    }

    /**
     * Sets a flag in ::mProcControl.
     */
    void setProcControlFlag(u8 flag)
    {
        mProcControl |= flag;
    }

    /**
     * Clears a flag in ::mProcControl.
     */
    void clearProcControlFlag(u8 flag)
    {
        mProcControl &= ~flag;
    }

    // Temporary fill data
    /* 0x10 */ FILL(0x10, 0x60);

public:
    // -----------------
    // Virtual Functions
    // -----------------

    /**
     * VT+0x08 0x80161EC0
     * do method for the create operation.
     *
     * @return A PACK_RESULT_e value.
     */
    virtual int create();

    /**
     * VT+0x0C 0x80161ED0
     * pre method for the create operation.
     *
     * @return A PACK_RESULT_e value.
     */
    virtual int preCreate();

    /**
     * VT+0x10 0x80161EE0
     * post method for the create operation.
     */
    virtual void postCreate(MAIN_STATE_e state);

    /**
     * VT+0x14 0x80161F70
     * do method for the delete operation. This method was renamed due to conflict with the delete
     * C++ keyword.
     *
     * @return A PACK_RESULT_e value.
     */
    virtual int doDelete();

    /**
     * VT+0x18 0x80162030
     * pre method for the delete operation.
     *
     * @return A PACK_RESULT_e value.
     */
    virtual int preDelete();

    /**
     * VT+0x1C 0x801620A0
     * post method for the delete operation.
     */
    virtual void postDelete(MAIN_STATE_e state);

    /**
     * VT+0x20 0x80162210
     * do method for the execute operation.
     *
     * @return A PACK_RESULT_e value.
     */
    virtual int execute();

    /**
     * VT+0x24 0x80162220
     * pre method for the execute operation.
     *
     * @return A PACK_RESULT_e value.
     */
    virtual int preExecute();

    /**
     * VT+0x28 0x80162250
     * post method for the execute operation.
     */
    virtual void postExecute(MAIN_STATE_e state);

    /**
     * VT+0x2C 0x80162310
     * do method for the draw operation.
     *
     * @return A PACK_RESULT_e value.
     */
    virtual int draw();

    /**
     * VT+0x30 0x80162320
     * pre method for the draw operation.
     *
     * @return A PACK_RESULT_e value.
     */
    virtual int preDraw();

    /**
     * VT+0x34 0x80162350
     * post method for the draw operation.
     */
    virtual void postDraw(MAIN_STATE_e state);

    /**
     * VT+0x38 0x80162410
     * Informs the base that it's about to be deleted.
     */
    virtual void deleteReady();

    /**
     * VT+0x3C 0x80162730
     * @unused Creates a heap of the given size for the base. If the requested heap space is not
     * available, the heap is adjusted to allocate all the available memory. If that also fails, the
     * base is deleted.
     *
     * @param size The heap's size, or -1 to allocate all available space.
     * @param parentHeap The parent heap, or nullptr to use the current heap.
     * @return If the heap creation was successful.
     */
    virtual bool entryFrmHeap(u32 size, void* parentHeap);

    /**
     * VT+0x40 0x80162930
     * @unused Creates a heap of the given size for the base. Unlike ::entryFrmHeap, the base is
     * immediately deleted if the requested space is not available.
     *
     * @param size The heap's size, or -1 to allocate all available space.
     * @param parentHeap The parent heap, or nullptr to use the current heap.
     * @return If the heap creation was successful.
     */
    virtual bool entryFrmHeapNonAdjust(u32 size, void* parentHeap);

    /**
     * VT+0x44 0x801629F0
     * @unused Does nothing.
     */
    virtual bool createHeap();

    /**
     * VT+0x48 0x80161D80
     * Destroys the base.
     */
    virtual ~fBase_c();

public:
    // ---------
    // Functions
    // ---------

    /**
     * 0x80162650
     * Requests deletion of the base. Calling this function multiple times has no effect.
     */
    void deleteRequest();
};