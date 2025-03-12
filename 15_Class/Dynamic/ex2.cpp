#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    
        int size;
        cout << "Nhập kích thước của mảng: ";
        cin >> size;
    
        int *arr = new int[size]; 
    
        for (int i = 0; i < size; i++){
            arr[i] = i * 2;
        }
    
        for (int i = 0; i < size; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    
        delete[] arr;  // Giải phóng bộ nhớ   
    
        return 0;
    }
    



