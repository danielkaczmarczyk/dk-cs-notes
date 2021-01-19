#include<stdio.h>
#define ARRAY_SIZE 1000
#define MAX_LINE_LEN 10
#define DEBUG 0
#define FALSE 0
#define TRUE  1

/*
 * program that removes comments from a C program source
 *
 * TODO
 * [ ] handle // comments
 * [ ] handle multiline comments
 */

int collect_line(char target[]);
void scrape_comments(char source[], int len);
void print_invisibles(char target[]); 

int main(void) {
  char line[ARRAY_SIZE];
  int line_length = 0;

  while (1) {
    line_length = collect_line(line);
    scrape_comments(line, line_length);
    print_invisibles(line);
  }
}

void scrape_comments(char source[], int len) {
  int in_comment = FALSE;
  char current, previous;
  int c;
  int i = 1;        /* leave 1 index for being able to read two chars */
  
  while (i < len) {
    current = source[i];
    previous = source[i - 1];
    if (DEBUG) printf("Current: %c, previous: %c\n", current, previous);

    if (current == '/' && previous == '/') {
      printf("\n");
      return;
    } else if (current == '*' && previous == '/') {
      in_comment = TRUE;  
    } else if (current == '/' && previous == '*') {
      in_comment = FALSE;  
    } else {
      if (!in_comment) {
        putchar(previous);
      }
    }
    i++;
  }
  printf("\n");
}

/* 
 * A function that collects a line of input from the stdin, copies it to
 * target char array, and returns the line length.
 */
int collect_line(char target[]) {
  int c;
  int i = 0;
  printf(">>> ");
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

/* prints invisible characters (tabs and spaces) for debugging */
void print_invisibles(char target[]) {
  if (DEBUG) {
    int i = 0;
    char c;
    printf("DEBUG: ");
    while((c = target[i]) != '\0') {
      if (c == ' ') {
        printf("\\s");
      } else if (c == '\t') {
        printf("\\t");
      } else {
        putchar(c);
      }
      i++;
    }
  }
}

