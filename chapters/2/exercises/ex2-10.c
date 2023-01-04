#include <stdio.h>
#include <string.h>

char lower(const char c) {
  return (c >= 'A' && c <= 'Z') ? ('a' + c - 'A') : c;
}

int main() {
  const char chars[50] = "ksfjIFDKFefwjfeiw>JFEJFSDEWJIF29rj";
  char lowerchars[50];
  for (int i = 0; i != strlen(chars); ++i) {
    lowerchars[i] = lower(chars[i]);
    printf("%c -> %c\n", chars[i], lowerchars[i]);
  }
}
