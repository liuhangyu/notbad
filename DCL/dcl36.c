/* Do not declare an identifier with conflicting linkage classifications */

/* BAD */

int i1 = 10;  /* definition, external linkage */
static int i2 = 20;  /* definition, internal linkage */
extern int i3 = 30;  /* definition, external linkage */
int i4;  /* tentative definition, external linkage */
static int i5;  /* tentative definition, internal linkage */
 
int i1;  /* valid tentative definition */
int i2;  /* not valid, linkage disagreement with previous */
int i3;  /* valid tentative definition */
int i4;  /* valid tentative definition */
int i5;  /* not valid, linkage disagreement with previous */
 
int main(void) {
  /* ... */
}

/* NOT BAD */

int i1 = 10;  /* definition, external linkage */
static int i2 = 20;  /* definition, internal linkage */
extern int i3 = 30;  /* definition, external linkage */
int i4;  /* tentative definition, external linkage */
static int i5;  /* tentative definition, internal linkage */
 
int main(void) {
  /* ... */
}

