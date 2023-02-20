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

#define CASADI_CPLEX_ADAPTOR

#ifdef _WIN32
#include <windows.h>
#define adaptor_handle_t HINSTANCE
#else
#include <dlfcn.h>
#define adaptor_handle_t void*
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

int cplex_adaptor_load(adaptor_handle_t handle);

#define CPXLaddmipstarts adaptor_CPXLaddmipstarts
DLLSYMBOL int (*CPXLaddmipstarts)(CPXCENVptr, CPXLPptr, int, CPXLONG, CPXLONG const *, CPXINT const *, double const *, int const *, char const *const *);
#define CPXLaddqconstr adaptor_CPXLaddqconstr
DLLSYMBOL int (*CPXLaddqconstr)(CPXCENVptr, CPXLPptr, CPXINT, CPXLONG, double, int, CPXINT const *, double const *, CPXINT const *, CPXINT const *, double const *, char const *);
#define CPXLaddrows adaptor_CPXLaddrows
DLLSYMBOL int (*CPXLaddrows)(CPXCENVptr, CPXLPptr, CPXINT, CPXINT, CPXLONG, double const *, char const *, CPXLONG const *, CPXINT const *, double const *, char const *const *, char const *const *);
#define CPXLaddsos adaptor_CPXLaddsos
DLLSYMBOL int (*CPXLaddsos)(CPXCENVptr, CPXLPptr, CPXINT, CPXLONG, char const *, CPXLONG const *, CPXINT const *, double const *, char const *const *);
#define CPXLcloseCPLEX adaptor_CPXLcloseCPLEX
DLLSYMBOL int (*CPXLcloseCPLEX)(CPXENVptr *);
#define CPXLcopyctype adaptor_CPXLcopyctype
DLLSYMBOL int (*CPXLcopyctype)(CPXCENVptr, CPXLPptr, char const *);
#define CPXLcopylp adaptor_CPXLcopylp
DLLSYMBOL int (*CPXLcopylp)(CPXCENVptr, CPXLPptr, CPXINT, CPXINT, int, double const *, double const *, char const *, CPXLONG const *, CPXINT const *, CPXINT const *, double const *, double const *, double const *, double const *);
#define CPXLcopyquad adaptor_CPXLcopyquad
DLLSYMBOL int (*CPXLcopyquad)(CPXCENVptr, CPXLPptr, CPXLONG const *, CPXINT const *, CPXINT const *, double const *);
#define CPXLcopystart adaptor_CPXLcopystart
DLLSYMBOL int (*CPXLcopystart)(CPXCENVptr, CPXLPptr, int const *, int const *, double const *, double const *, double const *, double const *);
#define CPXLcreateprob adaptor_CPXLcreateprob
DLLSYMBOL CPXLPptr (*CPXLcreateprob)(CPXCENVptr, int *, char const *);
#define CPXLfreeprob adaptor_CPXLfreeprob
DLLSYMBOL int (*CPXLfreeprob)(CPXCENVptr, CPXLPptr *);
#define CPXLgetbase adaptor_CPXLgetbase
DLLSYMBOL int (*CPXLgetbase)(CPXCENVptr, CPXCLPptr, int *, int *);
#define CPXLgeterrorstring adaptor_CPXLgeterrorstring
DLLSYMBOL CPXCCHARptr (*CPXLgeterrorstring)(CPXCENVptr, int, char *);
#define CPXLgetnumcols adaptor_CPXLgetnumcols
DLLSYMBOL CPXINT (*CPXLgetnumcols)(CPXCENVptr, CPXCLPptr);
#define CPXLgetnumrows adaptor_CPXLgetnumrows
DLLSYMBOL CPXINT (*CPXLgetnumrows)(CPXCENVptr, CPXCLPptr);
#define CPXLgetobjval adaptor_CPXLgetobjval
DLLSYMBOL int (*CPXLgetobjval)(CPXCENVptr, CPXCLPptr, double *);
#define CPXLgetparamnum adaptor_CPXLgetparamnum
DLLSYMBOL int (*CPXLgetparamnum)(CPXCENVptr, char const *, int *);
#define CPXLgetparamtype adaptor_CPXLgetparamtype
DLLSYMBOL int (*CPXLgetparamtype)(CPXCENVptr, int, int *);
#define CPXLgetprobtype adaptor_CPXLgetprobtype
DLLSYMBOL int (*CPXLgetprobtype)(CPXCENVptr, CPXCLPptr);
#define CPXLgetslack adaptor_CPXLgetslack
DLLSYMBOL int (*CPXLgetslack)(CPXCENVptr, CPXCLPptr, double *, CPXINT, CPXINT);
#define CPXLgetstat adaptor_CPXLgetstat
DLLSYMBOL int (*CPXLgetstat)(CPXCENVptr, CPXCLPptr);
#define CPXLgetstatstring adaptor_CPXLgetstatstring
DLLSYMBOL CPXCHARptr (*CPXLgetstatstring)(CPXCENVptr, int, char *);
#define CPXLgetx adaptor_CPXLgetx
DLLSYMBOL int (*CPXLgetx)(CPXCENVptr, CPXCLPptr, double *, CPXINT, CPXINT);
#define CPXLmipopt adaptor_CPXLmipopt
DLLSYMBOL int (*CPXLmipopt)(CPXCENVptr, CPXLPptr);
#define CPXLnewcols adaptor_CPXLnewcols
DLLSYMBOL int (*CPXLnewcols)(CPXCENVptr, CPXLPptr, CPXINT, double const *, double const *, double const *, char const *, char const *const *);
#define CPXLopenCPLEX adaptor_CPXLopenCPLEX
DLLSYMBOL CPXENVptr (*CPXLopenCPLEX)(int *status_p);
#define CPXLqpopt adaptor_CPXLqpopt
DLLSYMBOL int (*CPXLqpopt)(CPXCENVptr, CPXLPptr);
#define CPXLsetdblparam adaptor_CPXLsetdblparam
DLLSYMBOL int (*CPXLsetdblparam)(CPXENVptr, int, double);
#define CPXLsetdefaults adaptor_CPXLsetdefaults
DLLSYMBOL int (*CPXLsetdefaults)(CPXENVptr);
#define CPXLsetintparam adaptor_CPXLsetintparam
DLLSYMBOL int (*CPXLsetintparam)(CPXENVptr, int, CPXINT);
#define CPXLsetlongparam adaptor_CPXLsetlongparam
DLLSYMBOL int (*CPXLsetlongparam)(CPXENVptr, int, CPXLONG);
#define CPXLsetstrparam adaptor_CPXLsetstrparam
DLLSYMBOL int (*CPXLsetstrparam)(CPXENVptr, int, char const *);
#define CPXLsolution adaptor_CPXLsolution
DLLSYMBOL int (*CPXLsolution)(CPXCENVptr, CPXCLPptr, int *, double *, double *, double *, double *, double *);
#define CPXLwriteprob adaptor_CPXLwriteprob
DLLSYMBOL int (*CPXLwriteprob)(CPXCENVptr, CPXCLPptr, char const *, char const *);

#ifdef __cplusplus
}
#endif

#endif // CPX_CPLEXL_H
