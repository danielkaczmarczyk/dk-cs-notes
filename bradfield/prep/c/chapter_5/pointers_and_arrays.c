#include <stdio.h>

int main(void) {
  int numbers[10];   

  for (int i = 0; i < 10; i++) {
    numbers[i] = 100 + i;
  }

  // declare a pointer to an int.
  int *ptr;

  // assign the pointer to point at the address of
  // the first element of the numbers array.
  ptr = &numbers[0];

  for (int j = 0; j < 10; j++) {
    printf("numbers[%d]: %d\n", j, *ptr);
    ptr++;
  }
}
