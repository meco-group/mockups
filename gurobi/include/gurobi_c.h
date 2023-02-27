#ifndef GUROBI_H
#define GUROBI_H

#ifdef __cplusplus
extern "C" {
#endif


#include <stdio.h>

typedef struct _GRBbatch GRBbatch;
typedef struct _GRBmodel GRBmodel;
typedef struct _GRBenv GRBenv;

#if defined(_WIN64) && !defined(WIN64)
#define WIN64
#endif

#if defined(_WIN32) && !defined(_WIN64) && !defined(WIN32)
#define WIN32
#endif

#if !defined(WIN32) && !defined(WIN64)
#define __cdecl
#define __stdcall
#endif

#ifdef _WIN32
    #ifdef DLL_IMPLEMENTATION
    #define DLLSYMBOL __declspec( dllexport )
    #else
    #define DLLSYMBOL __declspec( dllimport ) extern
    #endif
#else
    #ifdef DLL_IMPLEMENTATION
    #define DLLSYMBOL 
    #else
    #define DLLSYMBOL extern
    #endif
#endif

#define GRB_CONTINUOUS 'C'
#define GRB_BINARY     'B'
#define GRB_INTEGER    'I'
#define GRB_SEMICONT   'S'
#define GRB_SEMIINT    'N'

#define GRB_LOADED          1
#define GRB_OPTIMAL         2
#define GRB_INFEASIBLE      3
#define GRB_INF_OR_UNBD     4
#define GRB_UNBOUNDED       5
#define GRB_CUTOFF          6
#define GRB_ITERATION_LIMIT 7
#define GRB_NODE_LIMIT      8
#define GRB_TIME_LIMIT      9
#define GRB_SOLUTION_LIMIT 10
#define GRB_INTERRUPTED    11
#define GRB_NUMERIC        12
#define GRB_SUBOPTIMAL     13
#define GRB_INPROGRESS     14
#define GRB_USER_OBJ_LIMIT 15

#define GRB_DBL_ATTR_X         "X"
#define GRB_DBL_ATTR_XN        "Xn"
#define GRB_DBL_ATTR_BARX      "BarX"
#define GRB_DBL_ATTR_RC        "RC"
#define GRB_DBL_ATTR_VDUALNORM "VDualNorm"
#define GRB_INT_ATTR_VBASIS    "VBasis"

#define GRB_DBL_ATTR_PI        "Pi"
#define GRB_DBL_ATTR_QCPI      "QCPi"
#define GRB_DBL_ATTR_SLACK     "Slack"
#define GRB_DBL_ATTR_QCSLACK   "QCSlack"
#define GRB_DBL_ATTR_CDUALNORM "CDualNorm"
#define GRB_INT_ATTR_CBASIS    "CBasis"

#define GRB_LESS_EQUAL    '<'
#define GRB_GREATER_EQUAL '>'
#define GRB_EQUAL         '='

#define GRB_MINIMIZE 1
#define GRB_MAXIMIZE -1

#define GRB_SOS_TYPE1 1
#define GRB_SOS_TYPE2 2

#define GRB_INFINITY  1e100
#define GRB_UNDEFINED 1e101
#define GRB_MAXINT    2000000000

#define GRB_MAX_NAMELEN    255
#define GRB_MAX_STRLEN     512
#define GRB_MAX_TAGLEN    10240
#define GRB_MAX_CONCURRENT 64

#define GRB_DBL_ATTR_RUNTIME       "Runtime"
#define GRB_INT_ATTR_STATUS        "Status"
#define GRB_DBL_ATTR_OBJVAL        "ObjVal"
#define GRB_DBL_ATTR_OBJBOUND      "ObjBound"
#define GRB_DBL_ATTR_OBJBOUNDC     "ObjBoundC"
#define GRB_DBL_ATTR_POOLOBJBOUND  "PoolObjBound"
#define GRB_DBL_ATTR_POOLOBJVAL    "PoolObjVal"
#define GRB_DBL_ATTR_MIPGAP        "MIPGap"
#define GRB_INT_ATTR_SOLCOUNT      "SolCount"
#define GRB_DBL_ATTR_ITERCOUNT     "IterCount"
#define GRB_INT_ATTR_BARITERCOUNT  "BarIterCount"
#define GRB_DBL_ATTR_NODECOUNT     "NodeCount"
#define GRB_DBL_ATTR_OPENNODECOUNT "OpenNodeCount"
#define GRB_INT_ATTR_HASDUALNORM   "HasDualNorm"
             
#define GUROBI_ADAPTOR
                                     
#define GRBaddconstr adaptor_GRBaddconstr
DLLSYMBOL int (__stdcall *GRBaddconstr)(GRBmodel *, int, int *, double *, char, double, const char *);
#define GRBaddqconstr adaptor_GRBaddqconstr
DLLSYMBOL int (__stdcall *GRBaddqconstr)(GRBmodel *, int, int *, double *, int, int *, int *, double *, char, double, const char *);
#define GRBaddqpterms adaptor_GRBaddqpterms
DLLSYMBOL int (__stdcall *GRBaddqpterms)(GRBmodel *, int, int *, int *, double *);
#define GRBaddrangeconstr adaptor_GRBaddrangeconstr
DLLSYMBOL int (__stdcall *GRBaddrangeconstr)(GRBmodel *, int, int *, double *, double, double, const char *);
#define GRBaddsos adaptor_GRBaddsos
DLLSYMBOL int (__stdcall *GRBaddsos)(GRBmodel *, int, int, int *, int *, int *, double *);
#define GRBaddvar adaptor_GRBaddvar
DLLSYMBOL int (__stdcall *GRBaddvar)(GRBmodel *, int, int *, double *, double, double, double, char, const char *);
#define GRBfreeenv adaptor_GRBfreeenv
DLLSYMBOL void (__stdcall *GRBfreeenv)(GRBenv *);
#define GRBfreemodel adaptor_GRBfreemodel
DLLSYMBOL int (__stdcall *GRBfreemodel)(GRBmodel *);
#define GRBgetdblattr adaptor_GRBgetdblattr
DLLSYMBOL int (__stdcall *GRBgetdblattr)(GRBmodel *, const char *, double *);
#define GRBgetdblattrarray adaptor_GRBgetdblattrarray
DLLSYMBOL int (__stdcall *GRBgetdblattrarray)(GRBmodel *, const char *, int, int, double *);
#define GRBgetenv adaptor_GRBgetenv
DLLSYMBOL GRBenv* (__stdcall *GRBgetenv)(GRBmodel *);
#define GRBgeterrormsg adaptor_GRBgeterrormsg
DLLSYMBOL const char* (__stdcall *GRBgeterrormsg)(GRBenv *);
#define GRBgetintattr adaptor_GRBgetintattr
DLLSYMBOL int (__stdcall *GRBgetintattr)(GRBmodel *, const char *, int *);
#define GRBgetparamtype adaptor_GRBgetparamtype
DLLSYMBOL int (__stdcall *GRBgetparamtype)(GRBenv *, const char *);
#define GRBloadenv adaptor_GRBloadenv
DLLSYMBOL int (__stdcall *GRBloadenv)(GRBenv **, const char *);
#define GRBnewmodel adaptor_GRBnewmodel
DLLSYMBOL int (__stdcall *GRBnewmodel)(GRBenv *, GRBmodel **, const char *, int, double *, double *, double *, char *, char **);
#define GRBoptimize adaptor_GRBoptimize
DLLSYMBOL int (__stdcall *GRBoptimize)(GRBmodel *);
#define GRBsetdblattrelement adaptor_GRBsetdblattrelement
DLLSYMBOL int (__stdcall *GRBsetdblattrelement)(GRBmodel *, const char *, int, double);
#define GRBsetdblparam adaptor_GRBsetdblparam
DLLSYMBOL int (__stdcall *GRBsetdblparam)(GRBenv *, const char *, double);
#define GRBsetintparam adaptor_GRBsetintparam
DLLSYMBOL int (__stdcall *GRBsetintparam)(GRBenv *, const char *, int);
#define GRBsetstrparam adaptor_GRBsetstrparam
DLLSYMBOL int (__stdcall *GRBsetstrparam)(GRBenv *, const char *, const char *);
#define GRBupdatemodel adaptor_GRBupdatemodel
DLLSYMBOL int (__stdcall *GRBupdatemodel)(GRBmodel *);

#ifdef __cplusplus
}
#endif

#endif // GUROBI_H
