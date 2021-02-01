#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define VERBOSE 0

/* fn defs */

void die(char *message);
struct Database *Database_create(int max_data, int max_rows);

/* Globals */

int MAX_DATA = 128;
int MAX_ROWS = 5;
struct Connection *CONNECTION;

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

  struct Address *address = malloc(sizeof(struct Address));
  address->id = id;
  address->set = set;

  int name_size = strlen(name);
  int email_size = strlen(email);

  if (name_size > MAX_DATA) {
    printf("Cannot write. Name \"%s\" too long. MAX_DATA == %d, string given == %d\n", name, MAX_DATA, name_size);
    die("OVERSIZE");
  }

  if (email_size > MAX_DATA) {
    printf("Cannot write. Email \"%s\" too long. MAX_DATA == %d, string given == %d\n", email, MAX_DATA, email_size);
    die("OVERSIZE");
  }

  char *name_ptr = malloc(strlen(name));
  char *email_ptr = malloc(strlen(email));

  strcpy(name_ptr, name);
  strcpy(email_ptr, email);

  address->name = name_ptr;
  address->email = email_ptr;

  return address;
}

/* Connection - related functions */

struct Connection {
  FILE *file;
  struct Database *db;
};

/* 
 * Creates a connection to the database, stores it in a global var
 */
void Connection_open(const char *filename, char mode) {
  // allocate memory for one Connection
  struct Connection *conn = malloc(sizeof(struct Connection));
  if (!conn) die("Memory error");
  conn->db = Database_create(MAX_DATA, MAX_ROWS);
  if (!conn->db) die("Memory error");

  if (mode == 'c') {
    conn->file = fopen("data.db", "w");
  }

  if (!conn->file) {
    die("Failed to open the database file");
  }

  CONNECTION = conn;
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

void Database_write(struct Connection *conn) {
  // set the file position indicater for the stream to the beginning of the file.
  rewind(conn->file);

  int rc = fwrite(conn->db, sizeof(struct Database), 1, conn->file);
  if (rc != 1) die("Failed to write db to file");

  rc = fflush(conn->file);
  if (rc == -1) die("Cannot flush database");
}

/* UTILITY FUNCTIONS */
void die(char *message) {
  printf("ERROR. PROGRAM EXITING. ERROR:%s\n", message);
  exit(1);
}

int main(int argc, char *argv[]) {
  // printf("---------------_DB_----------------\n");
  // struct Address *address = Address_create(3, 1, "Daniel Kaczmarczyk", "daniel@dan.dk", MAX_DATA);
  // manually set mode
  // char mode = 'c';

  // Connection_open("data.dat", mode);

  // CONNECTION->db->rows[address->id] = *address;
  // Address_print(&CONNECTION->db->rows[3]);
  // Database_print_all(CONNECTION->db);
  // Database_write(CONNECTION);

  // FILE *fp; // declare an empty pointer to some arbitrary file
  // char *str = "Daniel's file content!";
  // fp = fopen("file.txt", "w");
  // printf("sizeof(str): %lu\n", sizeof(str));
  // fwrite(str, 1, strlen(str), fp);
  // fclose(fp);

  struct Person {
    int age;         // 4
    int height;      // 4
    char initial;    // 1
    char name[10];   
    char email[10];
  };
  // total 29
  // it got padded to 32B (3 additional bytes) 
  // due to the initial being smaller than a size of a word (sizeof(int))

  struct Person Person_daniel = {
    .age = 20,
    .name = "Daniel",
    .email = "dan@dan.dk",
    .height = 30,
    .initial = 'D'
   };
  struct Person *daniel = &Person_daniel;

  struct Person Person_natasha = {
    .age = 30,
    .name = "Natasha",
    .email = "nat@nat.nk",
    .height = 40,
    .initial = 'N'
   };
  struct Person *natasha = &Person_natasha;
  // printf("%s, age: %d, email:%s \n", daniel->name, daniel->age, daniel->email);

  FILE *fp;
  fp = fopen("persons.txt", "w");
  fwrite(daniel, sizeof(struct Person), 1, fp);
  fwrite(natasha, sizeof(struct Person), 1, fp);
  fclose(fp);

}

