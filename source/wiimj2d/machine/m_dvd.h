#pragma once

#include <egg/core/eggDvdRipper.h>
#include <egg/core/eggHeap.h>

namespace mDvd
{

/* 0x8016B3E0 */
void* loadToMainRAM(
  int entryNum, char* dst, EGG::Heap* heap, EGG::DvdRipper::EAllocDirection allocDir, s32 offset,
  u32* outAmountRead, u32* outFileSize, u32 decompressorType
);

void* loadToMainRAM(
  const char* path, char* dst, EGG::Heap* heap, EGG::DvdRipper::EAllocDirection allocDir,
  s32 offset, u32* outAmountRead, u32* outFileSize, u32 decompressorType
);

} // namespace mDvd