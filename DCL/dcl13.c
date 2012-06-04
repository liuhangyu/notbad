/* Declare function parameters that are pointers to values not changed by the
 * function as const
 */

// === EXAMPLE 1 ==============================================================

/* BAD */

void foo(int *x) {
  if (x != NULL) {
    *x = 3; /* visible outside function */
  }
  /* ... */
}
 
// OR

void foo(const int *x) {
  if (x != NULL) {
    *x = 3; /* generates compiler error */
  }
  /* ... */
}

/* NOT BAD */

void foo(const int * x) {
  if (x != NULL) {
    printf("Value is %d\n", *x);
  }
  /* ... */
}

// === EXAMPLE 2 ==============================================================

/* BAD */

char *strcat_nc(char *s1, char *s2);
 
char *str1 = "str1";
const char *str2 = "str2";
char str3[9] = "str3";
const char str4[9] = "str4";
 
strcat_nc(str3, str2);  /* Compiler warns that str2 is const */
strcat_nc(str1, str3);  /* Attempts to overwrite string literal! */
strcat_nc(str4, str3);  /* Compiler warns that str4 is const */

/* NOT BAD */

char *strcat(char *s1, const char *s2);
 
char *str1 = "str1";
const char *str2 = "str2";
char str3[9] = "str3";
const char str4[9] = "str4";
 
strcat(str3, str2); 
/* Args reversed to prevent overwriting string literal */
strcat(str3, str1); 
strcat(str4, str3);  /* Compiler warns that str4 is const */