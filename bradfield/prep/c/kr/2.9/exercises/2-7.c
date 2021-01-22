#include <stdio.h>

/* k&r exercise 2-7
 * invert(x,p,n)
 * write a function that returns x with the n bits that begin at position
 * p inverted, leaving the others unchanged
 */

int invert(unsigned x, int p, int n);

int main(void) {
  invert(218, 2, 4);    
}


int invert(unsigned x, int p, int n) {
  unsigned y;

  y = x >> p; // y == 54
  printf("%d\n", y);
  y = ~y;     // y == 201
  printf("%d\n", y);

  int mask = 0;
  mask = ~mask;
  mask = mask << n;
  mask = ~mask;
  y = y & mask;
  y = y << p; // y == 36
  printf("%d\n", y);

  int mask2 = 0;
  mask2 = ~mask2;
  mask2 = ;
  return 1;
}
