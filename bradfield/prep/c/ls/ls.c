#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdarg.h>
#include <dirent.h>

#define DIR_N 0
#define DIR_R 1

#define true 1
#define false 0
#define bool int

#define DEBUG_ON 1

#define _for(x) for (int i = 0; i < x ; i++) {
#define __for(x) for (int i = x; i > 0; i--) {

bool starts_with(const char *string, const char c) {
  return string[0] == c;
}

void print_entries(int direction, int file_count, struct dirent **directory_entries) {
  if (direction == DIR_N) {
    int i = 0;
    while (i < file_count) {
      char *entry = directory_entries[i]->d_name;
        if (!starts_with(entry, '.')) {
          printf("%s ", entry); 
        }
      //printf("%hhu\n", directory_entries[file_count]->d_type);
      i++;
    }
    printf("\n");
  } else if (direction == DIR_R) {
      while(file_count--) {
        printf("%s ", directory_entries[file_count]->d_name);
      }
      printf("\n");
  }
}

/*
 * file OR directory - same thing
 */
void get_file_stats(char *filename, struct stat *stbuf) {
  // man 2 stat to look up details
  stat(filename, stbuf);

  printf("no argument specified. acting on cwd.\n");
  printf("%llu\n", stbuf->st_ino);
  printf("%u\n", stbuf->st_uid);
  printf("%u\n", stbuf->st_gid);
  printf("%u\n", stbuf->st_rdev);
}

// make it accept a pointer to array to the config
void parse_flags(int argc, char **argv, int *direction) {
  int flag;
  printf("parsing flags...\n");
  while ((flag = getopt(argc, argv, "r")) != -1) {
    printf("flag: %d\n", flag);
    switch(flag) {
      case 'r':
        if (DEBUG_ON) printf("setting direction: reverse\n");
        *direction = 1;
        break;
      default:
        printf("usage: -[r]\n");
    }
  }
  printf("parsing flags complete...\n");
}

int main(int argc, char **argv) {
  if (DEBUG_ON) printf("DEBUG MODE: ON\n");
  if (DEBUG_ON) printf("--------------\n");

  int direction = 0; // normal=0, reverse=1
  int flag;

  printf("parsing flags...\n");
  while ((flag = getopt(argc, argv, "r")) != -1) {
    printf("flag: %d\n", flag);
    switch(flag) {
      case 'r':
        if (DEBUG_ON) printf("setting direction: reverse\n");
        direction = 1;
        break;
      default:
        printf("usage: -[r]\n");
    }
  }
  printf("parsing flags complete...\n");

  // get the directory entries
  struct dirent **directory_entries;
  int file_count;
  char *directory = ".";
  printf("argc: %d\n", argc);

  // if the first argument starts with a `-`, then directory stays as default
  // if it does not, then it must be a directory name
  if (argc > 1) {
    if (!starts_with("-", argv[1][0])) {
      directory = argv[1]; 
    }
  }

  file_count = scandir(directory, &directory_entries, NULL, alphasort);

  if (file_count < 0) {
    perror("scandir");
    exit(EXIT_FAILURE);
  } else {
    print_entries(direction, file_count, directory_entries);
    printf("\n");
    free(directory_entries);
  }
  exit(EXIT_SUCCESS);
}

/* 
 * TODO
 *
 * I want a nicer way to log debug messages.
 * How do I pass a varied amount of arguments to a function? I could write a logger
 * function that takes a template string and an amount of arguments to be passed to printf.
 *
 * definition of done:
 * - [ ] implement flag handling
 *  - [x] r
 *  - [ ] d (for debug)
 *  - [ ] a
 *  - [ ] l
 *  - [ ] h
 */
