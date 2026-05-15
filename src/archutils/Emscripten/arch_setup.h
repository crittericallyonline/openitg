#ifndef ARCH_SETUP_EMSCRIPTEN_H
#define ARCH_SETUP_EMSCRIPTEN_H

#if !defined(MISSING_STDINT_H) /* need to define int64_t if so */
#include <stdint.h>
#endif

#define ENDIAN_LITTLE

#endif