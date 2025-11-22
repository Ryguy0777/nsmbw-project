#pragma once

EXTERN_C_START

/* 0x801AC560 */
void DCEnable();

/* 0x801AC580 */
void DCInvalidateRange(void* addr, u32 amount);

/* 0x801AC5B0 */
void DCFlushRange(void* addr, u32 amount);

/* 0x801AC5E0 */
void DCStoreRange(void* addr, u32 amount);

/* 0x801AC610 */
void DCFlushRangeNoSync(void* addr, u32 amount);

/* 0x801AC640 */
void DCStoreRangeNoSync(void* addr, u32 amount);

/* 0x801AC670 */
void DCZeroRange(void* addr, u32 amount);

/* 0x801AC6A0 */
void ICInvalidateRange(void* addr, u32 amount);

/* 0x801AC6E0 */
void ICFlashInvalidate();

/* 0x801AC6F0 */
void ICEnable();

/* 0x801AC710 */
void __LCEnable();

/* 0x801AC7E0 */
void LCEnable();

/* 0x801AC820 */
void LCDisable();

/* 0x801AC850 */
void LCLoadBlocks(void* param_1, void* param_2, u32 param_3);

/* 0x801AC880 */
void LCStoreBlocks(void* param_1, void* param_2, u32 param_3);

/* 0x801AC8B0 */
u32 LCStoreData(void* param_1, void* param_2, u32 param_3);

/* 0x801AC950 */
u32 LCQueueLength();

/* 0x801AC960 */
u32 LCQueueWait(u32 param_1);

EXTERN_C_END
