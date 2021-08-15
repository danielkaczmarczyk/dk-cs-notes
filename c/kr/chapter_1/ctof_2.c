#include <stdio.h>

#define LOWER_BOUNDARY 0
#define UPPER_BOUNDARY 300
#define STEP 20

/* print a c to f conversion table */

int c_to_f(float cel_temp);
void print_temp(float cel_temp, float fah_temp);

int main(void) {
  float cel_temp, fah_temp;

  for (cel_temp = UPPER_BOUNDARY; cel_temp >= LOWER_BOUNDARY; cel_temp -= STEP) {
    fah_temp = c_to_f(cel_temp);
    print_temp(cel_temp, fah_temp);
  }
}

int c_to_f(float cel_temp) {
  return (cel_temp * 9 / 5) + 32;
}

void print_temp(float cel_temp, float fah_temp) {
  printf("C: %-6.2f F: %-6.2f\n", cel_temp, fah_temp);
}
