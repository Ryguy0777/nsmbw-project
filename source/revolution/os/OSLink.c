// OSLink.c
// NSMBW: 0x801B1A50 - 0x801B24D0

#include "OSLink.h"

extern "C" {

EXTERN_SYMBOL(0x801B1A50, "OSNotifyLink");

EXTERN_SYMBOL(0x801B1A60, "OSNotifyUnlink");

EXTERN_SYMBOL(0x801B1A70, "OSNotifyPreLink");

EXTERN_SYMBOL(0x801B1A80, "OSNotifyPostLink");

EXTERN_SYMBOL(0x801B1A90, "OSSetStringTable");

EXTERN_SYMBOL(0x801B1AA0, "Relocate");

EXTERN_SYMBOL(0x801B1D70, "Link");

[[address(0x801B2060)]]
bool OSLink(OSModuleInfo* info, void* bss);

[[address(0x801B2070)]]
bool OSLinkFixed(OSModuleInfo* info, void* bss);

// 0x801B2090: Undo

// 0x801B22D0: OSUnlink

// 0x801B24B0: __OSModuleInit

// UNUSED: OSSearchModule

} // extern "C"