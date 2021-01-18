#include <stdio.h>

char getch(void) {
  char ch;
  ch = getchar();
  while (getchar() != '\n');
  return ch;
}

int main(void) {
  char first, second;
  printf("Type your first initial: ");
  first = getch();
  printf("Type your second initial: ");
  second = getch();
  printf("Your initials are: '%c', and '%c'.\n", first, second);
  return 0;
}
