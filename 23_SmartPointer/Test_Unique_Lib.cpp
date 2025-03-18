#include <iostream>
#include "UniquePointer.hpp"
using namespace std;

/**
 * @class Test
 * @brief Lớp Test để kiểm thử UniquePointer.
 */
class Test 
{
    public:
        int value;  /**< Biến dữ liệu của lớp Test. */

        /**
         * @brief Constructor của Test.
         * @param[in] val Giá trị khởi tạo (mặc định là 10).
         */
        Test(int val = 10) : value(val){}

        /**
         * @brief Thiết lập giá trị mới cho biến value.
         * @param[in] newValue Giá trị mới cần đặt.
         */
        void setValue(int newValue)
        {
            value = newValue;
        }

        /**
         * @brief Lấy giá trị hiện tại của biến value.
         * @return Giá trị int của biến value.
         */
        int getValue() const
        {
            return value;
        }


        /**
         * @brief Hiển thị giá trị của biến value.
         */
        void display() const 
        {
            cout << "Test value: " << getValue() << endl;
        }
};




int main(int argc, char const *argv[])
{
    /* Khởi tạo 1 Unique Pointer */
    UniquePointer<int> uptr1 = new int(10); // ptr = 0x01


    /* Ngăn chặn copy constructor */
    // UniquePointer<int> uptr2 = uptr1;
    UniquePointer<int> uptr2;

    /* Ngăn chặn copy assignment operator */
    // UniquePointer<int> uptr2;
    // uptr2 = uptr1;


    /* truy cập và in giá trị */ 
    cout << "value of int: " << *uptr1 << endl; // *ptr


    /* lấy giá trị con trỏ thô */
    cout << "Get - value of int: " << *(uptr1.get()) << endl;

    // int *rawPtr1 = uptr1.get();

    // cout << *rawPtr1 << endl;

    /* chuyển quyền sở hữu đối tượng cho con trỏ thô mới */
    // int *rawPtr = uptr1.release();
    // cout << "Release - value of int: " << *rawPtr << endl;
    // delete rawPtr;

    // if (uptr1.get() == nullptr){
    //     cout << "true\n";
    // } else {
    //     cout << "false\n";
    // }


    // /* thu hồi đối tượng cũ và bắt đầu quản lý đối tượng mới */
    uptr1.reset(new int(50));   // 0x0a
    cout << "new value of int: " << *uptr1 << endl;


    /* thu hồi vùng nhớ chứa 20, uptr không quản lý vùng nhớ nào */
    // uptr1.reset();
    // if (uptr1.get() == nullptr){
    //     cout << "uptr không còn quản lý đt\n";
    // } else {
    //     cout << "uptr vẫn còn quản lý đt\n";
    // }

    // // uptr1.reset(new int(100));


    /* sử dụng move semantic để chuyển quyền sở hữu */
    // UniquePointer<int> uptr2 = move(uptr1);
    UniquePointer<int> uptr2;

    uptr2 = move(uptr1);

    // // if (uptr1.get() == NULL){
    // //     cout << "uptr đã chuyển quyền sở hữu\n";
    // //     cout << "new value of int: " << *uptr2 << endl;
    // // } else {
    // //     cout << "uptr vẫn còn quyền sở hữu\n";

    // // }


    // /* sử dụng move assignment operator để chuyển quyền sở hữu */
    // UniquePointer<int> uptr3;
    // uptr3 = move(uptr2);
    // // cout << "uptr3 đang quản lý đối tượng kiểu int có giá trị là: " << *uptr3 << endl;


    // /* Sử dụng toán tử truy cập thành phần */
    // cout << endl;
    // UniquePointer<Test> uptr = new Test(10);
    // uptr->display();
    // uptr->setValue(50);
    // uptr->display();

    // (*uptr).setValue(100);
    // (*uptr).display();


    /* khi kết thúc chương trình, bộ nhớ sẽ được tự động giải phóng */ 
    return 0;
}
