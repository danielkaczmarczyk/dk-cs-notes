#include <stdio.h>

/* a program that counts lengths of words in its input
 * warning: doesn't format correctly with more than 9
 * occurencies per word.
 */

int main(void) {

  #define IN 1
  #define OUT 0

  int lens[10];

  for (int i = 0; i < 10; i++) {
    lens[i] = 0;
  }


  int c, cur_w_len, state;

  cur_w_len = 0;

  state = OUT;
  while ((c = getchar()) != EOF) {
    // whitespace 
    if (c == ' ' || c == '\n' || c == '\t') {
      if (state == IN) {
        state = OUT;
        lens[cur_w_len]++;
        cur_w_len = 0;
      }
    // not whitespace
    } else {
      cur_w_len++;
      state = IN;
    }
  }


  // calculate max height needed for printing
  int max = 0;
  for (int i = 0; i < 10; i++) {
    if (lens[i] >= max) {
      max = lens[i];
    }
  }


  printf("\n");
  for (int i = max; i > 0; i--) {
    for (int j = 1; j < 10; j++) {
      if (lens[j] >= i) {
        printf("#"); 
      } else {
        printf(" ");
      }
      printf(" ");
    }
    printf("\n");
  }

  // print bottom
  for (int i = 1; i < 10; i++) {
    printf("%d ", lens[i]);
  } 
  printf("\n");

  for (int i = 1; i < 10; i++) {
    printf("%d ", i);
  } 
  printf("\n");
}

