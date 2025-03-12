#include <iostream>

using namespace std;

// int sum(int a, int b)
// {
//     return a+b;
// }

// double sum(double a, double b)
// {
//     return a+b;
// }

// auto sum(auto a, auto b)
// {
//     return a+b;
// }

// Function Template

template <typename T>
T sum(T a, T b)
{
    return a+b;
}

// int sum(int a, int b)
// {
// }

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

// tham số mặc định
template <typename T = int>
T square(T x)
{
    return x * x;
}

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

int main(int argc, char const *argv[])
{
    display("hello");
    display(1);
    display(3.1);

    cout << square(4) << endl;
    cout << square(4.5) << endl;

    auto x = 5;
    auto y = 3.14;
    auto z = 'a';
    auto t = "hello";

    cout << sum(1, 2) << endl;      // T: int
    cout << sum(1.5, 3.6) << endl;  // T: double
    cout << sum(2.7, 1) << endl;    // T1: double, T2: int

    cout << sum(1,2,3) << endl;
    cout << sum(1.2, 2.3, 3.5) << endl;
    cout << sum(1, 2.4, 3) << endl;

    return 0;
}
