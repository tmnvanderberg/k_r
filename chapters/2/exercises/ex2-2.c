#include <stdio.h>
#include <stdlib.h>

int main() {
  const size_t lim = 5;
  char s[lim];
  for (int i = 0; i < lim - 1; ++i) {
    const char c = getchar();
    if (c == '\n') {
      break;
    }
    if (c == EOF) {
      break;
    }
    s[i] = c;
  }
}
