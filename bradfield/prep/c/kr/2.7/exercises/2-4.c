#include <stdio.h>

/* squeeze alt - deletes each char in s1 that can be found in s2 */

void squeeze(char s1[], char s2[]);

int main(void) {
  char s1[6] = "dumbo";
  char s2[5] = "body";

  squeeze(s1, s2);
  printf("%s\n", s1);
  printf("um\n");

}

void squeeze(char s1[], char s2[]) {
  int c, i, j;
  int delete;

  for (i = j = 0; s1[i] != '\0'; i++) {
    delete = 0;
    c = s1[i];
    printf("out: i:%d j:%d del:%d c:%c\n", i, j, delete, c);
    for (int m = 0; s2[m] != '\0'; m++) {
      printf("in: m:%d s2[m]:%c, c:%c\n", m, s2[m], c);
      if (c == s2[m]) {
        printf("deleting %c!\n", c);
        delete = 1;
        break;
      }
    }

    if (!delete) {
      s1[j++] = s1[i];
    }
  }
  s1[j] = '\0';
}

