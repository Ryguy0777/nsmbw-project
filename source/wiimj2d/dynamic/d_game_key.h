#pragma once

#include <egg/core/eggHeap.h>

class dGameKeyCore_c;

class dGameKey_c
{
    /* 0x00 VTABLE 0x80315900 */

public:
    // ------------
    // Constructors
    // ------------

    /* 0x800B5980 */
    dGameKey_c();

    /* VT+0x8 0x800B5A00 */
    virtual ~dGameKey_c();

public:
    // -----------
    // Static Data
    // -----------

    /* 0x8042A230 */ static dGameKey_c* m_instance;

public:
    // ----------------
    // Static Functions
    // ----------------

    /* 0x800B5930 */
    static dGameKey_c* createInstance(EGG::Heap* heap);

public:
    // -----------
    // Member Data
    // -----------

    /* 0x04 */ dGameKeyCore_c* mpCores[8];
};