#include <stdio.h>

const int a = 10;
char arr[] = "Hello";  // mảng kí tự
char *arr1 = "Hello";  // chuỗi hằng
int b = 0;
int *ptr = &b;

int main() {
   

    printf("a: %d\n", a);

    arr[3] = 'W';
    printf("arr: %s", arr);

  //  arr1[3] = 'E';
    printf("arr1: %s", arr1);

    
    return 0;
}



