#include <stdio.h>

int power(int m, int n);

int main(void) {

  for (int i = 0; i < 15; i++) {
    printf(
      "%2d %12d %12d %12d\n",
      i,
      power(-3, i),
      power(3,i),
      power(2, i)
      ); 
  }  
  return 0;
}

/* power: raise base to n-th power; n >= 0 */
int power(int base, int n) {
  int p = 1;

  for (int i = 1; i <= n; ++i) {
    p = p * base;
  }

  return p;
}

