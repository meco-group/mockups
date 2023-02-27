#include "worhp.h"

int CheckWorhpVersion(int, int, const char *) { return 0; }
void SetWorhpPrint(worhp_print_t) {}
void WorhpFidif(OptVar*, Workspace*, Params*, Control*) {}
void WorhpFree(OptVar*, Workspace*, Params*, Control*) {}
int WorhpGetParamCount(void) { return 0; }
const char* WorhpGetParamName(int) { return ""; }
WorhpType WorhpGetParamType(int) { return WORHP_NO_T; }
void WorhpInit(OptVar*, Workspace*, Params*, Control*) {}
void WorhpPreInit(OptVar *, Workspace *, Params *, Control *) {}
bool WorhpSetBoolParam  (Params *, const char*, bool) { return 0; }
bool WorhpSetDoubleParam(Params *, const char*, double) { return 0; }
bool WorhpSetIntParam   (Params *, const char*, int) { return 0; }
void Worhp(OptVar*, Workspace*, Params*, Control*) {}

