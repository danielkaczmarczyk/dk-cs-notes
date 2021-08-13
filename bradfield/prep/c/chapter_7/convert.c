#include <stdio.h>
#include <string.h>
#include <ctype.h>

// function that accepts pointer to a function
// as an argument
void print( int (*f)(int) ) {
  int c;
  while ((c = getchar()) != EOF) {
    putchar((*f)(c));
  }
}

int main(int argc, char *argv[]) {
  if (strcmp(argv[1], "upper") == 0) {
    print(toupper);
  } else if (strcmp(argv[1], "lower") == 0) {
    print(tolower);
  }
}

