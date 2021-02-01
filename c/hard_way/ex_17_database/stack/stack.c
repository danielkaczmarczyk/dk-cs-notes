#include <stdio.h>
#include <stdlib.h>

struct char_stack {
  int n_items;
  char items[512];
};

struct char_stack *new(void);
void print(struct char_stack *stack);
int push(struct char_stack *stack, char item);
int pop(struct char_stack *stack);
int is_empty(struct char_stack *stack);
void test_driver(void);
char peek(struct char_stack *stack);
int size(struct char_stack *stack);
void flush(struct char_stack *stack);
void destroy(struct char_stack *stack);

struct char_stack *new(void) {
  struct char_stack *stack = malloc(sizeof(struct char_stack));
  if (!stack) {
    printf("Memory error!\n");
    exit(1);
  }
  stack->n_items = 0;
  return stack;
}

void print(struct char_stack *stack) {
  printf("char_stack { items: %d } [ ", size(stack));
  for (int i = 0; i < stack->n_items; i++ ) {
    printf("%c, ", stack->items[i]);
  }
  printf("]\n");
}

int push(struct char_stack *stack, char item) {
  stack->items[stack->n_items] = item;
  stack->n_items += 1;
  return stack->n_items;
}

int pop(struct char_stack *stack) {
  if (is_empty(stack)) return 0;
  stack->items[stack->n_items] = 0;
  stack->n_items--;
  return stack->n_items;
}

int is_empty(struct char_stack *stack) {
  if (stack->n_items == 0) return 1;
  return 0;
}

char peek(struct char_stack *stack) {
  return stack->items[stack->n_items - 1];
}

int size(struct char_stack *stack) {
  return stack->n_items;
}

void flush(struct char_stack *stack) {
  stack->n_items = 0;
}

void destroy(struct char_stack *stack) {
  free(stack);
  printf("Stack destroyed.\n");
}

void test_driver(void) {
  struct char_stack *stack = new();
  print(stack);
  push(stack, 'l');
  push(stack, 'a');
  push(stack, 'r');
  push(stack, 'd');
  print(stack);
  pop(stack);
  pop(stack);
  push(stack, 'l');
  push(stack, 'a');
  push(stack, ' ');
  push(stack, 'l');
  push(stack, 'a');
  push(stack, 'n');
  push(stack, 'd');
  print(stack);
  printf("peeking: %c\n", peek(stack));
  printf("size: %d\n", size(stack));
  flush(stack);
  print(stack);
  destroy(stack);
  print(stack);
}

int main(int argc, char *argv[]) {
  test_driver();
}


// TODO write stack to file
// TODO read stack to file
