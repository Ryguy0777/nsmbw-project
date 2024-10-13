#include "System.h"

#include <dynamic/scene/d_s_boot.h>
#include <revolution/arc.h>
#include <revolution/dvd.h>
#include <revolution/os.h>
#include <string.h>

constexpr u32 THIS_MODULE_ID = 0x50414C41; // 'PALA'

typedef void (*PFN_voidfunc)();

extern PFN_voidfunc _ctors[];
extern PFN_voidfunc _ctors_end[];

extern __replace_struct _replarray[];
extern __replace_struct _replarray_end[];

extern _MRel_ReplaceRel _replrelarray[];
extern _MRel_ReplaceRel _replrelarray_end[];

extern _MRel_InsertData _replinsertarray[];
extern _MRel_InsertData _replinsertarray_end[];

extern __replace_struct _externarray[];
extern __replace_struct _externarray_end[];

u32 SearchPatch(u32 offset)
{
    return 0;
}

void PatchRelocations(OSModuleImportInfo* importTable, OSModuleImportInfo* importEnd, u32* sections)
{
    for (OSModuleImportInfo* import = importTable; import < importEnd; import++) {
        if (import->moduleId == THIS_MODULE_ID) {
            continue;
        }

        OSModuleSectionInfo* importSections = nullptr;
        if (import->moduleId != 0) {
            // We're importing from another REL module
            OSModuleHeader* relList = *reinterpret_cast<OSModuleHeader**>(0x800030C8);
            for (OSModuleHeader* rel = relList; rel != nullptr;
                 // Upcast
                 rel = reinterpret_cast<OSModuleHeader*>(rel->info.head.next)) {
                if (rel->info.id == import->moduleId) {
                    importSections =
                      reinterpret_cast<OSModuleSectionInfo*>(rel->info.sectionInfoOffset);
                    break;
                }
            }
        }

        u32 ptr = 0;

        OS_REPORT("Starting rel patches from %08X\n", import->offset);

        for (OSModuleRelInfo* rel = reinterpret_cast<OSModuleRelInfo*>(import->offset);
             rel->type != R_RVL_STOP; rel++) {
            if (rel->type == R_RVL_SECT) {
                ptr = sections[rel->section];

                OS_REPORT("Section start: %08X\n", ptr);
                continue;
            }

            ASSERT(ptr != 0);
            ptr += rel->offset;

            ASSERT(rel->section == 0 || importSections != nullptr);

            u32 offset = rel->section == 0 ? 0 : importSections[rel->section].offset & ~0b11;
            offset += rel->addend;
            u32 oldOffset = offset;

            ASSERT(offset != 0);

            switch (rel->type) {
            default:
                break;

            case R_PPC_ADDR32:
                if ((offset = SearchPatch(offset)) != 0) {
                    OS_REPORT(
                      "Patched R_PPC_ADDR32 at %08X (%08X -> %08X)\n", ptr, oldOffset, offset
                    );
                    *(u32*) ToUncached(ptr) = offset;
                }
                break;

            case R_PPC_ADDR16_LO:
            case R_PPC_ADDR16_HA:
            case R_PPC_ADDR16_HI:
                if ((offset = SearchPatch(offset)) == 0) {
                    break;
                }

                if (rel->type == R_PPC_ADDR16_LO) {
                    offset &= 0xFFFF;
                    oldOffset &= 0xFFFF;
                    OS_REPORT(
                      "Patched R_PPC_ADDR16_LO at %08X (%04X -> %04X)\n", ptr, oldOffset, offset
                    );
                } else if (rel->type == R_PPC_ADDR16_HI) {
                    offset >>= 16;
                    oldOffset >>= 16;
                    OS_REPORT(
                      "Patched R_PPC_ADDR16_HI at %08X (%04X -> %04X)\n", ptr, oldOffset, offset
                    );
                } else if (rel->type == R_PPC_ADDR16_HA) {
                    offset = (offset + 0x8000) >> 16;
                    oldOffset = (oldOffset + 0x8000) >> 16;
                    OS_REPORT(
                      "Patched R_PPC_ADDR16_HA at %08X (%04X -> %04X)\n", ptr, oldOffset, offset
                    );
                }

                if (ptr & 2) {
                    *(u32*) ToUncached(ptr - 2) =
                      ((*(u32*) ToUncached(ptr - 2)) & 0xFFFF0000) | offset;
                } else {
                    *(u32*) ToUncached(ptr) = ((*(u32*) ToUncached(ptr)) & 0xFFFF) | (offset << 16);
                }
                break;
            }
        }
    }
}

extern "C" void _prolog(s32 arcEntryNum, ARCHandle* arcHandle)
{
    // Do the external replaced array
    for (auto repl = _externarray; repl != _externarray_end; ++repl) {
        *ToUncached(repl->dest) = *repl->addr;
        ICInvalidateRange(repl->dest, 4);
    }

    // Do function patches
    for (auto repl = _replarray; repl != _replarray_end; ++repl) {
        *ToUncached(repl->addr) = 0x48000000 | ((u32(repl->dest) - u32(repl->addr)) & 0x3FFFFFC);
        ICInvalidateRange(repl->addr, 4);
    }

    // Do data patches
    for (auto repl = _replinsertarray; repl != _replinsertarray_end; ++repl) {
        memcpy(repl->addr, repl->dest, repl->size);
        DCFlushRange(repl->addr, repl->size);
    }

    // Do relocation patches for data symbol overrides
    // Currently disabled while I figure out how to reload the relocation table
    if (false) {
        for (OSModuleHeader* rel = *reinterpret_cast<OSModuleHeader**>(0x800030C8); rel != nullptr;
             // Upcast
             rel = reinterpret_cast<OSModuleHeader*>(rel->info.head.next)) {
            // Skip PALA a.k.a. this module
            if (rel->info.id == THIS_MODULE_ID) {
                continue;
            }

            // Offsets are set to pointers by OSLink
            auto importTable = reinterpret_cast<OSModuleImportInfo*>(rel->impOffset);
            auto importEnd = reinterpret_cast<OSModuleImportInfo*>(rel->impOffset + rel->impSize);
            auto sections = reinterpret_cast<OSModuleSectionInfo*>(rel->info.sectionInfoOffset);

            u32 sectionCount = rel->info.numSections;
            ASSERT(sectionCount <= 18);

            u32 sectionsArray[18] = {0};
            for (u32 i = 0; i < sectionCount; i++) {
                sectionsArray[i] = sections[i].offset & ~0b11;
            }

            PatchRelocations(importTable, importEnd, sectionsArray);
        }
    }

    __DVDEXInit(arcEntryNum, arcHandle);

    dScBoot_c::initCodeRegion();

    // Run global constructors
    for (PFN_voidfunc* ctor = _ctors; ctor != _ctors_end && *ctor; ++ctor) {
        (*ctor)();
    }
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