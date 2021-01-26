#include "armstrong_numbers.h"
#include <stdio.h>
#include <math.h>

bool is_armstrong_number(int candidate) {
  int temp = candidate;
  // find the length of the integer
  int len = 0;
  while (temp > 0) {
    len++;
    temp = temp / 10; 
  }

  // find the sum
  int sum = 0;
  int rem;
  temp = candidate;
  while (temp > 0) {
    rem = temp % 10;
    sum += pow(rem, len);
    temp = temp / 10;
  }

  if (sum == candidate) {
    return 1;
  } else {
    return 0;
  }
}

