#include <stdio.h>

int main(int argc, char *argv[])
{
  int areas[] = { 10, 12, 13, 14, 20 };
  char name[] = "Zed";
  char full_name[] = {
    'Z', 'e', 'd',
    ' ', 'A', '.', ' ',
    'S', 'h', 'a', 'w',
    '\0'
  };

  printf("The size of an int: %ld\n", sizeof(int));
  printf("The size of areas[] (int[]): %ld\n", sizeof(areas));
  printf("The number of ints in areas[]: %ld\n",
      sizeof(areas) / sizeof(int)); // 20 bytes, 4 per int

  printf("The size of char is: %ld\n", sizeof(char));
  printf("The size of char name[]: %ld\n", sizeof(name));
  printf("The number of chars: %ld\n",
      sizeof(name) / sizeof(char));

  printf("The size of full_name (char[]) is: %ld\n", sizeof(full_name));
  printf("The number of chars: %ld\n",
      sizeof(full_name) / sizeof(char));

  printf("name=\"%s\" and full_name=\"%s\"\n", name, full_name);
}
