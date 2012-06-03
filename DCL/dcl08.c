/* Properly encode relationships in constant definitions */

// === EXAMPLE 1 ==============================================================

/* BAD */

enum { IN_STR_LEN=18, OUT_STR_LEN=20 };

/* NOT BAD */

enum { IN_STR_LEN=18, OUT_STR_LEN=IN_STR_LEN+2 };

// === EXAMPLE 2 ==============================================================

/* BAD */

enum { ADULT_AGE=18 };
 
/* misleading, relationship established when none exists */
enum { ALCOHOL_AGE=ADULT_AGE+3 };

/* NOT BAD */

enum { ADULT_AGE=18 };
enum { ALCOHOL_AGE=21 };
