#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *_strcat(char *s, char *t) {
    int len_s = strlen(s);
    int len_t = strlen(t);
    int total = len_s + len_t;
    char *result = malloc(total);
    return result;
}

int main(void) {
    char a[] = "hello";
    char b[] = "_world";
    char *c = _strcat(a, b);
    printf("c: |%s|\n", c);
}
