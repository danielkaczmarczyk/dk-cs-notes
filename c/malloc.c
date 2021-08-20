#include <stdio.h>
#include <stdlib.h>

int main() {
    int *p = (int*)malloc(3 * sizeof(int));

    *p = 2;
    *(p+1) = 4;
    *(p+2) = 6;

    printf("0: %d\n", *p);
    printf("1: %d\n", *(p+1));
    printf("2: %d\n", *(p+2));

}
