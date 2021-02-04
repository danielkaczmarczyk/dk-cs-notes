#include <stdio.h>
#include <dirent.h>
#include <glob.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "dbg.h"
#define BUFFER_SIZE 512

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

/**
 * Reads globs from the configuration file and puts them
 * in a globs array inside of main
 */
int get_globs(char *globs[]) {
  debug("start reading globs");
  FILE *glob_file_pointer;

  int globs_count = 0;

  int buffer_length = 255;
  char buffer[buffer_length];

  glob_file_pointer = fopen(".logfind", "r");
  char c;
  int i = 0;
  int j = 0;
  do {
    c = fgetc(glob_file_pointer);
    if (c == '\n') {
      if (strlen(buffer) == 0) {
        debug("strlen of buffer is zero!");
        continue;
      }

      char *current_glob = malloc(128);
      strcpy(current_glob, buffer);
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
  debug("reading globs over. got %d globs!\n\n", globs_count);
  fclose(glob_file_pointer);
  return globs_count;
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

int get_filenames(char *globs[], int globs_count, char *filenames[]) {
  int files_count = 0;
  /* ----- ITERATE OVER FILENAMES THAT ARE GOING TO BE SEARCHED ----- */

  for (int i = 0; i < globs_count; i++) {
    debug("USING GLOB %s", globs[i]);
    glob_t g;
    debug("starting glob");
    glob(globs[i], 0, NULL, &g);
    debug("glob over. filenames count: %zu", g.gl_pathc);

    for (int i = 0; i < g.gl_pathc; i++) {
      debug("in the inside loop. i: %d", i);

      char *filename = malloc(128);
      strcpy(filename, g.gl_pathv[i]);
      filenames[files_count++] = filename;
      debug("file to search: %s", g.gl_pathv[i]);

//       for (int i = 0; i < argc; i++) {
//         if (!is_flag(argv[i])) {
//           debug("keyword: %s", argv[i]);
//           // perform strstr line by line on the contents of the file
//           // if at any point we've got a non-null value, STOP PROCESSING this file and
//           FILE *fp;
//           char buffer[BUFFER_SIZE];
//           fp = fopen(g.gl_pathv[i], "r");
//           if (fp == NULL) {
//             log_err("Unable to open %s.", g.gl_pathv[i]);
//             log_err("FAULTY gl_pathv i: %d", i);
//             log_err("FAULTY argv[i]: %s", argv[i]);
//           } else {
//             while(fgets(buffer, BUFFER_SIZE, fp) != NULL) {
//               debug("current line: %s", buffer);
//             }
//           }
// 
//           fclose(fp);
//           // return its filename.
//         }
//       }
    }
  }
  return files_count;
}

void print_strings(char *array[], int len, char *var_name) {
  debug("Printing contents of %s", var_name);
  for (int i = 0; i < len; i++) {
    debug("%s", array[i]);
  }
  debug("End contents of %s\n", var_name);
}


int main(int argc, char *argv[]) {

  // Gather globs from the config file
  char *globs[128];
  int globs_count;
  globs_count = get_globs(globs);
  print_strings(globs, globs_count, "globs");

  // Gather filenames to be searched based on globs
  char *filenames[128];
  int files_count = 0;
  files_count = get_filenames(globs, globs_count, filenames);
  print_strings(filenames, files_count, "filenames");

}

