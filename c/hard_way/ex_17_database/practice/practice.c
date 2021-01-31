#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define VERBOSE 0

int MAX_DATA = 512;

struct Address {
  int id;
  int set;
  char *name;
  char *email;
};

void Address_print(struct Address *add) {
  printf(">>> Address record #%d: \n", add->id);
  printf("set: %d\n", add->set);
  printf("name: %s\n", add->name);
  printf("email: %s\n", add->email);
}

/* 
 * Creates a struct in the memory, and returns the pointer to it
 *
 * in arguments, char *name, and char *email are equivalent to char name[] and char email[] - both are just pointers
 */
struct Address *Address_create(const int id, const int set, const char *name, const char *email, const int MAX_DATA) {
  struct Address *address = malloc(sizeof(struct Address));
  address->id = id;
  address->set = set;

  int name_size = strlen(name);
  int email_size = strlen(email);

  if (name_size > MAX_DATA) {
    printf("Cannot write. Name too long. MAX_DATA == %d, string given == %d\n", MAX_DATA, name_size);
  }

  if (email_size > MAX_DATA) {
    printf("Cannot write. Email too long. MAX_DATA == %d, string given == %d\n", MAX_DATA, name_size);
  }

  char *name_ptr = malloc(strlen(name));
  char *email_ptr = malloc(strlen(email));

  strcpy(name_ptr, name);
  strcpy(email_ptr, email);

  address->name = name_ptr;
  address->email = email_ptr;

  return address;
}

int main(int argc, char *argv[]) {
  printf("---------------_DB_----------------\n");
  //printf("sizeof: %lu\n", sizeof(char));
  struct Address *address = Address_create(3, 1, "Daniel Kaczmarczyk", "daniel@dan.dk", MAX_DATA);
  Address_print(address);
}
