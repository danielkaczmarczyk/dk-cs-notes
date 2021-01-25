#include <stdio.h>

int main(void) {
  int value;

  printf("The value of EOF is: %d\n", EOF);
  printf("Please provide something for getchar\n");
  value = getchar() != EOF;
  printf("The value of `value` that resulted from 'getchar() != EOF': %d\n", value);
}
