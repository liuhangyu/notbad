/* Do not use preprocessor directives inside macro arguments */

/* BAD */

memcpy(dest, src,
#ifdef PLATFORM1
  12
#else
  24
#endif
); // memcpy is a function, or macro?

/* NOT BAD */

#ifdef PLATFORM1
  memcpy(dest, src, 12);
#else
  memcpy(dest, src, 24);
#endif

// === EXCEPTION ==============================================================
/*
 * An exception can be made for invoking an unsafe macro with a function call
 * argument provided that the function has no side effects.
 */