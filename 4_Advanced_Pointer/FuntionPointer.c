#include <stdio.h>

void tong(int a, int b)
{
    printf("%d + %d = %d\n", a, b, a + b);
}

void hieu(int a, int b)
{
    printf("%d - %d = %d\n", a, b, a - b);
}

void tich(int a, int b)
{
    printf("%d * %d = %d\n", a, b, a * b);
}

/* Cách 2: Sử dụng con trỏ hàm làm tham số của 1 hàm */
void tinhtoan(void(*pheptoan)(int, int), int a, int b)
{
    pheptoan(a,b);
}
int main(int argc, char const *argv[])
{

    int a = 2, b = 3;
       
    /* Cách 1: Sử dụng con trỏ ham để gọi các phép toán */
    void(*ptr)(int, int); // khai báo con trỏ hàm
    ptr = tong;           // hoặc ptr = &tong; trỏ đến địa chỉ của hàm tổng 
    ptr(a, b);            // truyền vào tham số

    ptr = hieu;
    ptr(a, b);

    ptr = tich;
    ptr(a, b);

    /* Cách 2: Sử dụng con trỏ hàm làm tham số của 1 hàm */
    tinhtoan(tong, a, b);
    tinhtoan(hieu, a, b);
    tinhtoan(tich, a, b);

    /* Cách 3: Sử dụng mảng con trỏ hàm để gọi các phép toán*/
   void (*arr[])(int, int) = {tong, hieu, tich};
   arr[0](a, b);
   arr[1](a, b);
   arr[2](a, b);

  
    return 0;
}
