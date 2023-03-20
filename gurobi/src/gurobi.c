
#define DLL_IMPLEMENTATION
#include "gurobi_c.h"

#include <stdlib.h>
#include <stdio.h>
#ifdef _WIN32
#include <windows.h>
#else // _WIN32
#include <dlfcn.h>
#include <stddef.h>
#endif // _WIN32


int (*GRBaddconstr)(GRBmodel *, int, int *, double *, char, double, const char *) = NULL;
int (*GRBaddqconstr)(GRBmodel *, int, int *, double *, int, int *, int *, double *, char, double, const char *) = NULL;
int (*GRBaddqpterms)(GRBmodel *, int, int *, int *, double *) = NULL;
int (*GRBaddrangeconstr)(GRBmodel *, int, int *, double *, double, double, const char *) = NULL;
int (*GRBaddsos)(GRBmodel *, int, int, int *, int *, int *, double *) = NULL;
int (*GRBaddvar)(GRBmodel *, int, int *, double *, double, double, double, char, const char *) = NULL;
void (*GRBfreeenv)(GRBenv *) = NULL;
int (*GRBfreemodel)(GRBmodel *) = NULL;
int (*GRBgetdblattr)(GRBmodel *, const char *, double *) = NULL;
int (*GRBgetdblattrarray)(GRBmodel *, const char *, int, int, double *) = NULL;
GRBenv* (*GRBgetenv)(GRBmodel *) = NULL;
const char* (*GRBgeterrormsg)(GRBenv *) = NULL;
int (*GRBgetintattr)(GRBmodel *, const char *, int *) = NULL;
int (*GRBgetparamtype)(GRBenv *, const char *) = NULL;
int (*GRBloadenv)(GRBenv **, const char *) = NULL;
int (*GRBnewmodel)(GRBenv *, GRBmodel **, const char *, int, double *, double *, double *, char *, char **) = NULL;
int (*GRBoptimize)(GRBmodel *) = NULL;
int (*GRBsetdblattrelement)(GRBmodel *, const char *, int, double) = NULL;
int (*GRBsetdblparam)(GRBenv *, const char *, double) = NULL;
int (*GRBsetintparam)(GRBenv *, const char *, int) = NULL;
int (*GRBsetstrparam)(GRBenv *, const char *, const char *) = NULL;
int (*GRBupdatemodel)(GRBmodel *) = NULL;

  
  #if defined(_WIN32)
  static HINSTANCE h;
  #else
  void * h;
  #endif
  
  void gurobi_adaptor_unload() {
    if (h) {
        #if defined(_WIN32)
        FreeLibrary(h);
        #else
        dlclose(h);
        #endif
    }
  }
  int gurobi_adaptor_load(char* err_msg, unsigned int err_msg_len) {
  
    const char* suffix = getenv("GUROBI_VERSION");
    
    #if defined(_WIN32)
    const char library_suffix[] = "dll";
    const char library_prefix[] = "";
    const char path_env[] = "PATH";
    #elif defined(__APPLE__)
    const char library_suffix[] = "dylib";
    const char library_prefix[] = "lib";
    const char path_env[] = "DYLD_LIBRARY_PATH";
    #else
    const char library_suffix[] = "so";
    const char library_prefix[] = "lib";
    const char path_env[] = "LD_LIBRARY_PATH";
    #endif
    
    
    if (suffix==NULL) {
        snprintf(err_msg, err_msg_len, "Gurobi load adaptor needs an environmental variable <GUROBI_VERSION> "
        "such that %sgurobi<GUROBI_VERSION>.%s can be found.", library_prefix, library_suffix);
        return 1;
    }

    char buffer[100];
    
    snprintf(buffer, 100, "%sgurobi%s.%s", library_prefix, suffix, library_suffix);

    #if defined(_WIN32)
    h = LoadLibrary(TEXT(buffer));
    #elif defined(__APPLE__)
    h = dlopen(buffer, RTLD_LAZY | RTLD_LOCAL);
    #else
    h = dlopen(buffer, RTLD_LAZY | RTLD_LOCAL | RTLD_DEEPBIND);
    #endif
    
    if (h) {
      #ifdef _WIN32
            GRBaddconstr = (int (*)(GRBmodel *, int, int *, double *, char, double, const char *)) GetProcAddress(h, "GRBaddconstr");
            if (GRBaddconstr==NULL) { snprintf(err_msg, err_msg_len, "Could not find symbol 'GRBaddconstr' in libgurobi%s.%s", suffix, library_suffix); return 2; };
            GRBaddqconstr = (int (*)(GRBmodel *, int, int *, double *, int, int *, int *, double *, char, double, const char *)) GetProcAddress(h, "GRBaddqconstr");
            if (GRBaddqconstr==NULL) { snprintf(err_msg, err_msg_len, "Could not find symbol 'GRBaddqconstr' in libgurobi%s.%s", suffix, library_suffix); return 2; };
            GRBaddqpterms = (int (*)(GRBmodel *, int, int *, int *, double *)) GetProcAddress(h, "GRBaddqpterms");
            if (GRBaddqpterms==NULL) { snprintf(err_msg, err_msg_len, "Could not find symbol 'GRBaddqpterms' in libgurobi%s.%s", suffix, library_suffix); return 2; };
            GRBaddrangeconstr = (int (*)(GRBmodel *, int, int *, double *, double, double, const char *)) GetProcAddress(h, "GRBaddrangeconstr");
            if (GRBaddrangeconstr==NULL) { snprintf(err_msg, err_msg_len, "Could not find symbol 'GRBaddrangeconstr' in libgurobi%s.%s", suffix, library_suffix); return 2; };
            GRBaddsos = (int (*)(GRBmodel *, int, int, int *, int *, int *, double *)) GetProcAddress(h, "GRBaddsos");
            if (GRBaddsos==NULL) { snprintf(err_msg, err_msg_len, "Could not find symbol 'GRBaddsos' in libgurobi%s.%s", suffix, library_suffix); return 2; };
            GRBaddvar = (int (*)(GRBmodel *, int, int *, double *, double, double, double, char, const char *)) GetProcAddress(h, "GRBaddvar");
            if (GRBaddvar==NULL) { snprintf(err_msg, err_msg_len, "Could not find symbol 'GRBaddvar' in libgurobi%s.%s", suffix, library_suffix); return 2; };
            GRBfreeenv = (void (*)(GRBenv *)) GetProcAddress(h, "GRBfreeenv");
            if (GRBfreeenv==NULL) { snprintf(err_msg, err_msg_len, "Could not find symbol 'GRBfreeenv' in libgurobi%s.%s", suffix, library_suffix); return 2; };
            GRBfreemodel = (int (*)(GRBmodel *)) GetProcAddress(h, "GRBfreemodel");
            if (GRBfreemodel==NULL) { snprintf(err_msg, err_msg_len, "Could not find symbol 'GRBfreemodel' in libgurobi%s.%s", suffix, library_suffix); return 2; };
            GRBgetdblattr = (int (*)(GRBmodel *, const char *, double *)) GetProcAddress(h, "GRBgetdblattr");
            if (GRBgetdblattr==NULL) { snprintf(err_msg, err_msg_len, "Could not find symbol 'GRBgetdblattr' in libgurobi%s.%s", suffix, library_suffix); return 2; };
            GRBgetdblattrarray = (int (*)(GRBmodel *, const char *, int, int, double *)) GetProcAddress(h, "GRBgetdblattrarray");
            if (GRBgetdblattrarray==NULL) { snprintf(err_msg, err_msg_len, "Could not find symbol 'GRBgetdblattrarray' in libgurobi%s.%s", suffix, library_suffix); return 2; };
            GRBgetenv = (GRBenv* (*)(GRBmodel *)) GetProcAddress(h, "GRBgetenv");
            if (GRBgetenv==NULL) { snprintf(err_msg, err_msg_len, "Could not find symbol 'GRBgetenv' in libgurobi%s.%s", suffix, library_suffix); return 2; };
            GRBgeterrormsg = (const char* (*)(GRBenv *)) GetProcAddress(h, "GRBgeterrormsg");
            if (GRBgeterrormsg==NULL) { snprintf(err_msg, err_msg_len, "Could not find symbol 'GRBgeterrormsg' in libgurobi%s.%s", suffix, library_suffix); return 2; };
            GRBgetintattr = (int (*)(GRBmodel *, const char *, int *)) GetProcAddress(h, "GRBgetintattr");
            if (GRBgetintattr==NULL) { snprintf(err_msg, err_msg_len, "Could not find symbol 'GRBgetintattr' in libgurobi%s.%s", suffix, library_suffix); return 2; };
            GRBgetparamtype = (int (*)(GRBenv *, const char *)) GetProcAddress(h, "GRBgetparamtype");
            if (GRBgetparamtype==NULL) { snprintf(err_msg, err_msg_len, "Could not find symbol 'GRBgetparamtype' in libgurobi%s.%s", suffix, library_suffix); return 2; };
            GRBloadenv = (int (*)(GRBenv **, const char *)) GetProcAddress(h, "GRBloadenv");
            if (GRBloadenv==NULL) { snprintf(err_msg, err_msg_len, "Could not find symbol 'GRBloadenv' in libgurobi%s.%s", suffix, library_suffix); return 2; };
            GRBnewmodel = (int (*)(GRBenv *, GRBmodel **, const char *, int, double *, double *, double *, char *, char **)) GetProcAddress(h, "GRBnewmodel");
            if (GRBnewmodel==NULL) { snprintf(err_msg, err_msg_len, "Could not find symbol 'GRBnewmodel' in libgurobi%s.%s", suffix, library_suffix); return 2; };
            GRBoptimize = (int (*)(GRBmodel *)) GetProcAddress(h, "GRBoptimize");
            if (GRBoptimize==NULL) { snprintf(err_msg, err_msg_len, "Could not find symbol 'GRBoptimize' in libgurobi%s.%s", suffix, library_suffix); return 2; };
            GRBsetdblattrelement = (int (*)(GRBmodel *, const char *, int, double)) GetProcAddress(h, "GRBsetdblattrelement");
            if (GRBsetdblattrelement==NULL) { snprintf(err_msg, err_msg_len, "Could not find symbol 'GRBsetdblattrelement' in libgurobi%s.%s", suffix, library_suffix); return 2; };
            GRBsetdblparam = (int (*)(GRBenv *, const char *, double)) GetProcAddress(h, "GRBsetdblparam");
            if (GRBsetdblparam==NULL) { snprintf(err_msg, err_msg_len, "Could not find symbol 'GRBsetdblparam' in libgurobi%s.%s", suffix, library_suffix); return 2; };
            GRBsetintparam = (int (*)(GRBenv *, const char *, int)) GetProcAddress(h, "GRBsetintparam");
            if (GRBsetintparam==NULL) { snprintf(err_msg, err_msg_len, "Could not find symbol 'GRBsetintparam' in libgurobi%s.%s", suffix, library_suffix); return 2; };
            GRBsetstrparam = (int (*)(GRBenv *, const char *, const char *)) GetProcAddress(h, "GRBsetstrparam");
            if (GRBsetstrparam==NULL) { snprintf(err_msg, err_msg_len, "Could not find symbol 'GRBsetstrparam' in libgurobi%s.%s", suffix, library_suffix); return 2; };
            GRBupdatemodel = (int (*)(GRBmodel *)) GetProcAddress(h, "GRBupdatemodel");
            if (GRBupdatemodel==NULL) { snprintf(err_msg, err_msg_len, "Could not find symbol 'GRBupdatemodel' in libgurobi%s.%s", suffix, library_suffix); return 2; };

      #else // _WIN32
              GRBaddconstr = (int (*)(GRBmodel *, int, int *, double *, char, double, const char *)) dlsym(h, "GRBaddconstr");
            if (GRBaddconstr==NULL) { snprintf(err_msg, err_msg_len, "Could not find symbol 'GRBaddconstr' in libgurobi%s.%s", suffix, library_suffix); return 2; };
            GRBaddqconstr = (int (*)(GRBmodel *, int, int *, double *, int, int *, int *, double *, char, double, const char *)) dlsym(h, "GRBaddqconstr");
            if (GRBaddqconstr==NULL) { snprintf(err_msg, err_msg_len, "Could not find symbol 'GRBaddqconstr' in libgurobi%s.%s", suffix, library_suffix); return 2; };
            GRBaddqpterms = (int (*)(GRBmodel *, int, int *, int *, double *)) dlsym(h, "GRBaddqpterms");
            if (GRBaddqpterms==NULL) { snprintf(err_msg, err_msg_len, "Could not find symbol 'GRBaddqpterms' in libgurobi%s.%s", suffix, library_suffix); return 2; };
            GRBaddrangeconstr = (int (*)(GRBmodel *, int, int *, double *, double, double, const char *)) dlsym(h, "GRBaddrangeconstr");
            if (GRBaddrangeconstr==NULL) { snprintf(err_msg, err_msg_len, "Could not find symbol 'GRBaddrangeconstr' in libgurobi%s.%s", suffix, library_suffix); return 2; };
            GRBaddsos = (int (*)(GRBmodel *, int, int, int *, int *, int *, double *)) dlsym(h, "GRBaddsos");
            if (GRBaddsos==NULL) { snprintf(err_msg, err_msg_len, "Could not find symbol 'GRBaddsos' in libgurobi%s.%s", suffix, library_suffix); return 2; };
            GRBaddvar = (int (*)(GRBmodel *, int, int *, double *, double, double, double, char, const char *)) dlsym(h, "GRBaddvar");
            if (GRBaddvar==NULL) { snprintf(err_msg, err_msg_len, "Could not find symbol 'GRBaddvar' in libgurobi%s.%s", suffix, library_suffix); return 2; };
            GRBfreeenv = (void (*)(GRBenv *)) dlsym(h, "GRBfreeenv");
            if (GRBfreeenv==NULL) { snprintf(err_msg, err_msg_len, "Could not find symbol 'GRBfreeenv' in libgurobi%s.%s", suffix, library_suffix); return 2; };
            GRBfreemodel = (int (*)(GRBmodel *)) dlsym(h, "GRBfreemodel");
            if (GRBfreemodel==NULL) { snprintf(err_msg, err_msg_len, "Could not find symbol 'GRBfreemodel' in libgurobi%s.%s", suffix, library_suffix); return 2; };
            GRBgetdblattr = (int (*)(GRBmodel *, const char *, double *)) dlsym(h, "GRBgetdblattr");
            if (GRBgetdblattr==NULL) { snprintf(err_msg, err_msg_len, "Could not find symbol 'GRBgetdblattr' in libgurobi%s.%s", suffix, library_suffix); return 2; };
            GRBgetdblattrarray = (int (*)(GRBmodel *, const char *, int, int, double *)) dlsym(h, "GRBgetdblattrarray");
            if (GRBgetdblattrarray==NULL) { snprintf(err_msg, err_msg_len, "Could not find symbol 'GRBgetdblattrarray' in libgurobi%s.%s", suffix, library_suffix); return 2; };
            GRBgetenv = (GRBenv* (*)(GRBmodel *)) dlsym(h, "GRBgetenv");
            if (GRBgetenv==NULL) { snprintf(err_msg, err_msg_len, "Could not find symbol 'GRBgetenv' in libgurobi%s.%s", suffix, library_suffix); return 2; };
            GRBgeterrormsg = (const char* (*)(GRBenv *)) dlsym(h, "GRBgeterrormsg");
            if (GRBgeterrormsg==NULL) { snprintf(err_msg, err_msg_len, "Could not find symbol 'GRBgeterrormsg' in libgurobi%s.%s", suffix, library_suffix); return 2; };
            GRBgetintattr = (int (*)(GRBmodel *, const char *, int *)) dlsym(h, "GRBgetintattr");
            if (GRBgetintattr==NULL) { snprintf(err_msg, err_msg_len, "Could not find symbol 'GRBgetintattr' in libgurobi%s.%s", suffix, library_suffix); return 2; };
            GRBgetparamtype = (int (*)(GRBenv *, const char *)) dlsym(h, "GRBgetparamtype");
            if (GRBgetparamtype==NULL) { snprintf(err_msg, err_msg_len, "Could not find symbol 'GRBgetparamtype' in libgurobi%s.%s", suffix, library_suffix); return 2; };
            GRBloadenv = (int (*)(GRBenv **, const char *)) dlsym(h, "GRBloadenv");
            if (GRBloadenv==NULL) { snprintf(err_msg, err_msg_len, "Could not find symbol 'GRBloadenv' in libgurobi%s.%s", suffix, library_suffix); return 2; };
            GRBnewmodel = (int (*)(GRBenv *, GRBmodel **, const char *, int, double *, double *, double *, char *, char **)) dlsym(h, "GRBnewmodel");
            if (GRBnewmodel==NULL) { snprintf(err_msg, err_msg_len, "Could not find symbol 'GRBnewmodel' in libgurobi%s.%s", suffix, library_suffix); return 2; };
            GRBoptimize = (int (*)(GRBmodel *)) dlsym(h, "GRBoptimize");
            if (GRBoptimize==NULL) { snprintf(err_msg, err_msg_len, "Could not find symbol 'GRBoptimize' in libgurobi%s.%s", suffix, library_suffix); return 2; };
            GRBsetdblattrelement = (int (*)(GRBmodel *, const char *, int, double)) dlsym(h, "GRBsetdblattrelement");
            if (GRBsetdblattrelement==NULL) { snprintf(err_msg, err_msg_len, "Could not find symbol 'GRBsetdblattrelement' in libgurobi%s.%s", suffix, library_suffix); return 2; };
            GRBsetdblparam = (int (*)(GRBenv *, const char *, double)) dlsym(h, "GRBsetdblparam");
            if (GRBsetdblparam==NULL) { snprintf(err_msg, err_msg_len, "Could not find symbol 'GRBsetdblparam' in libgurobi%s.%s", suffix, library_suffix); return 2; };
            GRBsetintparam = (int (*)(GRBenv *, const char *, int)) dlsym(h, "GRBsetintparam");
            if (GRBsetintparam==NULL) { snprintf(err_msg, err_msg_len, "Could not find symbol 'GRBsetintparam' in libgurobi%s.%s", suffix, library_suffix); return 2; };
            GRBsetstrparam = (int (*)(GRBenv *, const char *, const char *)) dlsym(h, "GRBsetstrparam");
            if (GRBsetstrparam==NULL) { snprintf(err_msg, err_msg_len, "Could not find symbol 'GRBsetstrparam' in libgurobi%s.%s", suffix, library_suffix); return 2; };
            GRBupdatemodel = (int (*)(GRBmodel *)) dlsym(h, "GRBupdatemodel");
            if (GRBupdatemodel==NULL) { snprintf(err_msg, err_msg_len, "Could not find symbol 'GRBupdatemodel' in libgurobi%s.%s", suffix, library_suffix); return 2; };

      #endif // _WIN32
      
      return 0;
    } else {
      snprintf(err_msg, err_msg_len, "Could not find library '%s' (%sgurobi<GUROBI_VERSION>.%s). "
        "Consider adding the appropriate gurobi folder to environmental variable '%s', or specifying a different variable 'CPLEX_VERSION'.", buffer, library_prefix, library_suffix, path_env);
      return 1;
    }
  }
  