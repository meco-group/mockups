
#define DLL_IMPLEMENTATION
#include "cplex.h"

#ifdef _WIN32
#include <windows.h>
#else // _WIN32
#include <dlfcn.h>
#include <stddef.h>
#endif // _WIN32


int (*CPXLaddmipstarts)(CPXCENVptr, CPXLPptr, int, CPXLONG, CPXLONG const *, CPXINT const *, double const *, int const *, char const *const *) = NULL;
int (*CPXLaddqconstr)(CPXCENVptr, CPXLPptr, CPXINT, CPXLONG, double, int, CPXINT const *, double const *, CPXINT const *, CPXINT const *, double const *, char const *) = NULL;
int (*CPXLaddrows)(CPXCENVptr, CPXLPptr, CPXINT, CPXINT, CPXLONG, double const *, char const *, CPXLONG const *, CPXINT const *, double const *, char const *const *, char const *const *) = NULL;
int (*CPXLaddsos)(CPXCENVptr, CPXLPptr, CPXINT, CPXLONG, char const *, CPXLONG const *, CPXINT const *, double const *, char const *const *) = NULL;
int (*CPXLcloseCPLEX)(CPXENVptr *) = NULL;
int (*CPXLcopyctype)(CPXCENVptr, CPXLPptr, char const *) = NULL;
int (*CPXLcopylp)(CPXCENVptr, CPXLPptr, CPXINT, CPXINT, int, double const *, double const *, char const *, CPXLONG const *, CPXINT const *, CPXINT const *, double const *, double const *, double const *, double const *) = NULL;
int (*CPXLcopyquad)(CPXCENVptr, CPXLPptr, CPXLONG const *, CPXINT const *, CPXINT const *, double const *) = NULL;
int (*CPXLcopystart)(CPXCENVptr, CPXLPptr, int const *, int const *, double const *, double const *, double const *, double const *) = NULL;
CPXLPptr (*CPXLcreateprob)(CPXCENVptr, int *, char const *) = NULL;
int (*CPXLfreeprob)(CPXCENVptr, CPXLPptr *) = NULL;
int (*CPXLgetbase)(CPXCENVptr, CPXCLPptr, int *, int *) = NULL;
CPXCCHARptr (*CPXLgeterrorstring)(CPXCENVptr, int, char *) = NULL;
CPXINT (*CPXLgetnumcols)(CPXCENVptr, CPXCLPptr) = NULL;
CPXINT (*CPXLgetnumrows)(CPXCENVptr, CPXCLPptr) = NULL;
int (*CPXLgetobjval)(CPXCENVptr, CPXCLPptr, double *) = NULL;
int (*CPXLgetparamnum)(CPXCENVptr, char const *, int *) = NULL;
int (*CPXLgetparamtype)(CPXCENVptr, int, int *) = NULL;
int (*CPXLgetprobtype)(CPXCENVptr, CPXCLPptr) = NULL;
int (*CPXLgetslack)(CPXCENVptr, CPXCLPptr, double *, CPXINT, CPXINT) = NULL;
int (*CPXLgetstat)(CPXCENVptr, CPXCLPptr) = NULL;
CPXCHARptr (*CPXLgetstatstring)(CPXCENVptr, int, char *) = NULL;
int (*CPXLgetx)(CPXCENVptr, CPXCLPptr, double *, CPXINT, CPXINT) = NULL;
int (*CPXLmipopt)(CPXCENVptr, CPXLPptr) = NULL;
int (*CPXLnewcols)(CPXCENVptr, CPXLPptr, CPXINT, double const *, double const *, double const *, char const *, char const *const *) = NULL;
CPXENVptr (*CPXLopenCPLEX)(int *status_p) = NULL;
int (*CPXLqpopt)(CPXCENVptr, CPXLPptr) = NULL;
int (*CPXLsetdblparam)(CPXENVptr, int, double) = NULL;
int (*CPXLsetdefaults)(CPXENVptr) = NULL;
int (*CPXLsetintparam)(CPXENVptr, int, CPXINT) = NULL;
int (*CPXLsetlongparam)(CPXENVptr, int, CPXLONG) = NULL;
int (*CPXLsetstrparam)(CPXENVptr, int, char const *) = NULL;
int (*CPXLsolution)(CPXCENVptr, CPXCLPptr, int *, double *, double *, double *, double *, double *) = NULL;
int (*CPXLwriteprob)(CPXCENVptr, CPXCLPptr, char const *, char const *) = NULL;

  
  int cplex_adaptor_load(adaptor_handle_t handle) {
    #ifdef _WIN32
    HINSTANCE h = (HINSTANCE) handle;
    #else
    void * h = handle;
    #endif
    
    if (h != NULL) {
      #ifdef _WIN32
            CPXLaddmipstarts = (int (*)(CPXCENVptr, CPXLPptr, int, CPXLONG, CPXLONG const *, CPXINT const *, double const *, int const *, char const *const *)) GetProcAddress(h, "CPXLaddmipstarts");
            CPXLaddqconstr = (int (*)(CPXCENVptr, CPXLPptr, CPXINT, CPXLONG, double, int, CPXINT const *, double const *, CPXINT const *, CPXINT const *, double const *, char const *)) GetProcAddress(h, "CPXLaddqconstr");
            CPXLaddrows = (int (*)(CPXCENVptr, CPXLPptr, CPXINT, CPXINT, CPXLONG, double const *, char const *, CPXLONG const *, CPXINT const *, double const *, char const *const *, char const *const *)) GetProcAddress(h, "CPXLaddrows");
            CPXLaddsos = (int (*)(CPXCENVptr, CPXLPptr, CPXINT, CPXLONG, char const *, CPXLONG const *, CPXINT const *, double const *, char const *const *)) GetProcAddress(h, "CPXLaddsos");
            CPXLcloseCPLEX = (int (*)(CPXENVptr *)) GetProcAddress(h, "CPXLcloseCPLEX");
            CPXLcopyctype = (int (*)(CPXCENVptr, CPXLPptr, char const *)) GetProcAddress(h, "CPXLcopyctype");
            CPXLcopylp = (int (*)(CPXCENVptr, CPXLPptr, CPXINT, CPXINT, int, double const *, double const *, char const *, CPXLONG const *, CPXINT const *, CPXINT const *, double const *, double const *, double const *, double const *)) GetProcAddress(h, "CPXLcopylp");
            CPXLcopyquad = (int (*)(CPXCENVptr, CPXLPptr, CPXLONG const *, CPXINT const *, CPXINT const *, double const *)) GetProcAddress(h, "CPXLcopyquad");
            CPXLcopystart = (int (*)(CPXCENVptr, CPXLPptr, int const *, int const *, double const *, double const *, double const *, double const *)) GetProcAddress(h, "CPXLcopystart");
            CPXLcreateprob = (CPXLPptr (*)(CPXCENVptr, int *, char const *)) GetProcAddress(h, "CPXLcreateprob");
            CPXLfreeprob = (int (*)(CPXCENVptr, CPXLPptr *)) GetProcAddress(h, "CPXLfreeprob");
            CPXLgetbase = (int (*)(CPXCENVptr, CPXCLPptr, int *, int *)) GetProcAddress(h, "CPXLgetbase");
            CPXLgeterrorstring = (CPXCCHARptr (*)(CPXCENVptr, int, char *)) GetProcAddress(h, "CPXLgeterrorstring");
            CPXLgetnumcols = (CPXINT (*)(CPXCENVptr, CPXCLPptr)) GetProcAddress(h, "CPXLgetnumcols");
            CPXLgetnumrows = (CPXINT (*)(CPXCENVptr, CPXCLPptr)) GetProcAddress(h, "CPXLgetnumrows");
            CPXLgetobjval = (int (*)(CPXCENVptr, CPXCLPptr, double *)) GetProcAddress(h, "CPXLgetobjval");
            CPXLgetparamnum = (int (*)(CPXCENVptr, char const *, int *)) GetProcAddress(h, "CPXLgetparamnum");
            CPXLgetparamtype = (int (*)(CPXCENVptr, int, int *)) GetProcAddress(h, "CPXLgetparamtype");
            CPXLgetprobtype = (int (*)(CPXCENVptr, CPXCLPptr)) GetProcAddress(h, "CPXLgetprobtype");
            CPXLgetslack = (int (*)(CPXCENVptr, CPXCLPptr, double *, CPXINT, CPXINT)) GetProcAddress(h, "CPXLgetslack");
            CPXLgetstat = (int (*)(CPXCENVptr, CPXCLPptr)) GetProcAddress(h, "CPXLgetstat");
            CPXLgetstatstring = (CPXCHARptr (*)(CPXCENVptr, int, char *)) GetProcAddress(h, "CPXLgetstatstring");
            CPXLgetx = (int (*)(CPXCENVptr, CPXCLPptr, double *, CPXINT, CPXINT)) GetProcAddress(h, "CPXLgetx");
            CPXLmipopt = (int (*)(CPXCENVptr, CPXLPptr)) GetProcAddress(h, "CPXLmipopt");
            CPXLnewcols = (int (*)(CPXCENVptr, CPXLPptr, CPXINT, double const *, double const *, double const *, char const *, char const *const *)) GetProcAddress(h, "CPXLnewcols");
            CPXLopenCPLEX = (CPXENVptr (*)(int *status_p)) GetProcAddress(h, "CPXLopenCPLEX");
            CPXLqpopt = (int (*)(CPXCENVptr, CPXLPptr)) GetProcAddress(h, "CPXLqpopt");
            CPXLsetdblparam = (int (*)(CPXENVptr, int, double)) GetProcAddress(h, "CPXLsetdblparam");
            CPXLsetdefaults = (int (*)(CPXENVptr)) GetProcAddress(h, "CPXLsetdefaults");
            CPXLsetintparam = (int (*)(CPXENVptr, int, CPXINT)) GetProcAddress(h, "CPXLsetintparam");
            CPXLsetlongparam = (int (*)(CPXENVptr, int, CPXLONG)) GetProcAddress(h, "CPXLsetlongparam");
            CPXLsetstrparam = (int (*)(CPXENVptr, int, char const *)) GetProcAddress(h, "CPXLsetstrparam");
            CPXLsolution = (int (*)(CPXCENVptr, CPXCLPptr, int *, double *, double *, double *, double *, double *)) GetProcAddress(h, "CPXLsolution");
            CPXLwriteprob = (int (*)(CPXCENVptr, CPXCLPptr, char const *, char const *)) GetProcAddress(h, "CPXLwriteprob");

      #else // _WIN32
              CPXLaddmipstarts = (int (*)(CPXCENVptr, CPXLPptr, int, CPXLONG, CPXLONG const *, CPXINT const *, double const *, int const *, char const *const *)) dlsym(h, "CPXLaddmipstarts");
            CPXLaddqconstr = (int (*)(CPXCENVptr, CPXLPptr, CPXINT, CPXLONG, double, int, CPXINT const *, double const *, CPXINT const *, CPXINT const *, double const *, char const *)) dlsym(h, "CPXLaddqconstr");
            CPXLaddrows = (int (*)(CPXCENVptr, CPXLPptr, CPXINT, CPXINT, CPXLONG, double const *, char const *, CPXLONG const *, CPXINT const *, double const *, char const *const *, char const *const *)) dlsym(h, "CPXLaddrows");
            CPXLaddsos = (int (*)(CPXCENVptr, CPXLPptr, CPXINT, CPXLONG, char const *, CPXLONG const *, CPXINT const *, double const *, char const *const *)) dlsym(h, "CPXLaddsos");
            CPXLcloseCPLEX = (int (*)(CPXENVptr *)) dlsym(h, "CPXLcloseCPLEX");
            CPXLcopyctype = (int (*)(CPXCENVptr, CPXLPptr, char const *)) dlsym(h, "CPXLcopyctype");
            CPXLcopylp = (int (*)(CPXCENVptr, CPXLPptr, CPXINT, CPXINT, int, double const *, double const *, char const *, CPXLONG const *, CPXINT const *, CPXINT const *, double const *, double const *, double const *, double const *)) dlsym(h, "CPXLcopylp");
            CPXLcopyquad = (int (*)(CPXCENVptr, CPXLPptr, CPXLONG const *, CPXINT const *, CPXINT const *, double const *)) dlsym(h, "CPXLcopyquad");
            CPXLcopystart = (int (*)(CPXCENVptr, CPXLPptr, int const *, int const *, double const *, double const *, double const *, double const *)) dlsym(h, "CPXLcopystart");
            CPXLcreateprob = (CPXLPptr (*)(CPXCENVptr, int *, char const *)) dlsym(h, "CPXLcreateprob");
            CPXLfreeprob = (int (*)(CPXCENVptr, CPXLPptr *)) dlsym(h, "CPXLfreeprob");
            CPXLgetbase = (int (*)(CPXCENVptr, CPXCLPptr, int *, int *)) dlsym(h, "CPXLgetbase");
            CPXLgeterrorstring = (CPXCCHARptr (*)(CPXCENVptr, int, char *)) dlsym(h, "CPXLgeterrorstring");
            CPXLgetnumcols = (CPXINT (*)(CPXCENVptr, CPXCLPptr)) dlsym(h, "CPXLgetnumcols");
            CPXLgetnumrows = (CPXINT (*)(CPXCENVptr, CPXCLPptr)) dlsym(h, "CPXLgetnumrows");
            CPXLgetobjval = (int (*)(CPXCENVptr, CPXCLPptr, double *)) dlsym(h, "CPXLgetobjval");
            CPXLgetparamnum = (int (*)(CPXCENVptr, char const *, int *)) dlsym(h, "CPXLgetparamnum");
            CPXLgetparamtype = (int (*)(CPXCENVptr, int, int *)) dlsym(h, "CPXLgetparamtype");
            CPXLgetprobtype = (int (*)(CPXCENVptr, CPXCLPptr)) dlsym(h, "CPXLgetprobtype");
            CPXLgetslack = (int (*)(CPXCENVptr, CPXCLPptr, double *, CPXINT, CPXINT)) dlsym(h, "CPXLgetslack");
            CPXLgetstat = (int (*)(CPXCENVptr, CPXCLPptr)) dlsym(h, "CPXLgetstat");
            CPXLgetstatstring = (CPXCHARptr (*)(CPXCENVptr, int, char *)) dlsym(h, "CPXLgetstatstring");
            CPXLgetx = (int (*)(CPXCENVptr, CPXCLPptr, double *, CPXINT, CPXINT)) dlsym(h, "CPXLgetx");
            CPXLmipopt = (int (*)(CPXCENVptr, CPXLPptr)) dlsym(h, "CPXLmipopt");
            CPXLnewcols = (int (*)(CPXCENVptr, CPXLPptr, CPXINT, double const *, double const *, double const *, char const *, char const *const *)) dlsym(h, "CPXLnewcols");
            CPXLopenCPLEX = (CPXENVptr (*)(int *status_p)) dlsym(h, "CPXLopenCPLEX");
            CPXLqpopt = (int (*)(CPXCENVptr, CPXLPptr)) dlsym(h, "CPXLqpopt");
            CPXLsetdblparam = (int (*)(CPXENVptr, int, double)) dlsym(h, "CPXLsetdblparam");
            CPXLsetdefaults = (int (*)(CPXENVptr)) dlsym(h, "CPXLsetdefaults");
            CPXLsetintparam = (int (*)(CPXENVptr, int, CPXINT)) dlsym(h, "CPXLsetintparam");
            CPXLsetlongparam = (int (*)(CPXENVptr, int, CPXLONG)) dlsym(h, "CPXLsetlongparam");
            CPXLsetstrparam = (int (*)(CPXENVptr, int, char const *)) dlsym(h, "CPXLsetstrparam");
            CPXLsolution = (int (*)(CPXCENVptr, CPXCLPptr, int *, double *, double *, double *, double *, double *)) dlsym(h, "CPXLsolution");
            CPXLwriteprob = (int (*)(CPXCENVptr, CPXCLPptr, char const *, char const *)) dlsym(h, "CPXLwriteprob");

      #endif // _WIN32
      
      return 0;
    }
  }
  