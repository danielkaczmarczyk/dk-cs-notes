#include "dbg.h"
#include <stdlib.h>
#include <stdio.h>

void test_debug()
{
  // notice you don't need the \n
  debug("I have brown hair.");
}

int main(int argc, char *argv[]) {
  test_debug();
}
