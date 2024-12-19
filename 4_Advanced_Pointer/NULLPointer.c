#include <stdio.h>

int main(int argc, char const *argv[])
{
    int *ptr = NULL;

    printf("Addr of ptr: %p\n", ptr);

    if(ptr == NULL)
    {
        printf("Pointer is NULL, can't dereference\n");
    }

    else
    {
        printf("Ptr = %d\n", *ptr);
    }
    return 0;
}
