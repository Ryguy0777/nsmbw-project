#pragma once

#include "os/OSCache.h"
#include "os/OSContext.h"
#include "os/OSError.h"
#include "os/OSInterrupt.h"
#include "os/OSLink.h"
#include "os/OSFatal.h"

extern "C" {

void OSRegisterVersion(const char* string);

} // extern "C"
