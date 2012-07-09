/* Incompatible declarations of the same function or object */

/* BAD (Object Declaration) */

/* in a.c */
extern int i;   /* UB #14 */
 
int f(void) {
  return ++i;   /* UB #34 */
}
 
/* in b.c */
short i;   /* UB #14 */

/* BAD (Array Declaration) */

/* in a.c */
extern int *a;   /* UB #14 */
 
int f(unsigned i, int x) {
  int tmp = a[i];   /* UB #34: read access */
  a[i] = x;         /* UB #34: write access*/
  return tmp;
}
 
/* in b.c */
int a[] = { 1, 2, 3, 4 };   /* UB #14 */

/* BAD (Function Declaration) */

/* in a.c */
extern int f(int a);   /* UB #14 */
 
int g(int a) {
  return f(a);   /* UB #39 */
}
 
/* in b.c */
long f(long a) {   /* UB #14 */
  return a * 2;
}

/* BAD (Excessively Long Identifiers) */

/* in bash/bashline.h */
extern char* bash_groupname_completion_function(const char*, int);   /* UB #14 */
 
/* in a.c */
#include <bashline.h>
 
void f(const char *s, int i) {
  bash_groupname_completion_function(s, i);   /* UB #39 */
}
 
/* in b.c */
int bash_groupname_completion_func;   /* UB #14 */

// === EXCEPTION ==============================================================

/* a.c: */
int x = 0; /* the definition */
 
/* b.c: */
extern char x; /* incompatible declaration */
/* but no other references to 'x' */

