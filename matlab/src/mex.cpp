#include "mex.h"

int mexCallMATLAB(int, mxArray *[], int, mxArray *[], const char *) { return 0; }
mxArray *mexCallMATLABWithTrap(int, mxArray *[], int, mxArray *[], const char *) { return 0; }
void mexWarnMsgIdAndTxt(const char *, const char *, ...) {}
int mexPrintf(const char*, ...) { return 0; }
void mexLock(void) {}
int mexAtExit(void (*)(void)) { return 0; }
int mexEvalString(const char *) { return 0; }
