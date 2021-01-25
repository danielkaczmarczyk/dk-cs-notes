#include <stdio.h>
#define ARRAY_SIZE 1000

/* a program that prints out lines of input that are over 80 characters long */

int collect_line(char target[]);

int main(void) {

  int c;
  int current_line_len = 0;
  char current_line[ARRAY_SIZE];

  while (1) {
    current_line_len = collect_line(current_line);
    if (current_line_len >= 80) {
      printf("%s\n", current_line);
    } else {
      printf("line shorter than 80. len: %d\n", current_line_len);
    }
  }

  // printf("%d\n", current_line_len);

  // collect a line of input into temporary memory
  // if it is longer, print it
  // if not, keep collecting
  // stop collecting if EOF is found

}

/* 
 * A function that collects a line of input from the stdin, copies it to
 * target char array, and returns the line length.
 */
int collect_line(char target[]) {
  int c;
  int i = 0;
  while((c = getchar()) != '\n') {
    target[i] = c; 
    i++;
  }

  if (c == '\n') {
    target[i] = '\n';
    i++; 
  }

  target[i] = '\0';
  return i; 
}
