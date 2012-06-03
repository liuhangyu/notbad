/* Do not declare more than one variable per declaration */

// === EXAMPLE 1 ==============================================================

/* BAD */

char *src = 0, c = 0; // c isn't pointer

/* NOT BAD */

char *src;    /* source string */
char c;       /* character being tested */

// === EXAMPLE 2 ==============================================================

/* BAD */

int i, j = 1; // i remains uninitialized

/* NOT BAD */

int i = 1;
int j = 1;

// === EXCEPTION ==============================================================

size_t bitcount(size_t n) {
    const size_t limit = sizeof n * CHAR_BIT;
    size_t count = 0;
    for (size_t i = 0, j = 1; i < limit; ++i, j <<= 1) {
        if (n & j)
            ++count;
    }
    return count;
}
