/* Only one int_struct object is created, and all elements of ints array pointed
 * to one struct, with last assigned value.
 */

// === EXAMPLE 1 ==============================================================

/* BAD (Static Variables) */

const char *p;
void dont_do_this(void) {
    const char str[] = "This will change";
    p = str; /* dangerous */
    /* ... */
}
 
void innocuous(void) {
    const char str[] = "Surprise, surprise";
}
/* ... */
dont_do_this();
innocuous();
/* p might be pointing to "Surprise, surprise" */

/* NOT BAD (Similar Scope) */

void this_is_OK(void) {
    const char str[] = "Everything OK";
    const char *p = str;
    /* ... */
}
/* p is inaccessible outside the scope of string str */

/* NOT BAD AGAIN (Differing Scope) */

const char *p;
void is_this_OK(void) {
    const char str[] = "Everything OK?";
    p = str;
    /* ... */
    p = NULL;
}

// === EXAMPLE 2 ==============================================================

/* BAD (Return Values) */

char *init_array(void) {
   char array[10];
   /* Initialize array */
   return array;
}

/* NOT BAD */

void init_array(char array[]) {
   /* Initialize array */
   return;
}
 
int main(int argc, char *argv[]) {
   char array[10];
   init_array(array);
   /* ... */
   return 0;
}

// === EXAMPLE 3 ==============================================================

/* BAD */


void squirrel_away(char **ptr_param) {
   char local[10];
   /* Initialize array */
   *ptr_param = local;
}
 
void rodent() {
  char *ptr;
  squirrel_away(&ptr);
  /* ptr is live but invalid here */
}

