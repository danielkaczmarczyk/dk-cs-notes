#include <stdio.h>

void escape(char source[], char target[]);

int main(void) {
  char source[] = "Source\nString\tO.o\n";
  escape(source, source);
}

void escape(char source[], char target[]) {
  int i, c;
  for (i = 0; (c = source[i]) != '\0'; i++) {
    switch (c) {
      case '\n':
        printf("\\n");
        break;
      case '\t':
        printf("\\t");
        break;
      default:
        printf("%c", c);
    }
  }
  printf("\n");
}
