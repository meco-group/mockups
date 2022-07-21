import re

from collections import defaultdict

symboltable = defaultdict(list)

versions = set()

with open('symbols.txt') as f:
  for s in f:
    s = s.strip()
    try:
      symbol, version = s.split('_')
      version = int(version)
    except:
      symbol = s
      version = 0
    symboltable[symbol].append(version)

    versions.add(version)

for header in ["matrix","mex"]:

  names = []
  slurp = False
  with open('../include/{header}.h'.format(header=header),'r') as f:
    for l in f:
      if len(l.strip())==0:
        slurp = False
      if slurp:
        name = l.split("(")[0].split(" ")[-1]
        names.append(name)
      if l.startswith("// methods"):
        slurp = True

  with open('../include/{header}_versions.h'.format(header=header),'w') as f:
    for v in sorted(list(versions)):
      if v==0: continue
      f.write("#if MATLAB_API_VERSION=={v}\n".format(v=v))
      for name in names:  
        if v in symboltable[name]:
          f.write("#define {name} {name}_{v}\n".format(name=name,v=v))

      f.write("#endif // {v}\n".format(v=v))

        
