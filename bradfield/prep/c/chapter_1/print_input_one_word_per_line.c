#include <stdio.h>

#define IN 1   // in a word
#define OUT 0  // outside a word


int main(void) {
  int c;
  int state;

  state = OUT;

  while ((c = getchar()) != EOF) {
    if (c == ' ' || c == '\n' || c == '\t') {
      state = OUT;
      if (c != '\n') {
        putchar('\n');
      }
    } else if (state == OUT){
      state = IN;
    }

    if (state == IN) {
      putchar(c);
    }
  }
  printf("\n");
}
