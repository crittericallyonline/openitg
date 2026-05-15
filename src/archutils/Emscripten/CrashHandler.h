#ifndef CRASH_HANDLER_H
#define CRASH_HANDLER_H

void ForceCrashHandler( const char *reason );
struct BacktraceContext;
void ForceCrashHandlerDeadlock( CString reason, uint64_t CrashHandle );
void CrashHandlerHandleArgs( int argc, char* argv[] );
void InitializeCrashHandler();
	
#include <csignal>
#include <ucontext.h>
void CrashSignalHandler( int signal, siginfo_t *si, const ucontext_t *uc );

#endif