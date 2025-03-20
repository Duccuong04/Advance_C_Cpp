#include <stdio.h>
#include <stdint.h>

typedef union 
{
    uint8_t var1;
    uint32_t var2;
    uint16_t var3;
} frame;

int main(int argc, char const *argv[])
{
    frame data;

    data.var1 = 5;
    data.var2 = 10;

    printf("var1: %d", data.var1); 
    printf("var2: %d", data.var1);

    data.var2 = 4294967290; //0b 11111111 11111111 11111111 11111010
                                 0x03     0x02     0x01     0x00
    
    /*
    data.var2 = 11111010
    data.var2 = 11111111 11111010
    */
    
    return 0;
}
