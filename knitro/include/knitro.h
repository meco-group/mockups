#ifndef KNITRO_H__
#define KNITRO_H__

#ifndef TRUE
#define TRUE 1
#endif
#ifndef FALSE
#define FALSE 0
#endif

#include <stddef.h>
#include <float.h>

/*------------------------------------------------------------------*/
/*     EXPORT MACROS                                                */
/*------------------------------------------------------------------*/

#ifdef __cplusplus
extern "C" {
#endif

#ifdef _WIN32
  #ifdef MAKE_KNITRO_DLL
    #define KNITRO_API __declspec(dllexport) __stdcall
  #else
    #define KNITRO_API __stdcall
  #endif
#else
  #if (__GNUC__ >= 4) || (__INTEL_COMPILER)
    #define KNITRO_API __attribute__ ((visibility ("default")))
  #else
    #define KNITRO_API
  #endif
#endif

/* Define Knitro integer types.  Use KNLONG to support 64-bit integers. */
typedef int KNINT;
#ifdef _WIN64
    typedef __int64 KNLONG;
#elif _WIN32
    typedef int KNLONG;
#else
    typedef long long KNLONG;
#endif
typedef KNINT   KNBOOL;
#define KNTRUE  1
#define KNFALSE 0

typedef struct KN_eval_request {
    int a;
    int b;
    const double * c;
    const double * d;
    const double * e;
    const double * f;
} KN_eval_request, *KN_eval_request_ptr;
typedef struct KN_eval_result {
    double * a;
    double * b;
    double * c;
    double * d;
    double * e;
    double * f;
    double * g;
    double * h;
} KN_eval_result, *KN_eval_result_ptr;

typedef struct KN_context KN_context, *KN_context_ptr;
typedef struct LM_context LM_context, *LM_context_ptr;
typedef struct CB_context CB_context, *CB_context_ptr;
typedef int KN_eval_callback (KN_context_ptr,
                              CB_context_ptr,
                              KN_eval_request_ptr const,
                              KN_eval_result_ptr  const,
                              void              * const);

typedef int  KN_puts (const char * const, void * const);

int  KNITRO_API KN_add_cons (      KN_context_ptr, const KNINT, KNINT * const);
int  KNITRO_API KN_add_eval_callback (KN_context_ptr, const KNBOOL, const KNINT, const KNINT * const, KN_eval_callback * const, CB_context_ptr   * const);
int  KNITRO_API KN_add_vars (KN_context_ptr, const KNINT, KNINT * const);
int  KNITRO_API KN_free (KN_context_ptr *);
int KNITRO_API KN_get_param_id(KN_context_ptr ,const char * const, int  * const);
int KNITRO_API KN_get_param_type(KN_context_ptr, const int, int * const);
int  KNITRO_API KN_get_solution (const KN_context_ptr, int * const, double * const, double * const, double * const);
int  KNITRO_API KN_new (KN_context_ptr *);
int  KNITRO_API KN_set_cb_grad (KN_context_ptr, CB_context_ptr, const KNINT, const KNINT * const, const KNLONG, const KNINT * const, const KNINT * const, KN_eval_callback * const);
int  KNITRO_API KN_set_cb_hess (KN_context_ptr, CB_context_ptr, const KNLONG, const KNINT * const, const KNINT * const, KN_eval_callback * const);
int  KNITRO_API KN_set_cb_user_params (KN_context_ptr, CB_context_ptr, void * const);
int  KNITRO_API KN_set_char_param(KN_context_ptr, const int, const char * const);
int  KNITRO_API KN_set_compcons (KN_context_ptr, const KNINT, const int * const, const KNINT  * const, const KNINT  * const);
int  KNITRO_API KN_set_con_lobnds_all (KN_context_ptr, const double * const);
int  KNITRO_API KN_set_con_upbnds_all (KN_context_ptr, const double * const);
int  KNITRO_API KN_set_double_param(KN_context_ptr, const int, const double);
int  KNITRO_API KN_set_int_param(KN_context_ptr, const int, const int);
int  KNITRO_API KN_set_obj_goal (KN_context_ptr, const int);
int  KNITRO_API KN_set_puts_callback (KN_context_ptr, KN_puts * const, void * const);
int  KNITRO_API KN_set_var_lobnds_all (KN_context_ptr, const double * const);
int  KNITRO_API KN_set_var_primal_init_values_all (KN_context_ptr, const double * const);
int  KNITRO_API KN_set_var_types_all (KN_context_ptr, const int * const);
int  KNITRO_API KN_set_var_upbnds_all (KN_context_ptr, const double * const);
int  KNITRO_API KN_solve (KN_context_ptr);

#ifdef __cplusplus
}
#endif

#endif // KNITRO_H__
