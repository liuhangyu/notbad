/* Ensure that restrict-qualified source and destination pointers in function
 * arguments do not reference overlapping objects
 */

/* restrict arguments should not point to overlapping memory regions */
void *memcpy(
  void * restrict s1,
  const void * restrict s2,
  size_t n
);

/* BAD */

char str[]= "test string";
char *ptr1=str;
char *ptr2;
 
ptr2 = ptr1 + 3;
memcpy(ptr2, ptr1, 6);

/* NOT BAD */

char str[]= "test string";
char *ptr1=str;
char *ptr2;
 
ptr2 = ptr1 + 3;
memmove(ptr2, ptr1, 6);  /* Replace call to memcpy() */

