
method_declarations = []

import re

with open("include/mex_core.h.in","r") as fin:
  for line in fin.readlines():
    line = line.strip()
    method_declarations.append(line)
    
preamble = []
postamble = []

with open("include/mex.h.in","r") as fin:
  target = preamble
  for line in fin.readlines():
    if "[mex_core.h]" in line:
        target = postamble
        continue
    target.append(line)    

      
def get_name(decl):
  return decl.split("(")[0].split(" ")[-1]
  
def function_ptr(decl):
  return decl[:-1].replace(get_name(decl),"(*)")

with open("include/mex.h","w") as fout:
  fout.write("".join(preamble))
  fout.write("#ifdef _WIN32\n")
  for decl in method_declarations:
    fout.write("#define %s adaptor_%s\n" % (get_name(decl),get_name(decl)))
    fout.write("__declspec( dllimport ) " + decl.replace(get_name(decl),"(*%s)" % get_name(decl))+"\n")
  fout.write("#else\n")
  for decl in method_declarations:
    fout.write(decl+"\n")
    
  fout.write("#endif // _WIN32\n")
  fout.write("".join(postamble))

with open("src/mex.c","w") as fout:


  fout.write("""
#include "mex.h"
#ifdef _WIN32
#include <libloaderapi.h>
#include <stdio.h>

""")
  for decl in method_declarations:
    fout.write(decl.replace(get_name(decl),"(*%s)" % get_name(decl))[:-1]+" = NULL;\n")

  fout.write("""
BOOL APIENTRY DllMain( HMODULE hModule,
             DWORD  ul_reason_for_call,
             LPVOID lpReserved
           ) {
  switch (ul_reason_for_call) {
    case DLL_PROCESS_ATTACH:
      {
        char buffer[100];
        for (int i=0; i<100; i++) {
          if (i==0) {
            sprintf(buffer, "liboctinterp.dll");
          } else {
            sprintf(buffer, "liboctinterp-%d.dll", i);
          }
          HMODULE h = GetModuleHandle(buffer);
          if (h != NULL) {
""")
  for decl in method_declarations:
    fout.write("""            %s = (%s) GetProcAddress(h, "%s");\n""" % (get_name(decl),function_ptr(decl),get_name(decl)))
                 
  fout.write("""            return TRUE;
          }    
        }
      }
      return FALSE;
      break;
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        return TRUE;
  }
}

#else
""")

  for decl in method_declarations:
    def add_param_name(m):
      parts = m.group(0)[1:-1].split(",")
      for i in range(len(parts)):
        name = "abcdefgh"[i]
        if parts[i].count("*")==1:
          p = parts[i].split("*")
          parts[i] = p[0] + "* "+name + p[1]
          continue
        if parts[i]=="void": continue
        if "..." in parts[i]: continue
        parts[i] += " "+name
      return "("+",".join(parts)+")"
    d = re.sub("\(.*\)",add_param_name,decl[:-1])
    fout.write(d+" {" + (" return 0; " if not decl.startswith("void") else "")+ "}\n")
 
  fout.write("""
#endif // _WIN32
""")



