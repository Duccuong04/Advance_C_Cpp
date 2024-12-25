#include <stdio.h>

int a = 5;          // data // 0x01

static int b = 6;   // data

int *ptr = &b;     // data

void test(){
    static int c = 7;   // data // 0xf4
    ptr = &c;
}

int main(int argc, char const *argv[])
{
    a = 6;
    *ptr = 99;

    return 0;
}