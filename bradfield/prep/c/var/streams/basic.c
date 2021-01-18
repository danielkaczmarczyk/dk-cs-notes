#include <stdio.h>

int main(void) {
  char i;
  do {
    i = getchar();
    putchar(i);
  } while (i != '.');
  putchar('\n');
}
