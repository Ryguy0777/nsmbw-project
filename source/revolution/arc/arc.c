// arc.c
// NSMBW: 0x8019F7A0 - 0x801A0190

#include <revolution/arc.h>

[[address(0x8019F7A0)]]
bool ARCInitHandle(void* arcStart, ARCHandle* handle);

[[address(0x8019F840)]]
bool ARCOpen(ARCHandle* handle, const char* fileName, ARCFileInfo* af);

[[address(0x8019FAF0)]]
bool ARCFastOpen(ARCHandle* handle, s32 entrynum, ARCFileInfo* af);

[[address(0x8019FB40)]]
s32 ARCConvertPathToEntrynum(ARCHandle* handle, const char* pathPtr);

[[address(0x8019FDC0)]]
u32 entryToPath(ARCHandle* handle, s32 entrynum, char* path, u32 maxlen);

bool ARCConvertEntrynumToPath(ARCHandle* handle, s32 entrynum, char* path, u32 maxlen)
{
    if (entrynum < 0 || entrynum >= handle->entryNum) {
        return false;
    }

    return entryToPath(handle, entrynum, path, maxlen) != 0;
}

bool ARCEntrynumIsDir(ARCHandle* handle, s32 entrynum)
{
    if (entrynum < 0 || entrynum >= handle->entryNum) {
        return false;
    }

    FstEntry* entry = ((FstEntry*) handle->FSTStart) + entrynum;

    return entry->isDir;
}

[[address(0x8019FF90)]]
void* ARCGetStartAddrInMem(ARCFileInfo* af);

[[address(0x8019FFB0)]]
u32 ARCGetStartOffset(ARCFileInfo* af);

[[address(0x8019FFC0)]]
u32 ARCGetLength(ARCFileInfo* af);

[[address(0x8019FFD0)]]
bool ARCClose(ARCFileInfo* af);

[[address(0x8019FFE0)]]
bool ARCChangeDir(ARCHandle* handle, const char* dirName);

// UNUSED: ARCGetCurrentDir

bool ARCFastOpenDir(ARCHandle* handle, s32 entrynum, ARCDir* dir)
{
    if (entrynum < 0 || entrynum >= handle->entryNum) {
        return false;
    }

    FstEntry* entry = ((FstEntry*) handle->FSTStart) + entrynum;

    if (!entry->isDir) {
        return false;
    }

    dir->handle = handle;
    dir->entryNum = entrynum;
    dir->location = entrynum + 1;
    dir->next = entry->dir.next;

    return true;
}

[[address(0x801A0040)]]
bool ARCOpenDir(ARCHandle* handle, const char* dirName, ARCDir* dir);

[[address(0x801A00C0)]]
bool ARCReadDir(ARCDir* dir, ARCDirEntry* dirent);

[[address(0x801A0180)]]
bool ARCCloseDir(ARCDir* dir);