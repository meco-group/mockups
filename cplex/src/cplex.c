
#define DLL_IMPLEMENTATION
#include "ilcplex/cplexx.h"

#include <stdlib.h>
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

  
  #if defined(_WIN32)
  static HINSTANCE h;
  #else
  void * h;
  #endif
  
  void cplex_adaptor_unload() {
    if (h) {
        #if defined(_WIN32)
        FreeLibray(h);
        #elif defined(__APPLE__)
        dlclose(h);
        #endif
    }
  }
  int cplex_adaptor_load(char* err_msg, unsigned int err_msg_len) {
  
    const char* suffix = getenv("CPLEX_VERSION");
    
    #if defined(_WIN32)
    const char library_suffix[] = "dll";
    const char path_env[] = "PATH";
    #elif defined(__APPLE__)
    const char library_suffix[] = "dylib";
    const char path_env[] = "DYLD_LIBRARY_PATH";
    #else
    const char library_suffix[] = "so";
    const char path_env[] = "LD_LIBRARY_PATH";
    #endif
    
    
    if (suffix==NULL) {
        snprintf(err_msg, err_msg_len, "CPLEX load adaptor needs an environmental variable <CPLEX_VERSION> "
        "such that libcplex<CPLEX_VERSION>.%s can be found.", library_suffix);
        return 1;
    }

    char buffer[100];
    
    snprintf(buffer, 100, "libcplex%s.%s", suffix, library_suffix);

    #if defined(_WIN32)
    h = LoadLibrary(TEXT(buffer));
    #elif defined(__APPLE__)
    h = dlopen(buffer, RTLD_LAZY | RTLD_LOCAL);
    #else
    h = dlopen(buffer, RTLD_LAZY | RTLD_LOCAL | RTLD_DEEPBIND);
    #endif
    
    if (h) {
      #ifdef _WIN32
#if CPX_APIMODEL == CPX_APIMODEL_LARGE
            CPXXaddmipstarts = (int (*)(CPXCENVptr, CPXLPptr, int, CPXNNZ, CPXNNZ const *, CPXDIM const *, double const *, int const *, char const *const *)) GetProcAddress(h, "CPXLaddmipstarts");
            if (CPXXaddmipstarts==NULL) { snprintf(err_msg, err_msg_len, "Could not find symbol 'CPXLaddmipstarts' in libcplex%s.%s", suffix, library_suffix); return 2; };
            CPXXaddqconstr = (int (*)(CPXCENVptr, CPXLPptr, CPXDIM, CPXNNZ, double, int, CPXDIM const *, double const *, CPXDIM const *, CPXDIM const *, double const *, char const *)) GetProcAddress(h, "CPXLaddqconstr");
            if (CPXXaddqconstr==NULL) { snprintf(err_msg, err_msg_len, "Could not find symbol 'CPXLaddqconstr' in libcplex%s.%s", suffix, library_suffix); return 2; };
            CPXXaddrows = (int (*)(CPXCENVptr, CPXLPptr, CPXDIM, CPXDIM, CPXNNZ, double const *, char const *, CPXNNZ const *, CPXDIM const *, double const *, char const *const *, char const *const *)) GetProcAddress(h, "CPXLaddrows");
            if (CPXXaddrows==NULL) { snprintf(err_msg, err_msg_len, "Could not find symbol 'CPXLaddrows' in libcplex%s.%s", suffix, library_suffix); return 2; };
            CPXXaddsos = (int (*)(CPXCENVptr, CPXLPptr, CPXDIM, CPXNNZ, char const *, CPXNNZ const *, CPXDIM const *, double const *, char const *const *)) GetProcAddress(h, "CPXLaddsos");
            if (CPXXaddsos==NULL) { snprintf(err_msg, err_msg_len, "Could not find symbol 'CPXLaddsos' in libcplex%s.%s", suffix, library_suffix); return 2; };
            CPXXcloseCPLEX = (int (*)(CPXENVptr *)) GetProcAddress(h, "CPXLcloseCPLEX");
            if (CPXXcloseCPLEX==NULL) { snprintf(err_msg, err_msg_len, "Could not find symbol 'CPXLcloseCPLEX' in libcplex%s.%s", suffix, library_suffix); return 2; };
            CPXXcopyctype = (int (*)(CPXCENVptr, CPXLPptr, char const *)) GetProcAddress(h, "CPXLcopyctype");
            if (CPXXcopyctype==NULL) { snprintf(err_msg, err_msg_len, "Could not find symbol 'CPXLcopyctype' in libcplex%s.%s", suffix, library_suffix); return 2; };
            CPXXcopylp = (int (*)(CPXCENVptr, CPXLPptr, CPXDIM, CPXDIM, int, double const *, double const *, char const *, CPXNNZ const *, CPXDIM const *, CPXDIM const *, double const *, double const *, double const *, double const *)) GetProcAddress(h, "CPXLcopylp");
            if (CPXXcopylp==NULL) { snprintf(err_msg, err_msg_len, "Could not find symbol 'CPXLcopylp' in libcplex%s.%s", suffix, library_suffix); return 2; };
            CPXXcopyquad = (int (*)(CPXCENVptr, CPXLPptr, CPXNNZ const *, CPXDIM const *, CPXDIM const *, double const *)) GetProcAddress(h, "CPXLcopyquad");
            if (CPXXcopyquad==NULL) { snprintf(err_msg, err_msg_len, "Could not find symbol 'CPXLcopyquad' in libcplex%s.%s", suffix, library_suffix); return 2; };
            CPXXcopystart = (int (*)(CPXCENVptr, CPXLPptr, int const *, int const *, double const *, double const *, double const *, double const *)) GetProcAddress(h, "CPXLcopystart");
            if (CPXXcopystart==NULL) { snprintf(err_msg, err_msg_len, "Could not find symbol 'CPXLcopystart' in libcplex%s.%s", suffix, library_suffix); return 2; };
            CPXXcreateprob = (CPXLPptr (*)(CPXCENVptr, int *, char const *)) GetProcAddress(h, "CPXLcreateprob");
            if (CPXXcreateprob==NULL) { snprintf(err_msg, err_msg_len, "Could not find symbol 'CPXLcreateprob' in libcplex%s.%s", suffix, library_suffix); return 2; };
            CPXXfreeprob = (int (*)(CPXCENVptr, CPXLPptr *)) GetProcAddress(h, "CPXLfreeprob");
            if (CPXXfreeprob==NULL) { snprintf(err_msg, err_msg_len, "Could not find symbol 'CPXLfreeprob' in libcplex%s.%s", suffix, library_suffix); return 2; };
            CPXXgetbase = (int (*)(CPXCENVptr, CPXCLPptr, int *, int *)) GetProcAddress(h, "CPXLgetbase");
            if (CPXXgetbase==NULL) { snprintf(err_msg, err_msg_len, "Could not find symbol 'CPXLgetbase' in libcplex%s.%s", suffix, library_suffix); return 2; };
            CPXXgeterrorstring = (CPXCCHARptr (*)(CPXCENVptr, int, char *)) GetProcAddress(h, "CPXLgeterrorstring");
            if (CPXXgeterrorstring==NULL) { snprintf(err_msg, err_msg_len, "Could not find symbol 'CPXLgeterrorstring' in libcplex%s.%s", suffix, library_suffix); return 2; };
            CPXXgetnumcols = (CPXDIM (*)(CPXCENVptr, CPXCLPptr)) GetProcAddress(h, "CPXLgetnumcols");
            if (CPXXgetnumcols==NULL) { snprintf(err_msg, err_msg_len, "Could not find symbol 'CPXLgetnumcols' in libcplex%s.%s", suffix, library_suffix); return 2; };
            CPXXgetnumrows = (CPXDIM (*)(CPXCENVptr, CPXCLPptr)) GetProcAddress(h, "CPXLgetnumrows");
            if (CPXXgetnumrows==NULL) { snprintf(err_msg, err_msg_len, "Could not find symbol 'CPXLgetnumrows' in libcplex%s.%s", suffix, library_suffix); return 2; };
            CPXXgetobjval = (int (*)(CPXCENVptr, CPXCLPptr, double *)) GetProcAddress(h, "CPXLgetobjval");
            if (CPXXgetobjval==NULL) { snprintf(err_msg, err_msg_len, "Could not find symbol 'CPXLgetobjval' in libcplex%s.%s", suffix, library_suffix); return 2; };
            CPXXgetparamnum = (int (*)(CPXCENVptr, char const *, int *)) GetProcAddress(h, "CPXLgetparamnum");
            if (CPXXgetparamnum==NULL) { snprintf(err_msg, err_msg_len, "Could not find symbol 'CPXLgetparamnum' in libcplex%s.%s", suffix, library_suffix); return 2; };
            CPXXgetparamtype = (int (*)(CPXCENVptr, int, int *)) GetProcAddress(h, "CPXLgetparamtype");
            if (CPXXgetparamtype==NULL) { snprintf(err_msg, err_msg_len, "Could not find symbol 'CPXLgetparamtype' in libcplex%s.%s", suffix, library_suffix); return 2; };
            CPXXgetprobtype = (int (*)(CPXCENVptr, CPXCLPptr)) GetProcAddress(h, "CPXLgetprobtype");
            if (CPXXgetprobtype==NULL) { snprintf(err_msg, err_msg_len, "Could not find symbol 'CPXLgetprobtype' in libcplex%s.%s", suffix, library_suffix); return 2; };
            CPXXgetslack = (int (*)(CPXCENVptr, CPXCLPptr, double *, CPXDIM, CPXDIM)) GetProcAddress(h, "CPXLgetslack");
            if (CPXXgetslack==NULL) { snprintf(err_msg, err_msg_len, "Could not find symbol 'CPXLgetslack' in libcplex%s.%s", suffix, library_suffix); return 2; };
            CPXXgetstat = (int (*)(CPXCENVptr, CPXCLPptr)) GetProcAddress(h, "CPXLgetstat");
            if (CPXXgetstat==NULL) { snprintf(err_msg, err_msg_len, "Could not find symbol 'CPXLgetstat' in libcplex%s.%s", suffix, library_suffix); return 2; };
            CPXXgetstatstring = (CPXCHARptr (*)(CPXCENVptr, int, char *)) GetProcAddress(h, "CPXLgetstatstring");
            if (CPXXgetstatstring==NULL) { snprintf(err_msg, err_msg_len, "Could not find symbol 'CPXLgetstatstring' in libcplex%s.%s", suffix, library_suffix); return 2; };
            CPXXgetx = (int (*)(CPXCENVptr, CPXCLPptr, double *, CPXDIM, CPXDIM)) GetProcAddress(h, "CPXLgetx");
            if (CPXXgetx==NULL) { snprintf(err_msg, err_msg_len, "Could not find symbol 'CPXLgetx' in libcplex%s.%s", suffix, library_suffix); return 2; };
            CPXXmipopt = (int (*)(CPXCENVptr, CPXLPptr)) GetProcAddress(h, "CPXLmipopt");
            if (CPXXmipopt==NULL) { snprintf(err_msg, err_msg_len, "Could not find symbol 'CPXLmipopt' in libcplex%s.%s", suffix, library_suffix); return 2; };
            CPXXnewcols = (int (*)(CPXCENVptr, CPXLPptr, CPXDIM, double const *, double const *, double const *, char const *, char const *const *)) GetProcAddress(h, "CPXLnewcols");
            if (CPXXnewcols==NULL) { snprintf(err_msg, err_msg_len, "Could not find symbol 'CPXLnewcols' in libcplex%s.%s", suffix, library_suffix); return 2; };
            CPXXopenCPLEX = (CPXENVptr (*)(int *)) GetProcAddress(h, "CPXLopenCPLEX");
            if (CPXXopenCPLEX==NULL) { snprintf(err_msg, err_msg_len, "Could not find symbol 'CPXLopenCPLEX' in libcplex%s.%s", suffix, library_suffix); return 2; };
            CPXXqpopt = (int (*)(CPXCENVptr, CPXLPptr)) GetProcAddress(h, "CPXLqpopt");
            if (CPXXqpopt==NULL) { snprintf(err_msg, err_msg_len, "Could not find symbol 'CPXLqpopt' in libcplex%s.%s", suffix, library_suffix); return 2; };
            CPXXsetdblparam = (int (*)(CPXENVptr, int, double)) GetProcAddress(h, "CPXLsetdblparam");
            if (CPXXsetdblparam==NULL) { snprintf(err_msg, err_msg_len, "Could not find symbol 'CPXLsetdblparam' in libcplex%s.%s", suffix, library_suffix); return 2; };
            CPXXsetdefaults = (int (*)(CPXENVptr)) GetProcAddress(h, "CPXLsetdefaults");
            if (CPXXsetdefaults==NULL) { snprintf(err_msg, err_msg_len, "Could not find symbol 'CPXLsetdefaults' in libcplex%s.%s", suffix, library_suffix); return 2; };
            CPXXsetintparam = (int (*)(CPXENVptr, int, CPXINT)) GetProcAddress(h, "CPXLsetintparam");
            if (CPXXsetintparam==NULL) { snprintf(err_msg, err_msg_len, "Could not find symbol 'CPXLsetintparam' in libcplex%s.%s", suffix, library_suffix); return 2; };
            CPXXsetlongparam = (int (*)(CPXENVptr, int, CPXLONG)) GetProcAddress(h, "CPXLsetlongparam");
            if (CPXXsetlongparam==NULL) { snprintf(err_msg, err_msg_len, "Could not find symbol 'CPXLsetlongparam' in libcplex%s.%s", suffix, library_suffix); return 2; };
            CPXXsetstrparam = (int (*)(CPXENVptr, int, char const *)) GetProcAddress(h, "CPXLsetstrparam");
            if (CPXXsetstrparam==NULL) { snprintf(err_msg, err_msg_len, "Could not find symbol 'CPXLsetstrparam' in libcplex%s.%s", suffix, library_suffix); return 2; };
            CPXXsolution = (int (*)(CPXCENVptr, CPXCLPptr, int *, double *, double *, double *, double *, double *)) GetProcAddress(h, "CPXLsolution");
            if (CPXXsolution==NULL) { snprintf(err_msg, err_msg_len, "Could not find symbol 'CPXLsolution' in libcplex%s.%s", suffix, library_suffix); return 2; };
            CPXXwriteprob = (int (*)(CPXCENVptr, CPXCLPptr, char const *, char const *)) GetProcAddress(h, "CPXLwriteprob");
            if (CPXXwriteprob==NULL) { snprintf(err_msg, err_msg_len, "Could not find symbol 'CPXLwriteprob' in libcplex%s.%s", suffix, library_suffix); return 2; };
#endif
#if CPX_APIMODEL == CPX_APIMODEL_SMALL
            CPXXaddmipstarts = (int (*)(CPXCENVptr, CPXLPptr, int, CPXNNZ, CPXNNZ const *, CPXDIM const *, double const *, int const *, char const *const *)) GetProcAddress(h, "CPXSaddmipstarts");
            if (CPXXaddmipstarts==NULL) { snprintf(err_msg, err_msg_len, "Could not find symbol 'CPXSaddmipstarts' in libcplex%s.%s", suffix, library_suffix); return 2; };
            CPXXaddqconstr = (int (*)(CPXCENVptr, CPXLPptr, CPXDIM, CPXNNZ, double, int, CPXDIM const *, double const *, CPXDIM const *, CPXDIM const *, double const *, char const *)) GetProcAddress(h, "CPXSaddqconstr");
            if (CPXXaddqconstr==NULL) { snprintf(err_msg, err_msg_len, "Could not find symbol 'CPXSaddqconstr' in libcplex%s.%s", suffix, library_suffix); return 2; };
            CPXXaddrows = (int (*)(CPXCENVptr, CPXLPptr, CPXDIM, CPXDIM, CPXNNZ, double const *, char const *, CPXNNZ const *, CPXDIM const *, double const *, char const *const *, char const *const *)) GetProcAddress(h, "CPXSaddrows");
            if (CPXXaddrows==NULL) { snprintf(err_msg, err_msg_len, "Could not find symbol 'CPXSaddrows' in libcplex%s.%s", suffix, library_suffix); return 2; };
            CPXXaddsos = (int (*)(CPXCENVptr, CPXLPptr, CPXDIM, CPXNNZ, char const *, CPXNNZ const *, CPXDIM const *, double const *, char const *const *)) GetProcAddress(h, "CPXSaddsos");
            if (CPXXaddsos==NULL) { snprintf(err_msg, err_msg_len, "Could not find symbol 'CPXSaddsos' in libcplex%s.%s", suffix, library_suffix); return 2; };
            CPXXcloseCPLEX = (int (*)(CPXENVptr *)) GetProcAddress(h, "CPXScloseCPLEX");
            if (CPXXcloseCPLEX==NULL) { snprintf(err_msg, err_msg_len, "Could not find symbol 'CPXScloseCPLEX' in libcplex%s.%s", suffix, library_suffix); return 2; };
            CPXXcopyctype = (int (*)(CPXCENVptr, CPXLPptr, char const *)) GetProcAddress(h, "CPXScopyctype");
            if (CPXXcopyctype==NULL) { snprintf(err_msg, err_msg_len, "Could not find symbol 'CPXScopyctype' in libcplex%s.%s", suffix, library_suffix); return 2; };
            CPXXcopylp = (int (*)(CPXCENVptr, CPXLPptr, CPXDIM, CPXDIM, int, double const *, double const *, char const *, CPXNNZ const *, CPXDIM const *, CPXDIM const *, double const *, double const *, double const *, double const *)) GetProcAddress(h, "CPXScopylp");
            if (CPXXcopylp==NULL) { snprintf(err_msg, err_msg_len, "Could not find symbol 'CPXScopylp' in libcplex%s.%s", suffix, library_suffix); return 2; };
            CPXXcopyquad = (int (*)(CPXCENVptr, CPXLPptr, CPXNNZ const *, CPXDIM const *, CPXDIM const *, double const *)) GetProcAddress(h, "CPXScopyquad");
            if (CPXXcopyquad==NULL) { snprintf(err_msg, err_msg_len, "Could not find symbol 'CPXScopyquad' in libcplex%s.%s", suffix, library_suffix); return 2; };
            CPXXcopystart = (int (*)(CPXCENVptr, CPXLPptr, int const *, int const *, double const *, double const *, double const *, double const *)) GetProcAddress(h, "CPXScopystart");
            if (CPXXcopystart==NULL) { snprintf(err_msg, err_msg_len, "Could not find symbol 'CPXScopystart' in libcplex%s.%s", suffix, library_suffix); return 2; };
            CPXXcreateprob = (CPXLPptr (*)(CPXCENVptr, int *, char const *)) GetProcAddress(h, "CPXScreateprob");
            if (CPXXcreateprob==NULL) { snprintf(err_msg, err_msg_len, "Could not find symbol 'CPXScreateprob' in libcplex%s.%s", suffix, library_suffix); return 2; };
            CPXXfreeprob = (int (*)(CPXCENVptr, CPXLPptr *)) GetProcAddress(h, "CPXSfreeprob");
            if (CPXXfreeprob==NULL) { snprintf(err_msg, err_msg_len, "Could not find symbol 'CPXSfreeprob' in libcplex%s.%s", suffix, library_suffix); return 2; };
            CPXXgetbase = (int (*)(CPXCENVptr, CPXCLPptr, int *, int *)) GetProcAddress(h, "CPXSgetbase");
            if (CPXXgetbase==NULL) { snprintf(err_msg, err_msg_len, "Could not find symbol 'CPXSgetbase' in libcplex%s.%s", suffix, library_suffix); return 2; };
            CPXXgeterrorstring = (CPXCCHARptr (*)(CPXCENVptr, int, char *)) GetProcAddress(h, "CPXSgeterrorstring");
            if (CPXXgeterrorstring==NULL) { snprintf(err_msg, err_msg_len, "Could not find symbol 'CPXSgeterrorstring' in libcplex%s.%s", suffix, library_suffix); return 2; };
            CPXXgetnumcols = (CPXDIM (*)(CPXCENVptr, CPXCLPptr)) GetProcAddress(h, "CPXSgetnumcols");
            if (CPXXgetnumcols==NULL) { snprintf(err_msg, err_msg_len, "Could not find symbol 'CPXSgetnumcols' in libcplex%s.%s", suffix, library_suffix); return 2; };
            CPXXgetnumrows = (CPXDIM (*)(CPXCENVptr, CPXCLPptr)) GetProcAddress(h, "CPXSgetnumrows");
            if (CPXXgetnumrows==NULL) { snprintf(err_msg, err_msg_len, "Could not find symbol 'CPXSgetnumrows' in libcplex%s.%s", suffix, library_suffix); return 2; };
            CPXXgetobjval = (int (*)(CPXCENVptr, CPXCLPptr, double *)) GetProcAddress(h, "CPXSgetobjval");
            if (CPXXgetobjval==NULL) { snprintf(err_msg, err_msg_len, "Could not find symbol 'CPXSgetobjval' in libcplex%s.%s", suffix, library_suffix); return 2; };
            CPXXgetparamnum = (int (*)(CPXCENVptr, char const *, int *)) GetProcAddress(h, "CPXSgetparamnum");
            if (CPXXgetparamnum==NULL) { snprintf(err_msg, err_msg_len, "Could not find symbol 'CPXSgetparamnum' in libcplex%s.%s", suffix, library_suffix); return 2; };
            CPXXgetparamtype = (int (*)(CPXCENVptr, int, int *)) GetProcAddress(h, "CPXSgetparamtype");
            if (CPXXgetparamtype==NULL) { snprintf(err_msg, err_msg_len, "Could not find symbol 'CPXSgetparamtype' in libcplex%s.%s", suffix, library_suffix); return 2; };
            CPXXgetprobtype = (int (*)(CPXCENVptr, CPXCLPptr)) GetProcAddress(h, "CPXSgetprobtype");
            if (CPXXgetprobtype==NULL) { snprintf(err_msg, err_msg_len, "Could not find symbol 'CPXSgetprobtype' in libcplex%s.%s", suffix, library_suffix); return 2; };
            CPXXgetslack = (int (*)(CPXCENVptr, CPXCLPptr, double *, CPXDIM, CPXDIM)) GetProcAddress(h, "CPXSgetslack");
            if (CPXXgetslack==NULL) { snprintf(err_msg, err_msg_len, "Could not find symbol 'CPXSgetslack' in libcplex%s.%s", suffix, library_suffix); return 2; };
            CPXXgetstat = (int (*)(CPXCENVptr, CPXCLPptr)) GetProcAddress(h, "CPXSgetstat");
            if (CPXXgetstat==NULL) { snprintf(err_msg, err_msg_len, "Could not find symbol 'CPXSgetstat' in libcplex%s.%s", suffix, library_suffix); return 2; };
            CPXXgetstatstring = (CPXCHARptr (*)(CPXCENVptr, int, char *)) GetProcAddress(h, "CPXSgetstatstring");
            if (CPXXgetstatstring==NULL) { snprintf(err_msg, err_msg_len, "Could not find symbol 'CPXSgetstatstring' in libcplex%s.%s", suffix, library_suffix); return 2; };
            CPXXgetx = (int (*)(CPXCENVptr, CPXCLPptr, double *, CPXDIM, CPXDIM)) GetProcAddress(h, "CPXSgetx");
            if (CPXXgetx==NULL) { snprintf(err_msg, err_msg_len, "Could not find symbol 'CPXSgetx' in libcplex%s.%s", suffix, library_suffix); return 2; };
            CPXXmipopt = (int (*)(CPXCENVptr, CPXLPptr)) GetProcAddress(h, "CPXSmipopt");
            if (CPXXmipopt==NULL) { snprintf(err_msg, err_msg_len, "Could not find symbol 'CPXSmipopt' in libcplex%s.%s", suffix, library_suffix); return 2; };
            CPXXnewcols = (int (*)(CPXCENVptr, CPXLPptr, CPXDIM, double const *, double const *, double const *, char const *, char const *const *)) GetProcAddress(h, "CPXSnewcols");
            if (CPXXnewcols==NULL) { snprintf(err_msg, err_msg_len, "Could not find symbol 'CPXSnewcols' in libcplex%s.%s", suffix, library_suffix); return 2; };
            CPXXopenCPLEX = (CPXENVptr (*)(int *)) GetProcAddress(h, "CPXSopenCPLEX");
            if (CPXXopenCPLEX==NULL) { snprintf(err_msg, err_msg_len, "Could not find symbol 'CPXSopenCPLEX' in libcplex%s.%s", suffix, library_suffix); return 2; };
            CPXXqpopt = (int (*)(CPXCENVptr, CPXLPptr)) GetProcAddress(h, "CPXSqpopt");
            if (CPXXqpopt==NULL) { snprintf(err_msg, err_msg_len, "Could not find symbol 'CPXSqpopt' in libcplex%s.%s", suffix, library_suffix); return 2; };
            CPXXsetdblparam = (int (*)(CPXENVptr, int, double)) GetProcAddress(h, "CPXSsetdblparam");
            if (CPXXsetdblparam==NULL) { snprintf(err_msg, err_msg_len, "Could not find symbol 'CPXSsetdblparam' in libcplex%s.%s", suffix, library_suffix); return 2; };
            CPXXsetdefaults = (int (*)(CPXENVptr)) GetProcAddress(h, "CPXSsetdefaults");
            if (CPXXsetdefaults==NULL) { snprintf(err_msg, err_msg_len, "Could not find symbol 'CPXSsetdefaults' in libcplex%s.%s", suffix, library_suffix); return 2; };
            CPXXsetintparam = (int (*)(CPXENVptr, int, CPXINT)) GetProcAddress(h, "CPXSsetintparam");
            if (CPXXsetintparam==NULL) { snprintf(err_msg, err_msg_len, "Could not find symbol 'CPXSsetintparam' in libcplex%s.%s", suffix, library_suffix); return 2; };
            CPXXsetlongparam = (int (*)(CPXENVptr, int, CPXLONG)) GetProcAddress(h, "CPXSsetlongparam");
            if (CPXXsetlongparam==NULL) { snprintf(err_msg, err_msg_len, "Could not find symbol 'CPXSsetlongparam' in libcplex%s.%s", suffix, library_suffix); return 2; };
            CPXXsetstrparam = (int (*)(CPXENVptr, int, char const *)) GetProcAddress(h, "CPXSsetstrparam");
            if (CPXXsetstrparam==NULL) { snprintf(err_msg, err_msg_len, "Could not find symbol 'CPXSsetstrparam' in libcplex%s.%s", suffix, library_suffix); return 2; };
            CPXXsolution = (int (*)(CPXCENVptr, CPXCLPptr, int *, double *, double *, double *, double *, double *)) GetProcAddress(h, "CPXSsolution");
            if (CPXXsolution==NULL) { snprintf(err_msg, err_msg_len, "Could not find symbol 'CPXSsolution' in libcplex%s.%s", suffix, library_suffix); return 2; };
            CPXXwriteprob = (int (*)(CPXCENVptr, CPXCLPptr, char const *, char const *)) GetProcAddress(h, "CPXSwriteprob");
            if (CPXXwriteprob==NULL) { snprintf(err_msg, err_msg_len, "Could not find symbol 'CPXSwriteprob' in libcplex%s.%s", suffix, library_suffix); return 2; };
#endif

      #else // _WIN32
  #if CPX_APIMODEL == CPX_APIMODEL_LARGE
            CPXXaddmipstarts = (int (*)(CPXCENVptr, CPXLPptr, int, CPXNNZ, CPXNNZ const *, CPXDIM const *, double const *, int const *, char const *const *)) dlsym(h, "CPXLaddmipstarts");
            if (CPXXaddmipstarts==NULL) { snprintf(err_msg, err_msg_len, "Could not find symbol 'CPXLaddmipstarts' in libcplex%s.%s", suffix, library_suffix); return 2; };
            CPXXaddqconstr = (int (*)(CPXCENVptr, CPXLPptr, CPXDIM, CPXNNZ, double, int, CPXDIM const *, double const *, CPXDIM const *, CPXDIM const *, double const *, char const *)) dlsym(h, "CPXLaddqconstr");
            if (CPXXaddqconstr==NULL) { snprintf(err_msg, err_msg_len, "Could not find symbol 'CPXLaddqconstr' in libcplex%s.%s", suffix, library_suffix); return 2; };
            CPXXaddrows = (int (*)(CPXCENVptr, CPXLPptr, CPXDIM, CPXDIM, CPXNNZ, double const *, char const *, CPXNNZ const *, CPXDIM const *, double const *, char const *const *, char const *const *)) dlsym(h, "CPXLaddrows");
            if (CPXXaddrows==NULL) { snprintf(err_msg, err_msg_len, "Could not find symbol 'CPXLaddrows' in libcplex%s.%s", suffix, library_suffix); return 2; };
            CPXXaddsos = (int (*)(CPXCENVptr, CPXLPptr, CPXDIM, CPXNNZ, char const *, CPXNNZ const *, CPXDIM const *, double const *, char const *const *)) dlsym(h, "CPXLaddsos");
            if (CPXXaddsos==NULL) { snprintf(err_msg, err_msg_len, "Could not find symbol 'CPXLaddsos' in libcplex%s.%s", suffix, library_suffix); return 2; };
            CPXXcloseCPLEX = (int (*)(CPXENVptr *)) dlsym(h, "CPXLcloseCPLEX");
            if (CPXXcloseCPLEX==NULL) { snprintf(err_msg, err_msg_len, "Could not find symbol 'CPXLcloseCPLEX' in libcplex%s.%s", suffix, library_suffix); return 2; };
            CPXXcopyctype = (int (*)(CPXCENVptr, CPXLPptr, char const *)) dlsym(h, "CPXLcopyctype");
            if (CPXXcopyctype==NULL) { snprintf(err_msg, err_msg_len, "Could not find symbol 'CPXLcopyctype' in libcplex%s.%s", suffix, library_suffix); return 2; };
            CPXXcopylp = (int (*)(CPXCENVptr, CPXLPptr, CPXDIM, CPXDIM, int, double const *, double const *, char const *, CPXNNZ const *, CPXDIM const *, CPXDIM const *, double const *, double const *, double const *, double const *)) dlsym(h, "CPXLcopylp");
            if (CPXXcopylp==NULL) { snprintf(err_msg, err_msg_len, "Could not find symbol 'CPXLcopylp' in libcplex%s.%s", suffix, library_suffix); return 2; };
            CPXXcopyquad = (int (*)(CPXCENVptr, CPXLPptr, CPXNNZ const *, CPXDIM const *, CPXDIM const *, double const *)) dlsym(h, "CPXLcopyquad");
            if (CPXXcopyquad==NULL) { snprintf(err_msg, err_msg_len, "Could not find symbol 'CPXLcopyquad' in libcplex%s.%s", suffix, library_suffix); return 2; };
            CPXXcopystart = (int (*)(CPXCENVptr, CPXLPptr, int const *, int const *, double const *, double const *, double const *, double const *)) dlsym(h, "CPXLcopystart");
            if (CPXXcopystart==NULL) { snprintf(err_msg, err_msg_len, "Could not find symbol 'CPXLcopystart' in libcplex%s.%s", suffix, library_suffix); return 2; };
            CPXXcreateprob = (CPXLPptr (*)(CPXCENVptr, int *, char const *)) dlsym(h, "CPXLcreateprob");
            if (CPXXcreateprob==NULL) { snprintf(err_msg, err_msg_len, "Could not find symbol 'CPXLcreateprob' in libcplex%s.%s", suffix, library_suffix); return 2; };
            CPXXfreeprob = (int (*)(CPXCENVptr, CPXLPptr *)) dlsym(h, "CPXLfreeprob");
            if (CPXXfreeprob==NULL) { snprintf(err_msg, err_msg_len, "Could not find symbol 'CPXLfreeprob' in libcplex%s.%s", suffix, library_suffix); return 2; };
            CPXXgetbase = (int (*)(CPXCENVptr, CPXCLPptr, int *, int *)) dlsym(h, "CPXLgetbase");
            if (CPXXgetbase==NULL) { snprintf(err_msg, err_msg_len, "Could not find symbol 'CPXLgetbase' in libcplex%s.%s", suffix, library_suffix); return 2; };
            CPXXgeterrorstring = (CPXCCHARptr (*)(CPXCENVptr, int, char *)) dlsym(h, "CPXLgeterrorstring");
            if (CPXXgeterrorstring==NULL) { snprintf(err_msg, err_msg_len, "Could not find symbol 'CPXLgeterrorstring' in libcplex%s.%s", suffix, library_suffix); return 2; };
            CPXXgetnumcols = (CPXDIM (*)(CPXCENVptr, CPXCLPptr)) dlsym(h, "CPXLgetnumcols");
            if (CPXXgetnumcols==NULL) { snprintf(err_msg, err_msg_len, "Could not find symbol 'CPXLgetnumcols' in libcplex%s.%s", suffix, library_suffix); return 2; };
            CPXXgetnumrows = (CPXDIM (*)(CPXCENVptr, CPXCLPptr)) dlsym(h, "CPXLgetnumrows");
            if (CPXXgetnumrows==NULL) { snprintf(err_msg, err_msg_len, "Could not find symbol 'CPXLgetnumrows' in libcplex%s.%s", suffix, library_suffix); return 2; };
            CPXXgetobjval = (int (*)(CPXCENVptr, CPXCLPptr, double *)) dlsym(h, "CPXLgetobjval");
            if (CPXXgetobjval==NULL) { snprintf(err_msg, err_msg_len, "Could not find symbol 'CPXLgetobjval' in libcplex%s.%s", suffix, library_suffix); return 2; };
            CPXXgetparamnum = (int (*)(CPXCENVptr, char const *, int *)) dlsym(h, "CPXLgetparamnum");
            if (CPXXgetparamnum==NULL) { snprintf(err_msg, err_msg_len, "Could not find symbol 'CPXLgetparamnum' in libcplex%s.%s", suffix, library_suffix); return 2; };
            CPXXgetparamtype = (int (*)(CPXCENVptr, int, int *)) dlsym(h, "CPXLgetparamtype");
            if (CPXXgetparamtype==NULL) { snprintf(err_msg, err_msg_len, "Could not find symbol 'CPXLgetparamtype' in libcplex%s.%s", suffix, library_suffix); return 2; };
            CPXXgetprobtype = (int (*)(CPXCENVptr, CPXCLPptr)) dlsym(h, "CPXLgetprobtype");
            if (CPXXgetprobtype==NULL) { snprintf(err_msg, err_msg_len, "Could not find symbol 'CPXLgetprobtype' in libcplex%s.%s", suffix, library_suffix); return 2; };
            CPXXgetslack = (int (*)(CPXCENVptr, CPXCLPptr, double *, CPXDIM, CPXDIM)) dlsym(h, "CPXLgetslack");
            if (CPXXgetslack==NULL) { snprintf(err_msg, err_msg_len, "Could not find symbol 'CPXLgetslack' in libcplex%s.%s", suffix, library_suffix); return 2; };
            CPXXgetstat = (int (*)(CPXCENVptr, CPXCLPptr)) dlsym(h, "CPXLgetstat");
            if (CPXXgetstat==NULL) { snprintf(err_msg, err_msg_len, "Could not find symbol 'CPXLgetstat' in libcplex%s.%s", suffix, library_suffix); return 2; };
            CPXXgetstatstring = (CPXCHARptr (*)(CPXCENVptr, int, char *)) dlsym(h, "CPXLgetstatstring");
            if (CPXXgetstatstring==NULL) { snprintf(err_msg, err_msg_len, "Could not find symbol 'CPXLgetstatstring' in libcplex%s.%s", suffix, library_suffix); return 2; };
            CPXXgetx = (int (*)(CPXCENVptr, CPXCLPptr, double *, CPXDIM, CPXDIM)) dlsym(h, "CPXLgetx");
            if (CPXXgetx==NULL) { snprintf(err_msg, err_msg_len, "Could not find symbol 'CPXLgetx' in libcplex%s.%s", suffix, library_suffix); return 2; };
            CPXXmipopt = (int (*)(CPXCENVptr, CPXLPptr)) dlsym(h, "CPXLmipopt");
            if (CPXXmipopt==NULL) { snprintf(err_msg, err_msg_len, "Could not find symbol 'CPXLmipopt' in libcplex%s.%s", suffix, library_suffix); return 2; };
            CPXXnewcols = (int (*)(CPXCENVptr, CPXLPptr, CPXDIM, double const *, double const *, double const *, char const *, char const *const *)) dlsym(h, "CPXLnewcols");
            if (CPXXnewcols==NULL) { snprintf(err_msg, err_msg_len, "Could not find symbol 'CPXLnewcols' in libcplex%s.%s", suffix, library_suffix); return 2; };
            CPXXopenCPLEX = (CPXENVptr (*)(int *)) dlsym(h, "CPXLopenCPLEX");
            if (CPXXopenCPLEX==NULL) { snprintf(err_msg, err_msg_len, "Could not find symbol 'CPXLopenCPLEX' in libcplex%s.%s", suffix, library_suffix); return 2; };
            CPXXqpopt = (int (*)(CPXCENVptr, CPXLPptr)) dlsym(h, "CPXLqpopt");
            if (CPXXqpopt==NULL) { snprintf(err_msg, err_msg_len, "Could not find symbol 'CPXLqpopt' in libcplex%s.%s", suffix, library_suffix); return 2; };
            CPXXsetdblparam = (int (*)(CPXENVptr, int, double)) dlsym(h, "CPXLsetdblparam");
            if (CPXXsetdblparam==NULL) { snprintf(err_msg, err_msg_len, "Could not find symbol 'CPXLsetdblparam' in libcplex%s.%s", suffix, library_suffix); return 2; };
            CPXXsetdefaults = (int (*)(CPXENVptr)) dlsym(h, "CPXLsetdefaults");
            if (CPXXsetdefaults==NULL) { snprintf(err_msg, err_msg_len, "Could not find symbol 'CPXLsetdefaults' in libcplex%s.%s", suffix, library_suffix); return 2; };
            CPXXsetintparam = (int (*)(CPXENVptr, int, CPXINT)) dlsym(h, "CPXLsetintparam");
            if (CPXXsetintparam==NULL) { snprintf(err_msg, err_msg_len, "Could not find symbol 'CPXLsetintparam' in libcplex%s.%s", suffix, library_suffix); return 2; };
            CPXXsetlongparam = (int (*)(CPXENVptr, int, CPXLONG)) dlsym(h, "CPXLsetlongparam");
            if (CPXXsetlongparam==NULL) { snprintf(err_msg, err_msg_len, "Could not find symbol 'CPXLsetlongparam' in libcplex%s.%s", suffix, library_suffix); return 2; };
            CPXXsetstrparam = (int (*)(CPXENVptr, int, char const *)) dlsym(h, "CPXLsetstrparam");
            if (CPXXsetstrparam==NULL) { snprintf(err_msg, err_msg_len, "Could not find symbol 'CPXLsetstrparam' in libcplex%s.%s", suffix, library_suffix); return 2; };
            CPXXsolution = (int (*)(CPXCENVptr, CPXCLPptr, int *, double *, double *, double *, double *, double *)) dlsym(h, "CPXLsolution");
            if (CPXXsolution==NULL) { snprintf(err_msg, err_msg_len, "Could not find symbol 'CPXLsolution' in libcplex%s.%s", suffix, library_suffix); return 2; };
            CPXXwriteprob = (int (*)(CPXCENVptr, CPXCLPptr, char const *, char const *)) dlsym(h, "CPXLwriteprob");
            if (CPXXwriteprob==NULL) { snprintf(err_msg, err_msg_len, "Could not find symbol 'CPXLwriteprob' in libcplex%s.%s", suffix, library_suffix); return 2; };
#endif
#if CPX_APIMODEL == CPX_APIMODEL_SMALL
            CPXXaddmipstarts = (int (*)(CPXCENVptr, CPXLPptr, int, CPXNNZ, CPXNNZ const *, CPXDIM const *, double const *, int const *, char const *const *)) dlsym(h, "CPXSaddmipstarts");
            if (CPXXaddmipstarts==NULL) { snprintf(err_msg, err_msg_len, "Could not find symbol 'CPXSaddmipstarts' in libcplex%s.%s", suffix, library_suffix); return 2; };
            CPXXaddqconstr = (int (*)(CPXCENVptr, CPXLPptr, CPXDIM, CPXNNZ, double, int, CPXDIM const *, double const *, CPXDIM const *, CPXDIM const *, double const *, char const *)) dlsym(h, "CPXSaddqconstr");
            if (CPXXaddqconstr==NULL) { snprintf(err_msg, err_msg_len, "Could not find symbol 'CPXSaddqconstr' in libcplex%s.%s", suffix, library_suffix); return 2; };
            CPXXaddrows = (int (*)(CPXCENVptr, CPXLPptr, CPXDIM, CPXDIM, CPXNNZ, double const *, char const *, CPXNNZ const *, CPXDIM const *, double const *, char const *const *, char const *const *)) dlsym(h, "CPXSaddrows");
            if (CPXXaddrows==NULL) { snprintf(err_msg, err_msg_len, "Could not find symbol 'CPXSaddrows' in libcplex%s.%s", suffix, library_suffix); return 2; };
            CPXXaddsos = (int (*)(CPXCENVptr, CPXLPptr, CPXDIM, CPXNNZ, char const *, CPXNNZ const *, CPXDIM const *, double const *, char const *const *)) dlsym(h, "CPXSaddsos");
            if (CPXXaddsos==NULL) { snprintf(err_msg, err_msg_len, "Could not find symbol 'CPXSaddsos' in libcplex%s.%s", suffix, library_suffix); return 2; };
            CPXXcloseCPLEX = (int (*)(CPXENVptr *)) dlsym(h, "CPXScloseCPLEX");
            if (CPXXcloseCPLEX==NULL) { snprintf(err_msg, err_msg_len, "Could not find symbol 'CPXScloseCPLEX' in libcplex%s.%s", suffix, library_suffix); return 2; };
            CPXXcopyctype = (int (*)(CPXCENVptr, CPXLPptr, char const *)) dlsym(h, "CPXScopyctype");
            if (CPXXcopyctype==NULL) { snprintf(err_msg, err_msg_len, "Could not find symbol 'CPXScopyctype' in libcplex%s.%s", suffix, library_suffix); return 2; };
            CPXXcopylp = (int (*)(CPXCENVptr, CPXLPptr, CPXDIM, CPXDIM, int, double const *, double const *, char const *, CPXNNZ const *, CPXDIM const *, CPXDIM const *, double const *, double const *, double const *, double const *)) dlsym(h, "CPXScopylp");
            if (CPXXcopylp==NULL) { snprintf(err_msg, err_msg_len, "Could not find symbol 'CPXScopylp' in libcplex%s.%s", suffix, library_suffix); return 2; };
            CPXXcopyquad = (int (*)(CPXCENVptr, CPXLPptr, CPXNNZ const *, CPXDIM const *, CPXDIM const *, double const *)) dlsym(h, "CPXScopyquad");
            if (CPXXcopyquad==NULL) { snprintf(err_msg, err_msg_len, "Could not find symbol 'CPXScopyquad' in libcplex%s.%s", suffix, library_suffix); return 2; };
            CPXXcopystart = (int (*)(CPXCENVptr, CPXLPptr, int const *, int const *, double const *, double const *, double const *, double const *)) dlsym(h, "CPXScopystart");
            if (CPXXcopystart==NULL) { snprintf(err_msg, err_msg_len, "Could not find symbol 'CPXScopystart' in libcplex%s.%s", suffix, library_suffix); return 2; };
            CPXXcreateprob = (CPXLPptr (*)(CPXCENVptr, int *, char const *)) dlsym(h, "CPXScreateprob");
            if (CPXXcreateprob==NULL) { snprintf(err_msg, err_msg_len, "Could not find symbol 'CPXScreateprob' in libcplex%s.%s", suffix, library_suffix); return 2; };
            CPXXfreeprob = (int (*)(CPXCENVptr, CPXLPptr *)) dlsym(h, "CPXSfreeprob");
            if (CPXXfreeprob==NULL) { snprintf(err_msg, err_msg_len, "Could not find symbol 'CPXSfreeprob' in libcplex%s.%s", suffix, library_suffix); return 2; };
            CPXXgetbase = (int (*)(CPXCENVptr, CPXCLPptr, int *, int *)) dlsym(h, "CPXSgetbase");
            if (CPXXgetbase==NULL) { snprintf(err_msg, err_msg_len, "Could not find symbol 'CPXSgetbase' in libcplex%s.%s", suffix, library_suffix); return 2; };
            CPXXgeterrorstring = (CPXCCHARptr (*)(CPXCENVptr, int, char *)) dlsym(h, "CPXSgeterrorstring");
            if (CPXXgeterrorstring==NULL) { snprintf(err_msg, err_msg_len, "Could not find symbol 'CPXSgeterrorstring' in libcplex%s.%s", suffix, library_suffix); return 2; };
            CPXXgetnumcols = (CPXDIM (*)(CPXCENVptr, CPXCLPptr)) dlsym(h, "CPXSgetnumcols");
            if (CPXXgetnumcols==NULL) { snprintf(err_msg, err_msg_len, "Could not find symbol 'CPXSgetnumcols' in libcplex%s.%s", suffix, library_suffix); return 2; };
            CPXXgetnumrows = (CPXDIM (*)(CPXCENVptr, CPXCLPptr)) dlsym(h, "CPXSgetnumrows");
            if (CPXXgetnumrows==NULL) { snprintf(err_msg, err_msg_len, "Could not find symbol 'CPXSgetnumrows' in libcplex%s.%s", suffix, library_suffix); return 2; };
            CPXXgetobjval = (int (*)(CPXCENVptr, CPXCLPptr, double *)) dlsym(h, "CPXSgetobjval");
            if (CPXXgetobjval==NULL) { snprintf(err_msg, err_msg_len, "Could not find symbol 'CPXSgetobjval' in libcplex%s.%s", suffix, library_suffix); return 2; };
            CPXXgetparamnum = (int (*)(CPXCENVptr, char const *, int *)) dlsym(h, "CPXSgetparamnum");
            if (CPXXgetparamnum==NULL) { snprintf(err_msg, err_msg_len, "Could not find symbol 'CPXSgetparamnum' in libcplex%s.%s", suffix, library_suffix); return 2; };
            CPXXgetparamtype = (int (*)(CPXCENVptr, int, int *)) dlsym(h, "CPXSgetparamtype");
            if (CPXXgetparamtype==NULL) { snprintf(err_msg, err_msg_len, "Could not find symbol 'CPXSgetparamtype' in libcplex%s.%s", suffix, library_suffix); return 2; };
            CPXXgetprobtype = (int (*)(CPXCENVptr, CPXCLPptr)) dlsym(h, "CPXSgetprobtype");
            if (CPXXgetprobtype==NULL) { snprintf(err_msg, err_msg_len, "Could not find symbol 'CPXSgetprobtype' in libcplex%s.%s", suffix, library_suffix); return 2; };
            CPXXgetslack = (int (*)(CPXCENVptr, CPXCLPptr, double *, CPXDIM, CPXDIM)) dlsym(h, "CPXSgetslack");
            if (CPXXgetslack==NULL) { snprintf(err_msg, err_msg_len, "Could not find symbol 'CPXSgetslack' in libcplex%s.%s", suffix, library_suffix); return 2; };
            CPXXgetstat = (int (*)(CPXCENVptr, CPXCLPptr)) dlsym(h, "CPXSgetstat");
            if (CPXXgetstat==NULL) { snprintf(err_msg, err_msg_len, "Could not find symbol 'CPXSgetstat' in libcplex%s.%s", suffix, library_suffix); return 2; };
            CPXXgetstatstring = (CPXCHARptr (*)(CPXCENVptr, int, char *)) dlsym(h, "CPXSgetstatstring");
            if (CPXXgetstatstring==NULL) { snprintf(err_msg, err_msg_len, "Could not find symbol 'CPXSgetstatstring' in libcplex%s.%s", suffix, library_suffix); return 2; };
            CPXXgetx = (int (*)(CPXCENVptr, CPXCLPptr, double *, CPXDIM, CPXDIM)) dlsym(h, "CPXSgetx");
            if (CPXXgetx==NULL) { snprintf(err_msg, err_msg_len, "Could not find symbol 'CPXSgetx' in libcplex%s.%s", suffix, library_suffix); return 2; };
            CPXXmipopt = (int (*)(CPXCENVptr, CPXLPptr)) dlsym(h, "CPXSmipopt");
            if (CPXXmipopt==NULL) { snprintf(err_msg, err_msg_len, "Could not find symbol 'CPXSmipopt' in libcplex%s.%s", suffix, library_suffix); return 2; };
            CPXXnewcols = (int (*)(CPXCENVptr, CPXLPptr, CPXDIM, double const *, double const *, double const *, char const *, char const *const *)) dlsym(h, "CPXSnewcols");
            if (CPXXnewcols==NULL) { snprintf(err_msg, err_msg_len, "Could not find symbol 'CPXSnewcols' in libcplex%s.%s", suffix, library_suffix); return 2; };
            CPXXopenCPLEX = (CPXENVptr (*)(int *)) dlsym(h, "CPXSopenCPLEX");
            if (CPXXopenCPLEX==NULL) { snprintf(err_msg, err_msg_len, "Could not find symbol 'CPXSopenCPLEX' in libcplex%s.%s", suffix, library_suffix); return 2; };
            CPXXqpopt = (int (*)(CPXCENVptr, CPXLPptr)) dlsym(h, "CPXSqpopt");
            if (CPXXqpopt==NULL) { snprintf(err_msg, err_msg_len, "Could not find symbol 'CPXSqpopt' in libcplex%s.%s", suffix, library_suffix); return 2; };
            CPXXsetdblparam = (int (*)(CPXENVptr, int, double)) dlsym(h, "CPXSsetdblparam");
            if (CPXXsetdblparam==NULL) { snprintf(err_msg, err_msg_len, "Could not find symbol 'CPXSsetdblparam' in libcplex%s.%s", suffix, library_suffix); return 2; };
            CPXXsetdefaults = (int (*)(CPXENVptr)) dlsym(h, "CPXSsetdefaults");
            if (CPXXsetdefaults==NULL) { snprintf(err_msg, err_msg_len, "Could not find symbol 'CPXSsetdefaults' in libcplex%s.%s", suffix, library_suffix); return 2; };
            CPXXsetintparam = (int (*)(CPXENVptr, int, CPXINT)) dlsym(h, "CPXSsetintparam");
            if (CPXXsetintparam==NULL) { snprintf(err_msg, err_msg_len, "Could not find symbol 'CPXSsetintparam' in libcplex%s.%s", suffix, library_suffix); return 2; };
            CPXXsetlongparam = (int (*)(CPXENVptr, int, CPXLONG)) dlsym(h, "CPXSsetlongparam");
            if (CPXXsetlongparam==NULL) { snprintf(err_msg, err_msg_len, "Could not find symbol 'CPXSsetlongparam' in libcplex%s.%s", suffix, library_suffix); return 2; };
            CPXXsetstrparam = (int (*)(CPXENVptr, int, char const *)) dlsym(h, "CPXSsetstrparam");
            if (CPXXsetstrparam==NULL) { snprintf(err_msg, err_msg_len, "Could not find symbol 'CPXSsetstrparam' in libcplex%s.%s", suffix, library_suffix); return 2; };
            CPXXsolution = (int (*)(CPXCENVptr, CPXCLPptr, int *, double *, double *, double *, double *, double *)) dlsym(h, "CPXSsolution");
            if (CPXXsolution==NULL) { snprintf(err_msg, err_msg_len, "Could not find symbol 'CPXSsolution' in libcplex%s.%s", suffix, library_suffix); return 2; };
            CPXXwriteprob = (int (*)(CPXCENVptr, CPXCLPptr, char const *, char const *)) dlsym(h, "CPXSwriteprob");
            if (CPXXwriteprob==NULL) { snprintf(err_msg, err_msg_len, "Could not find symbol 'CPXSwriteprob' in libcplex%s.%s", suffix, library_suffix); return 2; };
#endif

      #endif // _WIN32
      
      return 0;
    } else {
      snprintf(err_msg, err_msg_len, "Could not find library '%s'. "
        "Consider adding the appropriate cplex folder to environmental variable '%s'.", buffer, path_env);
      return 1;
    }
  }
  
