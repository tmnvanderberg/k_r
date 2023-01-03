#include <assert.h>
#include <stdio.h>

unsigned get_rm_bits(unsigned int x, int n) { return x & ~(~0 << n); }

void print_bits(const unsigned int num) {
  unsigned int number = num;
  const size_t sz = sizeof(unsigned int);
  const size_t max = 1 << (sz * 8 - 1);
  for (int i = 0; i < sz * 8; ++i) {
    printf("%u", number & max ? 1 : 0);
    number = number << 1;
  }
  printf("\n");
}

unsigned setbits(const unsigned x, const int p, const int n, const unsigned y) {
  printf("asking for %d bits starting from %d\n", n, p);

  const size_t bits = 8u * sizeof(x);
  printf("bits: %zu\n", bits);

  const unsigned rm = get_rm_bits(y, n);
  printf("rm:\n  ");
  print_bits(rm);

  const int shiftw = bits - p - n + 1;
  printf("shifting left by %d\n", shiftw);
  const unsigned int rm_shifted = (rm << shiftw);
  printf("rm_shifted:\n  ");
  print_bits(rm_shifted);

  const unsigned n_ones = ~(~0 << n);
  printf("n_ones:\n  ");
  print_bits(n_ones);

  const unsigned n_ones_start_p = n_ones << shiftw;
  printf("n_ones_start_p:\n  ");
  print_bits(n_ones_start_p);

  const unsigned n_zeros_start_p = ~n_ones_start_p;
  printf("n_zeros_start_p:\n  ");
  print_bits(n_zeros_start_p);

  const unsigned cleaned_x = x & n_zeros_start_p;
  printf("cleaned_x:\n  ");
  print_bits(cleaned_x);

  const unsigned int ret = cleaned_x | rm_shifted;
  printf("x=\n  ");
  print_bits(x);
  printf("y=\n  ");
  print_bits(y);
  printf("ret:\n  ");
  print_bits(ret);

  return ret;
}

int main() {
  int n = 6;
  unsigned int x = 2852131882u;
  assert(get_rm_bits(x, n) == 42u);
  const unsigned int y = 2852131882;
  const int p = 6;
  assert(setbits(x, n, p, y) == 2906657834u);
}
