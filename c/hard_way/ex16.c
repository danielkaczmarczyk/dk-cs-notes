#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

struct Person {
  char *name;
  int age;
  int height;
  int weight;
};

struct Person *Person_create(char *name, int age, int height, int weight) {
  struct Person *who = malloc(sizeof(struct Person));
  assert(who != NULL);

  who->name = strdup(name);
  who->age = age;
  who->height = height;
  who->weight = weight;

  return who;
}

void Person_destroy(struct Person *who) {
  assert(who != NULL);

  free(who->name);
  free(who);
}

void Person_print(struct Person *who) {
  printf("--- %s ---\n", who->name);
  printf("Age:    %d\n", who->age);
  printf("Height: %d\n", who->height);
  printf("Weight: %d\n", who->weight);
}

int main(int argc, char *argv[]) {
  // make two people structures
  struct Person *joe = Person_create("Joe Alex", 32, 64, 140);
  struct Person *frank = Person_create("Frank Blank", 20, 72, 180);

  printf("Joe is at a memory location %p\n", joe);
  Person_print(joe);
  printf("Frank is at a memory location %p\n", frank);
  Person_print(frank);
  return 0;  
}

