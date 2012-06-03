/* Use meaningful symbolic constants to represent literal values */

// === EXAMPLE 1 ==============================================================

/* BAD */

if (age >= 18) {
   /* Take action */
}
else {
  /* Take a different action */
}

/* NOT BAD */

enum { ADULT_AGE=18 };

if (age >= ADULT_AGE) {
   /* Take action */
}
else {
  /* Take a different action */
}

// === EXAMPLE 2 ==============================================================

/* BAD */

char buffer[256];
fgets(buffer, 256, stdin);

/* NOT BAD */

enum { BUFFER_SIZE=256 };
 
char buffer[BUFFER_SIZE];
fgets(buffer, BUFFER_SIZE, stdin);

/* AGAIN NOT BAD */

char buffer[256];
fgets(buffer, sizeof(buffer), stdin);

// === EXAMPLE 3 ==============================================================

/* BAD */

LDAP *ld = ldap_init("localhost", 1234);
if (ld == NULL) {
  perror("ldap_init");
  return(1);
}

/* NOT BAD */

#ifndef PORTNUMBER     /* might be passed on compile line */
#  define PORTNUMBER 1234
#endif
 
#ifndef HOSTNAME        /* might be passed on compile line */
#  define HOSTNAME "localhost"
#endif
 
/* ... */
 
LDAP *ld = ldap_init(HOSTNAME, PORTNUMBER);
if (ld == NULL) {
  perror("ldap_init");
  return(1);
}