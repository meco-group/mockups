#include "madnlp.h"

MADNLP_SYMBOL_EXPORT void madnlp_c_startup(int, char**) { }
MADNLP_SYMBOL_EXPORT struct MadnlpCSolver* madnlp_c_create(struct MadnlpCInterface* nlp_interface) { return 0; }
MADNLP_SYMBOL_EXPORT void madnlp_c_init(struct MadnlpCSolver* s) { }
MADNLP_SYMBOL_EXPORT void madnlp_c_update_cco_indexes(struct MadnlpCSolver* s) { }
MADNLP_SYMBOL_EXPORT madnlp_int madnlp_c_solve(struct MadnlpCSolver*) { return 0; }

/* -1 for not found, 0 for double, 1 for int, 2 for bool, 3 for string */
MADNLP_SYMBOL_EXPORT int madnlp_c_option_type(const char* name) { return 0; }
MADNLP_SYMBOL_EXPORT int madnlp_c_set_option_double(struct MadnlpCSolver* s, const char* name, double val) { return 0; }
MADNLP_SYMBOL_EXPORT int madnlp_c_set_option_bool(struct MadnlpCSolver* s, const char* name, int val) { return 0; }
MADNLP_SYMBOL_EXPORT int madnlp_c_set_option_int(struct MadnlpCSolver* s, const char* name, int val) { return 0; }
MADNLP_SYMBOL_EXPORT int madnlp_c_set_option_string(struct MadnlpCSolver* s, const char* name, const char* val) { return 0; }

MADNLP_SYMBOL_EXPORT const struct MadnlpCDims* madnlp_c_get_dims(struct MadnlpCSolver* s) { return 0; }
MADNLP_SYMBOL_EXPORT const struct MadnlpCStats* madnlp_c_get_stats(struct MadnlpCSolver* s) { return 0; }
MADNLP_SYMBOL_EXPORT void madnlp_c_destroy(struct MadnlpCSolver*) { }
MADNLP_SYMBOL_EXPORT void madnlp_c_shutdown(void) { }
