#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

void die(const char *message) {
  if (errno) {
    perror(message);
  } else {
    printf("Error: %s\n", message);
  }

  exit(1);
}

// a typedef creates a fake type,
// in this case for a function pointer
typedef int (*compare_cb) (int a, int b);

int main(int argc, char *argv[]) {
}

