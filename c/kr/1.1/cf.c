#include <stdio.h>

int main(void) {

  float c, fahr;
  float start, stop, step;

  start = -20;
  stop  = 40;
  step  = 2;

  c = start;

  printf("Celcius to Fahrenheit conversion table\n");
  while (c <= stop) {
    fahr = (c * (9.0/5.0)) + 32.0;
    printf("%3.2f*C %3.2f*F\n", c, fahr);
    c += step;
  }
}

