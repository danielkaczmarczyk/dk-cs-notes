#ifndef lcthw_List_h
#define lcthw_List_h

#include <stdlib.h>

struct ListNode;

typedef struct ListNode {
  struct ListNode *next;
  struct ListNode *prev;
  void *value;
} ListNode;

typedef struct List {
  int count;
  ListNode *first;
  ListNode *last;
} List;

