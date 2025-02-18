// s_Print.cpp
// NSMBW .text: 0x8015F810 - 0x8015F900

#include <Port.h>
#include <cstdarg>
#include <cstdio>
#include <dynamic/d_player/d_s_boot.h>
#include <revolution/base/PPCArch.h>
#include <revolution/os/OSError.h>
#include <revolution/os/OSInterrupt.h>

// Unknown 0x8015F810

// Unknown 0x8015F820

// Override of the weak symbol from OSError.c
[[address(0x8015F870)]]
void OSReport(const char* format, ...);

// Override of the weak symbol from OSError.c
[[address(0x8015F880)]]
void OSVReport(const char* format, va_list args);

static void** checkStackAddr(void* stackPtr)
{
    u32 stackAddr = reinterpret_cast<u32>(stackPtr);

    if ((stackAddr >= 0x80003F00 && stackAddr <= 0x817FFFF8) ||
        (stackAddr >= 0x90000020 && stackAddr <= 0x935FFFF8)) {
        return reinterpret_cast<void**>(stackPtr);
    }

    return nullptr;
}

static void printRegionInfo()
{
    const char* regionStr;
    switch (dScBoot_c::m_codeRegion) {
    default:
        regionStr = "Unknown";
        break;

    case Port::Region::P1:
        regionStr = "PAL Rev 1";
        break;
    case Port::Region::P2:
        regionStr = "PAL Rev 2";
        break;

    case Port::Region::E1:
        regionStr = "USA Rev 1";
        break;
    case Port::Region::E2:
        regionStr = "USA Rev 2";
        break;

    case Port::Region::J1:
        regionStr = "JPN Rev 1";
        break;
    case Port::Region::J2:
        regionStr = "JPN Rev 2";
        break;

    case Port::Region::K:
        regionStr = "KOR";
        break;

    case Port::Region::W:
        regionStr = "TWN";
        break;

    case Port::Region::C:
        regionStr = "CHN";
        break;
    }

    OSReport("Code Region: %s\n", regionStr);
}

// Override of the weak symbol from OSError.c
[[address(0x801AD620)]] [[noreturn]]
void OSPanic(const char* file, int line, const char* format, ...)
{
    OSDisableInterrupts();

    va_list args;
    va_start(args, format);
    std::vprintf(format, args);
    va_end(args);

    OSReport(" in \"%s\" on line %d.\n", file, line);
    printRegionInfo();
    OSReport("\nAddress:      Back Chain    LR Save\n");

    // Print the first LR which may not be on the stack
    if (void** stack = checkStackAddr(__builtin_frame_address(1));
        stack == nullptr || stack[1] != __builtin_return_address(0)) {
        OSReport("----------:   ----------    0x%08x\n", __builtin_return_address(0));
    }

    bool first = true;
    for (void** stack = checkStackAddr(__builtin_frame_address(0)); stack != nullptr;
         stack = checkStackAddr(stack[0])) {
        if (first) {
            OSReport("0x%08x:   0x%08x    ----------\n", stack, stack[0]);
            first = false;
        } else {
            OSReport("0x%08x:   0x%08x    0x%08x\n", stack, stack[0], stack[1]);
        }
    }

    PPCHalt();
}