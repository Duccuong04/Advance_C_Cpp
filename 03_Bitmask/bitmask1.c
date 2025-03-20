#incldude <stdint.h>

/*
    int, int32_t, uint32_t: 4 byte
    int8_t, uint8_t: 1 byte
    int16_t, uint16_t: 2 byte
*/ 

/*
    uint8_t PORT_A = 0b00001101 (1 byte)
    bit 0: Pin_A0
    bit 1: Pin_A1 
    bit 2: Pin_A2
    .
    .
    .
    bit 8: Pin_A8

    Thao tác trên các bit này -> bit mask
*/

int main(int argc, char const *argv[])
{
    uint8_t A = 0b01001001
    uint8_t B = 0b11101111
    /*
    ~A = 0b10110110
    A&B = 0b01001001
    A|B = 0b11101111
    A^B = 0b10100110
    A = A << 2; 0b00100100
    B = B >> 3; 0b01111000
    */


    return 0;
}
