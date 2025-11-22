// s_StateID.cpp
// NSMBW .text: 0x8015F900 - 0x8015FAE0

#include "s_StateID.h"
#include <cstring>

/**
 * A null state instance.
 */
[[address_data(0x80377D04)]]
sStateID_c sStateID::null;

[[address_data(0x8042A640)]]
sStateID_c::NumberMemo_c sStateID_c::sm_numberMemo;

[[address(0x8015F900)]]
sStateID_c::sStateID_c(const char* name);

[[address(0x8015F940)]]
sStateID_c::~sStateID_c();

[[address(0x8015F980)]]
bool sStateID_c::isNull() const;

[[address(0x8015F990)]]
bool sStateID_c::isEqual(const sStateIDIf_c& other) const;

[[address(0x8015FA00)]]
bool sStateID_c::operator==(const sStateIDIf_c& other) const;

[[address(0x8015FA10)]]
bool sStateID_c::operator!=(const sStateIDIf_c& other) const;

[[address(0x8015FA50)]]
bool sStateID_c::isSameName(const char* otherName) const
{
    char* part = std::strrchr(otherName, ':');
    if (part != nullptr) {
        otherName = part + 1;
    }
    const char* thisName = std::strrchr(name(), ':') + 1;
    return std::strcmp(thisName, otherName) == 0;
}

[[address(0x8015FA60)]]
const char* sStateID_c::name() const;

[[address(0x8015FA70)]]
unsigned sStateID_c::number() const
{
    if (mNumber == -1) {
        mNumber = sm_numberMemo.get();
    }
    return mNumber;
}

// 8015FA80: __sinit_\s_StateID_cpp
