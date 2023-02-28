#ifndef WORHP_H__
#define WORHP_H__

#ifdef __cplusplus
extern "C" {
#endif

#if !defined(_MSC_VER) || (_MSC_VER >= 1800)
#include <stdbool.h>
#endif

#include <stdlib.h>

enum {
  WorhpMatrix_Name_Length = 10
};

typedef int mat_int;
typedef int rwmt_index;
typedef int iwmt_index;
typedef int counter;

typedef struct WorhpMatrix {
  double* val;
  mat_int* row;
  mat_int* col;
  mat_int* slc;
  mat_int* CCrow;
  mat_int* CCcol;
  mat_int* CCper;
  mat_int* nGroups;
  mat_int* Groups;
  mat_int* nSubGroups;
  mat_int* SubGroups;
  mat_int* perm;

  mat_int dim_val;
  mat_int dim_row;
  mat_int dim_col;
  mat_int dim_slc;
  mat_int dim_CCrow;
  mat_int dim_CCcol;
  mat_int dim_CCper;
  mat_int dim_nGroups;
  mat_int dim_Groups;
  mat_int dim_nSubGroups;
  mat_int dim_SubGroups;
  mat_int dim_perm;

  mat_int nnz;
  mat_int nnzDefault;
  mat_int nRow;
  mat_int nRowDefault;
  mat_int nCol;
  mat_int nColDefault;

  mat_int nGrp;

  int kind;

  char name[WorhpMatrix_Name_Length];
  bool NeedStructure;
  bool Dense;
} WorhpMatrix;

typedef struct {
  double start;
  double total;
  int status;
  int _shim;
} TimerType;

typedef struct {
  int year;
  int month;
  int day;
  int hour;
  int minute;
  int second;
} DateType;

struct FltNode{
  double anon0;
  double anon1;
  bool anon2;
  struct FltNode *anon3;
  struct FltNode *anon4;
};

enum {
  WorhpQueueSize = 10
};

typedef struct WorhpQueueStruct {
  double val[WorhpQueueSize];
  int idx;
} WorhpQueue;

typedef struct FltNode FilterNode;

enum {
  WMTslices = 100,
  WMTrows = 6,
  WMTnames = 20,
  NAres = 7,
  NUserAction = 14,
  NStageHistory = 10
};
#include "worhp_data_structs.h"

typedef void (*worhp_print_t) (int mode, const char s[]);

typedef enum {
  WORHP_BOOL_T,
  WORHP_CUSTOM_T,
  WORHP_DOUBLE_T,
  WORHP_INT_T,
  WORHP_NO_T,
  WORHP_SINGLE_T,
  WORHP_SIZE_T,
  WORHP_CONST_C_STRING_T
} WorhpType;

int CheckWorhpVersion(int, int, const char *);
/*/ U CheckWorhpVersion@@WORHP_1.0*/
void SetWorhpPrint(worhp_print_t);
/* U SetWorhpPrint@@WORHP_1.0*/
void WorhpFidif(OptVar*, Workspace*, Params*, Control*);
/* U WorhpFidif@@WORHP_1.0*/
void WorhpFree(OptVar*, Workspace*, Params*, Control*);
/* U WorhpFree@@WORHP_1.0*/
int WorhpGetParamCount(void);
/* U WorhpGetParamCount@@WORHP_1.2*/
const char* WorhpGetParamName(int);
/* U WorhpGetParamName@@WORHP_1.2*/
WorhpType WorhpGetParamType(int);
/* U WorhpGetParamType@@WORHP_1.2*/
void WorhpInit(OptVar*, Workspace*, Params*, Control*);
/* U WorhpInit@@WORHP_1.0*/
void WorhpPreInit(OptVar *, Workspace *, Params *, Control *);
/* U WorhpPreInit@@WORHP_1.0*/
bool WorhpSetBoolParam  (Params *, const char*, bool);
/* U WorhpSetBoolParam@@WORHP_1.2*/
bool WorhpSetDoubleParam(Params *, const char*, double);
/* U WorhpSetDoubleParam@@WORHP_1.2*/
bool WorhpSetIntParam   (Params *, const char*, int);
/* U WorhpSetIntParam@@WORHP_1.2*/
void Worhp(OptVar*, Workspace*, Params*, Control*);
/* U Worhp@@WORHP_1.0*/

void InitParams(int*, Params*); // @@WORHP_1.0
bool GetUserAction(const Control *, int); // @@WORHP_1.0
void DoneUserAction(Control *, int); // @@WORHP_1.0
void StatusMsg(OptVar*, Workspace*, Params*, Control*); // @@WORHP_1.0
void IterationOutput(OptVar*, Workspace*, Params*, Control*); // IterationOutput@@WORHP_1.0

enum {
  TerminateSuccess = 1000,
  OptimalSolution = 1001,
  LowPassFilterOptimal = 1011,
  OptimalSolutionConstantF = 1012,
  FritzJohn = 1021,
  NotDiffable = 1022,
  Unbounded = 1031,
  FeasibleSolution = 1041,
  SearchDirectionZero = 1051,
  SearchDirectionSmall = 1052,
  AcceptableSolution = 1061,
  AcceptablePrevious = 1062,
  LowPassFilterAcceptable = 1063,
  AcceptableSolutionConstantF = 1064,
  AcceptablePreviousConstantF = 1065,
  AcceptableSolutionSKKT = 1066,
  AcceptableSolutionScaled = 1067,
  AcceptablePreviousScaled = 1068,
 /*-----------------------------------------------------------------
  *  (somehow) unsuccessful termination
  *-----------------------------------------------------------------*/
  TerminateError = -1000,
  MaxCalls = -1001,
  MaxIter = -1002,
  Timeout = -1003,
  LocalInfeasOptimal = -1011,
  LocalInfeas = -1012,
  GlobalInfeas = -1013,
  TooBig = -1021,
  evalsNaN = -1022,
  DivergingPrimal = -1023,
  DivergingDual = -1024,
  MinimumStepsize = -1031,
  RegularizationFailed = -1032,
  InitError = -1041,
  DataError = -1042,
  RestartError = -1043,
  FileOpenError = -1044,
  QPerror = -1051,
  LinearSolverFailed = -1052,
  TerminatedByCheckFD = -1061,
  LicenseError = -1071,
  Debug = -1206,
};

enum {
  WORHP_PRINT_MESSAGE         = 1,
  WORHP_PRINT_WARNING         = 2,
  WORHP_PRINT_ERROR           = 4,
};

enum {
  callWorhp = 1,
  evalF = 2,
  evalG = 3,
  evalDF = 4,
  evalDG = 5,
  evalHM = 6,
  evalZenDGp = 7,
  evalZenDLxp = 8,
  evalZenDLp = 9,
  evalZenDLpp = 10,
  iterOutput = 11,
  fidif_DF = 12,
  fidif_DG = 13,
  fidif_HM = 14,
  fidif = 15,
  FirstCall = 20
};

#ifdef __cplusplus
}
#endif

#endif // WORHP_H__
