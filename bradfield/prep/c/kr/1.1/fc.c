#include <stdio.h>

/* print Fahrenheit-Celsius table
 * for fahr = 0, 20, ..., 300 */

int main(void) {
  float fahr, celsius;
  float lower, upper, step;

  lower = -100;
  upper = 300;
  step = 20;

  printf("Temperature conversion table for F to C:\n\n");
  fahr = lower;
  while (fahr <= upper) {
    celsius = 5 * (fahr - 32) / 9;
    printf(" %4.0f*F --> %5.1f*C\n", fahr, celsius);
    fahr += step;
  }
}

