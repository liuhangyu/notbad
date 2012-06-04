/* Minimize the scope of variables and functions */

// === EXAMPLE 1 ==============================================================

/* BAD */

unsigned int count = 0;
 
void counter() {
  if (count++ > MAX_COUNT) return;
  /* ... */
 
}

/* NOT BAD */

void counter() {
  static unsigned int count = 0;
  if (count++ > MAX_COUNT) return;
  /* ... */
 
}

// === EXAMPLE 2 ==============================================================

/* BAD */

public void doStuff(...){
  size_t i = 0;
 
  for (i=0; i < 10; i++){
    /* Perform operations */
  }
}

/* NOT BAD */

public void doStuff(...){
  for (size_t i=0; i < 10; i++) {
    /* Perform operations */
  }
}
