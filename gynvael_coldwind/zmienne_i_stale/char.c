#include <stdio.h>

int main() {
  signed int num = 0xFFFFFFFF;
  printf("%d\n", num);

  for (int i = 0; i < 10; i++) {
    num--;
    printf("%d\n", num);
  }
}
