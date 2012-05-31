/* Use parentheses within macros around parameter names */

/* BAD */

#define CUBE(I) (I * I * I)

/* NOT BAD */

#define CUBE(I) ( (I) * (I) * (I) )

// === EXCEPTION 1 =============================================================
// Devided by coma
#define FOO(a, b, c) bar(a, b, c)

// === EXCEPTION 2 =============================================================
// Concatenation/stringification
#define JOIN(a, b) (a ## b)
#define SHOW(a) printf(#a " = %d\n", a)