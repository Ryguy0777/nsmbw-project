#pragma once

#include "d_system/d_system.h"
#include "framework/f_base.h"
#include <type_traits>

class dBase_c;

using dProfName = fProfName;

namespace dProf
{

template <dProfName V>
struct Name_c {
    static constexpr dProfName StaticNonRegionalValue = V;

    static inline constexpr dProfName toNative();

    constexpr operator dProfName() const
    {
        return toNative();
    }
};

#define PROFILE(_ID, _NAME, _CLASS) constexpr Name_c<_ID> _NAME;
#include "d_profile.lst"
#undef PROFILE

template <dProfName V>
inline constexpr dProfName Name_c<V>::toNative()
{
    // Apply the region-dependant changes to the value
    dProfName value = V;
    if constexpr (V >= TIME_UP.StaticNonRegionalValue) {
        if (dSys_c::m_codeRegion < dSys_c::CODE_REGION_e::K) {
            value -= 2;
        }
    }
    if constexpr (V >= WM_CS_SEQ_MNG.StaticNonRegionalValue) {
        if (dSys_c::m_codeRegion < dSys_c::CODE_REGION_e::C) {
            value -= 2;
        }
    }
    return value;
}

template <class Owner, auto... Profiles>
struct Info {
};

template <class Owner, auto... Profiles>
constexpr bool hasProfile(dProfName prof, const Info<Owner, Profiles...>*)
{
    return (false || ... || (Profiles == prof));
}

/**
 * Downcast the base to the specified type. Verifies the object's profile with the specified type's
 * profile, and returns nullptr if the profile doesn't match.
 */
template <class T>
constexpr T* cast(fBase_c* base)
{
    if constexpr (std::is_same_v<T, dBase_c>) {
        // Everything is a dBase_c
        return static_cast<T*>(base);
    } else {
        if (hasProfile<T>(base->mProfName, (T*) nullptr)) {
            return static_cast<T*>(base);
        }
    }

    // Wrong type
    return nullptr;
}

// Moved dProf_getName into the dProf namespace

/* 0x801018C0 */
const char* getName(dProfName profile);

const char* getFormattedName(dBase_c* base);

} // namespace dProf
