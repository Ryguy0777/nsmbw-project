// snd_Util.cpp
// NSMBW: 0x802836F0 - 0x80283BD0

#include "Util.h"

namespace nw4r::snd::detail::Util
{

[[address(0x80283BA0)]]
const void* GetDataRefAddressImpl(RefType type, u32 value, const void* pBase);

} // namespace nw4r::snd::detail::Util