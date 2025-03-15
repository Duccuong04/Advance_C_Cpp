#include <iostream>

using namespace std;

namespace A{
    char *name = (char*)"Trung 20";

    namespace C{
        char *str = (char*)"Nguyen Hoang";
    }
}

namespace B{
    char *name = (char*)"Trung 21";
}

using namespace A::C;

int main(int argc, char const *argv[])
{
    cout << "Name: " << A::name << endl;
    cout << "Name: " << B::name << endl;
  //  cout << "Name: " << C::str << endl;

    str = (char*)"Hello World";
    cout << "Name: " << str << endl;
    return 0;
}


