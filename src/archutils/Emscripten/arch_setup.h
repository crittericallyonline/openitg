#ifndef ARCH_SETUP_EMSCRIPTEN_H
#define ARCH_SETUP_EMSCRIPTEN_H

#if !defined(MISSING_STDINT_H) /* need to define int64_t if so */
#include <stdint.h>
#endif

#if !defined(ENDIAN_LITTLE) && !defined(ENDIAN_BIG)
#define LITTLE_ENDIAN 1234
#define BIG_ENDIAN 4321
#endif

#endif