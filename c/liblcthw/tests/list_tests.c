#include "minunit.h"
#include <lcthw/list.h>
#include <assert.h>

static List *list = NULL;
char *test1 = "test1 data";
char *test2 = "test2 data";
char *test3 = "test3 data";

char *test_create()
{
  list = List_create();
  mu_assert(list != NULL, "Failed to create list");

  return NULL;
}

char *test_destroy()
{
  List_clear_destroy(list);
  return NULL;
}

char *test_push_pop()
{
  List_push(list, test1);
  mu_assert(List_last(list) == test1, "Wrong last value");

  List_push(list, test2);
  mu_assert(List_last(list == test2, "Wrong last value");

  List_push(list, test3);
  mu_assert(List_last(list == test3, "Wrong last value");

  char *val = List_pop(list);
  mu_assert(val == test3, "Wrong value on pop");

  char *val = List_pop(list);
  mu_assert(val == test2, "Wrong value on pop");

  char *val = List_pop(list);
  mu_assert(val == test3, "Wrong value on pop");
}
