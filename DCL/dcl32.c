/* Guarantee that mutually visible identifiers are unique */

// === EXAMPLE 1 ==============================================================

/* BAD */

/* longer than 32 characters */
extern int *global_symbol_definition_lookup_table_a;
extern int *global_symbol_definition_lookup_table_b;

/* NOT BAD */

extern int *a_global_symbol_definition_lookup_table;
extern int *b_global_symbol_definition_lookup_table;

// === EXAMPLE 2 ==============================================================

/* BAD */

extern int *\U00010401\U00010401\U00010401\U00010401;
extern int *\U00010401\U00010401\U00010401\U00010402;

/* NOT BAD */

extern int *\U00010401\U00010401\U00010401\U00010401;
extern int *\U00010402\U00010401\U00010401\U00010401;

