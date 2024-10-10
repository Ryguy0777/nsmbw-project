#pragma once

namespace EGG
{

class File
{
public:
    /* VT+0x08 */
    virtual ~File()
    {
    }

    /* VT+0x0C */
    virtual bool open(const char* path) = 0;

    /* VT+0x0C */
    virtual void close() = 0;

    /* VT+0x10 */
    virtual s32 readData(void* data, s32, s32) = 0;

    /* VT+0x14 */
    virtual s32 writeData(const void* data, s32, s32) = 0;
    
    /* VT+0x18 */
    virtual s32 getFileSize() const = 0;
};

} // namespace EGG
