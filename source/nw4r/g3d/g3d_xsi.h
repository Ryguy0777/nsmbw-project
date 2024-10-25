#ifndef NW4R_G3D_XSI_H
#define NW4R_G3D_XSI_H

#include "nw4r/math.h"
#include "g3d_anmtexsrt.h"

namespace nw4r {
namespace g3d {
namespace detail {
namespace dcc {
bool CalcTexMtx_Xsi(math::MTX34 *, bool, const TexSrt &, TexSrt::Flag);
}
} // namespace detail
} // namespace g3d
} // namespace nw4r

#endif
