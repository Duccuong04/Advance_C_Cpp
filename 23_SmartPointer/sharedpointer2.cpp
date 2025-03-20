#include <iostream>
#include <memory>

using namespace std;

class HinhChuNhat {
public:
    HinhChuNhat() { cout << "Constructor called." << endl; }
    ~HinhChuNhat() { cout << "Destructor called." << endl; }
};

int main() {
    shared_ptr<HinhChuNhat> ptr1 = make_shared<HinhChuNhat>();
    cout << "Count after creating ptr1: " << ptr1.use_count() << endl; // 1

    shared_ptr<HinhChuNhat> ptr2 = ptr1;
    cout << "Count after ptr2 = ptr1: " << ptr1.use_count() << endl; // 2

    {
        shared_ptr<HinhChuNhat> ptr3 = ptr1;
        cout << "Count inside scope (ptr3 = ptr1): " << ptr1.use_count() << endl; // 3
    } // ptr3 ra khỏi phạm vi, giảm `use_count()`

    cout << "Count after ptr3 is destroyed: " << ptr1.use_count() << endl; // 2

    ptr2.reset(); // Giải phóng `ptr2`
    cout << "Count after ptr2.reset(): " << ptr1.use_count() << endl; // 1

    ptr1.reset(); // Giải phóng `ptr1`, đối tượng bị hủy
    cout << "Program ends." << endl;

    return 0;
}
