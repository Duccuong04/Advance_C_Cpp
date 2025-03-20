#include <stdio.h>

typedef struct 
{
    int x;
    int y;
} Point_Data;

Point_Data p1 = {5, 0};

Point_Data p2;

Point_Data p1 = {0, 0};

int a = 0; //bss
int b = 5; //data

static int m = 0;  //bss
static int n;      // bss

void test()
{
    static int c = 1; //data
    static int d;     //bss
    static int e = 0; //bss
}

void funcA()
{
    static int x = 0; //bss
}

void funcB()
{
    static int x = 0; //bss
}


int main(int argc, char const *argv[])
{
    
    return 0;
}

