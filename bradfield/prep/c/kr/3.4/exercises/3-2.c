#include <stdio.h>
#define ARRAY_SIZE 1000

void escape(char source[], char target[]);

int main(void) {
  char source[] = "Source\nString\ttest\n";
  char target[ARRAY_SIZE];
  escape(source, target);
  printf("%s\n", target);
}

void escape(char source[], char target[]) {
  int i, j, c;
  i = 0;
  j = 0;
  while ((c = source[i]) != '\0') {
    switch (c) {
      case '\n':
        target[j] = '\\';
        target[j + 1] = 'n';
        j += 2;
        break;
      case '\t':
        target[j] = '\\';
        target[j + 1] = 't';
        j += 2;
        break;
      default:
        target[j] = c;
        j++;
    }
    i++;
  }
  target[j] = '\0';
}
