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
