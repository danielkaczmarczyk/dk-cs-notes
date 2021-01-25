#include <stdio.h>

/*
 * write a program that prints its input one word per line
 */

int main(void) {

  #define IN 1
  #define OUT 0

  int c;

  while ((c = getchar()) != EOF) {
    if (c == ' ' || c == '\t') {
      putchar('\n');
    } else {
      putchar(c);
    }
  }
}
