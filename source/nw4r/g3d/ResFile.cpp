// g3d_resfile.cpp
// NSMBW .text: 0x80239F70 - 0x8023B2F0

#include "nw4r/g3d/g3d_resfile.h"

namespace nw4r::g3d
{

[[address(0x80239F70)]]
ResMdl ResFile::GetResMdl(const char* name) const;

[[address(0x8023A340)]]
ResAnmTexPat ResFile::GetResAnmTexPat(const char* name) const;

} // namespace nw4r::g3d