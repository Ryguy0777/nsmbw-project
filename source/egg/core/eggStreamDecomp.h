#pragma once

namespace EGG
{

class StreamDecomp
{
public:
    /* VT+0x08 */
    virtual bool init(void* dst, u32 maxCompressedSize) = 0;

    /* VT+0x0C */
    virtual bool decomp(const void* src, u32 size) = 0;

    /* VT+0x10 */
    virtual u32 getHeaderSize() = 0;

    /* VT+0x14 */
    virtual u32 getUncompressedSize(const void* src) = 0;
};

static_assert(sizeof(StreamDecomp) == 0x4);

class StreamDecompLZ : public StreamDecomp
{
public:
    StreamDecompLZ() = default;
    ~StreamDecompLZ() = default;

    /* VT+0x08 0x802B8560 */
    virtual bool init(void* dst, u32 maxCompressedSize) override;

    /* VT+0x0C 0x802B8590 */
    virtual bool decomp(const void* src, u32 size) override;

    /* VT+0x10 0x802B8BA0 */
    virtual u32 getHeaderSize() override;

    /* VT+0x14 0x802B8B90 */
    virtual u32 getUncompressedSize(const void* src) override;

private:
    FILL(0x4, 0x24);
};

static_assert(sizeof(StreamDecompLZ) == 0x24);

class StreamDecompRL : public StreamDecomp
{
public:
    StreamDecompRL() = default;
    ~StreamDecompRL() = default;

    /* VT+0x08 0x802B85C0 */
    virtual bool init(void* dst, u32 maxCompressedSize) override;

    /* VT+0x0C 0x802B85F0 */
    virtual bool decomp(const void* src, u32 size) override;

    /* VT+0x10 0x802B8B80 */
    virtual u32 getHeaderSize() override;

    /* VT+0x14 0x802B8B70 */
    virtual u32 getUncompressedSize(const void* src) override;

private:
    FILL(0x4, 0x1C);
};

static_assert(sizeof(StreamDecompRL) == 0x1C);

class StreamDecompLH : public StreamDecomp
{
public:
    StreamDecompLH() = default;
    ~StreamDecompLH() = default;

    /* VT+0x08 0x802B8620 */
    virtual bool init(void* dst, u32 maxCompressedSize) override;

    /* VT+0x0C 0x802B8650 */
    virtual bool decomp(const void* src, u32 size) override;

    /* VT+0x10 0x802B8B60 */
    virtual u32 getHeaderSize() override;

    /* VT+0x14 0x802B8B70 */
    virtual u32 getUncompressedSize(const void* src) override;

private:
    FILL(0x4, 0x8B4);
};

static_assert(sizeof(StreamDecompLH) == 0x8B4);

class StreamDecompLRC : public StreamDecomp
{
public:
    StreamDecompLRC() = default;
    ~StreamDecompLRC() = default;

    /* VT+0x08 0x802B8680 */
    virtual bool init(void* dst, u32 maxCompressedSize) override;

    /* VT+0x0C 0x802B86B0 */
    virtual bool decomp(const void* src, u32 size) override;

    /* VT+0x10 0x802B8B40 */
    virtual u32 getHeaderSize() override;

    /* VT+0x14 0x802B8B30 */
    virtual u32 getUncompressedSize(const void* src) override;

private:
    FILL(0x4, 0x9038);
};

static_assert(sizeof(StreamDecompLRC) == 0x9038);

class StreamDecompSZS : public StreamDecomp
{
public:
    StreamDecompSZS() = default;
    ~StreamDecompSZS() = default;

    /* VT+0x08 0x802B8AB0 */
    virtual bool init(void* dst, u32 maxCompressedSize) override;

    /* VT+0x0C 0x802B8AE0 */
    virtual bool decomp(const void* src, u32 size) override;

    /* VT+0x10 0x802B8B20 */
    virtual u32 getHeaderSize() override;

    /* VT+0x14 0x802B8B10 */
    virtual u32 getUncompressedSize(const void* src) override;

private:
    FILL(0x4, 0x20);
};

static_assert(sizeof(StreamDecompSZS) == 0x20);

} // namespace EGG
