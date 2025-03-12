#include <iostream>
#include <string>

using namespace std;

class DoiTuong{
    // private:
    //    string ten;
    //    int id;

    protected:
        string ten;
        int id;

    public:
        DoiTuong(){  
            static int ID = 1;
            id = ID;
            ID++;
        }

        void setName(string _ten){
            // check chuỗi nhập vào
            ten = _ten;
        }

        void display(){
            cout << "ten: " << ten << endl;
            cout << "id: " << id << endl;
        }
};

class SinhVien : public DoiTuong{
    protected:
        string chuyenNganh;

    public:
        void setChuyenNganh(string _nganh){
            chuyenNganh = _nganh;
        }

        void display(){ // overload
            cout << "ten: " << ten << endl;
            cout << "id: " << id << endl;
            cout << "chuyen nganh: " << chuyenNganh << endl;
        }
};

class HocSinh : public DoiTuong{
    protected:
        string lop;
   
    public:
        void setLop(string _lop){
            lop = _lop;
        }

        void display(){ // overload
            cout << "ten: " << ten << endl;
            cout << "id: " << id << endl;
            cout << "lop: " << lop << endl;
        }
};

class GiaoVien : public DoiTuong{
    protected:
        string chuyenMon;

    public:
        void setChuyenMon(string _mon){
            chuyenMon = _mon;
        }

        void display(){ // overload
            cout << "ten: " << ten << endl;
            cout << "id: " << id << endl;
            cout << "chuyen mon: " << chuyenMon << endl;
        }
};

int main(int argc, char const *argv[])
{
    // SinhVien sv1;

    // sv1.ten = "Hoang";
    // sv1.id = 1;
    // sv1.chuyenNganh = "DTVT";

    // cout << "ID: " << sv1.id << endl;
    // cout << "Ten: " << sv1.ten << endl;
    // cout << "Chuyen nganh: " << sv1.chuyenNganh << endl;

    SinhVien sv1;
    sv1.setName("Cuong");
    sv1.setChuyenNganh("21CDT1");
    sv1.display();

    cout << endl;

    HocSinh hs1;
    hs1.setName("Cuong");
    hs1.setLop("12A1 - NguyenHue");
    hs1.display();

    cout << endl;

    GiaoVien gv1;
    gv1.setName("Tru Nguyen");
    gv1.setChuyenMon("TOEIC");
    gv1.display();

   // DoiTuong *dt = &sv1; // up-casting
  //  dt->display();

    DoiTuong *dt1[3] = {&sv1, &hs1, &gv1};

    for (size_t i = 0; i < 3; i++)
    {
        dt1[i] ->display();
    }
    
    return 0;
}
