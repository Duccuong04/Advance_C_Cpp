# Tính đa hình

- “Polymorphism” có nghĩa “nhiều hình thức”, hay “nhiều
dạng sống”;

- Một vật có tính đa hình (polymorphic) là vật có thể xuất
hiện dưới nhiều dạng;

- Đa hình là hiện tượng các đối tượng
thuộc các lớp khác nhau có khả năng hiểu cùng một
thông điệp theo các cách khác nhau.

- Ta có thể có định nghĩa tương tự cho đa hình hàm:
một thông điệp (lời gọi hàm) được hiểu theo các
cách khác nhau tuỳ theo danh sách tham số của
thông điệp.

- Ví dụ: nhận được cùng một thông điệp “nhảy”, một
con kangaroo và một con cóc nhảy theo hai kiểu
khác nhau: chúng cùng có hành vi “nhảy” nhưng các
hành vi này có nội dung khác nhau.

- Tính đa hình ( Polymorphism) có nghĩa là "nhiều dạng" và nó xảy ra khi chúng ta có nhiều class có liên quan với nhau thông qua tính kế thừa.

- Tính đa hình có thể được chia thành hai loại chính:

**Đa hình tại thời điểm biên dịch (Compile-time Polymorphism).**

**Đa hình tại thời điểm chạy (Run-time Polymorphism).**

## Đa hình tại thời điểm chạy (Run-time Polymorphism).

- ***upcast***  là quá trình tương tác với thể hiện của lớp
dẫn xuất như thể nó là thể hiện của lớp cơ sở. (con trỏ từ lớp cha trỏ đến đối tượng thuộc về lớp con)

-  Cụ thể, đây là việc đổi một con trỏ (hoặc tham
chiếu) tới lớp dẫn xuất thành một con trỏ (hoặc
tham chiếu) tới lớp cơ sở

```c
    DoiTuong *dt = &sv1; // up-casting
    dt->display();

    DoiTuong *dt1[3] = {&sv1, &hs1, &gv1};

    for (size_t i = 0; i < 3; i++)
    {
        dt1[i] ->display();
    }
    
```

Kết quả:

```c
ten: Cuong
id: 1
ten: Cuong
id: 2
ten: Tru Nguyen
id: 3
```
-> Chỉ xuất ra 2 thuộc tính (mất dữ liệu)

-> Cách xử lý: Sử dụng ***Virtual Function***

### 1. Override

- Overload: Tận dụng tính năng đã có sẵn, mở rộng ra ở các class thừa kế

- Override: ngoài tính năng của overload, override có thể ghi đè, định nghĩa hàm hoàn toàn mới

- Hàm ảo là một hàm thành viên được khai báo trong class cha với từ khóa virtual.

- Khi một hàm là virtual, nó có thể được ghi đè (override) trong class con để cung cấp cách triển khai riêng.

- Khi gọi một hàm ảo thông qua một con trỏ hoặc tham chiếu đến lớp con, ***hàm sẽ được quyết định dựa trên đối tượng thực tế mà con trỏ hoặc tham chiếu đang trỏ tới chứ không dựa vào kiểu của con trỏ.***

```c
#include <iostream>

using namespace std;

class cha{
    public:
        virtual void display(){                            // Hàm ảo
            cout << "display from class cha" << endl;
        }
};

class con : public cha{
    public:
        void display() override{                           // Ghi đè hàm ảo
            cout << "display from class con" << endl;
        }
};

int main(){
    cha *ptr;
    con obj;

    // trỏ con trỏ class cha đến đối tượng class con
    ptr = &obj;

    // Gọi hàm ảo
    ptr->display();
}


```

- Hàm ảo đi với từ khóa virtual

-  Một khi một phương thức được khai báo là hàm ảo
tại lớp cơ sở, nó sẽ tự động là hàm ảo tại mọi lớp
dẫn xuất trực tiếp hoặc gián tiếp

- Tuy không cần tiếp tục dùng từ khoá virtual trong
các lớp dẫn xuất, nhưng vẫn nên dùng để tăng tính
dễ đọc của các file header (nhắc ta rằng phương thức đó sử dụng liên kết động)

### 2. Pure Virtual Function (hàm thuần ảo)

- Hàm thuần ảo là một hàm ảo không có phần định nghĩa trong class cha, được khai báo với cú pháp = 0 và khiến class cha trở thành class trừu tượng, nghĩa là không thể tạo đối tượng từ class này.

```c
#include <iostream>
using namespace std;

class cha{
    public:
        virtual void display() = 0; // Hàm ảo thuần túy
};

class con : public cha{
    public:
        void display() override{   // Ghi đè hàm ảo thuần túy
            cout << "display from class con" << endl;
        }
};

int main(){
    // cha ptr; // wrong
    cha *ptr;
    con obj;

    ptr = &obj;
    ptr->display();

    return 0;
}

```

- Không thể tạo đối tượng vì lớp cha là lớp trừu tượng (có chứa ít nhất 1 hàm thuần ảo)

- Vẫn có thể khai báo con trỏ -> vì con trỏ đã trỏ tới lớp khác

- Phải ghi đè hàm ảo thuần túy, nếu không chương biên dịch sẽ hiểu cần chạy hàm thuần ảo của lớp cha -> lỗi

**Khi nào sử dụng hàm ảo, hàm thuần ảo???**

- Sử dụng hàm ảo khi đã biết chức năng chung của hàm con -> sử dụng hàm ảo để triển khai chức năng đó

- Sử dụng hàm ảo khi *chưa biết chức năng chung của hàm con*, triển khai = override hàm đó tại các lớp con

### 3. Kế thừa ảo

- Kế thừa ảo giúp tránh vấn đề diamond problem trong đa kế thừa.

- Chỉ có một bản sao duy nhất của lớp cơ sở chung được kế thừa.

- Kế thừa ảo giúp quản lý các lớp liên quan đến phần cứng và giao tiếp. 

- Điều này giúp tránh trùng lặp tài nguyên và quản lý hiệu quả trong hệ thống nhúng.


```c
#include <iostream>

using namespace std;

class A{
    public:
        A(){ cout << "Constructor A\n"; }

        void hienThiA(){ cout << "Day la lop A\n"; }
};

class B : public A{
    public:
        B(){ cout << "Constructor B\n"; }

        void hienThiB(){ cout << "Day la lop B\n"; }
};

class C : public A {
    public:
        C(){ cout << "Constructor C\n"; }

        void hienThiC(){ cout << "Day la lop C\n"; }
};

class D : public B, public C{
    public:
        D(){ cout << "Constructor D\n"; }

        void hienThiD(){ cout << "Day la lop D\n"; }
};

int main() {
    D d;

    // d.hienThiA(); // wrong

    // Gọi phương thức từ lớp A qua B và C
    d.B::hienThiA(); // Gọi hàm hienThiA từ lớp A thông qua B
    d.C::hienThiA(); // Gọi hàm hienThiA từ lớp A thông qua C

    // d.hienThiB();
    // d.hienThiC();
    // d.hienThiD();

    return 0;
}



```

- Diamond problem: Nếu từ đối tượng d gọi `d.hienThiA();` -> lỗi vì không biết hiển thị hàm đó thông qua lớp nào 

- Cách 1: Dùng toán tử ::

- Cách 2: Kế thừa ảo

```c
#include <iostream>

using namespace std;

class A {
    public:
        A(){ cout << "Constructor A\n"; }

        void hienThiA(){ cout << "Day la lop A\n"; }
};

class B : virtual public A{
    public:
        B(){ cout << "Constructor B\n"; }

        void hienThiB(){ cout << "Day la lop B\n"; }
};

class C : virtual public A {
    public:
        C(){ cout << "Constructor C\n"; }

        void hienThiC(){ cout << "Day la lop C\n"; }
};

class D : public B, public C{
    public:
        D(){ cout << "Constructor D\n"; }

        void hienThiD(){ cout << "Day la lop D\n"; }
};

int main() {
    D d;

    d.hienThiA();

    // Gọi phương thức từ lớp A qua B và C
    // d.B::hienThiA(); // Gọi hàm hienThiA từ lớp A thông qua B
    // d.C::hienThiA(); // Gọi hàm hienThiA từ lớp A thông qua C

    // d.hienThiB();
    // d.hienThiC();
    // d.hienThiD();

    return 0;
}


```

- `class B : virtual public A`, `class C : virtual public A`: chỉ có 1 bản sao duy nhất của lớp cơ sở B và C