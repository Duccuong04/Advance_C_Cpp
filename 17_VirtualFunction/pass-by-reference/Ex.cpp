#include <iostream>

using namespace std;

void modifyByReference(int &ref)
{
    cout << "Địa chỉ biến ref: " << &ref << endl;
    ref++;
    cout << "Giá trị: " << ref << endl;
}

void modifyByPointer(int *ptr)
{
    *ptr = 30;
}

int main()
{
    int x = 10;  // 0x34: 10
    cout << "Địa chỉ biến x: " << &x << endl;

    modifyByReference(x); // Tham chiếu
    cout << "After modifyByReference: " << x << endl;

    modifyByPointer(&x); // Con trỏ
    cout << "After modifyByPointer: " << x << endl;

    return 0;
}
