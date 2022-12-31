#include <stdio.h>

int main() {
  char str[] = "test123";
  printf("str = %p\n", str);
  printf("&str[0] = %p\n", &str[0]);
  printf("str printed as %%s is %s\n", str);
  printf("str printed as %%s is %s\n", str);
  printf("*str = %c\n", *str);
  printf("str[0] = %c\n", str[0]);
}
