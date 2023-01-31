
#define DLL_IMPLEMENTATION
#include "mex.h"
#ifdef _WIN32
#include <libloaderapi.h>
#include <stdio.h>


int (*mxAddField)(mxArray *, const char *) = NULL;
char* (*mxArrayToString)(const mxArray *) = NULL;
mxArray* (*mxCreateCellMatrix)(mwSize, mwSize) = NULL;
mxArray* (*mxCreateCharMatrixFromStrings)(mwSize, const char **) = NULL;
mxArray* (*mxCreateDoubleMatrix)(mwSize, mwSize, mxComplexity) = NULL;
mxArray* (*mxCreateDoubleScalar)(double) = NULL;
mxArray* (*mxCreateLogicalMatrix)(mwSize, mwSize) = NULL;
mxArray* (*mxCreateLogicalScalar)(bool) = NULL;
mxArray* (*mxCreateNumericArray)(mwSize, const mwSize *, mxClassID, mxComplexity) = NULL;
mxArray* (*mxCreateNumericMatrix)(mwSize, mwSize, mxClassID, mxComplexity) = NULL;
mxArray* (*mxCreateSparse)(mwSize, mwSize, mwSize, mxComplexity) = NULL;
mxArray* (*mxCreateString)(const char *) = NULL;
mxArray* (*mxCreateStructMatrix)(mwSize, mwSize, int, const char **) = NULL;
void (*mxDestroyArray)(mxArray *) = NULL;
mxArray* (*mxGetCell)(const mxArray *, mwIndex) = NULL;
mxChar* (*mxGetChars)(const mxArray *) = NULL;
mxClassID (*mxGetClassID)(const mxArray *) = NULL;
void* (*mxGetData)(const mxArray *) = NULL;
const mwSize* (*mxGetDimensions)(const mxArray *) = NULL;
mxArray* (*mxGetField)(const mxArray *, mwIndex, const char *) = NULL;
mxArray* (*mxGetFieldByNumber)(const mxArray *, mwIndex, int) = NULL;
const char* (*mxGetFieldNameByNumber)(const mxArray *, int) = NULL;
mwIndex* (*mxGetIr)(const mxArray *) = NULL;
mwIndex* (*mxGetJc)(const mxArray *) = NULL;
size_t (*mxGetN)(const mxArray *) = NULL;
size_t (*mxGetM)(const mxArray *) = NULL;
mwSize (*mxGetNumberOfDimensions)(const mxArray *) = NULL;
mwSize (*mxGetNumberOfElements)(const mxArray *) = NULL;
int (*mxGetNumberOfFields)(const mxArray *) = NULL;
mxArray* (*mxGetProperty)(const mxArray *, const mwIndex, const char *) = NULL;
double (*mxGetScalar)(const mxArray *) = NULL;
int (*mxGetString)(const mxArray *, char *, mwSize) = NULL;
bool (*mxIsCell)(const mxArray *) = NULL;
bool (*mxIsChar)(const mxArray *) = NULL;
bool (*mxIsComplex)(const mxArray *) = NULL;
bool (*mxIsDouble)(const mxArray *) = NULL;
bool (*mxIsLogical)(const mxArray *) = NULL;
bool (*mxIsLogicalScalar)(const mxArray *) = NULL;
bool (*mxIsLogicalScalarTrue)(const mxArray *) = NULL;
bool (*mxIsNumeric)(const mxArray *) = NULL;
bool (*mxIsSparse)(const mxArray *) = NULL;
bool (*mxIsStruct)(const mxArray *) = NULL;
void (*mxSetCell)(mxArray *, mwIndex, mxArray *) = NULL;
void (*mxSetField)(mxArray *, mwIndex, const char *, mxArray *) = NULL;
void (*mxSetProperty)(mxArray *, mwIndex, const char *, const mxArray *) = NULL;
void (*mxSetFieldByNumber)(mxArray *, mwIndex, int, mxArray *) = NULL;
mxArray* (*mxCreateCharArray)(mwSize, const mwSize *) = NULL;
int (*mexCallMATLAB)(int, mxArray *[], int, mxArray *[], const char *) = NULL;
mxArray* (*mexCallMATLABWithTrap)(int, mxArray *[], int, mxArray *[], const char *) = NULL;
void (*mexErrMsgIdAndTxt)(const char *, const char *, ...) = NULL;
void (*mexErrMsgTxt)(const char *) = NULL;
int (*mexEvalString)(const char *) = NULL;
void (*mexWarnMsgIdAndTxt)(const char *, const char *, ...) = NULL;
int (*mexPrintf)(const char*, ...) = NULL;
void (*mexLock)(void) = NULL;
int (*mexAtExit)(void (*)(void)) = NULL;

BOOL APIENTRY DllMain( HMODULE hModule,
             DWORD  ul_reason_for_call,
             LPVOID lpReserved
           ) {
  switch (ul_reason_for_call) {
    case DLL_PROCESS_ATTACH:
      {
        char buffer[100];
        for (int i=0; i<100; i++) {
          if (i==0) {
            sprintf(buffer, "liboctinterp.dll");
          } else {
            sprintf(buffer, "liboctinterp-%d.dll", i);
          }
          HMODULE h = GetModuleHandle(buffer);
          if (h != NULL) {
            mxAddField = (int (*)(mxArray *, const char *)) GetProcAddress(h, "mxAddField");
            mxArrayToString = (char* (*)(const mxArray *)) GetProcAddress(h, "mxArrayToString");
            mxCreateCellMatrix = (mxArray* (*)(mwSize, mwSize)) GetProcAddress(h, "mxCreateCellMatrix");
            mxCreateCharMatrixFromStrings = (mxArray* (*)(mwSize, const char **)) GetProcAddress(h, "mxCreateCharMatrixFromStrings");
            mxCreateDoubleMatrix = (mxArray* (*)(mwSize, mwSize, mxComplexity)) GetProcAddress(h, "mxCreateDoubleMatrix");
            mxCreateDoubleScalar = (mxArray* (*)(double)) GetProcAddress(h, "mxCreateDoubleScalar");
            mxCreateLogicalMatrix = (mxArray* (*)(mwSize, mwSize)) GetProcAddress(h, "mxCreateLogicalMatrix");
            mxCreateLogicalScalar = (mxArray* (*)(bool)) GetProcAddress(h, "mxCreateLogicalScalar");
            mxCreateNumericArray = (mxArray* (*)(mwSize, const mwSize *, mxClassID, mxComplexity)) GetProcAddress(h, "mxCreateNumericArray");
            mxCreateNumericMatrix = (mxArray* (*)(mwSize, mwSize, mxClassID, mxComplexity)) GetProcAddress(h, "mxCreateNumericMatrix");
            mxCreateSparse = (mxArray* (*)(mwSize, mwSize, mwSize, mxComplexity)) GetProcAddress(h, "mxCreateSparse");
            mxCreateString = (mxArray* (*)(const char *)) GetProcAddress(h, "mxCreateString");
            mxCreateStructMatrix = (mxArray* (*)(mwSize, mwSize, int, const char **)) GetProcAddress(h, "mxCreateStructMatrix");
            mxDestroyArray = (void (*)(mxArray *)) GetProcAddress(h, "mxDestroyArray");
            mxGetCell = (mxArray* (*)(const mxArray *, mwIndex)) GetProcAddress(h, "mxGetCell");
            mxGetChars = (mxChar* (*)(const mxArray *)) GetProcAddress(h, "mxGetChars");
            mxGetClassID = (mxClassID (*)(const mxArray *)) GetProcAddress(h, "mxGetClassID");
            mxGetData = (void* (*)(const mxArray *)) GetProcAddress(h, "mxGetData");
            mxGetDimensions = (const mwSize* (*)(const mxArray *)) GetProcAddress(h, "mxGetDimensions");
            mxGetField = (mxArray* (*)(const mxArray *, mwIndex, const char *)) GetProcAddress(h, "mxGetField");
            mxGetFieldByNumber = (mxArray* (*)(const mxArray *, mwIndex, int)) GetProcAddress(h, "mxGetFieldByNumber");
            mxGetFieldNameByNumber = (const char* (*)(const mxArray *, int)) GetProcAddress(h, "mxGetFieldNameByNumber");
            mxGetIr = (mwIndex* (*)(const mxArray *)) GetProcAddress(h, "mxGetIr");
            mxGetJc = (mwIndex* (*)(const mxArray *)) GetProcAddress(h, "mxGetJc");
            mxGetN = (size_t (*)(const mxArray *)) GetProcAddress(h, "mxGetN");
            mxGetM = (size_t (*)(const mxArray *)) GetProcAddress(h, "mxGetM");
            mxGetNumberOfDimensions = (mwSize (*)(const mxArray *)) GetProcAddress(h, "mxGetNumberOfDimensions");
            mxGetNumberOfElements = (mwSize (*)(const mxArray *)) GetProcAddress(h, "mxGetNumberOfElements");
            mxGetNumberOfFields = (int (*)(const mxArray *)) GetProcAddress(h, "mxGetNumberOfFields");
            mxGetProperty = (mxArray* (*)(const mxArray *, const mwIndex, const char *)) GetProcAddress(h, "mxGetProperty");
            mxGetScalar = (double (*)(const mxArray *)) GetProcAddress(h, "mxGetScalar");
            mxGetString = (int (*)(const mxArray *, char *, mwSize)) GetProcAddress(h, "mxGetString");
            mxIsCell = (bool (*)(const mxArray *)) GetProcAddress(h, "mxIsCell");
            mxIsChar = (bool (*)(const mxArray *)) GetProcAddress(h, "mxIsChar");
            mxIsComplex = (bool (*)(const mxArray *)) GetProcAddress(h, "mxIsComplex");
            mxIsDouble = (bool (*)(const mxArray *)) GetProcAddress(h, "mxIsDouble");
            mxIsLogical = (bool (*)(const mxArray *)) GetProcAddress(h, "mxIsLogical");
            mxIsLogicalScalar = (bool (*)(const mxArray *)) GetProcAddress(h, "mxIsLogicalScalar");
            mxIsLogicalScalarTrue = (bool (*)(const mxArray *)) GetProcAddress(h, "mxIsLogicalScalarTrue");
            mxIsNumeric = (bool (*)(const mxArray *)) GetProcAddress(h, "mxIsNumeric");
            mxIsSparse = (bool (*)(const mxArray *)) GetProcAddress(h, "mxIsSparse");
            mxIsStruct = (bool (*)(const mxArray *)) GetProcAddress(h, "mxIsStruct");
            mxSetCell = (void (*)(mxArray *, mwIndex, mxArray *)) GetProcAddress(h, "mxSetCell");
            mxSetField = (void (*)(mxArray *, mwIndex, const char *, mxArray *)) GetProcAddress(h, "mxSetField");
            mxSetProperty = (void (*)(mxArray *, mwIndex, const char *, const mxArray *)) GetProcAddress(h, "mxSetProperty");
            mxSetFieldByNumber = (void (*)(mxArray *, mwIndex, int, mxArray *)) GetProcAddress(h, "mxSetFieldByNumber");
            mxCreateCharArray = (mxArray* (*)(mwSize, const mwSize *)) GetProcAddress(h, "mxCreateCharArray");
            mexCallMATLAB = (int (*)(int, mxArray *[], int, mxArray *[], const char *)) GetProcAddress(h, "mexCallMATLAB");
            mexCallMATLABWithTrap = (mxArray* (*)(int, mxArray *[], int, mxArray *[], const char *)) GetProcAddress(h, "mexCallMATLABWithTrap");
            mexErrMsgIdAndTxt = (void (*)(const char *, const char *, ...)) GetProcAddress(h, "mexErrMsgIdAndTxt");
            mexErrMsgTxt = (void (*)(const char *)) GetProcAddress(h, "mexErrMsgTxt");
            mexEvalString = (int (*)(const char *)) GetProcAddress(h, "mexEvalString");
            mexWarnMsgIdAndTxt = (void (*)(const char *, const char *, ...)) GetProcAddress(h, "mexWarnMsgIdAndTxt");
            mexPrintf = (int (*)(const char*, ...)) GetProcAddress(h, "mexPrintf");
            mexLock = (void (*)(void)) GetProcAddress(h, "mexLock");
            mexAtExit = (int (*)(void (*)(void))) GetProcAddress(h, "mexAtExit");
            return TRUE;
          }    
        }
      }
      return FALSE;
      break;
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        return TRUE;
  }
}

#else
int mxAddField(mxArray * a, const char * b) { return 0; }
char* mxArrayToString(const mxArray * a) { return 0; }
mxArray* mxCreateCellMatrix(mwSize a, mwSize b) { return 0; }
mxArray* mxCreateCharMatrixFromStrings(mwSize a, const char ** b) { return 0; }
mxArray* mxCreateDoubleMatrix(mwSize a, mwSize b, mxComplexity c) { return 0; }
mxArray* mxCreateDoubleScalar(double a) { return 0; }
mxArray* mxCreateLogicalMatrix(mwSize a, mwSize b) { return 0; }
mxArray* mxCreateLogicalScalar(bool a) { return 0; }
mxArray* mxCreateNumericArray(mwSize a, const mwSize * b, mxClassID c, mxComplexity d) { return 0; }
mxArray* mxCreateNumericMatrix(mwSize a, mwSize b, mxClassID c, mxComplexity d) { return 0; }
mxArray* mxCreateSparse(mwSize a, mwSize b, mwSize c, mxComplexity d) { return 0; }
mxArray* mxCreateString(const char * a) { return 0; }
mxArray* mxCreateStructMatrix(mwSize a, mwSize b, int c, const char ** d) { return 0; }
void mxDestroyArray(mxArray * a) {}
mxArray* mxGetCell(const mxArray * a, mwIndex b) { return 0; }
mxChar* mxGetChars(const mxArray * a) { return 0; }
mxClassID mxGetClassID(const mxArray * a) { return 0; }
void* mxGetData(const mxArray * a) {}
const mwSize* mxGetDimensions(const mxArray * a) { return 0; }
mxArray* mxGetField(const mxArray * a, mwIndex b, const char * c) { return 0; }
mxArray* mxGetFieldByNumber(const mxArray * a, mwIndex b, int c) { return 0; }
const char* mxGetFieldNameByNumber(const mxArray * a, int b) { return 0; }
mwIndex* mxGetIr(const mxArray * a) { return 0; }
mwIndex* mxGetJc(const mxArray * a) { return 0; }
size_t mxGetN(const mxArray * a) { return 0; }
size_t mxGetM(const mxArray * a) { return 0; }
mwSize mxGetNumberOfDimensions(const mxArray * a) { return 0; }
mwSize mxGetNumberOfElements(const mxArray * a) { return 0; }
int mxGetNumberOfFields(const mxArray * a) { return 0; }
mxArray* mxGetProperty(const mxArray * a, const mwIndex b, const char * c) { return 0; }
double mxGetScalar(const mxArray * a) { return 0; }
int mxGetString(const mxArray * a, char * b, mwSize c) { return 0; }
bool mxIsCell(const mxArray * a) { return 0; }
bool mxIsChar(const mxArray * a) { return 0; }
bool mxIsComplex(const mxArray * a) { return 0; }
bool mxIsDouble(const mxArray * a) { return 0; }
bool mxIsLogical(const mxArray * a) { return 0; }
bool mxIsLogicalScalar(const mxArray * a) { return 0; }
bool mxIsLogicalScalarTrue(const mxArray * a) { return 0; }
bool mxIsNumeric(const mxArray * a) { return 0; }
bool mxIsSparse(const mxArray * a) { return 0; }
bool mxIsStruct(const mxArray * a) { return 0; }
void mxSetCell(mxArray * a, mwIndex b, mxArray * c) {}
void mxSetField(mxArray * a, mwIndex b, const char * c, mxArray * d) {}
void mxSetProperty(mxArray * a, mwIndex b, const char * c, const mxArray * d) {}
void mxSetFieldByNumber(mxArray * a, mwIndex b, int c, mxArray * d) {}
mxArray* mxCreateCharArray(mwSize a, const mwSize * b) { return 0; }
int mexCallMATLAB(int a, mxArray * b[], int c, mxArray * d[], const char * e) { return 0; }
mxArray* mexCallMATLABWithTrap(int a, mxArray * b[], int c, mxArray * d[], const char * e) { return 0; }
void mexErrMsgIdAndTxt(const char * a, const char * b, ...) {}
void mexErrMsgTxt(const char * a) {}
int mexEvalString(const char * a) { return 0; }
void mexWarnMsgIdAndTxt(const char * a, const char * b, ...) {}
int mexPrintf(const char* a, ...) { return 0; }
void mexLock(void) {}
int mexAtExit(void (* a)(void)) { return 0; }

#endif // _WIN32
