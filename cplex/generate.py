
method_declarations = []

import re

with open("include/cplex_core.h.in","r") as fin:
  for line in fin.readlines():
    line = line.strip()
    method_declarations.append(line)
    
preamble = []
postamble = []

with open("include/cplex.h.in","r") as fin:
  target = preamble
  for line in fin.readlines():
    if "[cplex_core.h]" in line:
        target = postamble
        continue
    target.append(line)    

      
def get_name(decl):
  return decl.split("(")[0].split(" ")[-1]
  
def function_ptr(decl):
  return decl[:-1].replace(get_name(decl),"(*)")

with open("include/ilcplex/cplexx.h","w") as fout:
  fout.write("".join(preamble))
  for decl in method_declarations:
    fout.write("#define %s adaptor_%s\n" % (get_name(decl),get_name(decl)))
    fout.write("DLLSYMBOL " + decl.replace(get_name(decl),"(*%s)" % get_name(decl))+"\n")
    
  fout.write("".join(postamble))

with open("src/cplex.c","w") as fout:


  fout.write("""
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


""")
  for decl in method_declarations:
    fout.write(decl.replace(get_name(decl),"(*%s)" % get_name(decl))[:-1]+" = NULL;\n")

  fout.write("""
  
  #if defined(_WIN32)
  static HINSTANCE h;
  #else
  void * h;
  #endif
  
  void cplex_adaptor_unload() {
    if (h) {
        #if defined(_WIN32)
        FreeLibrary(h);
        #else
        dlclose(h);
        #endif
    }
  }
  int cplex_adaptor_load(char* err_msg, unsigned int err_msg_len) {
  
    const char* suffix = getenv("CPLEX_VERSION");
    
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
        snprintf(err_msg, err_msg_len, "CPLEX load adaptor needs an environmental variable <CPLEX_VERSION> "
        "such that %scplex<CPLEX_VERSION>.%s can be found.", library_prefix, library_suffix);
        return 1;
    }

    char buffer[100];
    
    snprintf(buffer, 100, "%scplex%s.%s", library_prefix, suffix, library_suffix);

    #if defined(_WIN32)
    h = LoadLibrary(TEXT(buffer));
    #elif defined(__APPLE__)
    h = dlopen(buffer, RTLD_LAZY | RTLD_LOCAL);
    #else
    h = dlopen(buffer, RTLD_LAZY | RTLD_LOCAL | RTLD_DEEPBIND);
    #endif
    
    if (h) {
      #ifdef _WIN32
""")
    
  fout.write("""#if CPX_APIMODEL == CPX_APIMODEL_LARGE\n""")
  for decl in method_declarations:
    fout.write("""            %s = (%s) GetProcAddress(h, "%s");\n""" % (get_name(decl),function_ptr(decl),get_name(decl).replace("CPXX","CPXL")))
    fout.write("""            if (%s==NULL) { snprintf(err_msg, err_msg_len, "Could not find symbol '%s' in libcplex%%s.%%s", suffix, library_suffix); return 2; };\n""" % (get_name(decl),get_name(decl).replace("CPXX","CPXL")))
  fout.write("""#endif\n""")
  fout.write("""#if CPX_APIMODEL == CPX_APIMODEL_SMALL\n""")
  for decl in method_declarations:
    fout.write("""            %s = (%s) GetProcAddress(h, "%s");\n""" % (get_name(decl),function_ptr(decl),get_name(decl).replace("CPXX","CPXS")))
    fout.write("""            if (%s==NULL) { snprintf(err_msg, err_msg_len, "Could not find symbol '%s' in libcplex%%s.%%s", suffix, library_suffix); return 2; };\n""" % (get_name(decl),get_name(decl).replace("CPXX","CPXS")))
  fout.write("""#endif\n""")
  
  fout.write("""
      #else // _WIN32
  """)
    
  fout.write("""#if CPX_APIMODEL == CPX_APIMODEL_LARGE\n""")
  for decl in method_declarations:
    fout.write("""            %s = (%s) dlsym(h, "%s");\n""" % (get_name(decl),function_ptr(decl),get_name(decl).replace("CPXX","CPXL")))
    fout.write("""            if (%s==NULL) { snprintf(err_msg, err_msg_len, "Could not find symbol '%s' in libcplex%%s.%%s", suffix, library_suffix); return 2; };\n""" % (get_name(decl),get_name(decl).replace("CPXX","CPXL")))
  fout.write("""#endif\n""")
  fout.write("""#if CPX_APIMODEL == CPX_APIMODEL_SMALL\n""")
  for decl in method_declarations:
    fout.write("""            %s = (%s) dlsym(h, "%s");\n""" % (get_name(decl),function_ptr(decl),get_name(decl).replace("CPXX","CPXS")))
    fout.write("""            if (%s==NULL) { snprintf(err_msg, err_msg_len, "Could not find symbol '%s' in libcplex%%s.%%s", suffix, library_suffix); return 2; };\n""" % (get_name(decl),get_name(decl).replace("CPXX","CPXS")))
  fout.write("""#endif\n""")                 
  fout.write("""
      #endif // _WIN32
      
      return 0;
    } else {
      snprintf(err_msg, err_msg_len, "Could not find library '%s' (%scplex<CPLEX_VERSION>.%s). "
        "Consider adding the appropriate cplex folder to environmental variable '%s', or specifying a different variable 'CPLEX_VERSION'.", buffer, library_prefix, library_suffix, path_env);
      return 1;
    }
  }
  """)



