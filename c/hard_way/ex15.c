#include <stdio.h>

int main(int argc, char *argv[]) {
  // char *argv[] is an array of pointers to chars (strings)

  int ages[] = { 23, 43, 12, 89, 2 };
  char *names[] = {
    "Alan", "Frank", "Mary", "John", "Lisa" 
  };

  // safely get the size of ages
  int count = sizeof(ages) / sizeof(int);
  int i = 0;

  // printing
  // first way using indexing
  for (i = 0; i < count; i++) {
    printf("%s has %d years alive\n", names[i], ages[i]);
  }

  printf("--->\n");

  // setup the pointers to the start of arrays;
  int *cur_age = ages;      // pointer to the start of array ages.
  char **cur_name = names;  // pointer to pointers to strings (**)

  // printing second way using pointers
  for (i = 0; i < count; i++) {
    printf("%s is %d years old\n", *cur_name, *cur_age);
    cur_name += i;
    cur_age += i;
  }


}
