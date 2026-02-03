//
//  mkwcat/Relocate.hpp
//  nsmbw-project
//

#pragma once

#include "AddressMapper.hpp"
#include "BaseTypes.hpp"
#include "Macro.hpp"
#include <revolution/os/OSLink.h>

namespace mkwcat::Relocate
{

struct Reference {
    consteval Reference()
      : type(0)
      , addend(0)
      , addrP1(0)
    {
    }

    consteval Reference(u32 _addrP1, u8 _type, u16 _addend = 0)
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
struct Entry {
    constexpr Entry(u32 offset, const Reference (&_references)[N])
    {
        dest.offset = offset;
        for (unsigned i = 0; i < N; i++) {
            references[i] = _references[i];
        }
    }

    constexpr Entry(const void* const& addr, const Reference (&_references)[N])
    {
        dest.addr = addr;
        for (unsigned i = 0; i < N; i++) {
            references[i] = _references[i];
        }
    }

    union {
        const void* addr;
        u32 offset;
    } dest;

    u32 count = N;

    Reference references[N];
};

#define __PATCH_REFERENCES_EVAL(_COUNTER, _DEST, ...)                                              \
    SECTION("patch_references_array")                                                              \
    [[__gnu__::__used__]] static constinit ::mkwcat::Relocate::Entry __RelocateEntry_##_COUNTER =  \
      {_DEST, __VA_ARGS__};
#define __PATCH_REFERENCES(_COUNTER, _DEST, ...)                                                   \
    __PATCH_REFERENCES_EVAL(_COUNTER, _DEST, __VA_ARGS__)

#define PATCH_REFERENCES(_DEST, ...) __PATCH_REFERENCES(__COUNTER__, _DEST, __VA_ARGS__)

} // namespace mkwcat::Relocate
