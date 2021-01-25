#include <stdio.h>

int strleng(char *string);

int main(void) {
  char *string = "Hello, World";
  printf("len: %d\n", strleng(string));
}

/* checks the length of a string, returns its value as int */
int strleng(char *string) {
 char *end = string;

 while (*end != '\0') {
   end++;
 }
 return end - string;
}

