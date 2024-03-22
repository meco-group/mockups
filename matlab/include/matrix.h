#ifndef matrix_H
#define matrix_H


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
typedef size_t mwSize;
typedef size_t mwIndex;
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

typedef bool mxLogical;
typedef char16_t mxChar;

#include <matrix_versions.h>

// methods
int mx_Export mxAddField(mxArray *, const char *);
char* mx_Export mxArrayToString(const mxArray *);
mxArray* mx_Export mxCreateCellMatrix(mwSize, mwSize);
mxArray* mx_Export mxCreateCharMatrixFromStrings(mwSize, const char **);
mxArray* mx_Export mxCreateDoubleMatrix(mwSize, mwSize, mxComplexity);
mxArray* mx_Export mxCreateDoubleScalar(double);
mxArray* mx_Export mxCreateLogicalMatrix(mwSize, mwSize);
mxArray* mx_Export mxCreateLogicalScalar(bool);
mxArray* mx_Export mxCreateNumericArray(mwSize, const mwSize *, mxClassID, mxComplexity);
mxArray* mx_Export mxCreateNumericMatrix(mwSize, mwSize, mxClassID, mxComplexity);
mxArray* mx_Export mxCreateSparse(mwSize, mwSize, mwSize, mxComplexity);
mxArray* mx_Export mxCreateString(const char *);
mxArray* mx_Export mxCreateStructMatrix(mwSize, mwSize, int, const char **);
void mx_Export mxDestroyArray(mxArray *);
mxArray* mx_Export mxGetCell(const mxArray *, mwIndex);
mxChar* mx_Export mxGetChars(const mxArray *);
mxClassID mx_Export mxGetClassID(const mxArray *);
void* mx_Export mxGetData(const mxArray *);
const mwSize* mx_Export mxGetDimensions(const mxArray *);
mxArray* mx_Export mxGetField(const mxArray *, mwIndex, const char *);
mxArray* mx_Export mxGetFieldByNumber(const mxArray *, mwIndex, int);
const char* mx_Export mxGetFieldNameByNumber(const mxArray *, int);
mwIndex* mx_Export mxGetIr(const mxArray *);
mwIndex* mx_Export mxGetJc(const mxArray *);
size_t mx_Export mxGetN(const mxArray *);
size_t mx_Export mxGetM(const mxArray *);
mwSize mx_Export mxGetNumberOfDimensions(const mxArray *);
mwSize mx_Export mxGetNumberOfElements(const mxArray *);
int mx_Export mxGetNumberOfFields(const mxArray *);
mxArray* mx_Export mxGetProperty(const mxArray *, const mwIndex, const char *);
double mx_Export mxGetScalar(const mxArray *);
int mx_Export mxGetString(const mxArray *, char *, mwSize);
bool mx_Export mxIsCell(const mxArray *);
bool mx_Export mxIsChar(const mxArray *);
bool mx_Export mxIsComplex(const mxArray *);
bool mx_Export mxIsDouble(const mxArray *);
bool mx_Export mxIsLogical(const mxArray *);
bool mx_Export mxIsLogicalScalar(const mxArray *);
bool mx_Export mxIsLogicalScalarTrue(const mxArray *);
bool mx_Export mxIsNumeric(const mxArray *);
bool mx_Export mxIsSparse(const mxArray *);
bool mx_Export mxIsStruct(const mxArray *);
void mx_Export mxSetCell(mxArray *, mwIndex, mxArray *);
void mx_Export mxSetField(mxArray *, mwIndex, const char *, mxArray *);
void mx_Export mxSetProperty(mxArray *, mwIndex, const char *, const mxArray *);
void mx_Export mxSetFieldByNumber(mxArray *, mwIndex, int, mxArray *);
mxArray* mx_Export mxCreateCharArray(mwSize, const mwSize *);
mxArray mex_Export *mxDuplicateArray(const mxArray *);

#endif // matrix_H
