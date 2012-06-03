/* Do not replace secure functions with deprecated or obsolescent functions */

/* BAD */

#define vsnprintf(buf, size, fmt, list) \
vsprintf(buf, fmt, list)

/* NOT BAD */

#include <stdio.h>
#ifndef __USE_ISOC99
  /* reimplements vsnprintf() */
  #include "my_stdio.h"
#endif