/* Declare identifiers before using them */

// === EXAMPLE 1 ==============================================================

/* BAD */

/* Many C translators will continue to treat such declarations as implying the
 * type int
 */
extern foo;

/* NOT BAD */

extern int foo;

// === EXAMPLE 2 ==============================================================

/* BAD (Implict Function Declaration) */

int main(void) {
  int c = foo();  // expects -- extern int func()
  printf("%d\n", c);
  return 0;
}
 
int foo(int a) {
  return a;
}

/* NOT BAD */

int foo(int);
 
int main(void) {
  int c = foo(0);
  printf("%d\n", c);
  return 0;
}
 
int foo(int a) {
  return a;
}

// === EXAMPLE 3 ==============================================================

/* BAD (Implict Return Type) */

/* Expected int */
foo(void) {
  return UINT_MAX;  // converted to -1
}
 
int main(void) {
  long long c = foo();
  printf("%lld\n", c);
  return 0;
}

/* NOT BAD */

unsigned int foo(void) {
  return UINT_MAX;
}
 
int main(void) {
  long long c = foo();
  printf("%lld\n", c);
  return 0;
}

