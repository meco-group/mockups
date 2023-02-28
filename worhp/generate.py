import os
import re
from collections import defaultdict
versions = {"1.15": "/home/jgillis/programs/worhp_1.15-0_linux"}

worhp_interface = "/home/jgillis/programs/casadi/casadi/interfaces/worhp/worhp_interface.cpp"


structs = ["Workspace", "Params", "OptVar", "Control"]

data = {}


used_fields = defaultdict(set)

# Retrieve all uses of Worhp structs in worhp_interface
with open(worhp_interface,"r") as inp:
    contents = inp.read()
    for t,e in re.findall(r"worhp_([owpc]).(\w+)", contents):
        # Convert t to full struct name
        t = structs["wpoc".index(t)]
        used_fields[t].add(e)

print(used_fields)


def read_stucts(header_file):
    data = {}
    active_struct = None
    with open(header_file,"r") as inp:
        lines = inp.read()
        # Multi-line c style comment removal
        lines = re.sub(r"/\*.*?\*/", "", lines, flags=re.DOTALL)
        for line in lines.split("\n"):
            if line.startswith("typedef struct"):
                struct_name = line.split()[2]
                active_struct = struct_name
                data[active_struct] = []
            elif active_struct is not None:
                # Remove c style comments
                line = re.sub(r"/\*.*\*/", "", line)
                if line.strip()=="":
                    continue
                if line.startswith("}"):
                    active_struct = None
                else:
                    d = data[active_struct]
                    d.append(line.strip()[:-1])
    return data
    

for version, root in versions.items():
    for k,v in read_stucts(os.path.join(root,"include","worhp","C_Worhp_Data.h")).items():
        data[k[:-6]] = v
    qp_data = read_stucts(os.path.join(root,"include","worhp","C_qp_data.h"))
    leq_data = read_stucts(os.path.join(root,"include","worhp","C_leqsol_data.h"))

def write_struct(output,fields,struct_name,alias):
    outp.write(f"typedef struct {struct_name} {{\n")
    for line in fields:
        outp.write("  "+line+";\n")
    outp.write(f"}} {alias};\n")

def anonymize(fields,used_fields=None):
    if used_fields is None:
        used_fields = set()
    count = 0
    for line in fields:
        data_type, name = line.rsplit(" ",1)
        suffix = "".join(re.findall("\[\w+\]",name))
        if name.startswith("*"):
            name = name[1:]
            data_type = data_type + "*"
        if name in used_fields:
            yield line
        else:
            yield f"{data_type} anon{count}"+suffix
            count+=1

with open("include/worhp_data_structs.h","w") as outp:
    with open(os.path.join(root,"include","worhp","worhp_version.h"),"r") as inp:
        outp.write(inp.read())
    write_struct(outp,qp_data["QPParamsStruct"],"QPParamsStruct","QPParams")
    write_struct(outp,anonymize(leq_data["LeqsolWorkspaceStruct"]),"LeqsolWorkspaceStruct","LeqsolWorkspace")
    write_struct(outp,anonymize(qp_data["QPWorkspaceStruct"]),"QPWorkspaceStruct","QPWorkspace")
    for k,v in data.items():
        v = anonymize(v,used_fields[k])
        write_struct(outp,v,f"{k}Struct",k)


#print(data)
