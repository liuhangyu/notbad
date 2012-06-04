/* Declare file-scope objects or functions that do not need external linkage
 * as static
 */

/* BAD */

enum { MAX = 100 };
 
int helper(int i) {
  /* perform some computation based on i */
}
 
int main(void) {
  size_t i;
  int out[MAX];
 
  for (i = 0; i < MAX; i++) {
    out[i] = helper(i);
  }
 
  /* ... */
 
}

/* NOT BAD */

enum {MAX = 100};
 
static int helper(int i) {
  /* perform some computation based on i */
}
 
int main(void) {
  size_t i;
  int out[MAX];
 
  for (i = 0; i < MAX; i++) {
    out[i] = helper(i);
  }
 
  /* ... */
 
}