#ifndef POINT_H
#define POINT_H

class Point {
public:
    static int n;  // Biến tĩnh n
    static int n1;

private:
    int xVal, yVal;
    const int z;

public:
    Point(int = 1, int = 1, int = 2);
    Point(const Point&);
    ~Point();
    void Show();
    //get
    int get_xVal();
    //set
    void set_xVal(int);
};

#endif
