#include <stdio.h>
#define ARRAY_SIZE 1000

/* a program that removes trailing blanks and tabs of input, and removes empty
 * lines. 
 */

int collect_line(char target[]);
int trim(char target[], int len);

int main(void) {

  int c;
  int current_line_len = 0;
  char current_line[ARRAY_SIZE];

  while (1) {
    current_line_len = collect_line(current_line);
    if (current_line_len == 1) {
      continue;
    } else if (current_line_len >= 80) {
      printf("%s\n", current_line);
    } else {
      trim(current_line, current_line_len);      
    }
  }
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

/*
 * goes over the char array supplied and remembers the position of the last
 * non-whitespace character. removes the outstanding whitespace by moving the
 * null byte and the newline.
 */
int trim(char target[], int len) {
  int i = 0;
  int c = target[i];
  int last_char_pos = 0;

  printf("Trimming started. Current len of char array: %d\n", len);
  while (c != '\0') {
    if (c != ' ' && c != '\n' && c != '\t') {
      last_char_pos = i;
    }
    i++;
    c = target[i];
  }

  printf("The last char of this input is at index %d.\n", last_char_pos);
  printf("Moving the null byte and newline to reflect that.\n");

  last_char_pos++;
  target[last_char_pos] = '\n';
  last_char_pos++;
  target[last_char_pos] = '\0';
  printf("The difference in length: %d\n", len - last_char_pos);
  return last_char_pos;
}

