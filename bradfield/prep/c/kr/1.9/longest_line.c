#include <stdio.h>
#define MAXLINE 1000 /* maximum input line length */

int getline2(char line[], int maxline);
void copy(char to[], char from[]);

/* print the longest input line */
int main(void) {
  int len;                 // current line length
  int max;                 // max line length so far
  char line[MAXLINE];      // current input line
  char longest[MAXLINE];   // longest input line saved here

  max = 0;
  while ((len = getline2(line, MAXLINE)) > 0) {
    if (len > max) {
      max = len;
      copy(longest, line);
    } 
  }

  if (max > 0) {
    printf("%s", longest);
    return 0;
  }
  return 1;
}

int getline2(char s[], int lim) {
  int c, i;

  for (i = 0; i < lim - 1 && (c=getchar()) != EOF && c != '\n'; i++) {
    s[i] = c;
  }

  if (c == '\n') {
    s[i] = c;
    i++;
  }

  s[i] = '\0';
  return i;
}

void copy(char to[], char from[]) {
  int i;
  i = 0;
  while ((to[i] = from[i]) != '\0') {
    ++i;
  }
}

