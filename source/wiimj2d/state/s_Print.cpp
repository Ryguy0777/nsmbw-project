// s_Print.cpp
// NSMBW .text: 0x8015F810 - 0x8015F900

#include "d_player/d_s_boot.h"
#include <Region.h>
#include <cstdarg>
#include <cstdio>
#include <revolution/base/PPCArch.h>
#include <revolution/os/OSError.h>
#include <revolution/os/OSInterrupt.h>
#include <revolution/os/OSFatal.h>

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

static const char* getRegionInfo()
{
    const char* regionStr;
    switch (dSys_c::m_codeRegion) {
    default:
        return "Unknown";

    case Region::P1:
        return "PAL Rev 1";
    case Region::P2:
        return "PAL Rev 2";

    case Region::E1:
        return "USA Rev 1";
    case Region::E2:
        return "USA Rev 2";

    case Region::J1:
        return "JPN Rev 1";
    case Region::J2:
        return "JPN Rev 2";

    case Region::K:
        return "KOR";

    case Region::W:
        return "TWN";

    case Region::C:
        return "CHN";
    }
}

// Override of the weak symbol from OSError.c
[[address(0x801AD620)]] [[noreturn]]
void OSPanic(const char* file, int line, const char* format, ...)
{
    OSDisableInterrupts();

    char report[1024];

    va_list args;
    va_start(args, format);
    int n = std::vsnprintf(report, sizeof(report), format, args);
    va_end(args);

    if (report[n - 1] == '\n') {
        report[--n] = '\0';
    }

    n += std::snprintf(
      report + n, sizeof(report) - n,
      "\nin file \"%s\" on line %d.\n"
      "Region Info: %s.\n"
      "Address:    Back Chain  LR Save\n",
      file, line, getRegionInfo()
    );

    // Print the first LR which may not be on the stack
    if (void** stack = checkStackAddr(__builtin_frame_address(1));
        stack == nullptr || stack[1] != __builtin_return_address(0)) {
        n += std::snprintf(
          report + n, sizeof(report) - n, "----------: ----------  0x%08x\n",
          reinterpret_cast<unsigned>(__builtin_return_address(0))
        );
    }

    bool first = true;
    for (void** stack = checkStackAddr(__builtin_frame_address(0)); stack != nullptr;
         stack = checkStackAddr(stack[0])) {
        if (first) {
            n += std::snprintf(
              report + n, sizeof(report) - n, "0x%08x: 0x%08x  ----------\n",
              reinterpret_cast<unsigned>(stack), reinterpret_cast<unsigned>(stack[0])
            );
            first = false;
        } else {
            n += std::snprintf(
              report + n, sizeof(report) - n, "0x%08x: 0x%08x  0x%08x\n",
              reinterpret_cast<unsigned>(stack), reinterpret_cast<unsigned>(stack[0]),
              reinterpret_cast<unsigned>(stack[1])
            );
        }
    }

    report[sizeof(report) - 1] = '\0';
    OSReport("%s", report);
    OSFatal(GXColor{255, 255, 255, 255}, GXColor{0, 0, 0, 255}, report);

    PPCHalt();
}
