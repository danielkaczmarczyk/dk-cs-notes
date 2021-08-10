#include <stdio.h>

int main(int argc, char *argv[])
{
  int i;
  int count = 0;

  for (i = 1; i < argc; i++) {
    printf("%s%s", argv[i], (i < argc-1) ? " " : "");
    count++;
  }
  printf("\n");
  printf("total count of cli args: %d", count);
  printf("\n");
  return 0;
}
