#include <iostream>

using namespace std;

// variadic ...

template <typename T>
T sum(T value)
{
    return value;
}

template <typename T, typename... Args> // template <typename T, typename Args1, typename Args2, >
auto sum(T first, Args... args)         // T first, Args1 args1, Args2 args2, 
{
    return first + sum(args...);
}

int main(int argc, char const *argv[])
{
    cout << sum(1, 2, 3.5, 4, 5.5) << endl;
    /*
     * Lần 1: first = 1,    args... = 2, 3.5, 4, 5.5 --> 1 + sum(2, 3.5, 4, 5.5)
     * Lần 2: first = 2,    args... = 3.5, 4, 5.5    --> 1 + 2 + sum(3.5, 4, 5.5)
     * Lần 3: first = 3.5,  args... = 4, 5.5         --> 1 + 2 + 3.5 + sum(4, 5.5)
     * Lần 4: fisrt = 4,    args... = 5.5            --> 1 + 2 + 3.5 + 4 + sum(5.5)
     * Lần 5: value = 5.5                            --> 1 + 2 + 3.5 + 4 + 5.5 = 
     */
    return 0;
}

/*
 * typename... : định nghĩa nhiều kiểu dữ liệu tổng quát
 * Args... : đại diện cho nhiều kiểu dữ liệu khi truyền vào hàm
 * args... : đại diện cho nhiều tham số truyền vào hàm
 */
