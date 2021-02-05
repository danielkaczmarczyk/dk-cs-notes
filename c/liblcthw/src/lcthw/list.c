#include <lcthw/list.h>
#include <lcthw/dbg.h>

List *List_create()
{
  return calloc(1, sizeof(List));
}

void List_destroy(List * list)
{
  LIST_FOREACH(list, first, next, cur) {
    if (cur->prev) {
      free(cur->prev);
    }
  }

  free(list->last);
  free(list);
}
