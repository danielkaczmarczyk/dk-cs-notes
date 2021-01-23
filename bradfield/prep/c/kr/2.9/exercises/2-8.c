#include <stdio.h>

int rightrot(unsigned x, int n);

int main(void) {
  int result = rightrot(106, 5);
  printf("%d\n", result);
}


int rightrot(unsigned x, int n) {
  int lsb;

  while (n-- > 0) {
    // check if the lsb is 1 or 0
    lsb = x & 1;
    // if it is one, replace msb with 1
    x >>= 1;
    if (lsb) {
      x = x | ~(~0 >> 1);
    }
    // if it is zero, do nothing
  }
  return x;
}
