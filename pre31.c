/* Avoid side-effects in arguments to unsafe macros */

/* BAD */

#define ABS(x) (((x) < 0) ? -(x) : (x))

/*
m = ABS(++n); // undefined behavior

==

m = (((++n) < 0) ? -(++n) : (++n));  // undefined behavior
*/

/* NOT BAD */

#define ABS(x) (((x) < 0) ? -(x) : (x)) /* UNSAFE */

/*
++n;
m = ABS(n)

Alternatively, the macro can be renamed ABS_UNSAFE()
*/

/* AGAIN NOT BAD */

inline int abs(int x) {
  return (((x) < 0) ? -(x) : (x));
}
/*
m = abs(++n);
*/

// === EXCEPTION ==============================================================
/*
 * An exception can be made for invoking an unsafe macro with a function call
 * argument provided that the function has no side effects.
 */