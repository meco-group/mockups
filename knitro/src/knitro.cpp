#include "knitro.h"

int  KNITRO_API KN_add_cons (KN_context_ptr, const KNINT, KNINT * const) { return 0; }
int  KNITRO_API KN_add_eval_callback (KN_context_ptr, const KNBOOL, const KNINT, const KNINT * const, KN_eval_callback * const, CB_context_ptr * const) { return 0; }
int  KNITRO_API KN_add_vars (KN_context_ptr, const KNINT, KNINT * const) { return 0; }
int  KNITRO_API KN_free (KN_context_ptr *) { return 0; }
int KNITRO_API KN_get_param_id(KN_context_ptr ,const char * const, int  * const) { return 0; }
int KNITRO_API KN_get_param_type(KN_context_ptr, const int, int * const) { return 0; }
int  KNITRO_API KN_get_solution (const KN_context_ptr, int * const, double * const, double * const, double * const) { return 0; }
int  KNITRO_API KN_new (KN_context_ptr *) { return 0; }
int  KNITRO_API KN_set_cb_grad (KN_context_ptr, CB_context_ptr, const KNINT, const KNINT * const, const KNLONG, const KNINT * const, const KNINT * const, KN_eval_callback * const) { return 0; }
int  KNITRO_API KN_set_cb_hess (KN_context_ptr, CB_context_ptr, const KNLONG, const KNINT * const, const KNINT * const, KN_eval_callback * const) { return 0; }
int  KNITRO_API KN_set_cb_user_params (KN_context_ptr, CB_context_ptr, void * const) { return 0; }
int  KNITRO_API KN_set_char_param(KN_context_ptr, const int, const char * const) { return 0; }
int  KNITRO_API KN_set_compcons (KN_context_ptr, const KNINT, const int * const, const KNINT  * const, const KNINT  * const) { return 0; }
int  KNITRO_API KN_set_con_lobnds_all (KN_context_ptr, const double * const) { return 0; }
int  KNITRO_API KN_set_con_upbnds_all (KN_context_ptr, const double * const) { return 0; }
int  KNITRO_API KN_set_double_param(KN_context_ptr, const int, const double) { return 0; }
int  KNITRO_API KN_set_int_param(KN_context_ptr, const int, const int) { return 0; }
int  KNITRO_API KN_set_obj_goal (KN_context_ptr, const int) { return 0; }
int  KNITRO_API KN_set_puts_callback (KN_context_ptr, KN_puts * const, void * const) { return 0; }
int  KNITRO_API KN_set_var_lobnds_all (KN_context_ptr, const double * const) { return 0; }
int  KNITRO_API KN_set_var_primal_init_values_all (KN_context_ptr, const double * const) { return 0; }
int  KNITRO_API KN_set_var_types_all (KN_context_ptr, const int * const) { return 0; }
int  KNITRO_API KN_set_var_upbnds_all (KN_context_ptr, const double * const) { return 0; }
int  KNITRO_API KN_solve (KN_context_ptr) { return 0; }
int  KNITRO_API KN_set_int_param_by_name(KN_context_ptr, const char * const, const int value) { return 0; }
