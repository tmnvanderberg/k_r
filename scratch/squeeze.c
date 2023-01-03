#include <stdbool.h>
#include <stdio.h>
#include <string.h>

// delete any char from s that is present in ref
void squeeze(char s[], char ref[]) {
  int i, j;
  for (i = j = 0; s[i] != '\0'; ++i) {
    bool found = false;
    for (int k = 0; k != strlen(ref); ++k) {
      const char c = ref[k];
      if (s[i] == c) {
        found = true;
        break;
      }
    }
    if (!found) {
      s[j++] = s[i];
    }
    s[j] = '\0';
  }
}

int main() {
  char s[25] = "kadjfwefhafkjdafdsklj";
  char ref[3] = "kj";
  printf("origina: %s\n", s);
  squeeze(s, ref);
  printf("resultstr: %s\n", s);
}
