/* Beware of miscompiled volatile-qualified variables */

/* BAD */

const volatile int x;
volatile int y;
void foo(void) {
  for(y = 0; y < 10; y++) {
    int z = x;
  }
}

/*
 foo:
  movl $0, y
  movl x, %eax
  jmp .L2
.L3:
  movl y, %eax
  incl %eax
  movl %eax, y
.L2:
  movl y, %eax
  cmpl $10, %eax
  jg .L3
  ret
 */

/* NOT BAD */

int vol_read_int(volatile int *vp) {
  return *vp;
}
volatile int *vol_id_int(volatile int *vp) {
  return vp;
}
 
const volatile int x;
volatile int y;
void foo(void) {
  for(*vol_id_int(&y) = 0; vol_read_int(&y) < 10; *vol_id_int(&y) = vol_read_int(&y) + 1) {
    int z = vol_read_int(&x);
  }
}
