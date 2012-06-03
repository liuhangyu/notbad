/* Prefer inline or static functions to function-like macros */

// === EXAMPLE 1 =============================================================== 

/* BAD */

#define CUBE(X) ((X) * (X) * (X))

/*
int i = 2;
int a = BAD_CUBE(++i)

==

int a = 81 / ((++i) * (++i) * (++i));
*/

/* NOT BAD */

inline int cube(int i) {
	return i * i * i;
}

// === EXAMPLE 2 ===============================================================

size_t count = 0;

/* BAD */

#define EXEC_BUMP(func) (func(), ++count)

void g(void) {
	pritf("Called g, count = %zu.\n", count);
}

void aFunc(void) {
	size_t count = 0;
	while (count++ < 10) {
		EXEC_BUMP(g);
		/* local "count" variable was used */
	}
}

/* NOT BAD */

size_t count = 0;

void g(void) {
	printf("Called g, count = %zu.\n", count);
}

typedef void (*exec_func)(void);
inline void exec_bump(exec_func f) {
	f();
	++count;
}

void aFunc(void) {
	size_t count = 0;
	while (count++ < 10) {
		exec_bump(g);
	}
}

// === EXAMPLE 3 ===============================================================

/* BAD */

#define F(x) (++operations, ++calls_to_F, 2 * x)
#define G(x) (++operations, ++calls_to_G, x + 1)

/*
y = F(x) + G(y)

Order of execution is not guaranteed. For example:

read operations into register 0
read operations into register 1
increment register 0
increment register 1
store register 0 into operations
store register 1 into operations

*/

/* NOT BAD */

inline int f(int x) {
	++operations;
	++calls_to_f;
	return 2 * x;
}

inline int g(int x) {
	++operations;
	++calls_to_g;
	return x + 1
}

/*
y = f(x) + g(x);
*/

// === EXCEPTION 1 =============================================================

// Macros is not bad for concatenation and stringification

enum Color { Color_Red, Color_Green, Color_Blue };
static const struct {
  enum Color  color;
  const char *name;
} colors[] = {
#define COLOR(color)   { Color_ ## color, #color }
  COLOR(Red), COLOR(Green), COLOR(Blue)
};

// === EXCEPTION 2 =============================================================

// Macros is not bad for yield a compile-time constants

#define ADD_M(a, b) ((a) + (b))
static inline int add_f(int a, int b) {
  return a + b;
}

/* === OTHER EXCEPTIONS ========================================================
 * Macros is not bad for:
 * 
 * 3. implement type-generic functions
 * 4. call params by name, instead of calling by value
 * 5. implement for local functions
 */