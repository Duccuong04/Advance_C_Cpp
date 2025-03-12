# Template

- Trong C++, function templates là một tính năng mạnh mẽ giúp viết các function hoặc class chung có thể được sử dụng cho nhiều kiểu dữ liệu khác nhau mà không cần phải triển khai nhiều phiên bản của cùng một function hoặc class. 

- 2 loại: ***Function Template, Class Template***

## 1. Function Template

- Khuôn mẫu hàm cho phép định
nghĩa các hàm tổng quát dùng đến các kiểu dữ liệu
tùy ý;

- Từ khóa template được theo sau bởi 1 cặp <> chứa tên
của các kiểu dữ liệu tùy ý được cung cấp

- 1 template chỉ áp dụng đối với 1 hàm

![alt text](template.png)

```c
#include <iostream>

using namespace std;

int sum(int a, int b)
{
    return a+b;
}

double sum(double a, double b)
{
    return a+b;
}

template <typename T>
T sum(T a, T b)
{
    return a+b;
}


int main(int argc, char const *argv[])
{
    cout << sum(1,2) << endl;
    cout << sum(1.5, 3.6) << endl;
    return 0;
}


```

- Trong quá trình compile - time, template sẽ dựa vào biến truyền vào hàm để chọn hàm có kiểu dữ liệu tương ứng đã được khai báo & định nghĩa trước đó

**Khi gặp lời gọi hàm sum (int, int)**

- Trình biên dịch tìm xem có 1 hàm HV() được khai báo
với 2 tham số kiểu int hay không:

 Nó không tìm thấy 1 hàm thích hợp, nhưng tìm thấy 1 template
có thể dùng được.

- Tiếp theo, nó xem xét khai báo của template HV() để
xem có thể khớp được với lời gọi hàm hay không:

 Lời gọi hàm cung cấp 2 tham số thuộc cùng 1 kiểu int;

 Trình biên dịch thấy template chỉ ra 2 tham số thuộc cùng kiểu
T, nên nó kết luận rang T phải là kiểu int;

 Do đó, trình biên dịch kết luận rằng template khớp với lời gọi
hàm.

**Khai báo template đối với nhiều kiểu dữ liệu**

```c
template <typename T>
T divide(T a, T b){}

template <typename T1, typename T2>
auto sum(T1 a, T2 b)
{
    return a+b;
}

template <typename T1, typename T2, typename T3>
auto sum(T1 a, T2 b, T3 c)
{
    return a+b+c;
}
```
**Từ khóa auto**

- Trình biên dịch tự động suy diễn kiểu dữ liệu (trong compile-time), trong gcc ở tiền xử lí

- Khi khai báo biến phải có giá trị truyền vào

- `auto sum(T1 a, T2 b, T3 c)`: chỉ cần 1 trong 3 có kiểu dữ liệu double -> Template trả về kiểu double

**Định nghĩa kiểu dữ liệu mặc định trong Function Template**

```c
// tham số mặc định
template <typename T = int>
T square(T x)
{
    return x * x;
}
```


`template <typename T = int>`, nếu không chỉ định kiểu dữ liệu -> mặc định là kiểu int

**Chuyên biệt hóa**

- Định nghĩa Template cho 1 kiểu dữ liệu duy nhất

- Muốn sử dụng template chuyên biệt, phải định nghĩa 1 template cho các dữ liệu còn lại

```c
// chuyên biệt hóa
template <typename T>
void display(T value)
{
    cout << value << endl;
}

// Chuyên biệt hóa cho kiểu 'const char*'
template <>
void display<const char*>(const char *str)
{
    cout << "String: " << str << endl;
}

// Chuyên biệt hóa cho kiểu 'int'
template <>
void display<int>(int value)
{
    cout << value << endl;
}
```

## 2. Class Template (cũng áp dụng cho Struct)

```c
#include <iostream>
#include <string>

using namespace std;

template <typename T>
class Sensor
{
    private:
        T value;

    public:
        Sensor(T init): value(init){}

        T readSensor(T newValue);

        T getValue() const;

        void display()
        {
            cout << "Giá trị cảm biến: " << getValue() << endl;
        }
};

template <typename type>
type Sensor<type>::readSensor(type newValue)
{
    this->value = newValue;
}

template <typename T>
T Sensor<T>::getValue() const{ return value; }



template <typename T>
class Printer 
{
    public:
        void print(T value) 
        {
            cout << "Generic: " << value << endl;
        }
};

// Chuyên biệt hóa cho kiểu std::string
template <>
class Printer<string> 
{
    public:
        void print(string value) 
        {
            cout << "String specialization: " << value << endl;
        }
};


int main(int argc, char const *argv[])
{
    Sensor<int> tempSensor1(36.5);
    tempSensor1.display();

    Sensor tempSensor3(26.7);
    tempSensor3.display();

    Sensor<double> tempSensor2(25);
    tempSensor2.display();

    Sensor stateSensor("ON");
    stateSensor.display();

    return 0;
}

```

- Dữ liệu cảm biến để kiểu tổng quá là kiểu T (int, double, string, const char*...)

```c
 Sensor<int> tempSensor1(36.5);
    tempSensor1.display();
```

- Quy định kiểu dữ liệu int/ gán ngầm định không quy định kiểu dữ liệu

```c
template <typename type>
type Sensor<type>::readSensor(type newValue)
{
    this->value = newValue;
}

template <typename T>
T Sensor<T>::getValue() const{ return value; }
```

- Định nghĩa các phương thức bên ngoài class

### Chuyên biệt hóa trong Class Template

```c
template <typename T>
class Printer 
{
    public:
        void print(T value) 
        {
            cout << "Generic: " << value << endl;
        }
};

// Chuyên biệt hóa cho kiểu std::string
template <>
class Printer<string> 
{
    public:
        void print(string value) 
        {
            cout << "String specialization: " << value << endl;
        }
};
```

- Tương tự, phải ạo class riêng để đáp ứng cho tất cả các kiểu dữ liệu