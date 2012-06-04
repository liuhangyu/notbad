/* Implement abstract data types using opaque types */

// === EXAMPLE 1 ==============================================================

/* BAD */

struct string_mx {
    size_t size;
    size_t maxsize;
    unsigned char strtype;
    char *cstr;
};
 
typedef struct string_mx string_mx;
 
/* Function declarations */
extern errno_t strcpy_m(string_mx *s1, const string_mx *s2);
extern errno_t strcat_m(string_mx *s1, const string_mx *s2);
/* etc. */

/* NOT BAD */

struct string_mx;
typedef struct string_mx string_mx;
 
/* Interface function declarations */
extern errno_t strcpy_m(string_mx *s1, const string_mx *s2);
extern errno_t strcat_m(string_mx *s1, const string_mx *s2) ;
/* etc. */

/* Hiding from stupid users somewhere deep... */

struct string_mx {
    size_t size;
    size_t maxsize;
    unsigned char strtype;
    char *cstr;
};
