#include <stdio.h>
#define MAX_LINE_LENGTH 1000

int collectline(char line[], int max_length);
void copyline(char source[], char destination[]);

/*
 * this program reads lines from input and at the end, prints out the longest one
 */

// TODO:
// [x] capture a whole line as a string of characters and store it
// [x] capture the length of this line
// [ ] allow for multiple lines and report on the longest

int main(void) {

  char line[MAX_LINE_LENGTH];
  int line_length = 0;

  char longest_line[MAX_LINE_LENGTH];
  int longest_line_length = 0;

  while ((line_length = collectline(line, MAX_LINE_LENGTH)) > 0) {
    if (line_length > longest_line_length) {
      longest_line_length = line_length;
      copyline(line, longest_line);
    }
  }

  printf("longest line: %s\n", longest_line);
  printf("longest line length: %d\n", longest_line_length);
  return 0; 
}

/* captures a line of text, returns its length */
int collectline(char line[], int max_length) {
  int c, i;

  for (i = 0; i < max_length - 1 && (c = getchar()) != EOF && c != '\n'; i++) {
    line[i] = c;
  }

  if (c == '\n') {
    line[i] = c;
    i++;
  }

  line[i] = '\0';

  return i;
}

/* copies a line from source to destination */
void copyline(char source[], char destination[]) {
  int i = 0;
  while ((destination[i] = source[i]) != '\0') {
    ++i;
  }
}
