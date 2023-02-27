#ifndef WORHP_H__
#define WORHP_H__

#ifdef __cplusplus
extern "C" {
#endif

#if !defined(_MSC_VER) || (_MSC_VER >= 1800)
#include <stdbool.h>
#endif

typedef struct _OptVar OptVar;
typedef struct _Workspace Workspace;
typedef struct _Params Params;
typedef struct _Control Control;

typedef void (*worhp_print_t) (int mode, const char s[]);

typedef enum {
  WORHP_BOOL_T,
  WORHP_CUSTOM_T,
  WORHP_DOUBLE_T,
  WORHP_INT_T,
  WORHP_NO_T,
  WORHP_SINGLE_T,
  WORHP_SIZE_T,
  WORHP_CONST_C_STRING_T
} WorhpType;

int CheckWorhpVersion(int, int, const char *);
/*/ U CheckWorhpVersion@@WORHP_1.0*/
void SetWorhpPrint(worhp_print_t);
/* U SetWorhpPrint@@WORHP_1.0*/
void WorhpFidif(OptVar*, Workspace*, Params*, Control*);
/* U WorhpFidif@@WORHP_1.0*/
void WorhpFree(OptVar*, Workspace*, Params*, Control*);
/* U WorhpFree@@WORHP_1.0*/
int WorhpGetParamCount(void);
/* U WorhpGetParamCount@@WORHP_1.2*/
const char* WorhpGetParamName(int);
/* U WorhpGetParamName@@WORHP_1.2*/
WorhpType WorhpGetParamType(int);
/* U WorhpGetParamType@@WORHP_1.2*/
void WorhpInit(OptVar*, Workspace*, Params*, Control*);
/* U WorhpInit@@WORHP_1.0*/
void WorhpPreInit(OptVar *, Workspace *, Params *, Control *);
/* U WorhpPreInit@@WORHP_1.0*/
bool WorhpSetBoolParam  (Params *, const char*, bool);
/* U WorhpSetBoolParam@@WORHP_1.2*/
bool WorhpSetDoubleParam(Params *, const char*, double);
/* U WorhpSetDoubleParam@@WORHP_1.2*/
bool WorhpSetIntParam   (Params *, const char*, int);
/* U WorhpSetIntParam@@WORHP_1.2*/
void Worhp(OptVar*, Workspace*, Params*, Control*);
/* U Worhp@@WORHP_1.0*/

#ifdef __cplusplus
}
#endif

#endif // WORHP_H__
