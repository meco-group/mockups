#ifndef mex_H
#define mex_H


extern "C"
{
  typedef struct mxArray_tag mxArray;


  #include <matrix.h>

  #include <mex_versions.h>

// methods
int mexCallMATLAB(int, mxArray *[], int, mxArray *[], const char *);
mxArray *mexCallMATLABWithTrap(int, mxArray *[], int, mxArray *[], const char *);
int mexEvalString(const char *);
void mexWarnMsgIdAndTxt(const char *, const char *, ...);
int mexPrintf(const char*, ...);
void mexLock(void);
int mexAtExit(void (*)(void));

}

#endif // mex_H
