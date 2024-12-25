#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
/*
int a = 10;

uint16_t *ptr = &a; // data

double *ptr = NULL; // bss
*/
int main(int argc, char const *argv[])
{

   
    uint16_t *ptr = NULL; // Stack

    int size;

    scanf("%d", &size);

    ptr = (uint16_t* )malloc(size * sizeof(uint16_t));
    /*
    -  cấp phát động theo số lượng phần tử và kiểu dữ liệu từng phần tử
    - ép kiểu để đọc đúng dữ liệu tại từng phần tử
    */
   for(int i = 0; i < size; i++)
   {
    printf("addr %d: %p - value: %d\n", i, ptr+i, *(ptr+i));
   }
      
    
    return 0;
}
