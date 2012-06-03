/* Wrap multi-statement macros in a do-while loop */

/* BAD */

/*
 * Swaps two values.
 * Requires tmp variable to be defined.
 */
#define SWAP(x, y) \
  tmp = x; \
  x = y; \
  y = tmp

/*
int x, y, z, tmp;
if (z == 0)
  SWAP( x, y);

==

int x, y, z, tmp;
if (z == 0)
  tmp = x;
x = y;
y = tmp;
*/

/* AGAIN BAD */

/*
 * Swaps two values.
 * Requires tmp variable to be defined.
 */
#define SWAP(x,y) { tmp=x; x=y; y=tmp; }

/*
if (x > y)
  SWAP(x,y);          // Branch 1
else 
  do_something();     // Branch 2

==

if (x > y) { /* Single-branch if-statement!!!
 
  tmp = x;   // The one and only branch consists
  x = y;     // of the block.
  y = tmp;
}
;            // empty statement
else         // ERROR!!! "parse error before else"
  do_something();
*/

/* NOT BAD */

/*
 * Swaps two values.
 * Requires tmp variable to be defined.
 */
#define SWAP(x, y) \
  do { \
    tmp = x; \
    x = y; \
    y = tmp; } \
  while (0)