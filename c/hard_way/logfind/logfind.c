#include <stdio.h>
#include <dirent.h>
#include <glob.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "dbg.h"

/**
 *             LOGFIND
 *
 *   an alternative to grep
 *   that is not only more limited in functionality
 *   but also probably doesn't work well!
 *
 *   by 
 *   daniel kaczmarczyk
 *
 *   built to pass exercise 26 from
 *   learn c the hard way by zed shaw
 *
 *
 *   available flags:
 *   o      for running the queries in an 'or' manner
 *   t      for running the automated tests
 *
 *   flags to be passed ONLY separately, ex.:
 *   $ ./logfind -o -t hello world
 *
 *   passing flags like that:
 *   $ ./logfind -ot hello world
 *   _will not work_
 *
 */

/* GLOBALS */
int or = 0;
int test_mode = 0;

/* FN DECLARATIONS */

void print_usage();
int starts_with_char(const char starts, const char *str);
int is_flag(const char *str);
void parse_args(int argc, char *argv[]);


/**
 * Print usage of the tool in case of malformed args
 */
void print_usage() {
  printf("USAGE: ./logfind [-o, -t] ARG1, [ARG2, ARG3...]\n");
  exit(1);
}

/**
 * Test whether string starts with a given character.
 */
int starts_with_char(const char starts, const char *str) {
  if (str[0] == starts) {
    return 1;
  }
  return 0;
}

/**
 * Verify whether a given argument is a flag
 */
int is_flag(const char *str) {
  if (starts_with_char('-', str)) {
    if (strlen(str) == 2) {
      return 1;
    } else {
      print_usage();
      return 0;
    }
  } else {
    return 0;
  }
}

void parse_args(int argc, char *argv[]) {
  for (int i = 1; i < argc; i++) {
    printf("%s", argv[i]);
    if (is_flag(argv[i])) {
      char c = argv[i][1];

      switch (c) {
        case 'o':
          or = 1;
          break;

        case 't':
          test_mode = 1;
          break;

        default:
          log_err("Invalid flag declared.");
          break;
      }
    }
      printf("\n");
  }
}

/**
 * Searches current directory for files that match the
 * patterns we defined in ~/.logfind
 *
 * Returns all the filenames that MATCH
 * TODO: it does not do that
 */
void search_dir() {
  DIR *folder = NULL;    // pointer to the directory
  struct dirent *entry;  // struct for a directory entry, defined in <dirent.h>
  int files = 0;

  folder = opendir(".");
  // TODO fix it to use zed's macros
  if (folder == NULL) {
    puts("Unable to read directory");
  }

  while ((entry = readdir(folder))) {
    files++;
    printf("File %3d: %s\n", files, entry->d_name);
  }

  closedir(folder);
}

void globbing() {
  glob_t g;

  //g.gl_offs = 2;
  //
  
  // TODO -> first argument here is going to accept entries from ~/.logfind
  glob("*.c", GLOB_DOOFFS, NULL, &g);
  debug("%zu", g.gl_pathc);
  debug("%d", g.gl_matchc);
  debug("%zu", g.gl_offs);
  debug("%d", g.gl_flags);
  for (int i = 0; i < g.gl_pathc; i++) {
    // IF FILE (gl_pathv[i] IS IN LIST of files to be searched for, SEARCH
    debug("%s", g.gl_pathv[i]);
  }
  execvp("ls", g.gl_pathv);
}

/**
 * reads contents of ~/.logfind and
 * treats every line as a glob pattern
 */
void read_logfind() {
  FILE *fp;
  int buffer_length = 255;
  char buffer[buffer_length];

  fp = fopen("~/.logfind", "r");

  debug("%c \n", fp[0];

  // debug("before fgets");
  // while (fgets(buffer, buffer_length, fp)) {
  //   debug("in fgets");
  //   printf("%s\n", buffer);
  // }
  // debug("after fgets");

  fclose(fp);
}

int main(int argc, char *argv[]) {
  read_logfind();
}

