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

#ifdef _WIN32
#define mxAddField adaptor_mxAddField
int (*mxAddField)(mxArray *, const char *);
#define mxArrayToString adaptor_mxArrayToString
char* (*mxArrayToString)(const mxArray *);
#define mxCreateCellMatrix adaptor_mxCreateCellMatrix
mxArray* (*mxCreateCellMatrix)(mwSize, mwSize);
#define mxCreateCharMatrixFromStrings adaptor_mxCreateCharMatrixFromStrings
mxArray* (*mxCreateCharMatrixFromStrings)(mwSize, const char **);
#define mxCreateDoubleMatrix adaptor_mxCreateDoubleMatrix
mxArray* (*mxCreateDoubleMatrix)(mwSize, mwSize, mxComplexity);
#define mxCreateDoubleScalar adaptor_mxCreateDoubleScalar
mxArray* (*mxCreateDoubleScalar)(double);
#define mxCreateLogicalMatrix adaptor_mxCreateLogicalMatrix
mxArray* (*mxCreateLogicalMatrix)(mwSize, mwSize);
#define mxCreateLogicalScalar adaptor_mxCreateLogicalScalar
mxArray* (*mxCreateLogicalScalar)(bool);
#define mxCreateNumericArray adaptor_mxCreateNumericArray
mxArray* (*mxCreateNumericArray)(mwSize, const mwSize *, mxClassID, mxComplexity);
#define mxCreateNumericMatrix adaptor_mxCreateNumericMatrix
mxArray* (*mxCreateNumericMatrix)(mwSize, mwSize, mxClassID, mxComplexity);
#define mxCreateSparse adaptor_mxCreateSparse
mxArray* (*mxCreateSparse)(mwSize, mwSize, mwSize, mxComplexity);
#define mxCreateString adaptor_mxCreateString
mxArray* (*mxCreateString)(const char *);
#define mxCreateStructMatrix adaptor_mxCreateStructMatrix
mxArray* (*mxCreateStructMatrix)(mwSize, mwSize, int, const char **);
#define mxDestroyArray adaptor_mxDestroyArray
void (*mxDestroyArray)(mxArray *);
#define mxGetCell adaptor_mxGetCell
mxArray* (*mxGetCell)(const mxArray *, mwIndex);
#define mxGetChars adaptor_mxGetChars
mxChar* (*mxGetChars)(const mxArray *);
#define mxGetClassID adaptor_mxGetClassID
mxClassID (*mxGetClassID)(const mxArray *);
#define mxGetData adaptor_mxGetData
void* (*mxGetData)(const mxArray *);
#define mxGetDimensions adaptor_mxGetDimensions
const mwSize* (*mxGetDimensions)(const mxArray *);
#define mxGetField adaptor_mxGetField
mxArray* (*mxGetField)(const mxArray *, mwIndex, const char *);
#define mxGetFieldByNumber adaptor_mxGetFieldByNumber
mxArray* (*mxGetFieldByNumber)(const mxArray *, mwIndex, int);
#define mxGetFieldNameByNumber adaptor_mxGetFieldNameByNumber
const char* (*mxGetFieldNameByNumber)(const mxArray *, int);
#define mxGetIr adaptor_mxGetIr
mwIndex* (*mxGetIr)(const mxArray *);
#define mxGetJc adaptor_mxGetJc
mwIndex* (*mxGetJc)(const mxArray *);
#define mxGetN adaptor_mxGetN
size_t (*mxGetN)(const mxArray *);
#define mxGetM adaptor_mxGetM
size_t (*mxGetM)(const mxArray *);
#define mxGetNumberOfDimensions adaptor_mxGetNumberOfDimensions
mwSize (*mxGetNumberOfDimensions)(const mxArray *);
#define mxGetNumberOfElements adaptor_mxGetNumberOfElements
mwSize (*mxGetNumberOfElements)(const mxArray *);
#define mxGetNumberOfFields adaptor_mxGetNumberOfFields
int (*mxGetNumberOfFields)(const mxArray *);
#define mxGetProperty adaptor_mxGetProperty
mxArray* (*mxGetProperty)(const mxArray *, const mwIndex, const char *);
#define mxGetScalar adaptor_mxGetScalar
double (*mxGetScalar)(const mxArray *);
#define mxGetString adaptor_mxGetString
int (*mxGetString)(const mxArray *, char *, mwSize);
#define mxIsCell adaptor_mxIsCell
bool (*mxIsCell)(const mxArray *);
#define mxIsChar adaptor_mxIsChar
bool (*mxIsChar)(const mxArray *);
#define mxIsComplex adaptor_mxIsComplex
bool (*mxIsComplex)(const mxArray *);
#define mxIsDouble adaptor_mxIsDouble
bool (*mxIsDouble)(const mxArray *);
#define mxIsLogical adaptor_mxIsLogical
bool (*mxIsLogical)(const mxArray *);
#define mxIsLogicalScalar adaptor_mxIsLogicalScalar
bool (*mxIsLogicalScalar)(const mxArray *);
#define mxIsLogicalScalarTrue adaptor_mxIsLogicalScalarTrue
bool (*mxIsLogicalScalarTrue)(const mxArray *);
#define mxIsNumeric adaptor_mxIsNumeric
bool (*mxIsNumeric)(const mxArray *);
#define mxIsSparse adaptor_mxIsSparse
bool (*mxIsSparse)(const mxArray *);
#define mxIsStruct adaptor_mxIsStruct
bool (*mxIsStruct)(const mxArray *);
#define mxSetCell adaptor_mxSetCell
void (*mxSetCell)(mxArray *, mwIndex, mxArray *);
#define mxSetField adaptor_mxSetField
void (*mxSetField)(mxArray *, mwIndex, const char *, mxArray *);
#define mxSetProperty adaptor_mxSetProperty
void (*mxSetProperty)(mxArray *, mwIndex, const char *, const mxArray *);
#define mxSetFieldByNumber adaptor_mxSetFieldByNumber
void (*mxSetFieldByNumber)(mxArray *, mwIndex, int, mxArray *);
#define mxCreateCharArray adaptor_mxCreateCharArray
mxArray* (*mxCreateCharArray)(mwSize, const mwSize *);
#define mexCallMATLAB adaptor_mexCallMATLAB
int (*mexCallMATLAB)(int, mxArray *[], int, mxArray *[], const char *);
#define mexCallMATLABWithTrap adaptor_mexCallMATLABWithTrap
mxArray* (*mexCallMATLABWithTrap)(int, mxArray *[], int, mxArray *[], const char *);
#define mexErrMsgIdAndTxt adaptor_mexErrMsgIdAndTxt
void (*mexErrMsgIdAndTxt)(const char *, const char *, ...);
#define mexErrMsgTxt adaptor_mexErrMsgTxt
void (*mexErrMsgTxt)(const char *);
#define mexEvalString adaptor_mexEvalString
int (*mexEvalString)(const char *);
#define mexWarnMsgIdAndTxt adaptor_mexWarnMsgIdAndTxt
void (*mexWarnMsgIdAndTxt)(const char *, const char *, ...);
#define mexPrintf adaptor_mexPrintf
int (*mexPrintf)(const char*, ...);
#define mexLock adaptor_mexLock
void (*mexLock)(void);
#define mexAtExit adaptor_mexAtExit
int (*mexAtExit)(void (*)(void));
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
