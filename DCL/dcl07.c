/* Include the appropriate type information in function declarators */

// === EXAMPLE 1 ==============================================================

/* BAD */

int max(a, b)
int a, b;
{
  return a > b ? a : b;
}

/* NOT BAD */

int max(int a, int b) {
  return a > b ? a : b;
}

// === EXAMPLE 2 ==============================================================

/* BAD */

/* file_a.c source file */
int func(int one, int two, int three){
  printf("%d %d %d", one, two, three);
  return 1;
}

/* file_b.c source file */
func(1, 2);

/* NOT BAD */

/* file_b.c source file */
int func(int, int, int);
 
func(1, 2, 3);

// === EXAMPLE 3 ==============================================================

/* BAD */

int add(int x, int y, int z) {
   return x + y + z;
}
 
int main(int argc, char *argv[]) {
   int (*fn_ptr) (int, int);
   int res;
   fn_ptr = add;
   res = fn_ptr(2, 3);  /* incorrect */
   /* ... */
   return 0;
}

/* NOT BAD */

int add(int x, int y, int z) {
   return x + y + z;
}
 
int main(int argc, char *argv[]) {
   int (*fn_ptr) (int, int, int) ;
   int res;
   fn_ptr = add;
   res = fn_ptr(2, 3, 4);
   /* ... */
   return 0;
}
