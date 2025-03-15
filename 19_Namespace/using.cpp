#include <iostream>

using namespace std;

namespace A{
    char *name = (char*)"Trung 20";
}

namespace B{
    char *name = (char*)"Trung 21";
}

using namespace A;

// using namespace B; // error: tham chiếu không rõ ràng

int main(int argc, char const *argv[])
{
    cout << "Name: " << name << endl;
    cout << "Name: " << B::name << endl;
    return 0;
}


