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

  int *cur_age = (int *) names;
  char **cur_name = names;

  // printing second way using pointers
  for (i = 0; i < count; i++) {
    printf("%s is %d years old\n", *(cur_name + i), *(cur_age + i));
  }

  printf("--->\n");

  // third way, pointers are 'just arrays'
  for (i = 0; i < count; i++ ) {
    printf("%s is %d years old\n", cur_name[i], cur_age[i]);
  }

  printf("--->\n");

  // fourth way with pointers in a stupid complex way
  for (cur_name = names, cur_age = ages; (cur_age - ages) < count; cur_name++, cur_age++) {
    printf("%s is %d years old\n", *cur_name, *cur_age);
  }
}
