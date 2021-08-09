#include <stdio.h>

void swap(int *px, int *py) {
  int temp;

  temp = *px;
  *px = *py;
  *py = temp;
}

int main() {

  int x = 3;
  int y = 5;

  printf("Variables before the swap: x: %d, y: %d\n", x, y);
  swap(&x, &y);
  printf("Variables after the swap:  x: %d, y: %d\n", x, y);
}


