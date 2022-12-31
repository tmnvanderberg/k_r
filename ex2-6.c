// modify bits p to p + n to n rightmost bits
void setbits(unsigned x, int p, int n) {


}

// get n bits from position p
unsigned getbits(unsigned x, int p, int n) {
  return (x >> (p + 1 + n)) & ~(~0 << n);
}

int main() {}
