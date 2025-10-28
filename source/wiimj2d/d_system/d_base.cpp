// d_base.cpp
// NSMBW .text: 0x8006C420 - 0x8006C6D0

#include "d_base.h"

#include "d_bases/d_prof.h"
#include <revolution/os.h>

[[address(0x8006C420)]]
dBase_c::dBase_c()
{
    mpKindString = getKindString();
    mpNameString = dProf::getName(mProfName);

    OS_REPORT("Created base: %s\n", mpNameString);
}

/**
 * VT+0x48
 * Destroys the base.
 */
[[address(0x8006C490)]]
dBase_c::~dBase_c()
{
    mOwnedTree.~cUnaryTreeMg_c();
}

/**
 * VT+0x0C
 * pre method for the create operation.
 */
[[address(0x8006C540)]]
fBase_c::PACK_RESULT_e dBase_c::preCreate();

/**
 * VT+0x10
 * post method for the create operation.
 */
[[address(0x8006C570)]]
void dBase_c::postCreate(MAIN_STATE_e state);

/**
 * VT+0x18
 * pre method for the delete operation.
 */
[[address(0x8006C580)]]
fBase_c::PACK_RESULT_e dBase_c::preDelete();

/**
 * VT+0x1C
 * post method for the delete operation.
 */
[[address(0x8006C5B0)]]
void dBase_c::postDelete(MAIN_STATE_e state);

/**
 * VT+0x24
 * pre method for the execute operation.
 */
[[address(0x8006C5C0)]]
fBase_c::PACK_RESULT_e dBase_c::preExecute();

/**
 * VT+0x28
 * post method for the execute operation.
 */
[[address(0x8006C600)]]
void dBase_c::postExecute(MAIN_STATE_e state);

/**
 * VT+0x30
 * pre method for the draw operation.
 */
[[address(0x8006C610)]]
fBase_c::PACK_RESULT_e dBase_c::preDraw();

/**
 * VT+0x34
 * post method for the draw operation.
 */
[[address(0x8006C650)]]
void dBase_c::postDraw(MAIN_STATE_e state);

/**
 * VT+0x4C
 * Gets a string describing the kind of this base.
 */
[[address(0x8006C660)]]
const char* dBase_c::getKindString() const;
