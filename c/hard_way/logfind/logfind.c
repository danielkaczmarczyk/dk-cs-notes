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
 *
 * look at:
 * https://codeforwin.org/2018/01/c-program-read-and-display-file-contents.html
 */
void read_logfind(char *globs[]) {
  FILE *fp;
  int buffer_length = 255;
  char buffer[buffer_length];

  fp = fopen(".logfind", "r");
 
  int i = 0;
  while (fgets(buffer, buffer_length, fp)) {
    char *current_glob = malloc(128);
    strcpy(buffer, current_glob);
    globs[i] = current_glob;
    i++;
    printf("%s", buffer);
  }

  fclose(fp);
}

int main(int argc, char *argv[]) {

  debug("start reading globs");
  FILE *glob_file_pointer;

  char *globs[128];
  int globs_count = 0;

  int buffer_length = 255;
  char buffer[buffer_length]; // buffer of chars to put temporary stuff in

  glob_file_pointer = fopen(".logfind", "r");
  char c;
  int i = 0;
  int j = 0;
  do {
    c = fgetc(glob_file_pointer);
    if (c == '\n') {
      // copy what is in the buffer into a new location in memory
      // TODO what happens if it's just a newline?
      if (strlen(buffer) == 0) {
        debug("strlen of buffer is zerO!");
        continue;
      }
      char *current_glob = malloc(128);
      strcpy(current_glob, buffer);
      // and put the pointer to it in globs
      globs[j] = current_glob;
      globs_count++;
      j++;
      i = 0;
      memset(buffer, 0, sizeof(buffer));
    } else {
      buffer[i] = c;
      debug("putting %c in the buffer. current buffer: %s", c, buffer);
      i++;
    }
  } while(c != EOF);
  debug("reading globs over");

  debug("got %d globs!", globs_count);
  for (int k = 0; k < globs_count; k++) {
    // does the glob string include the newline character?
    int len = strlen(globs[k]);
    for (int l = 0; l < len; l++) {
      char c = globs[k][l];
      debug("%c: %d", c, c); 
    }
  }

  fclose(glob_file_pointer);
}

