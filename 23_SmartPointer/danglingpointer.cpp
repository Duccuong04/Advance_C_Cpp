#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int *ptr = new int (10);
    int *ptr1 = ptr;

    delete ptr;

    cout << *ptr1;
    return 0;
}
