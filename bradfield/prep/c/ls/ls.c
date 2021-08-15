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

#define DEBUG_ON 1

// get a macro for swapping directions?
int starts_with(const char *string, const char c) {
  return string[0] == c;
}


#define for_up(x) for (int i = 0; i < x ; i++) {
#define for_down(x) for (int i = x; i > 0; i--) {


void print_entries(int direction, int file_count, struct dirent **directory_entries) {
  //(direction == true) ? for_up(file_count) : for_down(file_count);

  direction == true ? for_up(file_count) : for_down(file_count);
    printf("hello\n");
  }

  if (direction == DIR_N) {
    int i = 0;
    while (i < file_count) {
      // prints name of file
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

// void get_file_stats(char *filename, struct stat *stbuf) {
//   stat(filename, stbuf);
//   
//     char *name = ".";
//     struct stat stbuf;
//     
//     // man 2 stat to look up details
//     stat(name, &stbuf);
//   
//       printf("no argument specified. acting on cwd.\n");
//       printf("%llu\n", stbuf.st_ino);
//       printf("%u\n", stbuf.st_uid);
//       printf("%u\n", stbuf.st_gid);
//       printf("%u\n", stbuf.st_rdev);
//     }
// }


int main(int argc, char **argv) {
  if (DEBUG_ON) printf("DEBUG MODE: ON\n");

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
 * - [ ] implement flag handling
 *  - [x] r
 *  - [ ] a
 *  - [ ] l
 *  - [ ] h
 * - [ ] write tests
 *
 */
