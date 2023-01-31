
method_declarations = []

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

with open("include/mex.h","w") as fout:
  fout.write("".join(preamble))
  fout.write("#ifdef _WIN32\n")
  for decl in method_declarations:
    fout.write("#define %s adaptor_%s\n" % (get_name(decl),get_name(decl)))
    fout.write( decl.replace(get_name(decl),"(*%s)" % get_name(decl))+"\n")
  fout.write("#else\n")
  for decl in method_declarations:
    fout.write(decl+"\n")
    
  fout.write("#endif // _WIN32\n")
  fout.write("".join(postamble))

with open("src/mex.c","w") as fout:


  fout.write("""

#ifdef _WIN32
#include <libloaderapi.h>
#include <stdio.h>

""")
  for decl in method_declarations:
    fout.write(decl.replace(get_name(decl),"(*adaptor_%s)" % get_name(decl))[:-1]+" = NULL;\n")

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
          HMODULE h = getModuleHandle(buffer);
          if (h != NULL) {
""")
  for decl in method_declarations:
    fout.write("""            adaptor_%s = GetProcAddress(h, "%s");\n""" % (get_name(decl),get_name(decl)))
                 
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
    fout.write(decl[:-1]+" {" + (" return 0; " if not decl.startswith("void") else "")+ "}\n")
 
  fout.write("""
#endif // _WIN32
""")



