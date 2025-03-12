include <iostream>

using namespace std;

class SinhVien{
    private:
        string name;
        int id;
        int age;
    
    public:
        SinhVien(string _name, int _age): name(_name), age(_age){
            static int _id = 1;
            id = _id;
            _id++;
        }

        void display(){
            cout << "Name: " << name << ", ID: " << id << ", Age: " << age << endl;
        }
};

int main(int argc, char const *argv[])
{   
    SinhVien *p1 = new SinhVien("Trung", 25);
    p1->display();

    SinhVien *p2 = new SinhVien("Tuan", 22);
    p2->display();

    delete p1, p2;
    return 0;
}


