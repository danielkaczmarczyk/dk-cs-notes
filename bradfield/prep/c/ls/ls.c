#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdarg.h>
#include <dirent.h>

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

// print file sizes
int main(int argc, char **argv) {
  //  printf("running ls program...\n");
  //

  struct dirent **directory_entries;
  int file_count;

  if (argc < 1) {
    exit(EXIT_FAILURE);
  } else if (argc == 1) {
    file_count = scandir(".", &directory_entries, NULL, alphasort);
  } else {
    file_count = scandir(argv[1], &directory_entries, NULL, alphasort);
  }

  if (file_count < 0) {
    perror("scandir");
    exit(EXIT_FAILURE);
  } else {
    // this loop controls the order
    while (file_count--) {
      // prints name of file
      printf("%s ", directory_entries[file_count]->d_name);
      // prints file type
      // printf("%hhu\n", directory_entries[file_count]->d_type);
    }
    printf("\n");
    free(directory_entries);
  }
  exit(EXIT_SUCCESS);
}

/* 
 * TODO
 *
 * - [ ] implement flag handling
 *  - [ ] l
 *  - [ ] a
 *  - [ ] h
 *  - [ ] r
 *
 */
