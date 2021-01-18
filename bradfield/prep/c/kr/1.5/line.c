#include <stdio.h>

// count lines in input
int main(void) {
  int lines, c;

  lines = 1;

  while((c = getchar()) != EOF) {
    if (c == '\n') {
        lines++;
      }
  }

  printf("\nnumber of lines in input: %d\n", lines);
} 

