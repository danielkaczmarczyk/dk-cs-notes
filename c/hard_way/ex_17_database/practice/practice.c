#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define VERBOSE 0

struct Address {
  int id;
  int set;
};

int main(int argc; char *argv[]) {
  struct Address my_address;
  my_address.id = 3;
  my_address.set = 1;
}
