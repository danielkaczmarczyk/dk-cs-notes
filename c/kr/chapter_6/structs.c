#include <stdio.h>

int main(void) {

  struct point {
    int x;
    int y;
  };
   
  // define a variable pt which is a structure of type
  // struct point
  struct point pt;

  struct point maxpt = { 320, 200 };

  printf("x:%d y:%d\n", maxpt.x, maxpt.y);

  struct rect {
    struct point pt1;
    struct point pt2;
  };

  struct rect screen;

  screen.pt1.x = 3;
  screen.pt1.y = 4;
  screen.pt2.x = 5;
  screen.pt2.y = 6;

  printf("x:%d y:%d\n", screen.pt1.x, screen.pt1.y);
  printf("x:%d y:%d\n", screen.pt2.x, screen.pt2.y);

  /*
   * Legal operations on structs:
   *  - copying it
   *  - assigning to a unit
   *  - taking its adderss with &
   *  - accessing its members
   */
  return 0;
}
