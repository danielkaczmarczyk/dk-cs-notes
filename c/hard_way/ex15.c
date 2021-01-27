#include <stdio.h>

void print_1(int *ages, char *names[], int count) {
  for (int i = 0; i < count; i++) {
    printf("%s has %d years alive\n", *(names + i), *(ages + i));
  }
  printf("--->\n");
}


void print_2(int ages[], char *names[], int count) {
  int *cur_age = ages;
  char **cur_name = names;

  // printing second way using pointers
  for (int i = 0; i < count; i++) {
    // printf("cur_name pointer address: %p\n", (&cur_name + i));
    // printf("cur_age  pointer address: %p\n", (&cur_age + i));
    printf("%s is %d years old\n", *(cur_name + i), *(cur_age + i));
  }

  printf("--->\n");
}


void print_3(int ages[], char *names[], int count) {
  int *cur_age = ages;
  char **cur_name = names;
  for (int i = 0; i < count; i++ ) {
    printf("%s is %d years old\n", cur_name[i], cur_age[i]);
  }

  printf("--->\n");
}

void print_4(int ages[], char *names[], int count) {
  int *cur_age = ages;
  char **cur_name = names;
  // fourth way with pointers in a stupid complex way
  for (
      // make cur_name point at the beginning of names
      // make cur_age point at the beginning of ages
      cur_name = names, cur_age = ages;
      // what the fuck is (cur_age - ages)
      // alright, it's pointer artihmetic expression checking how far
      // are we into the array
      (cur_age - ages) < count;
      // increment the pointers to move to the next block of memory
      cur_name += 1, cur_age++
  ) {
    //printf("cur_age - ages: %ld\n", cur_age - ages);
    printf("%s is %d years old\n", *cur_name, *cur_age);
  }
}

int main(int argc, char *argv[]) {
  // char *argv[] is an array of pointers to chars (strings)

  int ages[] = { 23, 43, 12, 89, 2 };
  char *names[] = {
    "Alan", "Frank", "Mary", "John", "Lisa" 
  };

  // safely get the size of ages
  int count = sizeof(ages) / sizeof(int);

  char **pointer_to_names = names;

  print_1(&ages[0], pointer_to_names, count);
  // print_2(ages, names, count);
  // print_3(ages, names, count);
  // print_4(ages, names, count);

  return 0;
}

