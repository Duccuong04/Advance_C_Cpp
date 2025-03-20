# Smart Pointer

**1. Giới thiệu về RAII**

📌 Khái niệm

- **RAII (Resource Acquisition Is Initialization)** là một kĩ thuật quản lý tài nguyên trong lập trình C++, trong đó tài nguyên (bộ nhớ, file, mutex, socket).. **được cấp phát khi một đối tượng được khởi tạo** và **giải phóng khi đối tượng đó bị hủ**y. Điều này giúp tránh rò rỉ tài nguyên và đảm bảo việc giải phóng tài nguyên diễn ra một cách tự động, ngay cả khi có ngoại lệ xảy ra.

📌 **Nguyên tắc hoạt động**

- **Cấp phát tài nguyên trong Constructor**: Khi 1 đối tượng được tạo, nó sẽ lấy tài nguyên cần thiết (ví dụ: cấp phát bộ nhớ động, mở file, lock mutex,...)

- **Giải phóng tài nguyên trong destructor**: Khi đối tượng đi ra khỏi phạm vi (scope), destructor của nó được gọi và tài nguyên sẽ được giải phóng 1 cách an toàn

## Unique_ptr
- Là một loại smart pointer trong C++, giúp quản lý bộ nhớ động và tự động giải phóng bộ nhớ khi không còn cần thiết. 

- Đặc điểm chính của unique_ptr là một unique_ptr **chỉ có thể sở hữu một đối tượng hoặc mảng** và khi một unique_ptr bị hủy, bộ nhớ của đối tượng sẽ được tự động giải phóng.

### Tính độc quyền

 - Ngăn chặn việc quản lí pointer từ đối tượng khác

```
        /**
         * @brief   Copy Assignment Operator - Xóa bỏ khả năng gán bằng copy đối tượng UniquePointer.
         * @return  Trả về tham chiếu đến đối tượng UniquePointer hiện tại.
         */
        UniquePointer& operator = (const UniquePointer &other) = delete;
c
```

- Chỉ ngăn chặn được cái đối tượng cùng loại, không ngăn chặn được con trỏ thô

```c
     /**
         * @brief   Trả về con trỏ thô đến đối tượng được quản lý.
         * @return  Con trỏ thô đến đối tượng.
         */        
        T* get() const
        {
            return ptr;
        }

```

1️⃣ Constructor (UniquePointer(T *p = nullptr))

UniquePointer(T *p = nullptr) : ptr(p) {}

📌 Chức năng:
Khởi tạo UniquePointer với một con trỏ thô (T* p).
Nếu không có đối số (p mặc định là nullptr), con trỏ ptr sẽ trỏ đến nullptr.

🛠️ Ví dụ:

```c
UniquePointer<int> p1(new int(10)); // p1 quản lý vùng nhớ chứa giá trị 10
UniquePointer<int> p2;              // p2 trỏ đến nullptr

```

2️⃣ Destructor (~UniquePointer())


```c
~UniquePointer()
{
    if (ptr) delete ptr;
}

```

📌 Chức năng:
Tự động giải phóng vùng nhớ khi đối tượng UniquePointer bị hủy.
Nếu ptr trỏ đến một vùng nhớ hợp lệ, nó sẽ được giải phóng bằng delete.

🛠️ Ví dụ:


```c
{
    UniquePointer<int> p(new int(20)); // cấp phát động giá trị 20
} // khi `p` ra khỏi scope, bộ nhớ được giải phóng tự động

```

3️⃣ Copy Constructor (XÓA)

UniquePointer(const UniquePointer &other) = delete;

📌 Chức năng:

Không cho phép sao chép một UniquePointer vì mỗi đối tượng phải sở hữu một con trỏ duy nhất.

🚫 Ví dụ KHÔNG hợp lệ:

UniquePointer<int> p1(new int(30));
UniquePointer<int> p2 = p1; // ❌ Lỗi: Copy constructor bị xóa

4️⃣ Copy Assignment Operator (XÓA)

UniquePointer& operator = (const UniquePointer &other) = delete;

📌 Chức năng:

Ngăn chặn phép gán giữa hai UniquePointer.

🚫 Ví dụ KHÔNG hợp lệ:

UniquePointer<int> p1(new int(40));
UniquePointer<int> p2;
p2 = p1; // ❌ Lỗi: Toán tử gán bị xóa

5️⃣ Toán tử Dereference (operator*)

T& operator * () const
{
    return *ptr;
}

📌 Chức năng:

Cho phép truy cập giá trị mà UniquePointer đang quản lý.

🛠️ Ví dụ:

UniquePointer<int> p(new int(50));
std::cout << *p << std::endl; // ✅ In ra: 50

6️⃣ Toán tử Arrow (operator->)

T* operator -> () const
{
    return ptr;
}

📌 Chức năng:

Cho phép truy cập các thành viên của đối tượng được quản lý bằng ->.

🛠️ Ví dụ:

struct Test { void sayHello() { std::cout << "Hello!" << std::endl; } };
UniquePointer<Test> p(new Test());
p->sayHello(); // ✅ Gọi phương thức sayHello()

7️⃣ Phương thức get()

T* get() const
{
    return ptr;
}

📌 Chức năng:

Trả về con trỏ thô mà UniquePointer đang quản lý mà không thay đổi quyền sở hữu.

🛠️ Ví dụ:

UniquePointer<int> p(new int(60));
int* rawPtr = p.get(); // ✅ Lấy con trỏ thô, nhưng không giải phóng bộ nhớ

8️⃣ Phương thức release()

T* release()
{
    T* temp = ptr;
    ptr = nullptr;
    return temp;
}

📌 Chức năng:

Giải phóng quyền sở hữu của UniquePointer và trả về con trỏ thô.

Người dùng chịu trách nhiệm giải phóng vùng nhớ.

🛠️ Ví dụ:

UniquePointer<int> p(new int(70));
int* rawPtr = p.release(); // ✅ p không còn quản lý con trỏ
delete rawPtr; // ✅ Giải phóng bộ nhớ theo cách thủ công

9️⃣ Phương thức reset()

void reset(T *newPtr = nullptr)
{
    if (this->ptr) delete ptr;
    ptr = newPtr;
}

📌 Chức năng:

Giải phóng vùng nhớ hiện tại (nếu có) và quản lý con trỏ mới (newPtr).

🛠️ Ví dụ:

UniquePointer<int> p(new int(80));
p.reset(new int(90)); // ✅ Giải phóng giá trị cũ, quản lý giá trị mới (90)

🔟 Move Constructor (UniquePointer(UniquePointer &&other))

UniquePointer(UniquePointer &&other) : ptr(other.ptr)
{
    other.ptr = nullptr;
}

📌 Chức năng:

Di chuyển quyền sở hữu từ other sang đối tượng mới.

Đảm bảo other không còn quản lý vùng nhớ.

🛠️ Ví dụ:

UniquePointer<int> p1(new int(100));
UniquePointer<int> p2 = std::move(p1); // ✅ p2 nhận quyền sở hữu, p1 trở thành nullptr

1️⃣1️⃣ Move Assignment Operator (operator =)

UniquePointer& operator = (UniquePointer &&other)
{
    if (this != &other)
    {
        if (this->ptr) delete ptr;
        this->ptr = other.ptr;
        other.ptr = nullptr;
    }
    return *this;
}

📌 Chức năng:

Gán UniquePointer bằng cách di chuyển quyền sở hữu thay vì sao chép.

Tránh tự gán (this != &other).

Giải phóng vùng nhớ hiện tại trước khi nhận quyền sở hữu.

🛠️ Ví dụ:

UniquePointer<int> p1(new int(110));
UniquePointer<int> p2;
p2 = std::move(p1); // ✅ p2 nhận quyền sở hữu, p1 trở thành nullptr

💡 Tổng kết

| Phương thức | Chức năng |
|------------|----------|
| `UniquePointer(T *p = nullptr)` | Khởi tạo con trỏ |
| `~UniquePointer()` | Giải phóng bộ nhớ tự động |
| `UniquePointer(const UniquePointer &other) = delete` | Không cho phép copy |
| `UniquePointer& operator=(const UniquePointer &other) = delete` | Không cho phép gán copy |
| `T& operator*()` | Truy cập giá trị đối tượng |
| `T* operator->()` | Truy cập thành viên đối tượng |
| `T* get()` | Trả về con trỏ thô mà không thay đổi quyền sở hữu |
| `T* release()` | Giải phóng quyền sở hữu, trả về con trỏ thô |
| `void reset(T *newPtr = nullptr)` | Giải phóng và quản lý con trỏ mới |
| `UniquePointer(UniquePointer &&other)` | Move Constructor, chuyển quyền sở hữu |
| `UniquePointer& operator=(UniquePointer &&other)` | Move Assignment Operator |


## Shared Pointer

- shared_ptr là một smart pointer trong thư viện <memory> của C++.

- Nó giúp quản lý bộ nhớ tự động bằng cách theo dõi số lượng shared_ptr cùng sở hữu một đối tượng.

- Khi số lượng shared_ptr tham chiếu đến đối tượng giảm về 0, đối tượng đó sẽ tự động bị hủy.

`    shared_ptr <HinhChuNhat> ptr1 (new HinhChuNhat(40,10));/ shared_ptr<HinhChuNhat> ptr1 = std::make_shared<HinhChuNhat>(40,10);
`:

📌ptr1:

- Là một đối tượng shared_ptr, đóng vai trò như một smart pointer để quản lý đối tượng HinhChuNhat.

📌new HinhChuNhat(40,10):

- Cấp phát động một đối tượng của lớp HinhChuNhat với các tham số khởi tạo (40,10), tức là tạo một hình chữ nhật có chiều dài 40 và chiều rộng 10.
Đối tượng này sẽ được quản lý bởi shared_ptr, nên không cần gọi delete thủ công.


`ptr1.use_count()`: trả về số lượng shared_ptr cùng quản lý 1 đối tượng


## Weak Pointer

- Tham chiếu yếu (weak reference) đến một đối tượng được quản lý bởi shared_ptr.

- Không tăng bộ đếm tham chiếu của shared_ptr. 

- Không trực tiếp truy cập đến đối tượng (object) mà nó theo dõi. 

📌 `cout << "ptr3: " << *(ptr3.lock()) << endl;`

Trả về: Một shared_ptr hợp lệ mà weak pointer đang trỏ tới nếu đối tượng vẫn tồn tại, hoặc một shared_ptr null ptr nếu đối tượng đã bị hủy.

📌 Hàm expired()

Công dụng: Kiểm tra xem đối tượng mà weak_ptr trỏ tới có còn tồn tại không.

true nếu đối tượng đã bị hủy.

false nếu đối tượng vẫn còn tồn tại.

## lvalue & rvlaue

- `&&` biểu thị cho 1 giá trị tạm thời, có thể thay đổi đột ngột, sử dụng khi viết thư viện có liên quan đến hàm move()





