#include <stdio.h>
#include <limits.h>
#include <float.h>

/*
 * this program determines ranges of:
 * - [ ] char
 * - [ ] short
 * - [ ] int
 * - [ ] long
 * - [ ] signed
 * - [ ] unsigned
 */

int main(void) {
  printf("CHAR_BIT: %d\n", CHAR_BIT);
  printf("CHAR_MAX: %d\n", CHAR_MAX);
  printf("UCHAR_MAX: %d\n", UCHAR_MAX);
  printf("INT_MAX: %d\n", INT_MAX);
  printf("ULONG_MAX: %lu\n", ULONG_MAX);
}

