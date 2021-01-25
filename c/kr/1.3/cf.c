#include <stdio.h>

int main(void) {

  float c, fahr;
  float start, stop, step;

  start = 300;
  stop  = 0;
  step  = 10;

  c = start;

  printf("Celcius to Fahrenheit conversion table\n\n");
  for (c = start; c >= stop; c -= step) {
    fahr = (c * (9.0/5.0)) + 32.0;
    printf("%6.2f*C %6.2f*F\n", c, fahr);
  }
}

