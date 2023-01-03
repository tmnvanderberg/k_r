
#include <float.h>
#include <limits.h>
#include <stdio.h>

int main() {
  // determine ranges for char, short, int, long
  // both signed and unsigned
  printf("char size: %zu bits, giving min %d and max %d \n",
         sizeof(char) * CHAR_BIT, CHAR_MIN, CHAR_MAX);
  printf("unsigned char size: %zu bits, giving min %d and max %d \n",
         sizeof(unsigned char) * CHAR_BIT, 0, UCHAR_MAX);
  printf("short size: %zu bits, giving min %d and max %d \n",
         sizeof(short) * CHAR_BIT, SHRT_MIN, SHRT_MAX);
  printf("unsigned short size: %zu bits, giving min %d and max %d \n",
         sizeof(unsigned short) * CHAR_BIT, 0, USHRT_MAX);
  printf("int size: %zu bits, giving min %d and max %d \n",
         sizeof(int) * CHAR_BIT, INT_MIN, INT_MAX);
  printf("unsigned int size: %zu bits, giving min %u and max %u \n",
         sizeof(unsigned int) * CHAR_BIT, 0, UINT_MAX);
  printf("long size: %zu bits, giving min %ld and max %ld \n",
         sizeof(long) * CHAR_BIT, LONG_MIN, LONG_MAX);
  printf("unsigned long size: %zu bits, giving min %u and max %lu \n",
         sizeof(unsigned long) * CHAR_BIT, 0, ULONG_MAX);
  // determine ranges for float, double, long double
  printf("float has min %f and max %f\n", FLT_MIN, FLT_MAX);
  printf("double has min %f and max %f\n", DBL_MIN, DBL_MAX);
  printf("long double has min %Lf and max %Lf\n", LDBL_MIN, LDBL_MAX);
  return 0;
}
