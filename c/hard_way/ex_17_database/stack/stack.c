#include <stdio.h>
#include <stdlib.h>

struct stack {
  int n_items;
  char items[512];
};

struct stack *new() {
  struct stack *s = malloc(sizeof(struct stack));
  s->n_items = 0;
  return s;
}

void print(struct stack *s) {
  printf("stack { items: %d } [ ", s->n_items);
  for (int i = 0; i < s->n_items; i++ ) {
    printf("%c, ", s->items[i]);
  }
  printf("]\n");
}


int main(int argc, char *argv[]) {
  struct stack *s = new();
  print(s);
}

