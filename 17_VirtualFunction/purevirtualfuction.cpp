#include <iostream>
using namespace std;

class cha{
    public:
        virtual void display() = 0; // Hàm ảo thuần túy
};

class con : public cha{
    public:
        void display() override{   // Ghi đè hàm ảo thuần túy
            cout << "display from class con" << endl;
        }
};

int main(){
    // cha ptr; // wrong
    cha *ptr;
    con obj;

    ptr = &obj;
    ptr->display();

    return 0;
}

