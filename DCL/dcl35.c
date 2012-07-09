/* Do not invoke a function using a type that does not match the function
 * definition
 */

/* BAD */

/* my_function has return type void */
static void my_function(int a) {
  /* ... */
  return;
}
 
int main(void) {
  int x;
  int (*new_function)(int a) = my_function;
  x = (*new_function)(10); /* the behavior is undefined */
  return 0;
}

/* NOT BAD */

/* my_function has return type int */
static int my_function(int a) {
  /* ... */
  return a;
}
 
int main(void) {
  int x;
  int (*new_function)(int a) = my_function;
  x = (*new_function)(10); /* x is 10 */
  return 0;
}

