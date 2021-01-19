#include <stdio.h>
#define MAX_LINE_LENGTH 1000

/*
 * this program reads lines from input and at the end, prints out the longest one
 */

// TODO:
// [x] capture a whole line as a string of characters and store it
// [x] capture the length of this line
// [ ] allow for multiple lines and report on the longest

int main(void) {

  int i = 0;
  int c;
  char line[MAX_LINE_LENGTH];

  while ((c = getchar()) != '\n') {
    line[i] = c;
    i++;
  }

  line[i] = '\0';

  printf("your line: %s\n", line);
  printf("i value: %d\n", i);
  return 0; 
}
