#include <stdio.h>
#include <math.h>
#define ARRAY_SIZE 1000

/* htoi - converts a hexadecimal string into its integer value */

int collect_line(char target[]);
void htoi(char string[]);

int main(void) {

  int c;
  int current_line_len = 0;
  char current_line[ARRAY_SIZE];

  while (1) {
    current_line_len = collect_line(current_line);
    printf("");
    htoi(current_line);
  }
}

void htoi(char string[]) {
  char hex_string[32];

  // load the string into the hex string char array
  int c, i, n, power;

  n = 0;
  power = 0;

  while((c = string[i]) != '\0') {
    hex_string[i] = c;
    i++;
  }
  hex_string[i] = '\0';
  printf("The string got loaded. here goes: %s", hex_string);
  // knowing the length, iterate from the end until the 'x' or 'X' char
  int len = i - 2; // i-2 due to the \n and \0 bytes included in the string.
  printf("Its length is: %d\n", len);
  // perform conversion
  for (int i = len; i >= 0; i--) {
    c = hex_string[i];
    if (c == 'x') {
      break;
    }
    c = c - '0';
    int term = c * pow(16, power);
    printf("c: %d, power: %d, n: %d, term: %d\n", c, power, n, term);
    n += term;
    power++;
  }
  printf("the value of n is: %d\n", n);
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

