/* Use volatile for data that cannot be cached */

// === EXAMPLE 1 ==============================================================

/* BAD (Missing volatile) */

#include <signal.h>
 
sig_atomic_t interrupted;   /* bug: not declared volatile */
 
void sigint_handler(int signum) {
  interrupted = 1;   /* assignment may not be visible in main() */
}
 
int main(void) {
  signal(SIGINT, sigint_handler);
  while (!interrupted) {   /* loop may never terminate */
   /* do something */
  }
  return 0;
}

/* BAD (Cast to volatile) */

extern int compute(void*);
 
static _Bool end_processing;
 
void* thread_func(void *arg) {
  while (0 == *(volatile _Bool*)&end_processing) {
    int status;
    status = compute(arg);
    if (status) {
      /* notify other threads to end processing */
      end_processing = 1;
      break;
    }
  }
  return 0;
}

/* NOT BAD */

#include <signal.h>
 
volatile sig_atomic_t interrupted;
 
void sigint_handler(int signum) {
  interrupted = 1;
}
 
int main(void) {
  signal(SIGINT, sigint_handler);
  while (!interrupted) {
   /* do something */
  }
  return 0;
}

