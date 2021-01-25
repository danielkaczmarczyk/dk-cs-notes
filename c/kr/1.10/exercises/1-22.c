#include<stdio.h>
#define ARRAY_SIZE 1000
#define MAX_LINE_LEN 10

/*
 * fold
 * program that prints lines longer than MAX_LINE_LEN on multiple lines.
 */

void break_line(char source[], int source_len);
int collect_line(char target[]);
void print_invisibles(char target[]); 

int main(void) {
  char line[ARRAY_SIZE];
  int line_length = 0;

  while (1) {
    line_length = collect_line(line);
    if (line_length > MAX_LINE_LEN) {
      printf("Max line exceeded\n");
      break_line(line, line_length);
    } else {
      printf("Max line not exceeded\n");
      printf("%s", line);
    }
    print_invisibles(line);
  }
}

void break_line(char source[], int source_len) {
  int index = 0;
  int fulls = source_len / MAX_LINE_LEN;
  int remainder = source_len % MAX_LINE_LEN; 

  for (int i = 0; i < fulls; i++ ) {
    for (int j = 0; j < MAX_LINE_LEN; j++) {
      putchar(source[index]);
      index++;
    }
    printf("\n");
  }

  if (remainder > 0) {
    for (int i = 0; i < remainder; i++) {
      putchar(source[index]);
      index++;
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

/* prints invisible characters (tabs and spaces) for debugging */
void print_invisibles(char target[]) {
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
  printf("\n");
}

