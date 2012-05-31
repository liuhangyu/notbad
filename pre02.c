/* Macro replacement lists should be parenthesized */

// === EXAMPLE 1 ===============================================================

/* BAD */

#define CUBE(X) (X) * (X) * (X)

/* NOT BAD */

#define CUBE(X) ((X) * (X) * (X))

// === EXAMPLE 2 ===============================================================

/* BAD */

#define EOF -1
/*
will be compilled without warnings

if (getchar() EOF) {
   ...
}
*/

/* NOT BAD */

enum { END_OF_FILE = -1 };

// === EXEPTION 1 ==============================================================
// functions
#define MY_PID getpid()

// === EXCETION 2 ==============================================================
// arrays and struct/union members
#define NEXT_FREE block->next_free
#define CID customer_record.account.cid
#define TOOFAR array[MAX_ARRAY_SIZE]
