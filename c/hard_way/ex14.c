#include <stdio.h>
#include <string.h>
#include <ctype.h>

void print_letters(char arg[], int len);   /* takes an array of characters */

void print_arguments(int argc, char *argv[]) {
  int i = 0;
  for (i = 0; i < argc; i++) {
    int length = strlen(argv[i]);
    printf("str len: %d\n", length);
    print_letters(argv[i], length);
  }
}

void print_letters(char arg[], int len) {
  int i = 0;

  for (i = 0; i < len; i++) {
    char ch = arg[i];

    if (isalpha((int)ch) || isblank((int)ch)) {
      printf("'%c' == %d ", ch, ch);  /* conversion of a char into int */
    }
  }
  printf("\n");
}

int main(int argc, char *argv[]) {
  print_arguments(argc, argv);
  return 0;
}

