#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define VERBOSE 0
#define MAX_DATA 512

struct Address {
  int id;
  int set;
  char *name;
  char *email;
};

void Address_print(struct Address *add) {
  printf("id: %d\n", add->id);
  printf("set: %d\n", add->set);
  printf("name: %s\n", add->name);
  printf("email: %s\n", add->email);
}

/* 
 * Creates a struct in the memory, and returns the pointer to it
 *
 * in arguments, char *name, and char *email are equivalent to char name[] and char email[] - both are just pointers
 */
struct Address *Address_create(const int id, const int set, const char *name, const char *email) {
  struct Address *address = malloc(sizeof(struct Address));
  address->id = id;
  address->set = set;

  printf("In Address_create, name: %s email: %s\n", name, email);

  // allocate some memory to store email and name
  char *name_ptr = malloc(MAX_DATA);
  strcpy(name_ptr, name);

  address->name = name_ptr;

  return address;
}

int main(int argc, char *argv[]) {
  printf("---------------_DB_----------------\n");
  //printf("sizeof: %lu\n", sizeof(char));
  struct Address *address = Address_create(3, 1, "Daniel Kaczmarczyk", "daniel@dan.dk");
  Address_print(address);
}
