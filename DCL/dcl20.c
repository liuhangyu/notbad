/* Always specify void even if a function accepts no arguments */

// === EXAMPLE 1 ==============================================================

/* BAD */

/* in foo.h */
void foo();
 
/* in foo.c */
void foo() {
  int i = 3;
  printf("i value: %d\n", i);
}
 
/* in caller.c */
#include "foo.h"
 
foo(3);

/* NOT BAD */

/* in foo.h */
void foo(void);
 
/* in foo.c */
void foo(void) {
  int i = 3;
  printf("i value: %d\n", i);
}
 
/* in caller.c */
#include "foo.h"
 
foo(3);  // Compile time error or warning

// === EXAMPLE 2 ==============================================================

/* BAD */

/* compile using gcc4.3.3 */
void foo() {
  /* use asm code to retrieve i
   * implicitly from caller
   * and transfer it to a less privileged file */
}
 
/* caller */
foo(i); /* i is fed from user input */

/* NOT BAD */

void foo(void) {
  int i = 3;
  printf("i value: %d\n", i);
}
