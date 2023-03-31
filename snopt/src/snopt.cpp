#include "snopt_cwrap.h"

void snInitX(snProblem*, char*, char*, int, char*, int) {}
void snInit(snProblem*, char*, char*, int) {}

void snInitXW(snProblem*, char*, char*, int, char*, int, int*, int, double*, int) {}
void snInitW(snProblem*, char*, char*, int, int*, int, double*, int) {}

void init2zero(snProblem*) {}

void allocI(snProblem*, int) {}
void allocR(snProblem*, int) {}
void reallocI(snProblem*, int) {}
void reallocR(snProblem*, int) {}

void setPrintfile(snProblem*, char*) {}
int setSpecsfile(snProblem*, char*) { return 0; }

void setPrintfileX(snProblem*, char*, int) {}
int setSpecsfileX(snProblem*, char*, int) { return 0; }

int setParameter(snProblem*, char []) { return 0; }
int setIntParameter(snProblem*, char [], int) { return 0; }
int getIntParameter(snProblem*, char [], int*) { return 0; }
int setRealParameter(snProblem*, char [], double) { return 0; }
int getRealParameter(snProblem*, char [], double*) { return 0; }

void setUserI(snProblem*, int*, int) {}
void setUserR(snProblem*, double*, int) {}
void setUserspace(snProblem*, int*, int , double*, int) {}

void setWorkspace(snProblem*, int, int, int, int, int, int, int) {}
void setWorkspaceA(snProblem*, int, int, int, int) {}

int solveC(snProblem*, int, int, int, int, int, int, int, int, double,	snFunC, double*, int*, int*, double*, double*, int*, double*, double*, double*, double*, int*, int* , double*) { return 0; }

void deleteSNOPT(snProblem*) {}
