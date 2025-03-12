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