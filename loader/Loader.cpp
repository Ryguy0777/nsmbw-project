#include <System.h>

#undef address
#define address(...) maybe_unused

#undef address_data
#define address_data(...) maybe_unused

#undef EXTERN_SYMBOL
#define EXTERN_SYMBOL(...)

#undef EXTERN_REPL
#define EXTERN_REPL(...)

#include <AddressMapper.h>
#include <cstdio>
#include <cstring>
#include <egg/core/eggDvdFile.h>
#include <egg/core/eggDvdRipper.h>
#include <egg/core/eggHeap.h>
#include <egg/core/eggStreamDecomp.h>
#include <revolution/arc.h>
#include <revolution/dvd.h>
#include <revolution/os.h>

#include <runtime/__mem.c>

// Function definitions. Define as extern "C" to avoid symbol name mangling for references from ASM.
extern "C" {
void PortCall();
bool LoaderMain();
static void LoaderAssertFail(const char* expr, s32 line);
}

#define LOADER_ASSERT(_EXPR) (((_EXPR) ? (void) 0 : LoaderAssertFail(#_EXPR, __LINE__)))

// Since the same Loader.bin file will be used for every region, ported addresses need to be
// realized on the fly.

// Regions in the order P1, P2, E1, E2, J1, J2, K, W, C

#define PORT_CALL_BASE 0x800047E4

#define _ADDRESS_LOADER3(_ADDR, _COUNTER, _PORT_CALL_BASE)                                         \
    __gnu__::__naked__]]  void _LoaderFunction##_COUNTER() asm("_LoaderFunction" #_COUNTER);       \
    [[__gnu__::__naked__]] void _LoaderFunction##_COUNTER()                                        \
    {                                                                                              \
        __asm__("li 12, ((. + 8) - " #_PORT_CALL_BASE ")@l;"                                       \
                "b PortCall;"                                                                      \
                ".long %0;"                                                                        \
                ".long %1;"                                                                        \
                ".long %2;"                                                                        \
                ".long %3;"                                                                        \
                ".long %4;"                                                                        \
                ".long %5;"                                                                        \
                ".long %6;"                                                                        \
                ".long %7;"                                                                        \
                ".long %8;"                                                                        \
                :                                                                                  \
                : "i"(_ADDR), "i"(AddressMapperP2.MapAddress(_ADDR)),                              \
                  "i"(AddressMapperE1.MapAddress(_ADDR)), "i"(AddressMapperE2.MapAddress(_ADDR)),  \
                  "i"(AddressMapperJ1.MapAddress(_ADDR)), "i"(AddressMapperJ2.MapAddress(_ADDR)),  \
                  "i"(AddressMapperK.MapAddress(_ADDR)), "i"(AddressMapperW.MapAddress(_ADDR)),    \
                  "i"(AddressMapperC.MapAddress(_ADDR)));                                          \
    }                                                                                              \
        [[__gnu__::__alias__("_LoaderFunction" #_COUNTER)

#define _ADDRESS_LOADER2(_ADDR, _COUNTER, _PORT_CALL_BASE)                                         \
    _ADDRESS_LOADER3(_ADDR, _COUNTER, _PORT_CALL_BASE)
#define _ADDRESS_LOADER(_ADDR, _COUNTER, _PORT_CALL_BASE)                                          \
    _ADDRESS_LOADER2(_ADDR, _COUNTER, _PORT_CALL_BASE)
#define address_loader(_ADDR) _ADDRESS_LOADER(_ADDR, __COUNTER__, PORT_CALL_BASE)

u32 g_portOffset = 0xFF;

void PortCall() ASM_METHOD(
  // clang-format off
    lis     r11, g_portOffset@ha;
    lwz     r11, g_portOffset@l(r11);
    lwzx    r12, r11, r12;
    mtctr   r12;
    bctr;
  // clang-format on
);

[[address_loader(0x8019F7A0)]]
bool ARCInitHandle(void* arcStart, ARCHandle* handle);

[[address_loader(0x8019F840)]]
bool ARCOpen(ARCHandle* handle, const char* fileName, ARCFileInfo* af);

[[address_loader(0x8019FAF0)]]
bool ARCFastOpen(ARCHandle* handle, s32 entrynum, ARCFileInfo* af);

[[address_loader(0x8019FB40)]]
s32 ARCConvertPathToEntrynum(ARCHandle* handle, const char* pathPtr);

[[address_loader(0x8019FF90)]]
void* ARCGetStartAddrInMem(ARCFileInfo* af);

[[address_loader(0x8019FFB0)]]
u32 ARCGetStartOffset(ARCFileInfo* af);

[[address_loader(0x8019FFC0)]]
u32 ARCGetLength(ARCFileInfo* af);

[[address_loader(0x8019FFD0)]]
bool ARCClose(ARCFileInfo* af);

[[address_loader(0x801AF710)]]
void OSFatal(GXColor textColor, GXColor bgColor, const char* text);

[[address_loader(0x801B2060)]]
bool OSLink(OSModuleInfo* info, void* bss);

[[address_loader(0x801B2070)]]
bool OSLinkFixed(OSModuleInfo* info, void* bss);

[[address_loader(0x801CA7C0)]]
s32 DVDConvertPathToEntrynum(const char* fileName);

// Actually a constructor but we can't define it due to a compiler bug.
[[address_loader(0x802B7C40)]]
EGG::DvdFile* MakeDvdFile(void* data);

[[address_loader(0x802B8560)]]
bool EGG::StreamDecompLZ::init(void* dst, u32 maxCompressedSize);

[[address_loader(0x802B8590)]]
bool EGG::StreamDecompLZ::decomp(const void* src, u32 size);

[[address_loader(0x802B8B90)]]
u32 EGG::StreamDecompLZ::getUncompressedSize(const void* src);

[[address_loader(0x802B8BA0)]]
u32 EGG::StreamDecompLZ::getHeaderSize();

[[address_loader(0x802B8290)]]
u8* EGG::DvdRipper::loadToMainRAMDecomp(
  DvdFile* file, StreamDecomp* streamDecomp, u8* dst, Heap* heap, EAllocDirection allocDirection,
  s32 offset, u32 size, u32 maxChunkSize, u32* amountRead, u32* fileSize
);

[[address_loader(0x802E19D8)]]
int snprintf(char* restrict s, size_t n, const char* restrict format, ...);

constexpr u32 MODULE_MAX_SIZE = 0x40000;

constexpr u32 REGION_INDEX = sizeof("rels/project_") - 1;
char g_modulePath[] = "rels/project_?1.rel.LZ";

const char g_contentsArc[] = "NSMBWProjectData.arc";

u32 g_dylinkHeapAddresses[] = {
  0x8042A664, // PAL v1 address

// Ports for other regions
// Disabled for clangd because I'm really annoyed about my Clang Language Server crashing
#ifndef CLANGD
  AddressMapperP2.MapAddress(0x8042A664),
  AddressMapperE1.MapAddress(0x8042A664),
  AddressMapperE2.MapAddress(0x8042A664),
  AddressMapperJ1.MapAddress(0x8042A664),
  AddressMapperJ2.MapAddress(0x8042A664),
  AddressMapperK.MapAddress(0x8042A664),
  AddressMapperW.MapAddress(0x8042A664),
  AddressMapperC.MapAddress(0x8042A664),
#endif
};

static EGG::Heap* GetPortByCode()
{
    u8 c;
    u8 i = 0;

    switch (*reinterpret_cast<u8*>(0x8000423A)) {
    default:
        return nullptr;

    case 0xFF:
        // PAL (P)
        g_modulePath[REGION_INDEX] = 'P';
        g_portOffset = PORT_CALL_BASE + 0x0;
        i = 0;

        c = *reinterpret_cast<u8*>(0x800CF287);
        break;

    case 0xFC:
        // USA (E)
        g_modulePath[REGION_INDEX] = 'E';
        g_portOffset = PORT_CALL_BASE + 0x8;
        i = 2;

        c = *reinterpret_cast<u8*>(0x800CF197);
        break;

    case 0xF9:
        // JPN (J)
        g_modulePath[REGION_INDEX] = 'J';
        g_portOffset = PORT_CALL_BASE + 0x10;
        i = 4;

        c = *reinterpret_cast<u8*>(0x800CF117);
        break;

    case 0xC8:
        // KOR (K)
        g_modulePath[REGION_INDEX] = 'K';
        g_portOffset = PORT_CALL_BASE + 0x18;
        return *reinterpret_cast<EGG::Heap**>(g_dylinkHeapAddresses[5]);

    case 0xAC:
        // TWN (W)
        g_modulePath[REGION_INDEX] = 'W';
        g_portOffset = PORT_CALL_BASE + 0x1C;
        return *reinterpret_cast<EGG::Heap**>(g_dylinkHeapAddresses[6]);

    case 0x55:
        // CHN (C)
        g_modulePath[REGION_INDEX] = 'C';
        g_portOffset = PORT_CALL_BASE + 0x20;
        return *reinterpret_cast<EGG::Heap**>(g_dylinkHeapAddresses[7]);
    }

    if (c == 0x30) {
        g_modulePath[REGION_INDEX + 1] = '1';
    } else if (c == 0x38) {
        g_portOffset += 0x4;
        i += 1;
        g_modulePath[REGION_INDEX + 1] = '2';
    } else {
        return nullptr;
    }

    return *reinterpret_cast<EGG::Heap**>(g_dylinkHeapAddresses[i]);
}

u32 g_StreamDecompLZVTable[] = {
  0x8034FFA8, // PAL v1 address

// Ports for other regions
#ifndef CLANGD
  AddressMapperP2.MapAddress(0x8034FFA8),
  AddressMapperE1.MapAddress(0x8034FFA8),
  AddressMapperE2.MapAddress(0x8034FFA8),
  AddressMapperJ1.MapAddress(0x8034FFA8),
  AddressMapperJ2.MapAddress(0x8034FFA8),
  AddressMapperK.MapAddress(0x8034FFA8),
  AddressMapperW.MapAddress(0x8034FFA8),
  AddressMapperC.MapAddress(0x8034FFA8),
#endif
};

EGG::StreamDecompLZ MakeStreamDecompLZ()
{
    EGG::StreamDecompLZ lzStream;
    int portIndex = g_portOffset - PORT_CALL_BASE;
    *reinterpret_cast<u32*>(&lzStream) = g_StreamDecompLZVTable[portIndex / 4];
    return lzStream;
}

// Loader entry point. Defined in section .start so the linker will always place this first.
__attribute__((section(".start"))) //
bool LoaderMain()
{
    EGG::Heap* heap = GetPortByCode();

    if (heap == nullptr) {
        // No valid region could be found! We have no OSFatal to display an error message, but we
        // can display a solid color to the screen using HW_VISOLID. This doesn't work on Dolphin,
        // but it does work on Wii/vWii. This color is blue.
        *(u32*) 0xCD000024 = ((255 << 24) | (107 << 16) | (29 << 8) | 1);
        while (true) {
        }
    }

    u8* moduleBlock = reinterpret_cast<u8*>(heap->alloc(MODULE_MAX_SIZE, 32));
    LOADER_ASSERT(!!moduleBlock);

    ARCHandle* arcHandle = reinterpret_cast<ARCHandle*>(heap->alloc(sizeof(ARCHandle), 4));
    LOADER_ASSERT(!!arcHandle);

    EGG::DvdFile* dvdFile = MakeDvdFile(heap->alloc(sizeof(EGG::DvdFile), 4));
    LOADER_ASSERT(!!dvdFile);

    s32 arcEntryNum = DVDConvertPathToEntrynum(g_contentsArc);
    LOADER_ASSERT(arcEntryNum != -1);

    // Open NSMBWProjectData.arc
    bool dvdOpenOk = dvdFile->open(arcEntryNum);
    LOADER_ASSERT(dvdOpenOk);

    // Read the 32 byte ARC header to get the size of the full header
    ARCHeader arcSmallHeader alignas(32);
    bool arcHeaderReadOk =
      dvdFile->readData(&arcSmallHeader, sizeof(ARCHeader), 0) == sizeof(ARCHeader);
    LOADER_ASSERT(arcHeaderReadOk);

    s32 arcHeaderSize = (arcSmallHeader.fileStart + 31) & ~31;
    void* arcHeader = heap->alloc(arcHeaderSize, 32);
    LOADER_ASSERT(!!arcHeader);

    // Read the full header
    bool arcFullHeaderReadOk = dvdFile->readData(arcHeader, arcHeaderSize, 0) == arcHeaderSize;
    LOADER_ASSERT(arcFullHeaderReadOk);

    bool arcInitHandleOk = ARCInitHandle(arcHeader, arcHandle);
    LOADER_ASSERT(arcInitHandleOk);

    ARCFileInfo arcFileInfo;
    bool arcOpenOk = ARCOpen(arcHandle, g_modulePath, &arcFileInfo);
    LOADER_ASSERT(arcOpenOk);

    EGG::StreamDecompLZ lzStream = MakeStreamDecompLZ();

    u32 amountRead, fileSize;
    moduleBlock = EGG::DvdRipper::loadToMainRAMDecomp(
      dvdFile, &lzStream, moduleBlock, heap, EGG::DvdRipper::ALLOC_DIR_TOP,
      ARCGetStartOffset(&arcFileInfo), ARCGetLength(&arcFileInfo), 0x1000, &amountRead, &fileSize
    );
    LOADER_ASSERT(!!moduleBlock);

    delete dvdFile;
    dvdFile = nullptr;

    auto header = reinterpret_cast<OSModuleHeader*>(moduleBlock);

    LOADER_ASSERT(header->bssSize <= MODULE_MAX_SIZE - header->fixSize);

    void* bssBlock = moduleBlock + header->fixSize;
    LOADER_ASSERT(!!bssBlock);

    bool osLinkModOk = OSLink(&header->info, bssBlock);
    LOADER_ASSERT(osLinkModOk);

    memset(bssBlock, 0, header->bssSize);

    (*(void (*)(...)) header->prolog)(arcEntryNum, arcHandle);

    return true;
}

[[gnu::noinline]]
static void LoaderAssertFail(const char* expr, s32 line)
{
    char printMsg[0x400];
    std::snprintf(
      printMsg, 0x400,
      "Loader assertion failed\n"
      "  %s\n"
      "  line %ld\n",
      expr, line
    );

    OSFatal(GXColor{255, 255, 255, 255}, GXColor{0, 0, 0, 255}, printMsg);
    while (1) {
    }
}
