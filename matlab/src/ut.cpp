#include "ut.h"

extern "C"
{

bool utIsInterruptPending(void) { return false; }
void utSetInterruptPending(bool) {}

}
