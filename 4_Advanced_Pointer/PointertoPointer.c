#include <stdio.h>

int main(int argc, char const *argv[])
{
    int a= 5;

    int *p = &a;

    int **ptp = &p;

    printf("Addr of a = %p %p %p\n", &a, p, *ptp);
    printf("Value of a = %d %d %d\n", a, *p, **ptp);

    return 0;
}
