#include <stdio.h>

float c_to_f(float c);

int main(void) {

  float c, fahr;
  float start, stop, step;

  start = 0;
  stop  = 40;
  step  = 2;

  c = start;

  printf("Celcius to Fahrenheit conversion table\n");
  while (c <= stop) {
    fahr = c_to_f(c);
    printf("%5.2f*C %3.2f*F\n", c, fahr);
    c += step;
  }
}

float c_to_f(float c) {
  float fahr = (c * (9.0/5.0)) + 32.0;
  return fahr;
}

