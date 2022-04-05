#include "mex.h"

int mex_Export mexCallMATLAB(int, mxArray *[], int, mxArray *[], const char *) {}
mxArray mex_Export *mexCallMATLABWithTrap(int, mxArray *[], int, mxArray *[], const char *) {}
void mex_Export mexWarnMsgIdAndTxt(const char *, const char *, ...) {}
int mex_Export mexPrintf(const char*, ...) {}
void mex_Export mexLock(void) {}
int mex_Export mexAtExit(void (*)(void)) {}
int mexEvalString(const char *) {}

// Undocumented Matlab API
bool utIsInterruptPending(void) { return true; }
void utSetInterruptPending(bool) {}