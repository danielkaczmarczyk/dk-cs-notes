#include <stdio.h>

struct point {
  int x;
  int y;
};

struct rect {
  struct point p1;
  struct point p2;
};

struct point make_point(int x, int y) {
  struct point temp;
  temp.x = x;
  temp.y = y;
  return temp;
}

struct rect make_rect(int x, int y, int z, int q) {
  struct point point1, point2;
  struct rect temp;
  
  point1 = make_point(x, y);  
  point2 = make_point(z, q);  

  temp.p1 = point1;
  temp.p2 = point2;

  return temp;
}

void print_rectangle(struct rect rectangle) {
  printf("%d, %d\n", rectangle.p1.x, rectangle.p1.y);   
  printf("%d, %d\n", rectangle.p2.x, rectangle.p2.y);   
}

int main(void) {
  
  struct rect rectangle = make_rect(0, 0, 10, 10);
  print_rectangle(rectangle);

  return 0;
}
