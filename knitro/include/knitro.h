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
          int      type;
          int      threadID;
    const double * x;
    const double * lambda;
    const double * sigma;
    const double * vec;
} KN_eval_request, *KN_eval_request_ptr;

typedef struct KN_eval_result {
    double * obj;
    double * c;
    double * objGrad;
    double * jac;
    double * hess;
    double * hessVec;
    double * rsd;
    double * rsdJac;
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
int  KNITRO_API KN_set_int_param_by_name(KN_context_ptr, const char * const, const int value);
int  KNITRO_API KN_load_param_file(KN_context_ptr, const char * const);
    

#define KN_INFINITY DBL_MAX

#define KN_PARAMTYPE_INTEGER 0
#define KN_PARAMTYPE_FLOAT   1
#define KN_PARAMTYPE_STRING  2


#define KN_COMPONENT_VAR     1
#define KN_COMPONENT_OBJ     2
#define KN_COMPONENT_CON     3
#define KN_COMPONENT_RSD     4

#define KN_OBJGOAL_MINIMIZE    0
#define KN_OBJGOAL_MAXIMIZE    1

#define KN_OBJTYPE_CONSTANT  -1
#define KN_OBJTYPE_GENERAL    0
#define KN_OBJTYPE_LINEAR     1
#define KN_OBJTYPE_QUADRATIC  2

#define KN_CONTYPE_CONSTANT  -1
#define KN_CONTYPE_GENERAL    0
#define KN_CONTYPE_LINEAR     1
#define KN_CONTYPE_QUADRATIC  2
#define KN_CONTYPE_CONIC      3

#define KN_CCTYPE_VARVAR      0
#define KN_CCTYPE_VARCON      1
#define KN_CCTYPE_CONCON      2

#define KN_VARTYPE_CONTINUOUS  0
#define KN_VARTYPE_INTEGER     1
#define KN_VARTYPE_BINARY      2

#define KN_RC_EVALFC          1
#define KN_RC_EVALGA          2
#define KN_RC_EVALH           3
#define KN_RC_EVALHV          7
#define KN_RC_EVALH_NO_F      8
#define KN_RC_EVALHV_NO_F     9
#define KN_RC_EVALR          10
#define KN_RC_EVALRJ         11
#define KN_RC_EVALFCGA       12

#  define KN_HESSOPT_AUTO                0
#  define KN_HESSOPT_EXACT               1
#  define KN_HESSOPT_BFGS                2
#  define KN_HESSOPT_SR1                 3
#  define KN_HESSOPT_PRODUCT_FINDIFF     4
#  define KN_HESSOPT_PRODUCT             5
#  define KN_HESSOPT_LBFGS               6
#  define KN_HESSOPT_GAUSS_NEWTON        7

#define KN_RC_OPTIMAL_OR_SATISFACTORY 0
#define KN_RC_OPTIMAL                 0
#define KN_RC_NEAR_OPT               -100
#define KN_RC_FEAS_XTOL              -101
#define KN_RC_FEAS_NO_IMPROVE        -102
#define KN_RC_FEAS_FTOL              -103
#define KN_RC_INFEASIBLE             -200
#define KN_RC_INFEAS_XTOL            -201
#define KN_RC_INFEAS_NO_IMPROVE      -202
#define KN_RC_INFEAS_MULTISTART      -203
#define KN_RC_INFEAS_CON_BOUNDS      -204
#define KN_RC_INFEAS_VAR_BOUNDS      -205
#define KN_RC_UNBOUNDED              -300
#define KN_RC_UNBOUNDED_OR_INFEAS    -301
#define KN_RC_ITER_LIMIT_FEAS        -400
#define KN_RC_TIME_LIMIT_FEAS        -401
#define KN_RC_FEVAL_LIMIT_FEAS       -402
#define KN_RC_MIP_EXH_FEAS           -403
#define KN_RC_MIP_TERM_FEAS          -404
#define KN_RC_MIP_SOLVE_LIMIT_FEAS   -405
#define KN_RC_MIP_NODE_LIMIT_FEAS    -406
#define KN_RC_ITER_LIMIT_INFEAS      -410
#define KN_RC_TIME_LIMIT_INFEAS      -411
#define KN_RC_FEVAL_LIMIT_INFEAS     -412
#define KN_RC_MIP_EXH_INFEAS         -413
#define KN_RC_MIP_SOLVE_LIMIT_INFEAS -415
#define KN_RC_MIP_NODE_LIMIT_INFEAS  -416
#define KN_RC_CALLBACK_ERR           -500
#define KN_RC_LP_SOLVER_ERR          -501
#define KN_RC_EVAL_ERR               -502
#define KN_RC_OUT_OF_MEMORY          -503
#define KN_RC_USER_TERMINATION       -504
#define KN_RC_OPEN_FILE_ERR          -505
#define KN_RC_BAD_N_OR_F             -506
#define KN_RC_BAD_CONSTRAINT         -507
#define KN_RC_BAD_JACOBIAN           -508
#define KN_RC_BAD_HESSIAN            -509
#define KN_RC_BAD_CON_INDEX          -510
#define KN_RC_BAD_JAC_INDEX          -511
#define KN_RC_BAD_HESS_INDEX         -512
#define KN_RC_BAD_CON_BOUNDS         -513
#define KN_RC_BAD_VAR_BOUNDS         -514
#define KN_RC_ILLEGAL_CALL           -515
#define KN_RC_BAD_KCPTR              -516
#define KN_RC_NULL_POINTER           -517
#define KN_RC_BAD_INIT_VALUE         -518
#define KN_RC_LICENSE_ERROR          -520
#define KN_RC_BAD_PARAMINPUT         -521
#define KN_RC_LINEAR_SOLVER_ERR      -522
#define KN_RC_DERIV_CHECK_FAILED     -523
#define KN_RC_DERIV_CHECK_TERMINATE  -524
#define KN_RC_OVERFLOW_ERR           -525
#define KN_RC_BAD_SIZE               -526
#define KN_RC_BAD_VARIABLE           -527
#define KN_RC_BAD_VAR_INDEX          -528
#define KN_RC_BAD_OBJECTIVE          -529
#define KN_RC_BAD_OBJ_INDEX          -530
#define KN_RC_BAD_RESIDUAL           -531
#define KN_RC_BAD_RSD_INDEX          -532
#define KN_RC_INTERNAL_ERROR         -600

#ifdef __cplusplus
}
#endif

#endif // KNITRO_H__
