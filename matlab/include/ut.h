#ifndef ut_H
#define ut_H
#include "ut_Export.h"

extern "C"
{
 
// Undocumented Matlab API
bool ut_Export utIsInterruptPending(void);
void ut_Export utSetInterruptPending(bool);

}

#endif // ut_H
