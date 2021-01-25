#include <stdio.h>

int main(void) {
  int c;

  printf("eof: %d", EOF);

  while ((c = getchar()) != EOF) {
    putchar(c);
  }
}

