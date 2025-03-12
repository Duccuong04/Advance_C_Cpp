#include <iostream>

using namespace std;

// Class tổng quát sử dụng Variadic Template
template<typename... Args>
class MyClass;

// Định nghĩa class khi không có đối số
template <>
class MyClass<>{
    public:
        void display() {
            cout << "No arguments" << endl;
        }
};

// Định nghĩa class khi có ít nhất một đối số
template <typename T, typename... Args> 
class MyClass<T, Args...> : public MyClass<Args...>{
    private:
        T first_;

    public:
        MyClass(T first, Args... args): first_(first),  MyClass<Args...>(args...){} // T first_ = first, Args1 args1_ = args1, Args2 args2_ = args2,...

        void display(){
            cout << first_ << " ";
            MyClass<Args...>::display(); // Gọi hàm display của lớp cơ sở
        }   

};

int main() 
{
    MyClass<int, double, char> obj(1, 2.5, 'A');
    obj.display();  // Kết quả: 1 2.5 A No arguments

    MyClass obj1;
    obj1.display();
    return 0;
}

/*
 * Lần 1: 
 *      + T = int, Args... = double, char
 *      + first = 1, args... = 2.5, 'A'
 *      --> In ra: 1                        --> MyClass<double, char>(2.5, 'A')
 * 
 * Lần 2:
 *      + T = double, Args... = char
 *      + first = 2.5, args... = 'A'
 *      --> In ra: 1 2.5                    --> MyClass<char>('A')
 * 
 * Lần 3:
 *      + T = char, Args... không còn
 *      + first = 'A', args... không còn
 *      --> In ra: 1 2.5 'A'                --> MyClass<>
 * 
 * Lần 4: 
 *      --> In ra: 1 2.5 'A' No arguments
 */