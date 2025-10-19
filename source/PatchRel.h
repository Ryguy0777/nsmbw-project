#pragma once

#include "AddressMapper.h"
#include <revolution/os/OSLink.h>

struct _MRel_PatchRel {
    consteval _MRel_PatchRel(u32 _addrP1, u8 _type, u16 _addend = 0)
      : type(_type)
      , addend(_addend)
      , addrP1(_addrP1)
    {
    }

    u8 type;
    u16 addend;

    u32 addrP1;
#ifndef CLANGD
    u32 addrP2 = AddressMapperP2.MapAddress(addrP1);
    u32 addrE1 = AddressMapperE1.MapAddress(addrP1);
    u32 addrE2 = AddressMapperE2.MapAddress(addrP1);
    u32 addrJ1 = AddressMapperJ1.MapAddress(addrP1);
    u32 addrJ2 = AddressMapperJ2.MapAddress(addrP1);
    u32 addrK = AddressMapperK.MapAddress(addrP1);
    u32 addrW = AddressMapperW.MapAddress(addrP1);
    u32 addrC = AddressMapperC.MapAddress(addrP1);
#else
    u32 addrP2 = 0;
    u32 addrE1 = 0;
    u32 addrE2 = 0;
    u32 addrJ1 = 0;
    u32 addrJ2 = 0;
    u32 addrK = 0;
    u32 addrW = 0;
    u32 addrC = 0;
#endif
};

template <u32 N>
struct _MRel_patch_references_array_entry {
    const void* addr;
    u32 count = N;
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wzero-length-array"
    _MRel_PatchRel references[N];
#pragma clang diagnostic pop
};

template <u32 N>
struct _MRel_patch_member_array_entry {
    u32 offset;
    u32 count = N;
    _MRel_PatchRel references[N];
};

#define _PATCH_REFERENCES3(_COUNTER, _DEST, ...)                                                   \
    [[__gnu__::__section__("patch_references_array"                                                \
    )]] [[__gnu__::__used__]] static constinit _MRel_patch_references_array_entry                  \
      _MRel_patch_references_array_entry_##_COUNTER = {.addr = &_DEST, .references = __VA_ARGS__};

#define _PATCH_REFERENCES2(_COUNTER, _DEST, ...) _PATCH_REFERENCES3(_COUNTER, _DEST, __VA_ARGS__)

#define _PATCH_REFERENCES1(_COUNTER, _DEST, ...) _PATCH_REFERENCES2(_COUNTER, _DEST, __VA_ARGS__)

#define PATCH_REFERENCES(_DEST, ...) _PATCH_REFERENCES1(__COUNTER__, _DEST, __VA_ARGS__)

#define _PATCH_MEMBER_REFERENCES3(_COUNTER, _DEST, ...)                                            \
    [[__gnu__::__section__("patch_references_array"                                                \
    )]] [[__gnu__::__used__]] static constinit _MRel_patch_member_array_entry                      \
      _MRel_patch_references_array_entry_##_COUNTER = {                                            \
        .offset = _DEST, .references = __VA_ARGS__                                                 \
    };

#define _PATCH_MEMBER_REFERENCES2(_COUNTER, _DEST, ...)                                            \
    _PATCH_MEMBER_REFERENCES3(_COUNTER, _DEST, __VA_ARGS__)

#define _PATCH_MEMBER_REFERENCES1(_COUNTER, _DEST, ...)                                            \
    _PATCH_MEMBER_REFERENCES2(_COUNTER, _DEST, __VA_ARGS__)

#define PATCH_MEMBER_REFERENCES(_DEST, ...)                                                        \
    _PATCH_MEMBER_REFERENCES1(__COUNTER__, _DEST, __VA_ARGS__)
