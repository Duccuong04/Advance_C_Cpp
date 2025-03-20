#include <stdio.h>

int main(int argc, char const *argv[])
{
    int test = 2;

    int *ptr = &test;

    printf("Size of pointer: %d bytes\n", sizeof(ptr));

    printf("Address of test: %p\n", &test);
    printf("Address of test: %p\n", ptr);

    printf("Value of test: %d\n", test);
    printf("Value of test: %d\n", *ptr); // dereference


    return 0;
}
