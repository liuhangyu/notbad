/* Understand the type issues associated with variadic functions */

// === EXAMPLE 1 ==============================================================

/* Type interpretation error */

/* BAD */

const char *error_msg = "Error occurred";
printf("%s:%d", 15, error_msg);

/* NOT BAD */

const char *error_msg = "Error occurred";
printf("%d:%s", 15, error_msg);

// === EXAMPLE 2 ==============================================================

/* Type alignment error */

/* BAD */

long long a = 1;
const char msg[] = "Default message";
printf("%d %s", a, msg);

/* NOT BAD */

long long a = 1;
const char msg[] = "Default message";
printf("%lld %s", a, msg);

// === EXAMPLE 3 ==============================================================

/* NULL */

/* BAD */

char* string = NULL;
printf("%s %d\n", string, 1);

/* NOT BAD */

char* string = NULL;
printf("%s %d\n", (string ? string : "null"), 1);
