/* Do not declare or define a reserved identifier */

// === EXAMPLE 1 ==============================================================

/* BAD (Header Guard) */

#ifndef _MY_HEADER_H_
#define _MY_HEADER_H_
 
/* contents of <my_header.h> */
 
#endif /* _MY_HEADER_H_ */

/* NOT BAD */

#ifndef MY_HEADER_H
#define MY_HEADER_H
 
/* contents of <my_header.h> */
 
#endif /* MY_HEADER_H */

// === EXAMPLE 2 ==============================================================

/* BAD (File Scope Objects) */

#include <stddef.h>   /* for size_t */
 
static const size_t _max_limit = 1024;
size_t _limit = 100;
 
unsigned int getValue(unsigned int count) {
  return count < _limit ? count : _limit;
}

/* NOT BAD */

#include <stddef.h>   /* for size_t */
 
static const size_t max_limit = 1024;
size_t limit = 100;
 
unsigned int getValue(unsigned int count) {
  return count < limit ? count : limit;
}

// === EXAMPLE 3 ==============================================================

/* BAD (Reserved Macros) */

#include <inttypes.h>   /* for int_fast16_t and PRIdFAST16 */
 
// INT*_MAX -- conflict (See Section 7.31.10 of the C standard.)
static const int_fast16_t INTFAST16_LIMIT_MAX = 12000;
 
void print_fast16(int_fast16_t val) {
    enum { MAX_SIZE = 80 };
    char buf [MAX_SIZE];  // MAX_SIZE -- conflict
    if (INTFAST16_LIMIT_MAX < val)
      sprintf(buf, "The value is too large");
    else
      snprintf(buf, MAX_SIZE, "The value is %" PRIdFAST16, val);
    /* ... */
}

/* NOT BAD */

#include <inttypes.h>   /* for int_fast16_t and PRIdFAST16 */
 
static const int_fast16_t MY_INTFAST16_UPPER_LIMIT = 12000;
 
void print_fast16(int_fast16_t val) {
    enum { BUFSIZE = 80 };
    char buf [BUFSIZE];
    if (MY_INTFAST16_UPPER_LIMIT < val)
      sprintf(buf, "The value is too large");
    else
      snprintf(buf, BUFSIZE, "The value is %" PRIdFAST16, val);
    /* ... */
}

// === EXAMPLE 4 ==============================================================

/* BAD (Identifiers with external linkage) */

#include <stddef.h>
 
void* malloc(size_t nbytes) {
  void *ptr;
  /* allocate storage from own pool and set ptr */
  return ptr;
}
 
void free(void *ptr) {
  /* return storage to own pool */
}

/* NOT BAD */

#include <stddef.h>
 
void* my_malloc(size_t nbytes) {
  void *ptr;
  /* allocate storage from own pool and set ptr */
  return ptr;
}
 
void* my_calloc(size_t nelems, size_t elsize) {
  void *ptr;
  /* allocate storage from own pool and set ptr */
  return ptr;
}
 
void* my_realloc(void *ptr, size_t nbytes) {
  /* reallocate storage from own pool and set ptr */
  return ptr;
}
 
void my_free(void *ptr) {
  /* return storage to own pool */
}

// === EXAMPLE 5 ==============================================================

/* BAD */

extern int errno;

/* NOT BAD */

#include <errno.h>

