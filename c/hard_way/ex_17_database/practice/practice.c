#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define VERBOSE 0

/* fn defs */

void die();

/* Globals */

int MAX_DATA = 128;
int MAX_ROWS = 5;

/* Address - related functions */

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
  int error = 0;

  struct Address *address = malloc(sizeof(struct Address));
  address->id = id;
  address->set = set;

  int name_size = strlen(name);
  int email_size = strlen(email);

  if (name_size > MAX_DATA) {
    printf("Cannot write. Name \"%s\" too long. MAX_DATA == %d, string given == %d\n", name, MAX_DATA, name_size);
    error = 1;
  }

  if (email_size > MAX_DATA) {
    printf("Cannot write. Email \"%s\" too long. MAX_DATA == %d, string given == %d\n", email, MAX_DATA, email_size);
    error = 1;
  }

  if (error) {
    die();
  }

  char *name_ptr = malloc(strlen(name));
  char *email_ptr = malloc(strlen(email));

  strcpy(name_ptr, name);
  strcpy(email_ptr, email);

  address->name = name_ptr;
  address->email = email_ptr;

  return address;
}

/* Database - related functions */

struct Database {
  int max_data;
  int max_rows;
  struct Address *rows;
};

struct Database *Database_create(const int max_data, const int max_rows) {
  struct Database *db = malloc(sizeof(struct Database));

  db->max_data = max_data;
  db->max_rows = max_rows;

  // put aside the memory for all the address pointers
  void *rows = malloc(sizeof(struct Address) * max_rows);
  db->rows = rows;

  return db;
}

void Database_info(struct Database *db) {
  printf("\nDB INSPECT\n");
  printf("max_data: %d\n", db->max_data);
  printf("max_rows: %d\n", db->max_rows);
  printf("&rows: %p\n", db->rows);
}

void Database_print_all(struct Database *db) {
  printf("\nPrinting all database entries\n");

  for (int i = 1; i <= db->max_rows; i++) {
    if (db->rows[i].set) {
      Address_print(&db->rows[i]);
    } else {
      printf("ERRR: no entry for %d\n", i);
    }
  }
}

/* UTILITY FUNCTIONS */
void die() {
  printf("ERROR. PROGRAM EXITING\n");
  exit(1);
}

int main(int argc, char *argv[]) {
  printf("---------------_DB_----------------\n");
  struct Address *address = Address_create(3, 1, "Daniel Kaczmarczyk", "daniel@dan.dk", MAX_DATA);

  struct Database *db = Database_create(MAX_DATA, MAX_ROWS);

  // TODO add row to the database. how?
  db->rows[address->id] = *address;
  Address_print(&db->rows[3]);

  // TODO print all
  Database_print_all(db);

  // TODO write the database to a file

  // TODO read the database from a file

}

