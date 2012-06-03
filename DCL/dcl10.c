/* Maintain the contract between the writer and caller of variadic functions */

// === EXAMPLE 1 ==============================================================

enum { va_eol = -1 };
 
unsigned int average(int first, ...) {
  unsigned int count = 0;
  unsigned int sum = 0;
  int i = first;
  va_list args;
 
  va_start(args, first);
 
  while (i != va_eol) {
    sum += i;
    count++;
    i = va_arg(args, int);
  }
 
  va_end(args);
  return(count ? (sum / count) : 0);
}

/* BAD */

int avg = average(1, 4, 6, 4, 1);

/* NOT BAD */

int avg = average(1, 4, 6, 4, 1, va_eol);

// === EXAMPLE 2 ==============================================================

/* BAD */

const char *error_msg = "Resource not available to user.";
printf("Error (%s): %s", error_msg);

/* NOT BAD */

const char *error_msg = "Resource not available to user.";
printf("Error: %s", error_msg);
