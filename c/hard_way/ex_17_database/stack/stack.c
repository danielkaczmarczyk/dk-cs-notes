#include <stdio.h>
#include <stdlib.h>

struct char_stack {
  int n_items;
  char items[64];
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

void write(struct char_stack *stack) {
  FILE *fp;
  fp = fopen("stack.st", "w");
  if (fp == NULL) {
    printf("\nError opening file\n");
    exit(1);
  }

  fwrite(stack, sizeof(struct char_stack), 1, fp);
  fclose(fp);
} 

struct char_stack *read(void) {
  FILE *fp;
  struct char_stack *stack = malloc(sizeof(struct char_stack));

  fp = fopen("stack.st", "r");
  if (fp == NULL) {
    printf("\nError opening file\n");
    exit(1);
  }
  fread(&stack, sizeof(struct char_stack), 1, fp);
  fclose(fp);
  return stack;
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
  print(stack);
  push(stack, 'l');
  push(stack, 'a');
  push(stack, 'r');
  push(stack, 'd');
  print(stack);
  write(stack);
  printf("written stack\n");

  printf("attempting to read stack\n");
  struct char_stack *new_stack;
  new_stack = read();
  printf("read stack successfully\n");
  print(new_stack);
}

int main(int argc, char *argv[]) {
  test_driver();
}

// TODO read stack from file
