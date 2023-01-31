

#ifdef _WIN32
#include <libloaderapi.h>
#include <stdio.h>

int (*adaptor_mxAddField)(mxArray *, const char *) = NULL;
char* (*adaptor_mxArrayToString)(const mxArray *) = NULL;
mxArray* (*adaptor_mxCreateCellMatrix)(mwSize, mwSize) = NULL;
mxArray* (*adaptor_mxCreateCharMatrixFromStrings)(mwSize, const char **) = NULL;
mxArray* (*adaptor_mxCreateDoubleMatrix)(mwSize, mwSize, mxComplexity) = NULL;
mxArray* (*adaptor_mxCreateDoubleScalar)(double) = NULL;
mxArray* (*adaptor_mxCreateLogicalMatrix)(mwSize, mwSize) = NULL;
mxArray* (*adaptor_mxCreateLogicalScalar)(bool) = NULL;
mxArray* (*adaptor_mxCreateNumericArray)(mwSize, const mwSize *, mxClassID, mxComplexity) = NULL;
mxArray* (*adaptor_mxCreateNumericMatrix)(mwSize, mwSize, mxClassID, mxComplexity) = NULL;
mxArray* (*adaptor_mxCreateSparse)(mwSize, mwSize, mwSize, mxComplexity) = NULL;
mxArray* (*adaptor_mxCreateString)(const char *) = NULL;
mxArray* (*adaptor_mxCreateStructMatrix)(mwSize, mwSize, int, const char **) = NULL;
void (*adaptor_mxDestroyArray)(mxArray *) = NULL;
mxArray* (*adaptor_mxGetCell)(const mxArray *, mwIndex) = NULL;
mxChar* (*adaptor_mxGetChars)(const mxArray *) = NULL;
mxClassID (*adaptor_mxGetClassID)(const mxArray *) = NULL;
void* (*adaptor_mxGetData)(const mxArray *) = NULL;
const mwSize* (*adaptor_mxGetDimensions)(const mxArray *) = NULL;
mxArray* (*adaptor_mxGetField)(const mxArray *, mwIndex, const char *) = NULL;
mxArray* (*adaptor_mxGetFieldByNumber)(const mxArray *, mwIndex, int) = NULL;
const char* (*adaptor_mxGetFieldNameByNumber)(const mxArray *, int) = NULL;
mwIndex* (*adaptor_mxGetIr)(const mxArray *) = NULL;
mwIndex* (*adaptor_mxGetJc)(const mxArray *) = NULL;
size_t (*adaptor_mxGetN)(const mxArray *) = NULL;
size_t (*adaptor_mxGetM)(const mxArray *) = NULL;
mwSize (*adaptor_mxGetNumberOfDimensions)(const mxArray *) = NULL;
mwSize (*adaptor_mxGetNumberOfElements)(const mxArray *) = NULL;
int (*adaptor_mxGetNumberOfFields)(const mxArray *) = NULL;
mxArray* (*adaptor_mxGetProperty)(const mxArray *, const mwIndex, const char *) = NULL;
double (*adaptor_mxGetScalar)(const mxArray *) = NULL;
int (*adaptor_mxGetString)(const mxArray *, char *, mwSize) = NULL;
bool (*adaptor_mxIsCell)(const mxArray *) = NULL;
bool (*adaptor_mxIsChar)(const mxArray *) = NULL;
bool (*adaptor_mxIsComplex)(const mxArray *) = NULL;
bool (*adaptor_mxIsDouble)(const mxArray *) = NULL;
bool (*adaptor_mxIsLogical)(const mxArray *) = NULL;
bool (*adaptor_mxIsLogicalScalar)(const mxArray *) = NULL;
bool (*adaptor_mxIsLogicalScalarTrue)(const mxArray *) = NULL;
bool (*adaptor_mxIsNumeric)(const mxArray *) = NULL;
bool (*adaptor_mxIsSparse)(const mxArray *) = NULL;
bool (*adaptor_mxIsStruct)(const mxArray *) = NULL;
void (*adaptor_mxSetCell)(mxArray *, mwIndex, mxArray *) = NULL;
void (*adaptor_mxSetField)(mxArray *, mwIndex, const char *, mxArray *) = NULL;
void (*adaptor_mxSetProperty)(mxArray *, mwIndex, const char *, const mxArray *) = NULL;
void (*adaptor_mxSetFieldByNumber)(mxArray *, mwIndex, int, mxArray *) = NULL;
mxArray* (*adaptor_mxCreateCharArray)(mwSize, const mwSize *) = NULL;
int (*adaptor_mexCallMATLAB)(int, mxArray *[], int, mxArray *[], const char *) = NULL;
mxArray* (*adaptor_mexCallMATLABWithTrap)(int, mxArray *[], int, mxArray *[], const char *) = NULL;
void (*adaptor_mexErrMsgIdAndTxt)(const char *, const char *, ...) = NULL;
void (*adaptor_mexErrMsgTxt)(const char *) = NULL;
int (*adaptor_mexEvalString)(const char *) = NULL;
void (*adaptor_mexWarnMsgIdAndTxt)(const char *, const char *, ...) = NULL;
int (*adaptor_mexPrintf)(const char*, ...) = NULL;
void (*adaptor_mexLock)(void) = NULL;
int (*adaptor_mexAtExit)(void (*)(void)) = NULL;

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
int mxAddField(mxArray *, const char *) { return 0; }
char* mxArrayToString(const mxArray *) { return 0; }
mxArray* mxCreateCellMatrix(mwSize, mwSize) { return 0; }
mxArray* mxCreateCharMatrixFromStrings(mwSize, const char **) { return 0; }
mxArray* mxCreateDoubleMatrix(mwSize, mwSize, mxComplexity) { return 0; }
mxArray* mxCreateDoubleScalar(double) { return 0; }
mxArray* mxCreateLogicalMatrix(mwSize, mwSize) { return 0; }
mxArray* mxCreateLogicalScalar(bool) { return 0; }
mxArray* mxCreateNumericArray(mwSize, const mwSize *, mxClassID, mxComplexity) { return 0; }
mxArray* mxCreateNumericMatrix(mwSize, mwSize, mxClassID, mxComplexity) { return 0; }
mxArray* mxCreateSparse(mwSize, mwSize, mwSize, mxComplexity) { return 0; }
mxArray* mxCreateString(const char *) { return 0; }
mxArray* mxCreateStructMatrix(mwSize, mwSize, int, const char **) { return 0; }
void mxDestroyArray(mxArray *) {}
mxArray* mxGetCell(const mxArray *, mwIndex) { return 0; }
mxChar* mxGetChars(const mxArray *) { return 0; }
mxClassID mxGetClassID(const mxArray *) { return 0; }
void* mxGetData(const mxArray *) {}
const mwSize* mxGetDimensions(const mxArray *) { return 0; }
mxArray* mxGetField(const mxArray *, mwIndex, const char *) { return 0; }
mxArray* mxGetFieldByNumber(const mxArray *, mwIndex, int) { return 0; }
const char* mxGetFieldNameByNumber(const mxArray *, int) { return 0; }
mwIndex* mxGetIr(const mxArray *) { return 0; }
mwIndex* mxGetJc(const mxArray *) { return 0; }
size_t mxGetN(const mxArray *) { return 0; }
size_t mxGetM(const mxArray *) { return 0; }
mwSize mxGetNumberOfDimensions(const mxArray *) { return 0; }
mwSize mxGetNumberOfElements(const mxArray *) { return 0; }
int mxGetNumberOfFields(const mxArray *) { return 0; }
mxArray* mxGetProperty(const mxArray *, const mwIndex, const char *) { return 0; }
double mxGetScalar(const mxArray *) { return 0; }
int mxGetString(const mxArray *, char *, mwSize) { return 0; }
bool mxIsCell(const mxArray *) { return 0; }
bool mxIsChar(const mxArray *) { return 0; }
bool mxIsComplex(const mxArray *) { return 0; }
bool mxIsDouble(const mxArray *) { return 0; }
bool mxIsLogical(const mxArray *) { return 0; }
bool mxIsLogicalScalar(const mxArray *) { return 0; }
bool mxIsLogicalScalarTrue(const mxArray *) { return 0; }
bool mxIsNumeric(const mxArray *) { return 0; }
bool mxIsSparse(const mxArray *) { return 0; }
bool mxIsStruct(const mxArray *) { return 0; }
void mxSetCell(mxArray *, mwIndex, mxArray *) {}
void mxSetField(mxArray *, mwIndex, const char *, mxArray *) {}
void mxSetProperty(mxArray *, mwIndex, const char *, const mxArray *) {}
void mxSetFieldByNumber(mxArray *, mwIndex, int, mxArray *) {}
mxArray* mxCreateCharArray(mwSize, const mwSize *) { return 0; }
int mexCallMATLAB(int, mxArray *[], int, mxArray *[], const char *) { return 0; }
mxArray* mexCallMATLABWithTrap(int, mxArray *[], int, mxArray *[], const char *) { return 0; }
void mexErrMsgIdAndTxt(const char *, const char *, ...) {}
void mexErrMsgTxt(const char *) {}
int mexEvalString(const char *) { return 0; }
void mexWarnMsgIdAndTxt(const char *, const char *, ...) {}
int mexPrintf(const char*, ...) { return 0; }
void mexLock(void) {}
int mexAtExit(void (*)(void)) { return 0; }

#endif // _WIN32
