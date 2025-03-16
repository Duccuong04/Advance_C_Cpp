#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    // định nghĩa lambda và gán cho biến
    auto func = []()
    {
        cout << "Hello" << endl;;
    };

    func();

    // định nghĩa lambda và gọi trực tiếp
    []()
    {
        cout << "Hello, lambda";
    }();
    return 0;
}
