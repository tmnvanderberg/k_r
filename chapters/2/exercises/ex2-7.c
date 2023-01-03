#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

unsigned int binary_to_uint(const char *b) {
  unsigned int val = 0;
  int i = 0;

  if (b == NULL)
    return 0;

  while (b[i] == '0' || b[i] == '1') { // Found another digit.
    val <<= 1;
    val += b[i] - '0';
    i++;
  }
  return val;
}

// invert n bits from position p
unsigned invert(const unsigned x, const int p, const int n) {
  const size_t bits = 8u * sizeof(x);
  const int shiftw = bits - p - n + 1;

  const unsigned n_ones = ~(~0 << n);
  printf("n_ones: \n");
  print_bits(n_ones);

  const unsigned n_ones_start_p = n_ones << shiftw;
  printf("n_ones_start_p: \n");
  print_bits(n_ones_start_p);

  const unsigned selected_bits = x & n_ones_start_p;
  printf("selected_bits: \n");
  print_bits(selected_bits);

  const unsigned inverted_selected_bits = selected_bits ^ n_ones_start_p;
  printf("inverted_selected_bits: \n");
  print_bits(inverted_selected_bits);

  const unsigned x_without_selected = x & ~n_ones_start_p;
  printf("x_without_selected: \n");
  print_bits(x_without_selected);

  const unsigned ret = x_without_selected | inverted_selected_bits;
  printf("x: \n");
  print_bits(x);
  printf("ret: \n");
  print_bits(ret);

  return ret;
}

char *get_inverted_bitstring(char *orig, const int p, const int n) {
  char *r = (char *)malloc(strlen(orig) + 1);
  strcpy(r, orig);
  for (int i = p - 1; i != n + p - 1; ++i) {
    r[i] = r[i] == '0' ? '1' : '0';
  }
  return r;
}

int main() {
  char original[33] = "10100101001110010101000101001010";
  unsigned x = binary_to_uint(original);
  const int p = 10;
  const int n = 5;
  char *inverted = get_inverted_bitstring(original, p, n);
  printf("original:\n%s\ninverted:\n%s\n", original, inverted);
  unsigned inverted_i = binary_to_uint(inverted);
  printf("inverted_i: \n");
  print_bits(inverted_i);
  assert(invert(x, p, n) == inverted_i);
}
