#ifndef SNOPT_H__
#define SNOPT_H__


#ifdef __cplusplus
extern "C" {
#endif

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

typedef struct snProblem_internal snProblem;

typedef void (*snFunC)(int*, int*, int*, int*, int*, int*, double [], double*,  double [], double [], double [], int*,char   [], int*, int[], int*, double [], int*);

void snInitX(snProblem*, char*, char*, int, char*, int);
void snInit(snProblem*, char*, char*, int);

void snInitXW(snProblem*, char*, char*, int, char*, int, int*, int, double*, int);
void snInitW(snProblem*, char*, char*, int, int*, int, double*, int);

void init2zero(snProblem*);

void allocI(snProblem*, int);
void allocR(snProblem*, int);
void reallocI(snProblem*, int);
void reallocR(snProblem*, int);

void setPrintfile(snProblem*, char*);
int setSpecsfile(snProblem*, char*);

void setPrintfileX(snProblem*, char*, int);
int setSpecsfileX(snProblem*, char*, int);

int setParameter(snProblem*, char []);
int setIntParameter(snProblem*, char [], int);
int getIntParameter(snProblem*, char [], int*);
int setRealParameter(snProblem*, char [], double);
int getRealParameter(snProblem*, char [], double*);

void setUserI(snProblem*, int*, int);
void setUserR(snProblem*, double*, int);
void setUserspace(snProblem*, int*, int , double*, int);

void setWorkspace(snProblem*, int, int, int, int, int, int, int);
void setWorkspaceA(snProblem*, int, int, int, int);

int solveC(snProblem*, int, int, int, int, int, int, int, int, double,	snFunC, double*, int*, int*, double*, double*, int*, double*, double*, double*, double*, int*, int* , double*);

void deleteSNOPT(snProblem*);

#ifdef __cplusplus
}
#endif

#endif // SNOPT_H__
