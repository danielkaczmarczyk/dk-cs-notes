#include <stdio.h>

/* k&r exercise 2-7
 * invert(x,p,n)
 * write a function that returns x with the n bits that begin at position
 * p inverted, leaving the others unchanged
 */

int invert(unsigned x, int p, int n);

int main(void) {
  unsigned result = invert(218, 2, 4);    
  printf("%u\n", result);
}


int invert(unsigned x, int p, int n) {
  return x ^ ~ (~0 << n) << p;
}
