/* Do not conclude macro definitions with a semicolon */

// === EXAMPLE 1 ===============================================================

/* BAD */

#define FOR_LOOP(n)  for(i=0; i<(n); i++);

/*
int i;
FOR_LOOP(3)
{
  puts("Inside for loop\n");
}
*/

/* NOT BAD */

#define FOR_LOOP(n)  for(i=0; i<(n); i++)
 
int i;
FOR_LOOP(3)
{
  puts("Inside for loop\n");
}

// === EXAMLE 2 ================================================================

/* BAD */

#define INCREMENT(x, max) ((x) = ((x) + 1) % (max));

/*
int index = 0;
int value;
value = INCREMENT(index, 10) + 2;
*/

/* NOT BAD */

#define INCREMENT(x, max) ((x) = ((x) + 1) % (max))