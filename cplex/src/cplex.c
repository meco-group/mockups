
#define DLL_IMPLEMENTATION
#include "cplex.h"

#include <stdio.h>
#ifdef _WIN32
#include <windows.h>
#else // _WIN32
#include <dlfcn.h>
#include <stddef.h>
#endif // _WIN32


int (*CPXXaddmipstarts)(CPXCENVptr, CPXLPptr, int, CPXNNZ, CPXNNZ const *, CPXDIM const *, double const *, int const *, char const *const *) = NULL;
int (*CPXXaddqconstr)(CPXCENVptr, CPXLPptr, CPXDIM, CPXNNZ, double, int, CPXDIM const *, double const *, CPXDIM const *, CPXDIM const *, double const *, char const *) = NULL;
int (*CPXXaddrows)(CPXCENVptr, CPXLPptr, CPXDIM, CPXDIM, CPXNNZ, double const *, char const *, CPXNNZ const *, CPXDIM const *, double const *, char const *const *, char const *const *) = NULL;
int (*CPXXaddsos)(CPXCENVptr, CPXLPptr, CPXDIM, CPXNNZ, char const *, CPXNNZ const *, CPXDIM const *, double const *, char const *const *) = NULL;
int (*CPXXcloseCPLEX)(CPXENVptr *) = NULL;
int (*CPXXcopyctype)(CPXCENVptr, CPXLPptr, char const *) = NULL;
int (*CPXXcopylp)(CPXCENVptr, CPXLPptr, CPXDIM, CPXDIM, int, double const *, double const *, char const *, CPXNNZ const *, CPXDIM const *, CPXDIM const *, double const *, double const *, double const *, double const *) = NULL;
int (*CPXXcopyquad)(CPXCENVptr, CPXLPptr, CPXNNZ const *, CPXDIM const *, CPXDIM const *, double const *) = NULL;
int (*CPXXcopystart)(CPXCENVptr, CPXLPptr, int const *, int const *, double const *, double const *, double const *, double const *) = NULL;
CPXLPptr (*CPXXcreateprob)(CPXCENVptr, int *, char const *) = NULL;
int (*CPXXfreeprob)(CPXCENVptr, CPXLPptr *) = NULL;
int (*CPXXgetbase)(CPXCENVptr, CPXCLPptr, int *, int *) = NULL;
CPXCCHARptr (*CPXXgeterrorstring)(CPXCENVptr, int, char *) = NULL;
CPXDIM (*CPXXgetnumcols)(CPXCENVptr, CPXCLPptr) = NULL;
CPXDIM (*CPXXgetnumrows)(CPXCENVptr, CPXCLPptr) = NULL;
int (*CPXXgetobjval)(CPXCENVptr, CPXCLPptr, double *) = NULL;
int (*CPXXgetparamnum)(CPXCENVptr, char const *, int *) = NULL;
int (*CPXXgetparamtype)(CPXCENVptr, int, int *) = NULL;
int (*CPXXgetprobtype)(CPXCENVptr, CPXCLPptr) = NULL;
int (*CPXXgetslack)(CPXCENVptr, CPXCLPptr, double *, CPXDIM, CPXDIM) = NULL;
int (*CPXXgetstat)(CPXCENVptr, CPXCLPptr) = NULL;
CPXCHARptr (*CPXXgetstatstring)(CPXCENVptr, int, char *) = NULL;
int (*CPXXgetx)(CPXCENVptr, CPXCLPptr, double *, CPXDIM, CPXDIM) = NULL;
int (*CPXXmipopt)(CPXCENVptr, CPXLPptr) = NULL;
int (*CPXXnewcols)(CPXCENVptr, CPXLPptr, CPXDIM, double const *, double const *, double const *, char const *, char const *const *) = NULL;
CPXENVptr (*CPXXopenCPLEX)(int *) = NULL;
int (*CPXXqpopt)(CPXCENVptr, CPXLPptr) = NULL;
int (*CPXXsetdblparam)(CPXENVptr, int, double) = NULL;
int (*CPXXsetdefaults)(CPXENVptr) = NULL;
int (*CPXXsetintparam)(CPXENVptr, int, CPXINT) = NULL;
int (*CPXXsetlongparam)(CPXENVptr, int, CPXLONG) = NULL;
int (*CPXXsetstrparam)(CPXENVptr, int, char const *) = NULL;
int (*CPXXsolution)(CPXCENVptr, CPXCLPptr, int *, double *, double *, double *, double *, double *) = NULL;
int (*CPXXwriteprob)(CPXCENVptr, CPXCLPptr, char const *, char const *) = NULL;

  
  int cplex_adaptor_load(const char* suffix, char* err_msg) {
    char buffer[100];
    
    #if defined(_WIN32)
    sprintf(buffer, "libcplex%s.dll", suffix);
    #elif defined(__APPLE__)
    sprintf(buffer, "libcplex%s.dylib", suffix);
    #else
    sprintf(buffer, "libcplex%s.so", suffix);
    #endif
    
    #if defined(_WIN32)
    HINSTANCE h = LoadLibrary(TEXT(buffer));
    #elif defined(__APPLE__)
    void * h = dlopen(buffer, RTLD_LAZY | RTLD_LOCAL);
    #else
    void * h = dlopen(buffer, RTLD_LAZY | RTLD_LOCAL | RTLD_DEEPBIND);
    #endif
    
    if (h) {
      #ifdef _WIN32
#if CPX_APIMODEL == CPX_APIMODEL_LARGE
            CPXXaddmipstarts = (int (*)(CPXCENVptr, CPXLPptr, int, CPXNNZ, CPXNNZ const *, CPXDIM const *, double const *, int const *, char const *const *)) GetProcAddress(h, "CPXLaddmipstarts");
            CPXXaddqconstr = (int (*)(CPXCENVptr, CPXLPptr, CPXDIM, CPXNNZ, double, int, CPXDIM const *, double const *, CPXDIM const *, CPXDIM const *, double const *, char const *)) GetProcAddress(h, "CPXLaddqconstr");
            CPXXaddrows = (int (*)(CPXCENVptr, CPXLPptr, CPXDIM, CPXDIM, CPXNNZ, double const *, char const *, CPXNNZ const *, CPXDIM const *, double const *, char const *const *, char const *const *)) GetProcAddress(h, "CPXLaddrows");
            CPXXaddsos = (int (*)(CPXCENVptr, CPXLPptr, CPXDIM, CPXNNZ, char const *, CPXNNZ const *, CPXDIM const *, double const *, char const *const *)) GetProcAddress(h, "CPXLaddsos");
            CPXXcloseCPLEX = (int (*)(CPXENVptr *)) GetProcAddress(h, "CPXLcloseCPLEX");
            CPXXcopyctype = (int (*)(CPXCENVptr, CPXLPptr, char const *)) GetProcAddress(h, "CPXLcopyctype");
            CPXXcopylp = (int (*)(CPXCENVptr, CPXLPptr, CPXDIM, CPXDIM, int, double const *, double const *, char const *, CPXNNZ const *, CPXDIM const *, CPXDIM const *, double const *, double const *, double const *, double const *)) GetProcAddress(h, "CPXLcopylp");
            CPXXcopyquad = (int (*)(CPXCENVptr, CPXLPptr, CPXNNZ const *, CPXDIM const *, CPXDIM const *, double const *)) GetProcAddress(h, "CPXLcopyquad");
            CPXXcopystart = (int (*)(CPXCENVptr, CPXLPptr, int const *, int const *, double const *, double const *, double const *, double const *)) GetProcAddress(h, "CPXLcopystart");
            CPXXcreateprob = (CPXLPptr (*)(CPXCENVptr, int *, char const *)) GetProcAddress(h, "CPXLcreateprob");
            CPXXfreeprob = (int (*)(CPXCENVptr, CPXLPptr *)) GetProcAddress(h, "CPXLfreeprob");
            CPXXgetbase = (int (*)(CPXCENVptr, CPXCLPptr, int *, int *)) GetProcAddress(h, "CPXLgetbase");
            CPXXgeterrorstring = (CPXCCHARptr (*)(CPXCENVptr, int, char *)) GetProcAddress(h, "CPXLgeterrorstring");
            CPXXgetnumcols = (CPXDIM (*)(CPXCENVptr, CPXCLPptr)) GetProcAddress(h, "CPXLgetnumcols");
            CPXXgetnumrows = (CPXDIM (*)(CPXCENVptr, CPXCLPptr)) GetProcAddress(h, "CPXLgetnumrows");
            CPXXgetobjval = (int (*)(CPXCENVptr, CPXCLPptr, double *)) GetProcAddress(h, "CPXLgetobjval");
            CPXXgetparamnum = (int (*)(CPXCENVptr, char const *, int *)) GetProcAddress(h, "CPXLgetparamnum");
            CPXXgetparamtype = (int (*)(CPXCENVptr, int, int *)) GetProcAddress(h, "CPXLgetparamtype");
            CPXXgetprobtype = (int (*)(CPXCENVptr, CPXCLPptr)) GetProcAddress(h, "CPXLgetprobtype");
            CPXXgetslack = (int (*)(CPXCENVptr, CPXCLPptr, double *, CPXDIM, CPXDIM)) GetProcAddress(h, "CPXLgetslack");
            CPXXgetstat = (int (*)(CPXCENVptr, CPXCLPptr)) GetProcAddress(h, "CPXLgetstat");
            CPXXgetstatstring = (CPXCHARptr (*)(CPXCENVptr, int, char *)) GetProcAddress(h, "CPXLgetstatstring");
            CPXXgetx = (int (*)(CPXCENVptr, CPXCLPptr, double *, CPXDIM, CPXDIM)) GetProcAddress(h, "CPXLgetx");
            CPXXmipopt = (int (*)(CPXCENVptr, CPXLPptr)) GetProcAddress(h, "CPXLmipopt");
            CPXXnewcols = (int (*)(CPXCENVptr, CPXLPptr, CPXDIM, double const *, double const *, double const *, char const *, char const *const *)) GetProcAddress(h, "CPXLnewcols");
            CPXXopenCPLEX = (CPXENVptr (*)(int *)) GetProcAddress(h, "CPXLopenCPLEX");
            CPXXqpopt = (int (*)(CPXCENVptr, CPXLPptr)) GetProcAddress(h, "CPXLqpopt");
            CPXXsetdblparam = (int (*)(CPXENVptr, int, double)) GetProcAddress(h, "CPXLsetdblparam");
            CPXXsetdefaults = (int (*)(CPXENVptr)) GetProcAddress(h, "CPXLsetdefaults");
            CPXXsetintparam = (int (*)(CPXENVptr, int, CPXINT)) GetProcAddress(h, "CPXLsetintparam");
            CPXXsetlongparam = (int (*)(CPXENVptr, int, CPXLONG)) GetProcAddress(h, "CPXLsetlongparam");
            CPXXsetstrparam = (int (*)(CPXENVptr, int, char const *)) GetProcAddress(h, "CPXLsetstrparam");
            CPXXsolution = (int (*)(CPXCENVptr, CPXCLPptr, int *, double *, double *, double *, double *, double *)) GetProcAddress(h, "CPXLsolution");
            CPXXwriteprob = (int (*)(CPXCENVptr, CPXCLPptr, char const *, char const *)) GetProcAddress(h, "CPXLwriteprob");
#endif
#if CPX_APIMODEL == CPX_APIMODEL_SMALL
            CPXXaddmipstarts = (int (*)(CPXCENVptr, CPXLPptr, int, CPXNNZ, CPXNNZ const *, CPXDIM const *, double const *, int const *, char const *const *)) GetProcAddress(h, "CPXSaddmipstarts");
            CPXXaddqconstr = (int (*)(CPXCENVptr, CPXLPptr, CPXDIM, CPXNNZ, double, int, CPXDIM const *, double const *, CPXDIM const *, CPXDIM const *, double const *, char const *)) GetProcAddress(h, "CPXSaddqconstr");
            CPXXaddrows = (int (*)(CPXCENVptr, CPXLPptr, CPXDIM, CPXDIM, CPXNNZ, double const *, char const *, CPXNNZ const *, CPXDIM const *, double const *, char const *const *, char const *const *)) GetProcAddress(h, "CPXSaddrows");
            CPXXaddsos = (int (*)(CPXCENVptr, CPXLPptr, CPXDIM, CPXNNZ, char const *, CPXNNZ const *, CPXDIM const *, double const *, char const *const *)) GetProcAddress(h, "CPXSaddsos");
            CPXXcloseCPLEX = (int (*)(CPXENVptr *)) GetProcAddress(h, "CPXScloseCPLEX");
            CPXXcopyctype = (int (*)(CPXCENVptr, CPXLPptr, char const *)) GetProcAddress(h, "CPXScopyctype");
            CPXXcopylp = (int (*)(CPXCENVptr, CPXLPptr, CPXDIM, CPXDIM, int, double const *, double const *, char const *, CPXNNZ const *, CPXDIM const *, CPXDIM const *, double const *, double const *, double const *, double const *)) GetProcAddress(h, "CPXScopylp");
            CPXXcopyquad = (int (*)(CPXCENVptr, CPXLPptr, CPXNNZ const *, CPXDIM const *, CPXDIM const *, double const *)) GetProcAddress(h, "CPXScopyquad");
            CPXXcopystart = (int (*)(CPXCENVptr, CPXLPptr, int const *, int const *, double const *, double const *, double const *, double const *)) GetProcAddress(h, "CPXScopystart");
            CPXXcreateprob = (CPXLPptr (*)(CPXCENVptr, int *, char const *)) GetProcAddress(h, "CPXScreateprob");
            CPXXfreeprob = (int (*)(CPXCENVptr, CPXLPptr *)) GetProcAddress(h, "CPXSfreeprob");
            CPXXgetbase = (int (*)(CPXCENVptr, CPXCLPptr, int *, int *)) GetProcAddress(h, "CPXSgetbase");
            CPXXgeterrorstring = (CPXCCHARptr (*)(CPXCENVptr, int, char *)) GetProcAddress(h, "CPXSgeterrorstring");
            CPXXgetnumcols = (CPXDIM (*)(CPXCENVptr, CPXCLPptr)) GetProcAddress(h, "CPXSgetnumcols");
            CPXXgetnumrows = (CPXDIM (*)(CPXCENVptr, CPXCLPptr)) GetProcAddress(h, "CPXSgetnumrows");
            CPXXgetobjval = (int (*)(CPXCENVptr, CPXCLPptr, double *)) GetProcAddress(h, "CPXSgetobjval");
            CPXXgetparamnum = (int (*)(CPXCENVptr, char const *, int *)) GetProcAddress(h, "CPXSgetparamnum");
            CPXXgetparamtype = (int (*)(CPXCENVptr, int, int *)) GetProcAddress(h, "CPXSgetparamtype");
            CPXXgetprobtype = (int (*)(CPXCENVptr, CPXCLPptr)) GetProcAddress(h, "CPXSgetprobtype");
            CPXXgetslack = (int (*)(CPXCENVptr, CPXCLPptr, double *, CPXDIM, CPXDIM)) GetProcAddress(h, "CPXSgetslack");
            CPXXgetstat = (int (*)(CPXCENVptr, CPXCLPptr)) GetProcAddress(h, "CPXSgetstat");
            CPXXgetstatstring = (CPXCHARptr (*)(CPXCENVptr, int, char *)) GetProcAddress(h, "CPXSgetstatstring");
            CPXXgetx = (int (*)(CPXCENVptr, CPXCLPptr, double *, CPXDIM, CPXDIM)) GetProcAddress(h, "CPXSgetx");
            CPXXmipopt = (int (*)(CPXCENVptr, CPXLPptr)) GetProcAddress(h, "CPXSmipopt");
            CPXXnewcols = (int (*)(CPXCENVptr, CPXLPptr, CPXDIM, double const *, double const *, double const *, char const *, char const *const *)) GetProcAddress(h, "CPXSnewcols");
            CPXXopenCPLEX = (CPXENVptr (*)(int *)) GetProcAddress(h, "CPXSopenCPLEX");
            CPXXqpopt = (int (*)(CPXCENVptr, CPXLPptr)) GetProcAddress(h, "CPXSqpopt");
            CPXXsetdblparam = (int (*)(CPXENVptr, int, double)) GetProcAddress(h, "CPXSsetdblparam");
            CPXXsetdefaults = (int (*)(CPXENVptr)) GetProcAddress(h, "CPXSsetdefaults");
            CPXXsetintparam = (int (*)(CPXENVptr, int, CPXINT)) GetProcAddress(h, "CPXSsetintparam");
            CPXXsetlongparam = (int (*)(CPXENVptr, int, CPXLONG)) GetProcAddress(h, "CPXSsetlongparam");
            CPXXsetstrparam = (int (*)(CPXENVptr, int, char const *)) GetProcAddress(h, "CPXSsetstrparam");
            CPXXsolution = (int (*)(CPXCENVptr, CPXCLPptr, int *, double *, double *, double *, double *, double *)) GetProcAddress(h, "CPXSsolution");
            CPXXwriteprob = (int (*)(CPXCENVptr, CPXCLPptr, char const *, char const *)) GetProcAddress(h, "CPXSwriteprob");
#endif

      #else // _WIN32
  #if CPX_APIMODEL == CPX_APIMODEL_LARGE
            CPXXaddmipstarts = (int (*)(CPXCENVptr, CPXLPptr, int, CPXNNZ, CPXNNZ const *, CPXDIM const *, double const *, int const *, char const *const *)) dlsym(h, "CPXLaddmipstarts");
            CPXXaddqconstr = (int (*)(CPXCENVptr, CPXLPptr, CPXDIM, CPXNNZ, double, int, CPXDIM const *, double const *, CPXDIM const *, CPXDIM const *, double const *, char const *)) dlsym(h, "CPXLaddqconstr");
            CPXXaddrows = (int (*)(CPXCENVptr, CPXLPptr, CPXDIM, CPXDIM, CPXNNZ, double const *, char const *, CPXNNZ const *, CPXDIM const *, double const *, char const *const *, char const *const *)) dlsym(h, "CPXLaddrows");
            CPXXaddsos = (int (*)(CPXCENVptr, CPXLPptr, CPXDIM, CPXNNZ, char const *, CPXNNZ const *, CPXDIM const *, double const *, char const *const *)) dlsym(h, "CPXLaddsos");
            CPXXcloseCPLEX = (int (*)(CPXENVptr *)) dlsym(h, "CPXLcloseCPLEX");
            CPXXcopyctype = (int (*)(CPXCENVptr, CPXLPptr, char const *)) dlsym(h, "CPXLcopyctype");
            CPXXcopylp = (int (*)(CPXCENVptr, CPXLPptr, CPXDIM, CPXDIM, int, double const *, double const *, char const *, CPXNNZ const *, CPXDIM const *, CPXDIM const *, double const *, double const *, double const *, double const *)) dlsym(h, "CPXLcopylp");
            CPXXcopyquad = (int (*)(CPXCENVptr, CPXLPptr, CPXNNZ const *, CPXDIM const *, CPXDIM const *, double const *)) dlsym(h, "CPXLcopyquad");
            CPXXcopystart = (int (*)(CPXCENVptr, CPXLPptr, int const *, int const *, double const *, double const *, double const *, double const *)) dlsym(h, "CPXLcopystart");
            CPXXcreateprob = (CPXLPptr (*)(CPXCENVptr, int *, char const *)) dlsym(h, "CPXLcreateprob");
            CPXXfreeprob = (int (*)(CPXCENVptr, CPXLPptr *)) dlsym(h, "CPXLfreeprob");
            CPXXgetbase = (int (*)(CPXCENVptr, CPXCLPptr, int *, int *)) dlsym(h, "CPXLgetbase");
            CPXXgeterrorstring = (CPXCCHARptr (*)(CPXCENVptr, int, char *)) dlsym(h, "CPXLgeterrorstring");
            CPXXgetnumcols = (CPXDIM (*)(CPXCENVptr, CPXCLPptr)) dlsym(h, "CPXLgetnumcols");
            CPXXgetnumrows = (CPXDIM (*)(CPXCENVptr, CPXCLPptr)) dlsym(h, "CPXLgetnumrows");
            CPXXgetobjval = (int (*)(CPXCENVptr, CPXCLPptr, double *)) dlsym(h, "CPXLgetobjval");
            CPXXgetparamnum = (int (*)(CPXCENVptr, char const *, int *)) dlsym(h, "CPXLgetparamnum");
            CPXXgetparamtype = (int (*)(CPXCENVptr, int, int *)) dlsym(h, "CPXLgetparamtype");
            CPXXgetprobtype = (int (*)(CPXCENVptr, CPXCLPptr)) dlsym(h, "CPXLgetprobtype");
            CPXXgetslack = (int (*)(CPXCENVptr, CPXCLPptr, double *, CPXDIM, CPXDIM)) dlsym(h, "CPXLgetslack");
            CPXXgetstat = (int (*)(CPXCENVptr, CPXCLPptr)) dlsym(h, "CPXLgetstat");
            CPXXgetstatstring = (CPXCHARptr (*)(CPXCENVptr, int, char *)) dlsym(h, "CPXLgetstatstring");
            CPXXgetx = (int (*)(CPXCENVptr, CPXCLPptr, double *, CPXDIM, CPXDIM)) dlsym(h, "CPXLgetx");
            CPXXmipopt = (int (*)(CPXCENVptr, CPXLPptr)) dlsym(h, "CPXLmipopt");
            CPXXnewcols = (int (*)(CPXCENVptr, CPXLPptr, CPXDIM, double const *, double const *, double const *, char const *, char const *const *)) dlsym(h, "CPXLnewcols");
            CPXXopenCPLEX = (CPXENVptr (*)(int *)) dlsym(h, "CPXLopenCPLEX");
            CPXXqpopt = (int (*)(CPXCENVptr, CPXLPptr)) dlsym(h, "CPXLqpopt");
            CPXXsetdblparam = (int (*)(CPXENVptr, int, double)) dlsym(h, "CPXLsetdblparam");
            CPXXsetdefaults = (int (*)(CPXENVptr)) dlsym(h, "CPXLsetdefaults");
            CPXXsetintparam = (int (*)(CPXENVptr, int, CPXINT)) dlsym(h, "CPXLsetintparam");
            CPXXsetlongparam = (int (*)(CPXENVptr, int, CPXLONG)) dlsym(h, "CPXLsetlongparam");
            CPXXsetstrparam = (int (*)(CPXENVptr, int, char const *)) dlsym(h, "CPXLsetstrparam");
            CPXXsolution = (int (*)(CPXCENVptr, CPXCLPptr, int *, double *, double *, double *, double *, double *)) dlsym(h, "CPXLsolution");
            CPXXwriteprob = (int (*)(CPXCENVptr, CPXCLPptr, char const *, char const *)) dlsym(h, "CPXLwriteprob");
#endif
#if CPX_APIMODEL == CPX_APIMODEL_SMALL
            CPXXaddmipstarts = (int (*)(CPXCENVptr, CPXLPptr, int, CPXNNZ, CPXNNZ const *, CPXDIM const *, double const *, int const *, char const *const *)) dlsym(h, "CPXSaddmipstarts");
            CPXXaddqconstr = (int (*)(CPXCENVptr, CPXLPptr, CPXDIM, CPXNNZ, double, int, CPXDIM const *, double const *, CPXDIM const *, CPXDIM const *, double const *, char const *)) dlsym(h, "CPXSaddqconstr");
            CPXXaddrows = (int (*)(CPXCENVptr, CPXLPptr, CPXDIM, CPXDIM, CPXNNZ, double const *, char const *, CPXNNZ const *, CPXDIM const *, double const *, char const *const *, char const *const *)) dlsym(h, "CPXSaddrows");
            CPXXaddsos = (int (*)(CPXCENVptr, CPXLPptr, CPXDIM, CPXNNZ, char const *, CPXNNZ const *, CPXDIM const *, double const *, char const *const *)) dlsym(h, "CPXSaddsos");
            CPXXcloseCPLEX = (int (*)(CPXENVptr *)) dlsym(h, "CPXScloseCPLEX");
            CPXXcopyctype = (int (*)(CPXCENVptr, CPXLPptr, char const *)) dlsym(h, "CPXScopyctype");
            CPXXcopylp = (int (*)(CPXCENVptr, CPXLPptr, CPXDIM, CPXDIM, int, double const *, double const *, char const *, CPXNNZ const *, CPXDIM const *, CPXDIM const *, double const *, double const *, double const *, double const *)) dlsym(h, "CPXScopylp");
            CPXXcopyquad = (int (*)(CPXCENVptr, CPXLPptr, CPXNNZ const *, CPXDIM const *, CPXDIM const *, double const *)) dlsym(h, "CPXScopyquad");
            CPXXcopystart = (int (*)(CPXCENVptr, CPXLPptr, int const *, int const *, double const *, double const *, double const *, double const *)) dlsym(h, "CPXScopystart");
            CPXXcreateprob = (CPXLPptr (*)(CPXCENVptr, int *, char const *)) dlsym(h, "CPXScreateprob");
            CPXXfreeprob = (int (*)(CPXCENVptr, CPXLPptr *)) dlsym(h, "CPXSfreeprob");
            CPXXgetbase = (int (*)(CPXCENVptr, CPXCLPptr, int *, int *)) dlsym(h, "CPXSgetbase");
            CPXXgeterrorstring = (CPXCCHARptr (*)(CPXCENVptr, int, char *)) dlsym(h, "CPXSgeterrorstring");
            CPXXgetnumcols = (CPXDIM (*)(CPXCENVptr, CPXCLPptr)) dlsym(h, "CPXSgetnumcols");
            CPXXgetnumrows = (CPXDIM (*)(CPXCENVptr, CPXCLPptr)) dlsym(h, "CPXSgetnumrows");
            CPXXgetobjval = (int (*)(CPXCENVptr, CPXCLPptr, double *)) dlsym(h, "CPXSgetobjval");
            CPXXgetparamnum = (int (*)(CPXCENVptr, char const *, int *)) dlsym(h, "CPXSgetparamnum");
            CPXXgetparamtype = (int (*)(CPXCENVptr, int, int *)) dlsym(h, "CPXSgetparamtype");
            CPXXgetprobtype = (int (*)(CPXCENVptr, CPXCLPptr)) dlsym(h, "CPXSgetprobtype");
            CPXXgetslack = (int (*)(CPXCENVptr, CPXCLPptr, double *, CPXDIM, CPXDIM)) dlsym(h, "CPXSgetslack");
            CPXXgetstat = (int (*)(CPXCENVptr, CPXCLPptr)) dlsym(h, "CPXSgetstat");
            CPXXgetstatstring = (CPXCHARptr (*)(CPXCENVptr, int, char *)) dlsym(h, "CPXSgetstatstring");
            CPXXgetx = (int (*)(CPXCENVptr, CPXCLPptr, double *, CPXDIM, CPXDIM)) dlsym(h, "CPXSgetx");
            CPXXmipopt = (int (*)(CPXCENVptr, CPXLPptr)) dlsym(h, "CPXSmipopt");
            CPXXnewcols = (int (*)(CPXCENVptr, CPXLPptr, CPXDIM, double const *, double const *, double const *, char const *, char const *const *)) dlsym(h, "CPXSnewcols");
            CPXXopenCPLEX = (CPXENVptr (*)(int *)) dlsym(h, "CPXSopenCPLEX");
            CPXXqpopt = (int (*)(CPXCENVptr, CPXLPptr)) dlsym(h, "CPXSqpopt");
            CPXXsetdblparam = (int (*)(CPXENVptr, int, double)) dlsym(h, "CPXSsetdblparam");
            CPXXsetdefaults = (int (*)(CPXENVptr)) dlsym(h, "CPXSsetdefaults");
            CPXXsetintparam = (int (*)(CPXENVptr, int, CPXINT)) dlsym(h, "CPXSsetintparam");
            CPXXsetlongparam = (int (*)(CPXENVptr, int, CPXLONG)) dlsym(h, "CPXSsetlongparam");
            CPXXsetstrparam = (int (*)(CPXENVptr, int, char const *)) dlsym(h, "CPXSsetstrparam");
            CPXXsolution = (int (*)(CPXCENVptr, CPXCLPptr, int *, double *, double *, double *, double *, double *)) dlsym(h, "CPXSsolution");
            CPXXwriteprob = (int (*)(CPXCENVptr, CPXCLPptr, char const *, char const *)) dlsym(h, "CPXSwriteprob");
#endif

      #endif // _WIN32
      
      return 0;
    } else {
      sprintf(err_msg, "Could not find library '%s'", buffer);
      return 1;
    }
  }
  