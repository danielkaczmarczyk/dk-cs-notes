#include <stdio.h>

int main(int argc, char *argv[]) {
  int ages[] = { 20, 30, 40 };

  int *cur_age = ages;

  printf("The value that cur_age is pointing at is : %d\n", *cur_age);
  printf("The value of *cur_age as a pointer is    : %p\n", cur_age);
  printf("The address of cur_age is                : %p\n", &cur_age);
  printf("The address of ages is                   : %p\n", &ages);
  printf("The address of ages[0] is                : %p\n", &ages[0]);
  // can I take a pointer and access it using array syntax?
  printf("The value of ages[0] is                  : %d\n", cur_age[0]);
  // effectively, pointers behave like arrays and vice versa
  // when dealing with pointers to arrays
  printf("The value of ages[1] is                  : %d\n", cur_age[1]);
}
