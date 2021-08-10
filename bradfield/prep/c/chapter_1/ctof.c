#include <stdio.h>

/* print a c to f conversion table */

int main(void) {
  float cel_temp, fah_temp;
  int lower_boundary, upper_boundary, step;

  lower_boundary = 0;
  upper_boundary = 300;
  step = 20;

  cel_temp = lower_boundary;

  while (cel_temp <= upper_boundary) {
    fah_temp = ( cel_temp * 9 / 5 ) + 32;
    printf("C: %-6.2f F: %-6.2f\n", cel_temp, fah_temp);
    cel_temp += step;
  }

}
