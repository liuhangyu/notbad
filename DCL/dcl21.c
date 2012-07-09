/* Understand the storage of compound literals */

/* For example, nex object allocated in stask */

void func(void) {
  int *ip = (int[4]){1,2,3,4};
  /* ... */
}

/* BAD */

#include <stdio.h>
 
typedef struct int_struct {
  int x;
} int_struct;
 
#define MAX_INTS 10
 
int main(void){
  size_t i;
  int_struct *ints[MAX_INTS];
 
  for (i = 0; i < MAX_INTS; i++) {
    /* Only one int_struct object is created, and all elements of ints array
     * pointed to one struct, with last assigned value.
     */
    ints[i] = &(int_struct){i};
  }
 
  for (i = 0; i < MAX_INTS; i++) {
    printf("%d\n", ints[i]->x);
  }
}

/* NOT BAD */

#include <stdio.h>
 
typedef struct int_struct {
  int x;
} int_struct;
 
#define MAX_INTS 10
 
int main(void){
  size_t i;
  int_struct ints[MAX_INTS];
 
  for (i = 0; i < MAX_INTS; i++) {
    // Copy value of int_struct instance to array element
    ints[i] = (int_struct){i};
  }
 
  for (i = 0; i < MAX_INTS; i++) {
    printf("%d\n", ints[i].x);
  }
}

