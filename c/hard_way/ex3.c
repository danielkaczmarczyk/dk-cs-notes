#include <stdio.h>

int main()
{
    int age = 10;
    int height = 72;
    char name[] = "Daniel";

    printf("I am %d years old. ", age);
    printf("I am %d inches tall.\n", height);
    printf("My name is %s\n", name + 11);      // moving the pointer
}
  
