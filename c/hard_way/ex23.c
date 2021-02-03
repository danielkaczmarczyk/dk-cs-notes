#include <stdio.h>
#include <string.h>
#include "dbg.h"

int normal_copy(char *from, char *to, int count)
{
  int i = 0;

  for (i = 0; i < count; i++) {
    to[i] = from[i];
  }

  return i;
}

int duffs_device(char *from, char *to, int count)
{
  {
    int n = (count + 7) / 8;

    switch (count % 8) {
      case 0:
        do {
          *to++ = *from++;
          case 7:
          *to++ = *from++;
          case 6:
          *to++ = *from++;
          case 5:
          *to++ = *from++;
          case 4:
          *to++ = *from++;
          case 3:
          *to++ = *from++;
          case 2:
          *to++ = *from++;
          case 1:
          *to++ = *from++;
        } while (--n > 0);
    }
  }

  return count;
}
