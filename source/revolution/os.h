#pragma once

#include "gx/GXStruct.h"
#include "os/OSCache.h"
#include "os/OSContext.h"
#include "os/OSError.h"
#include "os/OSInterrupt.h"
#include "os/OSLink.h"

extern "C" {

void OSRegisterVersion(const char* string);

/* 0x801AF710 */
void OSFatal(GXColor textColor, GXColor bgColor, const char* text);

//
} // extern "C"