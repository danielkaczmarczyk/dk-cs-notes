#include <stdio.h>

int main()
{
  int character, nLines;

  nLines = 0;

  while ((character = getchar()) != EOF)
  {
    if (character == '\n')
    {
      ++nLines;
    }
  }

  printf("There are %d lines in this file.\n", nLines);
}
