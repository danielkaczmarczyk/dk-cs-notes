#include <stdio.h>

int main(void) {

  #define START 300
  #define STOP 0
  #define STEP 10

  float c, fahr;

  printf("Celcius to Fahrenheit conversion table\n\n");
  for (c = START; c >= STOP; c -= STEP) {
    fahr = (c * (9.0/5.0)) + 32.0;
    printf("%6.2f*C %6.2f*F\n", c, fahr);
  }
}

