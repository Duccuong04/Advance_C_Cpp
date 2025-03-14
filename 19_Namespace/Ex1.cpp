include <iostream>

using namespace std;

namespace A{
    char *name = (char*)"Trung 20";

    void display(){
        cout << "Name: " << name << endl;
    }
}

namespace B{
    char *name = (char*)"Trung 21";

    void display(){
        cout << "Name: " << name << endl;
    }
}

int main(int argc, char const *argv[])
{
    cout << "Name: " << A::name << endl;
    cout << "Name: " << B::name << endl;

    A::display();
    B::display();
    return 0;
}


