#include <stdio.h>
#include <stdint.h>

int main(int argc, char const *argv[])
{
    // khai báo con trỏ void để trỏ tới các kiểu dữ liệu khác nhau
    void *ptr_void;

    // con trỏ void trỏ tới địa chỉ biến int
    int var_int = 10;
    ptr_void = &var_int;

    printf("Addr of = %p, Value = %d\n", ptr_void, *(int *)ptr_void);

    // Ép con trỏ void sang uint8_t* để đọc từng byte
    uint8_t *byte_ptr = (uint8_t *)ptr_void;

    for (int i = 0; i < 4; i++) // đọc từng byte trong 4 byte
    {
        printf("Addr of = %p, Value = %d\n", (byte_ptr + i), *(byte_ptr + i));
    }

    // trỏ tới địa chỉ khác
    double var_double = 3.14;
    ptr_void = &var_double;

     printf("Addr of = %p, Value = %.3f\n", ptr_void, *(double *)ptr_void);

     // trỏ đến 1 mảng
     char arr[] = "hello"; // gồm các kí tự h,e,l,l,o,\0
     ptr_void = arr;

     printf("Chuỗi: ");
     for(int i = 0; i <= (sizeof(arr)/sizeof(arr[0])); i++)
     {
        printf("%c\n", *(char* )(ptr_void + i));
     }
     printf("\n");

    /*Khai báo mảng con trỏ void*/
    void *ptr[] = {&var_int, &var_double, arr};
    printf("ptr[0] = %d\n", *(int* )ptr[0]);
    printf("ptr[1] = %f\n", *(double* )ptr[1]);

    for(int i = 0; i < (sizeof(arr)/sizeof(arr[0])); i++)
    {
        printf("%c\n", *(char* )(ptr[2] + i));
    }
    return 0;
}