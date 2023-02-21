#ifndef CPX_CPLEXL_H
#define CPX_CPLEXL_H

#ifdef __cplusplus
extern "C" {
#endif

#ifdef _WIN32
#define CPXPUBLIC      __stdcall
#define CPXPUBVARARGS  __cdecl
#define CPXCDECL       __cdecl
#else
#define CPXPUBLIC
#define CPXPUBVARARGS
#define CPXCDECL
#endif

#ifndef CPXBYTE_DEFINED
#   define CPXBYTE_DEFINED 1
    typedef signed char CPXBYTE;
#endif
    

#ifndef CPXINT_DEFINED
#   define CPXINT_DEFINED 1
    typedef int CPXINT;
#endif
    

#ifndef CPXLONG_DEFINED
#   define CPXLONG_DEFINED 1
#   ifdef _MSC_VER
       typedef __int64 CPXLONG;
#   else
       typedef long long CPXLONG;
#   endif
#endif

/* structure types */
struct cpxenv;
typedef struct cpxenv *CPXENVptr;
typedef struct cpxenv const *CPXCENVptr;

struct cpxchannel;
typedef struct cpxchannel  *CPXCHANNELptr;

struct paramset;
typedef struct paramset *CPXPARAMSETptr;
typedef struct paramset const *CPXCPARAMSETptr;

struct cpxlp;
typedef struct cpxlp        *CPXLPptr;
typedef const struct cpxlp  *CPXCLPptr;

struct cpxnet;
typedef struct cpxnet       *CPXNETptr;


typedef char       *CPXCHARptr;
typedef const char *CPXCCHARptr;
typedef void       *CPXVOIDptr;

#define CPXMESSAGEBUFSIZE 1024

#define CPX_INFBOUND  1.0E+20

#define CPX_PARAMTYPE_NONE   0
#define CPX_PARAMTYPE_INT    1
#define CPX_PARAMTYPE_DOUBLE 2 
#define CPX_PARAMTYPE_STRING 3
#define CPX_PARAMTYPE_LONG   4

#define CPX_AUTO -1
#define CPX_ON 1
#define CPX_OFF 0
#define CPX_MAX -1
#define CPX_MIN 1

#define CPX_STAT_OPTIMAL 1
#define CPX_STAT_INFEASIBLE 3
#define CPX_STAT_FIRSTORDER 24

#define CPXPROB_MIQP 7

#define CPXMIP_OPTIMAL 101
#define CPXMIP_OPTIMAL_TOL 102
#define CPXERR_NO_SOLN 1217

#define CASADI_CPLEX_ADAPTOR

#ifdef _WIN32
#include <windows.h>
#define adaptor_handle_t HINSTANCE
#else
#include <dlfcn.h>
#define adaptor_handle_t void*
#endif

#define CPX_APIMODEL_SMALL 1
#define CPX_APIMODEL_LARGE 2

#ifndef CPX_APIMODEL
#   if defined(__x86_64__) || defined(__ia64) || defined(_WIN64) || defined(__powerpc64__) || defined(__64BIT__) || defined(__sparcv9) || defined(__LP64__)
#      define CPX_APIMODEL CPX_APIMODEL_LARGE
#   else
#      define CPX_APIMODEL CPX_APIMODEL_SMALL
#   endif
#endif

#if CPX_APIMODEL == CPX_APIMODEL_SMALL
    typedef CPXINT CPXDIM;
#elif CPX_APIMODEL == CPX_APIMODEL_LARGE
    typedef CPXINT CPXDIM;
#endif

#if CPX_APIMODEL == CPX_APIMODEL_SMALL
    typedef CPXINT CPXNNZ;
#elif CPX_APIMODEL == CPX_APIMODEL_LARGE
    typedef CPXLONG CPXNNZ;
#endif

#if CPX_APIMODEL == CPX_APIMODEL_SMALL
    typedef CPXLONG CPXCNT;
#elif CPX_APIMODEL == CPX_APIMODEL_LARGE
    typedef CPXLONG CPXCNT;
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

int cplex_adaptor_load(const char* suffix, char* err_msg);

#define CPXXaddmipstarts adaptor_CPXXaddmipstarts
DLLSYMBOL int (*CPXXaddmipstarts)(CPXCENVptr, CPXLPptr, int, CPXNNZ, CPXNNZ const *, CPXDIM const *, double const *, int const *, char const *const *);
#define CPXXaddqconstr adaptor_CPXXaddqconstr
DLLSYMBOL int (*CPXXaddqconstr)(CPXCENVptr, CPXLPptr, CPXDIM, CPXNNZ, double, int, CPXDIM const *, double const *, CPXDIM const *, CPXDIM const *, double const *, char const *);
#define CPXXaddrows adaptor_CPXXaddrows
DLLSYMBOL int (*CPXXaddrows)(CPXCENVptr, CPXLPptr, CPXDIM, CPXDIM, CPXNNZ, double const *, char const *, CPXNNZ const *, CPXDIM const *, double const *, char const *const *, char const *const *);
#define CPXXaddsos adaptor_CPXXaddsos
DLLSYMBOL int (*CPXXaddsos)(CPXCENVptr, CPXLPptr, CPXDIM, CPXNNZ, char const *, CPXNNZ const *, CPXDIM const *, double const *, char const *const *);
#define CPXXcloseCPLEX adaptor_CPXXcloseCPLEX
DLLSYMBOL int (*CPXXcloseCPLEX)(CPXENVptr *);
#define CPXXcopyctype adaptor_CPXXcopyctype
DLLSYMBOL int (*CPXXcopyctype)(CPXCENVptr, CPXLPptr, char const *);
#define CPXXcopylp adaptor_CPXXcopylp
DLLSYMBOL int (*CPXXcopylp)(CPXCENVptr, CPXLPptr, CPXDIM, CPXDIM, int, double const *, double const *, char const *, CPXNNZ const *, CPXDIM const *, CPXDIM const *, double const *, double const *, double const *, double const *);
#define CPXXcopyquad adaptor_CPXXcopyquad
DLLSYMBOL int (*CPXXcopyquad)(CPXCENVptr, CPXLPptr, CPXNNZ const *, CPXDIM const *, CPXDIM const *, double const *);
#define CPXXcopystart adaptor_CPXXcopystart
DLLSYMBOL int (*CPXXcopystart)(CPXCENVptr, CPXLPptr, int const *, int const *, double const *, double const *, double const *, double const *);
#define CPXXcreateprob adaptor_CPXXcreateprob
DLLSYMBOL CPXLPptr (*CPXXcreateprob)(CPXCENVptr, int *, char const *);
#define CPXXfreeprob adaptor_CPXXfreeprob
DLLSYMBOL int (*CPXXfreeprob)(CPXCENVptr, CPXLPptr *);
#define CPXXgetbase adaptor_CPXXgetbase
DLLSYMBOL int (*CPXXgetbase)(CPXCENVptr, CPXCLPptr, int *, int *);
#define CPXXgeterrorstring adaptor_CPXXgeterrorstring
DLLSYMBOL CPXCCHARptr (*CPXXgeterrorstring)(CPXCENVptr, int, char *);
#define CPXXgetnumcols adaptor_CPXXgetnumcols
DLLSYMBOL CPXDIM (*CPXXgetnumcols)(CPXCENVptr, CPXCLPptr);
#define CPXXgetnumrows adaptor_CPXXgetnumrows
DLLSYMBOL CPXDIM (*CPXXgetnumrows)(CPXCENVptr, CPXCLPptr);
#define CPXXgetobjval adaptor_CPXXgetobjval
DLLSYMBOL int (*CPXXgetobjval)(CPXCENVptr, CPXCLPptr, double *);
#define CPXXgetparamnum adaptor_CPXXgetparamnum
DLLSYMBOL int (*CPXXgetparamnum)(CPXCENVptr, char const *, int *);
#define CPXXgetparamtype adaptor_CPXXgetparamtype
DLLSYMBOL int (*CPXXgetparamtype)(CPXCENVptr, int, int *);
#define CPXXgetprobtype adaptor_CPXXgetprobtype
DLLSYMBOL int (*CPXXgetprobtype)(CPXCENVptr, CPXCLPptr);
#define CPXXgetslack adaptor_CPXXgetslack
DLLSYMBOL int (*CPXXgetslack)(CPXCENVptr, CPXCLPptr, double *, CPXDIM, CPXDIM);
#define CPXXgetstat adaptor_CPXXgetstat
DLLSYMBOL int (*CPXXgetstat)(CPXCENVptr, CPXCLPptr);
#define CPXXgetstatstring adaptor_CPXXgetstatstring
DLLSYMBOL CPXCHARptr (*CPXXgetstatstring)(CPXCENVptr, int, char *);
#define CPXXgetx adaptor_CPXXgetx
DLLSYMBOL int (*CPXXgetx)(CPXCENVptr, CPXCLPptr, double *, CPXDIM, CPXDIM);
#define CPXXmipopt adaptor_CPXXmipopt
DLLSYMBOL int (*CPXXmipopt)(CPXCENVptr, CPXLPptr);
#define CPXXnewcols adaptor_CPXXnewcols
DLLSYMBOL int (*CPXXnewcols)(CPXCENVptr, CPXLPptr, CPXDIM, double const *, double const *, double const *, char const *, char const *const *);
#define CPXXopenCPLEX adaptor_CPXXopenCPLEX
DLLSYMBOL CPXENVptr (*CPXXopenCPLEX)(int *);
#define CPXXqpopt adaptor_CPXXqpopt
DLLSYMBOL int (*CPXXqpopt)(CPXCENVptr, CPXLPptr);
#define CPXXsetdblparam adaptor_CPXXsetdblparam
DLLSYMBOL int (*CPXXsetdblparam)(CPXENVptr, int, double);
#define CPXXsetdefaults adaptor_CPXXsetdefaults
DLLSYMBOL int (*CPXXsetdefaults)(CPXENVptr);
#define CPXXsetintparam adaptor_CPXXsetintparam
DLLSYMBOL int (*CPXXsetintparam)(CPXENVptr, int, CPXINT);
#define CPXXsetlongparam adaptor_CPXXsetlongparam
DLLSYMBOL int (*CPXXsetlongparam)(CPXENVptr, int, CPXLONG);
#define CPXXsetstrparam adaptor_CPXXsetstrparam
DLLSYMBOL int (*CPXXsetstrparam)(CPXENVptr, int, char const *);
#define CPXXsolution adaptor_CPXXsolution
DLLSYMBOL int (*CPXXsolution)(CPXCENVptr, CPXCLPptr, int *, double *, double *, double *, double *, double *);
#define CPXXwriteprob adaptor_CPXXwriteprob
DLLSYMBOL int (*CPXXwriteprob)(CPXCENVptr, CPXCLPptr, char const *, char const *);

#ifdef __cplusplus
}
#endif

#endif // CPX_CPLEXL_H
