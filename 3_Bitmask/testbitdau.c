#include <stdio.h>

int main() {
    int signed_num = -8;        // Số có dấu
    unsigned int unsigned_num = 8;  // Số không dấu

    printf("Signed -8 >> 2 = %d\n", signed_num >> 2);          // Dịch phải số học
    printf("Unsigned 8 >> 2 = %u\n", unsigned_num >> 2);       // Dịch phải logic

    return 0;
}