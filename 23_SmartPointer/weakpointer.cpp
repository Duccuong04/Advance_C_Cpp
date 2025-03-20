#include <iostream>
#include <memory>

using namespace std;

int main(int argc, char const *argv[]) {
    shared_ptr<int> ptr1 = make_shared<int>(20); // 0x01
    shared_ptr<int> ptr2 = ptr1;

    // Tạo một weak_ptr trỏ tới đối tượng được quản lý bởi shared_ptr
    weak_ptr<int> ptr3 = ptr1;

    cout << "Count: " << ptr1.use_count() << endl;
    cout << "ptr3: " << *(ptr3.lock()) << endl;
    cout << "Count: " << ptr1.use_count() << endl;

    ptr1.reset(); // Giải phóng quyền sở hữu của ptr1 đối với đối tượng tại địa chỉ 0x01
    cout << "check: " << ptr3.expired() << endl;
    cout << "Count: " << ptr2.use_count() << endl;

    ptr2.reset();
    cout << "check: " << ptr3.expired() << endl;

    return 0;
}
