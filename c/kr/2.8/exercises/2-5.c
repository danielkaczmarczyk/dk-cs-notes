#include <stdio.h>
#define MAX_LINE_SIZE 100

/* any - a program that returns the first location in a string s1
 * where a character from s2 occurs, or -1 if s1 contains no characters
 * from s2.
 */

int any(char string_1[], char string_2[]);
int my_getline(char s[], int lim);

int main(void) {
  int result;
  char string_1[MAX_LINE_SIZE];
  char string_2[MAX_LINE_SIZE];

  printf(">>>string_1: ");
  my_getline(string_1, MAX_LINE_SIZE);
  printf(">>>string_2: ");
  my_getline(string_2, MAX_LINE_SIZE);
  result = any(string_1, string_2); 
  printf("result: %d\n", result);
}

int any(char string_1[], char string_2[]) {
  char c_1, c_2;
  for (int i = 0; (c_1 = string_1[i]) != '\0'; i++) {
    for (int j = 0; (c_2 = string_2[j]) != '\0'; j++) {
      if (c_1 == c_2) {
        return i;
      }
    }
  }
  return -1;
}

int my_getline(char s[], int lim) {
  int c, i, len;
  len = 0;
  for (i = 0; i < lim && (c = getchar()) != '\n' && c != EOF; i++) {
    s[i] = c;
    len++;
  }
  s[i] = '\0';
  len++;
  return len;
}

