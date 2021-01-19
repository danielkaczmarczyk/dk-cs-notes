#include <stdio.h>

/* a program that counts occurences of every
 * character in input, and prints a histogram
 * limited to a-z alphabet for clarity
 */

int main(void) {

  #define CHARS 26 // n chars in the set

  int c;
  int counts[CHARS];

  for (int i = 0; i <= CHARS; i++) {
    counts[i] = 0;
  }

  while ((c = getchar()) != EOF) {
    counts[c - 97]++;
  }

  for (int i = 0; i < CHARS; i++) {
    putchar(i + 97);
    printf("%2d: ", counts[i]);
    for (int j = 0; j < counts[i]; j++) {
      printf("#");
    }
    printf("\n");
  }  
}
