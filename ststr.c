#include <stdio.h>
#include <string.h>

int main() {
  const char haystack[20] = "kdjffhwkokwowk";
  const char needle[10] = "kok";
  char *ret = strstr(haystack, needle);
  printf("found the substring %s \n", ret);
}
