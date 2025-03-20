#include <stdio.h>
#include "test.c"

#define SIZE1 5
int array[SIZE1];

// define function
#define CREATE_FUNC(name, cmd) \
void name()                    \
{                              \
    printf(cmd);               \
}
CREATE_FUNC(test1, "This is function test 1\n");
CREATE_FUNC(test2, "This is function test 2\n");

void hello()
{
    printf("Owned by main.c\n");
}

int SIZE2 = 10;

int main(int argc, char const *argv[])
{
    printf("SIZE1 = %d\n", SIZE1);

    #undef SIZE1

    #define SIZE1 50

    printf("SIZE1 = %d\n", SIZE1);

    int array2[SIZE2];
    hello();
    oftest();
    test1();
    test2();
    return 0;
}
