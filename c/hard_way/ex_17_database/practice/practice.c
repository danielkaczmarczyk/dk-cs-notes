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
  char name[MAX_DATA];
  char email[MAX_DATA];
};

void Address_print(struct Address *add) {
  printf("id: %d\n", add->id);
  printf("set: %d\n", add->set);
  printf("name: %s\n", add->name);
  printf("email: %s\n", add->email);

}

int main(int argc, char *argv[]) {
  struct Address my_address;
  my_address.id = 3;
  my_address.set = 1;
  strcpy( my_address.name, "Daniel Kaczmarczyk");
  strcpy( my_address.email, "daniel@dan.dk");
  Address_print(&my_address);
}
