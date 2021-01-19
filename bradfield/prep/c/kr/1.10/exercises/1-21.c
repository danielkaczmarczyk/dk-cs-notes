#include<stdio.h>
#define TAB_SIZE 2
#define ARRAY_SIZE 1000
#define IN_SPACES 1
#define OUT_SPACES 0

/* entab - replaces strings of blanks with the minimum amount of tabs and
 * blanks to achieve the same spacing.
 */

int collect_line(char target[]);
void entab(char source[], int len, char target[]);
void print_whitespace(int gap_size);
void print_invisibles(char target[]);

int main(void) {
  char line[ARRAY_SIZE];
  char post_entab_line[ARRAY_SIZE];
  int line_length = 0;

  while (1) {
    line_length = collect_line(line);
    entab(line, line_length, post_entab_line);
    print_invisibles(line);
    print_invisibles(post_entab_line);
  }
}

/*
 * given gap_size, prints appropriate amount of tabs and spaces
 */
void print_whitespace(int gap_size) {
  // is it a clean amount of tabs or not?
  // if yes, just print tabs
  // if need be, fill in with spaces
}

/*
 * entab iterates over the string and replaces the spaces with appropriate
 * amount of tabs and spaces
 */
void entab(char source[], int len, char target[]) {
  int state = OUT_SPACES;
  int space_count = 0;
  char c;
  int target_index = 0;

  for (int i = 0; i <= len; i++) {
    c = source[i];
    if (c == ' ') { // the character is a space
      space_count++;
      if (state == OUT_SPACES) {
        state = IN_SPACES;
      }
    } else { // the character is a word char
      if (state == IN_SPACES) {
        int remainder = space_count % TAB_SIZE;

        int tabs_to_print = space_count / TAB_SIZE;
        for (int i = 0; i <= tabs_to_print; i++) {
          target[target_index] = '\t';
          target_index++;
        }

        if (remainder > 0) {
          for (int i = 0; i < remainder; i++) {
            target[target_index] = ' ';
            target_index++;
          }
        }

        state = OUT_SPACES;
        space_count = 0;
        target[target_index] = c;
        target_index++;
      } else {
        target[target_index] = c;
        target_index++;
      }
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

