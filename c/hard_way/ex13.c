#include <stdio.h>

int main(int argc, char *argv[])
{
  int i = 0;

  char *states[] = {
    "California",
    "Oregon",
    NULL,
    "Maine"
  };

  argv[1] = states[3];

  for (i = 1; i < argc; i++)
  {
    printf("arg %d: %s\n", i, argv[i]);
  }


  states[2] = argv[0];

  int num_states = 4;
  char *state;
  for (i = 0; i < num_states && (state = states[i]); i++) {
    printf("State %d: %s\n", i, state);
  }
  return 0;
}
