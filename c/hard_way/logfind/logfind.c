#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dbg.h"


/**             TODO
 * - [ ] implement checking for flags
 * - [ ] implement checking for an 'or' flag
 * - [ ] implement checking for a -t flag for tests _and running them_
 */

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
      debug(" is flag");
      char c = argv[i][1];

      switch (c) {
        case 'o':
          debug("o found");
          or = 1;
          break;

        case 't':
          debug("t found");
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

int main(int argc, char *argv[]) {
  parse_args(argc, argv);
}


