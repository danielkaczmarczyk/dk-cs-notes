#include <stdio.h>

int main(void) {
  int somenumbers[5];
  int *ptr = somenumbers; /* in c, an array name is a pointer to itself */
  int v = 2;

  for (; ptr < &somenumbers[5]; ptr++) {
    *ptr = v;
    v = v * 2;
  }
  
  printf("%d\n", '\0');
}

