#include <stdio.h>

int *ptr = NULL;

int total(int a, int b)
{
    const int x = 5;    // stack: read - write

    ptr = &x;
    *ptr = 99;
    
    int c;
    c = a + b;
    return c;
}

int main(int argc, char const *argv[])
{
    printf("a+b=%d\n",total(5,6));
    /*
        0x01: 5
        0x12: 6
        0x06: 11
    */
    printf("a+b=%d\n",total(9,7));
    /*
        0x01: 9
        0x02: 7
        0x08: 16
    */
    return 0;
}