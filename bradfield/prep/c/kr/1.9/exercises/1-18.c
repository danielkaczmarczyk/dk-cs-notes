#include <stdio.h>
#define ARRAY_SIZE 1000

/* a program that removes trailing blanks and tabs of input, and removes empty
 * lines. 
 *
 * how do I know that the trailing blanks and tabs have been removed? it won't come up on the screen
 * comparing length of the char[] could do the trick. it's the placement of the \0 char that will
 * define how long the string is. therefore, I need to reduce the string size by doing this - 
 * cutting off and placing the null byte earlier than it originally was placed. to achieve that
 * i could write a method that goes over a char array and fixes that, or i could modify the
 * collect_line method to do that.
 *
 * [ ] remove empty lines
 * [ ] remove trailing blanks and tabs
 */

int collect_line(char target[]);

int main(void) {

  int c;
  int current_line_len = 0;
  char current_line[ARRAY_SIZE];

  while (1) {
    current_line_len = collect_line(current_line);
    if (current_line_len == 0) {
      continue;
    } else if (current_line_len >= 80) {
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
