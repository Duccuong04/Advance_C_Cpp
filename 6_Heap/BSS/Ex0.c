#include <stdio.h>

typedef struct
{
    int x;
    int y;
} Point_Data;

Point_Data p1 = {5,0};  // p1,x,y: data

Point_Data p2;  // p2,x,y: bss

Point_Data p3 = {0,0};  // p3,x,y: bss

int a = 0;  // bss
int b = 5;  // data

static int m = 0;   // bss
static int n;       // bss

int *ptr = NULL;    // bss  

void test(){
    static int c = 1;   // data
    static int d;       // bss
    static int e = 0;   // bss  // 0x01
}

void funcA()
{
    static int x = 1;   // data
    printf("addr of x: %p - value: %d\n", &x, x);
}

void funcB()
{
    static int x = 0;   // bss
    printf("addr of x: %p - value: %d\n", &x, x);
}

int main() {
    printf("a: %d\n", a);
    printf("m: %d\n", m);
    funcA();
    funcB();
    return 0;
}