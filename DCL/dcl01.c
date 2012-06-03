/* Do not reuse variable names in subscopes */

/* BAD */

static char msg[100];
static const size_t msgsize = sizeof( msg);
 
void report_error(const char *str) {
  char msg[80];
  snprintf(msg, msgsize, "Error: %s\n", str);
  /* ... */
}
 
int main() {
  /* ... */
  report_error("some error");
}

/* NOT BAD */

static char message[100];
static const size_t message_size = sizeof( message);
 
void report_error(const char *str) {
  char msg[80];
  snprintf(msg, sizeof( msg), "Error: %s\n", str);
  /* ... */
}
 
int main() {
  /* ... */
  report_error("some error");
}

// === EXCEPTION ==============================================================

/* No problem, if the variable name used in the list of formal argument in the
 * function declaration.
 */

extern int name;
void f(char *name);   // declaration: no problem here
// ...
void f(char *arg) {   // definition: no problem, arg doesn't hide name
  // use arg
}