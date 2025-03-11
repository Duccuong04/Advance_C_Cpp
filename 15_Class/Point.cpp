#include "Point.hpp"
#include <iostream>

using namespace std;

int Point::n = 30; // Khởi tạo biến tĩnh n
int Point::n1 = 20;

Point::Point(int xVal, int yVal, int z) : z(z) {
    this->xVal = xVal;
    this->yVal = yVal;
}

Point::Point(const Point& p) : z(p.z), xVal(p.xVal), yVal(p.yVal) {}

Point::~Point() {}

int Point::get_xVal()
{
    return this->xVal;
}
void Point::set_xVal(int value)
{
    this->xVal = value;
}

void Point::Show()
{
    cout << xVal <<endl<< yVal;
}