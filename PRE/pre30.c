/* Do not create a universal character name through concatenation */

/* BAD */

#define assign(uc1, uc2, val) uc1##uc2 = val;

/*
int \u0401;
assign( \u04, 01, 4);
*/

/* NOT BAD */

#define assign(ucn, val) ucn = val;

/* 
int \u0401;
assign( \u0401, 4);
*/