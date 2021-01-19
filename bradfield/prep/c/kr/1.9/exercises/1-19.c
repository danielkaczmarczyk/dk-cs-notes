#include <stdio.h>
#define ARRAY_SIZE 1000

/* reverse - a program that reverses a string passed into input,
 * one string at a time.
 */

int collect_line(char target[]);
void reverse(char source[], int len);

int main(void) {

  int c;
  int current_line_len = 0;
  char current_line[ARRAY_SIZE];

  while (1) {
    current_line_len = collect_line(current_line);
    printf("Reversing %s", current_line);
    printf("Length: %d\n", current_line_len);
    printf("Reversed:\n");
    reverse(current_line, current_line_len);
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

/* accepts a char array and its length as an arguments, and 
 * prints out the reverse of the char array
 */
void reverse(char source[], int len) {
  
  // iterate over source from len to zero, printing out chartacters
  for (int i = len - 2; i >= 0; i--) {
    printf("%c", source[i]);
  }
  printf("\n");
}


