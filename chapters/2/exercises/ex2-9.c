#include <assert.h>
#include <stdio.h>
#include <string.h>

// old bitcount
int bitcount(unsigned x) {
  int b;
  for (b = 0; x != 0; x >>= 1)
    if (x & 01)
      b++;
  return b;
}

// x &= (x-1) deletes the rightmost bit in x
unsigned int bitcount_fst(unsigned x) {
  int b = 0;
  while (x) {
    x &= (x - 1);
    b++;
  }
  return b;
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

int bitcount_str(const char *str) {
  const size_t sz = strlen(str);
  int tot;
  for (int i = 0; i != sz; ++i) {
    tot += str[i] == '1' ? 1 : 0;
  }
  return tot;
}

int main() {
  const char original[33] = "10100101001110010101000101001010";
  const int expected_bitcount = bitcount_str(original);
  assert(expected_bitcount == bitcount(binary_to_uint(original)));
  assert(expected_bitcount == bitcount_fst(binary_to_uint(original)));
}
