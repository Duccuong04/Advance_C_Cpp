#include <iostream>
#include "Point.hpp"

using namespace std;

int main() {
    Point point1;
    Point point2(2,3);
    cout << Point::n << endl; // In giá trị của biến tĩnh n
    cout << Point::n1 << endl;
    cout << "Addr of n " << &(point1.n) << endl;
    cout << "Addr of n " << &(point2.n) << endl;
    cout << "Addr of n1 " << &(point1.n1) << endl;
    cout << "Addr of n1 " << &(point2.n1) << endl;
    point1.set_xVal(point2.get_xVal());
    point1.Show();
    return 0;
}
