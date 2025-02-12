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

class mDvd_command_c
{
public:
    // ------------
    // Constructors
    // ------------

    /* VT+0x8 0x */
    virtual ~mDvd_command_c();

public:
    // ----------------
    // Member Functions
    // ----------------

    /* 0x8016B630 */
    void waitDone() const;

public:
    // -----------
    // Member Data
    // -----------
};

class mDvd_toMainRam_c : public mDvd_command_c
{
public:
    // ----------------
    // Static Functions
    // ----------------

    /* 0x8016C0B0 */
    static mDvd_toMainRam_c* create(const char* path, u8 param2, EGG::Heap* heap);

    /* 0x8016C0B0 - repl */
    static mDvd_toMainRam_c* createNoWait(const char* path, u8 param2, EGG::Heap* heap);
};