#include "mex.h"

int mexCallMATLAB(int, mxArray *[], int, mxArray *[], const char *) { return 0; }
void mexErrMsgIdAndTxt(const char *, const char *, ...) {}
mxArray *mexCallMATLABWithTrap(int, mxArray *[], int, mxArray *[], const char *) { return 0; }
mxArray *mexGetVariable(const char *, const char *) { return 0; }
void mexWarnMsgIdAndTxt(const char *, const char *, ...) {}
int mexPrintf(const char*, ...) { return 0; }
void mexLock(void) {}
int mexAtExit(void (*)(void)) { return 0; }
int mexEvalString(const char *) { return 0; }
