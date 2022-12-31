#include <math.h>
#include <stdio.h>
#include <string.h>

char *strip_prefix(char *str) {
  if (strlen(str) < 2) {
    return str;
  }
  if (str[0] == '0') {
    if (str[1] == 'x' || str[1] == 'X') {
      memmove(str, str + 2, strlen(str) - 2 + 1);
    }
  }
  return str;
}

int hd_i(char digit) {
  if (digit >= '0' && digit <= '9') {
    return digit - '0';
  }
  if (digit >= 'A' && digit <= 'Z') {
    return 10 + digit - 'A';
  }
  if (digit >= 'a' && digit <= 'z') {
    return 10 + digit - 'a';
  }
  return -1;
}

int hexstr_to_int(char *hex_str) {
  hex_str = strip_prefix(hex_str);
  const size_t len = strlen(hex_str);
  int ret = 0;
  for (int i = 0; i != len; ++i) {
    ret += hd_i(hex_str[i]) * pow(16, len - i - 1);
  }
  return ret;
}

void pr_dec(char *str) { printf("%s -> %d\n", str, hexstr_to_int(str)); }

int main() {
  char hex[20] = "0xa2132";
  pr_dec(hex);
  char hex2[5] = "0x01";
  pr_dec(hex2);
}
