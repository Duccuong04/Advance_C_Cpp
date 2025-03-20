#include <stdio.h>
#include <setjmp.h>

jmp_buf buf;

int exception;

void display()
{
    int x = 0;
}

int main(int argc, char const *argv[])
{
    exception = setjmp(buf);

    if(!exception)
    {
        printf("Exception = 0\n");
    }
    else if(exception == 1)
    {
        printf("Exception = 1\n");
    }
    else
    {
        printf("Exception # 0,1\n");
    }

    longjmp(buf, 2);
    
    return 0;
}
