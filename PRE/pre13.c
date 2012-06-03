/* Avoid changing control flow in macro definitions */

/* BAD */

#define SAFE_MALLOC(T, p, n)                         \
  if (0 == ((p) = (T*)malloc((n)))) {                \
    fprintf(stderr, "%s:%d (%s): out of memory\n",   \
            __FILE__, __LINE__, __func__);           \
    exit(1);                                         \
  }

/*
void f(const int *array, size_t nelems) {
  int *a;
  size_t nbytes = nelems * sizeof *a;
  int buffer[128];
 
  if (sizeof buffer < nbytes)
    SAFE_MALLOC(int, a, nbytes);
  else
    a = buffer;
 
  memcpy(a, array, nbytes);
 
  // Proceed to use a...
 
  if (a != buffer)
    free(a);
}
*/

/* NOT BAD */

#define SAFE_MALLOC(n) \
  safe_malloc(n, __FILE__, __LINE__, __func__)
 
void* safe_malloc(size_t n,
                  const char *file,
                  int line,
                  const char *func) {
  void *p = malloc(n);
  if (0 == p) {
    fprintf(stderr, "%s:%d (%s): out of memory\n",
            file, line, func);
    exit(1);
  }
  return p;
}
 
/*
void f(const int *array, size_t nelems) {
  int *a;
  size_t nbytes = nelems * sizeof *a;
  int buffer[128];
 
  if (sizeof buffer < nbytes)
    a = (int*)SAFE_MALLOC(nbytes);
  else
    a = buffer;
 
  memcpy(a, array, nbytes);
 
  // Proceed to use a...
 
  if (a != buffer)
    free(a);
}
*/