/* Do not define unsafe macros */

/* BAD */

#define ABS(x) (((x) < 0) ? -(x) : (x))
 
/*
void f(int n) {
  int m;
  m = ABS(++n); // undefined behavior
  // ...
}
*/

/* NOT BAD */

inline int Abs(x) {
  return x < 0 ? -x : x;
}

/* NOT BAD for GNU */

#define ABS(x) ({int tmp = (x); tmp < 0 ? -tmp : tmp; })