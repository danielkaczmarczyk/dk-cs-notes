#include <stdio.h>

int main(void) {
  printf("Processing input...\n"); 

  int c;
  int blanks = 0;
  int tabs = 0;
  int newlines = 0;

  while ((c = getchar()) != EOF) {
    if (c == ' ') {
      blanks += 1;
    } else if (c == '\t') {
      tabs += 1;
    } else if (c == '\n') {
      newlines += 1;
    }
  }

  printf("The final results are in, everybody gather round!\n");
  printf("Blanks: %d\n", blanks);
  printf("Tabs: %d\n", tabs);
  printf("Newlines: %d\n", newlines);
}
