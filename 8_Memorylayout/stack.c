#include <stdio.h>

int *ptr = NULL;

void test()
{
    const int c = 10; // 0xf4: stack

    ptr = &c;
    *ptr = 20;

    printf("%d", c);
    
    char *str = "hello";

}

void test1()
{
    static int x = 0;
    printf("addr of x: %p, value of x: %d", &x, x);
}