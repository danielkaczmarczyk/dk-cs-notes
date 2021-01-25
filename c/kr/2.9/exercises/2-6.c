#include <stdio.h>

/* k&r exercise 2-6 */

int setbits(unsigned x, int p, int n, unsigned y);

int main(void) {
  setbits(218, 3, 3, 170);
}

/*
 * returns x with the n bits that begin at position p
 * set to rightmost n bits of y, leaving other bits
 * unchanged.
 *
 * all comments for setbits(218, 3, 3, 170)
 */
int setbits(unsigned x, int p, int n, unsigned y) {

  // get the mask for y - it is a n long mask.
  unsigned mask = ~0;           // 1111 1111
  mask = mask << n;     // shift n to get 1111 1000
  mask = ~mask;         // flip to get    0000 0111

  // AND y and the mask to 'delete' the bits that are not 1's
  // therefore extracting the desired n bits 
  y = y & mask;  // result 0000 0010 (decimal 2)

  // shift y p bits to the left to place the desired bit pattern where we need it
  // it will not be used until the last step though.
  y = y << p;

  // now we need to reuse the mask we've created earlier. reminder, currently
  // it is 0000 0111. we need to move the 1's to the left to 'aim' at the
  // spot we want to mask in x.
  mask = mask << p;

  // in order to keep the bits we want in x, we need to AND x with the inverted mask
  // inverting the mask:
  mask = ~mask;

  // &'ing x and mask:
  x = x & mask;

  // now finally, to insert the bit pattern we extracted from y, we need to OR
  // x and y.
  
  x = x | y;
  printf("%d\n", x); // expected: 210;

}

