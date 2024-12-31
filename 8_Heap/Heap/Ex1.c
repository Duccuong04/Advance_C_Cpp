#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char const *argv[])
{
    uint16_t *ptr = NULL;   // stack

    int size;

    scanf("%d", &size);

    ptr = (uint16_t*)malloc(size * sizeof(uint16_t));  
    // cấp phát động 10 bytes: 
    // 0x01 0x02 0x03 0x04 0x05 ... 0x09 0x0A

    // ptr[0] = 2;
    // ptr[1] = 5;
    // ptr[2] = 6;

    for (int i=0; i<size; i++)
    {
        ptr[i] = 3*i;   // 0 3 6 9 12
    }

    // scanf("%d", &size);

    ptr = (uint16_t*)realloc(ptr, 10 * sizeof(uint16_t));
    // cấp phát động 20 bytes: 
    // 0x01 0x02 0x03 0x04 0x05 ... 0x09 0x0A ...

    for (int i=0; i<10; i++)
    {
        ptr[i] = 0;// cách thu hồi thứ 2
    }

    for (int i=0; i<10; i++)
    {
        printf("addr %d: %p - value: %d\n", i, ptr+i, *(ptr+i));
    }

    // for (int i=0; i<20; i++)
    // {
    //     printf("địa chỉ: %p, giá trị: %d\n", (uint8_t*)arr+i, *((uint8_t*)arr+i));
    // }

    // free(ptr);

    // ptr = NULL;

    return 0;
}
