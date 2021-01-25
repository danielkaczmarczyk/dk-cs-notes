#include <stdio.h>

void swap(int *a, int *b);

int main(void) {
  int a, b;
  a = 13;
  b = 42;  
  printf("a: %d, b: %d\n", a, b);
  swap(&a, &b);
  printf("a: %d, b: %d\n", a, b);
}

void swap(int *a, int *b) {
  int temp;
  temp = *a;
  *a = *b;
  *b = temp;
}

