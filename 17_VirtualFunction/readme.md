# Tính đa hình (Polymorphism)

- “Polymorphism” có nghĩa “nhiều hình thức”, hay “nhiều
dạng sống”;

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

### 1. Override & Overload

#### Function ***overloading*** - 

Hàm chồng: dùng một tên
hàm cho nhiều định nghĩa hàm, khác nhau ở danh
sách tham số

- Method overloading – Phương thức chồng: tương tự
void jump(int howHigh);
void jump(int howHigh, int howFar);

- Hai phương thức jump trùng tên nhưng có danh sách
tham số khác nhau.

- Tuy nhiên, đây không phải đa hình hướng đối tượng
mà ta đã định nghĩa, vì đây thực sự là hai thông điệp
jump khác nhau

#### Override: 

- Ngoài tính năng của overload, override có thể ghi đè, định nghĩa hàm hoàn toàn mới

- Đa hình được cài đặt bởi một khái niệm tương tự nhưng hơi
khác: method overriding:
o “override” có nghĩa “vượt quyền”.

- Method overriding: nếu một phương thức của lớp cơ sở
được định nghĩa lại tại lớp dẫn xuất thì định nghĩa tại lớp cơ
sở có thể bị “che” bởi định nghĩa tại lớp dẫn xuất;

- Với method overriding, toàn bộ thông điệp (cả tên và tham
số) là ***hoàn toàn giống nhau – điểm khác nhau là lớp đối
tượng được nhận thông điệp.***

- Khi một hàm ảo được ghi đè, hành vi của nó sẽ phụ thuộc vào kiểu của đối tượng thực tế, chứ không phải kiểu của con trỏ hay tham chiếu.

- Tính đa hình Run-time xảy ra khi quyết định gọi hàm nào (phiên bản của class cha hay class con) được đưa ra tại ***thời điểm chạy***, không phải lúc biên dịch, giúp mở rộng chức năng. Điều này giúp chương trình linh hoạt hơn, cho phép việc mở rộng chức năng mà không cần sửa đổi mã nguồn hiện tại.


### 2.VIRTUAL FUNCTION

- Hàm/phương thức ảo – virtual function/method
là cơ chế của C++ cho phép cài đặt đa hình động;

- Nếu khai báo một hàm thành viên (phương thức) là
virtual, trình biên dịch sẽ đẩy lùi việc liên kết các lời
gọi phương thức đó với định nghĩa hàm cho đến khi
chương trình chạy;

Nghĩa là, ta bảo trình biên dịch sử dụng liên kết động thay
cho liên kết tĩnh đối với phương thức đó.

-  Để một phương thức được liên kết tại thời gian chạy,
nó phải khai báo là phương thức ảo (từ khoá
virtual) tại lớp cơ sở.

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

### 3. Pure Virtual Function (hàm thuần ảo)

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

### 4. Kế thừa ảo

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


## Đa hình tại thời điểm biên dịch (Compile-time Polymorphism).

### 1. Function overloading (nạp chồng hàm)

- Là cách định nghĩa các hàm cùng tên nhưng khác
nhau:

Kiểu trả về;

Danh sách tham số:

 Số lượng;

 Thứ tự;

 Kiểu dữ liệu.

Có thể sử dụng đối số mặc định.

Ví dụ:

```c
#include <iostream>

using namespace std;

int sum(int a, int b)
{
    return a + b;
}

double sum(double a, double b)
{
    return (double)a + b;
}

double sum(int a, double b)
{
    return (double)a + b;
}

int sum(int a, int b, int c)
{
    return a + b + c;
}


int main(int argc, char const *argv[])
{
cout << "Tổng 2+3: " << sum(2,3) << endl;
cout << "Tổng 2+3.14: " << sum(2,3.14) << endl;
cout << "Tổng 3.5+5.6: " << sum(3.5,5.6) << endl;
cout << "Tổng 2+3+4: " << sum(2,3,4) << endl;

cout << "Tổng 2+3+4.6: " << sum(2,3,4.6) << endl;  // int x = 5.5;
    return 0;
}

```
### 2. Operator overloading (nạp chồng toán tử)

- Là đi tái định nghĩa toán tử trên kiểu dữ liệu mới
Viết 1 hàm đa năng hóa, trong hàm thực hiện định nghĩa toán tử đ/v kiểu dữ liệu mới (đối tượng)

- Đa năng hóa sử dụng 2 cách:

Hàm toàn cục: số lượng tham số bằng số toán hạng

Hàm thành viên của lớp: (), [], ->, = (bắt buộc)

- Các phép toán có thể tái định nghĩa:

![alt text](dananghoa.png)

Ví dụ: Đa năng hóa toán tử + & - bằng hàm toàn cục, số lượng tham số bằng số toán hạng; sử dụng hàm thành viên của lớp

```c
// Point.hpp
class Point
{
    private:
        int xVal, yVal;
    public:
        Point(int = 1, int = 1);
        Point(const Point&);
        ~Point();
        void Show();
        friend Point operator+(const Point&, const Point&);
        //p1 - p2
        Point operator-(const Point&);
};

// Point.cpp
#include "Point.hpp"
#include <iostream>
using namespace std;

Point::Point(int xVal, int yVal)
{
    this->xVal = xVal;
    this->yVal = yVal;
}

Point::Point(const Point& p)
: xVal(p.xVal), yVal(p.yVal)
{

}

Point::~Point()
{

}

void Point::Show()
{
    cout << this->xVal << this->yVal << endl;
}

Point operator+(const Point& p1, const Point& p2)
{
    Point p(p1.xVal + p2.xVal, p1.yVal + p2.yVal);
    return p;
}

Point Point::operator-(const Point& q)
{
    Point p(this->xVal - q.xVal, this->yVal - q.yVal);
    return p;
}

//main.cpp

#include "Point.hpp"
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    Point p1(1,2);
    Point p2(1,2);

    Point p3 = p1 + p2;
    Point p4 = operator + (p1, p2);

    Point p5 = p1 - p2;
    Point p6 = p1.operator-(p2); // p1 - p2
    Point p7 = p2.operator-(p1); // p2 - p1
    p3.Show();
    p4.Show();
    p5.Show();
    p6.Show();
    p7.Show();
    return 0;
}


```

 **Đa năng hóa sử dụng hàm toàn cục**

- Vì 2 thuộc tính xVal, yVal có quyền truy cập private -> xử lý qua hàm friend

- Truyền vào `const Point&` vì đối tượng của class Point truyền vào là không thay đổi

 **Đa năng hóa sử dụng hàm thành viên của lớp**

 - p1 là con trỏ this, truyền vào const Point& cho p2

### 3. This Pointer

- Khi khai báo 1 class, trình biên dịch tự động cung cấp 1 con trỏ, con trỏ đó trỏ đến đối tượng hiện tại

- Khai báo bao nhiêu đối tượng thì có bấy nhiêu con trỏ this

- Là con trỏ hằng (constant pointer)

```c
Point::Point(int xVal, int yVal)
{
    this->xVal = xVal;
    this->yVal = yVal;
}
```

-> Lúc này trình biên dịch không biết đây là biến xVal hay là thuộc tính xVal của lớp

- Nếu ghi this->xVal, sẽ hiểu là tên thuộc tính xVal của cái đối tượng mà con trỏ this đang trỏ tới, Point p1, ở đây là hàm dựng mặc định,  p1.Show() đi đến Point::Show() in ra xVal và yVal của đối tượng p1.


### 4. Truyền tham chiếu (pass-by-reference)

- Truyền tham trị vào hàm: mọi tác động đều không ảnh hưởng đến biến gốc

- Truyền tham chiếu:

```c
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

```

**Khác nhau giữa reference và con trỏ**

- Khi kháo báo 1 con trỏ, tốn 1 vùng nhớ trên RAM

- Khai báo tham chiếu, không tốn vùng nhớ, chỉ mượn vùng nhớ của biến tham chiếu đến