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
