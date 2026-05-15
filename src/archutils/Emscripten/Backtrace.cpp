#include "../../global.h"
#include "Backtrace.h"
#include "../../RageUtil.h"

#include <unistd.h>
#include <cstdlib>
// #include <sys/types.h>
// #include <sys/wait.h>
// #include <sys/ptrace.h>
// #include <sys/stat.h>
// #include <cerrno>
// #include <fcntl.h>

#warning Undefined BACKTRACE_METHOD_*
void InitializeBacktrace() { }

void GetBacktrace( const void **buf, size_t size, const BacktraceContext *ctx )
{
    buf[0] = BACKTRACE_METHOD_NOT_AVAILABLE;
    buf[1] = NULL;
}
