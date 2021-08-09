#include <stdio.h>

int main(void) {
  printf("we cookin'\n");
  
  int c;
  int space = 0;

  while ((c = getchar()) != EOF) {
    if (c == ' ') {
      space = 1;
      continue;
    } else {
      if (space == 1) {
        putchar(' ');
        space = 0;
      }
      putchar(c);
    }
  }
}

