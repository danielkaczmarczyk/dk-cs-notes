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
  // ptr = &numbers[0];
  // since the address of the first element is synonymous
  // to the name of the array, it's possible to do it like that
  // too:
  ptr = numbers;

  for (int j = 0; j < 10; j++) {
    printf("numbers[%d]: %d\n", j, *ptr);
    ptr++;
  }
}
