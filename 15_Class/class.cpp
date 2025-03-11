#include <iostream>
#include "class.hpp"

SinhVien::SinhVien()
{

}
string SinhVien::getName()
{
    return name;
}

void SinhVien::setName(string newName)
{
    name = newName;
}

void SinhVien::display()
{
    cout << "Tên: " << name << endl;  // endl = '\n'
    cout << "MSSV: " << mssv << endl;
}

int main(int argc, char const *argv[])
{
    SinhVien sv; // object

    sv.name = "Anh";
    sv.mssv = "HTN123";

    sv.setName("Trung");
    cout << "Tên SV: " << sv.getName() << endl;
    sv.display();

    return 0;
}

