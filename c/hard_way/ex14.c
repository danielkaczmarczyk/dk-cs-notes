#include <stdio.h>
#include <ctype.h>

// forward declarations
int can_print_it(char ch);        /* takes a character as an argument */
void print_letters(char arg[]);   /* takes an array of characters */

void print_arguments(int argc, char *argv[]) {
  int i = 0;

  for (i = 0; i < argc; i++) {
    print_letters(argv[i]);
  }
}

void print_letters(char arg[]) {
  int i = 0;

  for (i = 0; arg[i] != '\0'; i++) {
    char ch = arg[i];

    if (can_print_it(ch)) {
      printf("'%c' == %d ", ch, ch);  /* conversion of a char into int */
    }
  }
  printf("\n");
}

int can_print_it(char ch) {
  return isalpha((int)ch) || isblank((int)ch);
}

int main(int argc, char *argv[]) {
  print_arguments(argc, argv);
  return 0;
}

