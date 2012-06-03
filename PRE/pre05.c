/* Understand macro replacement when concatenating tokens
 * or performing stringification
*/

// === EXAMPLE 1 ===============================================================

#define static_assert(e) \
  typedef char JOIN(assertion_failed_at_line_, __LINE__) \
    [(e) ? 1 : -1]

/* BAD */

#define JOIN(x, y) x ## y

/* NOT BAD */

#define JOIN(x, y) JOIN_AGAIN(x, y)
#define JOIN_AGAIN(x, y) x ## y

// === EXAMPLE 2 ===============================================================

/* BAD */

#define str(s) #s
#define foo 4

/*
str(foo)
--> "foo"
*/

/* NOT BAD */

#define xstr(s) str(s)
#define str(s) #s
#define foo 4