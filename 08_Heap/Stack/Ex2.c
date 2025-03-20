#include <stdio.h>

int foo(int x)
{
    printf("addr of x: %p - value of x: %d\n", &x, x);
    return foo(x);
}

int main(int argc, char const *argv[])
{
    foo(2);
    return 0;
}

// đệ quy qua nhiều --> memory leak