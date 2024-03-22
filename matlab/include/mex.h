#ifndef mex_H
#define mex_H
#include "mex_Export.h"
#include "mx_Export.h"


extern "C"
{
  typedef struct mxArray_tag mxArray;


  #include <matrix.h>

  #include <mex_versions.h>

// methods
int mex_Export mexCallMATLAB(int, mxArray *[], int, mxArray *[], const char *);
void mex_Export mexErrMsgIdAndTxt(const char *, const char *, ...);
mxArray mex_Export *mexCallMATLABWithTrap(int, mxArray *[], int, mxArray *[], const char *);
mxArray mex_Export *mexGetVariable(const char *, const char *);
int mex_Export mexEvalString(const char *);
void mex_Export mexWarnMsgIdAndTxt(const char *, const char *, ...);
int mex_Export mexPrintf(const char*, ...);
void mex_Export mexLock(void);
int mex_Export mexAtExit(void (*)(void));
void mex_Export mexMakeArrayPersistent(mxArray *);

}

#endif // mex_H
