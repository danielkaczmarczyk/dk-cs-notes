#include <stdio.h>

int main(void) {
  int x = 7;

  int *ptr = &x;
  printf("The address of x is: %x\n", &ptr);
  printf("The value of x is: %d\n", *ptr);

  *ptr = 14;

  printf("The address of x is: %x\n", &ptr);
  printf("The value of x is: %d\n", *ptr);

}

