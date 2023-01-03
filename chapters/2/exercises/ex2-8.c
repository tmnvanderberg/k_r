#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

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

unsigned int rotate(const unsigned int x) {
  const unsigned trailing_one = ~(1 << 1);
  const unsigned last_bit = x & trailing_one;

  const unsigned last_bit_first_position = last_bit
                                           << (8 * sizeof(unsigned) - 1);
  printf("last_bit_first_position: \n");
  print_bits(last_bit_first_position);

  const unsigned first_bit_null = ~(trailing_one << (8 * sizeof(unsigned) - 1));
  printf("first_bit_null: \n");
  print_bits(first_bit_null);

  return ((x >> 1) & first_bit_null) + last_bit_first_position;
}

// return the value of x rotated to the right by n positions (i.e. bitshifted
// with wrap) smalls recursive
unsigned int rotate_n(const unsigned int x, const int n) {
  if (n == 0)
    return x;
  else
    return rotate_n(rotate(x), n - 1);
}

int main() {
  {
    char original[33] = "10100101001110010101000101001010";
    char goal[33] = "01010010100111001010100010100101";
    const unsigned original_i = binary_to_uint(original);
    printf("original_i: \n");
    print_bits(original_i);
    const unsigned goal_i = binary_to_uint(goal);
    printf("goal_i: \n");
    print_bits(goal_i);
    const unsigned rotated_i = rotate(original_i);
    printf("rotated_i: \n");
    print_bits(rotated_i);
    assert(rotated_i == goal_i);
  }
  printf("----\n");
  {
    char original[33] = "10100101001110010101000101001011";
    char goal[33] = "11010010100111001010100010100101";
    const unsigned original_i = binary_to_uint(original);
    printf("original_i: \n");
    print_bits(original_i);
    const unsigned goal_i = binary_to_uint(goal);
    printf("goal_i: \n");
    print_bits(goal_i);
    const unsigned rotated_i = rotate(original_i);
    printf("rotated_i: \n");
    print_bits(rotated_i);
    assert(rotated_i == goal_i);
  }
  printf("----\n");
  {
    char original[33] = "10100101001110010101000101001010";
    char goal[33] =
        "10010101010010100111001010100010"; // bad: i did this by hand
    const int n = 7;
    const unsigned original_i = binary_to_uint(original);
    printf("original_i: \n");
    print_bits(original_i);
    const unsigned goal_i = binary_to_uint(goal);
    printf("goal_i: \n");
    print_bits(goal_i);
    const unsigned rotated_i = rotate_n(original_i, n);
    printf("rotated_i: \n");
    print_bits(rotated_i);
    assert(rotated_i == goal_i);
  }
}
