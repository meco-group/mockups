#ifndef _MADNLPCINTERFACE_H
#define _MADNLPCINTERFACE_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stddef.h>

/* Symbol visibility in DLLs */
#ifndef MADNLP_SYMBOL_EXPORT
#if defined(_WIN32) || defined(__WIN32__) || defined(__CYGWIN__)
#if defined(STATIC_LINKED)
#define MADNLP_SYMBOL_EXPORT
#else
#define MADNLP_SYMBOL_EXPORT __declspec(dllexport)
#endif
#elif defined(__GNUC__) && defined(GCC_HASCLASSVISIBILITY)
#define MADNLP_SYMBOL_EXPORT __attribute__((visibility("default")))
#else
#define MADNLP_SYMBOL_EXPORT
#endif
#endif


#define madnlp_int int
#define madnlp_real double

// structs
struct MadnlpCSolver;
struct MadnlpCStats;
struct MadnlpCDims;
struct MadnlpCInterface;

// function pointer types
typedef madnlp_int (*MadnlpCGetDim)(void* user_data);
typedef madnlp_int (*MadnlpCGetDouble)(double*, void* user_data);

typedef madnlp_int (*MadnlpCFullEvalObj)(const double*, double *, void*);
typedef madnlp_int (*MadnlpCFullEvalConstr)(const double*, double *, void*);
typedef madnlp_int (*MadnlpCFullEvalObjGrad)(const double*, double*, void*);
typedef madnlp_int (*MadnlpCFullEvalConstrJac)(const double*, double*, void*);
typedef madnlp_int (*MadnlpCFullEvalLagHess)(double, const double*, const double*, double*, void*);


struct MadnlpCDims { 
  size_t nw;
  size_t nc;
};

struct MadnlpCStats {
  double compute_sd_time;
  double duinf_time;
  double eval_hess_time;
  double eval_jac_time;
  double eval_cv_time;
  double eval_grad_time;
  double eval_obj_time;
  double initialization_time;
  double time_total;
  int eval_hess_count;
  int eval_jac_count;
  int eval_cv_count;
  int eval_grad_count;
  int eval_obj_count;
  int iterations_count;
  int return_flag;
};

struct MadnlpCInterface {
  /// @brief number of variables
  MadnlpCGetDim get_nw;
  /// @brief number of equality constraints
  MadnlpCGetDim get_nc;

  MadnlpCFullEvalLagHess full_eval_lag_hess;
  MadnlpCFullEvalConstrJac full_eval_constr_jac;
  MadnlpCFullEvalConstr full_eval_constr;
  MadnlpCFullEvalObjGrad full_eval_obj_grad;
  MadnlpCFullEvalObj full_eval_obj;

  void* user_data;
};

MADNLP_SYMBOL_EXPORT void madnlp_c_startup(int, char**);
MADNLP_SYMBOL_EXPORT struct MadnlpCSolver* madnlp_c_create(struct MadnlpCInterface* nlp_interface);
MADNLP_SYMBOL_EXPORT void madnlp_c_init(struct MadnlpCSolver* s);
MADNLP_SYMBOL_EXPORT void madnlp_c_update_cco_indexes(struct MadnlpCSolver* s);
MADNLP_SYMBOL_EXPORT madnlp_int madnlp_c_solve(struct MadnlpCSolver*);

/* -1 for not found, 0 for double, 1 for int, 2 for bool, 3 for string */
MADNLP_SYMBOL_EXPORT int madnlp_c_option_type(const char* name);
MADNLP_SYMBOL_EXPORT int madnlp_c_set_option_double(struct MadnlpCSolver* s, const char* name, double val);
MADNLP_SYMBOL_EXPORT int madnlp_c_set_option_bool(struct MadnlpCSolver* s, const char* name, int val);
MADNLP_SYMBOL_EXPORT int madnlp_c_set_option_int(struct MadnlpCSolver* s, const char* name, int val);
MADNLP_SYMBOL_EXPORT int madnlp_c_set_option_string(struct MadnlpCSolver* s, const char* name, const char* val);

MADNLP_SYMBOL_EXPORT const struct MadnlpCDims* madnlp_c_get_dims(struct MadnlpCSolver* s);
MADNLP_SYMBOL_EXPORT const struct MadnlpCStats* madnlp_c_get_stats(struct MadnlpCSolver* s);
MADNLP_SYMBOL_EXPORT void madnlp_c_destroy(struct MadnlpCSolver*);
MADNLP_SYMBOL_EXPORT void madnlp_c_shutdown(void);

#ifdef __cplusplus
}
#endif

#endif // _MADNLPCINTERFACE_H
