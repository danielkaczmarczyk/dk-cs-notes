#include <stdio.h>

int count = 0;

int counter() {
  count++;
  return count;
}

void print_counter(int count) {
  printf("Count: %d\n", count);
}

int main(void) {
  print_counter(counter());
  print_counter(counter());
  print_counter(counter());
  print_counter(counter());
  print_counter(counter());
  return 0;
}


