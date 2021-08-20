#include <stdlib.h>

int main() {
    int *p;
    
    while (1) {
        p = (int*)malloc(sizeof(int) * 1240);
        *p = 10;
    }
    
}
