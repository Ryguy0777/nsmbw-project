// Module.cpp

#include "Four.h"
#include "PatchRel.h"
#include "d_player/d_s_boot.h"
#include <revolution/arc.h>
#include <revolution/dvd.h>
#include <revolution/os.h>

extern "C" {

int main();
int preinit(s32, void*);

void _prolog(s32, void*);
void _epilog();
void _unresolved();

} // extern "C"

constexpr u32 THIS_MODULE_ID = 0x50414C41; // 'PALA'

typedef void (*PFN_voidfunc)();

extern PFN_voidfunc _ctors[];
extern PFN_voidfunc _ctors_end[];

extern _MRel_replace_array_entry _MRel_replace_array[];
extern _MRel_replace_array_entry _MRel_replace_array_end[];

extern _MRel_replace_array_entry _MRel_extern_array[];
extern _MRel_replace_array_entry _MRel_extern_array_end[];

extern _MRel_patch_references_array_entry<0> _MRel_patch_references_array[];
extern _MRel_patch_references_array_entry<0> _MRel_patch_references_array_end[];

#define HID0 1008

void FlushAndInvalidateCache(bool interrupts = OSDisableInterrupts()) ASM_METHOD(
  // clang-format off
    // Flush the entire cache by filling up all 8 ways of 128 sets
    lis     r5, 0x8000;
    ori     r5, r5, 128 * 8 * 32 - 31;
    dcbst   r0, r5;
    lbz     r0, 0(r5);
    subic.  r5, r5, 32;
    blt+    cr0, -0xC;

    // Address broadcast to the 60x bus.
    sc;

    // Flash invalidate instruction cache
    mfspr   r4, HID0;
    ori     r0, r4, 1 << 31 >> 20; // Set HID0.ICFI
    rlwinm  r0, r0, 0, ~(1 << 31 >> 16); // Clear HID0.ICE
    mtspr   HID0, r0; // Write back
    isync;
    mtspr   HID0, r4; // Restore HID0

    // Restore interrupts
    mfmsr   r4;
    rlwimi  r4, r3, 15, 0x8000;
    mtmsr   r4;
    blr;
  // clang-format on
);

extern "C" void _prolog(s32 param1, void* param2)
{
    dSys_c::initCodeRegion();
    auto codeRegion = dSys_c::m_codeRegion;

    int interrupt = OSDisableInterrupts();

    // Reference patches
    for (auto repl = _MRel_patch_references_array; repl != _MRel_patch_references_array_end;) {
        for (u32 i = 0; i < repl->count; i++) {
            u32 offset = reinterpret_cast<u32>(repl->addr) + repl->references[i].addend;
            volatile u16* ptr = reinterpret_cast<volatile u16*>((&repl->references[i].addrP1)[static_cast<int>(codeRegion)]);

            if (repl->references[i].type == R_PPC_ADDR16_LO) {
                offset &= 0xFFFF;
            } else if (repl->references[i].type == R_PPC_ADDR16_HI) {
                offset >>= 16;
            } else if (repl->references[i].type == R_PPC_ADDR16_HA) {
                offset = (offset + 0x8000) >> 16;
            } else {
                OSPanic(__FILE_NAME__, __LINE__, "Unsupported relocation type %d");
            }

            *ptr = static_cast<u16>(offset);
        }

        // Increment repl to the next entry
        repl = reinterpret_cast<_MRel_patch_references_array_entry<0>*>(
          reinterpret_cast<u32>(repl) + sizeof(_MRel_patch_references_array_entry<0>) +
          repl->count * sizeof(_MRel_PatchRel)
        );
    }

    Four::Apply();

    // External replaced array
    for (_MRel_replace_array_entry* __restrict repl = _MRel_extern_array;
         repl != _MRel_extern_array_end; ++repl) {
        *repl->dest = *repl->addr;
    }

    // Function patches
    for (_MRel_replace_array_entry* __restrict repl = _MRel_replace_array;
         repl != _MRel_replace_array_end; ++repl) {
        *repl->addr = 0x48000000 | ((u32(repl->dest) - u32(repl->addr)) & 0x3FFFFFC);
    }

    FlushAndInvalidateCache(false);

    if (preinit(param1, param2) != 0) {
        OSPanic(__FILE_NAME__, __LINE__, "preinit() returned non-zero");
    }

    // Run global constructors
    for (PFN_voidfunc* ctor = _ctors; ctor != _ctors_end && *ctor; ++ctor) {
        (*ctor)();
    }

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmain"
    if (main() != 0) {
        OSPanic(__FILE_NAME__, __LINE__, "main() returned non-zero");
    }
#pragma clang diagnostic pop

    OSRestoreInterrupts(interrupt);
}

extern "C" void _epilog()
{
}

extern "C" void _unresolved()
{
    // Infinite loop
    _unresolved();
}

struct DestructorChain {
    void* next;
    void* destructor;
    void* object;
};

DestructorChain* __global_destructor_chain = nullptr;

extern "C" void* __register_global_object(void* object, void* dtor, DestructorChain* entry)
{
    entry->next = __global_destructor_chain;
    entry->destructor = dtor;
    entry->object = object;
    __global_destructor_chain = entry;

    return object;
};

extern "C" void __cxa_pure_virtual()
{
    OS_PANIC("Call of pure virtual function!\n");
}
