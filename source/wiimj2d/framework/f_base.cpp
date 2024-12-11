// f_base.cpp
// NSMBW .text: 0x80161C10 - 0x80162C80

#include "f_base.h"

[[address(0x80161C10)]]
fBase_c::fBase_c();

/**
 * VT+0x48
 * Destroys the base.
 */
[[address(0x80161D80)]]
fBase_c::~fBase_c();

/**
 * VT+0x08
 * do method for the create operation.
 *
 * @return A PACK_RESULT_e value.
 */
[[address(0x80161EC0)]]
int fBase_c::create();

/**
 * VT+0x0C
 * pre method for the create operation.
 *
 * @return A PACK_RESULT_e value.
 */
[[address(0x80161ED0)]]
int fBase_c::preCreate();

/**
 * VT+0x10
 * post method for the create operation.
 */
[[address(0x80161EE0)]]
void fBase_c::postCreate(MAIN_STATE_e state);

/**
 * VT+0x14
 * do method for the delete operation. This method was renamed due to conflict with the delete
 * C++ keyword.
 *
 * @return A PACK_RESULT_e value.
 */
[[address(0x80161F70)]]
int fBase_c::doDelete();

/**
 * VT+0x18
 * pre method for the delete operation.
 *
 * @return A PACK_RESULT_e value.
 */
[[address(0x80162030)]]
int fBase_c::preDelete();

/**
 * VT+0x1C
 * post method for the delete operation.
 */
[[address(0x801620A0)]]
void fBase_c::postDelete(MAIN_STATE_e state);

/**
 * VT+0x20
 * do method for the execute operation.
 *
 * @return A PACK_RESULT_e value.
 */
[[address(0x80162210)]]
int fBase_c::execute();

/**
 * VT+0x24
 * pre method for the execute operation.
 *
 * @return A PACK_RESULT_e value.
 */
[[address(0x80162220)]]
int fBase_c::preExecute();

/**
 * VT+0x28
 * post method for the execute operation.
 */
[[address(0x80162250)]]
void fBase_c::postExecute(MAIN_STATE_e state);

/**
 * VT+0x2C
 * do method for the draw operation.
 *
 * @return A PACK_RESULT_e value.
 */
[[address(0x80162310)]]
int fBase_c::draw();

/**
 * VT+0x30
 * pre method for the draw operation.
 *
 * @return A PACK_RESULT_e value.
 */
[[address(0x80162320)]]
int fBase_c::preDraw();

/**
 * VT+0x34
 * post method for the draw operation.
 */
[[address(0x80162350)]]
void fBase_c::postDraw(MAIN_STATE_e state);

/**
 * VT+0x38
 * Informs the base that it's about to be deleted.
 */
[[address(0x80162410)]]
void fBase_c::deleteReady();

/**
 * Requests deletion of the base. Calling this function multiple times has no effect.
 */
[[address(0x80162650)]]
void fBase_c::deleteRequest();

/**
 * VT+0x3C
 * @unused Creates a heap of the given size for the base. If the requested heap space is not
 * available, the heap is adjusted to allocate all the available memory. If that also fails, the
 * base is deleted.
 *
 * @param size The heap's size, or -1 to allocate all available space.
 * @param parentHeap The parent heap, or nullptr to use the current heap.
 * @return If the heap creation was successful.
 */
[[address(0x80162730)]]
bool fBase_c::entryFrmHeap(u32 size, void* parentHeap);

/**
 * VT+0x40
 * @unused Creates a heap of the given size for the base. Unlike ::entryFrmHeap, the base is
 * immediately deleted if the requested space is not available.
 *
 * @param size The heap's size, or -1 to allocate all available space.
 * @param parentHeap The parent heap, or nullptr to use the current heap.
 * @return If the heap creation was successful.
 */
[[address(0x80162930)]]
bool fBase_c::entryFrmHeapNonAdjust(u32 size, void* parentHeap);

/**
 * VT+0x44
 * @unused Does nothing.
 */
[[address(0x801629F0)]]
bool fBase_c::createHeap();

/**
 * Operator new override for all bases. Bases are allocated in mHeap::g_gameHeaps[0] in a
 * top-down direction, and are zero-initialized.
 */
[[address(0x80162A00)]]
void* fBase_c::operator new(size_t);

/**
 * Operator delete override for all bases.
 */
[[address(0x80162A60)]]
void fBase_c::operator delete(void*);
