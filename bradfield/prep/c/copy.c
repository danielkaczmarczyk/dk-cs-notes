#include <stdio.h>

int main()
{
  int c; // the character to be copied

  c = getchar();
  while (c != EOF)
  {
    putchar(c);
    c = getchar();
  }
}
