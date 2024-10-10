#pragma once

extern "C" {

struct ARCHeader {
    u32 magic;
    u32 fstOffset;
    u32 fstSize;
    u32 fileStart;
    u8 reserved[0x10];
};

static_assert(sizeof(ARCHeader) == 0x20);

struct ARCHandle {
    /* 0x00 */ void* archiveStartAddr;
    /* 0x04 */ void* FSTStart;
    /* 0x08 */ void* fileStart;
    /* 0x0C */ u32 entryNum;
    /* 0x10 */ char* FSTStringStart;
    /* 0x14 */ u32 FSTLength;
    /* 0x18 */ u32 currDir;
};

static_assert(sizeof(ARCHandle) == 0x1C);

struct ARCFileInfo {
    ARCHandle* handle;
    u32 startOffset;
    u32 length;
};

static_assert(sizeof(ARCFileInfo) == 0xC);

struct ARCDir {
    ARCHandle* handle;
    u32 entryNum;
    u32 location;
    u32 next;
};

static_assert(sizeof(ARCDir) == 0x10);

struct ARCDirEntry {
    FILL(0x00, 0x04);
    u32 entryNum;
    bool isDir;
    char* name;
};

static_assert(sizeof(ARCDirEntry) == 0x10);

struct FstEntry {
    u8 isDir : 8;
    u32 stringOffset : 24;

    union {
        struct {
            u32 parent;
            u32 next;
        } dir;

        struct {
            u32 startAddr;
            u32 length;
        } file;
    };
};

bool ARCInitHandle(void* arcStart, ARCHandle* handle);

bool ARCOpen(ARCHandle* handle, const char* fileName, ARCFileInfo* af);

bool ARCFastOpen(ARCHandle* handle, s32 entrynum, ARCFileInfo* af);

s32 ARCConvertPathToEntrynum(ARCHandle* handle, const char* pathPtr);

bool ARCConvertEntrynumToPath(ARCHandle* handle, s32 entrynum, char* path, u32 maxlen);

bool ARCEntrynumIsDir(ARCHandle* handle, s32 entrynum);

void* ARCGetStartAddrInMem(ARCFileInfo* af);

u32 ARCGetStartOffset(ARCFileInfo* af);

u32 ARCGetLength(ARCFileInfo* af);

bool ARCClose(ARCFileInfo* af);

bool ARCChangeDir(ARCHandle* handle, const char* dirName);

bool ARCFastOpenDir(ARCHandle* handle, s32 entrynum, ARCDir* dir);

bool ARCOpenDir(ARCHandle* handle, const char* dirName, ARCDir* dir);

bool ARCReadDir(ARCDir* dir, ARCDirEntry* dirent);

bool ARCCloseDir(ARCDir* dir);

} // extern "C"
