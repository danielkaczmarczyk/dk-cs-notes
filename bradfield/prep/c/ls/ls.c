#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdarg.h>

struct stat * get_file_stats(char *filename) {
  struct stat stbuf;
  stat(filename, &stbuf);
  // I shouldn't return that address as this variable is
  // not going to be accessible out of scope - 
  // I think I have to make that method get a pointer to a struct
  // that it will write to.
  return &stbuf;
}

// print file sizes
int main(int argc, char **argv) {
  printf("running ls program...\n");

  char *name = ".";
  struct stat stbuf;
  
  // man 2 stat to look up details of what's up
  stat(name, &stbuf);

  if (argc == 2) {
    printf("no argument specified. acting on cwd.\n");

    printf("%llu\n", stbuf.st_ino);
    printf("%u\n", stbuf.st_uid);
    printf("%u\n", stbuf.st_gid);
    printf("%u\n", stbuf.st_rdev);
  }
}

