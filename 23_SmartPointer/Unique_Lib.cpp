#include <iostream>

using namespace std;

/**
 * @brief   Lớp UniquePointer quản lý một con trỏ duy nhất và tự động giải phóng vùng nhớ.
 * @tparam  T   Kiểu dữ liệu của đối tượng được quản lý.
 */
template <typename T>
class UniquePointer
{
    private:
        T *ptr; /**< Con trỏ thô đến đối tượng được quản lý. */
        

    public:
        /**
         * @brief   Constructor khởi tạo con trỏ UniquePointer.
         * @param   p   Con trỏ thô đến đối tượng. Giá trị mặc định là nullptr.
         */
        UniquePointer(T *p = nullptr) : ptr(p){}


        /**
         * @brief   Destructor giải phóng vùng nhớ của đối tượng được quản lý nếu không null.
         */
        ~UniquePointer()
        {
            if (ptr) delete ptr;
        }


        /**
         * @brief   Copy Constructor - Xóa bỏ khả năng sao chép đối tượng UniquePointer.
         */
        UniquePointer(const UniquePointer &other);


        /**
         * @brief   Copy Assignment Operator - Xóa bỏ khả năng gán bằng copy đối tượng UniquePointer.
         * @return  Trả về tham chiếu đến đối tượng UniquePointer hiện tại.
         */
        UniquePointer& operator = (const UniquePointer &other);


        /**
         * @brief   Toán tử dereference để truy cập đối tượng được quản lý.
         * @return  Tham chiếu đến đối tượng được quản lý.
         */
        T& operator * () const
        {
            return *ptr;
        }


        /**
         * @brief   Toán tử để truy cập các thành phần của đối tượng.
         * @return  Con trỏ đến đối tượng được quản lý.
         */
        T* operator -> () const
        {
            return ptr;
        }


        /**
         * @brief   Trả về con trỏ thô đến đối tượng được quản lý.
         * @return  Con trỏ thô đến đối tượng.
         */        
        T* get() const
        {
            return ptr;
        }

        
        /**
         * @brief   Chuyển quyền sở hữu đối tượng cho con trỏ thô bên ngoài.
         * @return  Con trỏ thô đến đối tượng trước khi release.
         */
        T* release()
        {
            T* temp = ptr;  // lưu lại địa chỉ của đối tượng đang quản lý
            ptr = nullptr;  // đặt con trỏ thô ptr thành con trỏ null
            return temp;    // trả về địa chỉ của đối tượng
        }

        
        /**
         * @brief   Giải phóng đối tượng hiện tại và quản lý đối tượng mới.
         * @param   p   Con trỏ thô đến đối tượng mới. Mặc định là nullptr.
         */
        void reset(T *newPtr = nullptr)
        {
            if (this->ptr) delete ptr;

            ptr = newPtr;
        }


        /**
         * @brief   Move constructor chuyển nhượng quyền sở hữu con trỏ.
         * @param   other   Đối tượng 'UniquePointer' cần chuyển nhượng quyền sở hữu.
         */
        UniquePointer(UniquePointer &&other) : ptr(other.ptr)
        {
            other.ptr = nullptr;
        }


        /**
         * @brief   move assignment operator - Toán tử gán chuyển nhượng quyền sở hữu.
         * @param   other   Đối tượng 'UniquePointer' cần chuyển nhượng quyền sở hữu.
         */
        UniquePointer& operator = (UniquePointer &&other)
        {
            if (this != &other)
            {
                // giải phóng đối tượng hiện tại
                if (this->ptr) delete ptr;

                // chuyển quyền sở hữu
                this->ptr = other.ptr;
                other.ptr = nullptr;
            }

            return *this;
        }
};


class Test 
{
    public:
        int value;

        Test(int val = 10) : value(val){}

        void setValue(int newValue)
        {
            value = newValue;
        }

        int getValue() const
        {
            return value;
        }

        void display() const 
        {
            cout << "Test value: " << getValue() << endl;
        }
};

int main(int argc, char const *argv[])
{
    /* Khởi tạo 1 Unique Pointer */
    UniquePointer<int> uptr1 = new int(10);


    /* Ngăn chặn copy constructor */
    // UniquePointer<int> uptr2 = uptr1;


    /* Ngăn chặn copy assignment operator */
    // UniquePointer<int> uptr2;
    // uptr2 = uptr1;


    /* truy cập và in giá trị */ 
    cout << "value of int: " << *uptr1 << endl; // *ptr


    /* lấy giá trị con trỏ thô */
    cout << "Get - value of int: " << *(uptr1.get()) << endl;


    /* chuyển quyền sở hữu đối tượng cho con trỏ thô mới */
    // int *rawPtr = uptr1.release();
    // cout << "Release - value of int: " << *rawPtr << endl;
    // delete rawPtr;

    // if (uptr1.get() == nullptr){
    //     cout << "true\n";
    // } else {
    //     cout << "false\n";
    // }


    /* thu hồi đối tượng cũ và bắt đầu quản lý đối tượng mới */
    uptr1.reset(new int(50));
    cout << "new value of int: " << *uptr1 << endl;


    /* thu hồi vùng nhớ chứa 20, uptr không quản lý vùng nhớ nào */
    uptr1.reset();
    if (uptr1.get() == nullptr){
        cout << "uptr không còn quản lý đt\n";
    } else {
        cout << "uptr vẫn còn quản lý đt\n";
    }

    // uptr1.reset(new int(100));


    /* sử dụng move semantic để chuyển quyền sở hữu */
    UniquePointer<int> uptr2(move(uptr1));
    // if (uptr1.get() == NULL){
    //     cout << "uptr đã chuyển quyền sở hữu\n";
    //     cout << "new value of int: " << *uptr2 << endl;
    // } else {
    //     cout << "uptr vẫn còn quyền sở hữu\n";

    // }


    /* sử dụng move assignment operator để chuyển quyền sở hữu */
    UniquePointer<int> uptr3;
    uptr3 = move(uptr2);
    // cout << "uptr3 đang quản lý đối tượng kiểu int có giá trị là: " << *uptr3 << endl;


    /* Sử dụng toán tử truy cập thành phần */
    cout << endl;
    UniquePointer<Test> uptr = new Test(10);
    uptr->display();
    uptr->setValue(50);
    uptr->display();

    (*uptr).setValue(100);
    (*uptr).display();


    /* khi kết thúc chương trình, bộ nhớ sẽ được tự động giải phóng */ 
    return 0;
}
