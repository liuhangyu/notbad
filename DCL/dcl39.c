/* Avoid information leak in structure padding */

/* BAD */

/* In this noncompliant code example, the padding bytes after char b
 * may not be initialized.
 */

#include <stddef.h>
 
struct test{
  int a;
  char b;
  int c;
};
 
/* ... safely copy bytes to user space ... */
extern int copy_to_user(void *dest, void *src, size_t size);
 
void do_stuff(void *usr_buf) {
  struct test arg = {.a=1,.b=2,.c=3};
 
  /* ... perform operations on arg ... */
 
  /* copy arg to user space */
  copy_to_user(usr_buf, &arg, sizeof(arg));
 
  /* ... */
}

/* AGAIN BAD */

/* 
  Here, the compiler could implement arg.b = 2 in the following way,
  = setting the low byte of a 32-bit register to 2, leaving the high bytes unchanged, and
  = storing all 32 bits of the register into memory
*/
#include <stddef.h>
#include <string.h>
 
struct test{
  int a;
  char b;
  int c;
};
 
/* ... safely copy bytes to user space ... */
extern int copy_to_user(void *dest, void *src, size_t size);
 
void do_stuff(void *usr_buf) {
  struct test arg;
 
  /* initializes all bytes (including padding bytes) of the struct to zero */
  memset(&arg, 0, sizeof(arg));
 
  arg.a = 1;
  arg.b = 2;
  arg.c = 3;
 
  /* ... perform operations on arg ... */
 
  /* copy arg to user space */
  copy_to_user(usr_buf, &arg, sizeof(arg));
 
  /* ... */
}

/* NOT BAD (GCC-way) */

#include <stddef.h>
 
struct test{
  int a;
  char b;
  int c;
} __attribute__((__packed__));
 
/* ... safely copy bytes to user space ... */
extern int copy_to_user(void *dest, void *src, size_t size);
 
void do_stuff(void *usr_buf) {
  struct test arg = {.a=1,.b=2,.c=3};
 
  /* ... perform operations on arg ... */
 
  /* copy arg to user space */
  copy_to_user(usr_buf, &arg, sizeof(arg));
 
  /* ... */
}

/* NOT BAD (MSVC-way) */

#include <stddef.h>
 
#pragma pack(1) /* 1 byte */
struct test{
  int a;
  char b;
  int c;
};
 
/* ... safely copy bytes to user space ... */
extern int copy_to_user(void *dest, void *src, size_t size);
 
void do_stuff(void *usr_buf) {
  struct test arg = {.a=1,.b=2,.c=3};
 
  /* ... perform operations on arg ... */
 
  /* copy arg to user space */
  copy_to_user(usr_buf, &arg, sizeof(arg));
 
  /* ... */
}

/* NOT BAD (adding padding bytes) */

#include <stddef.h>
 
struct test{
  int a;
  char b;
  char padding_1, padding_2, padding_3;
  int c;
};
 
/* ... safely copy bytes to user space ... */
extern int copy_to_user(void *dest, void *src, size_t size);
 
void do_stuff(void *usr_buf) {
 
  /* make sure c is the next byte after the last padding byte */
  static_assert(offsetof(struct test, c) == \
    offsetof(struct test, padding_3) + 1, \
    "Error: not compiling for IA-32");
 
  struct test arg = {.a=1,.b=2,.c=3};
  arg.padding_1 = 0;
  arg.padding_2 = 0;
  arg.padding_3 = 0;
 
  /* ... perform operations on arg ... */
 
  /* copy arg to user space */
  copy_to_user(usr_buf, &arg, sizeof(arg));
 
  /* ... */
}

/* NOT BAD */

#include <stddef.h>
#include <string.h>
 
struct test{
  int a;
  char b;
  int c;
};
 
/* ... safely copy bytes to user space ... */
extern int copy_to_user(void *dest, void *src, size_t size);
 
void do_stuff(void *usr_buf) {
  struct test arg = {.a=1,.b=2,.c=3};
  unsigned char r[sizeof(arg)];
 
  /* ... perform operations on arg ... */
 
  /* just before passing arg to the function */
  memset(r, 0, sizeof(r));
  memset(r+offsetof(struct test,a), arg.a, sizeof(arg.a));
  memset(r+offsetof(struct test,b), arg.b, sizeof(arg.b));
  memset(r+offsetof(struct test,c), arg.c, sizeof(arg.c));
  /* now pass r to the function */
  copy_to_user(usr_buf, r, sizeof(r));
 
  /* ... */
}

