#include <stdio.h>
#define MAX_LINE_SIZE 100

/* template file with getline to read keybaord input
 * one line at a time
 */

int my_getline(char s[], int lim);

int main(void) {
  char line[MAX_LINE_SIZE];
  int size;

  printf(">>> ");
  size = my_getline(line, MAX_LINE_SIZE);
  printf("%s\n", line);
  printf("%d\n", size);
}

int my_getline(char s[], int lim) {
  int c, i, len;
  len = 0;
  for (i = 0; i <lim && (c = getchar()) != '\n' && c != EOF; i++) {
    s[i] = c;
    len++;
  }
  s[i] = '\0';
  len++;
  return len;
}

