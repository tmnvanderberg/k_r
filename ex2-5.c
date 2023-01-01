#include <stdio.h>
#include <string.h>

// ret first location in s1 where a char from s2 occurs, or -1
int any(char *s1, char *s2) {
  for (int i = 0; i != strlen(s1); ++i) {
    for (int j = 0; j != strlen(s2); ++j) {
      if (s1[i] == s2[j]) {
        return i;
      }
    }
  }
  return -1;
}

int main() {
  char s1[20] = "diagjfxwater";
  char s2[4] = "xyz";
  printf("found match at %d\n", any(s1, s2));
}
