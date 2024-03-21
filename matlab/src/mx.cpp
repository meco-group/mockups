#include "mex.h"

int mx_Export mxAddField(mxArray *, const char *) { return 0; }
char mx_Export *mxArrayToString(const mxArray *) { return 0; }
mxArray mx_Export *mxCreateCellMatrix(mwSize, mwSize) { return 0; }
mxArray mx_Export *mxCreateCharMatrixFromStrings(mwSize, const char **) { return 0; }
mxArray mx_Export *mxCreateDoubleMatrix(mwSize, mwSize, mxComplexity) { return 0; }
mxArray mx_Export *mxCreateDoubleScalar(double) { return 0; }
mxArray mx_Export *mxCreateLogicalMatrix(mwSize, mwSize) { return 0; }
mxArray mx_Export *mxCreateLogicalScalar(bool) { return 0; }
mxArray mx_Export *mxCreateNumericArray(mwSize, const mwSize *, mxClassID, mxComplexity) { return 0; }
mxArray mx_Export *mxCreateNumericMatrix(mwSize, mwSize, mxClassID, mxComplexity) { return 0; }
mxArray mx_Export *mxCreateSparse(mwSize, mwSize, mwSize, mxComplexity) { return 0; }
mxArray mx_Export *mxCreateString(const char *) { return 0; }
mxArray mx_Export *mxCreateStructMatrix(mwSize, mwSize, int, const char **) { return 0; }
void mx_Export mxDestroyArray(mxArray *) { }
mxArray mx_Export *mxGetCell(const mxArray *, mwIndex) { return 0; }
mxChar mx_Export *mxGetChars(const mxArray *) { return 0; }
mxClassID mx_Export mxGetClassID(const mxArray *) { return mxUNKNOWN_CLASS; }
void mx_Export *mxGetData(const mxArray *) { return 0; }
const mwSize mx_Export *mxGetDimensions(const mxArray *) { return 0; }
mxArray mx_Export *mxGetField(const mxArray *, mwIndex, const char *) { return 0; }
mxArray mx_Export *mxGetFieldByNumber(const mxArray *, mwIndex, int) { return 0; }
const char mx_Export *mxGetFieldNameByNumber(const mxArray *, int) { return 0; }
mwIndex mx_Export *mxGetIr(const mxArray *) { return 0; }
mwIndex mx_Export *mxGetJc(const mxArray *) { return 0; }
size_t mx_Export mxGetN(const mxArray *) { return 0; }
size_t mx_Export mxGetM(const mxArray *) { return 0; }
mwSize mx_Export mxGetNumberOfDimensions(const mxArray *) { return 0; }
mwSize mx_Export mxGetNumberOfElements(const mxArray *) { return 0; }
int mx_Export mxGetNumberOfFields(const mxArray *) { return 0; }
mxArray * mx_Export mxGetProperty(const mxArray *, const mwIndex, const char *) { return 0; }
double mx_Export mxGetScalar(const mxArray *) { return 0; }
int mx_Export mxGetString(const mxArray *, char *, mwSize) { return 0; }
bool mx_Export mxIsCell(const mxArray *) { return 0; }
bool mx_Export mxIsChar(const mxArray *) { return 0; }
bool mx_Export mxIsComplex(const mxArray *) { return 0; }
bool mx_Export mxIsDouble(const mxArray *) { return 0; }
bool mx_Export mxIsLogical(const mxArray *) { return 0; }
bool mx_Export mxIsLogicalScalar(const mxArray *) { return 0; }
bool mx_Export mxIsLogicalScalarTrue(const mxArray *) { return 0; }
bool mx_Export mxIsNumeric(const mxArray *) { return 0; }
bool mx_Export mxIsSparse(const mxArray *) { return 0; }
bool mx_Export mxIsStruct(const mxArray *) { return 0; }
void mx_Export mxSetCell(mxArray *, mwIndex, mxArray *) { }
void mx_Export mxSetField(mxArray *, mwIndex, const char *, mxArray *) { }
void mx_Export mxSetProperty(mxArray *, mwIndex, const char *, const mxArray *) { }
void mx_Export mxSetFieldByNumber(mxArray *, mwIndex, int, mxArray *) {  }
mxArray mx_Export *mxCreateCharArray(mwSize, const mwSize *) { return 0; }