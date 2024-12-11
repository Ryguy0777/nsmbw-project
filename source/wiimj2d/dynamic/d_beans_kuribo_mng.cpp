// d_beans_kuribo_mng.cpp
// NSMBW .text: 0x80076BC0 - 0x80076FD0

#include "d_beans_kuribo_mng.h"

[[address_data(0x8042A0A0)]]
dBeansKuriboMng_c* dBeansKuriboMng_c::m_instance;

[[address(0x80076BC0)]]
void dBeansKuriboMng_c::clear();
