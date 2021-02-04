#include <stdio.h>
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

/**
 * Test whether string starts with a given character.
 */
int starts_with_char(const char starts, const char *str) {
  if (str[0] == starts) {
    return 1;
  }
  return 0;
}

int is_flag(const char *str) {
  if (starts_with_char('-', str)) {
    return 1;
  }
  return 0;
}

void parse_args(int argc, char *argv[]) {
  // find '-o'
  for (int i = 1; i < argc; i++) {
    printf("%s\n", argv[i]);
  }
}

int main(int argc, char *argv[]) {
  int or = 0;
  int test_mode = 0;
  parse_args(argc, argv);
}


