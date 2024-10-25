// d_lytbase.cpp
// NSMBW: 0x800C89A0 - 0x800C9B50

#include "d_lytbase.h"

[[address(0x800C89A0)]]
LytBase_c::LytBase_c();

/* VT+0x08 */
[[address(0x800C89F0)]]
LytBase_c::~LytBase_c();

/* VT+0x14 */
[[address(0x800C8A60)]]
bool LytBase_c::build(const char* lytName, d2d::ResAccMult_c* resAcc);

[[address(0x800C8E50)]]
void LytBase_c::NPaneRegister(const char** paneNames, nw4r::lyt::Pane** nullPanes, int count);

[[address(0x800C8EC0)]]
void LytBase_c::WPaneRegister(
    const char** windowNames, nw4r::lyt::Window** windowPanes, int count
  );

[[address(0x800C8F30)]]
void LytBase_c::PPaneRegister(
    const char** pictureNames, nw4r::lyt::Picture** picturePanes, int count
  );

[[address(0x800C8FA0)]]
void LytBase_c::TPaneRegister(const char** paneNames, LytTextBox_c** textBoxPanes, int count);

[[address(0x800C90A0)]]
void LytBase_c::AnimeResRegister(const char** animNames, int count);

#if 0
[[address(0x800C91E0)]]
void LytBase_c::GroupRegister(const char** groupNames, const int* param_2, int count);
#endif

#define relimport(_ADDRESS)                                                                        \
  __gnu__::__section__(".external." #_ADDRESS)]]  void __external_##_ADDRESS() {}                        \
  [[__gnu__::__alias__("__external_" #_ADDRESS)


// [[relimport(0x800C91E0)]]

[[clang::external("0x800C91E0")]]
void LytBase_c::GroupRegister(const char** groupNames, const int* param_2, int count);