#include <stdio.h>

int main(int argc, char const *argv[])
{
    int var = 5;
    const int* ptr = &var;
    var = 6; // no error
    ptr = 6; //error
    return 0;
}
