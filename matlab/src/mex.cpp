#include "mex.h"
#include "include/mex_Export.h"

int mex_Export mexCallMATLAB(int, mxArray *[], int, mxArray *[], const char *) {}
mxArray mex_Export *mexCallMATLABWithTrap(int, mxArray *[], int, mxArray *[], const char *) {}
void mex_Export mexWarnMsgIdAndTxt(const char *, const char *, ...) {}
int mex_Export mexPrintf(const char*, ...) {}
void mex_Export mexLock(void) {}
int mex_Export mexAtExit(void (*)(void)) {}
