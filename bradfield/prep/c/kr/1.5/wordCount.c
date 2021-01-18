#include <stdio.h>

/* program that counts lines, words, and characters in input.
 * a word is a sequence of characters that do not contain
 * a blank, a tab, or newline. it is a bare-bones version of
 * wc program.
 */

int main(void) {

  #define IN 1   /* inside a word */
  #define OUT 0  /* outdside a word */

  int c, chars, lines, state, wc;

  chars = lines = wc 0;
  state = OUT;

  while ((c = getchar()) != EOF) {
    chars++;
    if (c == '\n' || c == '\t' || c == ' ') {
      if (c == '\n') ++lines;
      if (state == IN) wc++;
      state = OUT;
    } else {
      state = IN;
    }
  }
  
  printf("\nTotals:\n");
  printf("Lines: %d\n", lines);
  printf("Chars: %d\n", chars);
  printf("Words: %d\n", wc);
  return 0;
}
