#include "mex.h"

int mxAddField(mxArray *, const char *) { return 0; }
char *mxArrayToString(const mxArray *) { return 0; }
mxArray *mxCreateCellMatrix(mwSize, mwSize) { return 0; }
mxArray *mxCreateCharMatrixFromStrings(mwSize, const char **) { return 0; }
mxArray *mxCreateDoubleMatrix(mwSize, mwSize, mxComplexity) { return 0; }
mxArray *mxCreateDoubleScalar(double) { return 0; }
mxArray *mxCreateLogicalMatrix(mwSize, mwSize) { return 0; }
mxArray *mxCreateLogicalScalar(bool) { return 0; }
mxArray *mxCreateNumericArray(mwSize, const mwSize *, mxClassID, mxComplexity) { return 0; }
mxArray *mxCreateNumericMatrix(mwSize, mwSize, mxClassID, mxComplexity) { return 0; }
mxArray *mxCreateSparse(mwSize, mwSize, mwSize, mxComplexity) { return 0; }
mxArray *mxCreateString(const char *) { return 0; }
mxArray *mxCreateStructMatrix(mwSize, mwSize, int, const char **) { return 0; }
void mxDestroyArray(mxArray *) { }
mxArray *mxGetCell(const mxArray *, mwIndex) { return 0; }
mxChar *mxGetChars(const mxArray *) { return 0; }
mxClassID mxGetClassID(const mxArray *) { return 0; }
void *mxGetData(const mxArray *) { }
const mwSize *mxGetDimensions(const mxArray *) { return 0; }
mxArray *mxGetField(const mxArray *, mwIndex, const char *) { return 0; }
mxArray *mxGetFieldByNumber(const mxArray *, mwIndex, int) { return 0; }
const char *mxGetFieldNameByNumber(const mxArray *, int) { return 0; }
mwIndex *mxGetIr(const mxArray *) { return 0; }
mwIndex *mxGetJc(const mxArray *) { return 0; }
size_t mxGetN(const mxArray *) { return 0; }
size_t mxGetM(const mxArray *) { return 0; }
mwSize mxGetNumberOfDimensions(const mxArray *) { return 0; }
mwSize mxGetNumberOfElements(const mxArray *) { return 0; }
int mxGetNumberOfFields(const mxArray *) { return 0; }
mxArray * mxGetProperty(const mxArray *, const mwIndex, const char *) { return 0; }
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
void mxSetCell(mxArray *, mwIndex, mxArray *) { }
void mxSetField(mxArray *, mwIndex, const char *, mxArray *) { }
void mxSetProperty(mxArray *, mwIndex, const char *, const mxArray *) { }
void mxSetFieldByNumber(mxArray *, mwIndex, int, mxArray *) {  }
mxArray *mxCreateCharArray(mwSize, const mwSize *) { }
