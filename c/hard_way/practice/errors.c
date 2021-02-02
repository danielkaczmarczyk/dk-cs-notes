#include <stdio.h>
#include <errno.h>
#include <string.h>

int main(int argc, char **argv) {
  FILE *pf;
  int errnum;
  pf = fopen("non-existing-file.txt", "r");

  if (pf == NULL) {
    printf("Value of errno: %d\n", errno);
    perror("yikez");
    printf("Error opening file: %s\n", strerror(errno));
  } else {
    fclose(pf);
  }

  return 0;
}
