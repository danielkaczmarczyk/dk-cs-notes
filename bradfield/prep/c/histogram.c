#include <stdio.h>

#define IN  1
#define OUT  0
#define MAX_ARR 50

int main(void) {
  int c;
  int len = 0;
  int state;
  int lengths[MAX_ARR];
  int i = 0;

  state = OUT;

  while((c = getchar()) != EOF) {
    if (c == ' ' || c == '\n' || c == '\t') {
      state = OUT;
      if (len != 0) {
        lengths[i] = len;
        i++;
      }
      len = 0;
    } else {
      state = IN;
      len++;
    }
  }

  for (int j = 0; j < i; j++) {
    len = lengths[j]; 
    for (int x = len; x > 0; x--) {
      printf("X");
    }
    printf("\n");
  }
}
