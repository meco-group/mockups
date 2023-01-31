
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
          HMODULE h = getModuleHandle(buffer);
          if (h != NULL) {
            adaptor_mxAddField = GetProcAddress(h, "mxAddField");
            adaptor_mxArrayToString = GetProcAddress(h, "mxArrayToString");
            adaptor_mxCreateCellMatrix = GetProcAddress(h, "mxCreateCellMatrix");
            adaptor_mxCreateCharMatrixFromStrings = GetProcAddress(h, "mxCreateCharMatrixFromStrings");
            adaptor_mxCreateDoubleMatrix = GetProcAddress(h, "mxCreateDoubleMatrix");
            adaptor_mxCreateDoubleScalar = GetProcAddress(h, "mxCreateDoubleScalar");
            adaptor_mxCreateLogicalMatrix = GetProcAddress(h, "mxCreateLogicalMatrix");
            adaptor_mxCreateLogicalScalar = GetProcAddress(h, "mxCreateLogicalScalar");
            adaptor_mxCreateNumericArray = GetProcAddress(h, "mxCreateNumericArray");
            adaptor_mxCreateNumericMatrix = GetProcAddress(h, "mxCreateNumericMatrix");
            adaptor_mxCreateSparse = GetProcAddress(h, "mxCreateSparse");
            adaptor_mxCreateString = GetProcAddress(h, "mxCreateString");
            adaptor_mxCreateStructMatrix = GetProcAddress(h, "mxCreateStructMatrix");
            adaptor_mxDestroyArray = GetProcAddress(h, "mxDestroyArray");
            adaptor_mxGetCell = GetProcAddress(h, "mxGetCell");
            adaptor_mxGetChars = GetProcAddress(h, "mxGetChars");
            adaptor_mxGetClassID = GetProcAddress(h, "mxGetClassID");
            adaptor_mxGetData = GetProcAddress(h, "mxGetData");
            adaptor_mxGetDimensions = GetProcAddress(h, "mxGetDimensions");
            adaptor_mxGetField = GetProcAddress(h, "mxGetField");
            adaptor_mxGetFieldByNumber = GetProcAddress(h, "mxGetFieldByNumber");
            adaptor_mxGetFieldNameByNumber = GetProcAddress(h, "mxGetFieldNameByNumber");
            adaptor_mxGetIr = GetProcAddress(h, "mxGetIr");
            adaptor_mxGetJc = GetProcAddress(h, "mxGetJc");
            adaptor_mxGetN = GetProcAddress(h, "mxGetN");
            adaptor_mxGetM = GetProcAddress(h, "mxGetM");
            adaptor_mxGetNumberOfDimensions = GetProcAddress(h, "mxGetNumberOfDimensions");
            adaptor_mxGetNumberOfElements = GetProcAddress(h, "mxGetNumberOfElements");
            adaptor_mxGetNumberOfFields = GetProcAddress(h, "mxGetNumberOfFields");
            adaptor_mxGetProperty = GetProcAddress(h, "mxGetProperty");
            adaptor_mxGetScalar = GetProcAddress(h, "mxGetScalar");
            adaptor_mxGetString = GetProcAddress(h, "mxGetString");
            adaptor_mxIsCell = GetProcAddress(h, "mxIsCell");
            adaptor_mxIsChar = GetProcAddress(h, "mxIsChar");
            adaptor_mxIsComplex = GetProcAddress(h, "mxIsComplex");
            adaptor_mxIsDouble = GetProcAddress(h, "mxIsDouble");
            adaptor_mxIsLogical = GetProcAddress(h, "mxIsLogical");
            adaptor_mxIsLogicalScalar = GetProcAddress(h, "mxIsLogicalScalar");
            adaptor_mxIsLogicalScalarTrue = GetProcAddress(h, "mxIsLogicalScalarTrue");
            adaptor_mxIsNumeric = GetProcAddress(h, "mxIsNumeric");
            adaptor_mxIsSparse = GetProcAddress(h, "mxIsSparse");
            adaptor_mxIsStruct = GetProcAddress(h, "mxIsStruct");
            adaptor_mxSetCell = GetProcAddress(h, "mxSetCell");
            adaptor_mxSetField = GetProcAddress(h, "mxSetField");
            adaptor_mxSetProperty = GetProcAddress(h, "mxSetProperty");
            adaptor_mxSetFieldByNumber = GetProcAddress(h, "mxSetFieldByNumber");
            adaptor_mxCreateCharArray = GetProcAddress(h, "mxCreateCharArray");
            adaptor_mexCallMATLAB = GetProcAddress(h, "mexCallMATLAB");
            adaptor_mexCallMATLABWithTrap = GetProcAddress(h, "mexCallMATLABWithTrap");
            adaptor_mexErrMsgIdAndTxt = GetProcAddress(h, "mexErrMsgIdAndTxt");
            adaptor_mexErrMsgTxt = GetProcAddress(h, "mexErrMsgTxt");
            adaptor_mexEvalString = GetProcAddress(h, "mexEvalString");
            adaptor_mexWarnMsgIdAndTxt = GetProcAddress(h, "mexWarnMsgIdAndTxt");
            adaptor_mexPrintf = GetProcAddress(h, "mexPrintf");
            adaptor_mexLock = GetProcAddress(h, "mexLock");
            adaptor_mexAtExit = GetProcAddress(h, "mexAtExit");
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
int mexCallMATLAB(int a, mxArray *[] b, int c, mxArray *[] d, const char * e) { return 0; }
mxArray* mexCallMATLABWithTrap(int a, mxArray *[] b, int c, mxArray *[] d, const char * e) { return 0; }
void mexErrMsgIdAndTxt(const char * a, const char * b, ...) {}
void mexErrMsgTxt(const char * a) {}
int mexEvalString(const char * a) { return 0; }
void mexWarnMsgIdAndTxt(const char * a, const char * b, ...) {}
int mexPrintf(const char* a, ...) { return 0; }
void mexLock(void) {}
int mexAtExit(void (*)(void) a) { return 0; }

#endif // _WIN32
