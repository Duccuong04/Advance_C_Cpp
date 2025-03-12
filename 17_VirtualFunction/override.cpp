#include <iostream>

using namespace std;

class cha{
    public:
        virtual void display(){                            // Hàm ảo
            cout << "display from class cha" << endl;
        }
};

class con : public cha{
    public:
        void display() override{                           // Ghi đè hàm ảo
            cout << "display from class con" << endl;
        }
};

int main(){
    cha *ptr;
    con obj;

    // trỏ con trỏ class cha đến đối tượng class con
    ptr = &obj;

    // Gọi hàm ảo
    ptr->display();
}

