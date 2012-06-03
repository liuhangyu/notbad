/* Use typedefs to improve code readability */

/* BAD */

void (*signal(int, void (*)(int)))(int);

/* NOT BAD */

typedef void (*SighandlerType)(int signum);
extern SighandlerType signal(
  int signum,
  SighandlerType handler
);
