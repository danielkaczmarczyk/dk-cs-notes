#include <stdio.h>

int main(int argc, char *argv[]) {
  while (argc-- > 0) {
    printf("%s%s", *++argv, (argc > 0) ? " " : "");
  } 
  printf("\n");
  return 0;
}
