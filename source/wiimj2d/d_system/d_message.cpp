// d_message.cpp
// NSMBW .text: 0x800CDB60 - 0x800CDFB0

#include "d_message.h"

[[address(0x800CDB60)]]
dMessage_c::dMessage_c();

[[address(0x800CDBA0)]]
dMessage_c::~dMessage_c();

[[address(0x800CDC20)]]
bool dMessage_c::create(EGG::Heap* heap);

[[address(0x800CDCE0)]]
void dMessage_c::buildMsgRes(EGG::Heap* heap);

[[address(0x800CDD30)]]
wchar_t* dMessage_c::getMsg(u32 upper, u32 lower);

[[address(0x800CDD50)]]
MsgRes_c* dMessage_c::getMesRes();

[[address(0x800CDD60)]]
void dMessage_c::itoa(int i, wchar_t* buffer, u32 buffer_size, int max_num_chars, int);

[[address(0x800CDEA0)]]
void dMessage_c::itoaCustom(int i, wchar_t* buffer, u32 buffer_size, int max_num_chars, int);

[[address(0x800CDEE0)]]
void dMessage_c::toCustomFont(wchar_t* ws);
