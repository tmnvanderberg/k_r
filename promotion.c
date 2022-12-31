#include <stdbool.h>
#include <stdio.h>

int main() {
  long left = -1L;
  unsigned int right = 1U;
  printf("left value is %ld\n", left);
  printf("right value is %d\n", right);
  bool smaller = left < right;
  printf(smaller ? "left < right" : "left >= right");
  printf("\n");

  unsigned long int other_right = 1UL;
  printf("left value is %ld\n", left);
  printf("right value is %lu\n", other_right);
  bool o_smaller = left < other_right;
  printf(o_smaller ? "left < other_right" : "left >= other_right");
  printf("\n");

  signed char cres, c1, c2, c3;
  c1 = 100;
  c2 = 3;
  c3 = 4;
  // source: https://wiki.sei.cmu.edu/confluence/display/c/INT02-C.+Understand+integer+conversion+rules
  // assuming signed char is 8 bit, the product c1 * c2 (300) can not be represeted as signed char.
  // c1, c2 and c3 are promoted to int, and the result correctly calculated.
  // the final result is then truncated to fit cres.
  // in this case the final result fits, there is no data loss.
  cres = c1 * c2 / c3;
  printf("cres %c \n", cres);
  // in this example we lose data: the result is 100 * 3 * 4 / 2 = 600
  // which will be truncated to 600 mod 256 = 88 = X (asci) when assigning to cres
  signed char c4 = 2;
  cres = c1 * c2 * c3 / c4;
  printf("cres %c \n", cres);
}
