#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int *ptr = new int(10);
    /****************************************************
     * new int(10)
     *      + Khởi tạo một biến int
     *      + Cấp phát động cho biến int (0x01 - 0x04 - Heap)
     *      + Gán giá trị tại địa chỉ vừa cấp phát là 10
     *      + Trả về địa chỉ của vùng nhớ mới được cấp phát
     * 
     * con trỏ ptr sẽ trỏ đến địa chỉ trên
     ***************************************************/

    cout << "Địa chỉ đối tượng: " << ptr << endl;
    cout << "Giá trị đối tượng: " << *ptr << endl;

    delete ptr;

    return 0;
}

