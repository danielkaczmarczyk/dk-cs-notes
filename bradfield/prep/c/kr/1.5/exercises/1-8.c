#include <stdio.h>

/* program that counts blanks, tabs, and newlines
 * by daniel
 */

int main(void) {
  int c, w, spaces, tabs, newlines;
  spaces = 0;
  tabs = 0;
  newlines = 0;

  while ((c = getchar()) != EOF) {
    if (c == ' ') ++spaces;
    if (c == '\t') ++tabs;
    if (c == '\n') ++newlines;
  }

  w = spaces + tabs + newlines;
  printf("spaces: %d, tabs: %d, newlines: %d\n", spaces, tabs, newlines);
  printf("The total count of whitespace is: %d\n", w);
}
