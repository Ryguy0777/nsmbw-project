// g3d_resfile.cpp
// NSMBW: 0x80239F70 - 0x8023B2F0

#include "nw4r/g3d/g3d_resfile.h"

namespace nw4r::g3d
{

EXTERN_TEXT(
  0x80239F70, //
  ResMdl ResFile::GetResMdl(const char* name) const
);

EXTERN_TEXT(
  0x8023A340, //
  ResAnmTexPat ResFile::GetResAnmTexPat(const char* name) const
);

} // namespace nw4r::g3d