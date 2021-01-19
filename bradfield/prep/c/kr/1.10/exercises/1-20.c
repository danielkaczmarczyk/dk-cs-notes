#include<stdio.h>
#define TAB_SIZE 2
#define ARRAY_SIZE 1000

/* detab - replaces tabs in input with an appropriate amount of spaces
 * arbitrarily set to 2.
 */

int collect_line(char target[]);
void detab(char source[], int len);
void print_spaces();

int main(void) {
  char line[ARRAY_SIZE];
  int line_length = 0;

  while (1) {
    line_length = collect_line(line);
    detab(line, line_length);
  }
}

void print_spaces() {
  for (int i = 0; i < TAB_SIZE; i++) {
    putchar(' '); 
  }
}

/*
 * detab takes a source array of characters and prints them out
 * exchanging tabs for spaces
 */
void detab(char source[], int len) {
  char c;
  for (int i = 0; i <= len; i++) {
    c = source[i];
    if (c == '\t') {
      print_spaces();
    } else {
      putchar(c);
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

