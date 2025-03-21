#include <stdio.h>
#include <setjmp.h>

jmp_buf buf;

int exception_code;
const char *exception_msg;

typedef enum
{
    NO_ERROR,
    NO_EXIT,
    DIVIDE_BY_0
} ErrorCodes;  

#define TRY if ((exception_code = setjmp(buf)) == 0)
#define CATCH(x) else if (exception_code == x)
#define THROW(x, msg) do{exception_code = x; exception_msg = msg; longjmp(buf, x);} while(0)

double divide(int a, int b)
{
    if (a == 0 && b == 0)
    {
        THROW(NO_EXIT, "a & b đều bằng 0, không tồn tại" );
    }
    else if (b == 0)
    {
        THROW(DIVIDE_BY_0, "Lỗi phép chia cho 0");
    }

    return (double)a/b;
}

int main(int argc, char const *argv[])
{
    exception_code = NO_ERROR;

    TRY
    {
        printf("Ket qua: %0.3f\n", divide(0,0));
    }
    CATCH(NO_EXIT)
    {
        printf("%s\n", exception_msg);
    }
    CATCH(DIVIDE_BY_0)
    {
        printf("%s\n", exception_msg);
    }

    // thêm code ở đây
    printf("Hello world\n");
    return 0;
}


