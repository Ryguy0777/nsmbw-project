// f_base.cpp
// NSMBW .text: 0x80161A60 - 0x80162C80

#include "f_base.h"

[[address(0x80161C10)]]
fBase_c::fBase_c();

[[address(0x80161D80)]]
fBase_c::~fBase_c();

[[address(0x80161EC0)]]
fBase_c::PACK_RESULT_e fBase_c::create();

[[address(0x80161ED0)]]
fBase_c::PACK_RESULT_e fBase_c::preCreate();

[[address(0x80161EE0)]]
void fBase_c::postCreate(MAIN_STATE_e state);

[[address(0x80161F70)]]
fBase_c::PACK_RESULT_e fBase_c::doDelete();

[[address(0x80162030)]]
fBase_c::PACK_RESULT_e fBase_c::preDelete();

[[address(0x801620A0)]]
void fBase_c::postDelete(MAIN_STATE_e state);

[[address(0x80162210)]]
fBase_c::PACK_RESULT_e fBase_c::execute();

[[address(0x80162220)]]
fBase_c::PACK_RESULT_e fBase_c::preExecute();

[[address(0x80162250)]]
void fBase_c::postExecute(MAIN_STATE_e state);

[[address(0x80162310)]]
fBase_c::PACK_RESULT_e fBase_c::draw();

[[address(0x80162320)]]
fBase_c::PACK_RESULT_e fBase_c::preDraw();

[[address(0x80162350)]]
void fBase_c::postDraw(MAIN_STATE_e state);

[[address(0x80162410)]]
void fBase_c::deleteReady();

[[address(0x80162650)]]
void fBase_c::deleteRequest();

[[address(0x80162730)]]
bool fBase_c::entryFrmHeap(u32 size, void* parentHeap);

[[address(0x80162930)]]
bool fBase_c::entryFrmHeapNonAdjust(u32 size, void* parentHeap);

[[address(0x801629F0)]]
bool fBase_c::createHeap();

[[address(0x80162A00)]]
void* fBase_c::operator new(size_t);

[[address(0x80162A60)]]
void fBase_c::operator delete(void*);

[[address(0x80162B60)]]
bool fBase_c::checkChildProcessCreateState() const;

[[address(0x80162C40)]]
fBase_c* fBase_c::createChild(fProfName profName, fBase_c* parent, u32 param, u8 groupType);

[[address(0x80162C60)]]
fBase_c* fBase_c::createRoot(fProfName profName, u32 param, u8 groupType);
