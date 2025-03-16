#include <iostream>
#include <map>
#include <string>

using namespace std;

typedef struct
{
    string ten;
    int tuoi;
    string lop;
} SinhVien;

int main(int argc, char const *argv[])
{
    map<string, SinhVien> Database = 
    {
        { "SV100", { "Hoang", 20, "DDT" } },
        { "SV101", { "Tuan", 21, "CNTT" } }
    };

    for(auto item : Database)
    {
        cout << item.first << " " << item.second.lop << endl;
    }

    return 0;
}
