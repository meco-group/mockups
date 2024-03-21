#include "mex.h"

int mex_Export mexCallMATLAB(int, mxArray *[], int, mxArray *[], const char *) { return 0; }
void mex_Export mexErrMsgIdAndTxt(const char *, const char *, ...) {}
mxArray mex_Export *mexCallMATLABWithTrap(int, mxArray *[], int, mxArray *[], const char *) { return 0; }
mxArray mex_Export *mexGetVariable(const char *, const char *) { return 0; }
void mex_Export mexWarnMsgIdAndTxt(const char *, const char *, ...) {}
int mex_Export mexPrintf(const char*, ...) { return 0; }
void mex_Export mexLock(void) {}
int mex_Export mexAtExit(void (*)(void)) { return 0; }
int mex_Export mexEvalString(const char *) { return 0; }