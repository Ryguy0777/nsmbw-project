// d_nand_thread.cpp
// NSMBW .text: 0x800CED00 - 0x800CFCB0

#include "d_nand_thread.h"

#include "d_system/d_mj2d_data.h"
#include "d_system/d_mj2d_game.h"
#include "d_system/d_mj2d_json_handler.h"
#include "d_system/d_save_manager.h"
#include <cstddef>
#include <cstdio>
#include <cstring>
#include <revolution/fs.h>
#include <revolution/nand.h>
#include <revolution/os/OSError.h>

static void* rapidjsonRealloc(void* ptr, size_t size)
{
    u8* newPtr = new u8[size];
    if (newPtr && ptr) {
        std::memcpy(newPtr, ptr, size);
        delete[] (u8*) ptr;
    }
    return newPtr;
}

#define RAPIDJSON_MALLOC(size) new char[size]
#define RAPIDJSON_FREE(ptr) delete[] (u8*) ptr
#define RAPIDJSON_REALLOC rapidjsonRealloc
#include <rapidjson/reader.h>

[[nsmbw_data(0x8042A298)]]
dNandThread_c* dNandThread_c::m_instance;

namespace
{

/* @unofficial */
[[nsmbw_data(0x80359FC0)]]
u8 l_nandBuf[0x4000];

[[nsmbw_data(0x8035DFC0)]]
dMj2dData_c l_tmpSave;

NANDFileInfo l_fileInfo;

struct NandFileStream_c {
    using Ch = char;

    Ch Peek() const
    {
        if (mPos >= mAmount) {
            return 0;
        }

        return l_nandBuf[mPos];
    }

    Ch Take()
    {
        if (mPos >= mAmount) {
            return 0;
        }

        Ch c = l_nandBuf[mPos++];
        if (mPos >= mAmount && !mEof) {
            mTotalSize += mAmount;
            mAmount = 0;
            mPos = 0;
            mResult = NANDRead(&l_fileInfo, l_nandBuf, sizeof(l_nandBuf));
            if (mResult >= NAND_RESULT_OK) {
                mAmount = mResult;
                mResult = NAND_RESULT_OK;
                if (mAmount < sizeof(l_nandBuf)) {
                    mEof = true;
                }
            }
        }
        return c;
    }

    size_t Tell() const
    {
        return mTotalSize + mPos;
    }

    Ch* PutBegin()
    {
        __builtin_unreachable();
    }

    void Put(Ch c)
    {
        __builtin_unreachable();
    }

    void Flush()
    {
        __builtin_unreachable();
    }

    size_t PutEnd(Ch* begin)
    {
        __builtin_unreachable();
    }

    size_t mAmount = 0;
    size_t mTotalSize = 0;
    size_t mPos = 0;
    bool mEof = false;
    NANDResult mResult = NAND_RESULT_OK;
};

} // namespace

[[nsmbw(0x800CEF80)]]
void dNandThread_c::existCheck()
{
    u8 type;
    NANDResult result;

    result = NANDGetType("mkwcat-nsmbw.json", &type);
    if (result == NAND_RESULT_NOEXISTS) {
        result = NANDGetType("mkwcat-nsmbw-old.json", &type);
    }

    setNandError(result);
    if (isError()) {
        return;
    }

    mExists = (result == NAND_RESULT_OK && type == NAND_FILE_TYPE_FILE);
}

void dNandThread_c::reinitialize()
{
    l_tmpSave.mHeader.initialize();
    for (int i = 0; i < SAVE_SLOT_COUNT; i++) {
        l_tmpSave.mSaveGames[i].initialize();
        l_tmpSave.mTempGames[i].initialize();
    }
}

[[nsmbw(0x800CF170)]]
bool dNandThread_c::cmdSave(dMj2dData_c* data)
{
    if (!OSTryLockMutex(&mMutex)) {
        return false;
    }

    mError = 0;
    mState = 4;
    if (data != &l_tmpSave) {
        std::memcpy(static_cast<void*>(&l_tmpSave), static_cast<void*>(data), sizeof(dMj2dData_c));
    }
    OSUnlockMutex(&mMutex);
    OSSignalCond(&mThreadQueue);

    return true;
}

int dNandThread_c::ioProc(__file_handle file, u8* buff, std::size_t* count, __idle_proc idle_proc)
{
    if (file == 0 || buff == nullptr || count == nullptr || *count == 0) {
        return -1;
    }

    dNandThread_c* obj = reinterpret_cast<dNandThread_c*>(file);
    NANDResult result = NANDWrite(&l_fileInfo, buff, *count);
    if (result < NAND_RESULT_OK) {
        obj->setNandError(result);
        return -1;
    }
    *count = result;
    return 0;
}

extern "C" NANDResult nandConvertErrorCode(s32 isfsError);

[[nsmbw(0x800CF200)]]
int dNandThread_c::save()
{
    const char* tmpPath = "/tmp/mkwcat-nsmbw.json";
    char tmpPathData[64] = {};
    bool rename = false;
    NANDResult result = NANDCreate(tmpPath, 0x3C, 0);
    if (result == NAND_RESULT_INVALID) {
        // Might fail on console if /tmp is not redirected, due to the 12 character filename limit.
        // Riivolution allows renaming files though so we can create a tmp file in the home
        // directory with a different name instead
        setNandError(NANDGetHomeDir(tmpPathData));
        if (isError()) {
            return 1;
        }
        std::strcat(tmpPathData, "/mkwcat-nsmbw-tmp.json");
        result = NANDCreate(tmpPathData, 0x3C, 0);
        tmpPath = tmpPathData;
        rename = true;
    }
    setNandError(result);
    if (isError()) {
        return 1;
    }

    setNandError(NANDOpen(tmpPath, &l_fileInfo, 2));
    if (isError()) {
        setNandError(NANDDelete(tmpPath));
        return 1;
    }

    std::FILE file = {
      .handle = reinterpret_cast<__file_handle>(this),
      .file_mode =
        file_modes{
          .open_mode = 0,
          .io_mode = 2,
          .buffer_mode = 1,
          .file_kind = 2,
          .file_orientation = 0,
          .binary_io = 0,
        },
      .file_state =
        file_states{
          .io_state = 0,
          .free_buffer = 0,
          .eof = 0,
          .error = 0,
        },
      .is_dynamically_allocated = false,
      .char_buffer = 0,
      .char_buffer_overflow = 0,
      .ungetc_buffer = {},
      .ungetc_wide_buffer = {},
      .position = 0,
      .buffer = l_nandBuf,
      .buffer_size = sizeof(l_nandBuf),
      .buffer_ptr = l_nandBuf,
      .buffer_length = 0,
      .buffer_alignment = 0,
      .save_buffer_length = 0,
      .buffer_position = 0,
      .position_fn = nullptr,
      .read_fn = nullptr,
      .write_fn = ioProc,
      .close_fn = nullptr,
      .idle_fn = nullptr,
      .next_file = nullptr,
    };

    if (!dMj2dJsonHandler_c::writeJSON(&file)) {
        setNandError(NANDClose(&l_fileInfo));
        setNandError(NANDDelete(tmpPath));
        return 1;
    }

    std::fflush(&file);

    setNandError(NANDClose(&l_fileInfo));
    if (isError()) {
        setNandError(NANDDelete(tmpPath));
        return 1;
    }

    char newPath[64] = {};
    setNandError(NANDGetHomeDir(newPath));
    if (isError()) {
        setNandError(NANDDelete(tmpPath));
        return 1;
    }
    char oldPath[64];
    if (rename) {
        std::strcpy(oldPath, newPath);
    }
    std::strcat(newPath, "/mkwcat-nsmbw.json");
    if (rename) {
        // Rename the new path out of the way in case it's there. This is only a requirement with
        // Riivolution's proxy ISFS
        std::strcat(oldPath, "/mkwcat-nsmbw-old.json");
        result = nandConvertErrorCode(ISFS_Rename(newPath, oldPath));
        if (result != NAND_RESULT_OK && result != NAND_RESULT_NOEXISTS) {
            NANDDelete(newPath);
        }
        // No error checking as it might still work even if the file still exists
    }

    setNandError(nandConvertErrorCode(ISFS_Rename(tmpPath, newPath)));
    if (isError()) {
        setNandError(NANDDelete(tmpPath));
        return 1;
    }

    OS_REPORT("File saved!\n");
    return 0;
}

[[nsmbw(0x800CF680)]]
int dNandThread_c::load()
{
    std::memset(static_cast<void*>(&l_tmpSave), 0, sizeof(l_tmpSave));

    NANDResult result = NANDOpen("mkwcat-nsmbw.json", &l_fileInfo, 1);
    if (result != NAND_RESULT_OK) {
        result = NANDOpen("mkwcat-nsmbw-old.json", &l_fileInfo, 1);
    }

    setNandError(result);
    if (isError()) {
        return 1;
    }

    result = NANDRead(&l_fileInfo, l_nandBuf, sizeof(l_nandBuf));
    if (result < NAND_RESULT_OK) {
        setNandError(result);
        setNandError(NANDClose(&l_fileInfo));
        return 2;
    }

    for (int i = 0; i < SAVE_SLOT_COUNT; i++) {
        l_tmpSave.mSaveGames[i].setEmpty();
        l_tmpSave.mTempGames[i].setEmpty();
    }

    NandFileStream_c stream{
      .mAmount = static_cast<size_t>(result),
      .mTotalSize = 0,
      .mPos = 0,
      .mEof = result < sizeof(l_nandBuf),
      .mResult = NAND_RESULT_OK
    };
    rapidjson::Reader reader;
    dMj2dJsonHandler_c handler;
    rapidjson::ParseResult parseresult = reader.Parse(stream, handler);
    setNandError(NANDClose(&l_fileInfo));
    if (parseresult.IsError()) {
        OS_REPORT("JSON parse error, offset: %d\n", parseresult.Offset());
        std::memset(static_cast<void*>(&l_tmpSave), 0, sizeof(l_tmpSave));
        return 1;
    }

    return 0;
}

[[nsmbw(0x800CFC20)]]
void dNandThread_c::setNandError(s32 result);

[[nsmbw(0x800CFCA0)]]
dMj2dData_c* dNandThread_c::getSaveData();

[[nsmbw(0x800CFA50)]]
void dNandThread_c::deleteFile()
{
    setNandError(NANDDelete("mkwcat-nsmbw.json"));
}
