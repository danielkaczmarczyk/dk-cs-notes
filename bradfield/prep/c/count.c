#include <stdio.h>

int main()
{
  long nCharacters;

  nCharacters = 0;

  while (getchar() != EOF)
  {
    ++nCharacters;
  }

  printf("The file contains %ld characters.\n", nCharacters);
}
