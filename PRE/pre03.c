/* Prefer typedefs to defines for encoding types */

/* BAD */

#define cstring char *
cstring s1, s2;  // s2 not pointer

/* NOT BAD */

typedef char * cstring;
cstring s1;
cstring s2;