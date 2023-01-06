#include <stdio.h>
#include <string.h>
// convert characters into visible escape sequences
int escape(char *t, char *s) {
  for (int i = 0; i != strlen(t); ++i) {
    const char ch = t[i];
    switch (ch) {
    case '\n':
      printf("\\n\n");
      break;
    case '\t':
      printf("\\t\n");
      break;
    default:
      break;
    }
  }
}

int main() {
  char t[4] = "\na\t";
  char s[4];
  escape(t, s);
}
