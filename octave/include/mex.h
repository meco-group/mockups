#ifndef mex_H
#define mex_H


#ifdef __cplusplus
extern "C"
{
#endif

  typedef struct mxArray_tag mxArray;



#include <stdint.h>

#define int8_T int8_t
#define uint8_T uint8_t
#define int16_T int16_t
#define uint16_T uint16_t
#define int32_T int32_t
#define uint32_T uint32_t
#define int64_T int64_t
#define uint64_T uint64_t

#include <stdlib.h>
#include <stddef.h>
typedef int64_t mwSize;
typedef int64_t mwIndex;
typedef enum { mxREAL, mxCOMPLEX } mxComplexity;

typedef enum {
    mxUNKNOWN_CLASS = 0,
    mxCELL_CLASS,
    mxSTRUCT_CLASS,
    mxLOGICAL_CLASS,
    mxCHAR_CLASS,
    mxVOID_CLASS,
    mxDOUBLE_CLASS,
    mxSINGLE_CLASS,
    mxINT8_CLASS,
    mxUINT8_CLASS,
    mxINT16_CLASS,
    mxUINT16_CLASS,
    mxINT32_CLASS,
    mxUINT32_CLASS,
    mxINT64_CLASS,
    mxUINT64_CLASS,
    mxFUNCTION_CLASS,
    mxOPAQUE_CLASS,
    mxOBJECT_CLASS
} mxClassID;

typedef unsigned char bool;
typedef bool mxLogical;
typedef char mxChar;

#ifdef DLL_IMPLEMENTATION
#define DLLSYMBOL __declspec( dllexport )
#else
#define DLLSYMBOL __declspec( dllimport )
#endif

#ifdef _WIN32
#define mxAddField adaptor_mxAddField
DLLSYMBOL int (*mxAddField)(mxArray *, const char *);
#define mxArrayToString adaptor_mxArrayToString
DLLSYMBOL char* (*mxArrayToString)(const mxArray *);
#define mxCreateCellMatrix adaptor_mxCreateCellMatrix
DLLSYMBOL mxArray* (*mxCreateCellMatrix)(mwSize, mwSize);
#define mxCreateCharMatrixFromStrings adaptor_mxCreateCharMatrixFromStrings
DLLSYMBOL mxArray* (*mxCreateCharMatrixFromStrings)(mwSize, const char **);
#define mxCreateDoubleMatrix adaptor_mxCreateDoubleMatrix
DLLSYMBOL mxArray* (*mxCreateDoubleMatrix)(mwSize, mwSize, mxComplexity);
#define mxCreateDoubleScalar adaptor_mxCreateDoubleScalar
DLLSYMBOL mxArray* (*mxCreateDoubleScalar)(double);
#define mxCreateLogicalMatrix adaptor_mxCreateLogicalMatrix
DLLSYMBOL mxArray* (*mxCreateLogicalMatrix)(mwSize, mwSize);
#define mxCreateLogicalScalar adaptor_mxCreateLogicalScalar
DLLSYMBOL mxArray* (*mxCreateLogicalScalar)(bool);
#define mxCreateNumericArray adaptor_mxCreateNumericArray
DLLSYMBOL mxArray* (*mxCreateNumericArray)(mwSize, const mwSize *, mxClassID, mxComplexity);
#define mxCreateNumericMatrix adaptor_mxCreateNumericMatrix
DLLSYMBOL mxArray* (*mxCreateNumericMatrix)(mwSize, mwSize, mxClassID, mxComplexity);
#define mxCreateSparse adaptor_mxCreateSparse
DLLSYMBOL mxArray* (*mxCreateSparse)(mwSize, mwSize, mwSize, mxComplexity);
#define mxCreateString adaptor_mxCreateString
DLLSYMBOL mxArray* (*mxCreateString)(const char *);
#define mxCreateStructMatrix adaptor_mxCreateStructMatrix
DLLSYMBOL mxArray* (*mxCreateStructMatrix)(mwSize, mwSize, int, const char **);
#define mxDestroyArray adaptor_mxDestroyArray
DLLSYMBOL void (*mxDestroyArray)(mxArray *);
#define mxGetCell adaptor_mxGetCell
DLLSYMBOL mxArray* (*mxGetCell)(const mxArray *, mwIndex);
#define mxGetChars adaptor_mxGetChars
DLLSYMBOL mxChar* (*mxGetChars)(const mxArray *);
#define mxGetClassID adaptor_mxGetClassID
DLLSYMBOL mxClassID (*mxGetClassID)(const mxArray *);
#define mxGetData adaptor_mxGetData
DLLSYMBOL void* (*mxGetData)(const mxArray *);
#define mxGetDimensions adaptor_mxGetDimensions
DLLSYMBOL const mwSize* (*mxGetDimensions)(const mxArray *);
#define mxGetField adaptor_mxGetField
DLLSYMBOL mxArray* (*mxGetField)(const mxArray *, mwIndex, const char *);
#define mxGetFieldByNumber adaptor_mxGetFieldByNumber
DLLSYMBOL mxArray* (*mxGetFieldByNumber)(const mxArray *, mwIndex, int);
#define mxGetFieldNameByNumber adaptor_mxGetFieldNameByNumber
DLLSYMBOL const char* (*mxGetFieldNameByNumber)(const mxArray *, int);
#define mxGetIr adaptor_mxGetIr
DLLSYMBOL mwIndex* (*mxGetIr)(const mxArray *);
#define mxGetJc adaptor_mxGetJc
DLLSYMBOL mwIndex* (*mxGetJc)(const mxArray *);
#define mxGetN adaptor_mxGetN
DLLSYMBOL size_t (*mxGetN)(const mxArray *);
#define mxGetM adaptor_mxGetM
DLLSYMBOL size_t (*mxGetM)(const mxArray *);
#define mxGetNumberOfDimensions adaptor_mxGetNumberOfDimensions
DLLSYMBOL mwSize (*mxGetNumberOfDimensions)(const mxArray *);
#define mxGetNumberOfElements adaptor_mxGetNumberOfElements
DLLSYMBOL mwSize (*mxGetNumberOfElements)(const mxArray *);
#define mxGetNumberOfFields adaptor_mxGetNumberOfFields
DLLSYMBOL int (*mxGetNumberOfFields)(const mxArray *);
#define mxGetProperty adaptor_mxGetProperty
DLLSYMBOL mxArray* (*mxGetProperty)(const mxArray *, const mwIndex, const char *);
#define mxGetScalar adaptor_mxGetScalar
DLLSYMBOL double (*mxGetScalar)(const mxArray *);
#define mxGetString adaptor_mxGetString
DLLSYMBOL int (*mxGetString)(const mxArray *, char *, mwSize);
#define mxIsCell adaptor_mxIsCell
DLLSYMBOL bool (*mxIsCell)(const mxArray *);
#define mxIsChar adaptor_mxIsChar
DLLSYMBOL bool (*mxIsChar)(const mxArray *);
#define mxIsComplex adaptor_mxIsComplex
DLLSYMBOL bool (*mxIsComplex)(const mxArray *);
#define mxIsDouble adaptor_mxIsDouble
DLLSYMBOL bool (*mxIsDouble)(const mxArray *);
#define mxIsLogical adaptor_mxIsLogical
DLLSYMBOL bool (*mxIsLogical)(const mxArray *);
#define mxIsLogicalScalar adaptor_mxIsLogicalScalar
DLLSYMBOL bool (*mxIsLogicalScalar)(const mxArray *);
#define mxIsLogicalScalarTrue adaptor_mxIsLogicalScalarTrue
DLLSYMBOL bool (*mxIsLogicalScalarTrue)(const mxArray *);
#define mxIsNumeric adaptor_mxIsNumeric
DLLSYMBOL bool (*mxIsNumeric)(const mxArray *);
#define mxIsSparse adaptor_mxIsSparse
DLLSYMBOL bool (*mxIsSparse)(const mxArray *);
#define mxIsStruct adaptor_mxIsStruct
DLLSYMBOL bool (*mxIsStruct)(const mxArray *);
#define mxSetCell adaptor_mxSetCell
DLLSYMBOL void (*mxSetCell)(mxArray *, mwIndex, mxArray *);
#define mxSetField adaptor_mxSetField
DLLSYMBOL void (*mxSetField)(mxArray *, mwIndex, const char *, mxArray *);
#define mxSetProperty adaptor_mxSetProperty
DLLSYMBOL void (*mxSetProperty)(mxArray *, mwIndex, const char *, const mxArray *);
#define mxSetFieldByNumber adaptor_mxSetFieldByNumber
DLLSYMBOL void (*mxSetFieldByNumber)(mxArray *, mwIndex, int, mxArray *);
#define mxCreateCharArray adaptor_mxCreateCharArray
DLLSYMBOL mxArray* (*mxCreateCharArray)(mwSize, const mwSize *);
#define mexCallMATLAB adaptor_mexCallMATLAB
DLLSYMBOL int (*mexCallMATLAB)(int, mxArray *[], int, mxArray *[], const char *);
#define mexCallMATLABWithTrap adaptor_mexCallMATLABWithTrap
DLLSYMBOL mxArray* (*mexCallMATLABWithTrap)(int, mxArray *[], int, mxArray *[], const char *);
#define mexErrMsgIdAndTxt adaptor_mexErrMsgIdAndTxt
DLLSYMBOL void (*mexErrMsgIdAndTxt)(const char *, const char *, ...);
#define mexErrMsgTxt adaptor_mexErrMsgTxt
DLLSYMBOL void (*mexErrMsgTxt)(const char *);
#define mexEvalString adaptor_mexEvalString
DLLSYMBOL int (*mexEvalString)(const char *);
#define mexWarnMsgIdAndTxt adaptor_mexWarnMsgIdAndTxt
DLLSYMBOL void (*mexWarnMsgIdAndTxt)(const char *, const char *, ...);
#define mexPrintf adaptor_mexPrintf
DLLSYMBOL int (*mexPrintf)(const char*, ...);
#define mexLock adaptor_mexLock
DLLSYMBOL void (*mexLock)(void);
#define mexAtExit adaptor_mexAtExit
DLLSYMBOL int (*mexAtExit)(void (*)(void));
#else
int mxAddField(mxArray *, const char *);
char* mxArrayToString(const mxArray *);
mxArray* mxCreateCellMatrix(mwSize, mwSize);
mxArray* mxCreateCharMatrixFromStrings(mwSize, const char **);
mxArray* mxCreateDoubleMatrix(mwSize, mwSize, mxComplexity);
mxArray* mxCreateDoubleScalar(double);
mxArray* mxCreateLogicalMatrix(mwSize, mwSize);
mxArray* mxCreateLogicalScalar(bool);
mxArray* mxCreateNumericArray(mwSize, const mwSize *, mxClassID, mxComplexity);
mxArray* mxCreateNumericMatrix(mwSize, mwSize, mxClassID, mxComplexity);
mxArray* mxCreateSparse(mwSize, mwSize, mwSize, mxComplexity);
mxArray* mxCreateString(const char *);
mxArray* mxCreateStructMatrix(mwSize, mwSize, int, const char **);
void mxDestroyArray(mxArray *);
mxArray* mxGetCell(const mxArray *, mwIndex);
mxChar* mxGetChars(const mxArray *);
mxClassID mxGetClassID(const mxArray *);
void* mxGetData(const mxArray *);
const mwSize* mxGetDimensions(const mxArray *);
mxArray* mxGetField(const mxArray *, mwIndex, const char *);
mxArray* mxGetFieldByNumber(const mxArray *, mwIndex, int);
const char* mxGetFieldNameByNumber(const mxArray *, int);
mwIndex* mxGetIr(const mxArray *);
mwIndex* mxGetJc(const mxArray *);
size_t mxGetN(const mxArray *);
size_t mxGetM(const mxArray *);
mwSize mxGetNumberOfDimensions(const mxArray *);
mwSize mxGetNumberOfElements(const mxArray *);
int mxGetNumberOfFields(const mxArray *);
mxArray* mxGetProperty(const mxArray *, const mwIndex, const char *);
double mxGetScalar(const mxArray *);
int mxGetString(const mxArray *, char *, mwSize);
bool mxIsCell(const mxArray *);
bool mxIsChar(const mxArray *);
bool mxIsComplex(const mxArray *);
bool mxIsDouble(const mxArray *);
bool mxIsLogical(const mxArray *);
bool mxIsLogicalScalar(const mxArray *);
bool mxIsLogicalScalarTrue(const mxArray *);
bool mxIsNumeric(const mxArray *);
bool mxIsSparse(const mxArray *);
bool mxIsStruct(const mxArray *);
void mxSetCell(mxArray *, mwIndex, mxArray *);
void mxSetField(mxArray *, mwIndex, const char *, mxArray *);
void mxSetProperty(mxArray *, mwIndex, const char *, const mxArray *);
void mxSetFieldByNumber(mxArray *, mwIndex, int, mxArray *);
mxArray* mxCreateCharArray(mwSize, const mwSize *);
int mexCallMATLAB(int, mxArray *[], int, mxArray *[], const char *);
mxArray* mexCallMATLABWithTrap(int, mxArray *[], int, mxArray *[], const char *);
void mexErrMsgIdAndTxt(const char *, const char *, ...);
void mexErrMsgTxt(const char *);
int mexEvalString(const char *);
void mexWarnMsgIdAndTxt(const char *, const char *, ...);
int mexPrintf(const char*, ...);
void mexLock(void);
int mexAtExit(void (*)(void));
#endif // _WIN32

#ifdef __cplusplus
}
#endif

#endif // mex_H
