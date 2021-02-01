#include <stdio.h>

struct stack {
  int n_items;
  char items[512];
};

struct stack *new() {
  struct stack *s = malloc(sizeof(struct stack));
  return s;
}

void push(const char item) {

}

int main(int argc, char *argv[]) {
  struct stack *s = new();
}
