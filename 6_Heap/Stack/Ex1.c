#include <stdio.h>

int *ptr = NULL;

void test()
{
    const int c = 10; // 0xf4: stack

    ptr = &c;
    *ptr = 20;

    printf("%d\n", c);

    char *str = "hello";
}

void test1()
{
    static int x = 0;
    printf("1 - addr of x: %p - value of x: %d\n", &x, x);
}

void test2()
{
    static int x = 0;
    printf("2 - addr of x: %p - value of x: %d\n", &x, x);
}

int main(int argc, char const *argv[])
{
    test();

    test1();
    test2();

    return 0;
}
