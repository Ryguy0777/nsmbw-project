// OSCache.c
// NSMBW: 0x801AC560 - 0x801ACC10

#include "OSCache.h"

extern "C" {

// UNUSED: DCFlashInvalidate

[[address(0x801AC560)]]
void DCEnable();

// UNUSED: DCDisable

// UNUSED: DCFreeze

// UNUSED: DCUnfreeze

// UNUSED: DCTouchLoad

// UNUSED: DCBlockZero

// UNUSED: DCBlockStore

// UNUSED: DCBlockFlush

// UNUSED: DCBlockInvalidate

[[address(0x801AC580)]]
void DCInvalidateRange(void* addr, u32 amount);

[[address(0x801AC5B0)]]
void DCFlushRange(void* addr, u32 amount);

[[address(0x801AC5E0)]]
void DCStoreRange(void* addr, u32 amount);

[[address(0x801AC610)]]
void DCFlushRangeNoSync(void* addr, u32 amount);

[[address(0x801AC640)]]
void DCStoreRangeNoSync(void* addr, u32 amount);

[[address(0x801AC670)]]
void DCZeroRange(void* addr, u32 amount);

// UNUSED: DCTouchRange

[[address(0x801AC6A0)]]
void ICInvalidateRange(void* addr, u32 amount);

[[address(0x801AC6E0)]]
void ICFlashInvalidate();

[[address(0x801AC6F0)]]
void ICEnable();

// UNUSED: ICDisable

// UNUSED: ICFreeze

// UNUSED: ICUnfreeze

// UNUSED: ICBlockInvalidate

// UNUSED: ICSync

EXTERN_TEXT_STATIC(
  0x801AC710, //
  void __LCEnable()
);

[[address(0x801AC7E0)]]
void LCEnable();

[[address(0x801AC820)]]
void LCDisable();

// UNUSED: LCIsEnable

// UNUSED: LCAllocOneTag

// UNUSED: LCAllocTags

[[address(0x801AC850)]]
void LCLoadBlocks(void* param_1, void* param_2, u32 param_3);

[[address(0x801AC880)]]
void LCStoreBlocks(void* param_1, void* param_2, u32 param_3);

// UNUSED: LCAlloc

// UNUSED: LCAllocNoInvalidate

// UNUSED: LCLoadData

[[address(0x801AC8B0)]]
u32 LCStoreData(void* param_1, void* param_2, u32 param_3);

[[address(0x801AC950)]]
u32 LCQueueLength();

[[address(0x801AC960)]]
u32 LCQueueWait(u32 param_1);

// UNUSED: LCFlushQueue

// UNUSED: L2Enable

// UNUSED: L2Disable

// UNUSED: L2GlobalInvalidate

// UNUSED: L2SetDataOnly

// UNUSED: L2SetWriteThrough

EXTERN_TEXT_STATIC(
  0x801AC980, //
  void DMAErrorHandler()
);

[[address(0x801ACAD0)]]
void __OSCacheInit();

} // extern "C"