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

#endif // matrix_H
