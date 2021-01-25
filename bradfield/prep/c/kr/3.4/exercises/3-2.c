#include <stdio.h>
#define ARRAY_SIZE 1000

void escape(char source[], char target[]);
void unescape(char source[], char target[]);

int main(void) {
  char source[] = "Source\nString\ttest\n";
  char target[ARRAY_SIZE];
  char target_2[ARRAY_SIZE];

  printf("\nPre:\n%s", source);
  escape(source, target);
  printf("\nPost:\n%s\n\n", target);
  unescape(target, target_2);
  printf("\nReverted:\n%s\n", target_2);
 
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

void unescape(char source[], char target[]) {
  int i = 0;
  int j = 0;
  char c, c2;
  
  while ((c = source[i]) != '\0') {
    printf("encountered %c: %x. ", c, c);
    printf("i: %d ", i);
    switch (c) {
      case '\\' :
        c2 = source[i + 1];
        switch (c2) {
          case 't':
            printf("inputting a tab at position %d\n", j);
            target[j] = '\t';
            j++;
            break;
          case 'n':
            printf("inputting a newline at position %d\n", j);
            target[j] = '\n';
            j++;
            break;
        }
        i += 2;
        break;
      default:
        printf("inputting a char at position %d\n", j);
        target[j] = source[i];
        j++;
        i++;
    }
  }
  printf("adding null byte at position %d \n", i);
  printf("i: %d\n", i);
  target[i] = '\0';
}
