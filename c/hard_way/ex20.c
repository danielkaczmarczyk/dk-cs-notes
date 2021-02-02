#include "dbg.h"
#include <stdlib.h>
#include <stdio.h>

void test_debug()
{
  // notice you don't need the \n
  debug("I have brown hair.");

  // passing in arguments like printf
  debug("I am %d years old.", 37);
}

void test_log_err()
{
  log_err("I believe everything is broken.");
  log_err("There are %d problems in %s", 0, "space");
}


int main(int argc, char *argv[]) {
  test_debug();
  test_log_err();
}
