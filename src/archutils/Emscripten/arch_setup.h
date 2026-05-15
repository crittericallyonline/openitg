#ifndef ARCH_SETUP_EMSCRIPTEN_H
#define ARCH_SETUP_EMSCRIPTEN_H

#if !defined(MISSING_STDINT_H) /* need to define int64_t if so */
#include <stdint.h>
#endif

#include <endian.h>

#if !defined(ENDIAN_LITTLE) && !defined(ENDIAN_BIG)
#define ENDIAN_LITTLE 1234
#define ENDIAN_BIG 4321
#endif

#endif