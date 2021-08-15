#include <stdio.h>

int strl(char *string);

int main(void) {
  char *my_string = "hello world!";
  int len = strl(my_string);
  printf("len: %d\n", len);
}

int strl(char *string) {
  int count;

  for (int i = 0; *string != '\0'; string++) {
    count++;
  }

  return count;
}

