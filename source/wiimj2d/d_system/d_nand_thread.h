#pragma once

#include "d_mj2d_data.h"
#include <cstdio>
#include <revolution/os/OSMutex.h>
#include <revolution/os/OSThread.h>

class dNandThread_c
{
public:
    // ----------------
    // Member Functions
    // ----------------

    /* 0x800CF170 @unofficial */
    bool cmdSave(dMj2dData_c* data);

private:
    /* 0x800CEF80 */
    void existCheck();

    /* 0x800CF200 */
    int save();

    /* 0x800CF680 */
    int load();

    /* 0x800CFA50 */
    void deleteFile();

    /* 0x800CFC20 */
    void setNandError(s32 result);

    inline bool isError() const
    {
        return mError != 0;
    }

    inline bool isNandFailure() const
    {
        return mError == 6;
    }

public:
    // -----------
    // Member Data
    // -----------

    FILL(0x00, 0x54);
    /* 0x54 */ OSMutex mMutex;
    /* 0x6C */ OSThreadQueue mThreadQueue;
    /* 0x74 */ s32 mState;
    /* 0x78 */ s32 mError;
    /* 0x7C */ bool mExists;

public:
    // ----------------
    // Static Functions
    // ----------------

    static void reinitialize();

    /* 0x800CFCA0 */
    static dMj2dData_c* getSaveData();

private:
    static int ioProc(__file_handle file, u8* buff, std::size_t* count, __idle_proc idle_proc);

public:
    // -----------
    // Static Data
    // -----------

    /* 0x8042A298 */
    static dNandThread_c* m_instance;
};
