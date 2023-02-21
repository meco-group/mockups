
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

with open("include/cplex.h","w") as fout:
  fout.write("".join(preamble))
  for decl in method_declarations:
    fout.write("#define %s adaptor_%s\n" % (get_name(decl),get_name(decl)))
    fout.write("DLLSYMBOL " + decl.replace(get_name(decl),"(*%s)" % get_name(decl))+"\n")
    
  fout.write("".join(postamble))

with open("src/cplex.c","w") as fout:


  fout.write("""
#define DLL_IMPLEMENTATION
#include "cplex.h"

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
  
  int cplex_adaptor_load(adaptor_handle_t handle) {
    #ifdef _WIN32
    HINSTANCE h = (HINSTANCE) handle;
    #else
    void * h = handle;
    #endif
    
    if (h != NULL) {
      #ifdef _WIN32
""")
    
  fout.write("""#if CPX_APIMODEL == CPX_APIMODEL_LARGE\n""")
  for decl in method_declarations:
    fout.write("""            %s = (%s) GetProcAddress(h, "%s");\n""" % (get_name(decl),function_ptr(decl),get_name(decl).replace("CPXX","CPXL")))
  fout.write("""#endif\n""")
  fout.write("""#if CPX_APIMODEL == CPX_APIMODEL_SMALL\n""")
  for decl in method_declarations:
    fout.write("""            %s = (%s) GetProcAddress(h, "%s");\n""" % (get_name(decl),function_ptr(decl),get_name(decl).replace("CPXX","CPXS")))
  fout.write("""#endif\n""")
  
  fout.write("""
      #else // _WIN32
  """)
    
  fout.write("""#if CPX_APIMODEL == CPX_APIMODEL_LARGE\n""")
  for decl in method_declarations:
    fout.write("""            %s = (%s) dlsym(h, "%s");\n""" % (get_name(decl),function_ptr(decl),get_name(decl).replace("CPXX","CPXL")))
  fout.write("""#endif\n""")
  fout.write("""#if CPX_APIMODEL == CPX_APIMODEL_SMALL\n""")
  for decl in method_declarations:
    fout.write("""            %s = (%s) dlsym(h, "%s");\n""" % (get_name(decl),function_ptr(decl),get_name(decl).replace("CPXX","CPXS")))
  fout.write("""#endif\n""")                 
  fout.write("""
      #endif // _WIN32
      
      return 0;
    }
  }
  """)



