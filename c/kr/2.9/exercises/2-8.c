#include <stdio.h>

int rightrot(int x, int n);
void itob(int x, int pad);

int main(void) {
  itob(106, 8);
  // result = rightrot(106, 10);
}


int rightrot(int x, int n) {
  int lsb;

  printf("x: %d\n", x);
  while (n-- > 0) {
    lsb = x & 1;
    x = (x >> 1);
    if (lsb) {
      x = x | ~(~0 >> 1);
    }
  }
  return x;
}

void itob(int x, int pad) {
  int n;
  int i = 0;
  char string[50];

  while (x > 0) {
    n = x % 2;
    string[i] = n;
    x /= 2;
    i++;
  }
  string[i] = '\0';
  i -= 1;
  for (int j = i; j >= 0; j--) {
    printf("%d", string[j]);
  }
  printf("\n");
}
