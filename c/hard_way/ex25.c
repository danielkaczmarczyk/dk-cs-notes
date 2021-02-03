#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include "dbg.h"

#define MAX_DATA 100

int read_string(char **out_string, int max_buffer)
{
  *out_string = calloc(1, max_buffer + 1);
  check_mem(*out_string);

  char *result = fgets(*out_string, max_buffer, stdin);
  check(result != NULL, "Input error.");

  return 0;

error:
  if (*out_string) free(*out_string);
  *out_string = NULL;
  return -1;
}

int read_int(long *out_int)
{
  char *input = NULL;
  char *end = NULL;
  int rc = read_string(&input, MAX_DATA);
  check(rc == 0, "Failed to read number.");

  *out_int = strtol(input, &end, 10);
  check((*end == '\0' || *end == '\n') && *input != '\0', "Invalid number: %s", input);

  free(input);
  return 0;

error:
  if (input) free(input);
  return -1;
}


