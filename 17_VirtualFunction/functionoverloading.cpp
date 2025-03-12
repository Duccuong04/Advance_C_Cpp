#include <iostream>

using namespace std;

int sum(int a, int b)
{
    return a + b;
}

double sum(double a, double b)
{
    return (double)a + b;
}

double sum(int a, double b)
{
    return (double)a + b;
}

int sum(int a, int b, int c)
{
    return a + b + c;
}


int main(int argc, char const *argv[])
{
cout << "Tổng 2+3: " << sum(2,3) << endl;
cout << "Tổng 2+3.14: " << sum(2,3.14) << endl;
cout << "Tổng 3.5+5.6: " << sum(3.5,5.6) << endl;
cout << "Tổng 2+3+4: " << sum(2,3,4) << endl;

cout << "Tổng 2+3+4.6: " << sum(2,3,4.6) << endl;  // int x = 5.5;
    return 0;
}
