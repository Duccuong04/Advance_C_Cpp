#include <stdio.h>

char *ptr = "Hello world";  // ptr: data, "Hello world": rdata/text     --> nên sử dụng 'const char*' khi dùng con trỏ thao tác với chuỗi 

const int a = 0;            // rdata/text   // rdata (read-only data)

int main(int argc, char const *argv[])
{
    printf("%d\n", a);

    // a = 20;          // wrong

    // ptr[1] = 'a';    // wrong
    printf("chuoi: %s\n", ptr);

    return 0;
}
