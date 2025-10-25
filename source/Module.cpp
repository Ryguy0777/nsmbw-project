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

extern "C" void _prolog(s32 param1, void* param2)
{
    dSys_c::initCodeRegion();
    auto codeRegion = dSys_c::m_codeRegion;

    int interrupt = OSDisableInterrupts();

    // Reference patches
    for (auto repl = _MRel_patch_references_array; repl != _MRel_patch_references_array_end;) {
        for (u32 i = 0; i < repl->count; i++) {
            u32 offset = reinterpret_cast<u32>(repl->addr) + repl->references[i].addend;
            u32 ptr = (&repl->references[i].addrP1)[static_cast<int>(codeRegion)];

            if (repl->references[i].type == R_PPC_ADDR16_LO) {
                offset &= 0xFFFF;
            } else if (repl->references[i].type == R_PPC_ADDR16_HI) {
                offset >>= 16;
            } else if (repl->references[i].type == R_PPC_ADDR16_HA) {
                offset = (offset + 0x8000) >> 16;
            } else {
                OSPanic(__FILE_NAME__, __LINE__, "Unsupported relocation type %d");
            }

            if (ptr & 2) {
                *(volatile u32*) ToUncached(ptr - 2) =
                  ((*(volatile u32*) ToUncached(ptr - 2)) & 0xFFFF0000) | offset;
            } else {
                *(volatile u32*) ToUncached(ptr) =
                  ((*(volatile u32*) ToUncached(ptr)) & 0xFFFF) | (offset << 16);
            }

            ICInvalidateRange((u32*) ptr, 4);
        }

        // Increment repl to the next entry
        repl = reinterpret_cast<_MRel_patch_references_array_entry<0>*>(
          reinterpret_cast<u32>(repl) + sizeof(_MRel_patch_references_array_entry<0>) +
          repl->count * sizeof(_MRel_PatchRel)
        );
    }

    Four::Apply();

    // External replaced array
    for (auto repl = _MRel_extern_array; repl != _MRel_extern_array_end; ++repl) {
        *ToUncached(repl->dest) = *ToUncached(repl->addr);
        ICInvalidateRange(repl->dest, 4);
    }

    // Function patches
    for (auto repl = _MRel_replace_array; repl != _MRel_replace_array_end; ++repl) {
        *ToUncached(repl->addr) = 0x48000000 | ((u32(repl->dest) - u32(repl->addr)) & 0x3FFFFFC);
        ICInvalidateRange(repl->addr, 4);
    }

    if (preinit(param1, param2) != 0) {
        OSPanic(__FILE_NAME__, __LINE__, "preinit() returned non-zero");
    }

    // Run global constructors
    for (PFN_voidfunc* ctor = _ctors; ctor != _ctors_end && *ctor; ++ctor) {
        (*ctor)();
    }

    OSRestoreInterrupts(interrupt);

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmain"
    if (main() != 0) {
        OSPanic(__FILE_NAME__, __LINE__, "main() returned non-zero");
    }
#pragma clang diagnostic pop
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
