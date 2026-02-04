// d_a_wm_Map.cpp
// NSMBW d_bases.text: 0x808DEA90 - 0x808E3700

#include "d_a_wm_Map.h"

#include "framework/f_feature.h"

[[nsmbw(0x808DFE50)]]
void daWmMap_c::createEnemyActors();

[[nsmbw(0x808E1750)]]
void daWmMap_c::createMapActors();

EXTERN_REPL(0x808E2250, bool daWmMap_c::IsRouteOpen2(const char* routeName));

[[nsmbw(0x808E2250)]]
bool daWmMap_c::IsRouteOpen(const char* routeName)
{
    if (fFeat::all_paths_available) {
        return true;
    }
    return IsRouteOpen2(routeName);
}

EXTERN_REPL(
  0x808E2380, bool daWmMap_c::IsIbaraRouteOpen2(const char* subRoute1, const char* subRoute2)
);

[[nsmbw(0x808E2380)]]
bool daWmMap_c::IsIbaraRouteOpen(const char* subRoute1, const char* subRoute2)
{
    if (fFeat::all_paths_available) {
        return true;
    }

    return IsIbaraRouteOpen2(subRoute1, subRoute2);
}
