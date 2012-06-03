/* Use a static assertion to test the value of a constant expression */

/* BAD */

struct timer {
  uint8_t MODE;
  uint32_t DATA;
  uint32_t COUNT;
};
 
int func(void) {
  assert(offsetof(timer, DATA) == 4);
}

/* NOT BAD */

struct timer {
  uint8_t MODE;
  uint32_t DATA;
  uint32_t COUNT;
};
 
#if (offsetof(timer, DATA) != 4)
  #error "DATA must be at offset 4"
#endif

/* AGAIN NOT BAD */

struct timer {
  uint8_t MODE;
  uint32_t DATA;
  uint32_t COUNT;
};
 
// static_assert(constant-expression, string-literal); added in C11 and C++0x
static_assert(offsetof(struct timer, DATA) == 4, "DATA must be at offset 4");
